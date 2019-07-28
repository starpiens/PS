#include <bits/stdc++.h>

using namespace std;

vector<int> g[300001];
int vis[300001];

void dfs(int n) {
    vis[n] = 1;
    for (auto i : g[n]) {
        if (!vis[i]) dfs(i);
    }
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 2; i < N; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1);
    for (int i = 2; i <= N; i++)
        if (!vis[i])
            return printf("1 %d", i), 0;
    return -1;
}