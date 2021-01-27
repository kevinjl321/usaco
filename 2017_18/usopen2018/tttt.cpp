#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
#include<cmath>
using namespace std;

char grid[3][3];

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    if((name).size()){
        freopen((name+".in").c_str(), "r", stdin); 
        freopen((name+".out").c_str(), "w", stdout);
    }
}

bool win(char c1, char c2, char a, char b, char c){
    if(a != c1 && a != c2){
        return false;
    }
    if(b != c1 && b != c2){
        return false;
    }
    if(c != c1 && c != c2){
        return false;
    }
    if(a != c1 && b != c1 && c != c1){
        return false;
    }
    if(a != c2 && b != c2 && c != c2){
        return false;
    }
    return true;
}
int cow_wins(char ch){
    if(grid[0][0] == ch && grid[1][1] == ch && grid[2][2] == ch){
        return 1;
    }
    for(int i = 0; i < 3; i++){
        if(grid[0][i] == ch && grid[1][i] == ch && grid[2][i] == ch){
            return 1;
        }
        if(grid[i][0] == ch && grid[i][1] == ch && grid[i][2] == ch){
            return 1;
        }
    }
    return 0;
}

int team_wins(char c1, char c2){
    if(win(c1, c2, grid[0][0], grid[1][1], grid[2][2])){
        return 1;
    }
    if(win(c1, c2, grid[0][2], grid[1][1], grid[2][0])){
        return 1;
    }
    for(int i = 0; i < 3; i++){
        if(win(c1, c2, grid[0][i], grid[1][i], grid[2][i])){
            return 1;
        }
        if(win(c1, c2, grid[i][0], grid[i][1], grid[i][2])){
            return 1;
        }
    }
    return 0;
}

int main(void){
    setIO("tttt");

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> grid[i][j];
        }
    }

    int ans1 = 0; int ans2 = 0;
    for(char c = 'A'; c <= 'Z'; c++){
        ans1 += cow_wins(c);
    }
    for(char c1 = 'A'; c1 <= 'Z'; c1++){
        for(char c2 = c1 + 1; c2 <= 'Z'; c2++){
            ans2 += team_wins(c1, c2);
        }
    }

    cout << ans1 << endl << ans2 << endl;
    return 0;
}