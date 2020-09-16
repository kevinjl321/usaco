#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    //freopen("blocks.in", "r", stdin);
    //freopen("blocks.out", "w", stdout);

    int n; 
    cin >> n;
    
    vector<vector<int>> final(26);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 26; j++){
            string s1, s2;
            cin >> s1 >> s2;
            vector<int> freq1(26);
            vector<int> freq2(26);
            for(char x: s1){
                freq1[x - 'a']++;
            }
            for(char x: s2){
                freq2[x - 'a']++;
            }
            for(int k = 0; k < 26; k++){
                if(freq1[k] < freq2[k]){
                    final[k].push_back(freq2[k]);
                }
                else{
                    final[k].push_back(freq1[k]);
                }
            }

        }
    }
    for(auto arr: final){
        int freq = 0;
        sort(arr.rbegin(), arr.rend());
        for(int i = 0; i < n; i++){
            freq += arr[i];
        }
        cout << freq << endl;
    }
}