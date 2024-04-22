#include <iostream>
#include "BinaryTree.h"
using namespace std;

// TODO: solution breath first search
/**
 * traverser all level
 * Depth First Search Solution
*/
void Solution::dfs_zigzag(TreeNode *currentNode, vector<vector<int>>& allLevels, int currentLevel)
{
    if (!currentNode) return;
    // root node or first node of each level
    if (currentLevel >= allLevels.size()) {
        allLevels.push_back({currentNode->val});
    } else {
        if (currentLevel%2 == 0) {
            // left -> right direction
            allLevels.at(currentLevel).push_back(currentNode->val);
        } else {
            vector<int>::iterator it = allLevels.at(currentLevel).begin();
            allLevels.at(currentLevel).insert(it, currentNode->val);

        }
    }

    // traverser
    dfs_zigzag(currentNode->left, allLevels, currentLevel+1);
    dfs_zigzag(currentNode->right, allLevels, currentLevel+1);
}

/**
 * answer method
*/
vector<vector<int>> Solution::zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    
    dfs_zigzag(root, ans, 0);
    return ans;
}