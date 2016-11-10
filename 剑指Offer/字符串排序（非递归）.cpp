class Solution {
public:
   
    string s;
    int l;
    vector<string> ans;
    
    map<string,int> M;
    
    void swap(char &x,char &y){
        int tmp = x;
        x = y;
        y = tmp;
    }
    
    void fun(){
        
        while (1){
            ans.push_back(s);
            int j = l - 1;
            while (j > 0 && s[j-1] >= s[j]){
                --j;
            }
            --j;
            
            if (j < 0) break;
            
            int i = l-1;
            while (i > 0 && s[i] <= s[j]){
                --i;
            }
            
            swap(s[i],s[j]);
            
            for (int k = j+1; k <= (j+l)/2; ++k){
                swap(s[k],s[l+j-k]);
            }
        }
        
    }
    
    vector<string> Permutation(string str) {
        
        ans.clear();
        if (str==""){
            return ans;
        }
        
        vector<char> data;
        for (int i = 0; i < str.length(); ++i){
            data.push_back(str[i]);
        }
         
        sort(data.begin(),data.end());
        s="";
        for (int i = 0; i < data.size(); ++i){
            s += data[i];
        }
        
        l = s.length();
        fun();
        
        return ans;
    }
};