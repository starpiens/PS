#include <cstdio>
#include <vector>
using namespace std;

const int MAX_N = 1e5 + 1;
int par[MAX_N];
vector<int> g[MAX_N];

void dfs(int n) {
    for (int i : g[n])
        if (!par[i]) {
            par[i] = n;
            dfs(i);
        }
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 1; i < N; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    par[1] = 1;
    dfs(1);
    for (int i = 2; i <= N; i++)
        printf("%d\n", par[i]);
    return 0;
}