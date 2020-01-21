#include <cstdio>

using namespace std;

typedef unsigned long long llu;

int N, S;
int in[40];
int chk[(int)4e6 + 1];
llu ans;

void dfs_l(int idx, int sum) {
    if (idx == N / 2) {
        chk[sum + (int)2e6]++;
        return;
    }
    dfs_l(idx + 1, sum);
    dfs_l(idx + 1, sum + in[idx]);
}

void dfs_r(int idx, int sum) {
    if (idx == N) {
        if ((int)-2e6 <= S - sum && S - sum <= (int)2e6)
            ans += chk[S - sum + (int)2e6];
        return;
    }
    dfs_r(idx + 1, sum);
    dfs_r(idx + 1, sum + in[idx]);
}

int main() {
    scanf("%d %d", &N, &S);
    for (int i = 0; i < N; i++)
        scanf("%d", &in[i]);
    dfs_l(0, 0);
    dfs_r(N / 2, 0);
    printf("%llu", ans - (S == 0));
    return 0;
}