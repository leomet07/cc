#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
	ifstream cin("ac.in");
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll n;
	cin >> n;

	cout << "Cowditioning: " << n << endl;

	ll goal[n];
	for (ll i =0; i < n;i++){
		cin >> goal[i];
		cout << "i: " << i << " Goal: " << goal[i] << endl;
	}

	vector<ll> alldists;
	ll total_moves = 0;

	ll current[n];
	ll alldistascomputed[n];
	for (ll i =0; i < n;i++){
		cin >> current[i];
		ll dista = current[i] - goal[i];
		alldistascomputed[i] = dista;
	}
	for (ll i =0; i < n;i++){
		ll currentv = current[i];

		// distance from optimal
		ll dista = alldistascomputed[i];
		
		int current_sign = 0;
		if (dista > 0){
			current_sign = 1;
		} else if(dista < 0){
			current_sign = -1;
		}

		int future_sign = current_sign;

		if (i != n-1 ){
			ll future_dista = alldistascomputed[i+ 1];
			future_sign = 0;
			if (future_dista > 0){
				future_sign = 1;
			} else if(future_dista < 0){
				future_sign = -1;
			}
		}
		

		// ll distance = 
		bool diffofthefuture = (i != n-1 && current_sign != future_sign);
		bool do_switch = (i != 0 && dista==0) || diffofthefuture || i == n-1;
		cout << "i: " << i << " Current: " << currentv << " Distance: "<< dista << " Do switch?: " << int(do_switch) << " Diff of the future: " << int(diffofthefuture) << endl;

		if (dista != 0){ 
			alldists.push_back(dista);
		}
		if (do_switch){
			cout << "Inside the switch" << endl;
			sort( alldists.begin(), alldists.end() );
			alldists.erase( unique( alldists.begin(), alldists.end() ), alldists.end() );
			// cout << "HIT: " << endl;
			ll moves = 0;
			ll s = 0;
			for (auto elem : alldists){
				ll e = elem * -1;
				std::cout << "Distance: " <<  e << endl;
				moves += abs(s - e);
				cout << "e - s : " << e + s << " Moves: " << moves << endl;
				s += abs(e);
			}

			total_moves += moves;

			cout << "Loop Final Moves: " << moves << endl;
			alldists.clear();
		}

	}


	cout << "Total moves: " << total_moves << endl;
	// cout<< total_moves << endl;
	

	return 0;
}