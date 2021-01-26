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
#define vl vector<long long>
#define inf 2147483647
#define INF 9223372036854775807
#define f0(i,n) for(int i=0;i<n;i++)
#define fk(i,k,n) for(int i=k;i<n;i++)
ll one=1;
ll M=1000000007;       //10^9+7 
using namespace std;
template<class T>
bool is_even(T &n)
{
    return (n & 1)==0;
}
template<class T>
void input(T *v,int size)
{
    f0(i,size)
        cin>>v[i];
}
template<class T>
void print(T *v,int size)
{
    f0(i,size)
    cout<<v[i]<<" ";
    cout<<nl;
}
template<class T>
int array_partition(T &arr,int l,int r,int index)
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
template<class T>
int kth_smallest(T &arr,int l,int r,int k)
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
template<class T>
T gcd(T a,T b)
{
    if(a==0)
        return b;
    return gcd(b%a,a);
}
template<class T>
ll nCr(T n,T r)
{
    
    if(n<r || n<0 || r<0)
    return -1;
    if(r==0)
    return 1;
    if(r>n-r)
    r=n-r;
    ll nu,de,m;
    nu=de=1;
    while(r)
    {
        nu*=n;
        de*=r;
        m=gcd(n,r);
        nu/=m;
        de/=m;
        n--;
        r--;
    }
    return (nu/de);
}
void solve()
{
   
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t=1;

    while(t--)
        solve();
    return 0;
}