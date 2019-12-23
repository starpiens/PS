#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef unsigned long long llu;

int in[101][101];
int sum[101][101];

struct Rec {
  int r1, c1, r2, c2;
  llu s() {
      return sum[r2][c2] - sum[r2][c1 - 1] - sum[r1 - 1][c2] + sum[r1 - 1][c1 - 1];
  }
};

vector<pair<Rec, Rec>> div(Rec rec) {
    vector<pair<Rec, Rec>> ret;
    for (int i = rec.r1; i < rec.r2; i++) {
        Rec rec0 = {rec.r1, rec.c1, i, rec.c2};
        Rec rec1 = {i + 1, rec.c1, rec.r2, rec.c2};
        ret.emplace_back(rec0, rec1);
    }
    for (int i = rec.c1; i < rec.c2; i++) {
        Rec rec0 = {rec.r1, rec.c1, rec.r2, i};
        Rec rec1 = {rec.r1, i + 1, rec.r2, rec.c2};
        ret.emplace_back(rec0, rec1);
    }
    return ret;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            scanf(" %1d", &in[i][j]);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + in[i][j];

    llu ans = 0;
    vector<pair<Rec, Rec>> recs1 = div({1, 1, N, M});
    for (auto i : recs1) {
        Rec rec0, rec1, rec2;
        vector<pair<Rec, Rec>> recs2;

        rec0 = i.first;
        recs2 = div(i.second);
        for (auto j : recs2) {
            rec1 = j.first;
            rec2 = j.second;
            ans = max(ans, rec0.s() * rec1.s() * rec2.s());
        }

        rec0 = i.second;
        recs2 = div(i.first);
        for (auto j : recs2) {
            rec1 = j.first;
            rec2 = j.second;
            ans = max(ans, rec0.s() * rec1.s() * rec2.s());
        }
    }

    printf("%llu", ans);
    return 0;
}