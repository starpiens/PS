#include <cstdio>
#include <set>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    set<int> s;
    for (int i = 0; i <= 4; i++) {
        int d = 1;
        for (int j = 0; j < i; j++)
            d *= 10;
        for (int j = 0; j < (int) 1e4; j++) {
            int val = j / d;
            val *= (int) 1e3;
            val += 666;
            val *= d;
            val += j % d;
            s.insert(val);
        }
    }

    auto it = s.begin();
    for (int i = 1; i < N; i++, it++);
    printf("%d", *it);

    return 0;
}