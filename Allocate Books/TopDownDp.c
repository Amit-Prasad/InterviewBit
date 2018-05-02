int max(int x,int y)
{
    if(x<y)
        return y;
    return x;
}
int min(int x,int y)
{
    if(x<y)
        return x;
    return y;
}
int subarray(int *A,int start,int end)
{
    int i,sum=0;
    for(i=start;i<=end;i++)
        sum+=A[i];
    return sum;
}
int minimise(int *A,int n1,int B,int **dp)
{
    if(B==1)
        return dp[n1][1];
    if(n1==1)
        return dp[1][B];
    int best=INT_MAX;
    int i;
    for(i=1;i<n1;i++)
    {
        if(dp[i][B-1]!=0)
            best=min(best,max(dp[i][B-1],subarray(A,i,n1-1)));
        else
            best=min(best,max(minimise(A,i,B-1,dp),subarray(A,i,n1-1)));
    }
    dp[n1][B]=best;
    return dp[n1][B];
}
int books(int* A, int n1, int B) {
    if(B>n1)
        return -1;
    int **dp=(int **)malloc(sizeof(int*)*(n1+1));
    int i,j;
    for(i=0;i<=n1;i++)
    {
        dp[i]=(int *)malloc(sizeof(int)*(B+1));
        for(j=0;j<=B;j++)
            dp[i][j]=0;
    }
    for(i=1;i<=n1;i++)
    {
        dp[i][1]=subarray(A,0,i-1);
       // printf("%d\n",dp[i][1]);
    }
    for(i=1;i<=B;i++)
        dp[1][i]=A[0];
    return minimise(A,n1,B,dp);
}
