#include "test/test.h"
#include "lib/security.h"
#include "test/clocktime.h"
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL)); 

    TEST_SECTION(modpow_naive);
    TEST(modpow_naive(3, 3, 11), 5);
    TEST(modpow_naive(2, 10, 69), 58);
    TEST_SECTION_END();

    TEST_SECTION(modpow);
    TEST(modpow(17, 1, 18), 17);
    TEST(modpow(3, 2, 8), 1);
    TEST(modpow(3, 3, 1000), 27);
    TEST(modpow(3, 4, 10000), 81);
    TEST(modpow(2, 10, 10000), 1024);
    TEST(modpow(3, 3, 11), 5);
    TEST(modpow(2, 10, 69), 58);
    TEST(modpow(1147, 10, 9442), 3439);
    TEST(modpow(1147, 11, 9442), 7219);
    TEST_SECTION_END();
    
    TEST_SECTION(modpow_r);
    TEST(modpow_r(0, 3, 11), 0);
    TEST(modpow_r(3, 3, 11), 5);
    TEST(modpow_r(2, 10, 69), 58);
    TEST_SECTION_END();

    TEST_SECTION(is_prime_naive);
    TEST(is_prime_naive(7), true);
    TEST(is_prime_naive(248389), true);
    TEST(is_prime_naive(248389 + 2), false);
    TEST_SECTION_END();
    
    TEST_SECTION(is_prime_miller);
    TEST(is_prime_miller(7, 5), true);
    TEST(is_prime_miller(248389, 5), true);
    TEST(is_prime_miller(248389 + 2, 5), false);
    TEST_SECTION_END();

    TEST_SECTION(random_prime_number);
    TEST(is_prime_miller(random_prime_number(24, 26, 100), 500), true);
    TEST(is_prime_miller(random_prime_number(10, 18, 100), 500), true);
    TEST(is_prime_miller(random_prime_number(31, 31, 100), 500), true);
    TEST_SECTION_END();

    { 
        TEST_SECTION(extended_gcd);
        int64 u, v;
        TEST(extended_gcd(69, 42, &u, &v), 3);
        TEST(69*u + 42*v, 3);
        TEST(extended_gcd(6964, 4216, &u, &v), 4);
        TEST(6964*u + 4216*v, 4);
        TEST(extended_gcd(12345, 543, &u, &v), 3);
        TEST(12345*u + 543*v, 3);
        TEST(extended_gcd(6417, 6424, &u, &v), 1);
        TEST(6417*u + 6424*v, 1);
        TEST(extended_gcd(42, 42, &u, &v), 42);
        int i;
        for(i=0; i<5; i++){
            int64 p = random_prime_number(15, 16, 500);
            int64 q = random_prime_number(15, 16, 500);

            TEST(extended_gcd(p, q, &u, &v), 1);
            TEST(p*u + q*v, 1);
        }
        TEST_SECTION_END();
    }

    TEST_SUMMARY(); 
}