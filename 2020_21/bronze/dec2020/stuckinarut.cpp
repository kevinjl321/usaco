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

    int xs[51];
    int ys[51];
    char dir[51];
    for(int i = 0; i < n; i++){
        cin >> dir[i] >> xs[i] >> ys[i];
    }

    int ans[51];
    for(int i = 0; i < 51; i++){
        ans[i] = 1000000000;
    }
    
    vector<int> v;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            v.push_back(abs(xs[j] - xs[i]));
            v.push_back(abs(ys[j] - ys[i]));
        }
    }

    sort(v.begin(), v.end());
    for(int d: v){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                if(dir[j] == 'E' && dir[k] == 'N' && xs[j] < xs[k] && ys[k] < ys[j]){
                    if(xs[j] + d == xs[k] && ys[k] + min(ans[k], d) > ys[j]) {
                        ans[j] = min(ans[j], d);
                    }
                    else if(ys[k] + d == ys[j] && xs[j] + min(ans[j], d) > xs[k]){
                        ans[k] = min(ans[k], d);
                    }
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        if(ans[i] == 1000000000){
            cout << "Infinity" << endl;
        }
        else{
            cout << ans[i] << endl;
        }
    }

    return 0;
}