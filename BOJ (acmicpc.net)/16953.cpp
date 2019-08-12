#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B;
    scanf("%d %d", &A, &B);
    queue<pair<int, int> > q;
    q.push({A, 1});
    while (!q.empty()) {
        auto v = q.front();
        q.pop();
        if (v.first == B)
            return printf("%d", v.second), 0;
        if (v.first <= B / 2)
            q.push({v.first * 2, v.second + 1});
        if (v.first <= (B - 1) / 10)
            q.push({v.first * 10 + 1, v.second + 1});
    }
    return printf("-1"), 0;
}