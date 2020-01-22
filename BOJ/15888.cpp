#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);
    if (B * B - 4 * A * C <= 0)
        return printf("둘다틀렸근"), 0;

    vector<int> divA, divC;
    for (int i = 1; i * i <= abs(A); i++)
        if (A % i == 0)
            divA.push_back(i), divA.push_back(-i);
    for (int i = 1; i * i <= abs(C); i++)
        if (C % i == 0)
            divC.push_back(i), divC.push_back(-i);

    for (auto i : divA) {
        for (auto j : divC) {
            // (i x + j)(A/i x + C/j)
            if (i * C / j + A / i * j == B) {
                if (j % i == 0 && (C / j) % (A / i) == 0) {
                    int x1 = -j / i;
                    int x2 = -(C / j) / (A / i);
                    if ((x1 & (x1 - 1)) == 0 && (x2 & (x2 - 1)) == 0) {
                        return printf("이수근"), 0;
                    } else {
                        return printf("정수근"), 0;
                    }
                } else {
                    return printf("둘다틀렸근"), 0;
                }
            }
        }
    }
    printf("둘다틀렸근");
    return 0;
}