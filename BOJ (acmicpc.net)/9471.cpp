#include <bits/stdc++.h>
using namespace std;

int main() {
    int P;
    scanf("%d", &P);
    while (P--) {
        int N, M;
        scanf("%d %d", &N, &M);
        int m1 = 1, m2 = 1, cnt = 0;
        do {
            int tmp = m2;
            m2 = (m1 + m2) % M;
            m1 = tmp;
            cnt++;
        } while (m1 != 1 || m2 != 1);
        printf("%d %d\n", N, cnt);
    }
    return 0;
}