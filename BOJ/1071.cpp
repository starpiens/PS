#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    vector<int> in(N);
    for (int i = 0; i < N; i++)
        scanf("%d", &in[i]);
    sort(in.begin(), in.end());

    int last = -2;
    for (int i = 0; i < N; i++) {
        if (in[i] + 1 == in[N - 1]) {   // 2nd last number
            for (int j = N - 1; j >= i; j--)
                printf("%d ", in[j]);
            break;
        }

        if (last + 1 == in[i]) {    // cannot place number
            auto it = lower_bound(in.begin(), in.end(), in[i] + 1);
            printf("%d ", *it);
            in.erase(it);
            N--;
        }
        printf("%d ", in[i]);
        last = in[i];
    }

    return 0;
}