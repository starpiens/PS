#include <cstdio>
#include <cstring>

using namespace std;

const int MAX_N = 201;
int N, M;
int WT[MAX_N], WK[MAX_N];
bool vis[MAX_N];
int match[MAX_N];

bool bm(int n) {
    if (vis[n]) return false;
    vis[n] = true;
    int w = WT[n];
    for (int i = 1; i <= M; i++)
        if (((.5 * w <= WK[i] && WK[i] <= .75 * w) ||
             (w <= WK[i] && WK[i] <= 1.25 * w)) &&
            (!match[i] || bm(match[i])))
            return (match[i] = n), true;
    return false;
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)
        scanf("%d", &WT[i]);
    for (int i = 1; i <= M; i++)
        scanf("%d", &WK[i]);
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        memset(vis, 0, sizeof(vis));
        cnt += bm(i);
    }
    printf("%d", cnt);
    return 0;
}