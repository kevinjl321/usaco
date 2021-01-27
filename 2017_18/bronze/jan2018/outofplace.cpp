#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);

    int n;
    cin >> n;

    int height[100];
    vector<int> sorted;

    for(int i = 0; i < n; i++){
        cin >> height[i];
        sorted.push_back(height[i]);
    }

    sort(sorted.begin(), sorted.end());

    int ans = -1;
    for(int i = 0; i < n; i++){
        if(sorted[i] != height[i]){
            ans++;
        }
    }
    ans = max(0, ans);

    cout << ans << endl;
    return 0;
}