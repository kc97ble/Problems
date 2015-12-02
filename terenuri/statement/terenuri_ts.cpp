/*
 * Author: Tiberiu Savin
 * Complexitate: O(N log N + M log (N + M))
 * Memorie: TODO
 */
#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

#define NMAX 200000
#define eps 1e-10
#define LOG_DEBUG 0

int N, M;
vector< pair<double, double> > V;
vector< pair<double, double> > conv;
vector< pair<double, double> > st;
set<pair<double, pair<double, double> > > S;

set<pair<double, pair<double, double> > >::iterator prev_it(
    set<pair<double, pair<double, double> > >::iterator it) {
  if (it == S.begin()) {
    it = S.end();
    it--;
    return it;
  } else {
    it--;
    return it;
  }
}

set<pair<double, pair<double, double> > >::iterator next_it(
    set<pair<double, pair<double, double> > >::iterator it) {
  it++;
  if (it == S.end()) {
    it = S.begin();
    return it;
  } else {
    return it;
  }
}

long double det(pair<double, double> P1, pair<double, double> P2,
                pair<double, double> P3) {
  return P1.first * P2.second + P2.first * P3.second + P3.first * P1.second -
      P1.first * P3.second - P3.first * P2.second - P2.first * P1.second;
}

void convex_hull() {
  sort(V.begin(), V.end());
  st.push_back(V[0]);
  st.push_back(V[1]);
  for (int i = 2; i < V.size(); i++) {
    pair<double, double> P1, P2, P3;
    P1 = st[st.size() - 2];
    P2 = st[st.size() - 1];
    P3 = V[i];
    while (st.size() >= 2 && det(P1, P2, P3) < -eps) {
      st.pop_back();
      P1 = st[st.size() - 2];
      P2 = st[st.size() - 1];
    }
    st.push_back(V[i]);
    if (LOG_DEBUG) {
      for (int i = 0; i < st.size(); i++) {
        printf("%.2lf %.2lf |", st[i].first, st[i].second);
      }
      printf("\n");
    }
  }

  for (int i = 0; i < st.size() - 1; i++) {
    conv.push_back(st[i]);
  }

  if (LOG_DEBUG) {
    printf("\nFirst Part:\n");
    for (int i = 0; i < st.size() - 1; i++) {
      printf("%.2lf %.2lf\n", st[i].first, st[i].second);
    }
  }

  reverse(V.begin(), V.end());
  st.clear();
  st.push_back(V[0]);
  st.push_back(V[1]);
  for (int i = 2; i < V.size(); i++) {
    pair<double, double> P1, P2, P3;
    P1 = st[st.size() - 2];
    P2 = st[st.size() - 1];
    P3 = V[i];
    while (st.size() >= 2 && det(P1, P2, P3) < -eps) {
      st.pop_back();
      P1 = st[st.size() - 2];
      P2 = st[st.size() - 1];
    }
    st.push_back(V[i]);
  }

  for (int i = 0; i < st.size() - 1; i++) {
    conv.push_back(st[i]);
  }
}

void delete_prev(set<pair<double, pair<double, double> > >::iterator it,
                 pair<double, double> P) {
  set<pair<double, pair<double, double> > > :: iterator it1, it2;

  it1 = it;
  it2 = prev_it(it);

  if (LOG_DEBUG) {
    printf("Testing points %lf %lf, %lf %lf, %lf %lf\n", P.first, P.second,
        (*it1).second.first, (*it1).second.second, (*it2).second.first,
        (*it2).second.second);
  }

  while (det(P, (*it1).second, (*it2).second) > eps) {
    if (LOG_DEBUG) {
      printf("Erased point %lf %lf\n", (*it1).second.first,
             (*it1).second.second);
    }

    S.erase(it1);
    it1 = it2;
    it2 = prev_it(it1);
  }
}

