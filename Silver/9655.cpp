/*
    #백준9655 돌 게임(S5)
        - dp로 분류되어 있으나 n이 짝수인지 홀수인지만 판단하면 되는 문제..
*/
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int main(void) {
    cin >> n;
    if (n % 2 == 0) cout << "CY";
    else cout << "SK";
}