/**
Author:Micheal Chan@blog.csdn.net/aq14aq1

Complexity:
    O(n^2)  when the sequence is after-order sequence of a BST
**/

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        
        int l = sequence.size();
        if (l == 0){
            return false;
        }
        
        for (int i = 1; i < l; ++i){
            if (sequence[i] > sequence[i-1]){
                for (int j = i-1; j >= 0; --j){
                    if (sequence[i] < sequence[j]){
                        return false;
                    }
                }
            }else{
                int j;
               for (j = i-1; j >= 0; --j){
                    if (sequence[i] < sequence[j]){
                    }else{
                        break;
                    }
                }
                for (;j >=0; --j){
                    if (sequence[i] < sequence[j]){
                        return false;
                    }
                }
            }
        }
       
        return true;
    }
};