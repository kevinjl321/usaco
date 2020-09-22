//Link: https://codeforces.com/contest/863/problem/B
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    int kayaks = n - 1;
    vector<int> weights;
    for(int i = 0; i < 2*n; i++){
        int w;
        cin >> w;
        weights.push_back(w);
    }

    sort(weights.begin(), weights.end());

    int ctr = 0;
    for(int i = 0; i < weights.size() - 3; i++){
        ctr += abs(weights[i+1] - weights[i]);
    }

    cout << ctr;
    return 0;
}


