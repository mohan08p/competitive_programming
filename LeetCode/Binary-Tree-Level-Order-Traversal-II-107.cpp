/* Problem Statement:

Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:

Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7

return its bottom-up level order traversal as:

[
  [15,7],
  [9,20],
  [3]
]

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        vector<vector<int>> levelvec;
        vector<int> level;
        stack<vector<int>> s;       // stack to store the level order traversal bottom up
        queue<TreeNode*> q;
        int currLevelCount=0;       // variable to store the no of nodes in a given level
        TreeNode* temp = NULL;
        
        if(root==NULL) return levelvec;
        
        q.push(root);
        
        while(!q.empty())
        {
            currLevelCount=q.size();   // "currentLevelCount" determined from current size of queue
            
            while(currLevelCount--)
            {
                temp = q.front();
                level.push_back(temp->val);
                
                if(temp->left)
                    q.push(temp->left);
                    
                if(temp->right)
                    q.push(temp->right);
                    
                q.pop();
            }
            
            s.push(level);
            level.clear();
        }
        
        while(!s.empty())       // store the result in levelvec in reverse fashion using stack
        {
            levelvec.push_back(s.top());
            s.pop();
        }
        
        return levelvec;
        
    }
};