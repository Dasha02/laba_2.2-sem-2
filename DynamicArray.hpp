//
//  DynamicArray.hpp
//  
//
//
//

#ifndef DynamicArray_hpp
#define DynamicArray_hpp

#include <iostream>
using namespace std;

template<typename T>
class DynamicArray
{
private:
    T* dynamicArrayPointer;
    int size;    // размер буфера
    int count;   // кол-во элементов

public:
    DynamicArray();
    DynamicArray(int size);
    DynamicArray(T item, int count);
    DynamicArray(T* items, int count);
    DynamicArray(const DynamicArray<T>* dynamicArray);
    DynamicArray(const DynamicArray<T> & dynamicArray);
    ~DynamicArray();
public:
    int GetSize()const ;
    int GetCount() const ;
    T Get(int index) const ;
    void Set(int index, T data);
    void Resize(int size_new);
    void Remove(int index);
    void Print() const;
    T& operator[](int index);
    
};

template<typename T>
DynamicArray<T>::DynamicArray() : count(0)
{
    this->dynamicArrayPointer = new T[10];
    this->size = 10;
}

template<typename T>
DynamicArray<T>::DynamicArray(int size) : count(0), size(size)
{
    this->dynamicArrayPointer = new T[size];
}

template<typename T>
DynamicArray<T>::DynamicArray(T item, int count): size(count * 2), count(count)
{
    this->dynamicArrayPointer = new T[this->size];
    for (int i = 0; i < count; i++)
    {
        this->dynamicArrayPointer[i] = item;
    }
}

template<typename T>
DynamicArray<T> ::DynamicArray(T* items, int count) : size(count * 2), count(count)
{
    this->dynamicArrayPointer = new T[this->size];
    for (int i = 0; i < count; i++)
    {
        this->dynamicArrayPointer[i] = items[i];
    }
}

template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>* dynamicArray) : size(dynamicArray->size), count(dynamicArray->count)
{
    dynamicArrayPointer = new T[size];
    for (int i = 0; i < count; i++)
    {
        this->dynamicArrayPointer[i] = dynamicArray->dynamicArrayPointer[i];
    }
}

template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T> & dynamicArray) : size(dynamicArray.size), count(dynamicArray.count)
{
    dynamicArrayPointer = new T[size];
    for (int i = 0; i < count; i++)
    {
        this->dynamicArrayPointer[i] = dynamicArray.dynamicArrayPointer[i];
    }
}


template<typename T>
DynamicArray<T>::~DynamicArray()
{
    delete[] this->dynamicArrayPointer;
}

template<typename T>
int DynamicArray<T>::GetSize() const
{
    return this->size;
}

template<typename T>
int DynamicArray<T>::GetCount() const
{
    return this->count;
}

template<typename T>
T DynamicArray<T>::Get(int index) const
{
    return this->dynamicArrayPointer[index];
}

//предполагает вставку значения в элементе по индексу
template<typename T>
void DynamicArray<T>::Set(int index, T data)
{
    if (this->size == this->count)
    {
        this->size += 1;
        Resize(GetSize());
        this->count -= 1;
    }
    this->count += 1;
    memmove(this->dynamicArrayPointer + index + 1, this->dynamicArrayPointer + index, (this->count - index - 1) * sizeof(T));
    this->dynamicArrayPointer[index] = data;

}

 /*
template<typename T> //  функция под замену
 
void DynamicArray<T>::Set(int index, T data)
{
    if (index<count && index>=0)
        this->dynamicArrayPointer[index] = data;
    else
    {
        cout<<"IndexOutOfRange";
        assert(0);
    }
}




//функция под замену
template<typename T>
void DynamicArray<T>::Resize(int size_new)
{
    T* size_newPointer = new T[size_new];
    int copySize = size_new > (this->size) ? this->size : size_new;
    memcpy(size_newPointer, this->dynamicArrayPointer, copySize * sizeof(T));
    count = copySize < count ? copySize : count;
    size = size_new;
    delete[] this->dynamicArrayPointer;
    this->dynamicArrayPointer = size_newPointer;
}
 */

// 
template<typename T>
void DynamicArray<T>::Resize(int size_new)
{
    T* size_new_pointer = new T[size_new];
    int copySize = size_new > (this->size) ? this->size : size_new;
    memcpy(size_new_pointer, this->dynamicArrayPointer, copySize * sizeof(T));
    this->count = copySize;
    this->size = size_new;
    delete[] this->dynamicArrayPointer;
    this->dynamicArrayPointer = size_new_pointer;
}


template<typename T>
void DynamicArray<T>::Remove(int index)
{
    this->count -= 1;
    memmove(this->dynamicArrayPointer + index, this->dynamicArrayPointer + (index + 1), (this->count - index) * sizeof(T));
}

template<typename T>
void DynamicArray<T>::Print() const
{
    for (int i=0; i< this->count; i++)
        cout<< this->dynamicArrayPointer[i]<<"  ";
    cout<<endl;
}

template<typename T>
T& DynamicArray<T>::operator[](int index)
{
    return this->dynamicArrayPointer [index];
}

#endif /* DynamicArray_hpp */
