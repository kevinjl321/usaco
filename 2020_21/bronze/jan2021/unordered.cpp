#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
#include<cmath>
using namespace std;

string alpha;
string heard;

int findLetter(char a){
    for(int i = 0; i < 26; i++){
        if(alpha[i] == a){
            return i;
        }
    }
    return 0;
}

int main(void){
    cin >> alpha >> heard;

    int ans = 0;
    bool inAlpha = true;
    for(int i = 0; i < heard.size(); i++){
        if(findLetter(heard[i+1]) <= findLetter(heard[i])){
            if(inAlpha){
                inAlpha = false;
            }
            ans++;
        }
        else{
            inAlpha = true;
        }
    }

    cout << ans << endl;
    return 0;
}