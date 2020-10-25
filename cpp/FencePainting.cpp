#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    cout << min(max(b, d) - min(a, c), (d - c) + (b - a)) << endl;
    return 0;
}