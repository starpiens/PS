#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int P, M, F, C;
        scanf("%d %d %d %d", &P, &M, &F, &C);
        int coupon = M / P * C;
        printf("%d\n", max(coupon - C, 0) / (F - C) - coupon / F);
    }
    return 0;
}