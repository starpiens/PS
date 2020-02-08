#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int MAX_N = 101;
vector<int> g[MAX_N];
bool vis[MAX_N];
int match[MAX_N];

bool bm(int n) {
    if (vis[n]) return false;
    vis[n] = true;
    for (auto i : g[n]) {
        if (!match[i] || bm(match[i]))
            return (match[i] = n), true;
    }
    return false;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    while (M--) {
        int a, b;
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
    }
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        memset(vis, 0, sizeof(vis));
        sum += bm(i) == true;
    }
    printf("%d", sum);
    return 0;
}