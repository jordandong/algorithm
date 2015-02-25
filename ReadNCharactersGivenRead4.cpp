/*
The API: int read4(char *buf) reads 4 characters at a time from a file.
The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.
By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.
Note:
The read function will only be called once for each test case.
*/

#include<iostream>
#include<string>
using namespace std;

static int cnt = 5;

int read4(char *buf){
    if(cnt > 0){
        buf[0] = 'a' + cnt;   
        buf[1] = 'a' + cnt;   
        buf[2] = 'a' + cnt;   
        buf[3] = 'a' + cnt;
        cnt--;
        return 4;
    }else if(cnt == 0){
        buf[0] = '0' + cnt;   
        buf[1] = '0' + cnt;   
        cnt--;
        return 2;
    }else{
        return 0;   
    }
};

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char* buf, int n){
        char buffer[4];
        int readBytes = 0;
        bool eof = false;
        int bytes;
        while (!eof && n > 0 && readBytes < n) {
           bytes = read4(buffer); 
           if(bytes < 4)
               eof = true;
            bytes = min(n - readBytes, bytes); 
            memcpy(buf + readBytes, buffer, bytes);
            readBytes += bytes;
        }
        return readBytes;
    }
};

int main(){
    int n;
    Solution sol;  
    while(1){
        cnt = 5;     
        cin>>n;
        char buf[n];
        int sz = sol.read(buf, n);
        string s(buf, sz);
        cout<<"string: "<<s<<", size :"<<sz<<endl;
    }
}
