#include <bits/stdc++.h>
using namespace std;

int in[100000];

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &in[i]);
    sort(in, in + N);

    int ans = 0;
    for (int i = 0; i < N; i++) {
        int mask = 1;
        while (in[i] - mask >= mask) mask <<= 1;

        int val = 0;
        while (mask) {
            val += (in[i] ^ mask) & mask;
            int *l = lower_bound(in, in + N, val);
            int *r = upper_bound(in, in + N, val + mask - 1) - 1;
            if (l > r) {
                val ^= mask;
            } else if (*l == *r) {
                ans = max(ans, in[i] ^ *l);
                break;
            }
            mask >>= 1;
        }
    }

    printf("%d", ans);
    return 0;
}