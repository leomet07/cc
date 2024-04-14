#include <bits/stdc++.h>

using namespace std;
using ll = long long;


void uwu(){
    // Reminder about how to use vectors
    vector<ll> x = {2, 3, 5};

    for (int i = 0; i< x.size(); i++){
        cout << x.at(i) << endl;
    }
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);
    ll n;
    cin>>n;
    ll r;
    cin>>r;
    ll q;
    cin>>q;

    cout <<"NRQ: " << n << " " << r << " "<< q << endl;

    vector<vector<ll>> moves ; 
    
    while(r--){
        ll s; cin >> s;
        ll e; cin >> e;
        vector<ll> move = {s, e};
        moves.push_back(move);
    }

    // Print vector
    for (int i = 0; i< moves.size(); i++){
        vector<ll> move = moves.at(i);
        cout << move.at(0) << ", " << move.at(1) << endl;
    }

    

    while(q--){
        ll x; cin >> x;
        for (int i = moves.size() - 1; i >= 0; i--){
            vector<ll> move = moves.at(i);
            ll s = move.at(0);
            ll e = move.at(1);
            if (x < s || x > e){
                continue;
            } else {
                ll diff = x - s;
                x = e - diff;
            }
        }
        cout << x << endl;
    }
}
