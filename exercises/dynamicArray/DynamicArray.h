#pragma once

template< typename T_ >
class DynamicArray
{
public:
	//DynamicArray();
	DynamicArray(int growSize = 100);
	~DynamicArray();
	// assignment operator
	void operator= (const DynamicArray& dynArrayObj);
	// copy constructor
	DynamicArray(const DynamicArray& dynArrayObj);
	// add to end
	void AddToEnd(const T_ & newElement);
	// remove from end
	void RemoveFromEnd(int numElements = 1);
	// add one or more to middle
	void Insert(T_ & newElement, int location);
	// remove one or more from the middle
	// change space allocated (if less than current, then discard extra data)
	// clear array
	// size
	int size() const { return m_usedElements; };
	// get element
	T_ & getElement(int index);
	T_ & operator[](int index) { return getElement(index); };
private:
	T_* m_arrayPtr;
	int m_growSize;
	int m_allocElements;
	int m_usedElements;

	void copy(const DynamicArray & dynArrayObj);
	void grow();
	void shrink(const int shrinkBy = 1);
	void insert();
};

//template<typename T_>
//inline DynamicArray<T_>::DynamicArray()
//{
//	m_allocElements = 0;
//	m_usedElements = 0;
//	m_arrayPtr = nullptr;
//	m_growSize = 10;
//}

template<typename T_>
inline DynamicArray<T_>::DynamicArray(int growSize)
{
	m_allocElements = 0;
	m_usedElements = 0;
	m_arrayPtr = nullptr;
	m_growSize = growSize;
}

template< typename T_ >
DynamicArray<T_ >::~DynamicArray()
{
	if (m_arrayPtr != nullptr)
	{
		delete[] m_arrayPtr;
		m_arrayPtr = nullptr;
	}
}

template< typename T_ >
void DynamicArray<T_ >::operator=(const DynamicArray & dynArrayObj)
{
	if (this != &dynArrayObj)
	{
		copy(dynArrayObj);
	}
}

template< typename T_ >
inline DynamicArray<T_>::DynamicArray(const DynamicArray & dynArrayObj)
{
	// initialise some defaults
	m_allocElements = 0;
	m_usedElements = 0;
	m_arrayPtr = nullptr;
	m_growSize = 10;
	// do a deep copy
	copy(dynArrayObj);
}

template< typename T_ >
void DynamicArray<T_ >::AddToEnd(const T_ & newElement)
{
	// check is adding an element is bigger than capacity
	if (m_usedElements >= m_allocElements)
	{
		//increase array size
		grow();
	}
	// add element to the end of the array
	m_arrayPtr[m_usedElements] = newElement;
	// increment number of used element in the array
	m_usedElements++;
}

template<typename T_>
inline void DynamicArray<T_>::RemoveFromEnd(int numElements)
{
	m_usedElements -= numElements;
}

template<typename T_>
inline void DynamicArray<T_>::Insert(T_ & newElement, int location)
{
	int tempSize = m_usedElements;
	tempSize -= location;

	// check is adding an element is bigger than capacity
	if (m_usedElements == m_allocElements)
	{
		//increase array size
		grow();
	}
	// create temp array to store tail of array
	T_ * tempArr = new T_[tempSize];
	// copy elements from location
	int j = location;
	for (int i = location; i < m_usedElements; i++)
	{
		j -= i;
		tempArr[j] = m_arrayPtr[i];
	}
	// add new element
	m_arrayPtr[location] = newElement;
	// increment number of used element in the array
	m_usedElements++;
	// copy temp array elements after the new element
	int k = location;
	for (int i = 0; i < tempSize; i++)
	{
		k++;
		m_arrayPtr[i] = tempArr[i];
	}

	// delete temp array
	delete[] tempArr;
	tempArr = nullptr;
}

template<typename T_>
inline T_ & DynamicArray<T_>::getElement(int index)
{
	if (index < 0 || index >= m_usedElements)
	{
		std::cout << "out of bounds\n";
	}

	return m_arrayPtr[index];
}

template<typename T_>
inline void DynamicArray<T_>::copy(const DynamicArray & dynArrayObj)
{
	// assign values from dynamic array we want to copy
	m_allocElements = dynArrayObj.m_allocElements;
	m_usedElements = dynArrayObj.m_usedElements;
	m_growSize = dynArrayObj.m_growSize;

	// delete current array
	if (m_arrayPtr != nullptr)
	{
		delete[] m_arrayPtr;
		m_arrayPtr = nullptr;
	}

	// check array to copy already has elements and it's not null
	if (dynArrayObj.m_usedElements > 0 && dynArrayObj.m_arrayPtr != nullptr)
	{
		// allocate new array to size of array to copy
		m_arrayPtr = new T_[m_allocElements];
		// copy array
		for (int i = 0; i < dynArrayObj.m_allocElements; i++)
		{
			m_arrayPtr[i] = dynArrayObj.m_arrayPtr[i];
		}
	}
}

template<typename T_>
inline void DynamicArray<T_>::grow()
{
	// new array capacity
	m_allocElements += m_growSize;
	// create new array with new capacity
	T_ * tempArr = new T_[m_allocElements];
	// make sure current array is not empty
	if (m_arrayPtr != nullptr)
	{
		// copy existing array elements to new bigger array
		for (int i = 0; i < m_usedElements; i++)
		{
			tempArr[i] = m_arrayPtr[i];
		}

		// delete existing array
		delete[] m_arrayPtr;
		m_arrayPtr = nullptr;
	}
	// repoint ptr to new temp array
	m_arrayPtr = tempArr;
}

template<typename T_>
inline void DynamicArray<T_>::shrink(const int shrinkBy)
{
	// new array capacity
	m_usedElements -= shrinkBy;
	m_allocElements = m_usedElements;
	// create new array with smaller capacity
	T_ * tempArr = new T_[m_allocElements];
	// make sure current array is not empty
	if (m_arrayPtr != nullptr)
	{
		// copy existing array elements to new smaller array
		for (int i = 0; i < m_usedElements; i++)
		{
			tempArr[i] = m_arrayPtr[i];
		}

		// delete existing array
		delete[] m_arrayPtr;
		m_arrayPtr = nullptr;
	}
	// repoint ptr to new temp array
	m_arrayPtr = tempArr;
}


