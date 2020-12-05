/*

	BIT HACKS

*/






//////////////////////////////////////////////////////////////////////////////////////

// A=65 + 32 a=97, 0 - 48
// uppercase to lowercase
ch |= ' '
// lowercase to uppercase
ch &= '_'

//////////////////////////////////////////////////////////////////////////////////////
// built in functions
__builtin_popcount(x) // no. of set bits
__builtin_parity(x) // if odd no. of 1 then returns 1
__builtin_parityl(x) // for long
__builtin_parityll(x) // for long long
__builtin_ctz(x)
__builtin_clz(x)

/////////////////////////////////////////////////////////////////////////////////////

// multiply and divide by 2^x
#define mulby2powx(S, x) (S<<x)
#define divby2powx(S, x) (S>>x)
// x%2
x&1 == x%2
#define modulo(S, N) ((S) & (N - 1))   // returns S % N, where N is a power of 2

// testing if not -1
// instead of if(x != -1) we can write 
if(~x)

#define areequal(x, y) ((x^y) == 0)
#define isodd(x) ((x&1) == 1)
// for long no. use 1LL<<j

//////////////////////////////////////////////////////////////////////////////////////

#define ison(S,j) (S & (1<<j))
#define isOn(S, j) ((S>>j) & 1)
#define setBit(S, j) (S |= (1 << j)) 
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))


//////////////////////////////////////////////////////////////////////////////////////

//get rightmost 0 bit
~x & (x+1)

//get rightmost set bit
#define lowBit(S) (S & (-S))

// check if all bits are set 
n & (n+1) == 0

// no. of bits in binary rep.
log2(x) + 1

// to get position of rightmost set bit
log2(x & (-x))

// to set last n bits
#define setAll(S, n) (S = (1 << n) - 1)

///////////////////////////////////////////////////////////////////////////////////////

// is no. a power of 2
#define isPowerOfTwo(S) (S&&(!(S & (S - 1))))
__builtin_popcount(s) == 1
ceil(log2(x)) == floor(log2(x))

#define nearestPowerOfTwo(S) ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))


///////////////////////////////////////////////////////////////////////////////////////

// turn off rightmost 1 bit 
#define turnOffLastBit(S) ((S) & (S - 1))

// turn on rightmost 0 bit
#define turnOnLastZero(S) ((S) | (S + 1))

// turn off last consecutive runs of 1 e.g. 10111 -> 10000
#define turnOffLastConsecutiveBits(S) ((S) & (S + 1))

// turn on last consecutive runs of 0 e.g. 100 -> 111
#define turnOnLastConsecutiveZeroes(S) ((S) | (S - 1))

// clear all bits from lsb to ith pos
#define clearbitlsb(x, i) x &= (~((1<<i+1)-1))

// clear all bits from msb to ith pos
#define clearbitmsb(x, i) x &= ((1<<i)-1)


/////////////////////////////////////////////////////////////////////////////////////

// Printing Binary -> takes extra space
void printbinary(int n) {                         
  stack<int> s;
  while (n)
    s.push(n % 2), divby2powx(n,1);
  while (!s.empty())                         
    printf("%d", s.top()), s.pop();
  printf("\n");
}

// Printing Binary -> just takes one string
string to_binary(int x) {
	string s;
	while(x > 0) {
		s += (x % 2 ? '1' : '0');
		x /= 2;
	}
	reverse(s.begin(), s.end());
	return s;
}



// Printing Binary -> tail end recursion
void printNumber(int n, int len)
{
  if(!len)
    return ;

  printNumber(n>>1, len-1); // remove last bit
  cout<<(n&1);            // print last bit
}




// Count set bits
int countNumBits1(int mask) { // O(bits Length)
  int ret = 0;  //1101001 -> 110100 -> 11010 -> 1101 -> 110 -> 11 -> 1 -> 0
  while (mask) {
    ret += (mask&1);
    mask >>= 1;
  }
  return ret;
}

//Counting bits set, Brian Kernighan's way
unsigned int v; // count the number of bits set in v
unsigned int c=0; // c accumulates the total bits set in v
while(v){
  v &= v - 1; // clear the least significant bit set
  c++;
}

/////////////////////////////////////////////////////////////////////////////////

/*
	BITSET

	instead of using vector/array of bool we can use this
	but, size must be compile time constant

	indexing starts backwards
*/

#include <bitset>   // The power, speed and memory handling in one place

#define N 32


bitset<N> b; // default 0000....000 total N bits
bitset<N> b(20); // initialize with bits of 20 i.e. 000...0010100
bitset<N> b(string("10100"));
bitset<N> b(s, 2); // from pos 2
bitset<N> b(s, 2, 3); // from pos 2 till next 3 pos
bitset<N> b(s, 2, 3, 'a', 'b') // for every 'a' replace it with 0 ||y 'b' = 1

cout<<b<<endl; // would print exact bits 00000...0010100

b.to_string();
b.to_string('*');
b.to_string('*','#'); // replace 0 by *
b.to_ulong();

bitset<4> bs; // initialized 0000
bs[0] = 1; // 0001
bs.count(); // returns no. of set bits
bs.size(); // would give total no. of bits = 4 bcz bitset<4> bs;
bs.size()-bs.count(); // this would give no. of 0 bits
bs.test(i); // would return 1 if bit is 1 else 0
bs.any(); // returns 1 if there is any bit set
bs.none(); // returns 1 if none of bits is 1
bs.set(); // set all bits = 1
bs.set(pos, bit) // bs[pos] = bit
bs.reset(); // reset all bits
bs.reset(4); // reset 4th bit
bs.flip(); // flip all bits
bs.flip(3); // flips 3rd bit

b == bs // compares two bitsets
bs<<=1 // left shift by 1
bs>>=2 // right shift by 2
bs &= b // can use & ^ |

// find first set bit
bs._Find_first() // O(n/32) == O(n/logn)

// finding first set bit and then bits after some index
for(int i=BS._Find_first();i< BS.size();i = BS._Find_next(i))
    cout<<i<<endl;

// we can use bitset to find whether 
// there exists a subset whose sum = x

// idea -> precalculate for all subset sums
vector<int> vi = {1, 3, 5, 2, 8}
// sum = S = 16
bitset<S+1> bs; // 00...0 
// if ith bit = 1 that means subset sum = i exists
// bs.reset(); dont really need it as it is initialized to 000
bs[0] = 1;

for(int i=0; i<v.size(); ++i){
	// or the following
	// 1. all previous sums
	// 2. we add v[i] to previous sum e.g. 7, 4, 2 add 1 -> 8, 5, 3 (i.e shift by 1)
	bs = bs | (bs<<v[i]);
}
// this would work for W<=32 t.c. O(N*W/32)

