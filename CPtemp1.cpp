/*
  compiler404
*/
#include <bits/stdc++.h>
#pragma GCC optimize O2
using namespace std;

#define mp                       make_pair
#define mt                       make_tuple
#define pb                       push_back
#define eb                       emplace_back
#define all(x)                   (x).begin(),(x).end()
#define rall(x)                  (x).rbegin(),(x).rend()
#define fi                       first
#define se                       second
#define sz(x)                    ((int)(x).size())
#define rep(i,x,y,s)             for(int i=x;(x<=y?i<=y:i>=y);i=(x<=y?i+s:i-s))
#define fore(it, l)              for(auto it=l.begin(); it!=l.end(); it++)

#define PI                       acos(-1.0)
#define Pi                       3.141592653589793
#define SQR(n)                   ( n * n )
#define MAX                      1e9
#define MIN                      -1e9
#define MOD                      1000000007
#define FMOD                     998244353
#define max(x,y)                 (x>y)?x:y
#define min(x,y)                 (x<y)?x:y
#define mid(s,e)                 (s+(e-s)/2)
const   int                      dx4[] = {-1, 0, 1, 0};
const 	int                      dy4[] = {0, 1, 0, -1};  //rep0(i,4)  (x+dx4[i] , y+dy4[i])

typedef long long int            ll;
typedef map<int,int>	           mii;
typedef map<char,int>            mci;
typedef unordered_map<int,int>   umii;
typedef unordered_set<int,int>   usii;
typedef pair<int,int> 	         pii;
typedef tuple<int, int, int>     tiii; 
typedef vector<int> 	           vi;
typedef vector<ll> 	             vl;
typedef vector< vi >             vvi;
typedef vector< vl >             vvl;
typedef vector<string> 	         vs;
typedef vector< pii >            vii;

inline bool isEqual(double a, double b) { return fabs(a-b) < 1e-9; }
#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1 << n) - 1)

#define modulo(S, N) ((S) & (N - 1))   // returns S % N, where N is a power of 2
#define isPowerOfTwo(S) (!(S & (S - 1)))
#define nearestPowerOfTwo(S) ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))
#define turnOffLastBit(S) ((S) & (S - 1))
#define turnOnLastZero(S) ((S) | (S + 1))
#define turnOffLastConsecutiveBits(S) ((S) & (S + 1))
#define turnOnLastConsecutiveZeroes(S) ((S) | (S - 1))


ll power(ll a, ll n) {ll p = 1;while (n > 0) {if(n%2) {p = p * a;} n >>= 1; a *= a;} return p;}
ll power(ll a, ll n, ll mod) {ll p = 1;while (n > 0) {if(n%2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;}

template <typename T> inline void write(T x){
	int i = 20;char buf[21];
	buf[20] = '\n';
	do{
		buf[--i] = x % 10 + '0';
		x/= 10;
	}while(x);
	do{
		putchar(buf[i]);
	} while (buf[i++] != '\n');
}

template <typename T> inline T readInt(){
	T n=0,s=1;
	char p=getchar();
	if(p=='-') s=-1;
	while((p<'0'||p>'9')&&p!=EOF&&p!='-') p=getchar();
	if(p=='-') s=-1,p=getchar();
	while(p>='0'&&p<='9') {
		n = (n<< 3) + (n<< 1) + (p - '0');
		p=getchar();
	}
  return n*s;
}

int main()
{
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);

	// #ifndef ONLINE_JUDGE
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	// #endif

	int T, x; 
	cin >> T;

	while(cin >> x){}

	while(T--){
		string s;
		getline(cin, s);	
	}
	//for (int i = 0; s[i]; ++i) { ... }
	//iota(v.begin(), v.end(), x)
  //cout << a[i][j] << " \n"[j == m];
	//cout<<(x==1?"Yes":"No");
	//if (~x) { ... }
	return 0;
}
