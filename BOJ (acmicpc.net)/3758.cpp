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
#include <fstream>
#include <random>
#include <functional>

#define INF 2100000000
#define ABS(n) (((n) > 0) ? (n) : -(n))
#define SQR(n) ((n) * (n))

typedef long long ll;
typedef unsigned long long llu;

using namespace std;

struct Team {
    int sum = 0;
    int score[101] = { 0, };
    int num_submit = 0;
    int last = 10001;
};

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, k, t, m;
        scanf("%d %d %d %d", &n, &k, &t, &m);
        vector<Team> v(n + 1);
        while (m--) {
            int i, j, s;
            scanf("%d %d %d", &i, &j, &s);
            v[i].num_submit++;
            v[i].last = m;
            if (v[i].score[j] < s) {
                v[i].sum += s - v[i].score[j];
                v[i].score[j] = s;
            }
        }
        
        int ans = 1;
        for (int i = 1; i <= n; i++) {
            ans += (v[i].sum > v[t].sum) || (
                   (v[i].sum == v[t].sum) && (
                       (v[i].num_submit < v[t].num_submit) || (
                       (v[i].num_submit == v[t].num_submit) && (
                           v[i].last > v[t].last
                       ))
                   ));
        }
        
        printf("%d\n", ans);
    }

    return 0;
}