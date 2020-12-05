#include <bits/stdc++.h>
using namespace std;

#define all(x)  (x).begin(), (x).end()
int nxt(){ 
  int n;
  cin >> n; 
  return n;
}


/*
Struct
*/
struct Rectangle
{
  int length, width;
};

Rectangle rects[5] = {};

/*
Enums
*/
// enum Animals
// {
//   animal_cat = 2;
// };
// int array[animal_cat];
// Animals four_legged = animal_cat;

int main(){
  /*
  	ARRAYS
  */
  int arr[5]{1, 2, 3};
  int arr1[5] = {2, 3, 5};

  /*
  String
  */
  string s;
  cin >> s;
  getline(cin, s);

  string s1 = "hello mello";
  string s1("hello dello");
  string s2{"jello pello"};
  s1 = {"hello jello"};
  string s2{s1};       // s2 = s1
  string s3{5, '&'};   // s3 = "&&&&&"
  string s4{s2, 6};    // from 6 all characters
  string s5{s3, 6, 3}; // from 6 only 3 characters

  s.append("");
  int posn, nchar;
  s.append(s1, posn, nchar);
  
  s1 += s2;
  s1 += "mello ";
  s1 += 'c';
  
  s.insert(posn, s1);
  s.insert(posn, s1, posn, nchar);
  s.insert(posn, nchar, 'c');
  s.pop_back();

  
  //if(s.find(s1) == str::npos);
  s2 = s.substr(7, 3);
  s.erase(posn, nchar);
  s.replace(posn, nchar, s1);
  reverse(s.begin(), s.end());

  s1.compare(s2);

  s.clear();
  s.empty();
  s.at(2);
  s.front();
  s.back();

  s3 = R"()";
  int i_val = 999;
  s2 = to_string(i_val);
  int x = stoi(s);

  // Compare 3 characters from 3rd position
  // (or index 2) of str1 with 3 characters 
  // from 4th position of str2. 
  if (s1.compare(2, 3, s2, 3, 3) == 0)
    cout<<"Equal";
  else
    cout<<"Not equal";


///////////////////////////////////////////////////////////////////////////////////////////////////// 

/*
  *********************************** STL CONTAINERS ***********************************************
*/

/////////////////////////////////////////////////////////////////////////////////////////////////////

  /* 
    PAIR
  */
  pair<int, char> PAIR1;

  PAIR1.first = 21;
  PAIR1.second = 'M';
  pair<int, char> PAIR2(PAIR1);
  pair<int, char> PAIR3(99, 'E');
  pair<int, char> PAIR4;
  pair<int, char> PAIR5 = make_pair(19, 'F');
  pair<int, char> PAIR6 = {19, 'G'};

  // cpp11 =, ==, !=, >=, <= supported, not after cpp20

  // instead of this
  pair<int, char> p = make_pair(9, 'f');
  // use brace initialization
  pair<int, char> p({9, 'f'});
  pair<int, pair<int , char> > p ={ 1, {9, 'f'}};

  PAIR6.swap(PAIR5);

  deque<vector<pair<int, int>>> d;
	d = { { {3, 4}, {5, 6} }, { {1, 2}, {3, 4} } };
	for (auto i: d) {
    	for (auto j: i)
        	cout << j.first << ' ' << j.second << '\n';
    	cout << "-\n";
	}

  /* 
    TUPLE 
  */

  tuple<int, char, string> TUPLE1;
  tuple<int, char, string> TUPLE2(TUPLE1);
  tuple<int, char, string> TUPLE3;

  TUPLE1 = make_tuple(1, 'a', "str1");
  TUPLE3 = {3, 'c', "str3"};

  get<0>(TUPLE1) = 2;
  TUPLE3.swap(TUPLE1);
  int i_val;
  char c_val;
  string str_val;
  tie(i_val, c_val, str_val) = TUPLE1;
  tie(i_val, ignore, str_val) = TUPLE3;
  auto TUPLE4 = tuple_cat(TUPLE1, TUPLE2);

  /*
    VECTOR OF PAIRS, TUPLES, STRUCT
  */
 int n;
  vector<pair<int, int>> vecPairs;
  for (int i = 0; i < n; i++)
    vecPairs.push_back(make_pair(1, 2)); //v.emplace_back({1, 1});
  for (int i = 0; i < n; i++)
  {
    cout << vecPairs[i].first;
  }
  sort(vecPairs.begin(), vecPairs.end()); // sorts acc. to first value

  vector<tuple<int, int, int>> vecTuple;
  vecTuple.push_back(make_tuple(10, 20, 30)); //v.emplace_back(1,2,3)
  for (const auto &i : vecTuple)
    cout << get<0>(i);

  struct Interval
  {
    int start, end;
  };

  vector<Interval> vStruct{{6, 8}, {1, 9}, {2, 4}};
  sort(vStruct.begin(), vStruct.end(), [](Interval v1, Interval v2) { return v1.start < v2.start; });

  

  /*
    VECTOR
  */

  // INITIALIZATION
  int arr[n];
  vector<int> v(n);
  vector<int> v1 = {1, 2, 3}; // initializer list
  v1 = {3, 4, 5};
  vector<int> v2(3, 0);
  vector<string> v3(3, "HI");                 // fill constructor
  vector<int> v3(v2);                         // v3 = v2; copy constructor
  //vector<int> v4(arr, arr + n);               // n -> sizeof(arr)/sizeof(arr[0])
  vector<int> v5(v3.begin(), v3.begin() + 2); // range constructor

  // ITERATING
  for (auto it = v1.begin(); it != v1.end(); it++) // cbegin(), rbegin(), crbegin()
    cout << *it;

  for (int i = 0; i < v1.size(); i++)
    cout << v1[i];

  // note we can iterate string like
  for (auto i = 0; s[i]; i++)
  {
  }

  for (int i : v1)
    cout << i << " ";

  v.front();
  v.back();
  v.at(0);
  v[0];
  v.empty();
  v.size();
  //v.resize();
  v.capacity();
  v.max_size();
  v1.shrink_to_fit();

  v1.push_back(4);
  v1.pop_back();
  v1.emplace_back(4);

  v1.insert(v1.begin(), 5);    // inserts new elem. b4 that posn
  v1.insert(v1.begin(), 3, 5); // inserts 3 no. of 5s
  v1.insert(v1.begin(), v2.begin(), v2.end());

  v1.assign(3, 5); // assigns new values by replacign old values
  v1.assign(v2.begin(), v2.end());
  //v1.assign(arr, arr + n);

  v1.clear();
  v1.erase(v1.begin()); // position
  v1.erase(v1.begin(), v1.end()); //pos or range

  upper_bound(v1.begin(), v1.end(), 6); // x > 6
  lower_bound(v1.begin(), v1.end(), 6); // x >= 6

  

  /*
    2D VECTOR
  */
  int nRows, nRow, nCols, nCol;
  vector<vector<int>> v7{{1, 2, 3}, {5, 6}};
  vector<vector<int>> v8(nRows, vector<int>(nCols, 0));
  vector<vector<int>> v9(nRow);
  v9[0] = vector<int>(nCol);
  v9.push_back({1, 2, 3});
  v9.push_back(v1);

  sort(v8.begin(), v8.end()); // sorts whole 2d array
  sort(v7[0].begin(), v7[0].end()); // sorts 1st row of 2d vector
  // use of lambda functions
  // sort 2d array acc. to particular column
  sort(v8.begin(), v8.end(), [](const vector<int> &v1, const vector<int> &v2) { return v1[1] < v2[1]; });
  sort(all(v), [](const vector<int>& v1, const vector<int>& v2) { return v1.size() < v2.size(); } );





  /*
    DEQUE - functions same as vectors 
  */
  
  deque<int> dq; // double-ended queue
  dq.push_back(20);
  dq.emplace_back(40);
  dq.push_front(10);
  dq.emplace_front(40);
  dq.pop_back();
  dq.pop_front();
  dq.back();
  dq.front();
  dq.empty();
  dq.size();


  /*
    STACK
  */

  stack<int> stk, stk1, stk2;
  stk.push(20);
  stk.push(10);
  stk.push(30);
  stk1.swap(stk2);
  cout << "Stack elements: ";
  stk.size();
  while (!stk.empty())
  {
    cout << stk.top() << " ";
    stk.pop();
  }
  cout << "\n";

  
  

  /*
    QUEUE
  */

  queue<int> q, q1, q2;
  q.push(20);
  q.push(10);
  q.emplace(40);
  q.front();
  q.back();
  q.size();
  q1.swap(q2);
  while (!q.empty())
  {
    cout << q.front() << " ";
    q.pop();
  }

  


  /*
      PRIORITY  QUEUE
  */
  struct compare {
    bool operator()(int a, int b){
      return a < b;
    }
  };

  priority_queue<int> pq, pq1, pq2;                   // by default max heap
  priority_queue<int, vector<int>, greater<int>> pq1; //min heap
  priority_queue<int, vector<int>, compare> pq;
  pq.push(20);
  pq.push(10);
  pq.push(30);
  pq1.swap(pq2);
  cout << "Priority Queue elements: ";
  while (!pq.empty())
  {
    cout << pq.top() << " ";
    pq.pop();
  }
  cout << "\n";

  



  /*
  list
  */
  
  list<int> l1, l2;
  int count, element, val;
  l1.insert(l1.begin(), 100);
  l1.insert(l1.begin(), count ,element);
  l1.insert(l1.begin(), l2.begin(), l2.end());

  l1.assign(count, val);
  l2.assign(l1.begin(),l1.end());

  l1.push_back(x);
  l1.push_front(x);
  l1.pop_back();
  l1.pop_front();
  l1.front();
  l1.back();
  l1.empty();


  l1.swap(l2);
  l1.reverse();
  l1.sort();

  l1.erase(l1.begin());
  l1.erase(l1.begin(), next(l1.begin(),2));
  l1.remove(x);
  l1.clear();

  l1.merge(l2);
  l2.splice(l2.begin(),l1);

  /*
  iterator
  */
  auto it1 = v.begin();
  auto it2 = v.end();
  it1 = next(v.begin(), 3);
  it2 = prev(v.end(), 4);
  distance(it1, it2);




    /*
    

    SETS
    
    set
    multiset -> differ from set in having multiple keys of same value
    unordered_set -> no order in set
  
    set => ordered, uses balanced BST, search/insert/delete log(n) 
    unordered_set => no ordering, uses hash table, search/insert/delete O(1) but worst case O(n)

    note => for searching O(logn) in set and O(1) in unordered_set

    Use set when=> less memory , ordering matters, searching in small set(<100), predecessor access required
    Use unordered_ste when=>  search on large sets, single element access

    => can lexico. compare diff. sets with <, <=, > and >=. unordered_sets are not required to support these operations.
  

  */
  
  // declaration
  set<int, greater<int>> SET1, SET2, SET3;
  set<int> SET4, SET5, SET6;
  

  // initialization
  set<int> first;// empty set of ints
  set<int> second{1, 2, 5, 3, 4}; // brace initialization
  set<int> second = {1, 2, 5, 3, 4}; // same as above
  int myints[]= {10,20,30,40,50};
  set<int> third(myints,myints+5);// range based initialization
  set<int> fourth(second); // copy 
  set<int> fifth(second.begin(), second.end()); // iterator based
  set<int> sixth = fifth; // copy/ = operator based 
  set<int, compare> seventh{8, 4, 2, 1}; // custom set(binary predicate)
  //set<int> eight(cmerge(third, fourth)); // move/cmerge


  // cpp 11
  auto cmp = [](int a, int b) { return a < b; };
  std::set<int, decltype(cmp)> s1(cmp);
  // cpp 20
  std::set<int, decltype(cmp)> s2;
  // old soln
  struct comp {
    bool operator() (int a, int b) const {
        return a < b;
    }
  };
  std::set<int, comp> s3;

  // NOTE-> it has no access operator
  // diff. b/w set<pair> and map
  // set elements can't be modified when in set, you have to remove them from the set and then re-insert



  // insertion
  SET1.insert(1); // insert element directly
  SET1.insert(1, 2); // with posn. .insert(pos, x)
  SET3.insert(SET1.find(2), SET1.end()); // insert elements in given range
  SET3.insert({3,2, 1}); // brace initializer type insertion


  // swap
  SET3.swap(SET2);


  // deletion
  SET2.clear(); // clear whole set
  SET1.erase(2); // erase one element 
  SET1.erase(SET1.find(1), SET1.end()); // erases range of elements


  // capacity
  SET3.empty();
  SET3.size();

  
  // operations
  SET3.count(x);
  SET3.find(3); // returns iterator to the found ele. else returns s.end()


  // if not modifiying elements
  for (auto i : SET1)
    cout << i << " ";
  // if we want to modify elements
  for (auto &i : SET1)
  {
    i = i * 2;
  }
  

  // instead of 
  int key;
  if(SET1.find(key) != SET1.end())
  // use this->
  if(SET1.count(key)) // count returns 1 if there is key in map


  

  set_union(SET1.begin(), SET1.end(), SET2.begin(), SET2.end(), insert_iterator<set<int>>(SET4, SET4.begin()));
  set_intersection(SET1.begin(), SET1.end(), SET2.begin(), SET2.end(), insert_iterator<set<int>>(SET5, SET5.begin()));
  set_difference(SET1.begin(), SET1.end(), SET2.begin(), SET2.end(), insert_iterator<set<int>>(SET6, SET6.begin()));

  // one can initialize set from vector and vice versa








 
  /*
      MAPS 

      map
      multimap
      unordered_map

      map => ordered, uses balanced BST/Red Block tree, search/insert/delete log(n)/log(n)+rebalance, comparators < 
      unordered_map => no ordering, uses hash table, search/insert/delete O(1) but worst case O(n), comaparator ==

      note => for searching O(logn) in set and O(1) in unordered_set

      Use set when=> less memory , ordering matters, searching in small set(<100), predecessor access required
      Use unordered_ste when=>  search on large sets, single element access

      => can lexico. compare diff. sets with <, <=, > and >=. unordered_sets are not required to support these operations.
  
  */
  // declaration
  map<int, int> m, m1, m2, m3, m4;


  //  insertion in maps
  m1.insert(pair<int, int>(1, 40));
  m1.emplace(pair<int, int>(3, 50));
  m1.insert({2, 30}); // brace initializer - use this
  m1.insert({4, 35});
  m1.insert({5, 80});
  m2.insert(m1.begin(), m1.end());
  m3 = m2;


  // NOTE -> differs from set =>  it has element access 
  m1[6]; // inserts key 6 w/o any value
  m1[7] = 60;

  
  // swapping two maps
  m2.swap(m1);

  
  // removing elements  
  m4.clear(); // clear whole map
  m2.erase(2); // erase one particular element
  m2.erase(m2.find(1)); // erase one particular index
  m2.erase(m2.begin(), next(m2.begin(),2)); // erase range of elements b/w indices


  // capacity
  m4.empty();
  m4.size();


  // operations
  m1.count(1);
  m1.find(x);
  auto it = m2.upper_bound(2); // finds key > 2
  // if out of range returns size of map and 0
  auto it = m2.lower_bound(3);


  for (auto it = m.begin(); it != m.end(); it++)
    cout << it->first << " ";


  // instead of 
  if(m.find(key) != m.end());
  // use this->
  if(m.count(key)); // count returns 1 if there is key in map

  
  
}