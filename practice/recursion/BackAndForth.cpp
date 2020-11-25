#include <iostream>
#include <vector>
using namespace std;
 
int possible_answers[2000];
 
void friday(int b1milk, vector<int> B1, vector<int> B2) {
    for (int i = 0; i < B2.size(); i++) {
        int x = B2[i];
        possible_answers[b1milk + x] = 1; 
    }
}
 
void thursday(int b1milk, vector<int> B1, vector<int> B2) {
    for (int i = 0; i < B1.size(); i++) {
        int x = B1[i];
        vector<int> new_B2 = B2; new_B2.push_back(x);
        vector<int> new_B1 = B1; new_B1.erase(new_B1.begin() + i);
        friday(b1milk - x, new_B1, new_B2);
    }
}
 
void wednesday(int b1milk, vector<int> B1, vector<int> B2) {
    for (int i = 0; i < B2.size(); i++) {
        int x = B2[i];
        vector<int> new_B1 = B1; new_B1.push_back(x);
        vector<int> new_B2 = B2; new_B2.erase(new_B2.begin() + i);
        thursday(b1milk + x, new_B1, new_B2);
    }
}
 
void tuesday(int b1milk, vector<int> B1, vector<int> B2) {
    for (int i = 0; i < B1.size(); i++) {
        int x = B1[i];
        vector<int> new_B2 = B2; new_B2.push_back(x);
        vector<int> new_B1 = B1; new_B1.erase(new_B1.begin() + i);
        wednesday(b1milk - x, new_B1, new_B2);
    }
}
 
int main(void) {
    int n, answer = 0;
    vector<int> B1, B2;

    freopen("backforth.in", "r", stdin);
    freopen("backforth.out", "w", stdout);

    for(int i = 0; i < 10; i++) { 
        cin >> n; 
        B1.push_back(n); 
    }

    for(int i = 0; i < 10; i++) {
        cin >> n; 
        B2.push_back(n); 
    }
    
    tuesday(1000, B1, B2);
    
    for (int i = 0; i < 2000; i++) {
        answer += possible_answers[i];
    }

    cout << answer << endl;
    return 0;
}