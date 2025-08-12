#include <bits/stdc++.h>
using namespace std;

/// STL: standard Templete library

void explainVectors()
{
    /// Vector is a container which is dynamic in nature
    // vector is used for dynamic storage
    //  vector<int> v ;
    //  here to add element in the vector we use following methods
    //  v.push_back(2);
    //  v.emplace_back(3);
    cout << "i wanrt to chaeck value of v:" << endl;
    // we can have pair vectors as well
    vector<pair<int, int>> pv;
    pv.push_back({2, 4});
    pv.emplace_back(4, 6);
    // cout<< pv;

    vector<int> v(1, 100); // v(5, 100) means container contains instances of  100 is decalred
    v.emplace_back(3);
    v.emplace_back(5);
    v.emplace_back(7);
    v.emplace_back(34);

    // vector<int> v(5);//this means container of 5 instaces of zero is declared.
    vector<int> v1(5, 20); // this means container with 5 instaces of 20 is declared.
    // now i want to copy above container to another container
    vector<int> v2(v1); // here v2 is copy of the v1 container

    /// ITERATORS: iteratorsa are nothing but the addess of memory og the particular elements
    vector<int>::iterator it = v.begin();
    it++;
    cout << *(it) << ", " << endl;

    it = it + 2;
    cout << *(it) << " " << endl;

    vector<int>::iterator it1 = v.begin();

    cout << "Ways to print values in vectors v[0]: " << v[0] << " v.at(0): " << v.at(0) << endl;

    // now for printing entire vector we can do as follows
    cout << "First way to print loop: ";
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *(it) << " ";
    }
    cout << endl
         << "Second way to print loop: ";
    for (auto it = v.begin(); it != v.end(); it++) /// v.end() this indicates the memory address after last element.
    {
        cout << *(it) << " ";
    }
    cout << endl
         << "Third  way to print loop short cut: ";
    // this is for each loopw
    for (auto it : v)
    {
        cout << it << " ";
    }

    /// CORRECT: Regular iterators
    vector<int>::iterator it3 = v.begin(); // Points to first elements memory
    vector<int>::iterator it2 = v.end();   // Points past last element

    /// CORRECT: Reverse iterators (different type!)
    vector<int>::reverse_iterator rit1 = v.rbegin(); // Points to last element
    vector<int>::reverse_iterator rit2 = v.rend();   // Points before first element

    /// WRONG: This causes the error you're seeing
    /// vector<int>::iterator it3 = v.rbegin();  /// ERROR!
    /// vector<int>::iterator it4 = v.rend();    /// ERROR!

    // Demonstrating the difference:
    cout << endl
         << "Forward iteration (begin to end):\n";
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        cout << *it << " "; /// To access anything at a particular memory address we use '*' operator
    }
    cout << "\n";

    cout << "Reverse iteration (rbegin to rend):\n";
    for (auto rit = v.rbegin(); rit != v.rend(); ++rit)
    {
        cout << *rit << " ";
    }
    cout << "\n";

    // Using auto for cleaner code (recommended):
    auto forward_it = v.begin();
    auto reverse_it = v.rbegin();

    cout << "First element (forward): " << *forward_it << "\n";
    cout << "First element (reverse): " << *reverse_it << "\n";

    // Converting between iterator types (if needed):
    // From reverse_iterator to regular iterator:
    auto regular_from_reverse = reverse_it.base();
    // Note: base() points to the element AFTER the reverse iterator

    cout << "Reverse iterator points to: " << *reverse_it << "\n";
    cout << "Its base() points to: " << *(regular_from_reverse - 1) << "\n";

    /// DEletion of iterator

    /// ERASE: now let's i want to erase or delete something
    /// for deletion we can provide memory address to delete

    /// lets consider here v is {10, 20, 30, 40, 50}
    v.erase(v.begin() + 1); // output is {10, 30, 40, 50}

    /// Now if you want to delete in range, then we can provide [initial address, final address]
    /// lets consider here v is {10, 20, 30, 40, 50}
    v.erase(v.begin() + 2, v.begin() + 4); //[start, end)
    /// {10, 20, 50} ///End address we have to provide for after the delete

    /// INSERT: function
    vector<int> ins(2, 100);            // ins = {100,100}
    ins.insert(ins.begin(), 300);       //{300, 100, 100}
    ins.insert(ins.begin() + 1, 2, 20); //{300, 20, 20, 100, 100}

    // inserting one vector elements to other
    vector<int> copy(2, 50);                               //{50,50}
    ins.insert(ins.begin() + 1, copy.begin(), copy.end()); //{50,50, 300, 20, 20, 100, 100}

    /// PRINT SIZE: OF ARRAY:
    cout << ins.size(); // 7

    /// REMOVE LAST ELEMENT
    ins.pop_back(); //{50,50, 300, 20, 20, 100}

    /// SWAP: array
    /// v1---{10,20}, v2--{30,40}
    /// v1.swap(v2); //output: v2---{10,20}, v1--{30,40}

    ins.clear();         // Erases the entire array
    cout << ins.empty(); /// checks whether it is empty or not return bool

    /*
    Key Points:

    1. Iterator Types:
       - iterator: Forward iteration (begin() to end())
       - reverse_iterator: Backward iteration (rbegin() to rend())
       - These are DIFFERENT TYPES and cannot be assigned to each other

    2. Iterator Functions:
       - begin(): Points to first element
       - end(): Points PAST the last element (one position after)
       - rbegin(): Points to last element (reverse beginning)
       - rend(): Points BEFORE the first element (reverse ending)

    3. Correct Usage:
       vector<int>::iterator it = v.begin();           // ✓
       vector<int>::iterator it = v.end();             // ✓
       vector<int>::reverse_iterator rit = v.rbegin(); // ✓
       vector<int>::reverse_iterator rit = v.rend();   // ✓

    4. Wrong Usage (causes your error):
       vector<int>::iterator it = v.rbegin();          // ✗
       vector<int>::iterator it = v.rend();            // ✗

    5. Modern C++ Recommendation:
       Use 'auto' keyword to let compiler deduce the correct type:
       auto it = v.begin();    // Automatically deduces correct type
       auto rit = v.rbegin();  // Automatically deduces correct type
    */
}

