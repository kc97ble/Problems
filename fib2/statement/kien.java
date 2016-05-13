import java.util.*;

public class Fib2 {
	static Scanner in = new Scanner(System.in);
	public static void main(String[] args) {
		int t = in.nextInt();
		for (int i=1; i<=t; i++)
		System.out.println(new Fib2().solve());
	}
	
	int n = in.nextInt();
	long k = in.nextLong();
	long F[] = new long [n+2];
	long G[] = new long [n+2];
	
	long h(int n, long k) {
		if (n==0) return k>0 ? 1 : 0;
		if (n==1) return 0;
		if (k <= F[n-2] + G[n-2]) return h(n-2, k);
		return F[n-2] + h(n-1, k - F[n-2] - G[n-2]);
	}
	
	long solve() {
		F[0]=1; G[0]=0;
		F[1]=0; G[1]=1;
		for (int i=2; i<=n; i++) { 
			F[i] = F[i-2] + F[i-1];
			G[i] = G[i-2] + G[i-1];
		}
		return h(n, k);
	}
}

