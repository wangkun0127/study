#include <iostream>

using namespace std;

template<typename T>
class Node
{
	public:
		Node(T data)
		{
			m_data = data;
			m_pNext = NULL;
		}
		
	//private:
		T m_data;
		Node *m_pNext;
};

template<typename T>
ostream &operator<<(ostream &out,const Node<T> &node)
{
	out << node.m_data;
	return out;
};

template<typename T>
class List
{
	public:
		List()
		{
			m_iLen = 0;
			m_pFirstNode = NULL;
		}
		void insert(T data)
		{
			Node<T> *node = new Node<T>(data);
			node->m_pNext = m_pFirstNode;
			m_pFirstNode = node;
			m_iLen++;
		}
		Node<T> *getFirstNode()
		{
			return m_pFirstNode;
		}
	private:
		int m_iLen;
		Node<T> *m_pFirstNode;
};

template<typename T>
ostream &operator << (ostream &out,List<T> &list)
{
	Node<T> *node = list.getFirstNode();
	while(NULL != node)
	{
		out << *node << endl;
		node = node->m_pNext;
	}
	return out;
}

int main(void)
{
	List<int> int_list;
	int_list.insert(78);
	int_list.insert(88);
	int_list.insert(98);
	int_list.insert(68);
	cout << int_list;

	return 0;
}
