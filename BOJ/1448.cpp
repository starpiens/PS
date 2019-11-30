#include <bits/stdc++.h>
using namespace std;

int in[(int)1e6];
int cnt[(int)1e6 + 1];
int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        cnt[x]++;
    }
    int idx = 0;
    for (int i = 0; i <= (int)1e6; i++)
        while (cnt[i]--)
            in[idx++] = i;

    for (int i = N - 1; i >= 2; i--)
        if (in[i] < in[i - 1] + in[i - 2])
            return printf("%d", in[i] + in[i - 1] + in[i - 2]), 0;
    return printf("-1"), 0;
}