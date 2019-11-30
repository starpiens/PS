#include <bits/stdc++.h>

using namespace std;

int main() {
    int A, B;
    scanf("%d %d", &A, &B);
    long double M = (long double)(B - A) / 400;
    printf("%Lf", 1 / (1 + powl(10, M)));
    return 0;
}