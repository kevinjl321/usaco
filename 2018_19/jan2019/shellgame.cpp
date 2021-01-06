#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
#include<cmath>
using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    if((name).size()){
        freopen((name+".in").c_str(), "r", stdin); 
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int main(void){
    setIO("shell");

    int n;
    int positions[3];
    int ctr[3] = {0};

    cin >> n;
    for(int i = 0; i < 3; i++){
        positions[i] = i;
    }
    
    for(int i = 0; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--, c--;
        
        swap(positions[a], positions[b]);
        ctr[positions[c]]++;
    }
    
    cout << max({ctr[0], ctr[1], ctr[2]}) << endl;
    return 0;
}