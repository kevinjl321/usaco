#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define ll long long
#define ld long double

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int a[100];
    for (int i = 0; i < 2*n; ++i) cin >> a[i];
    
    sort(a, a + 2 * n);

    ll ans = 1e12;
    for (int i = 0; i < 2*n-1; ++i)
    {
        for (int j = i+1; j < 2*n; ++j)
        {
            vector <int> b(0);
            ll in = 0;
            for (int k = 0; k < 2*n; ++k) if (k != i && k != j) b.emplace_back(a[k]);
            for (int k = 0; k < 2*n-2; k += 2) in += (b[k+1]-b[k]);
            ans = min(ans, in);
        }
    }
    cout << ans << endl;
}