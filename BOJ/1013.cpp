#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string in;
        cin >> in;
        int idx = 0, fail = 1;
        while (idx < in.size()) {
            if (in.substr(idx, 3) == "100") {     // 100+1+
                idx += 3;
                while (idx < in.size() && in[idx] == '0') idx++;
                if (idx == in.size()) {
                    fail = 1;
                    break;
                }
                fail = 0;
                idx++;
                while (idx < in.size() && in[idx] == '1' && (idx > in.size() - 3 || in.substr(idx, 3) != "100")) idx++;
            } else if (in.substr(idx, 2) == "01") {    // 01
                idx += 2;
                fail = 0;
            } else {
                fail = 1;
                break;
            }
        }
        printf("%s\n", fail ? "NO" : "YES");
    }
    return 0;
}