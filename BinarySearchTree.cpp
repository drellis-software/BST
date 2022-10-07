// File: BinarySearchTree.cpp
// Binary Tree ADT implemented with TreeNode linked structures

/*!     \file BinarySearchTree.cpp
*       \brief
*
*       This program holds the class member functions of the Binary Search Tree
*       and the Data involved
*
*/

#include <iostream>
#include <string>
#include <queue>
#include "BinarySearchTree.h"

using namespace std;

/*************************************************************************/
/*                                                                       */
/* Function name: BinaryTree::BinaryTree()                               */
/* Description: Constructs the Root for Binary Tree                      */
/* Parameters: none                                                      */
/*                                                                       */
/*                                                                       */
/* Return Value: NA                                                      */
/*                                                                       */
/*************************************************************************/
// Constructor
template <typename treeEltType> BinaryTree<treeEltType>::BinaryTree()
{root=NULL;}

/*************************************************************************/
/*                                                                       */
/* Function name: BinaryTree::insertToTree()                             */
/* Description: Inserts user data to Binary Tree                         */
/* Parameters: const treeEltType &data - import/export                   */
/*                                                                       */
/*                                                                       */
/* Return Value: NA                                                      */
/*                                                                       */
/*************************************************************************/

// Place Element into Tree
// Returns 1 if inserted, 0 if data already in tree
template <typename treeEltType>
	  int BinaryTree<treeEltType>::insertToTree(const treeEltType &data)
{if (root==NULL) { // Empty Tree
  root=new TreeNode<treeEltType>(data);
  return(1);
 }
 // Search for spot to put data; We only stop when we get to the bottom (NULL)
 TreeNode<treeEltType> *t=root,*parent;
 while(t!=NULL) {
   if (t->info==data)
     {// data already in Tree
       (t->count)++;
       return t->count;
     }
   parent=t; // Set the trail pointer to the ancestor of where we're going
   if (data<t->info) 
     t=t->left;
   else 
     t=t->right;
 }
 // Found the spot; insert node.
 if (data<parent->info) parent->left=new TreeNode<treeEltType>(data);
 else parent->right=new TreeNode<treeEltType>(data);
 return(1);
}

/*************************************************************************/
/*                                                                       */
/* Function name: BinaryTree::treeSearch()                               */
/* Description: Seaches for  user data in Binary Tree                    */
/* Parameters: const treeEltType &data - import/export                   */
/*                                                                       */
/*                                                                       */
/* Return Value: Ptr to Elt, Otherwise NULL                              */
/*                                                                       */
/*************************************************************************/

// Search for Element in Tree
// Assumes == is defined for treeEltType
// Returns Ptr to Elt if Found, NULL otherwise
template <typename treeEltType>
	treeEltType *BinaryTree<treeEltType>::treeSearch(const treeEltType &key)
{TreeNode<treeEltType> *t=root;
 while (t && t->info != key)
   if (key < t->info) 
     t=t->left;
   else 
     t=t->right;
 if (t)
   return(&t->info);	
 return(NULL);
}

/*************************************************************************/
/*                                                                       */
/* Function name: BinaryTree::retrieveFromTree()                         */
/* Description: Retrieves user data from Binary Tree                     */
/* Parameters: const treeEltType &data - import/export                   */
/*                                                                       */
/*                                                                       */
/* Return Value: NA                                                      */
/*                                                                       */
/*************************************************************************/
// Retrieve Element from Tree (leaving Tree Intact)
// Precondition: Item is in Tree
template <typename treeEltType>
   treeEltType &BinaryTree<treeEltType>::retrieveFromTree(const treeEltType &key) 
{TreeNode<treeEltType> *t;
 for (t=root;t->info!=key;)
  if (key<t->info) t=t->left;
  else t=t->right;
 return(t->info);
}

