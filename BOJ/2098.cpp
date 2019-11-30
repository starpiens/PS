#include <bits/stdc++.h>

using namespace std;

int in[16][16];
int dp[1 << 16][16];

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            scanf("%d", &in[i][j]);
        for (int j = 0; j < (1 << N); j++)
            dp[j][i] = 2e9;
    }

    dp[1][0] = 0;
    for (int i = 2; i < (1 << N); i++) {
        for (int j = 1; j < N; j++) {
            if (!(i & (1 << j))) continue;  // j번째 bit 꺼져 있음
            for (int k = 0; k < N; k++)
                if (in[k][j])
                    dp[i][j] = min(dp[i][j], dp[i & ~(1 << j)][k] + in[k][j]);
        }
    }

    int ans = 2e9;
    for (int i = 1; i < N; i++)
        if (in[i][0])
            ans = min(ans, dp[(1 << N) - 1][i] + in[i][0]);
    printf("%d", ans);

    return 0;
}