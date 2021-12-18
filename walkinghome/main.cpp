#include <iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
	ifstream cin("w.in");
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll cases;
	cin >> cases;

	for (ll casenum = 0 ; casenum < cases; casenum++){
		ll n;
		cin >> n;

		ll t;
		cin >> t;

		cout << "Walk home: " << n << " T: " << t << endl;

		char grid[n][n];

		for (ll r = 0; r < n;r++){
			for (ll c = 0; c < n; c++){
				cin >> grid[r][c];
			}
		}

		for (ll r = 0; r < n; r++){
			for (ll c = 0; c < n; c++){
				cout << grid[r][c];
			}
			cout << endl;
		}

		ll posr = 0;
		ll posc = 0;

		string path = "";


		
	}




	return 0;
}