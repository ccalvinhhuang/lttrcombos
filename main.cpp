#include <iostream>
#include <vector>

using namespace std;

string m[8];
vector<string>ans;
string nums;
void recurse(int iter, string s){
    if(iter == nums.length() && s.length() == nums.length()){
        ans.push_back(s);
        return;
    }
    for(int i = iter; i < nums.length(); i++){
        int cur_stem = (nums[i] - '0') - 2;
        for(int j = 0; j < m[cur_stem].length(); j++){
            recurse(i + 1, s + m[cur_stem][j]);
        }
    }

}
vector<string> lttrCombos(string digits) {
    nums = digits;
    string temp = "abc";
    for(int i = 0; i < 8; i++){
        m[i] = temp;
        int add = 3;
        if(i == 5){
            m[i] += 's';
            add = 4;
        }
        if(i == 7){
            m[i] += 'z';
        }
        for(int j = 0; j < 3; j++){
            temp[j] += add;
        }
    }
    recurse(0,"");
    return ans;
}

