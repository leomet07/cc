#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool isStable(vector<ll> s, ll x){
    for (int i = 1; i < s.size(); i++){
        if (s[i] - s[i - 1] > x){
            return false;
        }
    }
    return true;
}

void printV(vector<ll> v){
    cout << "Printing array: " << endl;
    for (auto i : v) {
        cout <<  i << endl;
    }
    cout << "End" << endl;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

    ll n, ogk , x;
    cin >> n >> ogk >> x;
    ll k = ogk;
    vector<ll> levels;
    for (ll i = 0; i < n; i++){
        ll l;
        cin >> l;
        levels.push_back(l);
    }

    sort(levels.begin(), levels.end());

    printV(levels);

    bool run = !isStable(levels, x);

    ll b = 1;
    if (run){

        for (int i = 1; i < levels.size(); i++){
            ll dist = (levels[i] - levels[i - 1]);
            
            if ( dist > x){
                ll div = (dist / x);
                // if (dist % x == 0){ // can be bridged with one
                //     cout << "Can be bridged with one" << endl;
                //     div--;
                // }
                cout << "Distance: " << dist << " " << dist % x << " K: " << k << " X: " << x <<  endl;
                cout << "Greater distance: , subber div: "  << div  << endl;
                if (k == 0){
                    b++;
                } else{
                    if (dist / x > ogk  ){ // no worth it, so skip
                        cout << "Not worth it, so skip" << endl;
                        b++;
                    } else{
                        cout << " Worth adding... " << endl;
                        cout << " K before: " << k << endl;
                        k -= (dist - 1) / x;
                        cout << " devil " << (dist -1 )/ x << endl;
                        if (dist - 1% x == 0){ // could be bridged with one
                            cout << "Can be bridged with one" << endl;
                            k++;
                        }
                        cout << " K after: " << k << endl;
                        // if (dist % x >= k){
                        if (k < 0){
                            // cout<< "Fail sad" << endl;
                            
                            // fail, so we must break
                            b ++;
                        }
                        else{
                            cout << "Can be bridged" << endl;
                        }
                    }
                }
                
                
            } 

            cout << "B: " << b << endl;
        }
    } 
    // else{
    //     cout << "Not runnning? " << endl;
    // }

    cout << b << endl;
    return 0;

}
