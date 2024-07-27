/*
    #백준14725 개미굴(G3)
        - 문자열 trie 문제
        - trie 자료구조를 통해 문제를 해결할 수 있음
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

int n;
struct node{
    map<string, node> child;
}root;
void insert(node &nd, vector<string> &v, int idx) {
    if (idx == v.size()) return;
    if (nd.child.find(v[idx]) == nd.child.end()) nd.child[v[idx]] = node();
    insert(nd.child[v[idx]], v, idx + 1);
}
void dfs(node &nd, int dep) {
    for (auto i : nd.child) {
        for (int j = 0; j < dep; j++) cout << "--";
        cout << i.first << "\n";
        dfs(i.second, dep + 1);
    }
}
int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        vector<string> v(t);
        for (int j = 0; j < t; j++) cin >> v[j];
        insert(root, v, 0);
    }
    dfs(root, 0);
    return 0;
}