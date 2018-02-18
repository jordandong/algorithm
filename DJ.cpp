#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>
using namespace std;

/*
 * dijkstra algorithm
 *
 * INPUT:
 * vector<vector<int>> dG :
 *     directed graph adjacent array, size n * n
 *     dG[i][j] is the distance from node i to node j
 *     -1 means infinite, all other negtive values are considered as invalid
 * int src : 
 *     source node, range from 0 to n - 1, n is the size of dG
 *
 * OUTPUT:
 * vector<long long> ans:
 *     ans[i] means the distance from node source to node i
 *     assume the output is within the range of type long long
 *     if the distance is longer than the max value of long long can hold,
 *     the algorithm takes the maximum signed long long 0x7fffffffffffffff instead
 *     -1 means infinite, unreachable
 */

#define DEBUG_LL_RANGE 1
#define LMAX 0x7fffffffffffffff

//TIME : O(N*N*logN), SPACE : O(N)
#if DEBUG_LL_RANGE
//debug the overflow case only
vector<long long> dijkstra_v1(vector<vector<long long>> &dG, int src) {
#else
vector<long long> dijkstra_v1(vector<vector<int>> &dG, int src) {
#endif
    //case 1 : null input
    //case 2 : invalid (dG.size() != dG[0].size()) input
    //case 3 : invalid source node, out of range
    //case 4 : invalid distance from src to src, dG[src][src] is non zero
    //return empty vector{}
    int n = dG.size();
    if (n == 0 || n != dG[0].size() || src >= n || dG[src][src] != 0)
        return {};

    vector<long long> ans(n, -1); //init as infinite to all nodes
    set<pair<long long, int>> uvis; //set contains unvisited nodes
    unordered_map<int, bool> vis; //map contains visited nodes
    
    uvis.insert({dG[src][src], src}); //only adding curretly reachable nodes in set
    ans[src] = 0; //src to src is zero
    while (!uvis.empty()) { //O(N)
        // Sets are typically implemented as binary search trees.
        // lookup/insert/erase : O(logN)
        // the minimum element is in the front, don't need to find mimimum every time
        auto cur_node = uvis.begin()->second;
        uvis.erase(uvis.begin());
        vis[cur_node] = true; //the node can be added to visited map
        if (dG[cur_node][cur_node] != 0) 
            return {};
        for (int j = 0; j < n; j++) { //O(N)
            long long dis = dG[cur_node][j];
            //ignore same/unreachable/vistied nodes
            if (cur_node == j || dis == -1 || vis.find(j) != vis.end())
                continue;
            if (dis < 0) //invalid input, negtive distance
                return {};
            unsigned long long new_dis = ans[cur_node] + dis; //handle overflow
            if (ans[j] == -1 ||  new_dis < ans[j]) {
                //update distance and node pair in uvis set and ans, O(logN) operation
                uvis.erase({ans[j], j});
                uvis.insert({min(new_dis, (unsigned long long)LMAX), j});
                ans[j] = min(new_dis, (unsigned long long)LMAX);
            }
        }
    }
    return ans;
}

 
//TIME : O(N*N), SPACE : O(N)
#if DEBUG_LL_RANGE
//debug the overflow case only
vector<long long> dijkstra_v2(vector<vector<long long>> &dG, int src) {
#else
vector<long long> dijkstra_v2(vector<vector<int>> &dG, int src) {
#endif
    //case 1 : null input
    //case 2 : invalid (dG.size() != dG[0].size()) input
    //case 3 : invalid source node, out of range
    //case 4 : invalid distance from src to src, dG[src][src] is non zero
    //return empty vector{}
    int n = dG.size();
    if (n == 0 || n != dG[0].size() || src >= n || dG[src][src] != 0)
        return {};

    vector<long long> ans(n, -1); //init as infinite to all nodes
    unordered_map<int, bool> uvis; //map contains unvisited nodes
    unordered_map<int, bool> vis; //map contains visited nodes
    
    uvis[src] = true;
    ans[src] = 0; //src to src is zero
    while (!uvis.empty()) { //O(N)
        long long mi = LMAX;
        int cur_node = -1;
        //find current shortest distance node, O(N)
        for (int i = 0; i < n; i++) {
            //ignore current unreachable/visited nodes, which is not in uvis map
            if (uvis.find(i) == uvis.end())
                continue;
            if (ans[i] <= mi) {
                mi = ans[i];
                cur_node = i;
            }
        }

        uvis.erase(cur_node);
        vis[cur_node] = true; //the node can be added to visited map
        if (dG[cur_node][cur_node] != 0)
            return {};
        for (int j = 0; j < n; j++) { //O(N)
            long long dis = dG[cur_node][j];
            //ignore same/unreachable/vistied nodes
            if (cur_node == j || dis == -1 || vis.find(j) != vis.end())
                continue;
            if (dis < 0) //invalid input, negtive distance
                return {};
            unsigned long long new_dis = ans[cur_node] + dis; //handle overflow
            if (ans[j] == -1 ||  new_dis < ans[j]) {
                //update distance and node in uvis map and ans, O(1)
                uvis[j] = true;
                ans[j] = min(new_dis, (unsigned long long)LMAX);
            }
        }
    }
    return ans;
}

int main()
{
    vector<long long> ans;
#if not DEBUG_LL_RANGE
    vector<vector<int>> dG = {};
    ans = dijkstra_v1(dG, 0);
    cout<<"v1 case 1 null input, ans size: "<<ans.size()<<endl;
    for (auto e : ans) {
        cout<<e<<" ";
    }
    cout<<endl;
    
    ans = dijkstra_v2(dG, 0);
    cout<<"v2 case 1 null input, ans size: "<<ans.size()<<endl;
    for (auto e : ans) {
        cout<<e<<" ";
    }
    cout<<endl;
    
    
    dG = {{0, 2}, {1, 2}, {2, 3}};
    ans = dijkstra_v1(dG, 0);
    cout<<"v1 case 2 input size mismatch, ans size: "<<ans.size()<<endl;
    for (auto e : ans) {
        cout<<e<<" ";
    }
    cout<<endl;
    
    ans = dijkstra_v2(dG, 0);
    cout<<"v2 case 2 input size mismatch, ans size: "<<ans.size()<<endl;
    for (auto e : ans) {
        cout<<e<<" ";
    }
    cout<<endl;
    
    dG = {{0, 2}, {1, 2}};
    ans = dijkstra_v1(dG, 3);
    cout<<"v1 case 3 invalid source, ans size: "<<ans.size()<<endl;
    for (auto e : ans) {
        cout<<e<<" ";
    }
    cout<<endl;
    
    ans = dijkstra_v2(dG, 3);
    cout<<"v2 case 3 invalid source, ans size: "<<ans.size()<<endl;
    for (auto e : ans) {
        cout<<e<<" ";
    }
    cout<<endl;

    dG = {{1, 2}, {1, 2}};
    ans = dijkstra_v1(dG, 0);
    cout<<"v1 case 4 invalid src to src, ans size: "<<ans.size()<<endl;
    for (auto e : ans) {
        cout<<e<<" ";
    }
    cout<<endl;
    
    ans = dijkstra_v2(dG, 0);
    cout<<"v2 case 4 invalid src to src, ans size: "<<ans.size()<<endl;
    for (auto e : ans) {
        cout<<e<<" ";
    }
    cout<<endl;
    
    dG = {{0, 2}, {0, 1}};
    ans = dijkstra_v1(dG, 0);
    cout<<"v1 case 5 invalid nodex to nodex, ans size: "<<ans.size()<<endl;
    for (auto e : ans) {
        cout<<e<<" ";
    }
    cout<<endl;
    
    ans = dijkstra_v2(dG, 0);
    cout<<"v2 case 5 invalid nodex to nodex, ans size: "<<ans.size()<<endl;
    for (auto e : ans) {
        cout<<e<<" ";
    }
    cout<<endl;
    
    dG = {{0, 1, 10, 10}, {0, 0, 2, 8}, {0, 0, 0, -2}, {0, 0, 0, 0}};
    ans = dijkstra_v1(dG, 0);
    cout<<"v1 case 6 invalid negtive input, ans size: "<<ans.size()<<endl;
    for (auto e : ans) {
        cout<<e<<" ";
    }
    cout<<endl;
    
    ans = dijkstra_v2(dG, 0);
    cout<<"v2 case 6 invalid negtive input, ans size: "<<ans.size()<<endl;
    for (auto e : ans) {
        cout<<e<<" ";
    }
    cout<<endl;
    
    dG = {{0, 1, 10, 10}, {0, 0, 2, 8}, {0, 0, 0, -1}, {0, 0, 0, 0}};
    ans = dijkstra_v1(dG, 0);
    cout<<"v1 case 7 normal input with -1, ans size: "<<ans.size()<<endl;
    for (auto e : ans) {
        cout<<e<<" ";
    }
    cout<<endl;

    ans = dijkstra_v2(dG, 0);
    cout<<"v2 case 7 normal input with -1, ans size: "<<ans.size()<<endl;
    for (auto e : ans) {
        cout<<e<<" ";
    }
    cout<<endl;

    dG = {{0, 1, 10, 10}, {0, 0, 2, 8}, {0, 0, 0, 5}, {0, 0, 0, 0}};
    ans = dijkstra_v1(dG, 0);
    cout<<"v1 case 8 normal input, ans size: "<<ans.size()<<endl;
    for (auto e : ans) {
        cout<<e<<" ";
    }
    cout<<endl;
    
    ans = dijkstra_v2(dG, 0);
    cout<<"v2 case 8 normal input, ans size: "<<ans.size()<<endl;
    for (auto e : ans) {
        cout<<e<<" ";
    }
    cout<<endl;
    
    
    dG = {{0, 1, -1, -1}, {2, 0, -1, -1}, {-1, -1, 0, 5}, {-1, -1, 6, 0}};
    ans = dijkstra_v1(dG, 0);
    cout<<"v1 case 9 normal input seperated graph, ans size: "<<ans.size()<<endl;
    for (auto e : ans) {
        cout<<e<<" ";
    }
    cout<<endl;
    
    ans = dijkstra_v2(dG, 0);
    cout<<"v2 case 9 normal input seperated graph, ans size: "<<ans.size()<<endl;
    for (auto e : ans) {
        cout<<e<<" ";
    }
    cout<<endl;

#else
    vector<vector<long long>> dG = {{0, 0x7fffffffffffffff, -1}, {0, 0, 0x7fffffffffffffff}, {0, 0x7fffffffffffffff, 0}};
    ans = dijkstra_v1(dG, 0);
    cout<<"v1 case 10 out of range input, ans size: "<<ans.size()<<endl;
    for (auto e : ans) {
        cout<<e<<" ";
    }
    cout<<endl;
    
    ans = dijkstra_v2(dG, 0);
    cout<<"v2 case 10 out of range input, ans size: "<<ans.size()<<endl;
    for (auto e : ans) {
        cout<<e<<" ";
    }
    cout<<endl;
#endif

    return 0;
}
