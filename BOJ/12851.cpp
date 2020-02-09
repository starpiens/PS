#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX_N = 1e5 + 1;
pair<int, int> vis[MAX_N];

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    queue<int> q;
    q.push(N);
    vis[N] = {1, 1};

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        if (now == K) {
            printf("%d\n%d", vis[K].first - 1, vis[K].second);
            break;
        }

        int nxt[] = {now + 1, now - 1, now * 2};
        for (int i : nxt) {
            if (i < 0 || i >= MAX_N)
                continue;
            if (!vis[i].first) {
                vis[i] = {vis[now].first + 1, vis[now].second};
                q.push(i);
            } else if (vis[i].first == vis[now].first + 1) {
                vis[i].second += vis[now].second;
            }
        }
    }
    return 0;
}