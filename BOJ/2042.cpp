#include <cstdio>

using namespace std;
using ll = long long;

int N, M, K;
int base = 1;
ll tree[4000000];

ll query(int l, int r) {
    l += base - 1;
    r += base - 1;
    ll sum = 0;
    while (l <= r) {
        if (l % 2 == 1) {
            sum += tree[l];
            l++;
        }
        if (r % 2 == 0) {
            sum += tree[r];
            r--;
        }
        l /= 2;
        r /= 2;
    }
    return sum;
}

void update(int idx, ll num) {
    int node = base + idx - 1;
    tree[node] = num;
    while (node > 1) {
        node /= 2;
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}

int main() {
    scanf("%d %d %d", &N, &M, &K);
    while (base < N) base <<= 1;
    for (int i = 0; i < N; i++)
        scanf("%lld", &tree[base + i]);
    for (int i = base - 1; i >= 1; i--)
        tree[i] = tree[i * 2] + tree[i * 2 + 1];

    for (int i = 0; i < M + K; i++) {
        int a, b;
        ll c;
        scanf("%d %d %lld", &a, &b, &c);
        if (a == 1) {
            update(b, c);
        } else {
            printf("%lld\n", query(b, c));
        }
    }
    return 0;
}