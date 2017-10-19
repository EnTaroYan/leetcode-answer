/* Given a binary tree, return all root-to-leaf paths. 
For example, given the following binary tree: 

   1
 /   \
2     3
 \
  5

All root-to-leaf paths are: 
["1->2->5", "1->3"] */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
//Solution 1
class Solution 
{
public:
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        if(root==NULL)
           return result;
        temp.push_back(root->val);
        if((root->left==NULL) && (root->right==NULL))
        {
            result.push_back("");
            for(int a:temp)
            {
                result[cnt]+=to_string(a);
                result[cnt]+="->";
            }
            result[cnt].erase(result[cnt].end()-2,result[cnt].end());
            cnt++;
            temp.erase(temp.end()-1);
        }
        else
        {
            binaryTreePaths(root->left);
            binaryTreePaths(root->right);
            temp.erase(temp.end()-1);
        }
        return result;
    }
private:
    vector<string> result;
    vector<int> temp;
    int cnt=0;
};

//Solution 2
class Solution 
{
public:
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        if(root==NULL)
           return result;
        res(root,to_string(root->val));
        return result;
    }
    
    void res(TreeNode* root,string s)
    {
        if(!root->left && !root->right)
            result.push_back(s);
        if(root->left)
            res(root->left,s+"->"+to_string(root->left->val));
        if(root->right)
            res(root->right,s+"->"+to_string(root->right->val));
    }
    
private:
    vector<string> result;
};