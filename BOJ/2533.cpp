#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N = 1e6 + 1;

vector<int> adj[MAX_N];
int dp[MAX_N][2];
int depth[MAX_N];

// 0: 상관없음, 1: 얼리여야함
int f(int node, int type, int par_d) {
    if (depth[node] && depth[node] < par_d) return 0;
    depth[node] = par_d + 1;
    if (dp[node][type] >= 0)
        return dp[node][type];
    dp[node][0] = 0;
    dp[node][1] = 1;
    for (auto i : adj[node]) {
        dp[node][0] += f(i, 1, par_d + 1);
        dp[node][1] += f(i, 0, par_d + 1);
    }
    dp[node][0] = min(dp[node][0], dp[node][1]);
    return dp[node][type];
}

int main() {
    memset(dp, -1, sizeof(dp));
    int N;
    scanf("%d", &N);
    for (int i = 1; i < N; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    printf("%d", f(1, 0, 0));
    return 0;
}