import java.io.*;
import java.math.*;
import java.util.*;

public class parking_nn {

	int n;
	int m;

	void solve() {
		n = nextInt();
		m = nextInt();
		char[][] c = new char[n][];
		for (int i = 0; i < c.length; i++) {
			c[i] = nextToken().toCharArray();
		}
		int[] q = new int[n * m * n * m];
		int carX = -1;
		int carY = -1;
		int empX = -1;
		int empY = -1;
		for (int i = 0; i < c.length; i++) {
			for (int j = 0; j < m; j++) {
				if (c[i][j] == '.') {
					empX = i;
					empY = j;
				}
				if (c[i][j] == 'X') {
					carX = i;
					carY = j;
				}
			}
		}
		int head = 0;
		int tail = 1;
		q[0] = getState(carX, carY, empX, empY);
		int[] d = new int[n * n * m * m];
		Arrays.fill(d, Integer.MAX_VALUE);
		d[q[0]] = 0;
		int[] w = new int[4];
		while (head < tail) {
			int state = q[head++];
			goState(w, state);
			int x1 = w[0];
			int y1 = w[1];
			if (x1 == 0 && y1 == 0) {
				out.println(d[state]);
				return;
			}
			int x2 = w[2];
			int y2 = w[3];
			for (int dir = 0; dir < 4; dir++) {
				int x = x2 + DX[dir];
				int y = y2 + DY[dir];
				if (x < 0 || y < 0 || x >= n || y >= m || c[x][y] == '#') {
					continue;
				}
				int newState;
				if (x1 == x && y1 == y) {
					newState = getState(x2, y2, x1, y1);
				} else {
					newState = getState(x1, y1, x, y);
				}
				if (d[newState] == Integer.MAX_VALUE) {
					d[newState] = d[state] + 1;
					q[tail++] = newState;
				}
			}
		}
		out.println("Impossible");
	}

	final int[] DX = { 1, 0, -1, 0 };
	final int[] DY = { 0, 1, 0, -1 };

	void goState(int[] w, int state) {
		w[3] = state % m;
		state /= m;
		w[2] = state % n;
		state /= n;
		w[1] = state % m;
		w[0] = state / m;
	}

	int getState(int x1, int y1, int x2, int y2) {
		return y2 + m * (x2 + n * (y1 + m * x1));
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof;
	final Random rand = new Random(this.hashCode());

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}

	BigInteger nextBigInteger() {
		return new BigInteger(nextToken());
	}

	parking_nn() {
		try {
			br = new BufferedReader(new FileReader("parking.in"));
			out = new PrintWriter("parking.out");
			solve();
			br.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "-1";
			}
		}
		return st.nextToken();
	}

	public static void main(String[] args) {
		new parking_nn();
	}
}
