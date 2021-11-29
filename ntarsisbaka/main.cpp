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
 
        
        
        size_t last_ntarsisus = s.find("ntarsisus");
        vector<size_t> nflags;

        // account for ntarsisus
        while (last_ntarsisus != string::npos){
            nflags.push_back(last_ntarsisus); // flag it
            rem.insert(last_ntarsisus + 6);  // to remove the second s in ntarsisus
            s.replace(last_ntarsisus, 8,"jjjjjjjj"); // so the sus inside ntarsisu is not found later on

            last_ntarsisus = s.find("ntarsisus", last_ntarsisus + 8); // 8 bc natrsisus is 9 chars long and u want to start with latest
        }

        size_t last_susus = s.find("susus");
        vector<size_t> sflags;

        // account for susus
        while (last_susus != string::npos){
            sflags.push_back(last_susus); // flag it
            rem.insert(last_susus + 2);  // to remove the second s in ntarsisus
            s.replace(last_susus, 4,"jjjj"); // so the sus inside ntarsisu is not found later on

            last_susus = s.find("susus", last_susus + 4); // 4 bc natrsisus is 5 chars long and u want to start with latest
        }


        

        size_t last_sus = s.find("sus");
        size_t last_ntarsis = s.find("ntarsis");
        // find all occurences
        while (last_sus != string::npos){
            // check over the flags
            bool isAccounted = false;
            for (const auto &item : sflags) {
                if (item == last_sus) {
                    isAccounted = true;
                    break;
                }
            }
            if (!isAccounted){
                rem.insert(last_sus + 1); // to remove the u in sus
            } // else do nothing bc already accounted for
            last_sus = s.find("sus", last_sus + 2); // 2 bc sus is 3 chars long and u want to start with latest
        }
        while (last_ntarsis != string::npos){

            // check over the flags
            bool isAccounted = false;
            for (const auto &item : nflags) {
                if (item == last_ntarsis) {
                    isAccounted = true;
                    break;
                }
            }

            if (!isAccounted){
                rem.insert(last_ntarsis + 3);  // to remove the r in ntarsis

            } // else dont do anything bc it is already handled
            last_ntarsis = s.find("ntarsis", last_ntarsis + 6); // 6 bc natrsis is 7 chars long and u want to start with latest
        }
        

        cout << rem.size() << endl;

        set<int >::iterator it ;
        for (it = rem.begin() ; it != rem.end() ; it++ ) {
            cout << *it<<" ";
        }

        cout << endl;


        // DEBUG
        // cout << "\n\nDebug:::::: " << endl;


        // cout << "S: " << s << endl;

        // set<int >::iterator d ;
        // for (d = rem.begin() ; d != rem.end() ; d++ ) {
        //     cout << *d<<" ";
        //     s.erase(*d , 1);
            
        // }
        // cout << endl;

        // cout << "S new: " << s << endl;

        // // find any sus or ntarsis
        // size_t us = s.find("sus");
        // size_t is = s.find("ntarsis");

        // if (us != string::npos){
        //     cout << "sus found: " << us << endl;
        // }
        // if (is != string::npos){
        //     cout << "ntarsis found: " << is << endl;
        // }

    
    }
    return 0;

}
