#include<iostream>
using namespace std;

int main(){
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);

    int X, Y, M;
    cin >> X >> Y >> M;

    int ans = 0;
    for(int i = 0; i * X <= M; i++){
        for(int j = 0; i * X + j * Y <= M; j++){
            if(i * X +  j * Y > ans){
                ans = i * X + j * Y;
            }
        }
    }

    cout << ans << endl;
    return 0;

}