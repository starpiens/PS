#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N = 101;
const int MAX_K = 1e5 + 1;
int dp[MAX_N][MAX_K];
int N, K;
int w[MAX_N], v[MAX_N];

int main() {
    scanf("%d %d", &N, &K);
    for (int i = 1; i <= N; i++)
        scanf("%d %d", &w[i], &v[i]);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            if (j >= w[i])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
        }
    }
    printf("%d", dp[N][K]);
    return 0;
}