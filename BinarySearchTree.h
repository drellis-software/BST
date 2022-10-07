// File: BinarySearchTree.h
// Binary Tree ADT defined using Linked Structures

/*!     \file BinarySearchTree.h
*       \brief
*
*       This program holds the class definitions and member functions of the Binary Search Tree
*       and the Data involved
*
*/

#ifndef TREE_H
#define TREE_H

 template <typename treeEltType> class BinaryTree;

/*!
*  Class TreeNode,
*  Class for nodes in Tree with Children and info pointers.
*  Includes Count, Info, Left/Right Children
* 
*/
 template <typename eltType> class TreeNode {
 private:
  int count;
  eltType info;
  TreeNode<eltType> *left,*right;  
   TreeNode(const eltType &data,int cnt = 1,
                        TreeNode<eltType> *lChild=NULL,TreeNode *rChild=NULL)
   {info=data;   left=lChild; right=rChild; count=cnt; }
  
  friend class BinaryTree<eltType>;
 };

template <typename treeEltType> class BinaryTree {

public:

  
/*!
*  \fn BinaryTree
*  \ Constructor for the Binary Tree
*  \param NA
*  \return NA
*/
 // Constructor
 BinaryTree();

/*!
*  \fn insertToTree
*  \ Using eltType data passed from user, inserts
*  \ into tree if not already in the tree
*  \param const treeEltTyle &data
*  \return NA
*/
 // Place Element into Tree
 // Returns 1 if inserted, 0 if Data already in tree
 int insertToTree(const treeEltType &data);

 /*!
*  \fn treeSearch
*  \ Traverses Binary tree looking for data from user,
*  \ Finds the pointer of the data
*  \param const treeEltType &data
*  \return Pointer to Data
*/
 // Search for Element in Tree
 // Assumes == is defined for treeEltType
 // Returns pointer to data, or NULL, according to success
 treeEltType *treeSearch(const treeEltType &data);

/*!
*  \fn retrieveFromTree
*  \Finds inputted data from user in the Binary Tree
*  \ by traveral
*  \param const treeEltType &data
*  \return
*/
 // Retrieve Element from Tree (leaving Tree Intact)
 // Precondition: Item is in Tree
 treeEltType &retrieveFromTree(const treeEltType &data);

/*!
*  \fn deleteFromTree
*  \Deletes node with inputted data, keeping tree intact
*  \param const treeEltType &data
*  \return NA
*/
 // Remove an Element from the tree
 // Pre: Element is in the Tree
 void deleteFromTree(const treeEltType &data);

/*!
*  \fn decrementCount
*  \ Using a precondition for data count, the user will
*  \ select if all or once occurance will be deleted
*  \ decrements count or calls deleteFromTree function
*  \param const treeEltType &data, char &sel
*  \return NA
*/
 void decrementCount(const treeEltType &data, char &sel);

 /*!
*  \fn retrieveCount
*  \ Finds inputted datas count and returns true if less than 1
*  \param treeEltType &data
*  \return Bool Value
*/
 bool retrieveCount(treeEltType &data);

/*!
*  \fn inOrder
*  \ Displays tree traversing in order
*  \param NA
*  \return NA
*/ 
 // Display Tree using InOrder Traversal
 void inorder() const;
/*!
*  \fn preorder
*  \ Displays tree traversing pre order
*  \param NA
*  \return NA
*/

 // Display Tree using PreOrder Traversal
 void preorder() const;
/*!
*  \fn postorder
*  \ Displays tree traversing post order
*  \param NA
*  \return NA
*/

 // Display Tree using PostOrder Traversal
 void postorder() const;

 /*!
*  \fn treePrint
*  \ Breadth first print
*  \param NA
*  \return NA
*/

 // Breadth first print
 void treePrint() const;
 
private:

 TreeNode<treeEltType> *root;
/*!
*  \fn printInOrder
*  \ Prints tree traversing in order
*  \param NA
*  \return NA
*/

 // Display Tree using InOrder Traversal
 void printInorder(TreeNode<treeEltType> *) const;

/*!
*  \fn printPreOrder
*  \ Prints tree traversing pre order
*  \param treeNode<eltType> *
*  \return NA
*/

 // Display Tree using PreOrder Traversal
 void printPreorder(TreeNode<treeEltType> *) const;

/*!
*  \fn printPostOrder
*  \ Prints tree traversing post order
*  \param treeNode<eltType> *
*  \return NA
*/

 // Display Tree using PostOrder Traversal
 void printPostorder(TreeNode<treeEltType> *) const;

 /*!
*  \fn treePrintHelper
*  \ Helper function for tree Print
*  \param treeNode<eltType> *
*  \return NA
*/
 void treePrintHelper(TreeNode<treeEltType> *) const;

};

#endif
