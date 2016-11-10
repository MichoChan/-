class Solution {
public:
   
    void swap(int &x, int &y){
        int tmp = x;
        x = y;
        y = tmp;
    }
    
    void down(vector<int> &input,int start,int l){
        while (start*2 + 1 < l){
            int j = -1;
            if (input[start] > input[start*2+1]){
                swap(input[start],input[start*2+1]);
                j = start*2+1;
            }
            if (start*2+2 < l && input[start] > input[start*2+2]){
                swap(input[start],input[start*2+2]);
                j = start*2+2;
            }
            if (j == -1) break;
            start = j;
        }
    }
    
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
       
        vector<int> ans;
        if (k > input.size()){
            return ans;
        }
        
        int i = input.size() / 2 - 1;
        
        int l = input.size();
        for (; i >= 0; --i){
            down(input,i,l);
        }
        
 
        for (int i = 0; i < k; ++i){
     		ans.push_back(input[0]);
     
            swap(input[0],input[l-1]);
            
            down(input,0,--l);
           
        }
       
       return ans;
    }
    
};