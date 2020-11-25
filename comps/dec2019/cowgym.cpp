#include<iostream>
using namespace std;

int K, N;
int train[11][21];

bool better(int K, int a, int b){
    int posA, posB;
    for(int i = 0; i < N; i++){
        if(train[K][i] == a) {
            posA = i;
        }
        if(train[K][i] == b){
            posB = i;
        }
    }
    return posA < posB;
}

int numBetter(int a, int b){
    int n = 0;
    for(int i = 0; i < K; i++){
        if(better(i, a, b)){
            n++;
        }
    }
    return n;
}

int main(){
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);

    cin >> K >> N;

    for(int i = 0; i < K; i++){
        for(int j = 0; j < N; j++){
            cin >> train[i][j];
        }
    }

    int ans = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(numBetter(i, j) == K){
                ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
