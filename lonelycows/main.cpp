#include <iostream>
using namespace std;

#define ll long long
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	// ifstream cin("l.in");

	ll n;
	cin >> n;

	string f;
	cin >> f;

	char cows[n];
	pair<ll, ll> prefix_of_tos[n+1];
	prefix_of_tos[0] = pair<ll, ll>(0, 0);
	ll g_master = 0;
	ll h_master = 0;
	for (ll i = 0; i < n; i++){
		cows[i] = f.at(i);
		if(f.at(i) == 'H'){
			h_master++;
		}else if (f.at(i) == 'G'){
			g_master++;
		}
		prefix_of_tos[i+1] = pair<ll, ll>(g_master, h_master);
	}

	
	// for (ll i = 0; i < n; i++){
	// 	char t = cows[i];
		
	// 	// cout << "in cows t: " << t << endl;
	// }

	// for (ll d = 0; d < prefix_of_tos.size(); d++){
	// 	pair<ll, ll> currentpair = prefix_of_tos[d];
	// 	ll g = currentpair.first;
	// 	ll h = currentpair.second;

	// 	// cout << "Up to and including index d: " << d -1 << " G: " << g << " H: " << h << endl;
	// }

	

	ll lonlies = 0;
	// for (ll seqlen = 3; seqlen < n + 1; seqlen++ ){
	for (ll seqlen = 3; seqlen < n + 1; seqlen++ ){
		
		// cout << "Possible seqlen: " << seqlen << endl;
		// count cows
		
		for (ll left = 0; left < n - (seqlen -1); left++){
			
			// cout << "Left: " << left << " Right: " << right << endl;

			ll g = prefix_of_tos[left + seqlen].first - prefix_of_tos[left ].first;
			ll h =  prefix_of_tos[left + seqlen].second - prefix_of_tos[left].second;
			// cout << "Guess full g: " << guess_g << endl;
			// cout << "Guess full h: " << guess_h << endl;
			

			// cout << "G cows counted: " << g << " H cows counted: " << h << endl;

			if (g == 1 || h == 1){
				// cout << "Lonley possbility found, so incrementing lonlies" << endl;
				lonlies++;
			} 
		}
	}

	// cout << "Lonlies: " << lonlies << endl;
	cout << lonlies << endl;

	return 0;
}