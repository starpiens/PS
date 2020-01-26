#include <cstdio>
#include <queue>

using namespace std;

int in[100][100][100];
int cnt;
int dh[] = {0, 0, 0, 0, 1, -1};
int dr[] = {1, 0, -1, 0, 0, 0};
int dc[] = {0, 1, 0, -1, 0, 0};
using pos_t = struct _Pos {
  int h, r, c;
};

int main() {
    queue<pair<pos_t, int>> q;
    int M, N, H;
    scanf("%d %d %d", &M, &N, &H);
    for (int i = 0; i < H; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < M; k++) {
                scanf("%d", &in[i][j][k]);
                if (in[i][j][k] == 0) cnt++;
                if (in[i][j][k] == 1) q.emplace(pos_t{i, j, k}, 0);
            }

    int step = 0;
    while (!q.empty()) {
        auto now = q.front().first;
        step = q.front().second;
        q.pop();
        for (int i = 0; i < 6; i++) {
            auto nxt = now;
            nxt.h += dh[i];
            nxt.r += dr[i];
            nxt.c += dc[i];
            if (0 <= nxt.h && nxt.h < H && 0 <= nxt.r && nxt.r < N && 0 <= nxt.c && nxt.c < M
                && !in[nxt.h][nxt.r][nxt.c]) {
                in[nxt.h][nxt.r][nxt.c] = 1;
                cnt--;
                q.emplace(nxt, step + 1);
            }
        }
    }

    printf("%d", cnt ? -1 : step);
    return 0;
}