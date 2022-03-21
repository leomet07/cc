#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    
	ll n; cin >> n; // N number of cows
	ll m; cin >> m; // M queries
	cout << "N: " << n << " M: " << m << endl;
	// vector<vector<ll>> adjs;
	// for (ll i = 0 ; i < n; i++){
	// 	adjs.push_back(vector<ll> {});
	// }
	vector<ll> adjs[n];

	for (ll i = 0; i < n - 1; i++){
		ll s; cin >> s;
		ll e; cin >> e;

		adjs[s - 1].push_back(e - 1 );
		adjs[e - 1].push_back(s - 1);
	}

	for (ll i = 0; i < n; i++){
		vector<ll> current_adj = adjs[i];
		
		cout << "[";
		for (ll j = 0; j < current_adj.size(); j++){
			cout << " " << current_adj[j] << ",";
		}

		cout << "]" << endl;
	}

	// string cows
    cout << "Milk Visits" << endl;    
	char farm_types[n];
	cin.getline(farm_types, n);

	


	
    return 0;

}
