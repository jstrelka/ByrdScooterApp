/*
Program Info
Name: JUSTIN STRELKA
CSC 161-Section: 001 Fa18
Creation Date: 11/12/2018
Program Name: BINTREE.H (BIRDAPP)
Description: BINTREE CLASS DECLARATION (CONTAINER CLASS)
Version: 11/18/2018
Sources: C++ DATA STRUCTURES/ CPLUSPLUS.COM
*/

// MACRO GUARD BEGIN
#ifndef BINTREE_H
#define BINTREE_H

// INCLUDE LIBRARIES
#include<iostream>
#include<string>
#include "BinNode.h"

// NAMESPACE
namespace strelka_bird_1
{
	// DECLARE CLASS TEMPLATE
	template <class Type>
	// BEGIN BINTREE CLASS DECLARATION
	class BinTree
	{
	public:
		// DEFAULT CONSTRUCTOR
		BinTree(); //(EMPTY TREE
		BinTree(const BinTree<Type> & source); // COPY CONSTRUCTOR
		BinTree<Type>& operator=(const BinTree<Type> & source); // ASSIGNMENT OPERATOR
		~BinTree(); // DESTRUCTOR (EMPTY TREE)
		bool add(Type dataIn); // BINTREE ADD FUNCTION
		bool remove(Type& dataIn); // BINTREE REMOVE FUNCTION
		int countItems() { return treeCount; } // RETURN HOW MANY ITEMS ARE IN BINTREE
		// OTHER MEMBER FUNCS - DATA PERSISTING
		bool readFile(std::string fileName);
		bool writeFile(std::string fileName,
			char delimiter = '\n');
		void printAll(); // PRINT ENTIRE BINTREE
		void inOrderTraverse(void process(Type&, int)); // TRAVERSE BINTREE IN ORDER
		BinNode<Type>* getRoot() { return root; } // OBTAIN ROOT* OF BINTREE

	private:
		void copyTree(const BinNode<Type>* source); // RECURSIVELY COPY CONTENTS OF TREE
		void writeFile(BinNode<Type>* cursor, std::ofstream& outFile, char delimiter); // WRITE TREE DATA TO FILE
		BinNode<Type>* allocBinNode(Type dataIn); // ALLOCATE NEW BINNODE POINTER
		void freeAllBinNodes(BinNode<Type>* cursor); // RECURSIVELY FREE ENTIRE BINTREE
		void inOrderTraverse(BinNode<Type>* rootPtr, int& counter, void process(Type&, int)); // RECURSIVELY TRAVERSE BINTREE
		BinNode<Type>* remove(BinNode<Type>*& root, Type& dataIn); // REMOVE ITEM FROM BINTREE USING RECURSION
		BinNode<Type>* minValueNode(BinNode<Type>*& node); // OBTAIN MIN VALUE NODE 
		int treeCount = 0; // COUNTER TO KEEP TRACK OF TREE NODES
		BinNode<Type> * root; // ROOT POINTER
	};

	// STANDALONE FUNC TO PRINT CONTENTS OF TREE (USED WITH TRAVERSE TREE IN PRINTALL PUBLIC FUNCTION)
	template<class Type>
	void print(Type & cursor, int counter);
}

#include "BinTree.tem"

#endif