#include<stdio.h>


unsigned long long int exp(int exponent);

void nuke(char string[]);

int main() {
	printf("1234567891234567892123456789312\n%d\n", sizeof(long long int));
	int i, lvl;
	for(i = 0; i < 64; i = i + 1) {
		printf("%llu\n", exp(63-i));
	}
	
	char string[32];
	unsigned long int level[16];
	unsigned long int output;
	
	lvl = 0;
	while(1) {
		output = 0;
		fflush(stdin);
		
		nuke(string);
		gets(string);
		
		for(i = 0; i < 32; i = i + 1) {
			if(string[i] != ' ') output = output + exp(32-i);
			
		}
		level[lvl] = output;
		lvl = lvl + 1;
		if(lvl == 15) {
			for(i = 0; i < 15; i = i + 1) {
				printf("%lu, ", level[i]);
			}
			while(1);
		}
	}
	return 0;
}

unsigned long long int exp(int exponent) {
	unsigned long long int retVal;
	int i;
	retVal = 1;
	for(i = 0; i < exponent; i = i + 1) {
		retVal = retVal * 2;
	}
	return retVal;
}

void nuke(char string[]) {
	int i;
	for(i = 0; i < 32; i = i + 1) {
		string[i] = ' ';
	}
}


int getBitOn(unsigned long int number, bitno) {
	switch(bitno) {
		case 63: return number & 9223372036854775808;
		case 62: return number & 4611686018427387904;
		case 61: return number & 2305843009213693952;
		case 60: return number & 1152921504606846976;
		case 59: return number & 576460752303423488;
		case 58: return number & 288230376151711744;
		case 57: return number & 144115188075855872;
		case 56: return number & 72057594037927936;
		case 55: return number & 36028797018963968;
		case 54: return number & 18014398509481984;
		case 53: return number & 9007199254740992;
		case 52: return number & 4503599627370496;
		case 51: return number & 2251799813685248;
		case 50: return number & 1125899906842624;
		case 49: return number & 562949953421312;
		case 48: return number & 281474976710656;
		case 47: return number & 140737488355328;
		case 46: return number & 70368744177664;
		case 45: return number & 35184372088832;
		case 44: return number & 17592186044416;
		case 43: return number & 8796093022208;
		case 42: return number & 4398046511104;
		case 41: return number & 2199023255552;
		case 40: return number & 1099511627776;
		case 39: return number & 549755813888;
		case 38: return number & 274877906944;
		case 37: return number & 137438953472;
		case 36: return number & 68719476736;
		case 35: return number & 34359738368;
		case 34: return number & 17179869184;
		case 33: return number & 8589934592;
		case 32: return number & 4294967296;
		case 31: return number & 2147483648;
		case 30: return number & 1073741824;
		case 29: return number & 536870912;
		case 28: return number & 268435456;
		case 27: return number & 134217728;
		case 26: return number & 67108864;
		case 25: return number & 33554432;
		case 24: return number & 16777216;
		case 23: return number & 8388608;
		case 22: return number & 4194304;
		case 21: return number & 2097152;
		case 20: return number & 1048576;
		case 19: return number & 524288;
		case 18: return number & 262144;
		case 17: return number & 131072;
		case 16: return number & 65536;
		case 15: return number & 32768;
		case 14: return number & 16384;
		case 13: return number & 8192;
		case 12: return number & 4096;
		case 11: return number & 2048;
		case 10: return number & 1024;
		case 9: return number & 512;
		case 8: return number & 256;
		case 7: return number & 128;
		case 6: return number & 64;
		case 5: return number & 32;
		case 4: return number & 16;
		case 3: return number & 8;
		case 2: return number & 4;
		case 1: return number & 2;
		case 0: return number & 1
	}
}