/*
    #백준1671 상어의 저녁식사(P3)
        - 이분 매칭 문제
        - 스텟이 같은 경우, 번호가 작은 상어가 먹을 수 있도록 하더라도, 문제가 생기지 않음
        - 이분 매칭 문제는 기본적으로 최대 유량 문제이기 떄문에, 최대 유량은 어쩌다 잘못 흐르더라도 항상 최적해를 가질 수 있도록 해줌
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct shark{
    int a, b, c;
};
int n, matched[51], visited[51], cnt;
vector<shark> v(51);
vector<int> adj[51];
bool dfs(int cur) {
    for (int next : adj[cur]) {
        if (visited[next]) continue;
        visited[next] = true;
        if (matched[next] == 0 || dfs(matched[next])) {
            matched[next] = cur;
            return true;
        }
    }
    return false;
}
int main(void) {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i].a >> v[i].b >> v[i].c;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if (v[i].a >= v[j].a && v[i].b >= v[j].b && v[i].c >= v[j].c) {
                if (v[i].a == v[j].a && v[i].b == v[j].b && v[i].c == v[j].c) {
                    if (i > j) adj[i].push_back(j);
                } else adj[i].push_back(j);
            } 
        }
    }
    for (int i = 1; i <= n; i++) {
        fill(visited, visited + 51, 0);
        if (dfs(i)) cnt++;
        fill(visited, visited + 51, 0);
        if (dfs(i)) cnt++;
    }
    cout << n - cnt;
    return 0;
}