#include <bits/stdc++.h>
using namespace std;

int f(int n) {
    int ret = n;
    while (n) {
        ret += n % 10;
        n /= 10;
    }
    return ret;
}

int main() {
    int N; scanf("%d", &N);
    for (int i = 10; i < N; i++)
        if (N == f(i))
            return printf("%d", i), 0;
    return printf("0"), 0;
}