//
//  VectorList.hpp
//
//

#ifndef VectorList_hpp
#define VectorList_hpp

#include "LinkedListSequence.hpp"
#include <cmath>
#include "complex.hpp"
#include <complex>
#include <iostream>
Complex sqrt(Complex  &comp);
template <class T> class VectorList
{
private:
    LinkedListSequence<T> *seq;
public:
    VectorList();
    VectorList(int size);
    VectorList(T* arr,int count);
    VectorList(VectorList& v2);
    void Append(T item);
    T Get(int index);
    T& operator[](int index);
    VectorList* Sum_VectorLists(VectorList& v2);
    VectorList* Minus_VectorLists(VectorList& v2);
    VectorList&  Multiply_on_scalar(int scalar);
    T Norm();
    T Dot_product(VectorList& v2);
    void Print_VectorList();
    int GetLength();
    VectorList& operator+=(VectorList& v2);
    VectorList& operator+(VectorList& v2);
    VectorList& operator-(VectorList& v2);
    VectorList& operator-=(VectorList& v2);

};

template <class T>
VectorList<T>::VectorList()
{
    seq = new LinkedListSequence<T>();
}
template <class T>
VectorList<T>::VectorList(int size)
{
    seq=new LinkedListSequence<T>(size);
}
template <class T>
VectorList<T>::VectorList(T* arr,int count)
{
    seq=new LinkedListSequence<T>(arr,count);
}
template <class T>
VectorList<T>::VectorList(VectorList& v2)
{
    seq=new LinkedListSequence<T>((*v2.seq));
}
template <class T>
int VectorList <T>::GetLength()
{
    return seq->GetLength();
}

template <class T>
T VectorList<T>::Get(int index) {
    return seq->Get(index);
}
template <class T>
void VectorList<T>::Append(T item)
{
    this->seq->Append(item);
}
template <class T>
T& VectorList<T>::operator[](int index)
{
    if (index<0 )
        assert(0);
    return (this->seq)[index];
   // try {
   //     return (this->seq)[index];
   // }
   // catch(Myexception ex)
   // {
   //     throw ex;
   // }
}
template <class T>
VectorList<T>& VectorList<T>::operator+=(VectorList& v2)
{

    this->seq=this->Sum_VectorLists(v2)->seq;
    return *this;
}
template <class T>
VectorList<T>& VectorList<T>::operator-(VectorList& v2)
{
    this->seq=this->Minus_VectorLists(v2)->seq;
    return *this;
}
template <class T>
VectorList<T>& VectorList<T>::operator-=(VectorList& v2)
{
    this->seq=this->Minus_VectorLists(v2)->seq;
    return *this;
}
template <class T>
VectorList<T> & VectorList<T>::operator+(VectorList& v2)
{
    this->seq=this->Sum_VectorLists(v2)->seq;
    return *this;
}


template <class T>
VectorList<T>* VectorList<T>::Sum_VectorLists(VectorList& v2)
{
    int count_max=max(v2.seq->GetLength(),this->seq->GetLength());
    VectorList<T> *res=new VectorList<T>();
    if (v2.seq->GetLength()>this->seq->GetLength())
    {
        for (int i=0;i<v2.seq->GetLength();i++)
            if (i<this->seq->GetLength())
                res->Append(v2.seq->Get(i)+this->seq->Get(i));
            else
                res->Append(v2.seq->Get(i));

    }
    else
    {
        for (int i=0;i<this->seq->GetLength();i++)
            if (i<v2.seq->GetLength())
                res->Append(this->seq->Get(i)+v2.seq->Get(i));
            else
                res->Append(this->seq->Get(i));
    }
    return res;
}
template <class T>
VectorList<T>* VectorList<T>::Minus_VectorLists(VectorList& v2)
{
    int count_max=max(v2.seq->GetLength(),this->seq->GetLength());
    VectorList<T> *res=new VectorList<T>();
    if (v2.seq->GetLength()>this->seq->GetLength())
    {
        for (int i=0;i<v2.seq->GetLength();i++)
            if (i<this->seq->GetLength())
                res->Append(this->seq->Get(i)-v2.seq->Get(i));
            else
                res->Append((-1)*v2.seq->Get(i));

    }
    else
    {
        for (int i=0;i<this->seq->GetLength();i++)
            if (i<v2.seq->GetLength())
                res->Append(this->seq->Get(i)-v2.seq->Get(i));
            else
                res->Append(this->seq->Get(i));
    }
    return res;
}
template <class T>
VectorList<T>& VectorList<T>::Multiply_on_scalar(int scalar)
{
    VectorList<T> res= VectorList<T>();
    for (int i=0;i< this->seq->GetLength();i++)
        res.Append(this->Get(i)*scalar);
    return res;
}

template<class T>
T VectorList<T>::Norm(){
    T sm;
    sm=0;
    for (int i=0;i< this->seq->GetLength();i++)
    {
        sm+=this->Get(i)*this->Get(i);
    }
    return sqrt(sm);
}
template<class T>
T VectorList<T>::Dot_product(VectorList& v2){
    T sm=0;
    if (v2.seq->Get_Length() > this->seq->Get_Length()) {
        for (int i = 0; i < this->seq->Get_Length(); i++)
            sm += this->Get(i) * v2.Get(i);
    }
    else {
        for (int i = 0; i < v2.seq->Get_Length(); i++)
        {
            sm += this->Get(i) * v2.Get(i);

        }
    }
    return sm;
}
//    try {
//        if (v2.seq->Get_Length() > this->seq->Get_Length()) {
//            for (int i = 0; i < this->seq->Get_Length(); i++)
//                sm += this->Get(i) * v2.Get(i);
//        }
//        else {
//            for (int i = 0; i < v2.seq->Get_Length(); i++)
//            {
//
//                sm += this->Get(i) * v2.Get(i);
//
//            }
//        }
//        return sm;
//    }
//    catch(Myexception Ex)
//    {
//        Ex.show();
//    }

template <class T>
void VectorList<T>::Print_VectorList()
{
    for (int i=0;i<this->seq->GetLength();i++)
        cout<< this->seq->Get(i)<<"  ";
    cout<<endl;
}



#endif /* VectorList_hpp */
