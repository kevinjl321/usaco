#include <iostream>
#include <string>
using namespace std;
using ll = long long;

int main() {
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);

    ll n;
    cin >> n;

    string A;
    string B;
    cin >> A >> B;

    ll ans = 0;
    bool mismatched = false;
    for(ll i = 0; i < n; i++) {
      if(A[i] != B[i]) {
        if(!mismatched) {
          mismatched = true;
          ans++;
        }
      } 
      else {
        mismatched = false;
      }
    }

    cout << ans << endl;
    return 0;
}