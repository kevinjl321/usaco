#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);

    int n;
    string boards[101][2];
    int blocks[26] = {0};

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> boards[i][0] >> boards[i][1];
    }

    for(int i = 0; i < n; i++){
        for(char j = 'a'; j <= 'z'; j++){
            int first = 0;
            int second = 0;
            for(int k = 0; k < boards[i][0].length(); k++){
                if(boards[i][0][k] == j){
                    first++;
                }
            }
            for(int k = 0; k < boards[i][1].length(); k++){
                if(boards[i][1][k] == j){
                    second++;
                }
            }
            int max_l = max(first, second);
            blocks[j - 'a'] += max_l;
        }
    }

    for(int i = 0; i < 26; i++){
        cout << blocks[i] << endl;
    }
    
    return 0;
}