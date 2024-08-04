/*
    #백준12015 가장 긴 증가하는 부분 수열 2(G2)
        - lis 문제
        - 단순히 lis를 구성할 때, i번째 원소가 lis에 포함되는지 판단할 때 선형탐색을 할 경우 시간초과가 발생할 수 밖에 없음
        - 이때, 이분탐색을 이용하면 lis를 O(nlogn)의 시간복잡도로 구할 수 있음
*/
#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 987654321;
int n, a[1000006], lis[1000006], len;
void go() {
    for (int i = 0; i < n; i++) {
        int idx = lower_bound(lis, lis + len, a[i]) - lis;
        if (lis[idx] == INF) len++;
        lis[idx] = a[i];
    }
}
int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);
    fill(lis, lis + 1000006, INF);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    go();
    cout << len << "\n";
    return 0;
}