#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;

int n; ll weights[20];

ll solve(int i, ll s1, ll s2){
    if(i == n){
        return abs(s1 - s2);
    }
    return min(solve(i + 1, s1 + weights[i], s2), 
                solve(i + 1, s1, s2 + weights[i]));
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }
    cout << solve(0, 0, 0) << "\n";
}