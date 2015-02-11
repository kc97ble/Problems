#ifndef COMPARE_DOT_H
#define COMPARE_DOT_H    1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned char boiMem[4096][10248];
int  boiOrder[16777216];
int  boiAccesses;
int  boiPhase;

int  boi_guessval;
int  boi_cmpval;
int  boi_storeval;

void bit_set(int addr)
{
	if(boiPhase == 2) {
		fprintf(stderr, "ZERO POINTS: bit_set called by compare()\n");
		exit(1);
	}
	if((addr > 10240) || (addr < 1)) {
		fprintf(stderr, "ZERO POINTS: bit_set with addr out of range %d\n", addr);
		exit(1);
	}
	boiMem[boi_storeval][addr] |= 1;
	//fprintf(stderr, " %d",addr);
	boiAccesses++;
	if(boiAccesses > 20) {
		fprintf(stderr, "ERROR: bit_set called more than 20 times\n");
		exit(1);
	}
}

int bit_get(int addr)
{
	if(boiPhase == 1) {
		fprintf(stderr, "ZERO POINTS: bit_get called by remember()\n");
		exit(1);
	}
	//fprintf(stderr, " %d",addr);
	boiAccesses++;
	if((addr > 10240) || (addr < 1)) {
		fprintf(stderr, "ZERO POINTS: bit_get with address out of range\n");
		exit(1);
	}
	return boiMem[boi_guessval][addr]?1:0;
}

/* these are just prototypes that you must implement*/
void remember(int a);
int compare(int b);

/* DO NOT provide another main() function */
int main()
{
	int maxa = 0, maxb = 0, x, y, i;

	boiPhase = 1;
	//fprintf(stderr, "Phase 1: remember() calls\n");
	for(boi_storeval = 0; boi_storeval < 4096; boi_storeval++) {
		//fprintf(stderr, "[a=%d] set_bit:", boi_storeval);
		boiAccesses =0;
		remember(boi_storeval);
		if(boiAccesses > maxa)
			maxa = boiAccesses;
		//fprintf(stderr, "\n", boiAccesses);
	}
	//fprintf(stderr,"max accesses:%d\n",maxa);
	//fprintf(stderr,"Phase 2: compare() calls\n");
	boiPhase = 3;
	for (i=0; i<16777216; i++) boiOrder[i]=i;
	srand(2);
	for (i=1; i<16777216; i++) {
		x=random()%i;
		y=boiOrder[i];
		boiOrder[i]=boiOrder[x];
		boiOrder[x]=y;
	}
	srand(2);
	for (i=0; i<16777216; i++) {
		boi_guessval=boiOrder[i] % 4096;
		boi_cmpval  =boiOrder[i] / 4096;
		//fprintf(stderr,"guess=%d compare=%d get_bit:",boi_guessval,boi_cmpval);
		boiAccesses=0;
		x=compare(boi_cmpval);
		y=0;
		if (boi_cmpval>boi_guessval)
			y=1;
		if (boi_cmpval<boi_guessval)
			y=-1;
		if (x!=y) {
			fprintf(stderr, "ZERO POINTS: For a=%d and b=%d, correct answer is %d, got %d\n",boi_guessval,boi_cmpval,y,x);
			exit(1);
		}
		if (boiAccesses>maxb) 
			maxb=boiAccesses;
		//fprintf(stderr,"\n");
	}
	boiPhase=2;
	x=maxa+maxb;
	if (x>20)
		fprintf(stderr, "ZERO POINTS: more than 20 accesses in the worst case\n");
	fprintf(stderr, "maxAccesses = %d\n", x);

	return 0;
}

#endif
