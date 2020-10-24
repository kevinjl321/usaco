#include<iostream>
#include<string>
using namespace std;

int main(){
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);

    int n;
    int order[101];
    int current[101];
    int initial[101];

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> order[i];
    }

    for(int i = 1; i <= n; i++){
        cin >> current[i];
    }  

    for(int i = 0; i < 3; i++){
        for(int j = 1; j <= n; j++){
            initial[j] = current[order[j]];
        }
        for(int j = 1; j <= n; j++){
            current[j] = initial[j];
        }
    }

    for(int i = 1; i <= n; i++){
        cout << current[i] << endl;
    }
    return 0;
}