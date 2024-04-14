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

    // cout <<"NRQ: " << n << " " << r << " "<< q << endl;
    ll moves[r][2];  // OPTIMIZE TO USE ARRAY
    
    int insert = 0;
    ll rloop = r;
    while(rloop--){
        ll s; cin >> s;
        ll e; cin >> e;
        moves[insert][0] = s;
        moves[insert][1] = e;
        insert++;
    }

    

    while(q--){
        ll x; cin >> x;
        for (int i = r - 1; i >= 0; i--){
            ll s = moves[i][0];
            ll e = moves[i][1];
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
