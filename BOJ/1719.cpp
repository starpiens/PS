#include <bits/stdc++.h>

using namespace std;

int prv[201][201];
int dp[201][201];

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dp[i][j] = (int) 1e8;
        }
        dp[i][i] = 0;
    }
    while (M--) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        dp[a][b] = dp[b][a] = c;
        prv[a][b] = b;
        prv[b][a] = a;
    }

    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                if (dp[i][j] > dp[i][k] + dp[k][j]) {
                    dp[i][j] = dp[i][k] + dp[k][j];
                    prv[i][j] = prv[i][k];
                }

    for (int i = 1; i <= N; i++, printf("\n"))
        for (int j = 1; j <= N; j++) {
            if (i == j) printf("- ");
            else printf("%d ", prv[i][j]);
        }

    return 0;
}