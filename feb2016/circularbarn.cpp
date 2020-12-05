#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
   
    int n;
    int a[1001];
    int cows = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cows += a[i];
    }

    int sol = 1000000000;
    for (int start = 0; start < n; start++) {
        int cur = 0, cur_cows = cows;
        for (int i = 0; i < n; i++) {
            cur_cows -= a[(start + i) % n];
            cur += cur_cows;
        }
        sol = min(sol, cur);
    }
    
    cout << sol << endl;
    return 0;
}