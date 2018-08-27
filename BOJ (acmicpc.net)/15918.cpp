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

typedef long long ll;
typedef unsigned long long llu;

using namespace std;

int N, X, Y, cnt;
int arr[24];
vector<int> num;

void f(int n) {
    if (n == N * 2) {
        cnt++;
        return;
    }
    if (arr[n]) {
        f(n + 1);
        return;
    }
    for (int i = 0; i < num.size(); i++) {
        int now = num[i];
        if (n + now + 1 >= 2 * N || arr[n + now + 1]) continue;
        arr[n] = now;
        arr[n + now + 1] = now;
        num.erase(num.begin() + i);
        f(n + 1);
        arr[n] = arr[n + now + 1] = 0;
        num.insert(num.begin() + i, now);
    }
}

int main() {
    scanf("%d %d %d", &N, &X, &Y);
    int Z = max(X, Y) - min(X, Y) - 1;
    arr[X - 1] = arr[Y - 1] = Z;
    for (int i = 1; i <= N; i++)
        if (i != Z)
            num.push_back(i);
    f(0);
    printf("%d", cnt);
    return 0;
}