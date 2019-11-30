#include <stdio.h>
#include <cmath>
bool isok(int n) {
    if (n == 1) return false;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0) return false;
	int rev_n = 0, n_org = n;
	while (n) {
		rev_n *= 10;
		rev_n += n % 10;
		n /= 10;
	}
	return n_org == rev_n;
}
int main() {
	int N; scanf("%d", &N);
	while (!isok(N)) N++;
	printf("%d", N);
    return 0;
}