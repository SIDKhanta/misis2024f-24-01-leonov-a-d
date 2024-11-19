#ifndef DYNAMICARRAY_HPP
#define DYNAMICARRAY_HPP

#include <stdexcept>
#include <iostream>

class dynarr {
private:
    int* data;       
    size_t size;     
    size_t capacity; 

    void resize(size_t newCapacity); 

public:
    dynarr();
    explicit dynarr(size_t initialCapacity);
    ~dynarr();

    void pushBack(int value); 
    void popBack();           
    int get(size_t index) const;   
    void set(size_t index, int value); 
    size_t getSize() const;      
    size_t getCapacity() const;  
    bool isEmpty() const;        
    void clear();                

    int& operator[](size_t index);
    const int& operator[](size_t index) const;
};

#endif
