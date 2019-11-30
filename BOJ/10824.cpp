#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long llu;

int main() {
    llu A, B, C, D;
    scanf("%llu %llu %llu %llu", &A, &B, &C, &D);
    int B_cpy = B, D_cpy = D;
    while (B) {
        A *= 10;
        B /= 10;
    }
    while (D) {
        C *= 10;
        D /= 10;
    }
    printf("%llu", A + B_cpy + C + D_cpy);
    return 0;
}