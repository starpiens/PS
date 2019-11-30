#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long llu;

int main() {
    llu X, Y;
    scanf("%llu %llu", &X, &Y);
    llu Z = Y * 100 / X + 1;
    if (Z >= 100) printf("-1");
    else printf("%llu", (Z * X - 100 * Y + 99 - Z) / (100 - Z));
    return 0;
}