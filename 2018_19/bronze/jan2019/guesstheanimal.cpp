#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
 
int N;
vector<string> characteristics[100];
 
int num_common(int i, int j){
    int count = 0;
    vector<string> &v1 = characteristics[i], &v2 = characteristics[j];
    for (int i = 0; i < v1.size(); i++){
        for (int j = 0; j < v2.size(); j++){
            if (v1[i] == v2[j]){
                count++;
            }
        }
    }
    return count;
}
 
int main(){
    freopen("guess.in", "r", stdin);
    freopen("guess.out", "w", stdout);

    cin >> N;
    string s;
    for (int i = 0; i < N; i++){
        int K;
        cin >> s >> K;
        for (int j = 0; j < K; j++){
            cin >> s;
            characteristics[i].push_back(s);
        }
    }
        
    int largest = 0;
    for (int i = 0; i < N; i++){
        for (int j=i+1; j<N; j++){
            largest = max(largest, num_common(i,j));
        }
    }
    
    cout << largest+1 << endl;
    return 0;
}