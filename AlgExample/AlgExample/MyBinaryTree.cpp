#include "MyBinaryTree.h"
#include <iostream>



MyBinaryTree::MyBinaryTree()
{
	BTN root(1);
	root.m_pLeft = new BTN(2);
	root.m_pRight = new BTN(3);
	root.m_pLeft->m_pLeft = new BTN(4);
	root.m_pLeft->m_pRight = new BTN(5);
	root.m_pLeft->m_pRight->m_pLeft = new BTN(6);
	root.m_pRight->m_pRight = new BTN(7);
	root.m_pRight->m_pRight->m_pRight = new BTN(8);
	cout << root.getNext()->val << endl;
	cout << root.getNext()->val << endl;
	cout << root.getNext()->val << endl;
	cout << root.getNext()->val << endl;
	cout << root.getNext()->val << endl;
	cout << root.getNext()->val << endl;
	cout << root.getNext()->val << endl;
	cout << root.getNext()->val << endl;
}


MyBinaryTree::~MyBinaryTree()
{
}
