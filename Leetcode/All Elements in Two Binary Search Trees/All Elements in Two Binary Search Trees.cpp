#include<bits/stdc++.h>
using namespace std;

//  Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };  

class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
    {
        //declaration of vector
        vector<int> v1, v2;
        
        //function call
        inorder(root1, v1);
        inorder(root2, v2);
        
        //declaration of vector
        vector<int> ans;
        
        // Merge function takes log(m+n) as compared with sort function which takes nlogn time. 
        merge(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(ans)); 
        return ans;
    }
    
    void inorder(TreeNode* root, vector<int> &v)
    {
        // if tree is empty
        if(!root) return;
        
        //recusive call
        inorder(root->left,v);
        
        //pushing element into vector
        v.push_back(root->val);
        
        //recursive call
        inorder(root->right,v);
    }
};