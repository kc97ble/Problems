//by Puni Andrei-Paul - 100 puncte

#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int left[26][26], nr1[26][26], nr2[26][26], need[26];
int total_need, n,m;

//nrX[i][j] = nr de cartonase care au pus partea X in sus ...

stack <int> l[26][26];

#define Nmax 1000100

char sir[Nmax];


//bag buffer de 32 KB pt output :))
char buff[1<<15];


void read()
{
    FILE *f = fopen("teroristi.in","r");

    fscanf(f, "%d %d\n", &n, &m);

    fscanf(f, "%s\n", sir+1);

    for (int i = 1; i <= n; ++i)
    {
        sir[i] -= 'a';
        ++need[(int)sir[i]];
    }

    char Ai, Bi;

    for (int i = 1; i <= m; ++i)
    {
        fscanf(f, "%c %c\n", &Ai, &Bi);

        //printf("%c %c\n", A[i], B[i]);

        if (Ai > Bi)
            swap(Ai,Bi);
        Ai -= 'a';
        Bi -= 'a';
        ++left[(int)Ai][(int)Bi];
        l[(int)Ai][(int)Bi].push(i);
    }

    fclose(f);
}

int viz[26];

//daca pot sa cuplez litera lit
//folosind un cartonas de forma i, X
//si unul folosit deja de forma i, lit care e pus cu i in sus ...
inline bool cupleaza(int lit)
{
    if (viz[lit]) return false;
    viz[lit] = 1;

    //daca pot sa bag direct ...
    for (int i = 0; i < lit; ++i)
    if (left[i][lit] > 0)
    {
        --left[i][lit];
        ++nr2[i][lit];

        return true;
    }

    for (int i = lit; i < 26; ++i)
    if (left[lit][i] > 0)
    {
        --left[lit][i];
        ++nr1[lit][i];

        return true;
    }

    //daca pot sa smenuiesc ...

    for (int i = 0; i < lit; ++i)
    if (nr1[i][lit] > 0)
    if (cupleaza(i))
    {
        --nr1[i][lit];
        ++nr2[i][lit];

        return true;
    }

    for (int i = lit; i < 26; ++i)
    if (nr2[lit][i] > 0)
    if (cupleaza(i))
    {
        --nr2[lit][i];
        ++nr1[lit][i];

        return true;
    }

    return false;
}

void solve()
{

    vector<int> litere;

    for (int i = 0; i < 26; ++i)
        litere.push_back(i);

    //de dragul randommului :P
    random_shuffle(litere.begin(),litere.end());


    for (vector<int>::iterator it = litere.begin(); it != litere.end(); ++it)
    for (vector<int>::iterator it2 = litere.begin(); it2 != litere.end(); ++it2)
    {
        while (left[*it][*it2] > 0 && need[*it] > 0)
        {
            --left[*it][*it2];
            ++nr1[*it][*it2];
            --need[*it];
        }

        while (left[*it2][*it] > 0 && need[*it] > 0)
        {
            --left[*it2][*it];
            ++nr2[*it2][*it];
            --need[*it];
        }
    }


    bool ok = true;

    while (ok)
    {
        //de dragul randommului :P
        random_shuffle(litere.begin(),litere.end());

        ok = false;
        memset(viz, 0, sizeof viz);

        for (vector<int>::iterator it = litere.begin(); it != litere.end(); ++it)
        {
            while (need[*it] > 0)
            if (cupleaza(*it))
            {
                --need[*it];
                ok = true;
            }
                else
            break;
        }
    }
}


void write()
{
    FILE *f = fopen("teroristi.out","w");

    int afis = 0;

    setbuf(f ,buff);

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < 26; ++j)
        {
            if (nr1[(int)sir[i]][j] > 0)
            {
                fprintf(f, "%d ", l[(int)sir[i]][j].top());
                l[(int)sir[i]][j].pop();
                --nr1[(int)sir[i]][j];
                ++afis;
                break;
            }

            if (nr2[j][(int)sir[i]] > 0)
            {
                fprintf(f, "%d ", l[j][(int)sir[i]].top());
                l[j][(int)sir[i]].pop();
                --nr2[j][(int)sir[i]];
                ++afis;
                break;
            }
        }
    }
   /*
    if (afis == n)
        fprintf(f, "e ok ;)\n");
    else
        fprintf(f, "nu e ok :(\n");
*/
    fclose(f);
}

int main()
{
    read();

    solve();

    write();

    return 0;
}

