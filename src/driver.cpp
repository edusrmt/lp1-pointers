#include <iostream>
#include <iterator>

#include "../include/graal.h"

using namespace std;

bool INT_sort_comp( const void *a, const void *b ){
    const int * m_a = static_cast< const int * >(a);
    const int * m_b = static_cast< const int * >(b);

    return *m_a < *m_b;
}

bool CHAR_sort_comp( const void *a, const void *b ){
    const char * m_a = static_cast< const char * >(a);
    const char * m_b = static_cast< const char * >(b);

    return *m_a < *m_b;
}

int main () {
    int A[]= { 1, 2, 3, 4, 0 };

    auto ptr = (const int *) graal::min( std::begin(A), std::end(A), sizeof(int), INT_sort_comp);

    for (int e : A) {
        cout << e << " ";
    }
    cout << endl;

    cout << *(int *)ptr << endl;

    return 0;
}