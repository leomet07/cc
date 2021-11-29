#include <iostream>
using namespace std;

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
        // If x greater, ignore left half
        if (a[m] < v){
            l = m + 1;
        } else{ // if x is smaller ignore right half
            r = m - 1;
        }
    }

	if (opti_index == -1){ // if not found, use the (lower) last searched value
		opti_index = l - 1;
	}

	return opti_index;
}

int main() {
	long long test[] = {0 , 1, 2, 3 ,4 , 5 , 7, 10, 11, 67, 778, 9000};

	size_t len = sizeof(test) / sizeof(long long);
	
	int v = 68;

	long long r = opti_index(test, len, v);
    
	cout << "R: " << r << endl;
	cout << "lower: " << test[r] << endl;

    return 0;

}
