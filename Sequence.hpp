//
//  Sequence.hpp
// 
//
//
//


#ifndef Sequence_hpp
#define Sequence_hpp


using namespace std;
template<typename T>
class Sequence
{
public:
    virtual T GetFirst() const = 0;
    virtual T GetLast() const = 0;
    virtual T Get(int index) const = 0;
    virtual int GetLength() = 0;
    virtual void Remove(int index) = 0;
    virtual void Append(T item) = 0;
    virtual void Prepend(T item) = 0;
    virtual void InsertAt(T item,int index) = 0;
    virtual Sequence<T>* Concat(Sequence<T>* list) const = 0;
    virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) const = 0;
   // virtual T& operator[](int index)                                        = 0;
    
};


#endif /* Sequence_hpp */
