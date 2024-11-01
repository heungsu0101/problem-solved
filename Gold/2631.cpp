#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int INF = 987654321;
int n, lis[202], len;
vector<int> v;
void go() {
    for (int i = 0; i < n; i++) {
        int pos = upper_bound(lis, lis + len, v[i]) - lis;
        if (lis[pos] == INF) len++;
        lis[pos] = v[i]; 
    }
}
int main(void) {
    fill(lis, lis + 202, INF);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        v.push_back(tmp);
    }
    go();
    cout << n - len;
    return 0;
}