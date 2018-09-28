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

#define INF 2100000000
#define ABS(n) (((n) > 0) ? (n) : -(n))
#define SQR(n) ((n) * (n))

typedef long long ll;
typedef unsigned long long llu;

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N;
        char in[1000];
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
            scanf(" %c", &in[i]);
        stack<char> s;
        vector<char> v;
        s.push(in[0]);
        for (int i = 1; i < N; i++) {
            if (s.top() >= in[i]) s.push(in[i]);
            else v.push_back(in[i]);
        }
        while (!s.empty()) {
            printf("%c", s.top());
            s.pop();
        }
        for (auto i : v) {
            printf("%c", i);
        }
        printf("\n");
    }

    return 0;
}