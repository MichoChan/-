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
    vector<int> PrintFromTopToBottom(TreeNode *root) {
		vector<int> ret;
        
        
        queue<TreeNode*> Q;
        if (root != NULL)
        	Q.push(root);
        
        while (!Q.empty()){
            TreeNode* now = Q.front();
            Q.pop();
            
            if (now->left != NULL){
                Q.push(now->left);
            }
            if (now->right != NULL){
                Q.push(now->right);
            }
           	ret.push_back(now->val);
        }

      	return ret;
    }
};