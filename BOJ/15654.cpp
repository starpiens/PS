#include <cstdio>
#include <algorithm>
using namespace std;

int N, M;
int series[8];
int in[8];
int vis[8];

void dfs(int s) {
    if (s == M) {
        for (int i = 0; i < M; i++)
            printf("%d ", in[series[i]]);
        printf("\n");
    }
    for (int i = 0; i < N; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            series[s] = i;
            dfs(s + 1);
            vis[i] = 0;
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
        scanf("%d", &in[i]);
    sort(in, in + N);
    dfs(0);
    return 0;
}