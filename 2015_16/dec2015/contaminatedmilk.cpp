#include<iostream>
#include<algorithm>
using namespace std;

int N, M, D, S;
int p[101];
int m[101];
int t[101];
int s[101];
int t_s[101];


bool before(int person, int milk, int time){
    for(int i = 0; i < D; i++){
        if(p[i] == person && m[i] == milk && t[i] < time){
            return true;
        }
    }
    return false;
}

int numDrank(int type){
    bool yes[51] = {false};
    for(int i = 0; i < D; i++){
        if(m[i] = type){
            yes[p[i]] = true;
        }
    }
    int num = 0;
    for(int i = 1; i < D; i++){
        if(yes[i]){
            num++;
        }
    }
    return num;
}

bool bad(int ta){
    for(int i = 0; i < S; i++){
        if(!before(s[i], ta, t_s[i])){
            return false;
        }
    }
    return true;
}

int main(){
    freopen("badmilk.in", "r", stdin);
    freopen("badmilk.out", "w", stdout);

    cin >> N >> M >> D >> S;

    for(int i = 0; i < D; i++){
        cin >> p[i] >> m[i] >> t[i];
    }
    for(int i = 0; i < S; i++){
        cin >> s[i] >> t_s[i];
    }

    int ans = 1000000; 
    for(int i = 1; i <= M; i++){
        int drank;
        if(bad(i)){
            drank = numDrank(i);
            ans = min(drank, ans);
        }
        
    }

    cout << ans << endl;
    return 0;
}
