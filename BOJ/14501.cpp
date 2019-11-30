#include <bits/stdc++.h>
using namespace std;

int in[16][2], dp[17];

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d %d", &in[i][0], &in[i][1]);

    for (int i = 1; i <= N; i++) {
        dp[i + 1] = max(dp[i + 1], dp[i]);
        if (i + in[i][0] <= N + 1) {
            dp[i + in[i][0]] = max(dp[i + in[i][0]], dp[i] + in[i][1]);
        }
    }
    printf("%d", dp[N + 1]);

    return 0;
}