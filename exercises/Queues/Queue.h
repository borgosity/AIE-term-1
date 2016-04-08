#pragma once

template<class T>
class Queue
{
public:
	class Node 
	{
	public:
		Node() {};
		void SetData(int data) { m_data = data; };
		void SetNext(Node* next) { m_next = next; };
		void SetPrev(Node* previous) { m_prev = previous; };
		int Data() { return m_data; };
		Node* Next() { return m_next; };
		Node* Prev() { return m_prev; };
	private:
		int m_data;
		Node* m_next;
		Node* m_prev;

	};

	Queue() : m_pData(nullptr), m_uiSize(0) {};
	Queue(const Queue& a_rPointer);
	~Queue();

	//Accessory functions
	bool Empty()const;
	unsigned int GetSize()const;

	//Access functions
	void Push(T& a_rValue);
	void Pop();
	const T& Top();

private:
	Node* m_pData;
	unsigned int m_uiSize;
};

