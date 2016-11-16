#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
        vector<vector<int> > Print(TreeNode* pRoot) {
        	
            cout << "456" << endl;
            vector<vector<int> > ans;
            if (pRoot == NULL)
            {
                ans;
                cout << "123";
            }
            
            int cnt = 0;
            queue<TreeNode*> Q;
            vector<int> vec;
            //vec.push_back(pRoot->val);
            Q.push(pRoot);
            
            int a = 1, n = 1, flag = 1;

            while (!Q.empty()){
                TreeNode* node = Q.front();
                Q.pop();
         		vec.push_back(node->val);
                cnt++;

                if (node->left)
                    Q.push(node->left),n++;
                if (node->right)
                    Q.push(node->right),n++;

                if (cnt == flag){
                    ans.push_back(vec);
                    vec.clear();
                    flag = n - a;
                    a = n;
                    cnt = 0;
                }
            }
            
            return ans;
        }
    
};


int main(){

    TreeNode* p = new TreeNode(3);

    TreeNode* pl = new TreeNode(4);
    p->left = pl;

    TreeNode* pr = new TreeNode(4);
    p->right = pr;


    TreeNode* pll = new TreeNode(4);
    pl->left = pll;

    TreeNode *nul = NULL;

    Solution s;
    vector<vector<int> > v =  s.Print(nul);
    
    for (int i = 0; i < v.size(); ++i){
        for (int j = 0; j < v[i].size(); ++j)
            printf("%d ",v[i][j]);
        printf("\n");
    }

    return 0;
}
