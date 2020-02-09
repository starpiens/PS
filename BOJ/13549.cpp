#include <cstdio>
#include <queue>

using namespace std;

const int MAX_N = 1e5 + 1;
int vis[MAX_N];

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    queue<int> q;
    for (int i = N; i < MAX_N; i *= 2) {
        vis[i] = 1;
        q.push(i);
        if (!i) break;
    }
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        if (now == K) {
            printf("%d", vis[now] - 1);
            return 0;
        }
        int nxt[] = {now - 1, now + 1};
        for (int i : nxt) {
            if (i < 0) continue;
            for (int j = i; j < MAX_N; j *= 2) {
                if (!vis[j]) {
                    vis[j] = vis[now] + 1;
                    q.push(j);
                }
                if (!j) break;
            }
        }
    }
}