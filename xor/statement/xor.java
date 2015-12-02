import java.io.*;
import java.util.*;

public class xor_sp implements Runnable {

	public static void main(String[] args) {
		new Thread(new xor_sp()).start();
	}

	public void run() {
		try {
			Locale.setDefault(Locale.US);
//			br = new BufferedReader(new InputStreamReader(System.in));
//			out = new PrintWriter(System.out);
			br = new BufferedReader(new FileReader(FILENAME + ".in"));
			out = new PrintWriter(FILENAME + ".out");
			solve();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	BufferedReader br;

	PrintWriter out;

	StringTokenizer st;

	String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			st = new StringTokenizer(br.readLine());
		}
		return st.nextToken();
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	void myAssert(boolean e, String s) {
		if (!e) {
			throw new Error("Assertion failure " + s);
		}
	}

	private static final String FILENAME = "xor";
	
	class Trie {
		Trie[] child = new Trie[2];
		
		void add(int[] ch, int pos) {
			if (pos == ch.length) return;
			if (child[ch[pos]] == null) {
				child[ch[pos]] = new Trie();
			}
			child[ch[pos]].add(ch, pos + 1);
		}
		
		long find(int[] ch, int pos, long mul) {
			if (pos == ch.length) {
				return 0;
			}
			if (child[1 - ch[pos]] != null) {
				long t = child[1 - ch[pos]].find(ch, pos + 1, mul / 2);
				return (1 - ch[pos]) * mul + t;
			}
			long t = child[ch[pos]].find(ch, pos + 1, mul / 2);
			return (ch[pos]) * mul + t;
		}
	}
	
	int MAX = 32;
	
	int MAXN = 100000;
	int MAXV = 1000000000;
	
	int[] toBinary(int a) {
		int[] ret = new int[MAX];
		for (int i = MAX - 1; i >= 0; i--) {
			ret[i] = a % 2;
			a /= 2;
		}
		return ret;
	}

	public void solve() throws IOException {
		int n = nextInt();
		myAssert((1 <= n) && (n <= MAXN), "Wrong n");
		Trie root = new Trie();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
			myAssert((0 <= a[i]) && (a[i] <= MAXV), "Wrong a");
			int[] ch = toBinary(a[i]);
			root.add(ch, 0);
		}
		Arrays.sort(a);
		for (int i = 0; i < a.length - 1; i++) {
			assert(a[i] != a[i + 1]);
		}
		int m = nextInt();
		myAssert((1 <= m) && (m <= MAXN), "Wrong m");
		for (int i = 0; i < m; i++) {
			int b = nextInt();
			myAssert((0 <= b) && (b <= MAXV), "Wrong b");
			int[] ch = toBinary(b);
			out.println(root.find(ch, 0, 1l << (MAX - 1)));
		}
	}
}
	