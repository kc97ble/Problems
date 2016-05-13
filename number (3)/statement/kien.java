import java.util.*;

public class B {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int k = Math.min(in.nextInt(), n);
		int[] d = new int[n+1];
		
		for (int i=2; i<=k; i++)
		if (d[i]==0) {
			for (int j=i; j<=n; j+=i)
			d[j]=i;
		}
		
		boolean[] ok = new boolean[n+1];
		for (int i=1; i<=k; i++)
			ok[i] = true;
		for (int i=k+1; i<=n; i++)
			ok[i] = (d[i]!=0) && ok[i/d[i]];
		
		int Count = 0;	
		for (int i=1; i<=n; i++)
			Count += (ok[i] ? 1 : 0);
		System.out.println(Count);
	}
}

