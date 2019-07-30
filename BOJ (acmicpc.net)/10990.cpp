#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++, printf("\n"))
        for (int j = 1; j <= N + i; j++)
            printf("%c", abs(N - j) == i ? '*' : ' ');
    return 0;
}