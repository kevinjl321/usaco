#include<iostream>
using namespace std;

int main(){
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);

    int x, y, m;
    cin >> x >> y >> m;

    int ans = 0;
    for(int i = 0; i * x <= m; i++){
        for(int j = 0; j * y <= m; j++){
            if(i * x + j * y > ans){
                ans = i * x + y * j;
            }
        }
    }

    cout << ans << endl;
    return 0;
}