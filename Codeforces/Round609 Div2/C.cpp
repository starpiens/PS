#include <cstdio>
#include <algorithm>

using namespace std;

int N, K;
int X[(int) 1e6];
int Y[(int) 1e6];

int main() {
    scanf("%d %d", &N, &K);
    for (int i = N; i > 0; i--) {
        scanf("%1d", &X[i]);
        Y[i] = X[i];
    }

    // Try to make it beautiful
    for (int i = N; i > K; i--) {
        Y[i - K] = Y[i];
    }

    // Is y smaller than x?
    bool fail = false;
    for (int i = N; i > 0; i--) {
        if (X[i] > Y[i]) {
            fail = true;
            break;
        } else if (X[i] < Y[i]) {
            break;
        }
    }
    if (!fail) {
        printf("%d\n", N);
        for (int i = N; i > 0; i--)
            printf("%d", Y[i]);
        return 0;
    }

    // Try next Y.
    int j = min(N - K, K) + 1;
    while (++Y[j] == 10)
        Y[j++] = 0;
    N = max(N, j);
    for (int i = N; i > K; i--)
        Y[i - K] = Y[i];
    for (int i = K + 1; i <= N - K; i++)
        Y[i] = 0;
    printf("%d\n", N);
    for (int i = N; i > 0; i--)
        printf("%d", Y[i]);

    return 0;
}