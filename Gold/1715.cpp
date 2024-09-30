/*
    #백준1715 카드 정렬하기(G4)
        - 그리디하게 우선순위큐를 이용해서 문제를 해결하면 됨
*/
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n;
long long ans;
priority_queue<long long, vector<long long>, greater<long long>> pq;
int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        pq.push(tmp);
    }
    while (pq.size() >= 2) {
        long long cur1 = pq.top(); pq.pop();
        long long cur2 = pq.top(); pq.pop();
        long long ret = cur1 + cur2;
        ans += ret;
        pq.push(ret);
    }
    cout << ans;
    return 0;
}