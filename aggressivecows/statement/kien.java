import java.io.File;
import java.util.Arrays;
import java.util.Scanner;

public class aggressivecows {	
	static Scanner cin = new Scanner(System.in);
	
	public static void main(String[] args) {
		new aggressivecows();
	}
	
	int n = cin.nextInt();
	int m = cin.nextInt();
	int a[] = new int [n+1];
	
	boolean ok(int dx) {
		int least=-1000000007, count=0;
		
		for (int i=1; i<=n; i++)
		if (a[i] >= least) {
			least = a[i]+dx;
			count ++;
		}
		return count >= m;
	}
	
	public aggressivecows() {
		for (int i=1; i<=n; i++)
			a[i] = cin.nextInt();
		Arrays.sort(a, 1, n+1);
		
		int ll=0, rr=1000000007, mm=(ll+rr+1)/2;
		while (ll<rr) {
			if (ok(mm)) ll=mm; else rr=mm-1;
			mm=(ll+rr+1)/2;
		}
		System.out.println(mm);	
	}

}

