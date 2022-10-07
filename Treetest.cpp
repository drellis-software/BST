// File: TreeTest.cpp
// Driver for Binary Tree ADT

/*!     \file TreeTest.cpp
*       \brief
*
*       This program is the driver of the class definitions and member functions of the Binary Search Tree
*       and the Data involved
*
*/

#include <iostream>
#include <string>
#include "BinarySearchTree.h"

using namespace std;

typedef BinaryTree<int> IntTree;

/*!
*  \fn getChoice
*  \ Choice Function for implementations on Binary Tree
*  \param String ok
*  \return NA
*/

char getChoice(string ok);
/*!
*  \fn addToTree
*  \ Adds to Binary Tree using input and member function
*  \param IntTree &TheTree
*  \return NA
*/

// Insert Value to Search Tree
void addToTree(IntTree &TheTree);
/*!
*  \fn removeFromTree
*  \ Removes Value from Binary Tree using member function
*  \param IntTree &TheTree
*  \return NA
*/

// Remove Value from Search Tree
void removeFromTree(IntTree &TheTree);
/*!
*  \fn countHelper
*  \ Helper function to remove or decrement value from Binary Tree
*  \param char &sel
*  \return NA
*/

// Remove Value or Occurence from Search Tree
char countHelper(char &sel);

int main()
{IntTree Tree;
 int entry,*result;
 char Choice, sel;
 do {
  cout << "Select: A)dd    R)emove     P)rint     T)ree Print     Q)uit\n";
  Choice=getChoice("ARPTQ");
  switch (Choice) {
   case 'A':
    addToTree(Tree);
    break;
   case 'P':
    cout << "The Tree:" << endl;
    Tree.inorder();
    break;
  case 'R':
    removeFromTree(Tree);
    break;
   case 'T':
    cout << "The tree, as it appears (sort of)..\n";
    Tree.treePrint(); 
  }
 } while (Choice!='Q');
}

char getChoice(string ok)
{char ch=' ';
 do ch=toupper(cin.get()); while (ok.find(ch)==string::npos);
 cin.get(); // eat CR
 return(toupper(ch));
}

// Insert Value to Search Tree
void addToTree(IntTree &TheTree)
{  int entry;
   cout << " Enter an Integer >";
   cin >> entry;
   TheTree.insertToTree(entry);
}

char countHelper(char &sel)
{  
  cout << "Select: O)ne Occurance    A)ll Occurances\n";
  cin >> sel;
  return sel;
}
// Remove Value from Search Tree
void removeFromTree(IntTree &TheTree)
{
  char sel;
  int entry,*result;
  cout << "Value to Delete? >";
  cin >> entry;
  result=TheTree.treeSearch(entry);
  if (!result)
    {
    cout << entry << " Not Found\n";
    }
  else
    {
      if(!TheTree.retrieveCount(entry))
	{
	  TheTree.deleteFromTree(entry);
	}
      else
	{
	  countHelper(sel);
	  TheTree.decrementCount(entry, sel);
	}	  
    }
}