/*************************************************************************/
/*                                                                       */
/* Function name: BinaryTree::removeFromTree()                           */
/* Description: Removes user data from Binary Tree, leeping tree intact  */
/* Parameters: const treeEltType &data - import/export                   */
/*                                                                       */
/*                                                                       */
/* Return Value: NA                                                      */
/*                                                                       */
/*************************************************************************/
// Remove an Element from the tree
// Precondition: Element is in the Tree; 
template <typename treeEltType>
      void BinaryTree<treeEltType>::deleteFromTree(const treeEltType &data)
{TreeNode<treeEltType> *nodeWithData,*nodeToDelete,*t=root,*trailT=NULL;
 // Find spot
  
 while (t->info!=data) {  // safe because of precondition
  trailT=t;
  if (data<t->info) t=t->left;
  else t=t->right;
 }
  
  
 nodeWithData=t;  // Hold onto the data Node for later deletion
 // Case 1: Leaf?
 if (!(nodeWithData->left) && !(nodeWithData->right)) {
  // No Subtrees, node is leaf...Wipe it
  // Is it the root?
  if (nodeWithData==root)
    root=NULL;
  else if (trailT->right==nodeWithData) // Parent's right child
    trailT->right=NULL;
  else 
    trailT->left=NULL;
  nodeToDelete=nodeWithData;    // free this at the end
 }
 else if (!(nodeWithData->left)) {  
  // If 1st condition false and this one's true, there's a right subtree
  if (!trailT) { // Node to delete is root and there is no left subtree
    nodeToDelete=root;
    root=root->right;
  }
  else { // Point parent's pointer to this node to this node's right child
    if (trailT->right==nodeWithData) 
      trailT->right=nodeWithData->right;
    else 
      trailT->left=nodeWithData->right;
    nodeToDelete=nodeWithData;
  }
 }
 else if (!(nodeWithData->right)) {  
   // If 1st 2 conditions false and this one's true, there's a left subtree
   if (!trailT) { // Node to delete is root and there is no left subtree
     nodeToDelete=root;
     root=root->left;
   }
   else {// Otherwise, move up the right subtree
     if (trailT->right==nodeWithData) 
        trailT->right=nodeWithData->left;
     else 
        trailT->left=nodeWithData->left;
     nodeToDelete=nodeWithData;
   }
 } 
 else { // If you make it here, node has two children
   // Go to rightmost node in left subtree; we know there's a right child...
  for (trailT=nodeWithData,t=nodeWithData->left;
                                        t->right!=NULL;trailT=t,t=t->right);
  // Want to copy data from node with 0 or 1 child to node with data to delete 
  // Place node data in NodeWithData
  nodeWithData->info=t->info;
   // Set the parent of source node to point at source node's left child 
   //   (We know it hasn't a right child. Also ok if no left child.)
  if (trailT==nodeWithData) 
    // Need to point parent correctly. 
    //   See if after the we went left there was no right child
    //   If there was no right child, this is rightmost node in left subtree
    trailT->left=t->left;
  else // we did go right; after going left, there was a right child
   // rightmost node has no r. child, so point its parent at its l. child 
   trailT->right=t->left;
  nodeToDelete=t;
 }
 delete nodeToDelete;
}

/*************************************************************************/
/*                                                                       */
/* Function name: BinaryTree::printInOrder()                             */
/* Description: Prints Binary Tree in order using helper                 */
/* Parameters: TreeNode<treeEltType> *t                                  */
/*                                                                       */
/*                                                                       */
/* Return Value: NA                                                      */
/*                                                                       */
/*************************************************************************/

// Need Helper to Recursively Print the Tree
template <typename treeEltType>
     void BinaryTree<treeEltType>::printInorder(TreeNode<treeEltType> *t) const
//void printTheTree(TreeNode *T)
{if (t) {
  printInorder(t->left);
  cout << t->info << "(" << t->count << ")" << endl;
  printInorder(t->right);
 }
}

/*************************************************************************/
/*                                                                       */
/* Function name: BinaryTree::decrementCount()                           */
/* Description: Decrements or deletes  user data from Binary Tree        */
/* Parameters: const treeEltType &data, char &sel - import/export        */
/*                                                                       */
/*                                                                       */
/* Return Value: NA                                                      */
/*                                                                       */
/*************************************************************************/

template <typename treeEltType>
void BinaryTree<treeEltType>::decrementCount(const treeEltType &data, char &sel)
{TreeNode<treeEltType> *nodeWithData,*nodeToDelete,*t=root,*trailT=NULL;
  while (t->info!=data) {  // safe because of precondition                                                                                                                                                 
    trailT=t;                                                                                                                                                                                             
    if
      (data<t->info) t=t->left;   
    else
      t=t->right;
  }
  
  if(tolower(sel) == 'o')
    {
      t->count--;
    }
  else if(tolower(sel) == 'a')
    {
      deleteFromTree(data);
    }
  else
    {
      cout << "INVALID" << endl;
    }  
}

/*************************************************************************/
/*                                                                       */
/* Function name: BinaryTree::retrieveCount()                            */
/* Description: Retrieves users data count from Binary Tree, returns true*/
/*              if > 1                                                   */
/* Parameters: const treeEltType &data - import/export                   */
/*                                                                       */
/*                                                                       */
/* Return Value: True/False                                              */
/*                                                                       */
/*************************************************************************/

template <typename treeEltType> bool BinaryTree<treeEltType>::retrieveCount(treeEltType &data)
{
  TreeNode<treeEltType> *nodeWithData,*nodeToDelete,*t=root,*trailT=NULL;
  
  while (t->info!=data) {  // safe because of precondition                                                                                                                                                  
    trailT=t;
    if
      (data<t->info) t=t->left;
    else
      t=t->right;
  }

  if(t->count > 1)
    {
      return true;
    }
  else
    {
      return false;
    }

  
}

