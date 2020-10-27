#include<iostream>
#include<map>
using namespace std;

typedef long long ll;

int main(){
    freopen("citystate.in", "r", stdin);
    freopen("citystate.out", "w", stdout);

    ll n;
    cin >> n;
    map<string, int> cnt;
    ll ans = 0;

    for(int i = 0; i < n; i++){
        string city;
        string state;
        cin >> city >> state;
        if(city.substr(0, 2) != state){
            ans += cnt[state + city];
        }
        cnt[city + state]++;
    }

    cout << ans << endl;
    return 0;
}