class Solution {
public:
   
    vector<char> data;
    int l;
    vector<bool> flag;
    vector<string> ans;
    
    map<string,int> M;
    
    void fun(int k,string s){
        if (k >= l){
            if (M[s] == 0){
                ans.push_back(s);
                M[s]++;
            }
        }
        for (int i = 0; i < l; ++i){
            if (flag[i] == false){
                flag[i] = true;
                fun(k+1,s + data[i]);
                flag[i] = false;
            }
        }      
    }
    
    vector<string> Permutation(string str) {
        
        ans.clear();
        if (str==""){
            return ans;
        }
        
        data.clear();
        for (int i = 0; i < str.length(); ++i){
            data.push_back(str[i]);
        }
         
        sort(data.begin(),data.end());
        
        l = data.size();
         
        vector<bool> tmp(l,false);
        flag = tmp;  
        
        M.clear();
        fun(0,"");
        
        return ans;
    }
};