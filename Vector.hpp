//
//  Vector.hpp
//
//
//
//
#ifndef Vector_hpp
#define Vector_hpp
#include "Sequence.hpp"
#include "DynamicArray.hpp"
#include "ArraySequence.hpp"
#include <complex>
#include <iostream>
#include <cmath>
#include "complex.hpp"

Complex sqrt(Complex  &comp);

template <typename T>
class Vector
{
private:
    ArraySequence<T>* items;
    
public:
    Vector();
    Vector(int count);
    Vector(T* items, int count);
   // Vector(const Vector & vector);
 //   ~Vector();
    
    T Get(int inndex);
    int GetLength();
    void Append(T item);
    T& operator [] (int index); // переопредеоение квадратных скобок
    
    Vector* Sum_vectors(Vector& vector);
    Vector* Minus_vectors(Vector& vector);
    Vector&  Multiply_on_scalar(int scalar);
    T Norm();
    T Dot_product(Vector& vector);
    void Print_V();
    
    Vector& operator += (Vector& vector);
    Vector& operator + (Vector& vector);
    Vector& operator - (Vector& vector);
    Vector& operator -= (Vector& vector);
    
};

template <typename T>
Vector<T>::Vector()
{items = new ArraySequence<T>();}

template <typename T>
Vector<T>::Vector(int count)
{items = new ArraySequence<T>(count);}

template <typename T>
Vector<T>::Vector(T* array, int count)
{items = new ArraySequence<T>(array, count);}

//template <typename T>
//Vector<T>::Vector(const Vector & vector)
//{items = new ArraySequence<T>((*vector));}

template <typename T>
int Vector<T>::GetLength()
{return items->GetLength();}

template <class T>
T Vector<T>::Get(int index)
{return this->items->Get(index);}

template <class T>
void Vector<T>::Append(T item)
{this->items->Append(item);}

template <class T>
T& Vector<T>::operator[](int index)
{
    return this->items->Get(index);
/*
    try {return (this->items)[index];}
    catch(Myexception ex)
    {throw ex;}
 */
}

template <class T>
Vector<T>& Vector<T>::operator += (Vector& vector)
{
    this->items = this->Sum_vectors(vector)->items;
    return *this;
}

template <class T>
Vector<T>& Vector<T>::operator - (Vector& vector)
{
    this->items = this->Minus_vectors(vector)->items;
    return *this;
}

template <class T>
Vector<T>& Vector<T>::operator -= (Vector& vector)
{
    this->items = this->Minus_vectors(vector)->items;
    return *this;
}

template <class T>
Vector<T> & Vector<T>::operator + (Vector& vector)
{
    this->items = this->Sum_vectors(vector)->items;
    return *this;
}

template <class T>
Vector<T>* Vector<T>::Sum_vectors(Vector& vector2)
{
    int count_max = max(vector2.items->GetLength(),this->items->GetLength());
    Vector<T> *result = new Vector<T>();
    if (vector2.items->GetLength() > this->items->GetLength())
    {
        for (int i=0; i<vector2.items->GetLength(); i++)
            if (i < this->items->GetLength())
                result->Append(vector2.items->Get(i)+this->items->Get(i));
             else
                result->Append(vector2.items->Get(i));
    }
    else
    {
        for (int i=0;i<this->items->GetLength();i++)
            if (i<vector2.items->GetLength())
                result->Append(this->items->Get(i)+vector2.items->Get(i));
            else
                result->Append(this->items->Get(i));
    }
    return result;
}

template <class T>
Vector<T>* Vector<T>::Minus_vectors(Vector& vector2)
{
    int count_max=max(vector2.items->GetLength(),this->items->GetLength());
    Vector<T> * result = new Vector<T>();
    if (vector2.items->GetLength() > this->items->GetLength())
    {
        for (int i=0; i < vector2.items->GetLength(); i++)
            if (i < this->items->GetLength())
                result->Append(this->items->Get(i)-vector2.items->Get(i));
            else
                result->Append((-1) * vector2.items->Get(i));
    }
    else
    {
        for (int i=0; i < this->items->GetLength(); i++)
            if (i < vector2.items->GetLength())
                result->Append(this->items->Get(i)-vector2.items->Get(i));
            else
                result->Append(this->items->Get(i));
    }
    return result;
}


template <class T>
Vector<T>& Vector<T>::Multiply_on_scalar(int scalar)
{
    Vector<T> result = Vector<T>();
    for (int i=0; i< this->items->GetLength(); i++)
        result.Append(this->Get(i)*scalar);
    return result;
}

template<class T>
T Vector<T>::Norm()
{
  T quad_norm;
  quad_norm=0;
  for (int i=0; i< this->items->GetLength();i++)
  {
      quad_norm += this->Get(i)*this->Get(i);
  }
  return sqrt(quad_norm);
}

template<class T>
T Vector<T>::Dot_product(Vector& vector2)  // скалярн.
{
    T sm=0;
    if (vector2.items->GetLength() > this->items->GetLength())
    {
        for (int i = 0; i < this->items->GetLength(); i++)
            sm += this->Get(i) * vector2.Get(i);
    }
    else
    {
        for (int i = 0; i < vector2.items->GetLength(); i++)
        {
            sm += this->Get(i) * vector2.Get(i);
        }
    }
    return sm;

    
  /*
    try {
        if (vector2.items->GetLength() > this->items->GetLength()) {
            for (int i = 0; i < this->items->GetLength(); i++)
                sm += this->Get(i) * vector2.Get(i);
        }
        else {
            for (int i = 0; i < vector2.items->Get_Length(); i++) {

                sm += this->Get(i) * vector2.Get(i);
            }
        }
        return sm;
    }
    catch(Myexception Ex)
    {
        Ex.show();
    }*/
}

template <class T>
void Vector<T>::Print_V()
{
    for (int i=0;i<this->items->GetLength();i++)
        cout<< this->items->Get(i)<<"  ";
    cout<<endl;
}
#endif /* Vector_hpp */
