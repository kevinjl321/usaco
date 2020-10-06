#include<iostream>
using namespace std;

int main(){
    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);

    int n;
    int cows[100];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> cows[i];
    }
    int ans = n - 1;   
    for(int i = n - 2; i >= 0; i--){
        if(cows[i] < cows[i+1]){
            ans = i;
        }
        else{
            break;
        }
    }
    cout << ans << endl;
    return 0;
}