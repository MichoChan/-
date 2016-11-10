/*
struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
  TreeNode(int x) :
      val(x), left(NULL), right(NULL) {
  }
};*/
class Solution {
public:
    
    vector<TreeNode*> vec;
    
    void InOrder(TreeNode *now){
        if (now){
            InOrder(now->left);
            
            vec.push_back(now);
            
            InOrder(now->right);
        }
    }
       
    TreeNode* Convert(TreeNode* pRootOfTree){
     
        InOrder(pRootOfTree);
        
        if (vec.size() == 0)
            return NULL;
     
        for(int i = 1; i < vec.size(); ++i){
            vec[i-1]->right = vec[i];
            vec[i]->left = vec[i-1];
        }
        
        return vec[0];
    }
};