
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#include "util.cc"

/*
	Multiples of 3 and 5
	Problem 1

	If we list all the natural numbers below 10 that are multiples of 3 or 5,
	we get 3, 5, 6 and 9. The sum of these multiples is 23.

	Find the sum of all the multiples of 3 or 5 below 1000.
*/
void problem1 () {
	int sum = 0;
	for (int i = 0; i < 1000; ++i) {
		if (i % 3 == 0 || i % 5 == 0) {
			sum += i;
		}
	}

	printf("sum %i", sum);
}

/*
	Even Fibonacci numbers
	Problem 2

	Each new term in the Fibonacci sequence is generated by adding the previous two terms.
	By starting with 1 and 2, the first 10 terms will be:
	1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

	By considering the terms in the Fibonacci sequence whose values do not exceed four million,
	find the sum of the even-valued terms.
*/
void problem2 () {
	int fib1 = 1;
	int fib2 = 2;
	int sum = 2;
	while (true/*fib2 < 4000000*/) {
		int temp = fib2;
		fib2 = fib1 + fib2;
		fib1 = temp;
		// printf("fib %i \n", fib2);

		if (fib2 < 4000000) {
			if (fib2 % 2 == 0) {
				sum += fib2;
			}
		} else {
			break;
		}
	}

	printf("sum %i", sum);
}

/*
	Largest prime factor
	Problem 3

	The prime factors of 13195 are 5, 7, 13 and 29.

	What is the largest prime factor of the number 600851475143 ?
*/
void problem3 () {
	printf("calculating... \n");

	int64_t lastFactor = 0;
	int64_t number = 600851475143;
	/*for (int64_t i = 2; i < number; ++i) {
		if (number % i == 0 && isPrime(i)) {
			lastFactor = i;
			printf("prime factor %lli \n", lastFactor);
		}
	}*/
	/*for (int64_t i = number-1; i > 1; --i) {
		if (number % i == 0) {
			printf("checking %lli... \n", i);
			if (isPrime(i)) {
				lastFactor = i;
				printf("prime factor %lli \n", lastFactor);
				break;
			} else {
				printf("%lli isn't prime \n", i);
			}
		}
	}*/
	int64_t divider = 2;
	while (true) {
		int64_t check = number / divider;
		if (number % (check) == 0) {
			printf("checking %lli... ", check);
			if (isPrime(check)) {
				printf("prime factor %lli \n", check);
				break;
			} else {
				printf("%lli isn't prime \n", check);
			}
		}

		++divider;
	}

	/*for (int i = 2; i < 1000; ++i) {
		if (isPrime(i)) {
			printf("prime %i \n", i);
		}
	}*/
}

/*
	Smallest multiple
	Problem 5

	2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
	What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/
void problem5 () {
	int num = 20;
	while (true) {
		bool divisible = true;
		for (int i = 1; i <= 20; ++i) {
			if (num % i != 0) {
				divisible = false;
				break;
			}
		}

		if (divisible) {
			printf("result %i", num);
			break;
		}

		// ++num;
		num += 20; // optimisation
	}
}

/*
	Sum square difference
	Problem 6

	The sum of the squares of the first ten natural numbers is,
	1^2 + 2^2 + ... + 10^2 = 385
	The square of the sum of the first ten natural numbers is,
	(1 + 2 + ... + 10)^2 = 55^2 = 3025
	Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.
	Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/
void problem6 () {
	int sumOfSquares = 0;
	int squareOfSum = 0;
	for (int i = 1; i <= 100; ++i) {
		sumOfSquares += i*i;
		squareOfSum += i;
	}
	squareOfSum *= squareOfSum;

	printf("sumOfSquares %i \n", sumOfSquares);
	printf("squareOfSum %i \n", squareOfSum);
	int result = squareOfSum - sumOfSquares;
	printf("result %i", result);
}

/*
	10001st prime
	Problem 7

	By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
	What is the 10 001st prime number?
*/
void problem7 () {
	int i = 1;
	int64_t lastPrime = 0;
	int64_t currentNumber = 2;
	while (i <= 10001) {
		if (isPrime(currentNumber)) {
			printf("prime %i %lli \n", i, currentNumber);
			lastPrime = currentNumber;
			++i;
		}
		++currentNumber;
	}

	printf("result %lli", lastPrime);
}

/*
	Largest product in a series
	Problem 8

	The four adjacent digits in the 1000-digit number that have the greatest product are 9 × 9 × 8 × 9 = 5832.
	73167176531330624919225119674426574742355349194934
	96983520312774506326239578318016984801869478851843
	85861560789112949495459501737958331952853208805511
	12540698747158523863050715693290963295227443043557
	66896648950445244523161731856403098711121722383113
	62229893423380308135336276614282806444486645238749
	30358907296290491560440772390713810515859307960866
	70172427121883998797908792274921901699720888093776
	65727333001053367881220235421809751254540594752243
	52584907711670556013604839586446706324415722155397
	53697817977846174064955149290862569321978468622482
	83972241375657056057490261407972968652414535100474
	82166370484403199890008895243450658541227588666881
	16427171479924442928230863465674813919123162824586
	17866458359124566529476545682848912883142607690042
	24219022671055626321111109370544217506941658960408
	07198403850962455444362981230987879927244284909188
	84580156166097919133875499200524063689912560717606
	05886116467109405077541002256983155200055935729725
	71636269561882670428252483600823257530420752963450
	Find the thirteen adjacent digits in the 1000-digit number that have the greatest product. What is the value of this product?
*/
void problem8 () {
	int64_t result = 0;
	const char *longNumber = "73167176531330624919225119674426574742355349194934"
							 "96983520312774506326239578318016984801869478851843"
							 "85861560789112949495459501737958331952853208805511"
							 "12540698747158523863050715693290963295227443043557"
							 "66896648950445244523161731856403098711121722383113"
							 "62229893423380308135336276614282806444486645238749"
							 "30358907296290491560440772390713810515859307960866"
							 "70172427121883998797908792274921901699720888093776"
							 "65727333001053367881220235421809751254540594752243"
							 "52584907711670556013604839586446706324415722155397"
							 "53697817977846174064955149290862569321978468622482"
							 "83972241375657056057490261407972968652414535100474"
							 "82166370484403199890008895243450658541227588666881"
							 "16427171479924442928230863465674813919123162824586"
							 "17866458359124566529476545682848912883142607690042"
							 "24219022671055626321111109370544217506941658960408"
							 "07198403850962455444362981230987879927244284909188"
							 "84580156166097919133875499200524063689912560717606"
							 "05886116467109405077541002256983155200055935729725"
							 "71636269561882670428252483600823257530420752963450";
	int longNumberLen = strlen(longNumber);
	for (int i = 0; i < longNumberLen - 13; ++i) {
		int64_t sum = 0;
		for (int j = 0; j < 13; ++j) {
			char digit[2] = { longNumber[i+j], 0 };
			int num = atoi(digit);
			if (sum == 0) {
				sum += num;
			} else {
				sum *= num;
			}
		}

		if (sum > result) {
			result = sum;
		}
		// printf("sum %i = %lli \n", i, sum);
	}

	printf("result %lli", result);
}

int main () {
	// int number = 0.0f;
	// printf("hello world \n");

	// problem1();
	// problem2();
	// problem3();

	// problem5();
	// problem6();
	// problem7();
	problem8();

	printf("\n");
}