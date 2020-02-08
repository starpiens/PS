#include <cstdio>

int N, M;
int series[8];

void dfs(int n, int s) {
    if (s == M) {
        for (int i = 0; i < M; i++)
            printf("%d ", series[i]);
        printf("\n");
        return;
    }
    for (int i = n + 1; i <= N - (M - s - 1); i++) {
        series[s] = i;
        dfs(i, s + 1);
    }
}

int main() {
    scanf("%d %d", &N, &M);
    dfs(0, 0);
    return 0;
}