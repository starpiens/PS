#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <functional>

#define INF 2100000000
#define ABS(n) (((n) > 0) ? (n) : -(n))
#define SQR(n) ((n) * (n))

typedef long long ll;
typedef unsigned long long llu;

using namespace std;

stack<char> s;
char in[500002];

int main() {
    int N, K;
    scanf("%d %d ", &N, &K);
    scanf("%s", in);
    in[N] = '9' + 0;

    int idx = 0;
    while (K) {
        if (!s.empty() && s.top() < in[idx]) {
            s.pop();
            K--;
        } else s.push(in[idx++]);
    }

    stack<char> tmp;
    while (!s.empty()) {
        tmp.push(s.top());
        s.pop();
    }
    while (!tmp.empty()) {
        printf("%c", tmp.top());
        tmp.pop();
    }

    in[N] = 0;
    printf("%s", in + idx);

    return 0;
}