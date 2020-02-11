#include <cstdio>
#include <algorithm>
#include <cstdio>
using namespace std;

const int INF = 1e9;
const int MAX_N = 101;
int g[MAX_N][MAX_N];
int in[MAX_N];

int main() {
    int N, M, R;
    scanf("%d %d %d", &N, &M, &R);
    for (int i = 1; i <= N; i++)
        scanf("%d", &in[i]);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            g[i][j] = (i == j ? 0 : INF);
    while (R--) {
        int a, b, l;
        scanf("%d %d %d", &a, &b, &l);
        g[a][b] = g[b][a] = l;
    }

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            for (int k = 1; k <= N; k++)
                g[j][k] = min(g[j][k], g[j][i] + g[i][k]);

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        int sum = 0;
        for (int j = 1; j <= N; j++)
            sum += in[j] * (g[i][j] <= M);
        ans = max(ans, sum);
    }
    printf("%d", ans);
    return 0;
}