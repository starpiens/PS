#include <bits/stdc++.h>

using namespace std;

char str[] = "MOLA";
char in[501][502];
int N, dp[501][501];

int find(int r, int c, int s) {
    if (!r || !c) return 0;
    if (in[r][c] == str[s]) {
        if (!s) return dp[r][c] + 1;
        return max(find(r, c - 1, s - 1), find(r - 1, c, s - 1));
    }
    return 0;
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%s", in[i] + 1);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dp[i][j] = max({dp[i - 1][j], dp[i][j - 1], find(i, j, 3)});
        }
    }

    printf("%d", dp[N][N]);
    return 0;
}