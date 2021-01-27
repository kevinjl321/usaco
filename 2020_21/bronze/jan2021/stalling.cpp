#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
#include<cmath>
using namespace std;

typedef long long ll;

int n;
ll a[21], b[21];

int main(void){
    cin >> n;

    vector<ll> valid;
    for(int i = 0; i < n; i++){cin >> a[i]; valid.emplace_back(0);}
    for(int i = 0; i < n; i++){cin >> b[i];}

    ll ans = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i] <= b[j]){
                valid[i]++;
            }
        }
    }

    sort(valid.begin(), valid.end());

    for (int i = 0; i < n; i++){ans = max(ans, (ans * ((valid[i]) - i)));}

    cout << ans << endl;
    return 0;
}