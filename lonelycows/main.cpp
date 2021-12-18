#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	ifstream cin("l.in");

	ll n;
	cin >> n;

	string f;
	cin >> f;

	char cows[n];
	for (ll i = 0; i < f.length(); i++){
		char c = f.at(i);
		cows[i] = c;
	}

	vector<pair<ll, ll>> prefix_of_tos;
	prefix_of_tos.push_back(pair<ll, ll>(0, 0));
	ll g_master = 0;
	ll h_master = 0;
	for (ll i = 0; i < n; i++){
		char t = cows[i];
		if(t == 'H'){
			h_master++;
		}else if (t == 'G'){
			g_master++;
		}
		prefix_of_tos.push_back(pair<ll, ll>(g_master, h_master));
		cout << "in cows t: " << t << endl;
	}

	for (ll d = 0; d < prefix_of_tos.size(); d++){
		pair<ll, ll> currentpair = prefix_of_tos[d];
		ll g = currentpair.first;
		ll h = currentpair.second;

		cout << "Up to and including index d: " << d -1 << " G: " << g << " H: " << h << endl;
	}

	

	ll lonlies = 0;
	// for (ll seqlen = 3; seqlen < n + 1; seqlen++ ){
	for (ll seqlen = 3; seqlen < n + 1; seqlen++ ){
		
		cout << "Possible seqlen: " << seqlen << endl;
		// count cows
		
		for (ll left = 0; left < n - (seqlen -1); left++){
			ll h = 0;
			ll g = 0;
			ll right = left + seqlen;
			cout << "Left: " << left << " Right: " << right << endl;

			ll guess_g_right = prefix_of_tos[right ].first;
			ll guess_h_right = prefix_of_tos[right].second;
			ll guess_g_left = prefix_of_tos[left ].first;
			ll guess_h_left = prefix_of_tos[left].second;
			cout << "Guess g right " << guess_g_right << endl;
			cout << "Guess h right " << guess_h_right << endl;
			cout << "Guess g left " << guess_g_left << endl;
			cout << "Guess h left " << guess_h_left << endl;

			ll guess_g = prefix_of_tos[right ].first - prefix_of_tos[left ].first;
			ll guess_h =  prefix_of_tos[right].second - prefix_of_tos[left].second;
			cout << "Guess full g: " << guess_g << endl;
			cout << "Guess full h: " << guess_h << endl;
			// count cows 
			for (ll i = left; i < right; i++){
				char t = cows[i];
				cout << "Cow in looper: " << t << endl;
				if(t == 'H'){
					h++;
				}else if (t == 'G'){
					g++;
				}
			}

			cout << "G cows counted: " << g << " H cows counted: " << h << endl;

			if (g == 1 || h == 1){
				cout << "Lonley possbility found, so incrementing lonlies" << endl;
				lonlies++;
			} else{
				cout << "Not a lonley" << endl;
			}
		}
	}

	cout << "Lonlies: " << lonlies << endl;

	return 0;
}