#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    
    /*
    这个空间不够、时间也过不去，通过率为84%左右
    int f[1001000];
    bool flag[1000010];
    int n;
    
    int ugly[100100];
    bool uflag[100010];
    int m;
    
    Solution(){
        n = 0;
        m = 0;
        
        getPrimes();
        preProcess();
    }
    
    void getPrimes(){
        for (int i = 2; i < 10010; ++i){
            if (!flag[i]){
                f[n++] = i;
            }
            for (int j = 0; j < n && f[j]*i < 10010; ++j){
                flag[f[j]*i] = 1;
                if (i % f[j] == 0){
                    break;
                }
            }
        }
    }
    
    void preProcess(){
    	
        ugly[0] = 1;
        m = 1;
        
        for (int i = 3; i < n; ++i){
            for (int j = f[i]; j < 10010; j += f[i]){
                uflag[j] = 1;
            }        
        }
        for (int i = 2; i < 10010; ++i){
            if (!uflag[i]){
                ugly[m++] = i;
            }
        }
    }*/
    
    int key[3];
    long long int ugly[30000];
    int m;
    
    Solution(){
        key[0] = 2;
        key[1] = 3;
        key[2] = 5;
        
        m = 0;
       // ugly[0] = 1;
        fun(0,1);
    }
    
    void insert(long long int x){
        
        int j = m-1;
        while (j >= 0 && x < ugly[j]){
            ugly[j+1] = ugly[j];
            --j;
        }
        ugly[j+1] = x; 
        ++m;

        //cout << x << endl;
        //getchar();
    }
    
    void fun(int x,long long int now){
        
        //cout << x << "  " << now << endl;
        //getchar();

        if (x > 2){
            insert(now);
            return ;
        }
       
        for (int i = 1; ; i *= key[x]){
            if (now*i> 1000000000LL){
                break;
            }
            fun(x+1,now*i);
        }
    }
   
    int GetUglyNumber_Solution(int index) {
        return ugly[index-1];
    }
};

int main(){

    Solution sol;
    cout << sol.GetUglyNumber_Solution(1500) << endl;

}


