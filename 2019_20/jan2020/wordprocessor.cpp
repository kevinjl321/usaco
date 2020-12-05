#include<iostream>
#include<string>
using namespace std;
 
int main(){
    freopen("word.in", "r", stdin);
    freopen("word.out", "w", stdout);
 
    int n, k;
    cin >> n >> k;

    string word;
    int len = 0, wordCnt = 0;
    for(int i = 0; i < n; i++){
        cin >> word;
        len += word.size();
        if(len <= k){
            wordCnt++;
            if(1 != wordCnt){
                cout << ' ';
            }
            cout << word;
        }
        else{
            wordCnt = 1;
            cout << endl << word;
            len = word.size();
        }
    }
    return 0;
}
