#include <iostream>

using namespace std;

class Base
{

};

class Node
{
	public:
		Node(Base *base)
			:m_pData(base),m_pNext(NULL)
		{}
		Base *m_pData;
		Node *m_pNext;
};

class List
{
	public:
		List():m_pFirstNode(NULL),m_iLen(0)
		{}
		void insert(Base *base)
		{
			Node *node = new Node(base);
			node->m_pNext = m_pFirstNode;
			m_pFirstNode = node;
			m_iLen++;
		}
		Node *m_pFirstNode;
		int m_iLen;
};

class Student:public Base
{
	public:
		Student(string name="newStu",float score=60)
		{
			m_strName = name;
			m_fScore = score;
		}
		void show()
		{
			cout << "name:" <<m_strName
				<< "score:" <<m_fScore << endl;
		}
	private:
		string m_strName;
		float m_fScore;
};

int main(void)
{
	return 0;
}
