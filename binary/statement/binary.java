import java.util.*;

public class b {
  static int[][] next = new int[10][10];
  static int[][][] nextBlock = new int[10][20][100];
  static int[][][] nextSingle = new int[10][10][100];

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    for (int i = 0; i < 10; i++)
      for (int j = 0; j < 10; j++) next[i][j] = sc.nextInt();

    long a = sc.nextLong();
    long b = sc.nextLong();

    for (int i = 0; i < 10; i++)
      for (int j = 0; j < 10; j++) nextSingle[i][j][0] = next[i][j];
    
    for (int k = 1; k < 64; k++)
      for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
	  nextSingle[i][j][k] = nextSingle[nextSingle[i][j][k - 1]][j][k - 1];

    for (int i = 0; i < 10; i++) {
      long pow10 = 1;
      for (int j = 0; j < 19; j++) {
        nextBlock[i][j][0] = i;
	for (int k = 0; k < 10; k++) nextBlock[i][j][0] = findSingle(nextBlock[i][j][0],k,pow10);
	pow10 *= 10L;
      }
    }

    for (int k = 1; k < 64; k++)
      for (int i = 0; i < 10; i++)
        for (int j = 0; j < 19; j++)
	  nextBlock[i][j][k] = nextBlock[nextBlock[i][j][k - 1]][j][k - 1];

    int[] ret = new int[20];
    for (int i = 0; i < 20; i++) ret[i] = 0;
    int digit = 0;
    
    long pow10 = 1L;
    for (int i = 0; ; i++) {
      long diva = a/pow10,moda = a % pow10,divb = b/pow10,modb = b % pow10;
      if (diva == 0 && divb == 0) break;
      if (diva == divb) ret[digit] = findSingle((int) (diva % 10),(int) (diva % 10),modb - moda); else {
        ret[digit] = findSingle((int) (diva % 10),(int) (diva % 10),pow10 - 1 - moda);
	ret[digit] = findRange(ret[digit],diva + 1,divb - 1,i,pow10);
	ret[digit] = findSingle(ret[digit],(int) (divb % 10),modb + 1);
      }
      pow10 *= 10L;
      digit++;
    }
    while (digit > 0 && ret[digit - 1] == 0) digit--;
    if (digit == 0) digit = 1;
    for (int i = digit - 1; i >= 0; i--) System.out.print(ret[i]);
    System.out.println();
  }

  private static int findRange(int start,long fa,long fb,int idx,long jump) {
    if (fa > fb) return start;
    if (fb - fa <= 10) for (long i = fa; i <= fb; i++) start = findSingle(start,(int) (i % 10),jump); else {
      while (fa % 10 != 0) {
        start = findSingle(start,(int) (fa % 10),jump);
	fa++;
      }
      start = findBlock(start,idx,(fb - fa)/10);
      for (int i = 0; i <= (int) (fb % 10); i++) start = findSingle(start,i,jump);
    }
    return start;
  }

  private static int findSingle(int fa,int fb,long jump) {
    if (jump <= 0) return fa;
    for (int i = 63; i >= 0; i--) if ((jump & (1L << i)) > 0) fa = nextSingle[fa][fb][i];
    return fa;
  }

  private static int findBlock(int start,int idx,long jump) {
    if (jump <= 0) return start;
    for (int i = 63; i >= 0; i--) if ((jump & (1L << i)) > 0) start = nextBlock[start][idx][i];
    return start;
  }
};
