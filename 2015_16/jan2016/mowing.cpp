#include<iostream>
#include<string>
using namespace std;

int main(){
    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout);

    int n;
    cin >> n;

    int pos[2001][2001];
    for(int i = 0; i < 2001; i++){
        for(int j = 0; j < 2001; j++){
            pos[i][j] = -1;
        }
    }

    int currX = 1000;
    int currY = 1000;
    pos[currX][currY] = 0;
    int time = 0;
    int ans = 1001;

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        int dirX = 0;
        int dirY = 0;
        if(s == "N"){
            dirX = -1;
        }
        else if(s == "S"){
            dirX = 1;
        }
        else if(s == "W"){
            dirY = -1;
        }
        else{
            dirY = 1;
        }
        int steps;
        cin >> steps;
        for(int j = 1; j <= steps; j++){
            currX += dirX;
            currY += dirY;
            time++;
            if(pos[currX][currY] >= 0 && time - pos[currX][currY] < ans){
                ans = time - pos[currX][currY];
            }
            pos[currX][currY] = time;
        }
    }
    if(ans == 1001){
        ans = -1;
    }

    cout << ans << endl;
    return 0;
}