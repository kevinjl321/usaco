#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);

    int n, k;
    cin >> n >> k;

    int diamonds[1000];

    for(int i = 0; i < n; i++){
        cin >> diamonds[i];
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        int amt = 0; 
        for(int j = 0; j < n; j++){
            if(diamonds[j] >= diamonds[i] && diamonds[j] <= diamonds[i] + k){
                amt++;
            }
            ans = max(ans, amt);
        }
    }

    cout << ans << endl;
    return 0;
}