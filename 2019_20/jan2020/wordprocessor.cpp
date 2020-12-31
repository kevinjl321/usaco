#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
#include<cmath>
using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    if((name).size()){
        freopen((name+".in").c_str(), "r", stdin); 
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int main(void){
    setIO("word");

    int n, k;
    cin >> n >> k;

    string word;
    int len = 0, words = 0;
    for(int i = 0; i < n; i++){
        cin >> word;
        len += word.size();
        if(len <= k){
            words++;
            if(words != 1){
                cout << ' ';
            }
            cout << word;
        }
        else{
            words = 1;
            cout << endl << word;
            len = word.size();
        }
    }

    cout << endl;
    return 0;
}