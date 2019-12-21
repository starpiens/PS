#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

bool chk[(int)1e5];
vector<int> prime;

bool isprime(int n) {
    int sqn = (int)sqrt(n) + 1;
    for (auto i : prime) {
        if (i != n && n % i == 0)
            return false;
        if (i > sqn)
            return true;
    }
    return true;
}

int main() {
    int lim = (int)sqrt(1e9) + 1;
    for (int i = 2; i <= lim; i++)
        if (!chk[i]) {
            prime.push_back(i);
            for (int j = i + i; j <= lim; j += i)
                chk[j] = true;
        }
    int n;
    scanf("%d", &n);
    for (int b = 2; ; b++)
        if (!isprime(b) && !isprime(b + n))
            return printf("%d %d", b + n, b), 0;
    return 0;
}