void explainList()
{
    list<int> ls;
    ls.push_back(2);    //{2}
    ls.emplace_back(4); //{2,4}
    ls.push_front(5);   //{5,2,4}
    ls.emplace_front();
    // all other functions are similar to vectors
}

void explainDeQueue()
{
    deque<int> dq;

    dq.push_back(2);     //{2}
    dq.emplace_back(4);  //{2,4}
    dq.push_front(5);    //{5,2,4}
    dq.emplace_front(3); // {3,5,2,4}
    dq.pop_back();       //{3,5,2}
    dq.pop_front();      //{5,2}
    dq.back();
    dq.front();
    // all other functions are similar to vectors and list
}

void explainStack()
{

    /// stack is LAST in FIRST out
    stack<int> st;
    st.push(1);    //{1}
    st.push(2);    //{2,1}
    st.push(3);    //{3,2,1}
    st.push(3);    //{3,3,2,1}
    st.emplace(5); //{5,3,3,2,1}

    cout << st.top(); // prints 5 "st[2] is invalid for printing"
    st.pop();         //{3,3,2,1}
    st.top();         // 3
    st.size();        // 4

    stack<int> st1, st2;
    st1.swap(st2);
}

void explainQueue()
{
    /// queue is FIRST in FIRST out
    queue<int> q;
    q.push(1);    //{1}
    q.push(2);    //{1,2}
    q.emplace(4); //{1,2,4}
    q.back() += 5;
    cout << q.back();  // output 9
    cout << q.front(); // 1
    q.pop();           // q = {2,9}

    /// we can have similier operations similier a above operations
}

void explainPQ()
{
    /// priority queue is always prioritise largest value

    priority_queue<int> pq;
    pq.push(5);     //{5}
    pq.push(2);     //{5,2}
    pq.push(8);     //{8,5,2}
    pq.emplace(10); //{10,8,5,2},

    cout << pq.top(); // prints 10
    pq.pop();
    cout << pq.top(); // prints 8

    /// size, swap and other functionalities are same,

    /// This stores minimum data type at top
    /// way to maintain minimum priority queue which is know as min heap

    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(5);     //{5}
    pq.push(2);     //{2,5}
    pq.push(8);     //{2,5,8}
    pq.emplace(10); //{2,5,8,10},

    cout << pq.top(); // prints 2
    pq.pop();
    cout << pq.top(); // prints 5

    /// TIME: COMPLEXITY:
    /// PUSH: logn
    /// TOP: O(n)
    /// POP: logn
}

/// @brief SETS:
void explainSet()
{
    set<int> st;
    st.insert(1);  //{1}
    st.emplace(2); //{1,2}
    st.insert(3);  //{1,2,3}
    st.insert(4);  //{1,2,3,4}
    st.insert(3);  //{1,2,3,4}

    /// Functionality of insert in vector can also be used
    /// That only increases efficiency
    ///  All methods are applicable for set which are applicable for other containers

    /// Lets consider the following set {1,2,3,4,6,5}
    auto it = st.find(3);

    /// Lets consider the following set {1,2,3,4,6,5}
    auto it = st.find(6);

    st.erase(5); // erases 5 and takes logarithmic value

    int count = st.count(3);
    /// we can erase or delete by range as well

    st.erase(it);
}

