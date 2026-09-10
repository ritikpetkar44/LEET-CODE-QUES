class Solution {
public:
    pair<int,int> helper(TreeNode *root,int & ans){

        //Empty Subtree
        if(root==NULL) return {0,0};

        auto left = helper(root->left,ans);

        auto right = helper(root->right,ans);

        int sum = root->val + left.first + right.first;

        int count = 1 + left.second + right.second;

        if(root->val == (sum/count)) ans++;

        return {sum,count};
    }
    int averageOfSubtree(TreeNode* root) {
        /*
            How do we check whether a node is equal to the average of its entire subtree?

            The trick is to calculate the subtree's sum and count in on DFS.
        */

        /*
            Intuition
                For every node, we need :
                    Sum of all nodes in its subtree
                    No. of nodes in its subtree
                
                So the average wil be -> sum/count

                If the average equals to the current node's val, we increase our answer
            
            Helper() function ->

            We will use :
                pair<int,int> helper(TreeNode *root,int & ans);

                This will return  {sum,count}

            //Empty Subtree->
            if(root==NULL) return {0,0};

            Then we recursively calculate the left and right subtree : 

                auto left = helper(root->left,ans);
                auto right = helper(root->right,ans);

                So now:
                    left.first = left subtree sum
                    left.second = left subtree count
            
            Calculate current subtree :

                int sum = root->val + left.first + right.first

                int count = 1 + left.second + right.second;

            Check the average :

                if(root->val == (sum/count)) ans++;

            Return to the parent :
                
                return {sum,count};
        */
        int ans = 0;

        helper(root,ans);

        return ans;
    }
};