#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
#include<cmath>
using namespace std;

int capacity[3], amount[3];

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    if((name).size()){
        freopen((name+".in").c_str(), "r", stdin); 
        freopen((name+".out").c_str(), "w", stdout);
    }
}

void pour(int i, int j){
    int amt = min(amount[i], capacity[j] - amount[j]);
    amount[i] -= amt;
    amount[j] += amt;
}

int main(void){
    setIO("mixmilk");

    for(int i = 0; i < 3; i++){
        cin >> capacity[i] >> amount[i];
    }

    for(int i = 0; i < 100; i++){
        pour(i % 3, (i + 1) % 3);
    }

    for(int i = 0; i < 3; i++){
        cout << amount[i] << endl;
    }

    return 0;
}