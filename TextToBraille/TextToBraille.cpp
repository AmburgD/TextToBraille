// TextToBraille.cpp  By: AmburgD Start date: 12/11/21
//this is a converter that asks a user for an input string, then converts that string into a sentence in braille (specifically class 1 braille)
// it will also accept file names so a user can read in a file and convert it to braille
//class 2 braille will come after the project works
//as by suggestion, this will eventually allow for output files that could potentially be 3d printable, but we are just going to stick to
//getting the arrays to display for now

//Beta 1.0 1/20/22
/*
* So far the project works, however it prints the braille tranlsation vertically like japanese writing and not horizontally. Fix coming in the next update.
*/


//first release Alpha 1.0 6/13/22
/*
* This took way too long to actually come to a release build, but...
* we have finally reached a release version. The current version allows for a user to type in a sentence and output the translation to a .TXT file. 
* It also allows users to enter a text file name and translate that to an output file. These files are named by the user. 
* 
* Current Bugs: 
*	Cannot enter repeat capital letters in user entered text
*	certain characters are missing. In hamlet test there are a lot of "This is not a character" errors
*   exception handling
*/

#include <iostream>
#include <string>
#include <fstream>
#include <ctype.h>

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

//pauses the window from closing after the program is finished running so the user can see the program log
void pressEnterToContinue();

//constants for the arrays
const int COL = 2;
const int ROW = 3;

//variables to keep the sentences horizontal
string lineOne = "";
string lineTwo = "";
string lineThree = "";

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
char capitalLetter[3][2]{
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
	//what the user wants to translate
	string sentence;

	//determines if the program has ended
	bool end = false;

	//name of the file the user wants to translate
	string fileName;

	//keep running till the user exits
	while (!end) {

		//what the user chose to do in the program
		int choice;

		cout << "Enter (1) to type in the text you want to translate." << endl;
		cout << "Enter (2) to enter a filename you want to translate." << endl;
		cout << "Enter (3) to exit." << endl;
		cin >> choice;

		// choice for translating the user input (on command line)
		if (choice == 1) { 

			//the file that the user can write to
			ofstream brailleFile;

			//ask the user for input
			cout << "What would you like to say? Please enter here: ";

			//get the user's input
			cin >> sentence;
			//getline(cin, sentence, '\0');
			//cin.getline(sentence, 1024, '\0');

			//cout << "OK, if im hearing you corectly, you want to say: " << sentence << endl;
			cout << "Here it is in braille: " << endl;

			//for every character in the sentence, display the character
			
			for (int i = 0; i < sentence.length(); i++) {

				//pull the current character
				char currentChar = sentence[i];

				//adds capital letter symbol if the letter is capital
				if (isupper(currentChar)) {

					//convert the letter to lowercase
					currentChar = tolower(currentChar);

					//display capital letter symbol
					displayChar(capitalLetter, ROW, COL);

					//convert the letter to the braille arrangement
					textConvert(currentChar, ROW, COL);
				}
				else {
					//convert that character
					textConvert(currentChar, ROW, COL);
				}

				cout << "Calculating..." << endl;
			}
			
			cout << "Done!" << endl;
			cout << "Here is your translation..." << endl;
			cout << endl;
			cout << lineOne  << endl;
			cout << lineTwo << endl;
			cout << lineThree << endl;
			cout << endl;
			cout << "Now to output it into a file..." << endl;
			cout << "Please name the output file: " << endl;
			string outputFileName;
			cin >> outputFileName;
			//create the file that the data will output to
			brailleFile.open(outputFileName.append(".txt"));

			//breakpoint check
			if (!brailleFile) {
				cout << "File unable to open";
			}
			else {
				brailleFile << lineOne << endl;
				brailleFile << lineTwo << endl;
				brailleFile << lineThree << endl;
				brailleFile << endl;
				brailleFile.close();
				lineOne = "";
				lineTwo = "";
				lineThree = "";
			}
			cout << "Done! Go check it out!" << endl;
			cout << endl;
		}

		//choice for translating a file
		else if (choice == 2) { 

			//the file that the user can write to
			ofstream brailleFile;

			//ask the user for input
			cout << "Please enter a file name that is in the same directory as this .EXE file. \nBe sure to enter the name of the file EXACTLY, leaving out the .txt, as names are CaSe SeNsItIvE: ";
			cin >> fileName;

			//open the file that is wanted to be translated
			ifstream inFile(fileName.append(".txt"));
			
			cout << "Please name the output file: " << endl;
			string outputFileName;
			cin >> outputFileName;
			//create the file that the data will output to
			brailleFile.open(outputFileName.append(".txt"));

			//breakpoint check
			if (!brailleFile) {
				cout << "File unable to open";
			}

			//cout << "OK, if im hearing you corectly, you want to say: " << sentence << endl;
			cout << "Translating file... please wait." << endl;

			//run untill the end of the file
			while (!inFile.eof()) {

				//pull each line of the file
				getline(inFile, sentence);
				
				//for every character in the sentence, display the character
				for (int i = 0; i < sentence.length(); i++) {

					//pull the current character
					char currentChar = sentence[i];

					//adds capital letter symbol if the letter is capital
					if (isupper(currentChar)) {

						//convert the letter to lowercase
						currentChar = tolower(currentChar);

						//display capital letter symbol
						displayChar(capitalLetter, ROW, COL);

						//convert the letter to the braille arrangement
						textConvert(currentChar, ROW, COL);
					}
					else {
						//convert that character
						textConvert(currentChar, ROW, COL);
					}

				}

				//display what was translated
				cout << endl;
				cout << lineOne << endl;
				cout << lineTwo << endl;
				cout << lineThree << endl;
				cout << endl;

				//write to the open file
				brailleFile << lineOne << endl;
				brailleFile << lineTwo << endl;
				brailleFile << lineThree << endl;
				brailleFile << endl;

				//clear the line so the next one can be entered
				lineOne = "";
				lineTwo = "";
				lineThree = "";

			}
			
			//close the file that was written to
			cout << "Done! Go check it out!" << endl;
			brailleFile.close();
		}
		else if (choice == 3) {

			pressEnterToContinue();
			end = true;
		}
	}
}


