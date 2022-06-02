//
//  LinkedList.hpp
//
//
//
//
#ifndef LinkedList_hpp
#define LinkedList_hpp


#include "LinkedList.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

template<typename T>
class Node
{
private:
    T data;
    Node<T>* next;
    Node<T>* prev;
    
public:
    Node() : next(NULL), prev(NULL), data(NULL) {}
    Node(T item) : next(NULL), prev(NULL), data(item) {}
    T GetValue() { return this->data;}
    Node<T>* GetNext() { return this->next;}
    Node<T>* GetPrev() { return this->prev;}
    void SetValue(T item) {this->data = item;}
    void SetNext(Node<T>* next_point) {this->next  = next_point;}
    void SetPrev(Node<T>* prev_point) {this->prev  = prev_point;}

};

template<typename T>
class LinkedList
{
private:
    Node<T>* begin;
    Node<T>* end;
    int length;
public:
    LinkedList();
    LinkedList(T* items, int count);
    LinkedList(const LinkedList <T>* list);
    void SetBegin(Node<T>* begin_point);
    void SetEnd(Node<T>* end_point);
    void SetLength(int count);
    Node<T>* GetBegin() const;
    Node<T>* GetEnd() const;
    int GetLength() const;
    
public:
    Node<T>* FindWithIndex(int index);
    T Get(int index);
    T GetFirst();
    T GetLast();
    void InsertAt(T item, int index);
    void Append(T item);
    void Prepend(T item);
    void Remove(int index);
    void Print();
    LinkedList<T>* GetSubList(int start, int end);
    LinkedList<T>* Concat(LinkedList<T>* list);
};

template<typename T>
LinkedList<T>::LinkedList() : begin(NULL), end(NULL), length(0) {}

