#include<iostream>
#include<algorithm>
using namespace std;

int n, b[11][11];

bool appears(int c){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(b[i][j] == c){
                return true;
            }
        }
    }
    return false;
}

bool onTop(int c1, int c2){
    int top = n, bottom = 0, left = n, right = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(b[i][j] == c2){
                top = min(top, i);
                bottom = max(bottom, i);
                left = min(left, j);
                right = max(right, j);
            }
        }
    }
    for(int i = top; i <= bottom; i++){
        for(int j = left; j <= right; j++){
            if(b[i][j] == c1){
                return true;
            }
        }
    }
    return false;
}

int main(){
    freopen("art.in", "r", stdin);
    freopen("art.out", "w", stdout);

    int ans = 0;
    for(int i = 1; i <= 9; i++){
        if(appears(i)){
            bool first = true;
            for(int j = 1; j <= 9; j++){
                if(j != i && appears(j) && onTop(i, j)){
                    first = false;
                }
            }
            if(first){
                ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}