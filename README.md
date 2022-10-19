# TextToBraille
 TextToBraille.cpp  By: AmburgD Start date: 12/11/21
this is a converter that asks a user for an input string, then converts that string into a sentence in braille (specifically class 1 braille)
it will also accept file names so a user can read in a file and convert it to braille
class 2 braille will come after the project works
as by suggestion, this will eventually allow for output files that could potentially be 3d printable, but we are just going to stick to
getting the arrays to display for now

Beta 1.0 1/20/22
/*
* So far the project works, however it prints the braille tranlsation vertically like japanese writing and not horizontally. Fix coming in the next update.
*/


first release Alpha 1.0 6/13/22
/*
* This took way too long to actually come to a release build, but...
* we have finally reached a release version. The current version allows for a user to type in a sentence and output the translation to a .TXT file. 
* It also allows users to enter a text file name and translate that to an output file. These files are named by the user. 
* 
* Current Bugs: 
*	Cannot enter repeat capital letters in user entered text
*	certain characters are missing. In hamlet test there are a lot of "This is not a character" errors
*   exception handling
*   not case 2 braille
*/

Update 1.0.1 10/19/22
/*
* After a long hiatus with the start of college, I am now diving back into this project. This comes with good news
* 
* ...This will be 3d printable!!!!!
* 
* after a couple of external conversions I have discovered a method of converting the output text file into an STL... of sorts.
* Basically take the .TXT and convert it to at .JPG. Then take that .JPG and put it into Cura to make it into a lithophane.
* 
* This update converts all of the current braille letters from * to • as to make the .JPG easier to be interpereted by Cura
* 
* as for internal conversions (which would make this process more efficient) I have found a website that has a library with some of the 
* nessesary functions I need. I will need to discuss how to make that happen and the logistics behind it with some coleagues. It would only convert
* the .TXT to .JPG, so I still need to find a way to import it into Cura where it consistently makes a good file. 
*/
