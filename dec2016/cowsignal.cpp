#include<iostream>
#include<string>
using namespace std;

int n, m, k;

int main(){
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);

    cin >> n >> m >> k;

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < k; j++){
            for(int a = 0; a < m; a++){
                for(int b = 0; b < k; b++){
                    cout << s[a];
                }
            }
            cout << endl;
        }
    }

    return 0;
}