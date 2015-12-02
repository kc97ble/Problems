// Tataroiu Bogdan-Cristian
#include <cstdio>
#include <cassert>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

const int MAXN = 100000;
const int MAXM = 100000;
const double EPS = 1e-10;

int N, M, o[MAXN];
double x[MAXN + MAXM], y[MAXN + MAXM];

class cmp_sort {
public:
    bool operator()(int a, int b) {
        if (fabs(x[a] - x[b]) < EPS) {
            return y[a] < y[b];
        }
        return x[a] < x[b];
    }
};

template<class I>
class I::iterator prv(I &set, class I::iterator it) {
    if (it == set.begin()) {
        it = set.end();
    }
    it--;
    return it;
}

template<class I>
class I::iterator nxt(I &set, class I::iterator it) {
    it++;
    if (it == set.end()) {
        it = set.begin();
    }
    return it;
}

inline void get_coef(double X1, double Y1, double X2, double Y2,
                     double &A, double &B, double &C) {
    A = Y2 - Y1;
    B = X1 - X2;
    C = -Y2 * X1 + X2 * Y1;
}

inline int semn(double A, double B, double C, double X, double Y) {
    double D = A * X + B * Y + C;
    if (fabs(D) < EPS) {
        return 0;
    } else if (D < 0) {
        return -1;
    } else {
        return 1;
    }
}

inline int semn(int a, int b, int c) {
    double A, B, C;
    get_coef(x[a], y[a], x[b], y[b], A, B, C);
    return semn(A, B, C, x[c], y[c]);
}

inline void convex_hull(vector<int> &st_low) {
    st_low.clear();
    vector<int> st_high;
    st_high.push_back(o[0]);
    st_low.push_back(o[0]);
    for (int i = 1; i < N; i++) {
        for (; st_low.size() > 1 && semn(st_low[st_low.size() - 2],
                                         st_low.back(), o[i]) < 0; ) {
            st_low.pop_back();
        }
        for (; st_high.size() > 1 && semn(st_high[st_high.size() - 2],
                                          st_high.back(), o[i]) > 0; ) {
            st_high.pop_back();
        }
        st_low.push_back(o[i]);
        st_high.push_back(o[i]);
    }

    assert(st_low.back() == st_high.back());
    st_high.pop_back();
    for (; !st_high.empty(); ) {
        st_low.push_back(st_high.back());
        st_high.pop_back();
    }
    assert(st_low.front() == st_low.back());
    st_low.pop_back();
}

int main() {
    assert(freopen("terenuri.in", "rt", stdin));
    assert(freopen("terenuri.out", "wt", stdout));

    assert(scanf("%d %d", &N, &M) == 2);
    assert(3 <= N && N <= MAXN);
    assert(0 <= M && M <= MAXM);

    for (int i = 0; i < N; i++) {
        assert(scanf("%lf %lf", x + i, y + i) == 2);
        o[i] = i;
    }

    sort(o, o + N, cmp_sort());

    // Infasuratoarea convexa a punctelor din input.
    vector<int> H;
    convex_hull(H);

    // Gasim punctul G
    double Gx = 0, Gy = 0;
    for (size_t k = 0; k < H.size(); k++) {
        Gx += x[H[k]];
        Gy += y[H[k]];
    }
    Gx /= H.size();
    Gy /= H.size();

    // Translatam sistemul astfel incat G sa fie origine.
    for (int i = 0; i < N; i++) {
        x[i] -= Gx;
        y[i] -= Gy;
    }

    // Mentine punctele din infasuratoare sortate dupa unghi.
    set<pair<double, int> > S;
    for (size_t k = 0; k < H.size(); k++) {
        S.insert(make_pair(atan2(y[H[k]], x[H[k]]), H[k]));
    }

    printf("%d\n", (int)S.size());
    for (int i = N; i < N + M; i++, printf("%d\n", (int)S.size())) {
        assert(scanf("%lf %lf", x + i, y + i) == 2);
        x[i] -= Gx;
        y[i] -= Gy;

        double cur_angle = atan2(y[i], x[i]);

        set<pair<double, int> > :: iterator it, itprv;
        it = S.lower_bound(make_pair(cur_angle, i));
        if (it == S.end()) {
            it = S.begin();
        }
        itprv = prv<typeof(S)>(S, it);

        double A, B, C;
        get_coef(x[itprv->second], y[itprv->second],
                 x[it->second], y[it->second], A, B, C);
        if (semn(A, B, C, x[i], y[i]) < 0) {
            // Punctul este inclus in poligon.
            continue;
        }

        S.insert(make_pair(cur_angle, i));

        it = prv<typeof(S)>(S, it);
        assert(it->second == i);
        for (; semn(prv<typeof(S)>(S, prv<typeof(S)>(S, it))->second,
                    prv<typeof(S)>(S, it)->second, it->second) > 0; ) {
            S.erase(prv<typeof(S)>(S, it));
        }
        for (; semn(nxt<typeof(S)>(S, nxt<typeof(S)>(S, it))->second,
                    nxt<typeof(S)>(S, it)->second, it->second) < 0; ) {
            S.erase(nxt<typeof(S)>(S, it));
        }
    }

    return 0;
}
