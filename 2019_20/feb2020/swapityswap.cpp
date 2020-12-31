#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
#include<cmath>
using namespace std;

int cows[101];
int n, k, a1, a2, b1, b2;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    if((name).size()){
        freopen((name+".in").c_str(), "r", stdin); 
        freopen((name+".out").c_str(), "w", stdout);
    }
}

void rev(int start, int end){
    while(start < end){
        int temp = cows[start];
        cows[start] = cows[end];
        cows[end] = temp;
        start++;
        end--;
    }
}

int main(void){
    setIO("swap");

    cin >> n >> k >> a1 >> a2 >> b1 >> b2;

    for(int start = 1; start <= n; start++){
        cows[start] = start;
    }

    for(int i = 0; i < k ; i++){
        rev(a1, a2);
        rev(b1, b2);
    }

    for(int i = 1; i <= n; i++){
        cout << cows[i] << endl;
    }
    return 0;
}