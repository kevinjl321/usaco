#include<iostream>
using namespace std;

int main(){
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);

    int N, B;
    cin >> N >> B;

    int x[100];
    int y[100];
    for(int i = 0; i < N; i++){
        cin >> x[i] >> y[i];
    }

    int ans = N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int xDiv = x[i] + 1;
			int yDiv = y[j] + 1;
			int upperLeft = 0;
            int upperRight = 0;
            int lowerRight = 0;
            int lowerLeft = 0;
			for(int k = 0; k < N; k++) {
				if(x[k] < xDiv && y[k] < yDiv) {
					lowerLeft++;
				}
				if(x[k] < xDiv && y[k] > yDiv) {
					upperLeft++;
				}					
                if(x[k] > xDiv && y[k] < yDiv) {
					lowerRight++;
				}
				if(x[k] > xDiv && y[k] > yDiv) {
					upperRight++;
				}
			}				
            int worstRegion = 0;
			if(upperLeft > worstRegion) {
				worstRegion = upperLeft;
			}
			if(upperRight > worstRegion) {
                worstRegion = upperRight;
			}
			if(lowerLeft > worstRegion) {
				worstRegion = lowerLeft;
			}
			if(lowerRight > worstRegion) {
				worstRegion = lowerRight;
            }
			if(worstRegion < ans) {
				ans = worstRegion;
			}
        }
    }

    cout << ans << endl;
    return 0;
}
