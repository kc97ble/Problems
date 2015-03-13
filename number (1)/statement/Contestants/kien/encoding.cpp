#include <stdio.h>



void showbinary(long n, long maxlen){
  long i = maxlen-1;
  
  for (; i>=0; i--){
    printf("%d", (n >> i) %2);
  }
}

void show (long prefix, long size, long head, long tail){
  long i;
  for (i=0; i<(1 << size); i++)
  if (i>=head and i<=tail)
  {
//showbinary(prefix, 15);
    if (prefix ==1) printf("1");
    if (prefix ==2) printf("0");
    showbinary(i, size);
    printf("\n");
  }
}

long findk(long n){
  long i;
  for (i=15; i>=0; i--)
  if ((n>>i)%2 == 1)
  return i;
  return 0;
}

main(){
  long n;
  scanf("%d", &n);
  long k = findk(n);
/*
  if (n <= (3<<(k-1)))
  {
    show(0,k,0, (2 << k) - n-1);
    show(1,k, (1<<k) - 2*(n-(1<<k)) , 12345);
  }
  else
  {
    show(0,k,0, 23997);
    show(1,k,0, 23997);
  }
  */
  
  long a, b;
  b = n - (1 << k);
  a = n - 2*b;
  
  if (n <= (3<<(k-1)))
  {
    show (0, k, 0, a-1);
    show (1, k, (1<<k)-2*b, 23997);
  }
  else
  {
    show (0, k, 0, a-1);
    b = b - (1 << (k-1));
    show (2, k, (1<<k)-b , (1<<k)-1);
    show (1, k, 0, 23997);
  }
}

