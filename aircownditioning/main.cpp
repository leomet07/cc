#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
	// ifstream cin("ac.in");
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll n;
	cin >> n;

	// cout << "Cowditioning: " << n << endl;

	ll goal[n];
	for (ll i =0; i < n;i++){
		cin >> goal[i];
		// cout << "i: " << i << " Goal: " << goal[i] << endl;
	}
	ll current[n];

	set<ll> alldists;
	ll total_moves = 0;
	for (ll i =0; i < n;i++){
		cin >> current[i];

		// distance from optimal
		ll dista = current[i] - goal[i];

		
		// ll distance = 
		// cout << "i: " << i << " Current: " << current[i] << " Distance: "<< dista << "Do hit?: " << int(i == n-1) << endl;

		if (dista != 0){ 
			alldists.insert(dista);
		}
		if (dista==0 || i == n-1){
			// cout << "HIT: " << endl;
			ll moves = 0;
			ll s = 0;
			for (auto elem : alldists)
			{
				ll e = elem * -1;
				// std::cout << "Distance: " <<  e << endl;
				moves += abs(s - e);
				// cout << "e - s : " << e + s << " Moves: " << moves << endl;
				s += abs(e);
			}

			total_moves += moves;

			// cout << "Loop Final Moves: " << moves << endl;
			alldists.clear();
		}
	}


	// cout << "Total moves: " << total_moves << endl;
	cout<< total_moves << endl;
	

	return 0;
}