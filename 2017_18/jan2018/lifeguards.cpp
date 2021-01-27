#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);

    int start[101] = {0};
    int end1[101] = {0};
    int shift[1000] = {0};

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int n, n1;
        cin >> n >> n1;
        start[i] = n;
        end1[i] = n1;
    }

    for(int i = 0; i < n; i++){
        for(int j = start[i]; j < end1[i]; j++){
            shift[j]++;
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = start[i]; j < end1[i]; j++){
            shift[j]--;
        }
        int covered = 0;
        for(int j = 0; j < 1000; j++){
            if(shift[j] > 0){
                covered++;
            }
        }
        ans = max(ans, covered);
        for(int j = start[i]; j < end1[i]; j++){
            shift[j]++;
        }
    }

    cout << ans << endl;
    return 0;
}