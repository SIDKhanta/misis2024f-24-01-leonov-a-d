#include <arrayd/arrayd.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest/doctest.h"

TEST_CASE("[dynarr] - Constructors and Basic Properties") {
    dynarr arr;

    CHECK(arr.getSize() == 0);         
    CHECK(arr.isEmpty() == true);      
    CHECK(arr.getCapacity() == 0);     

    dynarr arr2(5);
    CHECK(arr2.getSize() == 0);        
    CHECK(arr2.getCapacity() == 5);     
    CHECK(arr2.isEmpty() == true);
}

TEST_CASE("[dynarr] - pushBack and popBack") {
    dynarr arr;

    arr.pushBack(10);
    CHECK(arr.getSize() == 1);        
    CHECK(arr[0] == 10);                
    CHECK(arr.getCapacity() >= 1);      

    arr.pushBack(20);
    CHECK(arr.getSize() == 2);         
    CHECK(arr[1] == 20);              

    arr.popBack();
    CHECK(arr.getSize() == 1);          
    CHECK(arr[0] == 10);                

    arr.popBack();
    CHECK(arr.isEmpty() == true);       

    CHECK_THROWS_AS(arr.popBack(), std::out_of_range); 
}

TEST_CASE("[dynarr] - Access Operators") {
    dynarr arr;
    arr.pushBack(5);
    arr.pushBack(15);

    CHECK(arr[0] == 5);                
    CHECK(arr[1] == 15);                

    arr[0] = 10;
    CHECK(arr[0] == 10);                 
    CHECK(arr[1] == 15);                 

    CHECK_THROWS_AS(arr[2], std::out_of_range); 
}

TEST_CASE("[dynarr] - resize and clear") {
    dynarr arr;

    arr.pushBack(1);
    arr.pushBack(2);
    arr.pushBack(3);

    CHECK(arr.getSize() == 3);
    CHECK(arr.getCapacity() >= 3);

    arr.clear();
    CHECK(arr.getSize() == 0);          
    CHECK(arr.isEmpty() == true);

    arr.pushBack(42);
    CHECK(arr.getSize() == 1);         
    CHECK(arr[0] == 42);                 
}
