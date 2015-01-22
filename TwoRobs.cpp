/*
a board M*N with some numbers in each cell.
two robs, start from left,up to right,bottom.
the max numbers the two robs can collect, each cell is counted only once
*/

#include <iostream>
#include <vector>
using namespace std;

int twoRobs(vector<vector<int> > &MP){
    int M = MP.size();
    int N = MP[0].size();
    int P_LEN = M + N -1;

    vector<vector<int> > dp1 = vector<vector<int> >(N, vector<int>(N, 0));
    vector<vector<int> > dp2 = vector<vector<int> >(N, vector<int>(N, 0));
    dp1[0][0] = MP[0][0];
    dp2[0][0] = MP[0][0];

    for (int p = 2; p <= P_LEN; p++){//p is the length of the path
        for (int x1 = 0; x1 < N; x1++){
            for (int x2 = x1; x2 < N; x2++){
                int y1 = p - 1 - x1;
                int y2 = p - 1 - x2;
                if(y1<0 || y2<0 || y1>=M || y2>=M)
                    continue; 
                int best = 0;
                int delta = MP[y1][x1];
                if (x1 != x2)
                delta += MP[y2][x2];
                if(x1>0 && x2>0)//from left left
                    best = max(best, dp1[x1-1][x2-1] + delta);
                if(x1>0 && y2>0)//from left up
                    best = max(best, dp1[x1-1][x2] + delta);
                if(y1>0 && x2>0)//from up left
                    best = max(best, dp1[x1][x2-1] + delta);
                if(y1>0 && y2>0)//from up up
                    best = max(best, dp1[x1][x2] + delta);
                dp2[x1][x2] = best;
            }
        }
        dp1=dp2;
    }
    return dp1[N-1][N-1];
}

int main(){
    vector<vector<int> > MP;
    vector<int> a(5, 3);
    vector<int> b(5, 2);
    vector<int> c(5, 3);
    vector<int> d(5, 4);
    MP.push_back(a);
    MP.push_back(b);
    MP.push_back(c);
    MP.push_back(d);
    cout<<twoRobs(MP)<<endl;
}
