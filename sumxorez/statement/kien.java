import java.util.Scanner;

public class kien {
	static Scanner cin = new Scanner(System.in);
	
	public static void main(String[] args) {
		int n = cin.nextInt();
		int m = cin.nextInt();
		int a[] = new int [n+1];
		
		for (int i=1; i<=n; i++) 
			a[i] = a[i-1] ^ cin.nextInt();
		for (int i=1; i<=m; i++) {
			int x = cin.nextInt();
			int y = cin.nextInt();
			System.out.println(a[y]^a[x-1]);
		}
	}
}
