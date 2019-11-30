#include <bits/stdc++.h>
using namespace std;

int Xs, Ys, T, Xh, Yh, N;
int in[401][401], dp[401][401][201];
int dr[] = {1, 0, -1, 0}, dc[] = {0, 1, 0, -1};

inline int dist(int x0, int y0, int x1, int y1) {
    return abs(x1 - x0) + abs(y1 - y0);
}

int main() {
    int Xs, Ys;
    scanf("%d %d", &Xs, &Ys);
    scanf("%d", &T);
    scanf("%d %d", &Xh, &Yh); // => (T, T)
    scanf("%d", &N);
    if (dist(Xs, Ys, Xh, Yh) > T)
        return printf("0"), 0;
    Xs -= Xh - T; Ys -= Yh - T;
    while (N--) {
        int X, Y;
        scanf("%d %d", &X, &Y);
        X -= Xh - T; Y -= Yh - T;
        if (dist(X, Y, Xs, Ys) + dist(X, Y, T, T) <= T)
            in[X][Y] = 1;
    }
    Xh = Yh = T;

    dp[Xs][Ys][0] = 1;
    for (int i = 0; i < T; i++) {
        for (int j = Xs - i; j <= Xs + i; j++)
            for (int k = Ys - i; k <= Ys + i; k++)
                if (dist(j, k, Xh, Yh) <= T - i && dp[j][k] && (j != Xh || k != Yh))
                    for (int d = 0; d < 4; d++) {
                        int nxtX = j + dr[d];
                        int nxtY = k + dc[d];
                        if (dist(nxtX, nxtY, Xh, Yh) < T - i && !in[nxtX][nxtY])
                            dp[nxtX][nxtY][i + 1] = (dp[nxtX][nxtY][i + 1] + dp[j][k][i]) % (int)(1e9 + 7);
                    }
    }

    int ans = 0;
    for (int i = 1; i <= T; i++)
        ans = (ans + dp[T][T][i]) % (int)(1e9 + 7);
    printf("%d", ans);
    return 0;
}