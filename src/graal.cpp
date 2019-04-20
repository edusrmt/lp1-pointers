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

    void reverse (void *first, void *last, size_t size) {
        byte *firstPtr = (byte *)first;
        byte *lastPtr = (byte *)last;
        lastPtr -= size;

        while (firstPtr < lastPtr) {
            std::swap(*firstPtr, *lastPtr);
            firstPtr += size;
            lastPtr -= size;
        }
    }

    void * copy (const void *first, const void *last, const void *d_first, size_t size){ 
        const byte *firstPtr = (const byte *)first;
        byte *d_firstPtr = (byte *)d_first;
        
        while(firstPtr != last) {
            *d_firstPtr = *firstPtr;
            d_firstPtr += size;
            firstPtr += size;
        }

        return (void *)d_firstPtr;
    }

    void * clone (const void *first, const void *last, size_t size){  
        int arraySize = std::distance((byte *)first, (byte *)last) / size;
        const void *d_first = calloc(arraySize, size);
        copy(first, last, d_first, size);

        return (void *)d_first;
    }

    const void * find_if (const void *first, const void *last, size_t size, Predicate p){
        const byte *firstPtr = (const byte *)first;

        while(firstPtr != last){
            if (p((const void *)firstPtr))
                return (const void *)firstPtr;
            
            firstPtr += size;
        }       

        return last;        
    }

    const void * find (const void *first, const void *last, size_t size, const void *value, Equal eq) {
        const byte *firstPtr = (const byte *)first;

        while(firstPtr != last){
            if (eq((const void *)firstPtr, value))
                return (const void *)firstPtr;
            
            firstPtr += size;
        }       

        return last;  
    }

    bool all_of (const void *first, const void *last, size_t size, Predicate p){
        const byte *firstPtr = (const byte *)first;

        while(firstPtr != last){
            if (!p((const void *)firstPtr))
                return false;
            
            firstPtr += size;
        }       

        return true;
    }
    
    bool any_of (const void *first, const void *last, size_t size, Predicate p){
        const byte *firstPtr = (const byte *)first;

        while(firstPtr != last){
            if (p((const void *)firstPtr))
                return true;
            
            firstPtr += size;
        }       

        return false;
    }
    
    bool none_of (const void *first, const void *last, size_t size, Predicate p){
        const byte *firstPtr = (const byte *)first;

        while(firstPtr != last){
            if (p((const void *)firstPtr))
                return false;
            
            firstPtr += size;
        }       

        return true;
    }

    bool equal (const void *first1, const void *last1, const void *first2, size_t size, Equal eq){
        const byte *first1Ptr = (const byte *)first1;
        const byte *first2Ptr = (const byte *)first2;
        
        while(first1Ptr != last1) {
            if(!eq((const void*)first1Ptr, (const void *)first2Ptr))
                return false;

            first1Ptr += size;
            first2Ptr += size;
        }

        return true;
    }

    bool equal (const void *first1, const void *last1, const void *first2, const void *last2, size_t size, Equal eq){
        return equal(first1, last1, first2, size, eq);
    }

    void * unique (const void *first, const void *last, size_t size, Equal eq){
        byte *firstPtr = (byte *)first;
        byte *newLast = firstPtr;

        while (firstPtr != last) {
            if(find(first, (const void *)newLast, size, (const void *)firstPtr, eq) == (const void *)newLast) {
                *newLast = *firstPtr;
                newLast += size;
            }

            firstPtr += size;
        }

        return (void *)newLast;
    }

    void * partition (const void *first, const void *last, size_t size, Predicate p){
        byte *left = (byte *)first;
        byte *mid = (byte *)last;
        mid = left;

        while(left != last){
            if (p(((const void *)left))) {
                std::swap(*left, *mid);
                mid += size;
            } 

            left += size;
        }

        return (void *)mid;
    }

    void qsort (void *first, int distance, size_t size, Compare cmp){
        size_t arraySize = distance * size;

        byte *firstPtr = (byte *)first;
        byte *lastPtr = firstPtr + arraySize;

        while (firstPtr != lastPtr) {
            const void *min = graal::min(firstPtr, lastPtr, size, cmp);
            std::swap(*((byte *)min), *firstPtr);
            firstPtr += size;
        }
    }
}