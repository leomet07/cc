#include <iostream>
using namespace std;

#define ll long long  
#include <bits/stdc++.h>

int main() {
    ifstream cin("cf.in");
    // ofstream cout("angry.out");
    ios::sync_with_stdio(0);
	cin.tie(0);

    ll n;
    cin >> n;
    cout << "Looping: " << n << endl;
    for (ll run = 0; run < n; run++){
        ll len;
        cin >> len;

        vector<ll> digits;
        string in;
        cin >> in; 

        for (int i = 0; i < in.length(); i++){
            digits.push_back(in.at(i) - '0');
        }

        for (int s = 0; s < digits.size(); s++){
            cout << digits[s] << " ";
        }

        cout << endl;
    }
    return 0;


}
