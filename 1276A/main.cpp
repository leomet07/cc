#include <iostream>
#include <iterator>
#include <set>
#include <vector>

using namespace std;
 
int getInt(){
    int i;
    cin >> i;
    return i; 
}

long long getLongLong(){
    long long l; // always have a 64bit num
    cin >> l;
    return l;
}

string getString(){
    string s;
    cin >> s;
    return s;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0); // unsync stdin and stdout, is fine for comp bc no input prompts are printed

    long long ins = getLongLong();
    
    for (long long i = 0; i < ins; i++){
        // run
        string s = getString();


        // empty set container
        set<int, greater<int> > rem;

        // account for edge cases
        size_t last_twone = s.find("twone");
        vector<size_t> tflags;

        // account for twone
        while (last_twone != string::npos){
            tflags.push_back(last_twone); // flag it
            rem.insert(last_twone + 2);  // to remove the o in twone
            s.replace(last_twone, 4,"jjjj"); // so the two inside twone is not found later on

            last_twone = s.find("twone", last_twone + 4); // 4 bc twone is 5 chars long and u want to start with latest
        }

        size_t last_one = s.find("one");
        size_t last_two = s.find("two");
        // find all occurences
        while (last_one != string::npos){ 
            rem.insert(last_one + 1); // to remove the n in one
            last_one = s.find("one", last_one + 2); // 2 bc one is 3 chars long and u want to start with latest
        }
        while (last_two != string::npos){
            bool isAccounted = false;
            for (const auto &item : tflags) {
                if (item == last_two) {
                    isAccounted = true;
                    break;
                }
            }
            if (!isAccounted){
                rem.insert(last_two + 1); // to remove the w in two
            } // else do nothing bc already accounted for

            last_two = s.find("two", last_two + 2); // 2 bc two is 3 chars long and u want to start with latest
        }
        

        cout << rem.size() << endl;

        set<int >::iterator it ;
        for (it = rem.begin() ; it != rem.end() ; it++ ) {
            cout << *it + 1 <<" "; // the +1 is bc this problem has the index starting at 1
        }

        cout << endl;

    }
    return 0;

}
