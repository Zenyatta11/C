
#include<stdio.h>
#include<stdlib.h>

#define true 1
#define false 0

#define MENU_MAIN 1
#define MENU_PLAY 2
#define MENU_WIN 3

unsigned long int level[1][8];

void showMainMenu(int selection);
int getKeyPress();
void drawLevel(int levelNo);
unsigned long int getBitOn(unsigned long int number, int bitno);

int main() {
	

	level[0][0] = 4294967294;
	level[0][1] = 133201794 + 2147483648;
	level[0][2] = 1879375934 + 2147483648;
	level[0][3] = 536739838 + 2147483648;
	level[0][4] = 3221225478 + 2147483648;
	level[0][5] = 4286578678 + 2147483648;
	level[0][6] = 6;
	level[0][7] = 4294967294 + 2147483648;
	
	int playing = true;
	int menu = MENU_MAIN;
	int select, confirm;
	char charInput;
	
	while(playing) {
		system("CLS");
		switch(menu) {
			case MENU_MAIN:
				showMainMenu(select);
				switch(getKeyPress()) {
					case 8: if(select > 0) select = select - 1; break;
					case 2: if(select < 1) select = select + 1; break;
					case 5: if(select == 0) menu = MENU_PLAY; 
						else if(select == 1) playing = false;
						break;
				}
				break;
				
			case MENU_PLAY:
				drawLevel(0);
				break;
				
		}
	}
	
	return 0;
}

int getKeyPress() {
	fflush(stdin);
	char input = getch();
	if (input == -32) {
		switch(getch()) {
			case 72:
				return 8; // arriba
			case 80:
				return 2; // abajo
			case 77:
				return 6; // derecha
			case 75:
				return 4; // izquierda
		}
	} else {
		switch(input) {
			case 'w':
			case 'W':
				return 8; // arriba
			case 's':
			case 'S':
				return 2; // abajo
			case 'd':
			case 'D':
				return 6; // derecha
			case 'a':
			case 'A':
				return 4; // izquierda
			case 13:
				return 5; // enter
		}
	}
}

void showMainMenu(int selection) {
	printf("\n\tM A Z E - G A M E\n\n\t%s\n\t%s\n", (selection == 0 ? "[PLAY]" : " PLAY "), (selection == 0 ? " QUIT " : "[QUIT]"));
}

void drawLevel(int levelNo) {
	int i, levelRow;
	for(levelRow = 0; levelRow < 8; levelRow = levelRow + 1) {
		printf("\n\t");
		for(i = 0; i < 32; i = i + 1) {
			if(getBitOn(level[levelNo][levelRow], 30-i)) {
				printf("X");
			} else printf(" ");
		}
	}
}

unsigned long int getBitOn(unsigned long int number, int bitno) {
	switch(bitno) {
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
		case 0: return number & 1;
	}
	return 0;
}