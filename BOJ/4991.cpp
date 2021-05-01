#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int W, H;
char in[20][20];
vector<pair<int, int>> dirty;
pair<int, int> robot;
int dist[11][11];
int vis[11];

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

void get_dist(int st) {
    int d[20][20];
    memset(d, -1, sizeof(d));
    queue<pair<int, int>> q;

    d[dirty[st].first][dirty[st].second] = 0;
    q.push(dirty[st]);
    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if (0 <= nr && nr < H && 0 <= nc && nc < W
                && in[nr][nc] != 'x' && d[nr][nc] == -1) {
                d[nr][nc] = d[cr][cc] + 1;
                q.push({nr, nc});
            }
        }
    }

    for (int i = 0; i < dirty.size(); i++) {
        dist[st][i] = dist[i][st] = d[dirty[i].first][dirty[i].second];
    }
}

int tsp(int n) {
    int minv = 1000;
    bool chk = false;
    for (int i = 0; i < dirty.size() - 1; i++)
        if (!vis[i]) {
            chk = true;
            vis[i] = true;
            minv = min(minv, dist[n][i] + tsp(i));
            vis[i] = false;
        }
    return chk * minv;
}

int main() {
    while (scanf("%d %d", &W, &H), W) {
        dirty.clear();
        memset(dist, -1, sizeof(dist));
        memset(vis, 0, sizeof(vis));

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                scanf(" %c", &in[i][j]);
                if (in[i][j] == '*')
                    dirty.emplace_back(i, j);
                else if (in[i][j] == 'o')
                    robot = {i, j};
            }
        }
        dirty.emplace_back(robot);

        for (int i = 0; i < dirty.size(); i++) {
            get_dist(i);
        }

        bool fail = false;
        for (int i = 0; i < dirty.size(); i++)
            if (dist[dirty.size() - 1][i] == -1)
                fail = true;
        if (fail) {
            printf("-1\n");
            continue;
        }

        printf("%d\n", tsp(dirty.size() - 1));
    }
    return 0;
}