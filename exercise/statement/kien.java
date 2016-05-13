import java.util.*;
import java.lang.*;

public class Exercise {
	static Scanner in  = new Scanner(System.in);

	public static void main(String[] args) {
		System.out.println(new Exercise().f(0));
	}

	int n = in.nextInt();
	int m = in.nextInt();
	int[] demand = getDemand();

	int[] getDemand() {
		assert n!=0;
		int[] demand = new int[n];
		for (int i=1; i<=m; i++) {
			int x = in.nextInt() - 1;
			int y = in.nextInt() - 1;
			demand[y] |= (1<<x);
		}
		return demand;
	}

	int[] FF = new int [1<<n];
	long[] F = new long [1<<n];

	long f(int u) {
		if (Integer.bitCount(u)==n)
			return 1;
		if (++FF[u] > 1)
			return F[u];
		long Sum = 0;
		for (int i=0; i<n; i++) {
			if ((u & (1<<i))==0)
			if ((demand[i] | u) == u)
			Sum += f(u | (1<<i));
		}
		return F[u] = Sum;
	}
}

