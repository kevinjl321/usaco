#include<iostream>
#include<set>
using namespace std;

int main(){
    int n;
    set<int> s;
    cin >> n;

    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        s.insert(k);
    }

    cout << s.size() << endl;
    return 0;
}