void explainMultiSet()
{
    /// Everything is similier as set
    /// only stores duplicate elements also

    multiset<int> ms;
    ms.insert(1); //{1}
    ms.insert(1); //{1,1}
    ms.insert(1); //{1,1,1}

    int cnt = ms.count(1); // This will give the count of 1's in the set

    /// only single 1 will be erased if we do this
    ms.erase(ms.find(1)); /// find gives the memory address

    /// so multiset store the ducplicate but when erased it will erase all duplicate
    ///  things when we do not use find as shown above
    ///  Rest all properties of set are applied to the multiset
}

void exmplainUSet()
{
    unordered_set<int> uS;
    // lower_bound  and  upper_bound functions doesnot work
    // rest all functions are same as above
    /// This does not stores elements in any order,
    /// Thats why it has better time compleity O(1), than set in most cases. except when collision happens
}

/// @brief MAP:

void explainMap()
{
    /// map is key value pairs
    // keys are always unique but values can be duplicate
    /// keys can be of any datatype, also vlaue can be of any datatype
    /// Map stores uniquwe key in sorted order.
    map<int, int> mpp;
    map<int, pair<int, int>> mpp;
    map<pair<int, int>, int> mpp;

    mpp[1] = 2;
    mpp.emplace(3, 1);
    mpp.insert(2, 4);
    /// Above lines are stored as {{1,2},{2,4},{3,1}}
    mpp[2, 3] = 10;

    // Iterating through the map || Traversing through map

    for (auto it : mpp)
    {
        cout << it.first << " " << it.second << endl;
    }

    cout << mpp[1];
    cout << mpp[5];

    auto it = mpp.find(2);
    // cout<< * (it).second; //somehow * is not accepting

    auto it = mpp.upper_bound(2);
    auto it = mpp.lower_bound(3);
}

void expolainMuliMap()
{
    // All properties are same as map but only difference is we can have dupilcate keys in map
    /// only map[key] can not be assigned without map
}

void explainUnorderedMap()
{
    // elements are not ordered ijn tne sorted way.
}

/// @attention ALGORITHMS: Sorting

void explainExtra()
{
    /// if it is an array a = [2,4,8,4,8,1,9,2,0]
    int a[] = {2, 4, 8, 4, 8, 1, 9, 2, 0};
    auto n = sizeof(a) / sizeof(a[0]); // This is to get lenth of the array
    sort(a, a + n);                    // output 1 2 2 4 4 8 8 9

    /// v is an vector
    vector<int> v(1, 100); // v(5, 100) means container contains instances of  100 is decalred
    v.emplace_back(3);
    v.emplace_back(5);
    v.emplace_back(7);
    v.emplace_back(34);

    sort(v.begin(), v.end()); // Output: 100 3 5 7 34
    auto len = v.size();
    sort(a, a + n, greater<int>());

    /// Consider following pair array
    // sort is according to second element
    //  if second element is same then sort it acccording to the first element but in descending order
    pair<int, int> pa[] = {{1, 2}, {2, 1}, {4, 1}};
    auto paL = sizeof(pa) / sizeof(pa[0]);
    sort(pa, pa + paL, comp); // t

    string s = "123";
    do
    {
        /* code */
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));
    int maxi = *max_element(a, a + n);
}

bool comp(const pair<int, int> &a, const pair<int, int> &b)
{ /// This method is for comparision
    if (a.second == b.second)
        return a.first > b.first; // descending for first element
    return a.second < b.second;   // ascending for second element
}

int main()
{
    explainVectors();
    return 0;
}

/// c++ STL is divided in to 4 parts
/// 1. Algorithms
/// 2. Containers
/// 3. Functions
/// 4. Iterator

void explainPair()
{
    pair<int, int> p = {1, 5};
    cout << p.first << " " << p.second << endl; // 1 5
    // if we want to store 3 or 4 values then we can have nested pairs
    pair<int, pair<int, int>> p2 = {1, {3, 5}};
    cout << "First element " << p2.first << "Output of secidn pair " << p2.second.first << " && " << p2.second.second << endl; // 1 5First element1Output of secidn pair3&&56

    /// this is pair array
    /// pairs are lied inside utiity library if utility library is imported we can use pairs

    pair<int, int> arr[] = {{1, 3}, {3, 6}, {5, 8}};
    cout << arr[1].second; // 6
}
