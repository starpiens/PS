#include <bits/stdc++.h>

using namespace std;

typedef long long lld;

int in[100];

int main() {
    int K, N;
    priority_queue<lld> pq;
    unordered_set<lld> s;
    scanf("%d %d", &K, &N);
    for (int i = 0; i < K; i++) {
        scanf("%d", &in[i]);
        pq.push(-in[i]);
        s.insert(in[i]);
    }

    lld mx = in[K - 1];
    for (int i = 0; i < N - 1; i++) {
        lld cur = -pq.top();
        pq.pop();
        for (int j = 0; j < K; j++) {
            if ((pq.size() + i < N || mx > cur * in[j]) && s.find(cur * in[j]) == s.end()) {
                s.insert(cur * in[j]);
                pq.push(-cur * in[j]);
                mx = max(mx, cur * in[j]);
            }
        }
    }
    printf("%lld", -pq.top());
    return 0;
}