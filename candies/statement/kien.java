import java.util.*;

public class Candies {
	static Scanner in = new Scanner(System.in);
	
	public static void main(String[] args) {
		System.out.println(new Candies().solve());
	}
	
	int m = in.nextInt();
	int n = in.nextInt();
	Integer[] a = new Integer[n];
	
	long solve() {
		for (int i=0; i<n; i++)
			a[i] = in.nextInt();
		Arrays.sort(a);
		
		long Sum=0, Result=0;
		for (int i=0; i<n; i++)
			Sum += a[i];
		for (int i=0; i<n; i++) {
			long Give = Math.max(a[i]-(Sum-m)/(n-i), 0);
			Result += (a[i]-Give) * (a[i]-Give);
			Sum -= a[i];
			m -= Give;
		}
		return Result;
	}
}

