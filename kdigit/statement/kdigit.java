import static java.util.Arrays.deepToString;

import java.io.*;
import java.util.*;

public class interesting_nn {

	static Random rand = new Random(12312863L);
    static final long MAXN = 4L * 1000000 * 1000000 * 1000000;

	static void solve() throws Exception {
		long a = nextLong();
		long b = nextLong();
        assert 1 <= a && a <= MAXN;
        assert 1 <= b && b <= MAXN;
		int k = nextInt();
        assert 1 <= k && k <= 20;
		out.println(answer(a, b, k));
	}

	static long answer(long a, long b, int k) {
		return get(b, k) - get(a - 1, k);
	}

	static boolean isGood(long n, int k) {
		int last = 0;
		int count = 0;
		while (n > 0) {
			if (n % 10 == last) {
				count++;
			} else {
				last = (int) (n % 10);
				count = 1;
			}
			if (k == count) {
				return true;
			}
			n /= 10;
		}
		return false;
	}

	static long get(long n, int k) {
		n++;
		int[] d = getDigitRepresentation(n);
		long[] ten = getTenPowers(d);
		if (k == 1) {
			return n;
		}
		if (d.length < k) {
			return 0;
		}
		long[][] dpGood = getGoodDP(k, d);
		int last = -1;
		int count = 0;
		long ans = getNumbersWithLessDigits(d.length, dpGood);
		for (int pos = 0; pos < d.length; pos++) {
			if (count == k) {
				ans += getNumberLeft(d, pos);
				break;
			}
			for (int j = 0; j < d[pos]; j++) {
				if (pos == 0 && j == 0) {
					continue;
				}
				if (j == last) {
					int left = k - count;
					if (d.length - pos - left >= 0) {
						ans += ten[d.length - pos - left];
						for (int next = pos + 1; next < pos + left; next++) {
							for (int digit = 0; digit < 10; digit++) {
								if (digit == j) {
									continue;
								}
								ans += dpGood[d.length - next][digit];
							}
						}
					}
				} else {
					ans += dpGood[d.length - pos][j];
				}
			}
			if (d[pos] == last) {
				count++;
			} else {
				last = d[pos];
				count = 1;
			}
		}
		return ans;
	}

	static long getNumberLeft(int[] d, int pos) {
		long add = 0;
		for (int curPos = pos; curPos < d.length; curPos++) {
			add = add * 10 + d[curPos];
		}
		return add;
	}

	static long getNumbersWithLessDigits(int length, long[][] dpGood) {
		long ans = 0;
		for (int len = length - 1; len >= 1; len--) {
			for (int digit = 1; digit < 10; digit++) {
				ans += dpGood[len][digit];
			}
		}
		return ans;
	}

	private static long[] getTenPowers(int[] d) {
		long[] ten = new long[d.length + 1];
		ten[0] = 1;
		for (int i = 1; i < ten.length; i++) {
			ten[i] = ten[i - 1] * 10;
		}
		return ten;
	}

	private static int[] getDigitRepresentation(long n) {
		int[] d = new int[(n + "").length()];
		{
			long m = n;
			for (int i = d.length - 1; i >= 0; i--) {
				d[i] = (int) (m % 10);
				m /= 10;
			}
		}
		return d;
	}

	private static long[][] getGoodDP(int k, int[] d) {
		long[][][] dp = new long[d.length + 1][d.length + 1][10];
		dp[0][0][0] = 1;
		for (int pos = 1; pos <= d.length; pos++) {
			for (int digit = 0; digit < 10; digit++) {
				for (int count = 1; count <= k; count++) {
					dp[pos][count][digit] += dp[pos - 1][count - 1][digit];
				}
				for (int countOld = 0; countOld < k; countOld++) {
					for (int digitOld = 0; digitOld < 10; digitOld++) {
						if (digit == digitOld) {
							continue;
						}
						dp[pos][1][digit] += dp[pos - 1][countOld][digitOld];
					}
				}
			}
		}
		long[][] dpGood = new long[d.length + 1][10];
		for (int pos = 1; pos <= d.length; pos++) {
			for (int digit = 0; digit < 10; digit++) {
				for (int digitOld = 0; digitOld < 10; digitOld++) {
					dpGood[pos][digit] += dpGood[pos - 1][digitOld];
				}
				dpGood[pos][digit] += dp[pos][k][digit];
			}
		}
		return dpGood;
	}

	static void test() {
		int q = 0;
		while (true) {
			if (++q == 1000) {
				q = 0;
				System.err.println("PASSED");
			}
			int a = rand.nextInt(90000000) + 1;
			int b = rand.nextInt(2000) + a;
			int k = rand.nextInt(6) + 1;
			long ans1 = answer(a, b, k);
			long ans2 = answerStupid(a, b, k);
			if (ans1 != ans2) {
				System.err.println(a + " " + b + " " + k);
				System.err.println(ans1 + " " + ans2);
				throw new AssertionError();
			}
		}
	}

	static long answerStupid(long a, long b, int k) {
		// long ans1 = getStupid(a - 1, k);
		// long ans2 = getStupid(b, k);
		// return ans2 - ans1;
		long ans = 0;
		for (long i = a; i <= b; i++) {
			if (isGood(i, k)) {
				ans++;
			}
		}
		return ans;
	}

	static long getStupid(long n, int k) {
		long ans = 0;
		for (long i = 1; i <= n; i++) {
			if (isGood(i, k)) {
				ans++;
			}
		}
		System.err.println("stupid " + n + " " + k + " => " + ans);
		return ans;
	}

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	static void debug(Object... a) {
		System.err.println(deepToString(a));
	}

	static int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	static String next() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null) {
				return null;
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
	}

	static long nextLong() throws IOException {
		return Long.parseLong(next());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	public static void main(String[] args) {
		try {
			File file = new File("interesting.in");
			InputStream input = System.in;
			OutputStream output = System.out;
			if (file.canRead()) {
				input = (new FileInputStream(file));
				output = (new PrintStream("interesting.out"));
			}
			br = new BufferedReader(new InputStreamReader(input));
			out = new PrintWriter(output);
			solve();
			out.close();
			br.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(1);
		}
	}
}
