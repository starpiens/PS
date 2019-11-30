#include <bits/stdc++.h>
using namespace std;

char arr[6561][6361];

void f(int r, int c, int s) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (i != 1 || j != 1) {
                if (s == 3) arr[r + i][c + j] = 1;
                else f(r + i * s / 3, c + j * s / 3, s / 3);
            }
}

int main() {
    int N;
    scanf("%d", &N);
    f(0, 0, N);
    for (int i = 0; i < N; i++, printf("\n"))
        for (int j = 0; j < N; j++)
            printf("%c", arr[i][j] ? '*' : ' ');
    return 0;
}