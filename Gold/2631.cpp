/*
    #백준2631 줄 세우기(G4)
        - lis문제
        - 어떤 학생을 옮겨야하나 생각해보면 lis를 구해서 기준을 구하고 lis에 해당하지 않은 학생들만 옮겨주면 됨.
        - 따라서 n - lis길이 답이 됨
*/
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