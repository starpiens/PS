#include <cstdio>
using namespace std;

bool isok(int n, int step) {
    if (!step)
        return !n;
    for (int i = 1; i * i <= n; i++)
        if (isok(n - i * i, step - 1))
            return true;
    return false;
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= 3; i++)
        if (isok(N, i))
            return printf("%d", i), 0;
    printf("4");
    return 0;
}