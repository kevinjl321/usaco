#include <iostream>
using namespace std;
 
int N, A[1000001];

int find_smallest_01_gap(){
    int smallest_gap = 2000000, current_start = -1;
    for (int i = 0; i <= 1000000; i++){
        if (A[i] != 0) {
            if (current_start != -1 && A[current_start] != A[i] && i - current_start < smallest_gap){
                smallest_gap = i - current_start;
            }
            current_start = i;
        }
    }
    return smallest_gap;
}
 
int num_sick_clusters(){
    int last_state = 0, answer = 0;
    for (int i = 0; i <= 1000000; i++){
        if (A[i] != 0) {
            if (A[i] != last_state && A[i] == 1){
                answer++;
            }
            last_state = A[i];
        }
    }
    return answer;
}
 
int num_sick_gaps(int r){
    int answer = 0, current_start = 0;
    for (int i = 0; i <= 1000000; i++){
        if (A[i] != 0) {
            if (current_start!=0 && A[current_start]==1 && A[i]==1 && i-current_start>=r){
                answer++;
            }
            current_start = i;
        }
    }
    return answer;
}
 
int main(){
    freopen("socdist2.in", "r", stdin);
    freopen("socdist2.out", "w", stdout);
    
    int x, s;
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> x >> s;
        if (s==1) { A[x] = 1; }
        if (s==0) { A[x] = -1; }
    }
    int r = find_smallest_01_gap();

    cout << num_sick_clusters() + num_sick_gaps(r) << endl;
    return 0;
}