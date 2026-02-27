/*
 * @lc app=leetcode id=1933152936 lang=cpp
 *
 * SumOfRootToLeafBinaryNumbers
 * 
 * Difficulty: Easy
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int fun(TreeNode * root, int sum){
        sum *=2;
        sum += root->val;
        if(root->left == NULL && root->right == NULL  )return sum;
        int ret=0;
        if(root->left!=NULL)ret += fun(root->left, sum);
        if(root->right!=NULL)ret += fun(root->right, sum);
        return ret;

    }
    int sumRootToLeaf(TreeNode* root) {
        return fun(root, 0);
    }
};