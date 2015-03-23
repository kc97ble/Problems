//by Puni Andrei-Paul
#include <cstdio>
#include <cassert>

using namespace std;

#define FIN "telefon.in"
#define FOUT "telefon.out"

#define Nmax 100100

int gi[Nmax], t[Nmax],tt[Nmax], n, nrModificari;
bool viz[Nmax];

void read()
{
    FILE *f = fopen(FIN, "r");

    fscanf(f, "%d", &n);
    
    assert(1 < n && n <= 100000);

    for (int i=1;i<=n;++i)
    {
        fscanf(f, "%d", &t[i]);
        assert(0 < t[i] && t[i] <= n);
        assert(t[i] != i);
        tt[i] = t[i];
        //calculez gradele de intrare
        ++gi[t[i]];
    }
    fclose(f);
}

void solve()
{
    int inceput = 0, sfarsit = 0;
    int nrFrunze = 0, nrCicluri = 0;
    int nod;

    //rezolv arbori agatati
    for (int i=1;i<=n;++i)
    if (gi[i] == 0 && viz[i] == false)
    {
        ++nrFrunze;

        nod = i;
        viz[i] = i;

        while (viz[t[nod]] == false)
        {
            nod = t[nod];
            viz[nod] = true;
        }

        if (inceput == 0)
            inceput = i;

        if (sfarsit == 0)
            sfarsit = nod;

        t[nod] = inceput;
        inceput = i;
    }
    
    //rezolv restul ciclurilor
    for (int i=1;i<=n;++i)
    if (viz[i] == false)
    {
        ++nrCicluri;
        
        nod = i;
        viz[i] = i;

        while (viz[t[nod]] == false)
        {
            nod = t[nod];
            viz[nod] = true;
        }

        if (inceput == 0)
            inceput = i;

        if (sfarsit == 0)
            sfarsit = nod;

        t[nod] = inceput;
        inceput = i;
    }
    
    if (nrFrunze == 0 && nrCicluri == 1)
        nrModificari = 0;
    else
        {
            nrModificari = nrFrunze + nrCicluri;
            t[sfarsit] = inceput;
        }
}

void write()
{
    FILE *f = fopen(FOUT, "w");

    fprintf(f, "%d\n", nrModificari);

    for (int i=1;i<=n;++i)
        if (tt[i] != t[i])
            fprintf(f, "%d %d\n", i, t[i]);

    fclose(f);
}

int main()
{
    read();

    solve();

    write();

    return 0;
}
