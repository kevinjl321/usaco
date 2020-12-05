#include<iostream>
#include<map>
using namespace std;

int main(){
    freopen("crossroad.in", "r", stdin);
    freopen("crossroad.out", "w", stdout);

    map<int, int> m;
    int n;
    cin >> n;

    int ans = 0;
    for(int i = 0; i < n; i++){
        int k, v;
        cin >> k >> v;
        if(m.count(k) > 0){
            if(m[k] != v){
                ans++;
            }
            else{
                m[k] = v;
            }
        }
        else{
            m[k] = v;
        }
    }

    cout << ans << endl;
    return 0;
}