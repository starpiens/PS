#include <cstdio>
#include <vector>

using namespace std;

int t[501];
vector<int> g[501];
int ans[501];

int dfs(int n) {
    if (ans[n]) return ans[n];
    int ret = 0;
    for (int i : g[n]) {
        ret = max(ret, dfs(i));
    }
    return ans[n] = ret + t[n];
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &t[i]);
        int x;
        while (scanf("%d", &x), x > 0) {
            g[i].push_back(x);
        }
    }
    for (int i = 1; i <= N; i++)
        printf("%d\n", dfs(i));
    return 0;
}