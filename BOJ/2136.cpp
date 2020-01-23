#include <cstdio>
#include <algorithm>
using namespace std;

pair<int, int> in[(int)1e5];

int main() {
    int N, L;
    scanf("%d %d", &N, &L);
    int lcnt = 0, lmax = 0, rmin = L;
    for (int i = 0; i < N; i++) {
        scanf("%d", &in[i].first);
        if (in[i].first > 0) {
            rmin = min(rmin, in[i].first);
        } else {
            lmax = max(lmax, in[i].first *= -1);
            lcnt++;
        }
        in[i].second = i + 1;
    }
    sort(in, in + N);
    if (lmax < L - rmin) {
        printf("%d %d", in[lcnt].second, L - rmin);
    } else {
        printf("%d %d", in[lcnt - 1].second, lmax);
    }
    return 0;
}