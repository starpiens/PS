#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long llu;
const int SZ = (int)1e5 + 1;
llu val[SZ];
pair<llu, int> lazy[SZ * 4];

void update(int n, int l, int r, int s, int e) {
    int m = (l + r) >> 1;
    if (r < s || l > e) return;
    if (s <= l && r <= e) {
        lazy[n].first += l - s + 1;
        lazy[n].second++;
        return;
    }
    update(n * 2, l, m, s, e);
    update(n * 2 + 1, m + 1, r, s, e);
}

llu query(int n, int l, int r, int q) {
    if (lazy[n].second) {
        if (l != r) {
            lazy[n * 2].first += lazy[n].first;
            lazy[n * 2].second += lazy[n].second;
            lazy[n * 2 + 1].first += lazy[n].first + (llu)(r - l + 1) / 2 * lazy[n].second;
            lazy[n * 2 + 1].second += lazy[n].second;
        } else {
            val[q] += lazy[n].first;
        }
        lazy[n] = {0, 0};
    }
    if (l == r) return val[q];
    int m = (l + r) >> 1;
    return q <= m ? query(n * 2, l, m, q) : query(n * 2 + 1, m + 1, r, q);
}

int main() {
    int N;
    scanf("%d", &N);

    int base = 1;
    while (base < N) base <<= 1;
    for (int i = 1; i <= N; i++)
        scanf("%llu", &val[i]);

    int Q;
    scanf("%d", &Q);
    while (Q--) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            int L, R;
            scanf("%d %d", &L, &R);
            update(1, 1, base, L, R);
        } else {
            int X;
            scanf("%d", &X);
            printf("%llu\n", query(1, 1, base, X));
        }
    }

    return 0;
}