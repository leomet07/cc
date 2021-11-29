#include <iostream>
#include <set>
#include <iterator>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
 

int getInt(){
    int i;
    cin >> i;
    return i;
}

int main() {
    ifstream cin("angry.in");
    ofstream cout("angry.out");

    ios::sync_with_stdio(0);
	cin.tie(0);

    int ins = getInt();
    vector<int> cows(ins);

    for (int i = 0; i < ins; i++){
        int a = getInt();
        cows[i] = a;
    }
    sort(cows.begin(), cows.end());
    // cout << "\n" << endl;
    int m = 0;
    for (int i = 0; i < ins; i++){
        int l = cows[i];
        // cout << "i:" <<  i <<  " L: " << l << endl;
        int r = 1;
        int k = 1;  
        int c = i + 1;
        // try to leap forward
        while (c < ins){
            // cout << "C: " << c << endl;
            int v = cows[c];
            // cout << "V: " << v << " " << v - l << " " << r << endl;
            if (v - l <= r){
                // cout << "Yes: " << endl;
                k++;
                
                if (v - l == r){
                    // cout<< "Exact" << endl;
                    r++;
                }
            }
            c++;
            
            l = v;
        }

        int s = i -1;
        r = 1;
        l = cows[i];
        while (s >= 0){
            // cout << "C: " << c << endl;
            int v = cows[s];
            // cout << "S: " << s << " " << l - v << endl;
            if (l -v <= r){
                // cout << "Yes: " << endl;
                k++;
                if (l -v == r){ // if exact, add one more dist
                    r++;
                }
            }
            s--;

            l = v;
            
        }

        if (k > m){
            m = k;
        }
        // cout << "K: " << k << endl;

    }

    cout << m << endl;
    
    return 0;

}
