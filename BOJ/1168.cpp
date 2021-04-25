#include <cstdio>

using namespace std;

int N, K;
int tree[100000 * 4];
int base = 1;

int query(int node, int k) {
    tree[node]--;
    if (node >= base) {
        return node - base + 1;
    }
    if (k <= tree[node * 2])
        return query(node * 2, k);
    else
        return query(node * 2 + 1, k - tree[node * 2]);
}

int main() {
    scanf("%d %d", &N, &K);

    // Setup tree
    while (base < N)
        base <<= 1;
    for (int i = 0; i < N; i++)
        tree[base + i] = 1;
    for (int i = base - 1; i >= 1; i--)
        tree[i] = tree[i * 2] + tree[i * 2 + 1];

    printf("<");
    int k = 1;
    for (int i = 0; i < N; i++) {
        k = (k + K - 1 - 1) % tree[1] + 1;
        printf("%d", query(1, k));
        i == N - 1 ? printf(">") : printf(", ");
    }

    return 0;
}