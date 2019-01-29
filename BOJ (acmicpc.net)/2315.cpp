#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long llu;

const llu INF = 4e18;

int N, M;
pair<int, int> in[1000];
llu dp[1000][1000];
llu sum[1000];

inline llu consume(int st, int end) {
    return sum[N - 1] - sum[end] + (st ? sum[st - 1] : 0);
}

inline int dist(int st, int end) {
    return in[end].first - in[st].first;
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &in[i].first, &in[i].second);
        sum[i] = (i ? sum[i - 1] : 0) + in[i].second;
        for (int j = 0; j < N; j++)
            dp[i][j] = INF;
    }
    M--;
    dp[M][M] = 0;

    // i < j
    for (int i = N - 1; i >= 0; i--)
        for (int j = max(i + 1, M); j < N; j++) {
            dp[i][j] = min({
                    dp[i][j - 1] + consume(i, j - 1) * dist(j - 1, j),  // i->(j-1), (j-1)->j
                    dp[j - 1][i] + consume(i, j - 1) * dist(i, j),
                    INF
            });
            dp[j][i] = min({
                    dp[j][i + 1] + consume(i + 1, j) * dist(i, i + 1),
                    dp[i + 1][j] + consume(i + 1, j) * dist(i, j),
                    INF
            });
            dp[i][j] = min({dp[i][j], dp[j][i] + consume(i, j) * dist(i, j)});
            dp[j][i] = min({dp[j][i], dp[i][j] + consume(i, j) * dist(i, j)});
        }

    printf("%llu", min(dp[0][N - 1], dp[N - 1][0]));

    return 0;
}

// dp[i][j] = min(dp[i][k] + k->j), min(dp[k][i] + i->j)
// 양 끝이 i와 j이고 끝점이 j일 때 낭비되는 전력의 최소값