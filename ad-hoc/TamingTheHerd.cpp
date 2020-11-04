#include<iostream>
using namespace std;

int main(){
    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);

    int cows[100];

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> cows[i];
    }

    if(cows[0] > 0){
        cout << -1 << endl;
        return 0;
    }

    cows[0] = 0;
    int t = -1;
    int req = 0;
    int pos = 0;
    for(int i = n - 1; i >= 0; i--){
        if(t != -1 && cows[i] != -1 && cows[i] != t){
            cout << -1 << endl;
            return 0;
        }
        if(t == -1){
            t = cows[i];
        }
        if(cows[i] == -1){
            cows[i] = t;
        }
        if(cows[i] == 0){
            req++;
        }
        if(cows[i] == -1){
            pos++;
        }
        if(t > -1){
            t--;
        }
    }
    cout << req << " " << req + pos << endl;
    return 0;
}