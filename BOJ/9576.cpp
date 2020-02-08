#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX_N = 1001;
pair<int, int> in[MAX_N];
bool vis[MAX_N];
int match[MAX_N];

bool bm(int n) {
    if (vis[n]) return false;
    vis[n] = true;
    for (int i = in[n].first; i <= in[n].second; i++)
        if (!match[i] || bm(match[i]))
            return (match[i] = n), true;
    return false;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N, M;
        scanf("%d %d", &N, &M);
        for (int i = 1; i <= M; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            in[i] = {a, b};
        }
        int cnt = 0;
        for (int i = 1; i <= M; i++) {
            memset(vis, 0, sizeof(vis));
            cnt += bm(i);
        }
        printf("%d\n", cnt);
        memset(match, 0, sizeof(match));
    }
    return 0;
}