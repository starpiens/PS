#include <bits/stdc++.h>
using namespace std;

int N;
char in[10][2];
int perm[10], bias;

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        char tmp[101];
        scanf("%s", tmp);
        int len = strlen(tmp);
        char prev = tmp[0];
        for (int j = 0; j < len; j++) {
            bias += tmp[j] != prev;
            prev = tmp[j];
        }
        in[i][0] = tmp[0];
        in[i][1] = tmp[len - 1];
        perm[i] = i;
    }

    int minval = 1e9;
    do {
        int cnt = 0;
        int prev = in[perm[0]][1];
        for (int i = 1; i < N; i++) {
            cnt += in[perm[i]][0] != prev;
            prev = in[perm[i]][1];
        }
        minval = min(minval, cnt);
    } while (next_permutation(perm, perm + N));

    printf("%d", bias + minval);

    return 0;
}