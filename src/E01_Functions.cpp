//
//  E01_Functions.cpp
//  Unit1_exercise1_understanding_functions
//

/*
 
 Note:
 Implement the functions in this exercise file to make the tests
 pass in E01_FunctionsSpec.cpp file.
 
 */


//
// Note:
//  Think of all the edge cases.
//
// returns the mid-point of
// given 2 points on X-axis
//
int midPoint(int x1, int x2) {
	int midpoint=x2-x1;
	midpoint = x1+midpoint/2;
	//printf("%x", midpoint);
    return midpoint;
}

//
// sum of most significant digits of non-negative integers.
//
int sumOfMSDs(int num1, int num2) {
	int sum;
	while (num1 >= 10) {
		num1 = num1 / 10;
	}
	while (num2 >= 10) {
		num2 = num2 / 10;
	}
	sum = num1 + num2;
    return sum;
}

//
// sum of two 100 digit positive numbers
//
void sumOf100DigitNumbers(int num1[100], int num2[100], int sum[101]) {
	int k = 0, j=100,p;
	for (int i = 99; i>=0; i--) {
		p = k + num1[i] + num2[i];
		if (p > 9) {
			sum[j] = p % 10;
			k = p / 10;
		}
		else {
			sum[j] = p;
			k = 0;
		}
		j--;
	}
    sum[0] = k;
}

//
// product of two 100 digit positive numbers
//
void productOf100DigitNumbers(int num1[100], int num2[100], int prod[200]) {
	int i, j, length = 200, l, p, k = 0;
	int out[200];
	for (i = 0;i < 200;i++) {
		prod[i] = 0;
	}
	for (i = 99;i >= 0;i--) {
		l = --length;
		for (j = 99;j >= 0;j--) {
			p = k + num1[i] * num2[j] + prod[l];
			if (p > 9) {
				prod[l] = p % 10;
				k = p / 10;
				l--;
			}
			else {
				prod[l] = p;
				k = 0;
				l--;
			}
		}
		prod[l] = k;
		k = 0;
	}
}
