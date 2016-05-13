import java.util.Scanner;

public class kien {
	static Scanner in = new Scanner(System.in);
	
	public static void main(String args[]) {
		int n = in.nextInt();
		int Xor = 0;
		for (int i=1; i<=n; i++)
		Xor ^= in.nextInt();
		System.out.println(Xor);
	}
}

