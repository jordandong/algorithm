/*
Given two string, sort the input string based on the order of order string.
e.g.
order = "gfedcba"
input = "xcyczabcdefg"
output = "gfedcccbaxyz"
*/

string Sort_String(string &order, string &input) {
    char mp[256] = {0};
    string res = "";
    for (int i = 0; i < (int)input.size(); i++) {
        mp[input[i]]++;
    }
    for (int i = 0; i < (int)order.size(); i++) {
        while(mp[order[i]]-- > 0) {
            res.push_back(order[i]);
        }
    }
    for (int i = 0; i < (int)input.size(); i++) {
        while(mp[input[i]]-- > 0) {
            res.push_back(input[i]);
        }
    }
    return res;
}
