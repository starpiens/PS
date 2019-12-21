#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int A[(int)2e3];
int B[(int)2e3];

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);
    for (int i = 0; i < N; i++)
        scanf("%d", &B[i]);
    sort(A, A + N);
    sort(B, B + N);

    // Match A[0] and B[i]
    for (int i = 0; i < N; i++) {
        int x = B[i] - A[0];
        if (x < 0) x += M;
        bool fail = false;
        for (int j = 0; j < N; j++)
            if ((A[j] + x) % M != B[(i + j) % N]) {
                fail = true;
                break;
            }
        if (!fail) return printf("%d", x), 0;
    }

    return 0;
}