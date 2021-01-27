#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
#include<cmath>
using namespace std;

int main(void){
    int n;
    cin >> n;

    int f[101];
    for(int i = 0; i < n; i++){
        cin >> f[i];
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int total = 0;
            for(int k = i; k <= j; k++){
                total += f[k];
            }
            bool avg = false;
            for(int k = i; k <= j; k++){
                if(f[k] * (j - i + 1) == total){
                    avg = true;
                }
            }
            if(avg){
                ans++;
            }
        
        }
    }

    cout << ans << endl;
    return 0;
}