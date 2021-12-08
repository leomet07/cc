#include <iostream>
using namespace std;

#define ll long long  
#include <bits/stdc++.h>


void genPreLinear(const ll* a, ll n,  ll* pre ){
    pre[0] = 0;

    for (int i = 1; i < n + 1; i++){
      pre[i] = pre[i -1] + a[i-1];
    }
}

bool isGood(ll *a, ll l, ll r, ll* pre){
    ll p = pre[r] - pre[l];
    return p == r - l;
}

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

        ll digits[len];
        string in;
        cin >> in; 

        for (int i = 0; i < in.length(); i++){
            digits[i] = in.at(i) - '0';
        }
        ll appears[9] = { };
        
        for (int s = 0; s < len; s++){
            appears[digits[s]] = appears[digits[s]] + 1;
            cout << digits[s] << " ";
        }
        cout << endl;

        cout << "Appears: " << endl;
        for (int i = 0; i < 10; i++){
            cout << i << ": " << appears[i] << " " << endl;
        }

        ll pre[len + 1];
        genPreLinear(digits, len, pre);

        // cout << "Pre: " << endl;
        // for (int i = 0; i < len + 1; i++){
        //     cout << pre[i] << " ";
        // }
        // cout << endl;

        bool ig = isGood(digits, 0, len, pre);
        cout << "IsGood: " << ig << endl;


        
    }
    return 0;


}
