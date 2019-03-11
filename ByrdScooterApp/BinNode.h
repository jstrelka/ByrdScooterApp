/*
Program Info
Name: JUSTIN STRELKA
CSC 161-Section: 001 Fa18
Creation Date: 11/12/2018
Program Name: BINNODE.H (BIRDAPP)
Description: NODE CLASS DECLARATION (BINTREE HELPER CLASS)
Version: 11/18/2018
Sources: C++ DATA STRUCTURES/ CPLUSPLUS.COM
*/

/*
FILE: BINNODE.H
CLASS PROVIDED: BINNODE (PART OF THE NAMESPACE strelka_bird_1) (BINNODE HELPER CLASS)

CONSTANTS:

NONE

CONSTRUCTORS:

//DEFAULT CONSTRUCTOR
BinNode();
POSTCONDITION: NODE class is initiated and member pointers left and right
are set to nullptr.

// OTHER CONSTRUCTOR
BinNode(Item dataIn);
POSTCONDITION: BINNODE class is initiated and member pointers left and right
are set to nullptr. Data member variable is set to dataIn.
*/

// MACRO GUARD BEGIN
#ifndef BINNODE_H
#define BINNODE_H

// INCLUDE LIBRARIES
#include<iostream>
#include<string>

// NAMESPACE
namespace strelka_bird_1
{
	//TEMPLATE CLASS DECLARATION
	template <class Type>
	// BEGIN DECLARE CLASS BINNODE
	class BinNode
	{
	public:
		// DEFAULT CONSTRUCTOR
		BinNode();
		// OTHER CONSTRUCTOR
		BinNode(Type dataIn);
	private:
		// POINTS TO LEFT NODE IN BINTREE
		BinNode<Type> * left;
		// POINTS TO RIGHT NODE IN BINTREE
		BinNode<Type> * right;
		// HOLDS DATA TYPE
		Type data;
		// ALLOWS LINKLIST CLASS TO USE PRIVATE MEMBER VARIABLES (NEXT, PREVIOUS, DATA)
		template<typename> friend class BinTree;
	};
}

// INCLUDE BINNODE TEM FILE
#include "BinNode.tem"

// END OF MACROGUARD
#endif