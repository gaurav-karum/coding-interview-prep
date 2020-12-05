

///////////////////////////////////////////////////////////////////////////////

/******************************* SOME TRICKS **********************************/

///////////////////////////////////////////////////////////////////////////////


// use builtin functions
__builtin_gcd(a,b)
__builtin_lcm(a,b)
__builtin_clz(), __builtin_clzl(), __builtin_clzll()
__builtin_ctz(), __builtin_ctzl(), __builtin_ctzll()
__builtin_popcount()


// use nullptr instead of NULL or 0
// fast i/o
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 



// use emplace_back when dealing with pairs and tuples
// emplace_back is faster than push_back 'cause it just construct value at the end of vector 
// but push_back construct it somewhere else and then move it to the vector.



// use brace initializer list to initialize containers



// range based loops
 
 	// old way
	for(auto it=container.begin(); it!=container.end(); it++){}
	// or
	for(auto i=0; i<v.size(); i++)

	// new way
	for (auto i : container){
		cout<<i<<" ";
	}
	// if we need to change values too then
	for (auto &i : container){
		i *= 2;
		cout<<i<<" ";
	}





// instead of this
	for(i = 0; i < n; i++) {
    	for(j = 0; j < m; j++)
        	cout << a[i][j] << " ";
   		cout << "\n";
	}
// use this
	for(i = 0; i < n; i++)
    for(j = 0; j < m; j++)
        cout << a[i][j] << " \n"[j == m-1];





// use of lambda functions
[capture list](parameters) -> return value { body }

auto f = [] (int a, int b) -> int { return a + b; };
// can use lambda function in stl





// min or max of 3 or more no.
min({a, b, c})
// Find mid point without overflow
int mid = (s+e)/2 may sometimes cause overflow
//It is better to use
int mid = s + (e-s)/2




// CPP17
//std::clamp
//Returns x if it is in the interval [low, high] or, otherwise, the nearest value:
cout << clamp(7, 0,  10); //7
cout << clamp(7, 0,  5);  //5
cout << clamp(7, 10, 50); //10





//swap two integers w/o using temp.
swapint(x, y){
  x ^= y;
  y ^= x;
  x ^= y;
}




// swap 2 variables
a = a + b - (b = a);




// !! bang bang you're boolean
// Assume you want to use a function which maps 0 to 0 and every non-zero number to 1 
// The easiest bool casting operator is !! 




// CPP17
//  Introducing variables inside an if statement
if (int x = f(); is_good(x)) {
    use_somehow(x);
}




// grid conversion
// let say we want to convert S to 0 E to 1 . to 2 and so on ..
// do it by
arayint[i] = string.("SE.#").find(arraychar[i]); // where array char has those chars





// 2d array to 1d
arr[i][j] will be arr[i*c + j]; //where 2d array is r*c
// 1d array to 2d
as 2d to 1d is x = i*c + j
j = x%c;
i = x/c;





// modulus Distributive Property over +, -, *
(a+b+c)%X = (a%X + b%X + c%X)%X			REMEMBER the last %X
What about negative a?
postiveMode = (a%X + X)%X		-> get smallest negative, add 1 cycle, MOD again
MOD is expensive! That is, in case a tight order problem, code TLE due to MOD!
if(a > MOD || a < 0)	do MOD operation
Or more efficiently, if possible
if(a > MOD)	a -= MOD;	// given that you are sure we are far by ONLY 1 cycle
if(a < 0)	a += MOD;







// operation tricks

// Floor of 2 positive Integers
	a / b
// Ceil of 2 positive Integers
	(a + b-1) / b
// Round of 2 positive Integers
	(a + b/2) / b
// What about negatives? Similar, but in careful way





// floating points comparison is tricky
int doubleCompare(double x, double y) {
	if (fabs(x-y) <= EPS)	// Check equality first. EPS is ur define, e.g. 1e-8. BASED on problem requested precision.
		return 0;
	if(x < y)
		return -1;
	return 1;
}






