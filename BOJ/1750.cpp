#include <bits/stdc++.h>

typedef unsigned long long llu;

const int DIV = 1e7 + 3;

using namespace std;

map<int, int> m[2];

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int N, S[100];
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &S[i]);

    for (int i = 0; i < N; i++) {
        int now = i % 2;
        int prv = !now;
        m[now].clear();
        m[now][S[i]] = (m[now][S[i]] + 1) % DIV;
        for (auto it : m[prv]) {
            m[now][it.first] = (m[now][it.first] + it.second) % DIV;
            m[now][gcd(it.first, S[i])] = (m[now][gcd(it.first, S[i])] + it.second) % DIV;
        }
    }

    printf("%d", m[(N + 1) % 2][1]);

    return 0;
}