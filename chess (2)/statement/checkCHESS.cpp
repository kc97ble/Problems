#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdio>

using namespace std;

#define input "CHESS.INP"
#define answer "CHESS.ANS"
#define output "CHESS.OUT"
#define maxN 1000

char workDir[1000], testDir[1000];
ifstream fi, fo, fa;
int a[maxN], n, m, jm;
bool b[maxN][maxN];

void openfiles()
{
    cin.getline(testDir, 1000);
    cin.getline(workDir, 1000);

    char finp[1000], fout[1000], fans[1000];
    strcpy(finp, testDir);
    strcat(finp, "\\");
    strcat(finp, input);
    fi.open(finp);

    strcpy(fans, testDir);
    strcat(fans, "\\");
    strcat(fans, answer);
    fa.open(fans);

    strcpy(fout, workDir);
    strcat(fout, "\\");
    strcat(fout, output);
    fo.open(fout);
}

void closefiles()
{
    fi.close();
    fo.close();
    fa.close();
}

string checkans()
{
    fi>>n;
    for (int i = 0; i < n; i++)
        fi>>a[i];
    memset(b, false, sizeof(b));

    fo>>m;
    fa>>jm;
    cout<<"Tra loi: "<<m<<endl;
    cout<<"Dap an: :"<<jm<<endl;

    if (jm < m)
        return "So quan co khong toi uu!";

    int x, y;
    for (int i = 0; i < m; i++)
    {
        fo>>x>>y;

        if (x < 1 || x > n)
            return "Quan co dat tai vi tri khong hop le!";
        if (y < 1 || y > a[x - 1])
            return "Quan co dat tai vi tri khong hop le!";

        for (int j = 0; j < n; j++)
            b[j][y - 1] = true;

        for (int j = 0; j < a[x - 1]; j++)
            b[x - 1][j] = true;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < a[i]; j++)
        {
            if (!b[i][j])
                return "Ban co chua bi chieu het!";
        }
    }

    return "";
}

void marking()
{
    string err = checkans();
    if (err != "")
        cout<<"0.0"<<endl;
    else
    {
        cout<<"Ket qua dung!"<<endl;
        cout<<"1.0"<<endl;
    }
}

int main()
{
    openfiles();
    marking();
    closefiles();
}
