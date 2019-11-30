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
#define ABS(n) (((n) > 0) ? (n) : -(n))
#define SQR(n) ((n) * (n))

typedef long long ll;
typedef unsigned long long llu;

using namespace std;
int N, w[10001], in[10001], dp[10001];
vector<int> g[10001];

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &w[i]);
        dp[i] = w[i];
    }
    for (int i = 1; i < N; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (a > b) swap(a, b);
        g[a].push_back(b);
        in[b]++;
    }
    queue<int> q;
    for (int i = 1; i <= N; i++)
        if (!in[i]) q.push(i);
    int ans = 0;
    while (!q.empty()) {
        int now = q.front(); q.pop();
        for (int nxt : g[now]) {
            if (--in[nxt] == 0) q.push(nxt);
            for (int n_nxt : g[nxt]) {
                dp[n_nxt] = max(dp[n_nxt], dp[now] + w[n_nxt]);
                ans = max(ans, dp[n_nxt]);
            }
        }
    }
    printf("%d", ans);

    return 0;
}