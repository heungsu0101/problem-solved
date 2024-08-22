/*
    #백준10775 공항(G2)
        - 그리디 문제
        - 유니온 파인드를 통해 gate를 연결해서 문제를 해결할 수 있음
        - 유니온 파인드 구현 방법은 총 3가지가 있음
            1. 트리의 높이를 이용해 구현 (union함수 구현에 해항)
            2. 트리의 사이즈를 이용해 구현 (union함수 구현에 해당)
            3. 경로압축을 이용해 구현 (find함수 구현에 해당)
            - 1, 2번은 임의의 정점의 루트를 찾는 과정이 O(log n)의 시간복잡도가 걸림
            - 3번 또한 O(log n)의 시간복잡도가 걸림, 하지만 처음에 경로를 압축하는 과정에서 O(n)의 시간이 걸림을 인지해야함
            - 1-3번 또는 2-3번을 같이 사용한다면 경로를 압축하는 과정 또한 O(log n)의 시간이 걸리므로 조금 더 효율적이게 됨

*/
#include <iostream>
#include <algorithm>

using namespace std;

int g, p, parent[100005], ans;
int findRoot(int node) {
    if (node == parent[node]) return node;
    return parent[node] = findRoot(parent[node]);
}
void isUnion(int a, int b) {
    a = findRoot(a);
    b = findRoot(b);
    if (a == b) return;
    parent[a] = b;
}
int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> g >> p;
    for (int i = 1; i <= g; i++) parent[i] = i;
    for (int i = 0; i < p; i++) {
        int a; cin >> a;
        a = findRoot(a);
        if (a == 0) break;
        isUnion(a, a - 1);
        ans++;
    }
    cout << ans;
    return 0;
}