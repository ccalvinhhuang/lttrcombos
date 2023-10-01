#include <iostream>
#include <vector>
#include <map>

using namespace std;

void recurse(string& digits, int i, map<char, string>&m, vector<string>& ans, string cur_string){
    if(cur_string.length() == digits.length()){
        ans.push_back(cur_string);
        return;
    }
    for(char c : m[digits[i]]){
        recurse(digits, i + 1, m, ans, cur_string + c);
    }
}
vector<string> letterCombinations(string digits) {
    map<char, string>m;
    m['2'] = "abc";
    m['3'] = "def";
    m['4'] = "ghi";
    m['5'] = "jkl";
    m['6'] = "mno";
    m['7'] = "pqrs";
    m['8'] = "tuv";
    m['9'] = "wxyz";
    vector<string> ans;
    recurse(digits, 0, m, ans, "");
    if(digits.length() == 0) return {};
    return ans;
}

int main(){
    vector<string> p = letterCombinations("234");
    for(string k : p){
        cout << k << " ";
    }
}
