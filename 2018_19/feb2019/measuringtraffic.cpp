#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
     
int main(){
    freopen("traffic.in", "r", stdin);
    freopen("traffic.out", "w", stdout);

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