void displayChar(char character[][2], int row, int col)
{
	//run each row of the array
	for (int i = 0; i < row; i++) {
		//for each row
			if (i == 0) {
				//pass in both of the dots in that row into a string
				for (int j = 0; j < 2; j++) {
					lineOne = lineOne + character[i][j];
				}
			}
			if (i == 1) {
				for (int j = 0; j < 2; j++) {
					lineTwo = lineTwo + character[i][j];
				}
			}
			if (i == 2) {
				for (int j = 0; j < 2; j++) {
					lineThree = lineThree + character[i][j];
				}
			}
		
	}
}

void textConvert(char currentLetter, int row, int col){
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
		case '0': displayChar(numberSign, row, col); displayChar(j, row, col); break;
		case '1': displayChar(numberSign, row, col); displayChar(a, row, col); break;
		case '2': displayChar(numberSign, row, col); displayChar(b, row, col); break;
		case '3': displayChar(numberSign, row, col); displayChar(c, row, col); break;
		case '4': displayChar(numberSign, row, col); displayChar(d, row, col); break;
		case '5': displayChar(numberSign, row, col); displayChar(e, row, col); break;
		case '6': displayChar(numberSign, row, col); displayChar(f, row, col); break;
		case '7': displayChar(numberSign, row, col); displayChar(g, row, col); break;
		case '8': displayChar(numberSign, row, col); displayChar(h, row, col); break;
		case '9': displayChar(numberSign, row, col); displayChar(i, row, col); break;
		default: cout << "This is not a character" << endl;
	}
}

// pressEnterToContinue: used to keep the console window open long enough to see your program's output
void pressEnterToContinue(void) {
	char c;
	cout << "Press Enter to continue...";
	cin.ignore(1024, '\n');

	do { cin.get(c); } while (c != '\n' && c != EOF);
	return;
}

