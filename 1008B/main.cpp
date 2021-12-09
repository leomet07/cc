#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main() {
    ifstream cin("read.in");
    // ofstream cout("o.out");
    ios::sync_with_stdio(0);
	cin.tie(0);
    
    ll t; 
    cin >> t;

    vector<pair<ll, ll>> rects;
    for (ll i = 0; i < t; i++){
        ll w, h;
        cin >> w >> h;
        rects.push_back(pair<ll, ll>(w, h));
    }

    // read the receievd rects
    for (ll i = 0; i < rects.size(); i++ ){
        pair<ll, ll> r = rects[i];
        cout << "Width: "<< r.first << " Height: " << r.second << endl;
    }
    return 0;

}
