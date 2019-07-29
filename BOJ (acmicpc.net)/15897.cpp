#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long llu;

int main() {
    int N;
    scanf("%d", &N);
    llu ans = 1;
    for (int i = 1; i < N;) {
        int val = (N + i - 1) / i;
        int j = (N + val - 2) / (val - 1);
        ans += val * (j - i);
        i = j;
    }
    printf("%llu", ans);
    return 0;
}