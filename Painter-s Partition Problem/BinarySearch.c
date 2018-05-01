long long int subarray(int *A,int start,int end)
{
    int i;
    long long int sum=0;
    for(i=start;i<=end;i++)
        sum+=A[i];
    return sum;
}
int numOfPainters(int *arr,int n,int maxlen)
{
    int total=0,painters=1,i;
    for(i=0;i<n;i++)
    {
        total+=arr[i];
        if(total>maxlen)
        {
            total=arr[i];
            painters++;
        }
    }
    return painters;
}
long long int minimise(int *t,int n,int A,long long int start,long long int end)
{
    while(start<end)
    {
        int mid=start+(end-start)/2;
        int required=numOfPainters(t,n,mid);
        if(required<=A)
            end=mid;
        else
            start=mid+1;
    }
    return start%10000003;
}
int paint(int A, int B, int* C, int n3) {
   long long int max=subarray(C,0,n3-1);
   long long int min=C[0],i;
   for(i=1;i<n3;i++)
   {
       if(C[i]>min)
        min=C[i];
   }
   
   return (int)((minimise(C,n3,A,min,max)*B)%10000003);
}
