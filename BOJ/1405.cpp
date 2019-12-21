#include <cstdio>

using namespace std;

int N;
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};
int p[4];
bool vis[29][29];

long double dfs(int r, int c, int d) {
    if (d == N) return 1;
    long double ret = 0;
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (!vis[nr][nc]) {
            vis[nr][nc] = true;
            ret += dfs(nr, nc, d + 1) * p[i] / 100;
            vis[nr][nc] = false;
        }
    }
    return ret;
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < 4; i++)
        scanf("%d", &p[i]);

    vis[14][14] = true;
    printf("%.9Lf", dfs(14, 14, 0));

    return 0;
}