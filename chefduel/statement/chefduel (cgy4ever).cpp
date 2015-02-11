#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int START[] = {0 , 40 , 40 , 40 , 40 , 40 , 40 , 40 , 40 , 40 , 40};
int FACTOR[] = {0 , 98 , 101 , 100 , 100 , 100 ,100 , 100 , 100 , 100 , 100};

int NOWTEST;

int Nmaze , NOWBEST;
int MAXITERATION;
bool succ;

struct coord
{
    int x , y;
    coord(){x = y = 0;}
    coord(int _x , int _y){x = _x , y = _y;}
    coord operator +(coord u){return coord(x+u.x , y+u.y);}
    bool operator ==(coord u){return (x == u.x) && (y == u.y);}
}Queue[10001] , F[4];

string fName = "EWSN";
string Oppo = "WENS";

int head , tail;

struct maze
{
    int n , m;
    coord e;
    bool free[75][75];
    int dist[75][75];
    void clear(){memset(free , false , sizeof(free));}
    bool at(coord c){return free[c.x][c.y];}
    int di(coord c){return dist[c.x][c.y];}
    void calcDist()
    {
        memset(dist , 0xe , sizeof(dist));
        dist[e.x][e.y] = 0;
        Queue[1] = e;
        head = tail = 1;
        while(tail <= head)
        {
            coord Now = Queue[tail];
            for(int i = 0 ; i < 4 ; i++)
            {
                coord Next = Now + F[i];
                if(at(Next))
                    if(di(Next) > di(Now) + 1)
                    {
                        dist[Next.x][Next.y] = di(Now) + 1;
                        head ++;
                        Queue[head] = Next;
                    }
            }
            ++tail;
        }
    }
}M[26];

struct state
{
    coord pos[26];
    state *prev;
    char lastMove;
    int alreadyMoved;
    state(){prev = NULL , alreadyMoved = 0 , lastMove = 'X';}
    state move(int f)
    {
        state ret;
        ret.prev = this;
        ret.alreadyMoved = alreadyMoved + 1;
        ret.lastMove = fName[f];
        for(int i = 1 ; i <= Nmaze ; i++)
            if(!M[i].at(pos[i]+F[f]) || (M[i].e == pos[i]))
                ret.pos[i] = pos[i];
            else
                ret.pos[i] = pos[i] + F[f];
        return ret;
    }
}Start , S[200001];

struct solution
{
    virtual string solve() = 0;
} *solutionList[101];

int Nsolution;

bool finish(state A)
{
    for(int i = 1 ; i <= Nmaze ; i++)
        if(!(M[i].e == A.pos[i]))
            return false;
    return true;
}

struct BasicSolution : solution
{
    int mapping[26];
    
    void makeMapping()
    {
        for(int i = 1 ; i <= Nmaze ; i++)
            mapping[i] = i;
        for(int it = Nmaze ; it >= 1 ; it--)
            for(int i = 1 ; i < Nmaze ; i++)
                if(M[mapping[i]].di(Start.pos[mapping[i]]) < M[mapping[i+1]].di(Start.pos[mapping[i+1]]))
                    swap(mapping[i] , mapping[i+1]);
    }
    
    bool betterThan(state A , state B)
    {
        for(int I = 1 ; I <= Nmaze ; I++)
        {
            int i = mapping[I];
            if(M[i].di(A.pos[i]) < M[i].di(B.pos[i]))
                return true;
            if(M[i].di(A.pos[i]) > M[i].di(B.pos[i]))
                return false;
        }
        return true;
    }
    string solve()
    {
        makeMapping();
        S[1] = Start;
        for(int i = 1 ; ; i++)
        {
            if(finish(S[i]))
            {
                string OUTPUT = "";
                state *t = &S[i];
                while(t->prev != NULL)
                {
                    OUTPUT = t->lastMove + OUTPUT;
                    t = t->prev;
                }
                return OUTPUT;
            }
            else
            {
                state t = S[i].move(0);
                for(int j = 1 ; j < 4 ; j++)
                {
                    state u = S[i].move(j);
                    if(betterThan(u , t))
                        t = u;
                }
                S[i+1] = t;
            }
            if(i > MAXITERATION)return "X";
            if(S[i].alreadyMoved > NOWBEST)return "X";
        }
    }
};

