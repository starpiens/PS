#include <cstdio>
#include <numeric>

using namespace std;

int dp[11][11];
int sum[11][11];

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 1; i <= 10; i++) {
        dp[i][i - 1] = 1;
        for (int j = i; j < 10; j++)
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
    }
    for (int i = 1; i <= 10; i++) {
        sum[i][i - 1] = 0;
        for (int j = i; j <= 10; j++)
            sum[i][j] = sum[i][j - 1] + dp[i][j - 1];
    }

    for (int i = 1; i <= 10; i++) {
        if (N < sum[i][10]) {
            for (int j = i; j > 0; j--) {
                for (int k = j - 1; k < 10; k++)
                    if (N < sum[j][k + 1]) {
                        printf("%d", k);
                        N -= sum[j][k];
                        break;
                    }
            }
            return 0;
        }
        N -= sum[i][10];
    }

    printf("-1");
    return 0;
}