
#include "Text.h"
#include <iostream>
#include <cstring>
#include <string>
//functions from the cstring include strlen, strcpy, toUpper, and toLower
//hi
Text::Text(const char* charSeq)
{

	bufferSize = strlen(charSeq) + 1;
	buffer = new char[bufferSize];
	strcpy(buffer, charSeq);

}

Text::Text(const Text& other)
{
	//prevent a shallow leak but make you copy contents of from the class object passed to the current object
	bufferSize = other.bufferSize;
	buffer = new char[other.bufferSize];
	strcpy(buffer, other.buffer);


}

void Text::operator = (const Text& other)
{

	if (other.bufferSize > bufferSize) {
		delete[] buffer;
		buffer = new char[other.bufferSize];
	}
	strcpy(buffer, other.buffer);

}

Text::~Text()
{
	delete[] buffer;
}

int Text::getLength() const
{
	//int length = sizeof(buffer) / sizeof(buffer[0]);
	//strlen returns the length or the number of elements in the array of type char
	return strlen(buffer);
}

char Text::operator [] (int n) const
{

	//int length = sizeof(buffer) / sizeof(buffer[0]);
	if (n > strlen(buffer)) {
		return '\0';
	}

	else {
		return buffer[n];
	}
}

void Text::clear()
{
	buffer[0] = '\0'; //still in memory but it deletes the elements in the array.
}

void Text::showStructure() const
{
    for(int i = 0; i<strlen(buffer); i++){
        cout << buffer[i];
    }
}

//for both functions toUpper and toLower. We are creating a copy of the contents of characters inside of the array of type char 
//which was called by the object in test1.cpp (main). Here, we take the copy and lowercase or Uppercase every letter (depending on which one
//you called) and have it intialized to the temp object created in both functions. Rather than modfying the characters inside of the class object 
//that invoked the function

Text Text::toUpper() const
{
    //toUpper capitalizes every character in the array of type char
    
	Text temp;
	for (int i = 0; i < strlen(buffer); i++) {
		temp.buffer[i] = (char)toupper(buffer[i]);
	}
	return temp;
}

Text Text::toLower() const
{
    //toLower lowercases everty character in the array of type char
	Text temp;
	for (int i = 0; i < strlen(buffer); i++) {
		temp.buffer[i] = (char)tolower(buffer[i]);
	}
	return temp;
}

bool Text::operator == (const Text& other) const
{
	//the function strcmp() takes a paramter of two char type arrays where it compares the contents stored in the array.
	//it return three  possible integer values. The first one being zero, if the contents in both arrays are exactly the same
	//
	if (strcmp(buffer, other.buffer) == 0) {
		return true;
	}
	else {
		return false;
	}
}

bool Text::operator <  (const Text& other) const
{
	if (strcmp(buffer, other.buffer) < 0) {
		return true;
	}
	else {
		return false;
	}
}

bool Text::operator >  (const Text& other) const
{
	if (strcmp(buffer, other.buffer) > 0) {
		return true;
	}
	else {
		return false;
	}
}

//overloading the extraction operator and insertion operator in the textio.cpp file

