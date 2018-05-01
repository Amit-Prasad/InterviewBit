/*Source: https://www.geeksforgeeks.org/painters-partition-problem*/
long long int min(long long int x,long long int y)
{
    if(x<y)
        return x;
    return y;
}
long long int max(long long int x,long long int y)
{
    if(x<y)
        return y;
    return x;
}
long long int subarray(int *A,int start,int end)
{
    int i;
    long long int sum=0;
    for(i=start;i<=end;i++)
        sum+=A[i];
    return sum;
}

long long int minimise(int *t,int n,int A)
{
    long long int dp[n+1][A+1];
    int i,j,p;
    for(i=0;i<=n;i++)
        for(j=0;j<=A;j++)
            dp[i][j]=0;
    for(i=1;i<=n;i++)
        dp[i][1]=subarray(t,0,i-1);//dp[i-1][1]+t[i-1];
    for(i=1;i<=A;i++)
        dp[1][i]=t[0];
    for(i=2;i<=A;i++)
    {
        for(j=2;j<=n;j++)
        {
            long long int best=INT_MAX;
            for(p=1;p<=j;p++)
                best=min(best,max(dp[p][i-1],subarray(t,p,j-1)));
            
            dp[j][i]=best%10000003;
        }
    }
    return dp[n][A];
}

int paint(int A, int B, int* C, int n3) {
    return (int)((minimise(C,n3,A)*B)%10000003);
}
