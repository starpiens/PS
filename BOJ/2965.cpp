#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);
    printf("%d", max(C - B, B - A) - 1);
    return 0;
}