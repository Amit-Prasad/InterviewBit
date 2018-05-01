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
long long int minimise(int *t,int n,int A,long long int **dp)
{
    if(A==1)
        return dp[n][1];//subarray(t,0,n-1);
    if(n==1)
        return dp[1][A];//t[0];
    long long int best=INT_MAX;
    int i;
    for(i=1;i<n;i++)
    {
        if(dp[i][A-1]!=0)
            best=min(best, max(dp[i][A-1], subarray(t,i,n-1)));
        else
            best=min(best, max(minimise(t,i,A-1,dp), subarray(t,i,n-1)));
    }
    dp[n][A]=best%10000003;
    return dp[n][A];
}
int paint(int A, int B, int* C, int n3) {
    long long int **dp=(long long int **)malloc(sizeof(long long int *)*(n3+1));
    int i,j;
    for(i=0;i<=n3;i++)
    {
        dp[i]=(long long int *)malloc(sizeof(long long int)*(A+1));
        for(j=0;j<=A;j++)
            dp[i][j]=0;
    }
    dp[0][1]=0;
    for(i=1;i<=n3;i++)
        dp[i][1]=subarray(C,0,i-1);
    for(i=0;i<=A;i++)
        dp[1][i]=C[0];
    return (int)((minimise(C,n3,A,dp)*B)%10000003);
}