void delete_next(set<pair<double, pair<double, double> > >::iterator it,
                 pair<double, double> P) {
  set<pair<double, pair<double, double> > > :: iterator it1, it2;
  it1 = it;
  it2 = next_it(it);

  if (LOG_DEBUG) {
    printf("Testing points %lf %lf, %lf %lf, %lf %lf\n", P.first, P.second,
        (*it1).second.first, (*it1).second.second, (*it2).second.first,
        (*it2).second.second);
  }

  double d = det(P, (*it1).second, (*it2).second) < -eps;
  if (LOG_DEBUG) {
    printf("Determinant: %lf\n", d);
  }

  while (det(P, (*it1).second, (*it2).second) < -eps) {
    if (LOG_DEBUG) {
      printf("Erased point %lf %lf\n", (*it1).second.first, (*it1).second.second);
    }
    S.erase(it1);
    it1 = it2;
    it2 = next_it(it1);
  }
  return;
}

int main() {
  freopen("terenuri.in", "r", stdin);
  freopen("terenuri.out", "w", stdout);

  scanf("%d %d ", &N, &M);
  for (int i = 1; i <= N; i++) {
    double x, y;
    scanf("%lf %lf ", &x, &y);
    V.push_back(make_pair(x, y));
  }

  convex_hull();

  double Sx = 0, Sy = 0;
  for (int i = 0; i < conv.size(); i++) {
    Sx = Sx + conv[i].first;
    Sy = Sy + conv[i].second;
  }

  pair<double, double> G = make_pair(Sx / conv.size(), Sy / conv.size());

  if (LOG_DEBUG) {
    printf("Convex Hull:\n");
  }
  for (int i = 0; i < conv.size(); i++) {
    double x = conv[i].first, y = conv[i].second;
    double angle = atan2(y, x);

    if (LOG_DEBUG) {
      printf("%lf %lf %lf\n", x, y, angle);
    }

    x -= G.first;
    y -= G.second;
    angle = atan2(y, x);

    S.insert(make_pair(angle, make_pair(x, y)));
  }

  set<pair<double, pair<double, double> > >::iterator it;
  if (LOG_DEBUG) {
    printf("\nPunctul G: %lf %lf\n\n", G.first, G.second);
    printf("Set:\n");
    for (it = S.begin(); it != S.end(); it++) {
      printf("%lf %lf %lf\n", (*it).first, (*it).second.first,
        (*it).second.second);
    }
  }

  if (LOG_DEBUG) {
    printf("Convex hull size: %d\n", S.size());
    printf("\nIncepe invazia taranilor\n");
  } else {
    printf("%d\n", S.size());
  }

  for (int i = 1; i <= M; i++) {
    double x, y;
    scanf("%lf %lf ", &x, &y);
    x = x - G.first;
    y = y - G.second;

    pair<double, pair<double, double> > P = make_pair(atan2(y, x),
        make_pair(x, y));

    set<pair<double, pair<double, double> > >::iterator it1, it2, it;
    it2 = S.upper_bound(P);
    if (it2 == S.end()) {
      it2 = S.begin();
    }
    it1 = prev_it(it2);

    if (LOG_DEBUG) {
      printf("\n\nPoint %lf %lf with atan = %lf enters the stage:\n", x, y, 
              P.first);
      printf("Neighbours: %lf %lf", (*it1).second.first, (*it1).second.second);
      printf(" and %lf %lf\n", (*it2).second.first, (*it2).second.second);
    }

    pair<double, double> P1 = (*it1).second, P2 = (*it2).second,
        P3 = make_pair(x, y);

    if (det(P1, P2, P3) > eps) {
      if (LOG_DEBUG) {
        printf("%.2lf %.2lf Inside", x, y);
      } else {
        printf("%d\n", S.size());
      }
      continue;
    }

    delete_prev(it1, make_pair(x, y));
    delete_next(it2, make_pair(x, y));


    if (LOG_DEBUG) {
      printf("Set size %d\n", S.size());
      S.insert(P);
      printf("Set size after insert %d\n", S.size());
     
      printf("Set after peasant %d\n", i);
      for (it = S.begin(); it != S.end(); it++) {
//        printf("%lf %lf\n", (*it).second.first, (*it).second.second);
      }
    } else {
      S.insert(P);
      printf("%d\n", S.size());
    }
  }

  return 0;
}
