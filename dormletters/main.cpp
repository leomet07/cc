#include <iostream>
 
using namespace std;

int getInt(){
    int i;
    cin >> i;
    return i;
}

long long getLongLong(){
    long long l;
    cin >> l;
    return l;
}


long long opti_index(long long* a, long long len, long long v){
	long long l = 0;
    long long r = len - 1;
    long long opti_index = -1;

    while (l <= r  ){
        long long m = l + ((r - l) / 2);
        if (a[m] == v ){
            opti_index = m - 1;
            break;
        }
        // if x greater, ignore left (lower) half
        if (a[m] < v){
            l = m + 1;
        } else{ // if x is smaller ignore right (greater) half
            r = m - 1;
        }
    }

	if (opti_index == -1){ // if not found, use the (lower) last searched value
		opti_index = l - 1;
	}

	return opti_index;
}


int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

    int dorm_num = getInt();
    int test_num = getInt();

    long long dormRoomInfo[dorm_num];

    int subtracts_len = dorm_num + 1;
    long long subtracts[subtracts_len];
    subtracts[0] = 0;
    for (int i = 0; i < dorm_num; i++){
        dormRoomInfo[i] = getLongLong();
        subtracts[i + 1] = dormRoomInfo[i] + subtracts[i]; 
    }
    
    for (int i = 0; i < test_num; i++){
        long long l = getLongLong();
        long long opti = opti_index(subtracts, subtracts_len, l) ;
        long long dorm = opti + 1;
        long long room = l - subtracts[opti];
        cout << dorm << " " << room << endl;

    }

    return 0;

}
