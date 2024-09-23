
#include "BlogEntry.h"
using namespace std;

// Uses default constructors of all objects
BlogEntry::BlogEntry() {
    // nothing needs to be changed
}


// intialize the data members with given values
BlogEntry::BlogEntry(const Text& initAuthor, const Text& initContents)
{
    author = initAuthor;
    contents = initContents;

}

Text BlogEntry::getAuthor() const {

    /*Text temp;
    return temp;*/
    return author;
}

Text BlogEntry::getContents() const {

   /* Text temp;
    return temp;*/
   return contents;
}

Date BlogEntry::getCreateDate() const {

    //Date temp;
    //return temp;
  return created;
}

Date BlogEntry::getModifyDate() const {

  /*Date temp;
  return temp;*/
   return modified;
}

// set author as the given value, the modified date also needs to be updated
void BlogEntry::setAuthor(const Text& newAuthor) {
    author = newAuthor;
    modified = Date();

}

// set contents as the given value, the modified date also needs to be updated
void BlogEntry::setContents(const Text& newContents) {
    contents = newContents;
    modified = Date();
}


void BlogEntry::printHTML(ostream& out) const {

    /* Example of output :

    Blog's HTML:
    <html>
    <body>
    <h1>Tester</h1>
    <p>
    This is a small test.
    </p>
    <p>
    Created: 9/11/2024
    </p>
    <p>
    Last modified: 9/11/2024
    </p>
    </body>
    </html>

    */
    // It should contain all the information including author, blog content, created and modified dates
    out << "blog's HTML" << endl;
    out << "<html>" << endl;
    out << "<body>" << endl;
    out << "<h1>Tester</h1>" << endl;
    out << "<p>" << endl;
    out << "This is a small test." << endl;
    out << "</p>" << endl;
    out << "<p>" << endl;
    out << "created: " << created << endl;
    out << "</p>" << endl;
    out << "<p>" << endl;
    out << "last modified" << modified << endl;
    out << "</p>" << endl;
    out << "</body>" << endl;
    out << "</html>" << endl;
    out << "author: " << author << endl;
    



}


void BlogEntry::showStructure() const {

    // nothing needs to be changed
    
    cout << "Author: " << author << endl;
    cout << "Created: " << created << endl;
    cout << "Modified: " << modified << endl;
    cout << "Content: " << contents << endl;
}
