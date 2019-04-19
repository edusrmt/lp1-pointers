#include "../include/graal.h"

namespace graal {
    const void * min (void *first,  void *last, size_t size, Compare cmp) {
        const byte *firstPtr = (const byte *)first;
        const void *min = firstPtr;
        firstPtr += size;
        
        while (firstPtr != last) {
            if (cmp(firstPtr, min))
                min = firstPtr;

            firstPtr += size;
        }

        return min;
    }

    void reverse (void *first, void *last, size_t size){ }

    void * copy (const void *first, const void *last, const void *d_first, size_t size){ return nullptr;}

    void * clone (const void *first, const void *last, size_t size){ return nullptr;}

    const void * find_if (const void *first, const void *last, size_t size, Predicate p){ return nullptr;}

    const void * find (const void *first, const void *last, size_t size, const void *value, Equal eq){ return nullptr;}

    bool all_of (const void *first, const void *last, size_t size, Predicate p){ return false;}
    
    bool any_of (const void *first, const void *last, size_t size, Predicate p){ return false;}
    
    bool none_of (const void *first, const void *last, size_t size, Predicate p){ return false;}

    bool equal (const void *first1, const void *last1, const void *first2, size_t size, Equal eq){return false; }

    bool equal (const void *first1, const void *last1, const void *first2, const void *last2, size_t size, Equal eq){ return false;}

    void * unique (const void *first, const void *last, size_t size, Equal eq){return nullptr; }

    void * partition (const void *first, const void *last, size_t size, Predicate p){return nullptr; }

    void qsort (void *first, int distance, size_t size, Compare cmp){ }

/*
    void reverse (void *first, void *last, size_t size) {
        const byte *lastPtr = (const byte *)last;
        --lastPtr;

        const byte *firstPtr = (const byte *)first;
        --firstPtr;

        while (first < last) {
            std::swap(*firstPtr, *lastPtr);
            ++firstPtr;
            --lastPtr;
        }
    }*/
}