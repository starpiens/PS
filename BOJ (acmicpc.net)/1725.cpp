#include <bits/stdc++.h>

using namespace std;

int in[(int)1e5 + 2];

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", &in[i]);
    stack<int> s;
    s.push(0);
    int ans = 0;
    for (int i = 1; i <= N + 1; i++) {
        while (in[s.top()] > in[i]) {
            int h = in[s.top()];
            s.pop();
            ans = max(ans, h * (i - 1 - s.top()));
        }
        s.push(i);
    }
    printf("%d", ans);
    return 0;
}