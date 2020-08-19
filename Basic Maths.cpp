#include<bits/stdc++.h>
using namespace std;

typedef vector <int> vi;
typedef pair< int ,int > pii;
#define endl "\n"
#define sd(val) scanf("%d",&val)
#define ss(val) scanf("%s",&val)
#define sl(val) scanf("%lld",&val)
#define debug(val) printf("check%d\n",val)
#define all(v) v.begin(),v.end()
#define PB push_back
#define MP make_pair
#define FF first
#define SS second
#define ll long long
#define MOD 1000000007
#define clr(val) memset(val,0,sizeof(val))
#define what_is(x) cerr << #x << " is " << x << endl; 
#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
ll prime=1e9+7;
ll power(ll a,ll n){
    ll ans=1;
    while(n>0){
        ll last_bit=(n&1);
        if(last_bit){
            ans=ans*a;//multiple ans with a if last bit of n is 1
            ans%=prime;
        }
        a=a*a;//square up
        a%=prime;
        n=n>>1;//discard the last bit ==>n/=2
    }
    return ans;
}
ll inverse(ll a){
    return power(a,prime-2);
} 
ll gcd(ll a,ll b){
    return b==0?a:gcd(b,a%b);
}
ll lcm(ll a,ll b){
    return (a*b)/gcd(a,b);
}
vector<ll> trial_division1(ll n) {
    vector<long long> factorization;
    for (long long d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}

vector<pair<ll,ll>> trial_division2(ll n) {
    vector<pair<ll,ll>> factorization;
    for (long long d = 2; d * d <= n; d++) {
        int c(0);
        while (n % d == 0) {
            c++;
            factorization.push_back({d,c});
            n /= d;
        }
    }
    if (n > 1)
        factorization.push_back({n,1});
    return factorization;
}
int main(){
    OJ;
    FIO;
    ll n;
    cin>>n;
    //cout<<power(a,n)<<endl;
    //cout<<multiply(a,n);
    //cout<<inverse(a);
    //just a factor
    vector<ll>primefactor=trial_division1(n);
    //factor with number of times it divides
    vector<pair<ll,ll>>factor=trial_division2(n);
    for(auto x:factor){
        cout<<x.first<<" "<<x.second<<"\n";
    }
}
