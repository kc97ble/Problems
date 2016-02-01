// A.Astrelin - Delivery

#include <stdio.h>

int main(){
    freopen("delivery.inp", "rt", stdin);
    freopen("delivery.out", "wt", stdout);

	int M,N,b,c,d;
	scanf("%d%d%d%d%d",&M,&N,&b,&c,&d);
	char s[10];
	scanf("%s",s);

	char myor=s[0];

	int a=1;
	switch(myor){
		case 'B':
			if(c<=3) goto _way1;
			if(b>d) goto _way2;
			if(b<d) goto _way3;
			goto _way4;
		case 'T':
_top:
			if(d==b-1 || d==b+1 || (c<=2 && d==b)) goto _way1;
			if(M==1 || N==1) goto _way0;
			if(d==b) goto _way5;
			goto _way6;
		case 'F':
			if(c!=1) goto _way0;
			goto _way1;
		case 'L':
			if(b==d) goto _way1;
			if(b==N && d!=N) goto _way0;
			if(M==1 && (d<b || d>b+2)) goto _way0;
			if(b<N){ printf("R"); b++; myor='T'; goto _top; }
			goto _way1;
		case 'R':
			if(b==d) goto _way1;
			if(b==1 && d!=1) goto _way0;
			if(M==1 && (d<b-2 || d>b)) goto _way0;
			if(b>1){ printf("L"); b--; myor='T'; goto _top; }
			goto _way1;
	}
	return 0;
_way1:
	while(b>d){ printf("L"); b--; }
	while(b<d){ printf("R"); b++; }
	while(a<c){ printf("F"); a++; }
	printf("\n");
	return 0;
_way2:		
	while(b>d+1){ printf("L"); b--; }
	printf("F"); a++;
	printf("L"); b--;
	while(a<c){ printf("F"); a++; }
	printf("\n");
	return 0;
_way3:
	while(b<d-1){ printf("R"); b++; }
	printf("F"); a++;
	printf("R"); b++;
	while(a<c){ printf("F"); a++; }
	printf("\n");
	return 0;
_way4:
	if(b>1){ printf("L"); b--; goto _way3; }
	if(b<N){ printf("R"); b++; goto _way2; }
	goto _way0;
_way6:
	printf("F"); a++;
	while(b>d){ printf("L"); b--; }
	while(b<d){ printf("R"); b++; }
	if(a!=c){ printf("B"); a--; }
_way5:
	if(a!=c){ 
		if(b>1){
			printf("L");
			while(a<c){ printf("F"); a++; }
			printf("R");
		}else{
			printf("R");
			while(a<c){ printf("F"); a++; }
			printf("L");
		}
	}
	printf("\n"); return 0;
_way0:
	printf("IMPOSSIBLE\n"); return 0;
}
