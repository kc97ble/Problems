import java.io.*;
import java.util.*;

/**
 * Solution for NEERC'2011 Problem D: Dictionary Size
 * This solution checks correctness of the input.
 * @author Roman Elizarov
 */
public class dictionary_re {
	private static final char FIRST = 'a';
	private static final int CHILDREN = 26;

	public static void main(String[] args) throws Exception {
		new dictionary_re().go();
	}

	void go() throws Exception {
		read();
		solve();
		write();
	}

	static class Node {
		Node[] children;
		boolean word;

		boolean isWord() {
			return word;
		}

		boolean isLeaf() {
			return children == null;
		}

		Node get(char c) {
			return children == null ? null : children[c - FIRST];
		}

		void put(char c, Node n) {
			if (children == null)
				children = new Node[CHILDREN];
			children[c - FIRST] = n;
		}

		void visit(int idx, Visitor v) {
			if (children != null)
				for (int i = 0; i < CHILDREN; i++) {
					Node n = children[i];
					if (n != null) {
						v.onNode(idx, (char)(i + FIRST), n);
						n.visit(idx + 1, v);
					}
				}
		}
	}

	interface Visitor {
		void onNode(int idx, char c, Node n);
	}

	static class Trie {
		Node root = new Node();

		void add(char[] s) {
			Node cur = root;
			for (char c : s) {
				Node next = cur.get(c);
				if (next == null)
					cur.put(c, next = new Node());
				cur = next;
			}
			cur.word = true;
		}

		void visit(Visitor v) {
			root.visit(0, v);
		}
	}

	int n;
	Set<String> words = new HashSet<String>();

	void read() throws Exception {
		Scanner in = new Scanner(new File("dictionary.in"));
		in.useLocale(Locale.US);
		n = in.nextInt();
		assert n >= 1 && n <= 10000;
		in.nextLine();
		for (int i = 0; i < n; i++) {
			String word = in.next();
			assert word.length() >= 1 && word.length() <= 40;
			for (int j = 0; j < word.length(); j++)
				assert word.charAt(j) >= FIRST && word.charAt(j) < FIRST + CHILDREN;
			words.add(word);
			in.nextLine();
		}
		in.close();
	}

	long[] result;

	void solve() {
		Trie forward = new Trie();
		final Trie backward = new Trie();
		for (String word : words) {
			char[] s = word.toCharArray();
			forward.add(s);
			reverse(s);
			backward.add(s);
		}
		final int[] suffixes = new int[CHILDREN];
		backward.visit(new Visitor() {
			public void onNode(int idx, char c, Node n) {
				suffixes[c - FIRST]++;
			}
		});
		final int sum = sum(suffixes);
		result = new long[1];
		result[0] = 0;
		forward.visit(new Visitor() {
			public void onNode(int idx, char c, Node n) {
				if (n.isLeaf())
					result[0] += sum + 1;
				else {
					if (n.isWord() || idx > 0 && backward.root.get(c) != null)
						result[0]++;
					for (int i = 0; i < CHILDREN; i++)
						if (n.children[i] == null)
							result[0] += suffixes[i];
				}
			}
		});
	}

	private int sum(int[] a) {
		int sum = 0;
		for (int i : a)
			sum += i;
		return sum;
	}

	private void reverse(char[] s) {
		for (int i = 0, j = s.length - 1; i < j; i++, j--) {
			char t = s[i];
			s[i] = s[j];
			s[j] = t;
		}
	}

	void write() throws Exception {
		PrintWriter out = new PrintWriter("dictionary.out");
		out.println(result[0]);
		out.close();
	}

//----------------- just for validation ------------------

	/**
	 * Strict scanner to veryfy 100% correspondence between input files and input file format specification.
	 * It is a drop-in replacement for {@link java.util.Scanner} that could be added to a soulution source
	 * (cut-and-paste) without breaking its ability to work with {@link java.util.Scanner}.
	 */
	public class Scanner {
		private final BufferedReader in;
		private String line = "";
		private int pos;
		private int lineNo;
		private boolean localeset;

		public Scanner(File source) throws FileNotFoundException {
			in = new BufferedReader(new FileReader(source));
			nextLine();
		}

		public void close() {
			assert line == null : "Extra data at the end of file";
			try {
				in.close();
			} catch (IOException e) {
				throw new AssertionError("Failed to close with " + e);
			}
		}

		public void nextLine() {
			assert line != null : "EOF";
			assert pos == line.length() : "Extra characters on line " + lineNo;
			try {
				line = in.readLine();
			} catch (IOException e) {
				throw new AssertionError("Failed to read line with " + e);
			}
			pos = 0;
			lineNo++;
		}

		public String next() {
			assert line != null : "EOF";
			assert line.length() > 0 : "Empty line " + lineNo;
			if (pos == 0)
				assert line.charAt(0) > ' ' : "Line " + lineNo + " starts with whitespace";
			else {
				assert pos < line.length() : "Line " + lineNo + " is over";
				assert line.charAt(pos) == ' ' : "Wrong whitespace on line " + lineNo;
				pos++;
				assert pos < line.length() : "Line " + lineNo + " is over";
				assert line.charAt(pos) > ' ' : "Line " + lineNo + " has double whitespace";
			}
			StringBuilder sb = new StringBuilder();
			while (pos < line.length() && line.charAt(pos) > ' ')
				sb.append(line.charAt(pos++));
			return sb.toString();
		}

		public int nextInt() {
			String s = next();
			assert s.length() == 1 || s.charAt(0) != '0' : "Extra leading zero in number " + s + " on line " + lineNo;
			assert s.charAt(0) != '+' : "Extra leading '+' in number " + s + " on line " + lineNo;
			try {
				return Integer.parseInt(s);
			} catch (NumberFormatException e) {
				throw new AssertionError("Malformed number " + s + " on line " + lineNo);
			}
		}

		public double nextDouble() {
			assert localeset : "Locale must be set with useLocale(Locale.US)";
			String s = next();
			assert s.length() == 1 || s.startsWith("0.") || s.charAt(0) != '0' : "Extra leading zero in number " + s + " on line " + lineNo;
			assert s.charAt(0) != '+' : "Extra leading '+' in number " + s + " on line " + lineNo;
			try {
				return Double.parseDouble(s);
			} catch (NumberFormatException e) {
				throw new AssertionError("Malformed number " + s + " on line " + lineNo);
			}
		}

		public void useLocale(Locale locale) {
			assert locale == Locale.US;
			localeset = true;
		}
	}
}
