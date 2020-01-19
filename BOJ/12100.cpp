#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int board[20][20];
int mx;
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

void dfs(int n, int b[][20], int prev_d) {
    if (n == 5) return;
    for (int i = 0; i < 4; i++) {
        if (i == prev_d) continue;
        int nxt_b[20][20];
        for (int j = 0; j < N; j++) {
            int anchor = (dr[i] == 1 || dc[i] == 1) * (N - 1);
            for (int k = 0; k < N; k++) {
                int r, c;
                if (dr[i] + dc[i] > 0) r = N - 1 - k, c = j;
                else r = k, c = j;
                if (!dr[i]) swap(r, c);

                nxt_b[r][c] = b[r][c];
                if (!b[r][c]) continue;
                mx = max(mx, b[r][c]);
                int &ch = dr[i] ? nxt_b[anchor][c] : nxt_b[r][anchor];
                if ((dr[i] ? r : c) == anchor) continue;
                if (ch == nxt_b[r][c]) {
                    nxt_b[r][c] = 0;
                    ch <<= 1;
                    mx = max(mx, ch);
                    anchor -= (dr[i] + dc[i]);
                } else if (!ch) {
                    swap(nxt_b[r][c], ch);
                } else {
                    anchor -= (dr[i] + dc[i]);
                    swap(dr[i] ? nxt_b[anchor][c] : nxt_b[r][anchor], nxt_b[r][c]);
                }
            }
        }
        dfs(n + 1, nxt_b, i);
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &board[i][j]);
    dfs(0, board, -1);
    printf("%d", mx);
    return 0;
}