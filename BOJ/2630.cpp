#include <cstdio>
using namespace std;

int in[128][128], cnt[2];

void calc(int r, int c, int sz) {
    for (int i = 0; i < sz; i++)
        for (int j = 0; j < sz; j++)
            if (in[r + i][c + j] != in[r][c]) {
                sz /= 2;
                calc(r, c, sz);
                calc(r, c + sz, sz);
                calc(r + sz, c, sz);
                calc(r + sz, c + sz, sz);
                return;
            }
    cnt[in[r][c]]++;
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &in[i][j]);
    calc(0, 0, N);
    printf("%d\n%d", cnt[0], cnt[1]);
    return 0;
}