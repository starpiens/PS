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

int N, M;
vector<pair<int, int> > g[500];     // node, dist
pair<int, vector<int> > d[500];  // dist, prev
bool deact[500][500];

inline void find_shortest(int s) {
    for (int i = 0; i < N; i++) {
        d[i].first = INF;
        d[i].second.clear();
    }
    priority_queue<pair<int, int> > pq;     // -dist, node
    d[s].first = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        int now = pq.top().second;
        int now_dist = -pq.top().first;
        pq.pop();
        for (auto i : g[now]) {
            int nxt = i.first;
            int nxt_dist = now_dist + i.second;
            if (deact[now][nxt]) continue;
            if (d[nxt].first == nxt_dist) {
                d[nxt].second.push_back(now);
            } else if (d[nxt].first > nxt_dist) {
                d[nxt].first = nxt_dist;
                d[nxt].second.clear();
                d[nxt].second.push_back(now);
                pq.push({ -nxt_dist, nxt });
            }
        }
    }
}

inline void run_deact(int n) {
    for (auto i : d[n].second) {
        deact[i][n] = true;
        run_deact(i);
    }
}

int main() {
    while (scanf("%d %d", &N, &M), (N || M)) {
        int S, D;
        scanf("%d %d", &S, &D);
        for (int i = 0; i < N; i++) {
            g[i].clear();
            for (int j = 0; j < N; j++)
                deact[i][j] = false;
        }

        while (M--) {
            int U, V, P;
            scanf("%d %d %d", &U, &V, &P);
            g[U].push_back({V, P});
        }
        
        find_shortest(S);
        run_deact(D);
        find_shortest(S);

        printf("%d\n", d[D].first == INF ? -1 : d[D].first);
    }

    return 0;
}