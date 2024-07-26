/*
    #백준1311 할 일 정하기1(G1)
        - 비트마스킹 + dp문제
        - 문제를 처음 풀 때, 2차원 dp를 활용하여 문제를 해결하였음
        - 하지만, 굳이 2차원 dp를 사용할 필요 없는게
          예를 들어 외판원 순회문제의 경우 visited 상태와 cur의 상태, 2가지 요소가 중요하기 때문에 2차원 dp를 사용함
          하지만, 이 문제는 어떤 일을 해결했는지 즉, visited 상태만 고려하면 되기 때문에(사람은 1번, 2번 순서대로 함수가 돌아감)
          1차원 dp를 통해 해결할 수 있음
        - 위와 같은 방법으로 2차원 dp를 사용할 때 보다, 메모리, 시간복잡도 차원에서 더 효율적으로 해결할 수 있음
*/
#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 987654321;
int n, a[21][21], dp[1 << 20];

int go(int visited, int person) {
    if (visited == (1 << n) - 1) return 0;
    int &ret = dp[visited];
    if (ret) return ret;
    
    ret = INF;
    for (int i = 0; i < n; i++) {
        if (visited & (1 << i)) continue;
        ret = min(ret, go(visited | (1 << i), person + 1) + a[person][i]);
    }

    return ret;
}
int main(void) {
    ios::sync_with_stdio(false); cin.tie(0); 
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    cout << go(0, 0) << "\n";
    return 0;
}