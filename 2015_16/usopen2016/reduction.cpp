#include<iostream>
#include<algorithm>
using namespace std;

int x1, x2, x3, x4, y_1, y2, y3, y4;

void update(int x, int y){
    if(x < x1){
		x2 = x1;
		x1 = x;
	}
	else if(x < x2){
		x2 = x;
	}
	if(x > x4){
		x3 = x4;
		x4 = x;
	}
	else if(x > x3){
		x3 = x;
	}
	if(y < y_1){
		y2 = y_1;
		y_1 = y;
	}
	else if(y < y2){
		y2 = y;
	}
	if(y > y4){
		y3 = y4;
		y4 = y;
	}
	else if(y > y3){
		y3 = y;
	}
}

int main(){
    freopen("reduce.in", "r", stdin);
    freopen("reduce.out", "w", stdout);

    int n;
    cin >> n;

    x1 = 1000000;
    x2 = 1000000;
    x3 = 0;
    x4 = 0;
    y_1 = 1000000;
    y2 = 1000000;
    y3 = 0;
    y4 = 0;

    int x[50001];
    int y[50001];

    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
        update(x[i], y[i]);
    }

    int ans = (x4 - x1) * (y4 - y_1);
    for(int i = 0; i < n; i++){
        int xMin = x1;
        if(x[i] == xMin){
            xMin = x2;
        }
        int xMax = x4;
		if(x[i] == xMax) {
			xMax = x3;
		}
		int yMin = y_1;
		if(y[i] == yMin) {
			yMin = y2;
		}
		int yMax = y4;
		if(y[i] == yMax) {
			yMax = y3;
		}
		ans = min(ans, (xMax - xMin) * (yMax - yMin));
    }

    cout << ans << endl;
    return 0;
}

