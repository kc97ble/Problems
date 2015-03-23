n = int(raw_input())
A = [[int(x) for x in raw_input().split()] for i in range(n)]

kaviarne = []
for i in range(n):
    for j in range(n):
        if A[i][j]:
            kaviarne.append((i, j))
k = len(kaviarne)

def pridaj_obdlznik(S, x1, y1, x2, y2):
    if 0 <= x1 <= x2 < n and 0 <= y1 <= y2 < n:
        S[y1][x1] += 1
        S[y1][x2 + 1] -= 1
        S[y2 + 1][x1] -= 1
        S[y2 + 1][x2 + 1] += 1
        
def pridaj_kus_uhlopriecky(U, cislo, od, do):
    if 0 <= od <= do < len(U[cislo]):
        U[cislo][od] += 1
        U[cislo][do + 1] -= 1

R = [[False] * n for i in range(n)]
if k <= 2 * n - 1:
    S = [[0] * (n + 1) for i in range(n + 1)]
    
    UH = [[0] * (n + 1) for i in range(2 * n - 1)]
    
    UV = [[0] * (n + 1) for i in range(2 * n - 1)]
    for k1 in range(len(kaviarne)):
        for k2 in range(k1 + 1, len(kaviarne)):
            y1, x1 = kaviarne[k1]
            y2, x2 = kaviarne[k2]
            if x1 > x2:
                x1, y1, x2, y2 = x2, y2, x1, y1
            hlavna = (y1 <= y2)
            # le*ia na rovnakej farbe*
            if (x1 + y1) % 2 != (x2 + y2) % 2:
                continue
            if abs(x1 - x2) == abs(y1 - y2):
                # kaviarne le*ia na spolo*nej uhloprie*ke
                if hlavna:
                    pridaj_obdlznik(S, 0, y2, x1, n - 1)
                    pridaj_obdlznik(S, x2, 0, n - 1, y1)
                    pridaj_kus_uhlopriecky(UV, x1 + y2, y1, y2)
                else:
                    pridaj_obdlznik(S, 0, 0, x1, y2)
                    pridaj_obdlznik(S, x2, y1, n - 1, n - 1)
                    pridaj_kus_uhlopriecky(UH, x1 - y2 + n - 1, x1, x2)
            elif abs(x1 - x2) > abs(y1 - y2):
                #
                posun = (abs(x1 - x2) - abs(y1 - y2)) // 2
                if hlavna:
                    pridaj_obdlznik(S, x1 + posun, y2 + 1, x1 + posun, n - 1)
                    pridaj_obdlznik(S, x2 - posun, 0, x2 - posun, y1 - 1)
                    pridaj_kus_uhlopriecky(UV, x1 + y1 + posun + abs(y1 - y2), y1, y2)
                else:
                    pridaj_obdlznik(S, x1 + posun, 0, x1 + posun, y2 - 1)
                    pridaj_obdlznik(S, x2 - posun, y1 + 1, x2 - posun, n - 1)
                    pridaj_kus_uhlopriecky(UH, x1 - y1 + posun + abs(y1 - y2) + n - 1, x1 + posun, x2 - posun)
            else:
                # 
                posun = (abs(y1 - y2) - abs(x1 - x2)) // 2
                if hlavna:
                    pridaj_obdlznik(S, 0, y2 - posun, x1 - 1, y2 - posun)
                    pridaj_obdlznik(S, x2 + 1, y1 + posun, n - 1, y1 + posun)
                    pridaj_kus_uhlopriecky(UV, x1 + y1 + posun + abs(x1 - x2), y1 + posun, y2 - posun)
                else:
                    pridaj_obdlznik(S, 0, y2 + posun, x1 - 1, y2 + posun)
                    pridaj_obdlznik(S, x2 + 1, y1 - posun, n - 1, y1 - posun)
                    pridaj_kus_uhlopriecky(UH, x1 - y1 + posun + abs(x1 - x2) + n - 1, x1, x2)
    for i in range(n):
        for j in range(n):
            if i > 0:
                S[i][j] += S[i - 1][j]
                UV[j + i][i] += UV[j + i][i - 1]
            if j > 0:
                S[i][j] += S[i][j - 1]
                UH[j - i + n - 1][j] += UH[j - i + n - 1][j - 1]
            if i > 0 and j > 0:
                S[i][j] -= S[i - 1][j - 1]
            R[i][j] = (S[i][j] == 0 and UH[j - i + n - 1][j] == 0 and UV[j + i][i] == 0)
for x in R:
    print(' '.join(('0' if y else '1') for y in x))
