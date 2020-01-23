#include <cstdio>
#include <algorithm>

using namespace std;

int N, B[(int)3e5];

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &B[i]);
    sort(B, B + N);

    int l = 0, r = N;
    while (l < r) {
        int m = (l + r) / 2;
        bool fail = false;
        int s = N - 1;
        for (int i = 0; i < N; i++) {
            if (i == m) continue;
            if (B[m] + N < B[i] + s) {
                fail = true;
                break;
            }
            s--;
        }
        if (fail) l = m + 1;
        else r = m;
    }

    printf("%d", N - l);
    return 0;
}