int Tot;
int V[200001];
int w[200001];

void clear()
{
    Tot = 0;
}

void upfix(int node)
{
    if(node <= 1)return;
    if(V[w[node/2]] > V[w[node]])
    {
        swap(w[node/2] , w[node]);
        upfix(node/2);
    }
}

void downfix(int node)
{
    if(2*node+1 <= Tot)
    {
        if(V[w[2*node]] < V[w[2*node+1]])
        {
            if(V[w[2*node]] < V[w[node]])
            {
                swap(w[2*node] , w[node]);
                downfix(2*node);
            }
        }
        else
        {
            if(V[w[2*node+1]] < V[w[node]])
            {
                swap(w[2*node+1] , w[node]);
                downfix(2*node+1);
            }
        }
    }
    else if(2*node <= Tot)
    {
        if(V[w[2*node]] < V[w[node]])
        {
            swap(w[2*node] , w[node]);
            downfix(2*node);
        }
    }
}
    
void add(int which , int value)
{
    Tot ++;
    w[Tot] = which;
    V[which] = value;
    upfix(Tot);
}
    
int findMin()
{
    return w[1];
}

int delMin()
{
    swap(w[Tot] , w[1]);
    Tot --;
    downfix(1);
}

struct HeuristicSearch : solution
{
    int c;
    HeuristicSearch(int _c){c = _c;}
    
    int Heuristic(int w)
    {
        int minD = 100000;
        int maxD = 0;
        int already = S[w].alreadyMoved;
        int expect = 0;
        for(int i = 1 ; i <= Nmaze ; i++)
        {
            expect += M[i].di(S[w].pos[i]);
            maxD = max(maxD , M[i].di(S[w].pos[i]));
        }
        return 200 * already + 2 * c * (expect) + FACTOR[NOWTEST] * maxD;
    }
    
    string solve()
    {
        clear();
        S[1] = Start;
        add(1 , Heuristic(1));
        int p = 1;
        int countFinish = 0;
        string nowBest = "X";
        int MAXFINISH = 10;
        while(true)
        {
            if(countFinish > MAXFINISH)return nowBest;
            if(Tot == 0 || p > MAXITERATION)return nowBest;
            int now = findMin();
            if(S[now].alreadyMoved > NOWBEST)return nowBest;
            delMin();
            if(finish(S[now]))
            {
                string OUTPUT = "";
                state *t = &S[now];
                while(t->prev != NULL)
                {
                    OUTPUT = t->lastMove + OUTPUT;
                    t = t->prev;
                }
                countFinish ++;
                if(nowBest == "X" || (OUTPUT.length() < nowBest.length()))
                    nowBest = OUTPUT;
            }
            else
            {
                for(int f = 0 ; f < 4 ; f++)
                    if(Oppo[f] != S[now].lastMove)
                    {
                        p ++;
                        S[p] = S[now].move(f);
                        add(p , Heuristic(p));
                    }
            }
        }
    }
};

struct StepHeuristicSearch : solution
{
    int c;
    StepHeuristicSearch(int _c){c = _c;}
    
    int Heuristic(int w)
    {
        int maxD = 0;
        int minD = 1000000;
        int already = S[w].alreadyMoved;
        int expect = 0;
        for(int i = 1 ; i <= Nmaze ; i++)
        {
            expect += M[i].di(S[w].pos[i]);
            maxD = max(maxD , M[i].di(S[w].pos[i]));
            minD = max(minD , M[i].di(S[w].pos[i]));
        }
        return 200 * already + c * (2 * expect + maxD);
    }
    
