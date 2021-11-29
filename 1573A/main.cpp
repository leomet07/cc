#include <iostream>
#include <stdio.h>   
#include <stdlib.h>  

using namespace std;

int inspect(string in){
    int clocknum = stoi(in);
    int smallest_num = 9;
    
    int totalops = 0;

    for (int i = 0; i < in.size(); i++){
        char c = in[i];
        int current_int = atoi(&c);

        if (current_int > 0 && i < in.size() -1){
            totalops += current_int + 1;
        } else if ( current_int > 0 ){
            totalops += current_int;
        }
    }
    
    return totalops;
}

int getNum(string q){
    int i = 0;
    cout << q;
    cin >> i;

    return i;
}

string getString(string q){
    string s = "";
    cout << q;

    cin >> s;

    return s;
}

void doubleAskParse(int total_tests){
    cout << "Three line parse. Tests to be asked?: " << total_tests << endl;

    for (int current_test = 0; current_test < total_tests; current_test++){
        int numdigits = getNum("Enter number of digits: ");
        // Useless var, only to not break when during double ask input

        string snum = getString("Enter a number: ");
        cout << "Total ops: " << inspect(snum) << endl;
    }
}

void singleAskParse(int total_tests){
    cout << "One line parse. Tests to be asked?: " << total_tests << endl;

    for (int current_test = 0; current_test < total_tests; current_test++){
        string snum = getString("Enter a number: ");
        cout << "Total ops: " << inspect(snum) << endl;
    }
}


int main() {
    int total_tests = getNum("Enter total tests: ");
    
    // doubleAskParse(total_tests);
    singleAskParse(total_tests);

    
    // test case 1: 007
    // test case 2: 1000
    // test case 3: 000000
    return 0;
}