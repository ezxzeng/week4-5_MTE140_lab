#ifndef A1_TESTS_HPP
#define A1_TESTS_HPP

#include "a1_doubly_linked_list2.hpp"
#include "a1_big_int.hpp"

#define ASSERT_TRUE(T) if (!(T)) return false;
#define ASSERT_FALSE(T) if ((T)) return false;

class BigIntTest
{
public:
	// Constructor with boolean list and size input
    bool test1()
    {
    	bool test_arr[3] = {true, true, true};
    	BigInt test(test_arr, 3);
	    return true;
    }

	// Constructor with string value input
    bool test2()
    {
	    return true;
    }

	// addition
    bool test3()
    {
	    return true;
    }
    
    // subtraction
    bool test4()
    {
	    return true;
    }
    
    // multipliction
    bool test5()
    {
	    return true;
    }
    
    // bitwise and
    bool test6()
    {
	    return true;
    }
    
    // bitwise or
    bool test7()
    {
	    return true;
    }
    
    // bitwise xor
    bool test8()
    {
	    return true;
    }
};


#endif
