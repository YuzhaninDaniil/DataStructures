#include "../Header/Treap.h"

void Split(TreapNode* node, int key, TreapNode*& leftNode, TreapNode*& rightNode)
{
	if (node == nullptr)
	{
		leftNode = rightNode = nullptr;
	}
	else if (node->Key < key)
	{
		Split(node->RightNode, key, node->RightNode, rightNode);
		leftNode = node;
	}
	else
	{
		Split(node->LeftNode, key, leftNode, node->LeftNode);
		rightNode = node;
	}
}

TreapNode* Merge(TreapNode* leftNode, TreapNode* rightNode)
{
	if (!leftNode || !rightNode)
	{
		return leftNode == nullptr ? rightNode : leftNode;
	}
	if (leftNode->Priority > rightNode->Priority)
	{
		leftNode->RightNode = Merge(leftNode->RightNode, rightNode);
		return leftNode;
	}

	rightNode->LeftNode = Merge(leftNode, rightNode->LeftNode);
	return rightNode;
}

void AddUnoptimized(TreapNode*& node, int key)
{
	TreapNode* newNode = new TreapNode(key);
	TreapNode* lessNode = nullptr;
	TreapNode* biggerNode = nullptr;
	Split(node, key, lessNode, biggerNode);
	node = Merge(Merge(lessNode, newNode), biggerNode);
}

void AddOptimized(TreapNode*& node, int key)
{
	if (!node)
	{
		node = new TreapNode(key);
		node->Key = key;
		return;
	}

	TreapNode* newNode = new TreapNode(key);

	if (node->Priority > newNode->Priority)
	{
		if (key < node->Key)
		{
			AddOptimized(node->LeftNode, key);
		}
		else
		{
			AddOptimized(node->RightNode, key);
		}
		return;
	}

	newNode->Key = key;
	Split(node, key, newNode->LeftNode, newNode->RightNode);
	node = newNode;
}

void RemoveOptimized(TreapNode*& node, int key, bool& isOperationSuccessfull)
{
	if (!node)
	{
		isOperationSuccessfull = false;
		return;
	}

	if (key > node->Key)
	{
		RemoveOptimized(node->RightNode, key, isOperationSuccessfull);
	}
	else if (key < node->Key)
	{
		RemoveOptimized(node->LeftNode, key, isOperationSuccessfull);
	}
	else
	{
		TreapNode* temp = node;
		node = Merge(node->LeftNode, node->RightNode);
		delete temp;
	}
}

void RemoveUnoptimized(TreapNode*& node, int key, bool& isOperationSuccessfull)
{
	TreapNode* lessNode = nullptr;
	TreapNode* equalNode = nullptr;
	TreapNode* biggerNode = nullptr;

	Split(node, key, lessNode, biggerNode);
	Split(biggerNode, key + 1, equalNode, biggerNode);
	if (!equalNode)
	{
		isOperationSuccessfull = false;
	}

	node = Merge(lessNode, biggerNode);
	delete equalNode;
}

TreapNode* FindElement(TreapNode* node, int key)
{
	if (!node)
	{
		return nullptr;
	}

	if (node->Key == key)
	{
		return node;
	}

	if (key > node->Key)
	{
		return FindElement(node->RightNode, key);
	}

	return FindElement(node->LeftNode, key);
}

int GetValue(TreapNode* node, int key)
{
	TreapNode* targetedValue = FindElement(node, key);
	if (targetedValue != nullptr)
	{
		return targetedValue->Key;
	}
	else
	{
		return 0;
	}
}
