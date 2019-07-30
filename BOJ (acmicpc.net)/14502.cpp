#include <bits/stdc++.h>
using namespace std;

int N, M;
int pos[4];
int dr[] = {0, 1, 0, -1}, dc[] = {1, 0, -1, 0};
int in[8][8], tmp[8][8];

void ff(int r, int c) {
    if (r < 0 || r == N || c < 0 || c == M || tmp[r][c] % 2) return;
    tmp[r][c] = 3;
    for (int i = 0; i < 4; i++)
        ff(r + dr[i], c + dc[i]);
}

int per(int n) {
    int ret = 0;
    for (int i = pos[n - 1] + 1; i < N * M + n - 3; i++) {
        if (in[i / M][i % M]) continue;
        pos[n] = i;
        if (n < 3) ret = max(ret, per(n + 1));
        else {
            memcpy(tmp, in, sizeof(in));
            for (int j = 1; j <= 3; j++)
                tmp[pos[j] / M][pos[j] % M] = 1;
            for (int j = 0; j < N; j++)
                for (int k = 0; k < M; k++)
                    if (tmp[j][k] == 2) ff(j, k);
            int cnt = 0;
            for (int j = 0; j < N; j++)
                for (int k = 0; k < M; k++)
                    cnt += tmp[j][k] == 0;
            ret = max(ret, cnt);
        }
    }
    return ret;
}

int main() {

    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf("%d", &in[i][j]);
    pos[0] = -1;

    printf("%d", per(1));
    return 0;
}