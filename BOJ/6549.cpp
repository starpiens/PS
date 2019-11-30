#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long llu;

int in[(int)1e5 + 2];

int main() {
    int N;
    while (scanf("%d", &N), N) {
        for (int i = 1; i <= N; i++)
            scanf("%d", &in[i]);
        in[N + 1] = 0;

        llu ans = 0;
        stack<int> s;
        s.push(0);
        for (int i = 1; i <= N + 1; i++) {
            while (in[s.top()] > in[i]) {
                int h = in[s.top()];
                s.pop();
                ans = max(ans, (llu)h * (i - 1 - s.top()));
            }
            s.push(i);
        }
        printf("%llu\n", ans);
    }
    return 0;
}