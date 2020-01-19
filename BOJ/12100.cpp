#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int board[20][20];
int mx;
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

void dfs(int n, int b[][20]) {
    if (n == 5) return;
    for (int i = 0; i < 4; i++) {
        int nxt_b[20][20];
        for (int j = 0; j < N; j++) {
            int anchor = (dr[i] == 1 || dc[i] == 1) * (N + 1) - 1;
            for (int k = 0; k < N; k++) {
                int r, c;
                if (dr[i] + dc[i] > 0) r = N - 1 - k, c = j;
                else r = k, c = j;
                if (!dr[i]) swap(r, c);

                nxt_b[r][c] = b[r][c];
                int nxt_r = r + dr[i], nxt_c = c + dc[i];
                while ((dr[i] ? nxt_r : nxt_c) != anchor && !nxt_b[nxt_r][nxt_c]) {
                    swap(nxt_b[nxt_r][nxt_c], nxt_b[r][c]);
                    nxt_r = (r = nxt_r) + dr[i];
                    nxt_c = (c = nxt_c) + dc[i];
                }
                if ((dr[i] ? nxt_r : nxt_c) != anchor && nxt_b[nxt_r][nxt_c] == nxt_b[r][c]) {
                    nxt_b[r][c] = 0;
                    r = nxt_r, c = nxt_c;
                    nxt_b[r][c] <<= 1;
                    anchor = (dr[i] ? r : c);
                }
                mx = max(mx, nxt_b[r][c]);
            }
        }
        dfs(n + 1, nxt_b);
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &board[i][j]);
    dfs(0, board);
    printf("%d", mx);
    return 0;
}