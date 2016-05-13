import java.util.Scanner;
import java.lang.Math;

public class kien {
	static Scanner cin = new Scanner(System.in);

	public static void main(String args[]) {
		int a = cin.nextInt();
		int b = cin.nextInt();
		int c = cin.nextInt();
		System.out.println(Math.min((a+b-c)/3, Math.min(a/2, b)));
	}
}

