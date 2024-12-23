#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


string makeLargestSpecial(string s) {
    if (s.size() <= 1) return s;

    vector<string> substrings;
    int balance = 0, start = 0;
    
    
    for (int i = 0; i < s.size(); ++i) {
        balance += (s[i] == '1') ? 1 : -1;
        if (balance == 0) {
            substrings.push_back("1" + makeLargestSpecial(s.substr(start + 1, i - start - 1)) + "0");
            start = i + 1;
        }
    }
    

    sort(substrings.begin(), substrings.end(), greater<string>());
    

    string result;
    for (const string& sub : substrings) {
        result += sub;
    }
    
    return result;
}

int main() {

    string s1 = "11011000";
    cout << "Result for s = \"" << s1 << "\": " << makeLargestSpecial(s1) << endl; 
    
    string s2 = "10";
    cout << "Result for s = \"" << s2 << "\": " << makeLargestSpecial(s2) << endl;
    
    return 0;
}
