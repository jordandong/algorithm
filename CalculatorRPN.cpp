/*
 get value for exp like  "1/((1+1)/(1+1))-(-5)*6"
*/



#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

vector<string> r_polish(vector<string> vs){
    stack<string> stk;
    vector<string> res;
    int len = vs.size();

    for(int i = 0; i<len ; i++){
        string e = vs[i];    
        if(e == "("){//highest priority  
            stk.push(e);
        }else if(e == "-" || e == "+"){ // * and / has higher priority than + and -
            while(!stk.empty() && (stk.top() == "-" || stk.top() == "*" || stk.top() == "/")){
                res.push_back(stk.top());
                stk.pop();
            }
            stk.push(e);
        } else if(e == "*" || e == "/"){ // / has higer priority than * and /
            while(!stk.empty() && (stk.top() == "/")){
                res.push_back(stk.top());
                stk.pop();
            }
            stk.push(e);
        }else if(e == ")"){ // highest priority
            while(!stk.empty() && stk.top() != "("){
                res.push_back(stk.top());
                stk.pop();
            }
            stk.pop();
        }else{
            res.push_back(e);
        }
    }
    while(!stk.empty()){
        res.push_back(stk.top());
        stk.pop();
    }
    return res;
}

double cal_r_polish(vector<string> vs){
    int len = vs.size();
    stack<double> stk;
    for(int i=0 ; i<len ; i++){
        if(vs[i]=="+" || vs[i]=="-" || vs[i]=="*" || vs[i]=="/"){
            double a = stk.top();
            stk.pop();
            double b = stk.top();
            stk.pop();
            if(vs[i] == "+")
                stk.push(b+a);
            if(vs[i] == "-")
                stk.push(b-a);
            if(vs[i] == "*")
                stk.push(b*a);
            if(vs[i] == "/")
                stk.push(b/a);
        } else {
            double num = 0;
            for(int j=0; j<vs[i].size(); j++){
                num=10*num + (double)(vs[i][j]-'0');
            }
            stk.push(num);
        }
    }
    return stk.top();
}


vector<string> str2vec(string s){
    int len = s.length();
    string num = "";
    vector<string> res;
    for(int i = 0 ; i<len ; i++){
        if(isdigit(s[i])){
            num+=s.substr(i,1);
        }else{
            if(num.length()){
                res.push_back(num);
                num = "";
            }
            if(i && (s[i]=='-' || s[i]=='+')){
                if(s[i-1] == '('){
                    res.push_back("0"); // if ...+ or * or /(-+x) make it (0-+x)
                }
            }
            res.push_back(s.substr(i,1));
        }
    }
    if(num.length()){
        res.push_back(num);
        num = "";
    }
    return res;
}

int main(){
    vector<string> aa = r_polish(str2vec("1/((1+1)/(1+1))-(-5)*6"));
    for(int i = 0; i<aa.size(); i++){
        cout<<aa[i]<<endl;
    }
    cout<<cal_r_polish(aa)<<endl;
    return 0;
}
