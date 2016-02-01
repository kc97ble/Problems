import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Locale;
import java.util.Set;
import java.util.StringTokenizer;

public class pinetree_sm {

	class DSU {
		int[] p, r;

		public DSU(int n) {
			p = new int[n];
			for (int i = 0; i < p.length; i++) {
				p[i] = i;
			}
			r = new int[n];
		}

		int get(int x) {
			if (p[x] == x) {
				return x;
			}
			return p[x] = get(p[x]);
		}

		void union(int a, int b) {
			a = get(a);
			b = get(b);
			if (a == b)
				throw new AssertionError();
			if (r[a] > r[b]) {
				p[b] = a;
			} else if (r[b] > r[a]) {
				p[a] = b;
			} else {
				p[a] = b;
				r[b]++;
			}
		}
	}

	HashSet<Integer>[] es;
	Set<Integer> active;
	ArrayList<Integer> deg1;

	@SuppressWarnings("unchecked")
	void solve() throws IOException {
		int n = nextInt();
		es = new HashSet[n];
		for (int i = 0; i < es.length; i++) {
			es[i] = new HashSet<Integer>();
		}
		DSU dsu = new DSU(n);
		for (int i = 0; i < n - 1; i++) {
			int a = nextInt() - 1;
			int b = nextInt() - 1;
			es[a].add(b);
			es[b].add(a);
			dsu.union(a, b);
		}
		deg1 = new ArrayList<Integer>();
		active = new HashSet<Integer>();
		for (int i = 0; i < es.length; i++) {
			active.add(i);
			if (es[i].size() == 1) {
				deg1.add(i);
			}
		}
		int size = 0;
		while (active.size() > 2) {
			// System.err.println();
			// System.err.println(Arrays.toString(es) + active);
			removeLeafs();
			// System.err.println(Arrays.toString(es) + active);
			// System.err.println(deg1);
			removePaths();
			// System.err.println(Arrays.toString(es) + active);
			// System.err.println(deg1);
			// System.err.println("active = " + active);
			size++;
		}
		out.println(size);
	}

	void removeLeafs() {
		HashSet<Integer> nd1 = new HashSet<Integer>();
		for (int x : deg1) {
			if (es[x].isEmpty())
				continue;
			int y = es[x].iterator().next();
			es[y].remove(x);
			es[x].clear();
			active.remove(x);
			if (es[y].size() == 1) {
				nd1.add(y);
			}
			if (es[y].isEmpty()) {
				active.remove(y);
			}
		}
		deg1.clear();
		for (int x : nd1) {
			if (es[x].isEmpty()) {
				active.remove(x);
			}
			if (active.contains(x)) {
				deg1.add(x);
			}
		}
	}

	void removePaths() {
		for (int x : deg1) {
			while (true) {
				int y = es[x].iterator().next();
				if (es[y].size() != 2)
					break;
				int z = -1;
				for (int q : es[y]) {
					if (q != x) {
						assert z == -1;
						z = q;
					}
				}
				es[z].remove(y);
				es[z].add(x);
				es[x].remove(y);
				es[x].add(z);
				es[y].clear();
				active.remove(y);
			}
		}
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;

	public void run() {
		try {
			String filename = this.getClass().getName()
					.substring(0, this.getClass().getName().indexOf("_"));
			br = new BufferedReader(new FileReader(filename + ".in"));
			out = new PrintWriter(filename + ".out");
			solve();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	String nextToken() {
		try {
			while (st == null || !st.hasMoreTokens()) {
				String s = br.readLine();
				if (s == null) {
					return null;
				}
				st = new StringTokenizer(s);
			}
			return st.nextToken();
		} catch (IOException e) {
			throw new RuntimeException();
		}
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Integer.parseInt(nextToken());
	}

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new pinetree_sm().run();
	}
}
