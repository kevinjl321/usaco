#include<iostream>
#include<string>
using namespace std;

int main(){
    freopen("cowtip.in", "r", stdin);
    freopen("cowtip.out", "w", stdout);

    int n;
    cin >> n;

    string grid[10];

    for(int i = 0; i < n; i++){
        cin >> grid[i];
    }

    int ans = 0;
    for(int i = n - 1; i >= 0; i--){
        for(int j = n - 1; j >= 0; j--){
            if(grid[i][j] == '1'){
                ans++;
                for(int a = 0; a <= i; a++){
                    for(int b = 0; b <= j; b++){
                        if(grid[a][b] == '0'){
                            grid[a][b] = '1';
                        }
                        else{
                            grid[a][b] = '0';
                        }
                    }
                }
            }
        }
    }
    
    cout << ans << endl;
    return 0;

}