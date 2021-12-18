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

	vector<ll> alldists;
	ll total_moves = 0;
	for (ll i =0; i < n;i++){
		ll currentv;
		cin >> currentv;

		// distance from optimal
		ll dista = currentv - goal[i];

		
		// ll distance = 
		// cout << "i: " << i << " Current: " << currentv << " Distance: "<< dista << "Do hit?: " << int(i == n-1) << endl;

		if (dista != 0){ 
			alldists.push_back(dista);
		}
		if (dista==0 || i == n-1){
			sort( alldists.begin(), alldists.end() );
			alldists.erase( unique( alldists.begin(), alldists.end() ), alldists.end() );
			// cout << "HIT: " << endl;
			ll moves = 0;
			ll s = 0;
			for (auto elem : alldists){
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