//
// Created by MEHDI on 18/10/2024.
//

#include <iostream>
#include <queue>
#include <stack>
#include <cctype>
#include <cstring>
using namespace std ;
bool isPalindrome ( const string& input ) {
    size_t n = input.size( );

    int stack_size = n/2;
    stack<char> s;
    int queue_size = n/2;
    queue<char> q;

    for (char c : input) {
        if (std::isalnum(c)) {
            char lowercase = std::tolower(c);
            s.push(lowercase);
            q.push(lowercase);
        }
    }

    while (!s.empty() && !q.empty()) {
        if (s.top() != q.front()) {
            return false;
        }
        s.pop();
        q.pop();
    }

    return true;

}


int main ( ) {
    cout << boolalpha ;
    cout << " Is ’racecar’ a palindrome ?   "
    << isPalindrome ( "racecar" ) << endl ;

    cout << " Is ’hello’ a palindrome ?   "
<< isPalindrome ( "hello" ) << endl ;
    return 0 ;
}
