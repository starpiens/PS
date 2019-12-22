#include <cstdio>

using namespace std;

int N, K;
char X[(int) 2e5 + 1];
char Y[(int) 2e5 + 1];

void print() {
    printf("%d\n", N);
    for (int i = N; i > 0; i--)
        printf("%d", Y[i]);
}

int main() {
    scanf("%d %d", &N, &K);
    for (int i = N; i > 0; i--) {
        scanf(" %c", &X[i]);
        Y[i] = X[i] -= '0';
    }

    // Try to make it beautiful
    for (int i = N; i > K; i--)
        Y[i - K] = Y[i];

    // Is y greater than x?
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
        print();
        return 0;
    }

    // Try next Y.
    int j = N - K + 1;
    while (++Y[j] == 10)
        Y[j++] = 0;
    for (int i = N; i > K; i--)
        Y[i - K] = Y[i];
    print();
    return 0;
}