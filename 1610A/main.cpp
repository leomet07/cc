#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

	// ifstream cin("mh.in");
    
    ll t; cin >> t;

	for (ll i = 0; i < t; i++){
		ll r, c;
        cin >> r >> c;
        if (r == 1 && c == 1){
            cout << "0" << endl;
        }
        else if ( min(r, c) == 1){
            cout << "1" << endl;
        }
        else {
			cout << "2" << endl;
		}

	}   
    return 0;

}
