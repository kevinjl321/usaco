#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);

    int s[101], t[101], b[101];
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> s[i] >> t[i] >> b[i];
    }

    int ans = 0;
    for(int i = 1; i <= 1000; i++){
        int curr = 0;
        for(int j = 1; j <= n; j++){
            if(s[j] <= i && i <= t[j]) {
                curr += b[j];
            }
        }
        ans = max(ans, curr);
    }

    cout << ans << endl;
    return 0;
}