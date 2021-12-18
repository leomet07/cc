#include <iostream>
using namespace std;

#define ll long long
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

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
		prefix_of_tos[i+1].first = g_master;
		prefix_of_tos[i+1].second = h_master;
	}

	ll lonlies = 0;
	for (ll seqlen = 3; seqlen < n + 1; seqlen++ ){ 
		for (ll left = 0; left < n - (seqlen -1); left++){
			ll g = prefix_of_tos[left + seqlen].first - prefix_of_tos[left ].first;
			ll h =  prefix_of_tos[left + seqlen].second - prefix_of_tos[left].second;
			if (g == 1 || h == 1){
				lonlies++;
			} 
		}
	}

	cout << lonlies << endl;

	return 0;
}