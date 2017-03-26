// Author:
// https://leetcode.com/derekhh/

int dp[201][201][201],rr[201],s[201];

struct data{
    int x,n;
}d[200];

class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int T,n,m,i,j,k,l,r;
        n=boxes.size();
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++)s[i]=0;
        for(i=0;i<n;i++){
            d[i].x=boxes[i];
            d[i].n=1;
        }
        for(i=m=0;i<n;i=j){
            r=0;
            for(j=i;j<n&&d[i].x==d[j].x;j++)r++;
            d[m++]=(data){d[i].x,r};
        }
        n=m;
        for(i=n-1;i>=0;i--){
            rr[i]=s[d[i].x];
            s[d[i].x]+=d[i].n;
        }
        for(i=0;i<n;i++)
            for(j=0;j<=rr[i];j++)
                dp[i][1][j]=(d[i].n+j)*(d[i].n+j);
        for(i=2;i<=n;i++)
            for(j=0;j+i<=n;j++)
                for(k=0;k<=rr[j+i-1];k++){
                    dp[j][i][k]=dp[j][i-1][0]+(d[j+i-1].n+k)*(d[j+i-1].n+k);
                    for(l=1;l<i;l++){
                        if(d[j+i-1].x==d[j+l-1].x){
                            if(dp[j][i][k]<dp[j][l][k+d[j+i-1].n]+dp[j+l][i-l-1][0])dp[j][i][k]=dp[j][l][k+d[j+i-1].n]+dp[j+l][i-l-1][0];
                            l++;
                        }
                    }
                }
        return dp[0][n][0];
    }
};

