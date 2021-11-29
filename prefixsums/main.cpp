#include <iostream>

using namespace std;

void genPreLinear(const long long* a, int n,  long long* pre ){
    pre[0] = 0;

    for (int i = 1; i < n + 1; i++){
      pre[i] = pre[i -1] + a[i-1];
    }
}


int main() {
    
    int n = 0;
    long long q = 0;
    cin >> n;
    cin >> q;
    
    long long array[n];

    for (int i = 0; i < n; i++){
        cin  >> array[i];
    }

    long long pre[n + 1];
    genPreLinear(array, n,  pre);

    for (long long j = 0; j < q; j++){
        long long start = 0;
        long long end = 0;

        cin >> start;
        cin >> end;

        
        long long sum = pre[end] - pre[start -1];
        cout << sum << endl;

    }


	// cout << "Prefix sums" << endl;
    return 0;
}


