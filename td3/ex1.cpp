//
// Created by MEHDI on 18/10/2024.
//

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <ctime>


using namespace std ;
void countFrequencyBruteForce ( const vector<int>& numbers ) {

    vector<int> visited_elems;

    for ( size_t i = 0; i < numbers.size ( ) ; i++ ) {
        if ( find ( visited_elems.begin ( ) , visited_elems.end ( ) , numbers [ i ] ) != visited_elems.end ( ) ) {
            continue;
        }

        int count = 1;
        for ( size_t j = i + 1; j < numbers.size ( ) ; j++ ) {
            if ( numbers [ i ] == numbers [ j ] ) {
                count++;
            }
        }
        //cout << numbers [ i ] << " : " << count << " times " << endl ;
        visited_elems.push_back ( numbers [ i ] );
    }
}
map<int , int> countFrequencyOptimal ( const vector<int>& numbers ) {
    map<int , int> frequencyMap;
    for ( const auto& number : numbers ) {
        frequencyMap [ number ]++;


    }
    return frequencyMap;
}
int main ( ) {
    // random big numbe array
    int array_size = 1000000;
    vector<int> numbers  = vector<int> ( array_size );
    for ( int i = 0; i < array_size; i++ ) {
        numbers [ i ] = rand ( ) % 1000;
    }
    // Test countFrequencyBruteForce
    cout << " Frequency   ( Brute Force ) : " << endl ;

    const clock_t bruteforce_begin_time = clock();
    countFrequencyBruteForce ( numbers ) ;
    std::cout << "bruteforce time:" << float( clock () - bruteforce_begin_time ) /  CLOCKS_PER_SEC;


    // Test countFrequencyOptimal
    cout << "\nFrequency ( Optimal ) : " << endl ;

    const clock_t optimal_begin_time = clock();
    map<int , int> frequencyMapOptimal = countFrequencyOptimal ( numbers ) ;
    std::cout << "optimal time:" << float( clock () - optimal_begin_time ) /  CLOCKS_PER_SEC;

    std::cout << float( clock () - bruteforce_begin_time ) /  CLOCKS_PER_SEC;

    return 0 ;
}