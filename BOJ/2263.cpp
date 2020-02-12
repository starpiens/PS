#include <cstdio>

const int MAX_N = 1e5 + 1;
int N;
int in[MAX_N], post[MAX_N];
int idx_in[MAX_N];

void rec(int l, int r, int sh) {
    if (l > r)
        return;
    printf("%d ", post[r]);
    int root_in = idx_in[post[r]];
    rec(l, root_in - 1 - sh, sh);
    rec(root_in - sh, r - 1, sh + 1);
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &in[i]);
        idx_in[in[i]] = i;
    }
    for (int i = 0; i < N; i++)
        scanf("%d", &post[i]);
    rec(0, N - 1, 0);
    return 0;
}