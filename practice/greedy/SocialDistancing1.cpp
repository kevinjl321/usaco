#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
 
int find_largest_interior_gap(string s, int &gap_start) {
    int biggest_gap = 0, current_start = -1, N = s.length();
    for(int i = 0; i < N; i++){
        if (s[i] == '1') {
            if (current_start != -1 && i - current_start > biggest_gap) {
                biggest_gap = i - current_start;
                gap_start = current_start;
            }
            current_start = i;
        }
    }
    return biggest_gap;
}
 
int find_smallest_interior_gap(string s) {
    int smallest_gap = 1000000000, current_start = -1, N = s.length();
    for (int i = 0; i < N; i++){ 
        if (s[i] == '1') {
            if (current_start != -1 && i - current_start < smallest_gap){
                smallest_gap = i - current_start;
            }
            current_start = i;
        }
    }
    return smallest_gap;
}
 
int try_cow_in_largest_gap(string s){
    int gap_start, largest_gap = find_largest_interior_gap(s, gap_start);
    if (largest_gap >= 2) {
        s[gap_start + largest_gap / 2] = '1';
        return find_smallest_interior_gap(s);
    } 
    return -1;
}
 
int main(){
    freopen("socdist1.in", "r", stdin);
    freopen("socdist1.out", "w", stdout);
    
    int N;
    string s, temp_s;
    cin >> N >> s;
    int ans = 0;
    
    int gap_start, largest_gap = find_largest_interior_gap(s, gap_start);
    if (largest_gap >= 3) {
        temp_s = s;
        temp_s[gap_start + largest_gap / 3] = '1';
        temp_s[gap_start + largest_gap * 2 / 3] = '1';
        ans = max(ans, find_smallest_interior_gap(temp_s));
    }
    
    if (s[0] == '0' && s[N-1] == '0') {
        temp_s = s; temp_s[0] = temp_s[N-1] = '1';
        ans = max(ans, find_smallest_interior_gap(temp_s));        
    }

    if (s[0] == '0') {
        temp_s = s; temp_s[0] = '1';
        ans = max(ans, try_cow_in_largest_gap(temp_s));
    }
    
    if (s[N-1] == '0') {
        temp_s = s; temp_s[N-1] = '1';
        ans = max(ans, try_cow_in_largest_gap(temp_s));
    }
    
    if (largest_gap >= 2) {
        temp_s = s; temp_s[gap_start + largest_gap / 2] = '1';
        ans = max(ans, try_cow_in_largest_gap(temp_s));
    }
    
    cout << ans << endl;
    return 0;
}