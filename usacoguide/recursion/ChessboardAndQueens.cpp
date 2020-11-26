#include<iostream>
#include<string>
using namespace std;

string g[8];
bool sum[15], dif[15], c[8];
int ans = 0;
 
void dfs(int r) { 
    if (r == 8) {
        ++ ans; 
        return;
    }
    for(int i = 0; i < 8; i++){
        if (g[r][i] == '.' && !c[i] && !sum[i + r] && !dif[i - r + 7]) {
            c[i] = sum[i + r] = dif[i - r + 7] = 1;
            dfs(r + 1);
            c[i] = sum[i + r] = dif[i - r + 7] = 0;
        }
    }
}
 
int main() { 
    for(int i = 0; i < 8; i++){
        cin >> g[i];
    } 
    dfs(0); 
    cout << ans << endl;
}