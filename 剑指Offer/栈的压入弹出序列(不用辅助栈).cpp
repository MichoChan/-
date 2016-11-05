/******
Author:Micheal Chan@blog.csdn.net/aq14aq1

Summary:
    without a stack

Analysis:
    O(n^2)

    if using map-like data struct for searching,time can be O(nlgn)
******/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
         
        if (pushV.size() == 0 || popV.size() == 0) return false;
         
        int idx = -1;
        for (int i = 0; i < pushV.size(); ++i){
            if (popV[0] == pushV[i]){
                idx = i;
            }
        }
         
        if (idx < 0) return false;   //一开始这种情况没有考虑到
         
        int j = 1;
         
        vector<int> flag(pushV.size(),0);
        flag[idx] = 1;
         
        while (j < popV.size()){
            int tmpIdx = -1;
            for (int i = 0; i < pushV.size(); ++i){
                if (popV[j] == pushV[i]){
                    tmpIdx = i;
                }
            }
             
            if (tmpIdx > idx){
                idx = tmpIdx;
            }else{
                int i;
                for (i = idx - 1; i >= 0; --i){
                    if (flag[i] == 0){
                        break;
                    }
                }
                if (i < 0 || tmpIdx != i){
                    return false;
                }
                idx = tmpIdx;
            }
             
            flag[idx] = 1;
            ++j;
        }
         
        return true;
    }
};

int main(){

    Solution sol;

    int a[] = {1,2,3,4,5};
    int b[] = {4,3,5,1,2};

    vector<int> pushV(a,a+5);
    vector<int> popV(b,b+5);

    cout << sol.IsPopOrder(pushV,popV)
         << endl;

    return 0;
}

