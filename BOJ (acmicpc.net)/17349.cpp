#include <bits/stdc++.h>

using namespace std;

int main() {
    int in[9][2];
    for (int i = 0; i < 9; i++)
        scanf("%d %d", &in[i][0], &in[i][1]);

    int ans = -1;
    for (int i = 0; i < 9; i++) {
        // i번째가 거짓말
        if (i > 0) in[i - 1][0] ^= 1;
        in[i][0] ^= 1;
        int guess[10], fail = 0;
        memset(guess, -1, sizeof(guess));

        for (int j = 0; j < 9; j++) {
            if (guess[in[j][1]] != -1 && guess[in[j][1]] != in[j][0])
                fail = 1;
            else guess[in[j][1]] = in[j][0];
        }
        if (fail) continue;

        set<int> s_1;
        set<int> s_unkown;
        for (int j = 1; j <= 9; j++) {
            if (guess[j] == 1) s_1.insert(j);
            if (guess[j] == -1) s_unkown.insert(j);
        }
        if (s_1.size() > 1) continue;
        if (s_1.size() == 1) {
            if (ans != -1) return printf("-1"), 0;
            ans = *s_1.begin();
        } else if (s_unkown.size() == 1) {
            if (ans != -1) return printf("-1"), 0;
            ans = *s_unkown.begin();
        } else if (s_unkown.size() == 0) {
            continue;
        } else {
            return printf("-1"), 0;
        }
    }
    printf("%d", ans);

    return 0;
}