class Solution {
public:
    int numberOfSets(int n, int k) {
        /*Intuition*/

        /*
            We have n points : 0,1,2, ...... , n-1

            We need to chose exactly k line segments where segments cannot overlap.

            Important Observations -> Instead of thinking about all possible segments at once,
            let's focus on the rightmost point j.

            Define : dp[i][j] => no. of ways to choose exactly i non-overlapping segments using 
            the points from 0 to j.

            Now, when calculating dp[i][j] , there are two possibilites :

            Case 1 : Point j is not the right endpoint 

            Then our last segment ends somewhere before j.

            So we simply ignore the point j:

            dp[i][j] = dp[i][j-1]

            Example : [0,1.....,5] => So i segments was already constructed using [0,1,....,4]

            Case 2 : Point j is the right endpoint

            Now the last segment must end at j.

            Suppose the last segment starts at p.

            [p,j] 

            Then all the previous i-1 segments must be completely inside : 0,1.....,p

            Why p? Because the previous segment cannot overlap [p,j] but they can share the endpoint

            So for every possible p : 
            p = 0,1,2.....,j-1

            we can add :
            dp[i-1][p]

            Therefore : dp[i][j] = dp[i][j-1] + dp[i-1][0] + dp[i-1][1] +..... + dp[i-1][j-1]

            And seeing this is exactly where the prefix sum comes from.



            Why do we need prefix sums?

            If we directly calculate

            dp[i-1][0] + dp[i-1][1] + .... dp[i-1][j-1]

            For every j , we are repeatedly calculate the same sums.

            That could make the solution O(n*n*k).

            Instead , maintain:
            prefixSums[j] = dp[i-1][0] + dp[i-1][1] +.......... + dp[i-1][j]

            Then the entire sum :

            prefixSum[j-1]


            Small Example :

            0 1 2 3  k=2

            dp[2][3]

            Case 1 :dp[2][3] += dp[2][2]

            Case 2 :[0,3] [1,3] [2,3]

            So we add : dp[1][0] + dp[1][1] + dp[1][2]



            Base Cases :

            If we want 0 segments , there is exactly one way : 
            Choose nothing


            So dp[0][j] = 1 for every j

            And with only one point , we can't create a segment:

            dp[i][0] = 0 for i>0

        */

        int MOD = 1e9+7;

        vector<vector<long long>>dp(k+1,vector<long long>(n,0));

        //0 segments can always be chosen in exactly 1 way
        for(int j=0;j<n;j++) dp[0][j]=1;

        for(int i=1;i<=k;i++){
            long long prefix = 0;
            for(int j=1;j<n;j++){
                //dp[i-1][0.....j-1]
                prefix = (prefix+dp[i-1][j-1]) %MOD;

                dp[i][j] = (dp[i][j-1] + prefix)%MOD;
            }
        } 
        return dp[k][n-1];
        //TC -> O(n*k)
    }
};