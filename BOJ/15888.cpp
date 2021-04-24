#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);

    if (!(B % A == 0 && C % A == 0))
        return printf("둘다틀렸근"), 0;
    B /= A;
    C /= A;

    for (int i = 1; i * i < abs(C); i++) {
        if (C % i != 0) continue;
        int x1 = i;
        int x2 = C / i;
        if (abs(x1 + x2) != abs(B)) continue;
        if (x1 + x2 == B) {
            x1 *= -1;
            x2 *= -1;
        }
        if (x1 > 1 && x2 > 1 && !(x1 & (x1 - 1)) && !(x2 & (x2 - 1)))
            return printf("이수근"), 0;
        else
            return printf("정수근"), 0;
    }
    printf("둘다틀렸근");
    return 0;
}