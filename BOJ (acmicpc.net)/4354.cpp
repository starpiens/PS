#include <bits/stdc++.h>

using namespace std;

int f[(int)1e6 + 1];
char in[(int)1e6 + 1];

int main() {
    while (scanf("%s", in + 1), in[1] != '.') {
        int j = 0, len = strlen(in + 1);
        for (int i = 2; i <= len; i++) {
            while (j && in[i] != in[j + 1]) j = f[j];
            j += (in[i] == in[j + 1]);
            f[i] = j;
        }
        printf("%d\n", len % (len - f[len]) ? 1 : len / (len - f[len]));
    }
    return 0;
}