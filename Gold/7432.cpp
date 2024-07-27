/*
    #백준7432 디스크 트리(G3)
        - 문자열 trie 문제
        - trie 자료구조를 이용해서 문제를 해결하면 됨
        - 문자 \을 기준으로 나눠지니 split함수를 이용해서 입력 문자열을 쪼개주어 trie를 구성할 수 있도록 함

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
    if (v.size() == idx) return;
    if (nd.child.find(v[idx]) == nd.child.end()) nd.child[v[idx]] = node();
    insert(nd.child[v[idx]], v, idx + 1);
}
void dfs(node &nd, int dep) {
    for (auto i : nd.child) {
        for (int j = 0; j < dep; j++) cout << " ";
        cout << i.first << "\n";
        dfs(i.second, dep + 1);
    }
}
vector<string> split(string s, string d) {
    vector<string> ret;
    long long pos = 0;
    string token = "";
    while ((pos = s.find(d)) != string::npos) {
        token = s.substr(0, pos);
        ret.push_back(token);
        s.erase(0, pos + d.size());
    }
    ret.push_back(s);
    return ret;
}
int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    while (n--) {
        string s; cin >> s;
        string d = "\\";
        vector<string> v = split(s, d);
        insert(root, v, 0);
    }
    dfs(root, 0);
    return 0;
}