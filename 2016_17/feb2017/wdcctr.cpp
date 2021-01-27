#include<iostream>
#include<map>
using namespace std;

int main(){
    freopen("crossroad.in", "r", stdin);
    freopen("crossroad.out", "w", stdout);

    int n;
    cin >> n;

    int seen[11];

    int ans = 0;
    for(int i = 0; i < n; i++){
        int k, v;
        cin >> k >> v;
        
        if(seen[i] > 0 && seen[i] != v){
            ans++;
        }
        seen[i] = v;
    }

    cout << ans << endl;
    return 0;
}