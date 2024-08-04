/*
    #백준11722 가장 긴 감소하는 부분 수열(S2)
        - lds 문제
*/
#include <iostream>
#include <algorithm>

using namespace std;
int n, lds[1003], a[1003], len;
void go() {
    for (int i = 0; i < n; i++) {
        int idx = len;
        for (int j = 0; j < len; j++) {
            if (a[i] >= lds[j]) {
                idx = j; break;
            }
        }
        if (idx == len) len++;
        lds[idx] = a[i];
    }
}
int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    go();
    cout << len;
    return 0;
}