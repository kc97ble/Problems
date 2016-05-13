import java.util.Scanner;
import java.util.Comparator;
import java.util.Arrays;

public class Recruit {
	static Scanner in = new Scanner(System.in);
		
	static public void main(String args[]) 
		{ System.out.println(new Recruit().solve()); }
	
	Integer[] a, c;
	
	
	int solve() {
		int n = in.nextInt();
		a = new Integer [n+3];
		c = new Integer [n+3];
		
		for (int i=1; i<=n; i++) {
			a[i] = in.nextInt();
			c[i] = in.nextInt();
		}
		
		Integer id[] = new Integer [n];
		for (int i=0; i<n; i++)
			id[i]=i+1;
		
		Comparator<Integer> cmp = new Comparator<Integer>() {
			public int compare(Integer p, Integer q) { 
				if (a[p] != a[q])
					return a[q]-a[p]; 
				return c[q]-c[p];
			}
		};
		
		Arrays.sort(id, cmp);
		
		int Sum=0, People=0, Price=0;
		for (int i=1; i<=n; i++)
			Sum += a[i];
		
		for (int u: id) {
			Sum -= a[u];
			if (a[u] >= People + Sum) {
				int Pay = (a[u]-(People+Sum))/2+1;
				Price += Pay * c[u];
				People += Pay;
			}
		}
		
		return Price;
	}
}

