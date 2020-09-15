#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N;

int main(){
    //freopen("angry.in", "r", stdin);
    //freopen("angry.out", "w", stdout);
   
    cin >> N;
    vector<int> pos = {0};

    for(int i = 0; i < N; i++){
        int n;
        cin >> n;
        pos[i] = n;
    }

    sort(pos.begin(), pos.end());
    int ans = -1;
    for(int i = 0; i < N; i++){
        int start = pos[i];
        int current = 1;
        int radius = 1;
        int down = i - 1;
        int up = i + 1;
        bool goneUp = true;
        bool goneDown = true;
        while(true){
            bool goDown = false;
            bool goUp = false;
            int current_up = pos[up - 1] + radius;
            int current_down = pos[up + 1] - radius;
            while(down >= 0 && pos[down] >= current_down && goneDown){
                goDown = true;
                down--;
                current++;
            }
            while(up < N && pos[up] <= current_up && goneUp){
                goUp = true;
                up++;
                current++;
            }
            if (!goDown){
                goneDown = false;
            }
            if(!goUp){
                goneUp = false;
            }
            radius++;
        }
        ans = max(ans, current);
    }
    cout << ans << endl;
    
}