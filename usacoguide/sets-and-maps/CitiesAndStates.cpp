#include<iostream>
#include<map>
#include<string>
using namespace std;

typedef long long ll;

int main(){
    freopen("citystate.in", "r", stdin);
    freopen("citystate.out", "w", stdout);

    int n;
    cin >> n;

    map<string, long> cnt;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        string city, state;
        cin >> city >> state;
        city = city.substr(0,2);
        if(city != state){
            ans += cnt[state + city];
        }
        cnt[city + state]++;
    }

    cout << ans << endl;
    return 0;
}