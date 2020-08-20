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
//Create a boolean array "prime[0..n]" and initialize 
    // all entries it as true. A value in prime[i] will 
    // finally be false if i is Not a prime, else true. 
   
ll maxN=90000001;
vector<bool>p(maxN,true);
vi ans;
void sieve(){
    p[0]=p[1]=false;
    for(ll i=2;i*i<=maxN;i++){
        if(p[i]){
            // Update all multiples of p greater than or  
            // equal to the square of it 
            // numbers which are multiple of p and are 
            // less than p^2 are already been marked.
            for(ll j=i*i;j<=maxN;j+=i){
                p[j]=false;
            }
        }
    }
    for(int i=2;i<=maxN;i++){
        if(p[i]){
            ans.PB(i);
        }
    }
}


int main(){
    //OJ;
    FIO;
    ll n;
    cin>>n;
    sieve();
    while(n--){
        ll k;cin>>k; 
        cout<<ans[k-1]<<"\n"; 
    }
    
}
