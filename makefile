cc=g++
debugFlag=-g

tree: BinarySearchTree.o Treetest.o 
	$(cc) -o tree Treetest.o BinarySearchTree.o $(debugFlag)
	
icdemo: BinarySearchTree.o InClassDemo.o
	$(cc) -o icd InClassDemo.o BinarySearchTree.o $(debugFlag)

InClassDemo.o: BinarySearchTree.h InClassDemo.cpp
	$(cc) -c InClassDemo.cpp $(debugFlag)

Treetest.o: Treetest.cpp  BinarySearchTree.h
	$(cc) -c Treetest.cpp $(debugFlag)

BinarySearchTree.o: BinarySearchTree.cpp BinarySearchTree.h 
	$(cc) -c BinarySearchTree.cpp $(debugFlag)


clean: 
	\rm -f *.o tree icdemo