    string solve()
    {
        clear();
        S[1] = Start;
        add(1 , Heuristic(1));
        int p = 1;
        int countFinish = 0;
        string ret = "";
        int MoveDist = 11;
        while(true)
        {
            int now = findMin();
            delMin();
            if(succ == true && S[now].alreadyMoved + ret.length() >= NOWBEST)return "X";
            if(finish(S[now]) || S[now].alreadyMoved >= MoveDist)
            {
                //cout << ret << endl;
                string OUTPUT = "";
                state *t = &S[now];
                while(t->prev != NULL)
                {
                    OUTPUT = t->lastMove + OUTPUT;
                    t = t->prev;
                }
                ret += OUTPUT;
                if(finish(S[now]))return ret;
                clear();
                S[1] = S[now];
                S[1].alreadyMoved = 0;
                S[1].prev = NULL;
                S[1].lastMove = 'X';
                add(1 , Heuristic(1));
            }
            else
            {
                for(int f = 0 ; f < 4 ; f++)
                    if(Oppo[f] != S[now].lastMove)
                    {
                        p ++;
                        S[p] = S[now].move(f);
                        add(p , Heuristic(p));
                    }
            }
        }
    }
};

void prepare(int CaseID)
{
    F[0] = coord(0 , 1);
    F[1] = coord(0 , -1);
    F[2] = coord(1 , 0);
    F[3] = coord(-1 , 0);
    Nsolution = 0;
    solutionList[++Nsolution] = new BasicSolution();
    
    
    for(int i = START[CaseID] ; i <= 80; i += 5)
        solutionList[++Nsolution] = new HeuristicSearch(i);
        
    solutionList[++Nsolution] = new StepHeuristicSearch(30);
}

string runALL()
{
    NOWBEST = 100000000;
    string ret = "X";
    //bool alreadyHave = false;
    for(int i = 1 ; i < Nsolution ; i++)
    {
        string t = solutionList[i]->solve();
        //cout << "Solution #" << i << " : " << (t == "X" ? -1 : (int)t.length()) << endl;
        if(t != "X")
        {
            NOWBEST = min(NOWBEST , (int)t.length());
            if(t.length() < ret.length() || ret == "X")ret = t;
            if(i > 1)
            {
                succ = true;
                break;
            }
        }
        if(i == 1)
            NOWBEST = int(NOWBEST * 0.9);
    }

    string t = solutionList[Nsolution]->solve();
    if(t != "X")
    {
        NOWBEST = min(NOWBEST , (int)t.length());
        if(t.length() < ret.length() || ret == "X")ret = t;
    }

    return ret;
}



int main()
{
    //freopen("input.txt" , "r" , stdin);
    //freopen("output.txt" , "w" , stdout);
    ios :: sync_with_stdio(false);
    
    int TestCase;
    while(cin >> TestCase)
    {
        for(int CaseID = 1 ; CaseID <= TestCase ; CaseID ++)
        {
            NOWTEST = CaseID;
            cin >> Nmaze;
            prepare(CaseID);
            MAXITERATION = min(Nmaze+1 , 8) * 6000;
            for(int i = 1 ; i <= Nmaze ; i++)
            {
                cin >> M[i].n >> M[i].m;
                M[i].clear();
                for(int x = 1 ; x <= M[i].n ; x ++)
                {
                    string s;
                    cin >> s;
                    for(int y = 1 ; y <= M[i].m ; y++)
                    {
                        char c = s[y-1];
                        if(c == '.' || c == 'E' || c == 'S')
                            M[i].free[x][y] = true;
                        if(c == 'E')
                            M[i].e = coord(x , y);
                        if(c == 'S')
                            Start.pos[i] = coord(x , y);
                    }
                }
                M[i].calcDist();
            }
            cout << runALL() << endl;
        }
    }
    return 0;
}