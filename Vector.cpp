//
//  Vector.cpp
//
//
//
//

#include "Vector.hpp"
Complex sqrt(Complex &comp)
{
    complex <double> res(comp.Get_rl(),comp.Get_im());
    res=sqrt(res);
    Complex result=Complex (res.real(),res.imag());
    return result;
}
