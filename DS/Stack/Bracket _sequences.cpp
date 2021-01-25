/*

Link:-   
https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/bracket-sequence-1-40eab940/description/

-------------------------------------------------------------------------------------------
nput format:-
The single line contains sequence s.
|s|<= 5*10^5

Output format :-
Print the number of shifts denoting the correct bracket sequence.

Example:-
1.
    )()()(  => ()()()  ,  ()()()  ,  ()()()     ----> output: 3
    012345     501234     345012     123450

2.
    ()(())()()  ----> output: 4

3.
    )()))()   -----> output: 0

----------------------------------------------------------------------------------------------
solution:-

time complexity:- O(n)
Data structure used :- Stack

approach=> 

--> if n('(') != n(')')  , then string can't be balanced for any combination

let the sequence is S1,S2,S3,....Sn
balanced sequence is Si,Si+1,....Sn,S1,S2,...Si-1

--> find the Si
--> build the balanced string
--> find number of substring which are balanced
*/
#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
using namespace std;
int main()
{
    string str;
    cin>>str;
    if(count(str.begin(),str.end(),'(')!=count(str.begin(),str.end(),')'))
    {
        cout<<0;
        return 0;
    }
    int l;
    l=str.size();
    int prev=l;
    stack<char> s;
    for(int j=l-1;j>=0;j--)
    {
        if(s.empty() && str[j]=='(')
        {
            prev=j;
            continue;
        }
        if(str[j]==')')
        s.push(')');
        else
        s.pop();

    }
    if(prev!=l )
    str=str.substr(prev,l-prev)+str.substr(0,prev);
    while(!s.empty())
    s.pop();
    int cnt=0;
    for(char ch : str)
    {
        if(ch=='(')
        s.push('(');
        else
        {
            s.pop();
            if(s.empty())
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}