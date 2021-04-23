#include <cstdio>
#include <algorithm>

using namespace std;
int R, C;
int dp[750][750][2];
int ans = 0;

int main() {
    scanf("%d %d", &R, &C);
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            int in;
            scanf(" %1d", &in);
            if (!in) continue;
            dp[i][j][0] = dp[i][j][1] = 1;
            if (i > 0 && j > 0)
                dp[i][j][0] = dp[i - 1][j - 1][0] + 1;
            if (i > 0 && j < C - 1)
                dp[i][j][1] = dp[i - 1][j + 1][1] + 1;
            int sz = min(dp[i][j][0], dp[i][j][1]);
            while (sz > ans) {
                if (dp[i - sz + 1][j - sz + 1][1] >= sz &&
                    dp[i - sz + 1][j + sz - 1][0] >= sz) {
                    ans = sz;
                    break;
                }
                sz--;
            }
        }
    }

    printf("%d", ans);

    return 0;
}