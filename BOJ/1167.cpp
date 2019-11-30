#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <fstream>
#include <random>
#include <functional>

#define INF 2100000000
#define ABS(n) (((n) > 0) ? (n) : -(n))
#define SQR(n) ((n) * (n))

typedef long long ll;
typedef unsigned long long llu;

using namespace std;

vector<pair<int, int> > g[100001];
int vis[100001];

int dfs(int n) {
    int farest = n;
    for (auto i : g[n])
        if (!vis[i.first]) {
            vis[i.first] = vis[n] + i.second;
            int ret = dfs(i.first);
            if (vis[farest] < vis[ret])
                farest = ret;
        }
    return farest;
}

int main() {
    int V;
    scanf("%d", &V);
    for (int i = 0; i < V; i++) {
        int node, nxt, dist;
        scanf("%d", &node);
        while (scanf("%d", &nxt), nxt > 0) {
            scanf("%d", &dist);
            g[node].push_back({nxt, dist});
        }
    }

    vis[1] = 1;
    int farest = dfs(1);
    
    memset(vis, 0, sizeof(vis));
    vis[farest] = 1;
    printf("%d", vis[dfs(farest)] - 1);

    return 0;
}