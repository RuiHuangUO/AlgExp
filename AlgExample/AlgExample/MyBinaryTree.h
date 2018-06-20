#pragma once
#include <cstddef>
#include <list>
using namespace std;

class BTN {
public:
	int val;
	BTN * m_pLeft;
	BTN * m_pRight;
	BTN(int v):val(v),m_pLeft(NULL),m_pRight(NULL),
		m_pCurrent(NULL) {}

	BTN * getNext() {
		if (m_pCurrent == NULL) {
			BTN * ptr = this;
			while (ptr) {
				inorderstack.push_back(ptr);
				ptr = ptr->m_pLeft;
			}
			m_pCurrent = inorderstack.back();
			inorderstack.pop_back();
		}
		else {
			BTN * ptr = m_pCurrent->m_pRight;
			while (ptr) {
				inorderstack.push_back(ptr);
				ptr = ptr->m_pLeft;
			}
			if (inorderstack.empty()) {
				m_pCurrent = NULL;
			}
			else {
				m_pCurrent = inorderstack.back();
				inorderstack.pop_back();
			}
		}
		return m_pCurrent;
	}

private:
	BTN * m_pCurrent;
	list<BTN*> inorderstack;
};

class MyBinaryTree
{
public:
	MyBinaryTree();
	virtual ~MyBinaryTree();
};

