#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;
 
string readFile(const string& path) {
    ifstream inf(path);
    if (!inf.is_open()) {
        cerr << "Couldn't open file: '"
             << path << "'" << endl;
        exit(EXIT_FAILURE);
    }
    return string((std::istreambuf_iterator<char>(inf)), std::istreambuf_iterator<char>());
}

int main() {
    string paras;
    string path = "in.txt";

    paras = readFile(path);

    
    int l = 0;
    for (int i = 0; i < paras.length(); i++){
        char c = paras[i];

        if (c == '('){
            l++;
        }else if (c == ')'){
            l--;
        }
    }

    cout << l << endl;
    return 0;

}