// overflows
Say we would like to do a * b, but we want to ignore this operation if it exceeds MAX (e.g. MAX = 32 bit max)
Convert if(a * b > MAX) continue;
			TO
		if(a > MAX / b) continue;
What about a * b * c?
	if(a > MAX / b || a * b > MAX / c)	continue;	// Check ab, then abc
What about a * b + c?
	if(a > MAX / b || a * b > MAX - c)	continue;	// Check ab, then abc







// atmost exact
Say we have N balls, and would like to 
	know in how many ways, we could got EXACTLY M balls?	OR
	know in how many ways, we could got AT MOST M balls?	OR
		
The interesting her is there relations.
	Say we have wrote a function that calc EXACT(N, M).
		Then we could calculate AT_MOST(N, M) = EXACT(N, 0) + EXACT(N, 1) + .... EXACT(N, M)
			
	What if we found it easily/efficient to write Function AT_MOST(N, M)
		Then we could calculate EXACT(N, M) = AT_MOST(N, M) - AT_MOST(N, M-1) 





// fixed size sliding windows 
// Given an array and k, find sub-array of length K with maximum Sum
	
	Think in the array: [a b c d e f g h] with k = 3		
	Then we want to check:
	[a b c]
	  [b c d]
		[c d e]
		  [d e f]
			[e f g]
			  [f g h]

	Could we do better? Check the windows again. What is relation between consecutive windows? One number is removed and one number is entered.
	int max = 0;
		for(int win = 0 ; win < k; win++)
			max += A[win];
	sum = max;
	for(int i = 1; i < n-k+1; i++)	O(n)
	{
		sum = sum - A[i-1] + A[i+k];	remove first of last window, and add new one
	}


/*// variable sized sliding window
	// soln. by converting it to fixed size window
Given array and k, find longest range such that max-min <= k.

To convert for fixed, try every length, and then run a fixed sizing window
		For Each length
			Do similar to above algorithm. Note, we can't maintain relation between consecutive windows, so we will do it in O(n^2)
		Total Order O(n^3). We could improve it to N^2logN, but let's try a variable size way.
		*) Start with an empty window, as long as u can add new elements, add them,
		*) Else start to remove the elements from the start. Use multiset.
		E.g. A[] = {2, 3, 2, 1, 4, 10, 9, 8, 7, 2}	K = 7
		Start with 								{}
			2? YES								{2}
			3? YES								{2, 3}
			2? YES								{2, 2, 3}
			1? YES								{1, 2, 2, 3}
			4? YES								{1, 2, 2, 3, 4}
			10? NO 10-1 > 7.   Remove 2			{1, 2, 3, 4, 10}	Still NO
						   	   Remove 3			{1, 2, 4, 10}		Still NO
						   	   Remove 2			{1, 4, 10}			Still NO
						   	   Remove 1			{4, 10}				YES, 10-4 <= 7
			9? Yes								{4, 9, 10}
			8? Yes								{4, 8, 9, 10}
			7? Yes								{4, 7, 8, 9, 10}
			2? NO	10-2 > 7   Remove 4			{2, 7, 8, 9, 10}
			2? NO			   Remove 10		{2, 7, 8, 9}		YES...and so on
			For each YES, maximize over the multiset length.
*/

/*
// variable size window
Given an array, find sub-array with maximum Sum. Notice, this time window is variable size.
		Again, you could try every length, and O(n) find max sum, and maximize over maximums.
		Let's try a variable sliding window size. Here is one general way that to may work with variable windows.
		Say we are given A = [a, b, c, d, ... ]
			Start with first element in array. This is the first window. {a}
		 	Move to next element, could we extend the window do {a, b} or we must remove a?
		 		Say we managed to add it.
		 	Move to c. Could we extend window with it to {a, b, c}? or must remove a? or must remove a and b?
		 	and so on. So each time window ends at current element. Let's apply it.
		 
	
	this is approach for KADENE'S ALGO


*/





