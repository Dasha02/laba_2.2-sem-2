//
//  LinkedListSequence.hpp

//
//



#ifndef LinkedListSequence_h
#define LinkedListSequence_h

#include "Sequence.hpp"
#include "LinkedList.hpp"
template <class T>
class LinkedListSequence : Sequence<T>
{
private:
    LinkedList<T>* items;
    int lenght;
public:
    LinkedListSequence(T* items, int count);
    LinkedListSequence();
    LinkedListSequence(const LinkedList <T>* list);
    ~LinkedListSequence();
public:
    virtual T GetFirst()const;
    virtual T GetLast()const;
    virtual T Get(int index)const;
    virtual int  GetLength()override;
    virtual void Remove(int index)override;
    virtual void Append(T item)override;
    virtual void Prepend(T item)override;
    virtual void InsertAt(T item, int index)override;
    virtual Sequence<T>* Concat(Sequence<T>* list)const override;
    virtual Sequence<T>* GetSubsequence(int start, int end) const override;
};
template <class T>
LinkedListSequence<T>::LinkedListSequence(T* items, int count) : lenght(count)
{
    this->items = new LinkedList<T>(items, count);
}
template <class T>
LinkedListSequence<T>::LinkedListSequence() : lenght(0)
{
    this->items = new LinkedList<T>();
}
template <class T>
LinkedListSequence<T>::LinkedListSequence(const LinkedList <T>* list) : lenght(list->GetLength())
{
    this->items = new LinkedList<T>(list);
}
template <class T>
LinkedListSequence<T>::~LinkedListSequence()
{
    delete this->items;
}


template <class T>
T LinkedListSequence<T>::GetFirst()const
{
    return this->items->GetFirst();
}

template <class T>
T LinkedListSequence<T>::GetLast()const
{
    return this->items->GetLast();
}

template <class T>
T LinkedListSequence<T>::Get(int index)const
{
    return this->items->Get(index);
}

template <class T>
int LinkedListSequence<T>::GetLength()
{
    return this->lenght; }

template <class T>
void LinkedListSequence<T>::Remove(int index)
{
    this->lenght--; this->items->Remove(index);
}

template <class T>
void LinkedListSequence<T>::Append(T item)
{
    this->lenght++; this->items->Append(item);
}

template <class T>
void LinkedListSequence<T>::Prepend(T item)
{
    this->lenght++; this->items->Prepend(item);
}

template <class T>
void LinkedListSequence<T>::InsertAt(T item, int index)
{
    this->lenght++; this->items->InsertAt(item, index);
}
template <class T>
Sequence<T>* LinkedListSequence<T>::Concat(Sequence<T>* list)const
{
    list = (LinkedListSequence*)list;
    LinkedListSequence<T>* concatedSequence = new LinkedListSequence(this->items);
    for (int i = 0; i < list->GetLength(); i++)
    {
        concatedSequence->Append(list->Get(i));
    }
    return (Sequence<T>*)concatedSequence;
}

template <class T>
Sequence<T>* LinkedListSequence<T>::GetSubsequence(int start, int end) const
{
    Sequence<T>* subSequence = new LinkedListSequence();

    for (int i = start; i < end + 1; i++)
    {
        subSequence->Append(this->Get(i));
    }
    return subSequence;
}

#endif /* LinkedListSequence_h */
