#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long llu;

int in[(int)1e5 + 2];
llu sum[(int)1e5 + 2];

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &in[i]);
        sum[i] = sum[i - 1] + in[i];
    }

    llu ans = 0;
    stack<int> s;
    s.push(0);
    for (int i = 1; i <= N + 1; i++) {
        while (in[s.top()] > in[i]) {
            int mn = in[s.top()];
            s.pop();
            ans = max(ans, mn * (sum[i - 1] - sum[s.top()]));
        }
        s.push(i);
    }
    printf("%llu", ans);

    return 0;
}