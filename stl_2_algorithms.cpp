///////////////////////////////////////////////////////////////////////////////////////////////////// 

/*
  *********************************** STL ALGORITHMS ***********************************************
*/

/////////////////////////////////////////////////////////////////////////////////////////////////////





#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;

bool custom(int i){
  return i%2 == 0;
}

int nxt(){
  int n; 
  cin >> n;
  return n;
}

vi v;
vi vv;
int n, k, i;
int main(){
/*
  SORTING
*/

sort(all(v)); //  v.begin() to v.end()
sort(n+all(v)-k); // v.begin()+n to v.end()-k
sort(all(v), greater<int>()); // in descending order
sort(all(v[i]), greater<int>()); // sorting ith row of 2d vector

// using lambda function
struct Interval{ int start, end;};
vector<Interval> vec{{6,8}, {1,9}, {2,4}, {4,7}}; 
sort(all(vec),[](Interval i1, Interval i2){ return i1.start > i2.start;});

partial_sort(v.begin(), v.begin()+k, v.end()); // w/o custom func.
partial_sort(v.begin(), v.begin()+k, v.end(), custom); // with custom func.

// diff b/w sort and partial_sort
// sort with range considers elements of that range only
// partial_sort considers all elements and give sorted no. for that range
vector<int> v = { 45, 10, 60, 78, 23, 21, 3 }, v1; 
partial_sort(v.begin(), v.begin() + 2, v.end()); // will give 3, 10
sort(v1.begin(), v1.begin() + 2); // will give 10, 45 

// use of partial_sort
// to get sorted elements till some index-> 
// can be used to get maximum or minimum at first index 
// w/o sorting whole array
partial_sort(v.begin(), v.begin()+1, v.end(), greater<int>()); // max at first index
partial_sort(v.begin(), v.begin()+1, v.end()); // min at first index


// use of stable_sort
// if we want to preserve order
stable_sort(all(v));

// Note -> 
// sort uses introsort(mix of quick, heap and insertion sort) 
// insertion sort most optimal for small arrays also if array is partially sorted
// heapsort used instead of merge because heapsort requires O(1) space 
// partition size < 16 uses insertion sort, 16 <= partition size < 2log(n) uses quicksort, >2log(n) uses heapsort
// sort t.c. O(nlog(n)) s.c. O(log(n))
// partial_sort uses mergesort 
// partial_sort t.c. O(nlog^2(n)) if O(n) space not available
// partial_sort t.c. O(nlog(n)) if O(n) space available

// if we want to keep original array intact
partial_sort_copy(all(v), all(vv)); // copy sorted range from v to vv

// check if elements follow some order in given range
is_sorted(all(v), [](char a, char b){return tolower(a) <= tolower(b);});

// find first element that defies sorted order
auto it = is_sorted_until(all(v));// returns iterator 

// ..... < x < ...... nth position has element which will be if vector is sorted
nth_element(v.begin(), v.begin()+n, v.end()); // if mid iterator is v.end() then it will do nothing









/*
  SEARCHING(operating on partitioned/sorted ranges)
*/
int x;
lower_bound(all(v), x); // finds element >=x
upper_bound(all(v), x); // finds element > x
// equal_range returns pair of iterator b/w which range == some given element
auto it = equal_range(all(v), x);
auto i = it.first - v.begin();// -> same as lower bound
auto j = it.second - v.begin();// -> same as upper bound 
// elements = x in it.first to it.second-1
binary_search(all(v), x);// will tell whether x is present or not








/*
  PERMUTATION
*/
next_permutation(all(v)); // returns true if there is next_permutation
// we can generate all permutations from this
while(next_permutation(all(v))){
  cout << v[0]<<" "<<v[1]<<" "<<v[2]<<endl;
}
prev_permutation(all(v));
// to compare two ranges lexicographically
lexicographical_compare(all(v), all(vv)); // compare all of v with all of vv







/*
  MIN, MAX
*/
// all these return element
min_element(all(v));
max_element(n+all(v)-k);
minmax_element(n+all(v)); // returns pair of iterator
max({1, 4, 3, 7, 8}, [](int a, int b){return a>b;});
min({1, -1, 0});
minmax({23, 44, 57});






/*
  NON MODIFYING
*/
all_of(all(v), [](int i){return i%2 == 0;}); // takes unary predicate
any_of(all(v), [](int i){return i%2 != 0;});
none_of(all(v), [](int i){return i%2 == 0;});

find(all(v), x); // returns iterator
find_if(all(v), custom);
find_if_not(all(v), custom);

search(all(v), all(vv));// search where subsequence vv occurs first in v
find_end(all(v), all(vv));// search last occurrence of subsequence vv in v 
search_n(all(v), n, x); // to search where element x occurs n times consecutively

find_first_of(all(v), all(vv)); // searches for first occurrence of any element of vv in v
// application -> find first occurrence of vowel/ odd no/ even no

is_permutation(all(v), vv.begin()); // searches whether they are permutations
equal(all(v), vv.begin()); 
mismatch(all(v), vv.begin()); // returns pair of iterator where mismatch occurred

count(all(v), x);
count_if(all(v), [](){});

adjacent_find(all(v));
int ans = 0;
accumulate(all(v), ans);// accumulates initial value = ans, stores in ans 



/*
    MODIFYING 
*/


move(all(v), vv.begin());
copy(all(v), vv.begin());
copy_if(all(v), vv.begin(), [](int i){return i%2==0;});
copy_n(v.begin(), n, vv.begin());
//copy_backwards(v.begin(), v.begin()+x, vv.begin());


int old_val, new_val;
replace(all(v), old_val, new_val);
replace_if(all(v), [](int i){return i%2==0;}, new_val);
replace_copy(all(v), vv.begin(), old_val, new_val);
replace_copy_if(all(v), vv.begin(), [](int i){return i%2==0;}, new_val);


remove(all(v), x); // returns iterator to end 
v.resize(remove(all(v), x) - v.begin());
remove_if(all(v), [](int i){return i%2==0;}); // then resize it
remove_copy(all(v), vv.begin(), x);
remove_copy_if(all(v), back_inserter(vv), [](int i){return i%2==0;} );


int rotL, rotR;
// to rotate left
rotate(v.begin(), v.begin()+rotL, v.end());
// to rotate right
rotate(v.begin(), v.end()-rotR, v.end());
// easier to understand rotate as swap two ranges
reverse(all(v));
reverse_copy(all(v), vv.begin());



// unique(all(v)) removes consecutive duplicates
// and returns iterator to last elem.
// to make vector contain only unique elements
sort(all(v));
v.resize(unique(all(v)) - v.begin());
unique(all(v), [](char a, char b){return a==b && a=='G';});
unique_copy(all(v), vv.begin()); 


// now instead of int n; cin >> n;
// we can do
int n = nxt();


// to fill a vector with some no.
fill(all(v), x);
fill_n(v.begin(), n, x);


// to fill with consecutive elements 
iota(all(v), x); // will give x, x+1, x+2
iota_n(v.begin(), n, x);


// to fill with random values
generate(all(v), rand);
// to fill a vec by n values
vector<int> v(nxt());
generate(all(v), nxt);
generate_n(back_inserter(v), n, nxt);// instead of generate(v.begin(), nxt);
// analogous with _n takes size of second parameter
// instead of end iterator
back_insert_iterator<vector<int> > backr(v);
generate_n(backr, n, nxt);
// back_inserter can be used instead of v.begin() if vector is initially
// empty and hence there is no v.begin()
// can only be used where we can use .push_back() i.e. vector, list, dequeue


for_each(all(v), [](int i){cout<<i<<" ";});
vi foo;
vi bar;
transform(foo.begin(), foo.end(), bar.begin(), op_increase);
transform(foo.begin(), foo.end(), bar.begin(), foo.begin(), plus<int>());
transform(all(v), v.begin(), [](int i) -> int{ return i+1;}); 
}