#ifndef REGEX_AST_H
#define REGEX_AST_H

#include "Macro.h"
#include "CharSet.h"

/*
enum ASTNodeType{
	andType,
	orType,
	minusType,
	linkType,
	repeatType,
	optionalRepeatType,
	infRepeatType,
	leafType,
	baseType
};
*/

struct ASTNode{
public:
	ASTNode *leftNode{ nullptr }, *rightNode{ nullptr };

	virtual ~ASTNode()
	{
		if (leftNode != nullptr)
			delete leftNode;
		if (rightNode != nullptr)
			delete rightNode;
	}

};

struct AndNode :public ASTNode{};
struct OrNode :public ASTNode{};
struct MinusNode :public ASTNode{};
struct LinkNode :public ASTNode{};
struct RepeatNode :public ASTNode{
public:
	unsigned int repeatTime;
	RepeatNode(unsigned int n) :repeatTime(n){}
};
struct OptionalRepeatNode :public ASTNode{
public:
	unsigned int repeatTime;
	OptionalRepeatNode(unsigned int n) :repeatTime(n){}
};
struct InfRepeatNode :public ASTNode{};
struct LeafNode :public ASTNode{
public:
	CharSet *charSet;
	LeafNode(CharSet &charSet) :charSet(&charSet){}
	~LeafNode()
	{
		delete charSet;
	}
};

#endif