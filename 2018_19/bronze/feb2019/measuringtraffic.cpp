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
    setIO("traffic");

    int N, A[100], B[100];
    string T[100];
        
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> T[i] >> A[i] >> B[i];
    }
        
    int a = -999999999, b = 999999999;
    for (int i = N - 1; i >= 0; i--){
        if (T[i] == "none") { a = max(a, A[i]); b = min(b, B[i]); }
        if (T[i] == "off") { a += A[i]; b += B[i]; }
        if (T[i] == "on") { a -= B[i]; b -= A[i]; a = max(0, a); }
    }
    cout << a << " " << b << endl;
        
    a = -999999999, b = 999999999;
    for (int i = 0; i < N; i++) {
        if (T[i] == "none") { a = max(a, A[i]); b = min(b, B[i]); }
        if (T[i] == "on") { a += A[i]; b += B[i]; }
        if (T[i] == "off") { a -= B[i]; b -= A[i]; a = max(0,a); }
    }
    cout << a << " " << b << endl;

    return 0;
}