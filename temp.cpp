#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<numeric>
#include<queue>
#include<functional>
#define nl "\n"
#define ll long long
#define vi vector<int>
#define INF 2000000000
#define f0(i,n) for(int i=0;i<n;i++)
#define fk(i,k,n) for(int i=k;i<n;i++)
using namespace std;
bool even(int &n)
{
    return n%2==0;
}
void input(vi &v,int &size)
{
    v.clear();
    int n;
    f0(i,size)
    {
        cin>>n;
        v.push_back(n);
    }
}
void print(int arr[],int s)
{
    for(int* i=arr;i<arr+s;i++)
    cout<<(*i)<<" ";
    cout<<nl;
}
int array_partition(int arr[],int l,int r,int index)
{
    if(r<l)
    return -1;
    if(l==r)
    return l;
    int i,j;
    swap(arr[index],arr[l]);
    i=l;
    j=r+1;
    while(i!=j-1)
    {
        if(arr[i+1]<=arr[l])
        i++;
        else if(arr[j-1]>arr[l])
        j--;
        else
        swap(arr[++i],arr[--j]);
    }
    swap(arr[l],arr[i]);
    return i;
}
int kth_smallest(int arr[],int l,int r,int k)
{
    if(k<0 || r-l+1<k)
    return INF;
    int pivot=array_partition(arr,l,r,l+(rand()%(r-l+1)));
    if(pivot-l+1==k)
    return arr[pivot];
    else if(pivot-l+1>k)
    return kth_smallest(arr,l,pivot-1,k);
    else
    return kth_smallest(arr,pivot+1,r,k-(pivot-l+1));
}
int maxSubarraySum(int arr[], int n)
{
    if(n==0)
    return 0;
    int mx,M;
    mx=M=arr[0];
    for(int i=1;i<n;i++)
    {
        M=max(arr[i],M+arr[i]);
        mx=max(mx,M);
    }
    return mx;
}
int main()
{
    cout<<((-5)%7);
    return 0;
}