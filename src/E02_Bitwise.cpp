//
//  E02_Bitwise.cpp
//  Unit1_exercise2_understanding_bitwise
//

/*
 
 Note:
 Implement the functions in this exercise file to make the tests
 pass in E02_BitwiseSpec.cpp file.
 
 Your primary goal is to implement all these functions by using
 bitwise operators only.
 
 */

int andOfEachByte(int n) {
	int  p, q, r, result;
	int byte3, byte2, byte1, byte0;
	byte3 = n >> 24;
	byte3 = byte3 & 0xFF;
	p = n << 8;
	byte2 = p >> 24;
	byte2 = byte2 & 0xFF;
	q = n >> 8;
	byte1 = q & 0xFF;
	byte0 = n & 0xFF;
	result = byte3 & byte2 & byte1 & byte0;
    return result;
}

//
// Note1:
// implement the function using bitwise operators only
// should not use * and + operators.
int numberFromBits(int bits[32]) {
	int i, j, out = 0, power[32], p;
	for (i = 0;i < 32;i++) {
		power[i] = 1;
	}
	for (i = 31;i > 0;i--) {
		j = i;
		while (j != 0) {
			power[i] = 2 * power[i];
			j--;
		}
	}
	power[0] = 1;
	for (i = 31;i >= 0;i--) {
		out = out + bits[i] * power[31 - i];
	}
    return out;
}

//
// Note2:
// implement the function using bitwise operators only
// should not use % and / operators.
void bitsFromNumber(int n, int bits[32]) {
	int i = 0;
	int bits1[32];
	while (n != 0) {
		bits1[i] = n % 2;
		n = n / 2;
		i++;
	}
	bits1[i] = n;
	i++;
	for (i = i;i < 32;i++) {
		bits1[i] = 0;
	}
	for (i = 0; i < 32; i++) {
		bits[i] = bits1[32 - i - 1];
	}
}

//
// Note3:
// Refer this to understand how numbers are represented in binary format
// https://www.youtube.com/watch?v=qrUjFtZZWf4
// mainly how negative number are represented.
//
// implement this function by calling above bitsFromNumber function only.
//
int numberOfOnesInBinary(int n) {
	int i =0, count=0;
	int bits;
	while (n != 0) {
		bits = n % 2;
		if (bits == 1) {
			count++;
		}
		n = n / 2;
		i++;
	}
	if (n == 1) {
		count++;
	}
    return count;
}

//
// Returns
//  1 - yes
//  0 - no
//
int isPalindromeInBase256(unsigned long int n) {
	int i = 0,count,p;
	int bits[32];
	while (n != 0) {
		bits[i] = n % 2;
		n = n / 2;
		i++;
	}
	bits[i] = n;
	count = i;
	i = 0;
	while (i<=count) {
		if (bits[count - i - 1] == bits[i]) {
			p++;
		}
		i++;
	}
	if (p = count) {
		return 1;
	}
	else {
		return 0;
	}
}
