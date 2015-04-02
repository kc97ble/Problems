/*

tester for the task "alliances"
compile: g++ -O2 tester.cc -o tester
run: ./tester input_file contestants_output correct_output

*/
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstring>

using namespace std;

int hisedges[75][75][4];
string his[300];
int N,M;
int input[75][75];

fstream fin,fhis,fcorrect;

void die(string m){
  cout << m << "   ";
  fin.close();
  fhis.close();
  fcorrect.close();
  exit(1);
}

int main(int argc, char** argv) {
  if (argc!=4) {
    cout << "The input has incorrect number of parameters" << endl;
    return 1;
  }

  fin.open( argv[1], fstream::in );
  fhis.open( argv[2], fstream::in );
  fcorrect.open( argv[3], fstream::in );

  fin >> N >> M;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if (!(fin >> input[i][j])) die("Incorrert input file!");
    }
  }

  string correct;
  fcorrect >> correct;

  for(int i=0;i<3*N;i++){
    if (!(fhis >> his[i])){ die("Incorrect format of output - less lines than expected"); }
    if ( i == 0){
      if (his[i] == "Impossible!"){
        if ( correct == his[i] ){
          cout << "OK" << endl;
          fin.close();
          fhis.close();
          fcorrect.close();
          return 0;
        }else{
          die("Contestant thinks there is no solution, but there is!");
        }
      }
    }
  }

  char c;
  fhis >> c;
  if (!fhis.eof()){
    die("Incorrect format of output - too many lines");
  }

  memset( hisedges, 0, sizeof( hisedges) );

  for(int i=0;i<3*N;i++){
    if (his[i].length() != M*3) die("Incorrect length of a line");
    for(int i=0;i<N;i++){
      for(int j=0;j<M;j++){
        if ( his[3*i][3*j] != '.') die("There is not a dot in a corner");
        if ( his[3*i+2][3*j] != '.') die("There is not a dot in a corner");
        if ( his[3*i+2][3*j+2] != '.') die("There is not a dot in a corner");
        if ( his[3*i][3*j+2] != '.') die("There is not a dot in a corner");

        if ( input[i][j] == 0) if ( his[3*i+1][3*j+1] != '.') die("There is not a dot in a centre of an empty square");
        if ( input[i][j] != 0) if ( his[3*i+1][3*j+1] != 'O') die("There is not 'O' in a centre of an empty square");

        if ( his[3*i][3*j+2] != '.' && his[3*i][3*j+2] != 'X' ) die("There is incorrect symbol in a square");
        if ( his[3*i+2][3*j+2] != '.' && his[3*i+2][3*j+2] != 'X' ) die("There is incorrect symbol in a square");
        if ( his[3*i+2][3*j] != '.' && his[3*i+2][3*j] != 'X' ) die("There is incorrect symbol in a square");
        if ( his[3*i][3*j] != '.' && his[3*i][3*j] != 'X' ) die("There is incorrect symbol in a square");

        if ( his[3*i][3*j+1] == 'X' ) hisedges[i][j][0] = 1;
        if ( his[3*i+1][3*j+2] == 'X' ) hisedges[i][j][2] = 1;
        if ( his[3*i+1][3*j] == 'X' ) hisedges[i][j][1] = 1;
        if ( his[3*i+2][3*j+1] == 'X' ) hisedges[i][j][3] = 1;

      }
    }
  }

  for(int i=0;i<N;i++)for(int j=0;j<M;j++){
    int a = 0;
    for(int k=0;k<4;k++) a+= hisedges[i][j][k];
    if (a != input[i][j]) die("Number of alliances of a tile does not correspond to input requirements");
  }

  for(int i=0;i<N;i++){
    if (hisedges[i][0][1] != 0 || hisedges[i][M-1][2] != 0) die("Edge leads out of the rectangle");
  }
  for(int i=0;i<M;i++){
    if (hisedges[0][i][0] != 0 || hisedges[N-1][i][3] != 0) die("Edge leads out of the rectangle");
  }

  for(int i=0;i<N;i++){
    for(int j=0;j<M-1;j++) if ( hisedges[i][j][2] != hisedges[i][j+1][1]) die("Edge does not meet counterpart from the neighbour");
  }
  for(int i=0;i<N-1;i++){
    for(int j=0;j<M;j++) if ( hisedges[i][j][3] != hisedges[i+1][j][0]) die("Edge does not meet counterpart from the neighbour");
  }

  for(int i=0;i<N;i++) for(int j=0;j<M;j++) if (input[i][j] == 2){
    if ( hisedges[i][j][3] == 1 && hisedges[i][j][0] == 1) die("Two opposite neigbours");
    if ( hisedges[i][j][1] == 1 && hisedges[i][j][2] == 1) die("Two opposite neigbours");
  }

  cout << "OK" << endl;
  fhis.close();
  fin.close();
  fcorrect.close();
  return 0;
}
