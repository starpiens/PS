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

int main() {
    int arr[] = {500, 100, 50, 10, 5, 1};
    int cnt = 0;
    int N;
    scanf("%d", &N);
    N = 1000 - N;
    for (int i = 0; i < 6; i++) {
        while (N >= arr[i]) {
            N -= arr[i];
            cnt++;
        }
    }
    printf("%d", cnt);

    return 0;
}