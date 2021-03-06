
#include<bits/stdc++.h>
using namespace std;

#define intmax 1000000
#define endl "\n"
#define add(a,b) a+b

typedef long long ll ;

ll bin(ll a[],ll n, ll mn, ll mx, ll x)
{
    if(mn==mx)
    {
            if(a[mn]>x)return mn;
            else return n;
    }
    ll mid = (mn+mx)/2;
    if(a[mid] >x)
    {
        return bin(a,n,mn,mid,x);
    }
    else{
        return bin(a,n,mid+1,mx,x);
    }
}

ll check(ll a[], ll n)
{
    ll ans=0;
    for(ll i =0;i<n;i++)
    {
        for(ll j =i+1;j<n-1; j++)
        {
                ans+=n-bin(a,n,j+1,n-1,a[i]+a[j]);
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    while(n)
    {
        ll a[n];
        for(ll i = 0 ;i<n;i++)
            cin>> a[i];
        sort(a,a+n);
        ll m =0;
        ll t=0;
        for(ll i =1;i<=n-2;i++)
        {
            m += i+t;
            t=m;
        }
        cout<<check(a, n)<<endl;
        cin >>n;
    }
    return 0;
}
