// TextToBraille.cpp  By: Dax Amburgy Start date: 12/11/21

//this is a converter that asks a user for an input string, then converts that string into a sentence in braille (specifically class 1 braille)
// it will also accept file names so a user can read in a file and convert it to braille
//class 2 braille will come after the project works
//as by suggestion, this will eventually allow for output files that could potentially be 3d printable, but we are just going to stick to
//getting the arrays to display for now
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//function prototypes
/**
displayChar: function for displaying the character. Uses a nested for loop for displaying each 2D array
@param character - a 2D array that holds one braille character
@param row - the X dimention of the array. 
@param col - the Y dimention of the array.
*/
void displayChar(char character[][2], int row, int col);
/**
textConvert: takes what the user gave as input and converts it to its braille counterpart

*/
void textConvert(char currentLetter, int row, int col);

const int COL = 2;
const int ROW = 3;
char a[3][2]{
	{'*',' '},
	{' ',' '},
	{' ',' '}
};
char b[3][2]{
	{'*',' '},
	{'*',' '},
	{' ',' '}
};
char c[3][2]{
	{'*','*'},
	{' ',' '},
	{' ',' '}
};
char d[3][2]{
	{'*','*'},
	{' ','*'},
	{' ',' '}
};
char e[3][2]{
	{'*',' '},
	{' ','*'},
	{' ',' '}
};
char f[3][2]{
	{'*','*'},
	{'*',' '},
	{' ',' '}
};
char g[3][2]{
	{'*','*'},
	{'*','*'},
	{' ',' '}
};
char h[3][2]{
	{'*',' '},
	{'*','*'},
	{' ',' '}
};
char i[3][2]{
	{' ','*'},
	{'*',' '},
	{' ',' '}
};
char j[3][2]{
	{' ','*'},
	{'*','*'},
	{' ',' '}
};
char k[3][2]{
	{'*',' '},
	{' ',' '},
	{'*',' '}
};
char l[3][2]{
	{'*',' '},
	{'*',' '},
	{'*',' '}
};
char m[3][2]{
	{'*','*'},
	{' ',' '},
	{'*',' '}
};
char n[3][2]{
	{'*','*'},
	{' ','*'},
	{'*',' '}
};
char o[3][2]{
	{'*',' '},
	{' ','*'},
	{'*',' '}
};
char p[3][2]{
	{'*','*'},
	{'*',' '},
	{'*',' '}
};
char q[3][2]{
	{'*','*'},
	{'*','*'},
	{'*',' '}
};
char r[3][2]{
	{'*',' '},
	{'*','*'},
	{'*',' '}
};
char s[3][2]{
	{' ','*'},
	{'*',' '},
	{'*',' '}
};
char t[3][2]{
	{' ','*'},
	{'*','*'},
	{'*',' '}
};
char u[3][2]{
	{'*',' '},
	{' ',' '},
	{'*','*'}
};
char v[3][2]{
	{'*',' '},
	{'*',' '},
	{'*','*'}
};
char w[3][2]{
	{' ','*'},
	{'*','*'},
	{' ','*'}
};
char x[3][2]{
	{'*','*'},
	{' ',' '},
	{'*','*'}
};
char y[3][2]{
	{'*','*'},
	{' ','*'},
	{'*','*'}
};
char z[3][2]{
	{'*',' '},
	{' ','*'},
	{'*','*'}
};
//put in front of a word to make the first letter capital, put two to make every letter capital
char CapitalLetter[3][2]{
	{' ',' '},
	{' ',' '},
	{' ','*'}
};

//This next section is punctuation
char period[3][2]{
	{' ',' '},
	{'*','*'},
	{' ','*'}
};
char questionMark[3][2]{
	{' ',' '},
	{'*',' '},
	{'*','*'}
};
char exclamationMark[3][2]{
	{' ',' '},
	{'*','*'},
	{'*',' '}
};
char comma[3][2]{
	{' ',' '},
	{'*',' '},
	{' ',' '}
};

//braille numbers are made by using this sign then the letters a through j after it
// 10 would be aj because number sign a = 1 and then tag a j to add the 0
// 15 would be ae because number sign a = 1 and then tag an e for the 5
// this goes for every number up to infinity
char numberSign[3][2]{
	{' ','*'},
	{' ','*'},
	{'*','*'}
};

//make sure that spaces are accounted for
char space[3][2]{
	{' ',' '},
	{' ',' '},
	{' ',' '}
};

//main code
int main()
{
	string sentence;

	cout << "What would you like to say? ";
	getline(cin, sentence);
	cout << "OK, if im hearing you corectly, you want to say: " << sentence << endl;
	cout << "Here it is in braille: " << endl;

	for (int i = 0; i < sentence.length(); i++) {
		char currentChar = sentence[i];
		textConvert(currentChar, ROW, COL);
		cout << endl;
	}
	
}

//end of line

void displayChar(char character[][2], int row, int col)
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << character[i][j];
		}
		cout << endl;
	}
}

void textConvert(char currentLetter, int row, int col)
{
	switch (currentLetter) {
		case 'a': displayChar(a, row, col); break;
		case 'b': displayChar(b, row, col); break;
		case 'c': displayChar(c, row, col); break;
		case 'd': displayChar(d, row, col); break;
		case 'e': displayChar(e, row, col); break;
		case 'f': displayChar(f, row, col); break;
		case 'g': displayChar(g, row, col); break;
		case 'h': displayChar(h, row, col); break;
		case 'i': displayChar(i, row, col); break;
		case 'j': displayChar(j, row, col); break;
		case 'k': displayChar(k, row, col); break;
		case 'l': displayChar(l, row, col); break;
		case 'm': displayChar(m, row, col); break;
		case 'n': displayChar(n, row, col); break;
		case 'o': displayChar(o, row, col); break;
		case 'p': displayChar(p, row, col); break;
		case 'q': displayChar(q, row, col); break;
		case 'r': displayChar(r, row, col); break;
		case 's': displayChar(s, row, col); break;
		case 't': displayChar(t, row, col); break;
		case 'u': displayChar(u, row, col); break;
		case 'v': displayChar(v, row, col); break;
		case 'w': displayChar(w, row, col); break;
		case 'x': displayChar(x, row, col); break;
		case 'y': displayChar(y, row, col); break;
		case 'z': displayChar(z, row, col); break;
		case '.': displayChar(period, row, col); break;
		case '!': displayChar(exclamationMark, row, col); break;
		case '?': displayChar(questionMark, row, col); break;
		case ',': displayChar(comma, row, col); break;
		case ' ': displayChar(space, row, col); break;
		default: cout << "This is not a character" << endl;
	}
}
