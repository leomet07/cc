#include <iostream>
 
using namespace std;
 
int main() {
    string i;
    cin >> i;
    
    long long w = stol(i);
    
    if (w % 2 == 0 && w != 2){
        cout << "YES" << endl;
        
    } else{
        cout << "NO" <<endl;
    }
    
    return 0;

}