/*************************************************************************/
/*                                                                       */
/* Function name: BinaryTree::inOrder()                                  */
/* Description: Displays Binary Tree in order                            */
/* Parameters: NA                                                        */
/*                                                                       */
/*                                                                       */
/* Return Value: NA                                                      */
/*                                                                       */
/*************************************************************************/

// Display Tree using InOrder Traversal
template <typename treeEltType> void BinaryTree<treeEltType>::inorder() const
{printInorder(root);}

/*************************************************************************/
/*                                                                       */
/* Function name: BinaryTree::printPreOrder()                            */
/* Description: Prints Binary Tree pre order                             */
/* Parameters: NA                                                        */
/*                                                                       */
/*                                                                       */
/* Return Value: NA                                                      */
/*                                                                       */
/*************************************************************************/

// Need Helper to Recursively Print the Tree
template <typename treeEltType>
   void BinaryTree<treeEltType>::printPreorder(TreeNode<treeEltType> *t) const
//void printTheTree(TreeNode *t)
{if (t) {
  cout << t->info << "(" << t->count << ")" << endl;
  printPreorder(t->left);
  printPreorder(t->right);
 }
}

/*************************************************************************/
/*                                                                       */
/* Function name: BinaryTree::preOrder()                                 */
/* Description: Displays Binary Tree in order                            */
/* Parameters: NA                                                        */
/*                                                                       */
/*                                                                       */
/* Return Value: NA                                                      */
/*                                                                       */
/*************************************************************************/

// Display Tree using InOrder Traversal
template <typename treeEltType> void BinaryTree<treeEltType>::preorder() const
{printInorder(root);}


/*************************************************************************/
/*                                                                       */
/* Function name: BinaryTree::printPostOrder()                           */
/* Description: Prints Binary Tree post order using helper               */
/* Parameters: TreeNode<treeEltType> *t                                  */
/*                                                                       */
/*                                                                       */
/* Return Value: NA                                                      */
/*                                                                       */
/*************************************************************************/

// Need Helper to Recursively Print the Tree
template <typename treeEltType>
  void BinaryTree<treeEltType>::printPostorder(TreeNode<treeEltType> *t) const
//void printTheTree(TreeNode *t)
{if (t) {
  printPostorder(t->left);
  printPostorder(t->right);
  cout << t->info << "(" << t->count << ")" << endl;
 }
}

/*************************************************************************/
/*                                                                       */
/* Function name: BinaryTree::postOrder()                                */
/* Description: Displays Binary Tree post order                          */
/* Parameters: NA                                                        */
/*                                                                       */
/*                                                                       */
/* Return Value: NA                                                      */
/*                                                                       */
/*************************************************************************/

// Display Tree using InOrder Traversal
template <typename treeEltType> void BinaryTree<treeEltType>::postorder() const
{printInorder(root);}

/*************************************************************************/
/*                                                                       */
/* Function name: BinaryTree::treePrint()                                */
/* Description: Prints Binary Tree using helper                          */
/* Parameters: NA                                                        */
/*                                                                       */
/*                                                                       */
/* Return Value: NA                                                      */
/*                                                                       */
/*************************************************************************/

template <typename treeEltType> void BinaryTree<treeEltType>::treePrint() const
{treePrintHelper(root);}

/*************************************************************************/
/*                                                                       */
/* Function name: BinaryTree::treePrintHelper()                          */
/* Description: Helper function for Tree Print                           */
/* Parameters: TreeNode>treeEltType> *root - import/export               */
/*                                                                       */
/*                                                                       */
/* Return Value: NA                                                      */
/*                                                                       */
/*************************************************************************/

template <typename treeEltType> void BinaryTree<treeEltType>::
                        treePrintHelper(TreeNode<treeEltType> *root) const
{queue<TreeNode<treeEltType> *> Q;
 // A dummy node to mark end of level
 TreeNode<treeEltType> *dummy=new  TreeNode<treeEltType>(-1);
 if (root) {
   cout << root->info << "(" << root->count << ")" << endl;
   Q.push(root->left);
   Q.push(root->right);
   Q.push(dummy);
 }
 TreeNode<treeEltType> *t=root;
 while (!Q.empty()) {
  t=Q.front();
  Q.pop();
  if (t==dummy) {
   if (!Q.empty()) 
    Q.push(dummy);
   cout << endl;
  }
  else if (t) {
   cout << t->info << "(" << t->count << ")" << " ";
   Q.push(t->left);
   Q.push(t->right);
  } 
 }
}

template class BinaryTree<int>;
