#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    
struct nod{
        int v;
        string sv;
        
        nod(int vv,string svv){
        	v = vv;
        	sv = svv;
        }

        bool operator < (const nod& x) const{
           
           string s1 = sv + x.sv;
           string s2 = x.sv + sv;

           return s1 < s2;
        }
    };
    
    string convertToString(int x){
        char buffer[255]={0};
        int l = 0;

        while (x){
            buffer[l++] = char(x%10+'0');
            x /= 10;
        }
       
        string s;
        for (int i = l-1; i >= 0; --i){
            s += buffer[i];
        }

        return s;
    } 
    
    string PrintMinNumber(vector<int> numbers) {
       
        vector<nod> vec;
        for (int i = 0; i < numbers.size(); ++i){
            vec.push_back(nod(numbers[i],convertToString(numbers[i])));
        }
        
        sort(vec.begin(),vec.end());
        
        string ret;
        for (int i = 0; i < vec.size(); ++i){
            ret += vec[i].sv;
        }
        //cout << ret << "!!" << endl; 

        return ret;
    }
};

int main(){
  
     int a[] = {3,32,321};
     vector<int> data(a,a+3);
     Solution sol;
     cout << sol.PrintMinNumber(data)
     	  << endl;

	 return 0;
}
