#include<iostream>
#include<string>
using namespace std;

int main(){
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);

    string s;
    cin >> s;

    int ans = 0;
    for(int i = 0; i < s.length(); i++){
        for(int j = i + 1; j < s.length(); j++){
            for(int k = j + 1; k < s.length(); k++){
                for(int z = k + 1; z < s.length(); z++){
                    ans += s[i] == s[k] && s[j] == s[z];
                }
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}