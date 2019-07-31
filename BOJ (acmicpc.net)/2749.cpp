#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long llu;

const int p = (int)15e5;
int fibo[p];

int main() {
    llu N;
    scanf("%llu", &N);
    N %= p;
    fibo[1] = 1;
    for (int i = 2; i <= N; i++)
        fibo[i] = (fibo[i - 1] + fibo[i - 2]) % (int)1e6;
    printf("%d", fibo[N]);
    return 0;
}