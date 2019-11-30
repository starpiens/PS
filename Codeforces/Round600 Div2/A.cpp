#include <cstdio>

using namespace std;

int T, N;
int A[(int)1e5], B[(int)1e5];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
            scanf("%d", &A[i]);
        for (int i = 0; i < N; i++)
            scanf("%d", &B[i]);
        int status = 0;
        int diff = 0;
        for (int i = 0; i < N; i++) {
            if (status == 0) {
                if (A[i] != B[i]) {
                    status = 1;
                    if ((diff = A[i] - B[i]) > 0)
                        status = 3;
                }
            } else if (status == 1) {
                if (A[i] == B[i]) status = 2;
                else if (A[i] - B[i] != diff) status = 3;
            } else if (status == 2) {
                if (A[i] != B[i]) status = 3;
            }
        }
        printf("%s\n", status != 3 ? "YES" : "NO");
    }
    return 0;
}
