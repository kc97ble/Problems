import java.util.*;

public class A {
	static Scanner in = new Scanner(System.in);
	public static void main(String[] args) {
		int t = in.nextInt();
		for (int i=1; i<=t; i++)
		System.out.println(new A().solve() ? "YES" : "NO");
	}
	int n = in.nextInt();
	int m = in.nextInt();
	Integer[] a = new Integer[n];
	Integer[] b = new Integer[n];
	
	int sum(Integer[] a, int L, int R) {
		int result = 0;
		for (int i=L; i<=R; i++)
		result += a[i];
		return result;
	}
	
	boolean solve() {
		for (int i=0; i<n; i++)
			a[i] = in.nextInt();
		for (int i=0; i<n; i++)
			b[i] = in.nextInt();
		
		Arrays.sort(a);
		Arrays.sort(b, Collections.reverseOrder());
		return sum(a, 0, m-1) > sum(b, 0, m-1);
	}
}

