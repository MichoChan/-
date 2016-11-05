class Solution {
       
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        
        if (pushV.size() ==0 || popV.size() == 0){
            return false;
        }
        
        stack<int> S;
        
        int i = 0 ,j = 0;
        while (i < popV.size()){
            if (S.empty() || S.top() != popV[i]){
                if (j >= pushV.size()){
                    return false;
                }
                S.push(pushV[j]);
                ++j;
            }else{
                S.pop();
                ++i;
            }
        }
        
        return true;
    }
};