template<typename T>
LinkedList<T>::LinkedList(T* items, int count) : length(count)
{
    Node<T>* NodePreviosPointer = new Node<T>(items[0]);
    SetBegin(NodePreviosPointer);
    for (int i = 1; i < length; i++)
    {
        Node<T>* NodePointer = new Node<T>(items[i]);
        NodePointer->SetPrev(NodePreviosPointer);
        NodePreviosPointer->SetNext(NodePointer);
        NodePreviosPointer = NodePointer;
    }
    SetEnd(NodePreviosPointer);
}
template<typename T>
LinkedList<T>::LinkedList(const LinkedList <T>* list)
{
    this->SetLength(list->GetLength());
    Node<T>* SourceNodePointer = list->GetBegin();
    Node<T>* CopyNodePointer = new Node<T>(SourceNodePointer->GetValue());
    this->SetBegin(CopyNodePointer);
    while (SourceNodePointer != list->GetEnd())
    {
        Node<T>* PreviousCopyNodePointer = CopyNodePointer;
        SourceNodePointer = SourceNodePointer->GetNext();
        CopyNodePointer = new Node<T>(SourceNodePointer->GetValue());
        CopyNodePointer->SetPrev(PreviousCopyNodePointer);
        PreviousCopyNodePointer->SetNext(CopyNodePointer);
    }
    this->SetEnd(CopyNodePointer);
}
template<typename T>
Node<T>* LinkedList<T>::GetBegin() const {return this->begin;}
template<typename T>
Node<T>* LinkedList<T>::GetEnd() const {return this->end;}
template<typename T>
int LinkedList<T>::GetLength() const {return this->length;}
template<typename T>
void LinkedList<T>::SetBegin(Node<T>* begin_point) {this->begin = begin_point;}
template<typename T>
void LinkedList<T>::SetEnd(Node<T>* end_point) {this->end = end_point;}
template<typename T>
void LinkedList<T>::SetLength(int count) {this->length = count;}
template<typename T>
Node<T>* LinkedList<T>::FindWithIndex(int index)
{
    int counter;
    Node<T>* temp;
    if (index == -1) { return NULL; }
    if (index <= this->GetLength() / 2)
    {
        counter = 0;
        temp = this->GetBegin();
        while (counter != index)
        {
            temp = temp->GetNext();
            counter++;
        }
    }
    else
    {
        counter = this->GetLength() - 1;
        temp = this->GetEnd();
        while (counter != index)
        {
            temp = temp->GetPrev();
            counter--;
        }
    }
    return temp;
}
template<typename T>
T LinkedList<T>::Get(int index) {return this->FindWithIndex(index)->GetValue();}
template<typename T>
T LinkedList<T>::GetFirst() {return this->Get(0);}
template<typename T>
T LinkedList<T>::GetLast() {return this->Get(this->GetLength() - 1);}
template<typename T>
void LinkedList<T>::InsertAt(T item, int index)
{
    Node<T>* node_1 = NULL;
    Node<T>* node_2 = new Node<T>(item);
    if (index == 0 && this->FindWithIndex(index) == NULL)
    {
        this->SetBegin(node_2);
        this->SetEnd(node_2);
    }
    else if (index == 0)
    {
        node_1 = this->FindWithIndex(index);
        node_1->SetPrev(node_2);
        node_2->SetNext(node_1);
        this->SetBegin(node_2);
    }
    else
    {
        node_1 = this->FindWithIndex(index);
        node_2->SetPrev(node_1->GetPrev());
        node_1->SetPrev(node_2);
        node_2->SetNext(node_1);
        node_2->GetPrev()->SetNext(node_2);
    }
    this->SetLength(this->GetLength() + 1);
}
template<typename T>
void LinkedList<T>::Prepend(T item) {this->InsertAt(item, 0);}
template<typename T>
void LinkedList<T>::Append(T item)
{
    Node<T>* node_1 = NULL;
    Node<T>* node_2 = new Node<T>(item);
    if (this->FindWithIndex(this->GetLength() - 1) == NULL)
    {
        this->SetBegin(node_2);
        this->SetEnd(node_2);
    }
    else
    {
        node_1 = this->FindWithIndex(this->GetLength() - 1);
        node_2->SetPrev(node_1);
        node_1->SetNext(node_2);
        this->SetEnd(node_2);
    }
    this->SetLength(this->GetLength() + 1);
}
template<typename T>
void LinkedList<T>::Remove(int index)
{
    Node<T>* data_point = this->FindWithIndex(index);
    if (index == 0)
    {
        data_point->GetNext()->SetPrev(NULL);
        this->SetBegin(data_point->GetNext());
    }
    else if (index == this->GetLength() - 1)
    {
        data_point->GetPrev()->SetNext(NULL);
        this->SetEnd(data_point->GetPrev());
    }
    else
    {
        data_point->GetNext()->SetPrev(data_point->GetPrev());
        data_point->GetPrev()->SetNext(data_point->GetNext());
    }
    delete data_point;
    this->SetLength(this->GetLength() - 1);;

}
template<typename T>
LinkedList<T>* LinkedList<T>::Concat(LinkedList<T>* list)
{
    LinkedList<T>* newList = new LinkedList<T>(this);
    newList->SetLength(newList->GetLength() + list->GetLength());
    newList->GetEnd()->SetNext(list->GetBegin());
    list->GetBegin()->SetPrev(newList->GetEnd());
    newList->SetEnd(list->GetEnd());
    return newList;
}
template<typename T>
LinkedList<T>* LinkedList<T>::GetSubList(int start, int end)
{
    LinkedList<T>* subList = new LinkedList<T>();
    subList->SetLength(end - start + 1);
    Node<T>* SourceNodePointer = this->FindWithIndex(start);
    Node<T>* CopyNodePointer = new Node<T>(SourceNodePointer->GetValue());
    subList->SetBegin(CopyNodePointer);
    while (SourceNodePointer != FindWithIndex(end))
    {
        Node<T>* PreviousCopyNodePointer = CopyNodePointer;
        SourceNodePointer = SourceNodePointer->GetNext();
        CopyNodePointer = new Node<T>(SourceNodePointer->GetValue());
        CopyNodePointer->SetPrev(PreviousCopyNodePointer);
        PreviousCopyNodePointer->SetNext(CopyNodePointer);
    }
    subList->SetEnd(CopyNodePointer);
    return subList;
}
template<typename T>
void LinkedList<T>::Print()
{
    Node<T>* data_point = this->GetBegin();
    for (int i = 0; i < this->GetLength(); i++)
    {
        cout << data_point->GetValue()<<"  ";
        data_point =data_point->GetNext();
    }
    cout << endl;
}
#endif /* LinkedList_hpp */
