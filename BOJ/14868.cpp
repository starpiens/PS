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

#define INF 2100000000

typedef long long ll;
typedef unsigned long long llu;

using namespace std;

int N, K, par[4008004];
bool is_k[4008004];
int vis[4008004];

int find(int n) {
    if (n == par[n]) return n;
    return par[n] = find(par[n]);
}

void uni(int a, int b) { par[find(a)] = find(b); }

int to_num(int x, int y) { return x * (N + 2) + y; }

int main() {
    queue<int> q;
    scanf("%d %d", &N, &K);
    for (int i = 0; i < (N + 2) * (N + 2); i++)
        par[i] = i;
    for (int i = 0; i < K; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        q.push(to_num(x, y));
        is_k[to_num(x, y)] = 1;
    }
    int res = 0;
    while (K > 1) {
        int now = q.front(); q.pop();
        int dir[] = { -1, 1, N + 2, -N - 2 };
        for (int i = 0; i < 4; i++) {
            int go = now + dir[i];
            // 범위 및 같은 문명인지 체크.
            if (go >= N + 2 && go < (N + 1) * (N + 2) && go % (N + 2) != 0 && go % (N + 2) != N + 1 &&
                    find(go) != find(now)) {
                if (is_k[find(go)]) { // 다른 문명을 만남.
                    K--;
                    res = max(res, vis[go]);
                } else {
                    q.push(go);
                    vis[go] = vis[now] + 1;
                }
                uni(go, now);
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)
            printf("%d ", par[to_num(i, j)]);
        printf("\n");
    }
    printf("\n");
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)
            printf("%d ", vis[to_num(i, j)]);
        printf("\n");
    }
    printf("\n");
    printf("%d\n", res);
    return 0;
}