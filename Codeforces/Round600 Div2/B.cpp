#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

char vis[(int) 1e6 + 1];
vector<int> one, two;
vector<int> res;
int num_in;

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int emp;
        scanf("%d", &emp);
        if (emp > 0) {
            if (vis[emp] == 0) {
                vis[emp] = 1;
                one.push_back(emp);
                num_in++;
            } else {
                printf("-1");
                return 0;
            }
        } else {
            if (vis[-emp] == 1) {
                vis[-emp] = 2;
                two.push_back(-emp);
                if (--num_in == 0) {
                    res.push_back(i);
                    for (auto j : one) vis[j] = 0;
                    for (auto j : two) vis[j] = 0;
                    one.clear();
                    two.clear();
                }
            } else {
                printf("-1");
                return 0;
            }
        }
    }
    if (num_in != 0) {
        printf("-1");
        return 0;
    }
    printf("%d\n", (int) res.size());
    int prv = -1;
    for (auto i : res) {
        printf("%d ", i - prv);
        prv = i;
    }
    return 0;
}