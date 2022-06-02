//
//  main.cpp
//  
//
//


#include <iostream>
//#include "menu.hpp"
#include "LinkedList.hpp"
//#include "LinkedListTests.hpp"
//#include "LinkedListSequenceTests.hpp"
//#include "DynamicArrayTests.hpp"
//#include "ArraySequenceTests.hpp"
#include "ArraySequence.hpp"
#include "LinkedListSequence.hpp"
#include "DynamicArray.hpp"
#include "Vector.hpp"
#include "VectorList.hpp"
//#include "Test_.hpp"

using namespace std;

void Test_DynamicArray ();
void Test_ArraySequence ();
void Test_LinkedList ();

void Test_Vector();
void Test_Vector_Complex();

int menu_var(int count);
int main_menu ();
int input_count ();
int * input_arr_i (int count);
double * input_arr_d (int count);
Complex * input_arr_c (int count);
Complex input_value ();
void Menu();


int main()
{
 /*
    LinkedListTests* testList=new LinkedListTests();
    DynamicArrayTests* testArray = new DynamicArrayTests();
    LinkedListSequenceTests* testListSequence = new LinkedListSequenceTests();
    ArraySequenceTests* testArraySequence = new ArraySequenceTests();
    
    testArray->Test();
    testList->Test();
    testListSequence->Test();
    testArraySequence->Test();
  

    cout << "SecondLaba work correctly\n";
  */
    cout<<endl;
    cout<<endl;
    
    
  
    //Test_DynamicArray();
    //Test_ArraySequence();
    //Test_LinkedList();
    //Test_Vector_Complex();
    Menu();
}





int menu_var(int count)
{
    int v;
    cin>>v;
    while ( v < 0 || v > count) {
        cout<<("ошибка, попробйте еще раз==>"); // выводим сообщение об ошибке
        cin>>v; // считываем строку повторно
    }
    return v;
}

int main_menu ()
{
    int r;
    cout<<"ОСНОВНОЕ ДИАЛОГОВОЕ МЕНЮ!"<< endl;
    cout<<"1 - ВЕКТОР ArraySequence<int>          / ручной ввод и расчет"<< endl;
    cout<<"2 - ВЕКТОР ArraySequence<double>       / ручной ввод и расчет"<< endl;
    cout<<"3 - ВЕКТОР ArraySequence<complex>      / ручной ввод и расчет"<< endl;
    cout<<"4 - ВЕКТОР LinkedListSequence<int>     / ручной ввод и расчет"<< endl;
    cout<<"5 - ВЕКТОР LinkedListSequence<double>  / ручной ввод и расчет"<< endl;
    cout<<"6 - ВЕКТОР LinkedListSequence<complex> / ручной ввод и расчет"<< endl;
    cout<<"7 - ТЕСТ ВЕКТОР"<< endl;;
    cout<<"0 - ВЫХОД ИЗ ПРОГРАММЫ!"<<endl;
    cout<<"Введите цифру от 0 до 7 ==> ";
    r=menu_var(7);
    return r;
}


int input_count ()
{
    int result;
    cout<<"Ввод размерности вектора ==> ";
    cin>> result;
    while (result<=0)
    {
        cout<<"ошибка, попробуйте еще раз (введите положительное целое число)"<<endl;
        cout<<"Ввод размерности вектора ==> ";
        cin>> result;
    }
    return result;
}

int * input_arr_i (int count)
{
    int * result = new int [count];
    cout<<"Ввод Вектора размерностью = "<< count << " <int>:" << endl;
    for (int i=0; i<count; i++)
    {
        cout<< "["<<i<<"]"<<" = ";
        cin>>result[i];
    }
    return result;
}

double * input_arr_d (int count)
{
    double * result = new double [count];
    cout<<"Ввод Вектора размерностью = "<< count << " <double>:" << endl;
    for (int i=0; i<count; i++)
    {
        cout<< "["<<i<<"]"<<" = ";
        cin>>result[i];
    }
    return result;
}

Complex input_value_c ()
{
    double real,imag;
    cout<<"real = ";
    cin>>real;
    cout<<"imag = ";
    cin>>imag;
    Complex result = Complex(real,imag);
    return result;
}

Complex * input_arr_c (int count)
{
    Complex * result = new Complex[count];
    cout<<"Ввод Вектора размерностью = "<< count << " <double> :" << endl;
    for (int i=0; i<count; i++)
    {
        result[i]=input_value_c();
    }
    return result;
}

void Menu()
{



int c;


while (1==1)
{
    

    c=main_menu();
    switch (c)
    {
        case 0:
      
        return ;
            
        case 1: //ВЕКТОР <int> / ручной ввод и расчет
        {
            cout<<"Введите вектор А"<< endl;
            int count_a = input_count();
            int * arA = input_arr_i(count_a);
            Vector<int> vector_A=Vector<int>(arA, count_a);
            cout<<"введен вектор А : ";
            vector_A.Print_V();
            
            cout<<"Введите вектор B"<< endl;
            int count_b = input_count();
            int * arB = input_arr_i(count_b);
            Vector<int> vector_B=Vector<int>(arB, count_b);
            cout<<"введен вектор B : ";
            vector_B.Print_V();
            
            int scalar_int;
            cout<<"Введите <скаляр> ==> ";
            cin>> scalar_int;
            
            cout<<endl;
            cout<<"##### РЕЗУЛЬТАТЫ РАСЧЕТОВ #####:"<<endl;
            cout<<"Вектор А   = ";
            vector_A.Print_V();
            cout<<"Вектор B   = ";
            vector_B.Print_V();
            Vector<int> * vector_sum = vector_A.Sum_vectors(vector_B);
            cout<<"Вектор sum = ";
            (*vector_sum).Print_V();
            cout<<"Скаляр = "<< scalar_int<< endl;
            Vector<int> vector_B_scalar = vector_B.Multiply_on_scalar(scalar_int);
            cout<<"<скаляр> * Вектор В = ";
            vector_B_scalar.Print_V();
            cout<<"<Вектор В>.norm = "<< vector_B.Norm()<<endl;
            cout<<"######___________________#####"<<endl;
            
            delete [] arA;
            delete [] arB;
            
            
        }
            
            break;
            
        case 2: //ВЕКТОР <double> / ручной ввод и расчет
        {
            cout<<"Введите вектор А"<< endl;
            int count_a = input_count();
            double * arA = input_arr_d(count_a);
            Vector<double> vector_A=Vector<double>(arA, count_a);
            cout<<"введен вектор А : ";
            vector_A.Print_V();
            
            cout<<"Введите вектор B"<< endl;
            int count_b = input_count();
            double * arB = input_arr_d(count_b);
            Vector<double> vector_B=Vector<double>(arB, count_b);
            cout<<"введен вектор B : ";
            vector_B.Print_V();
            
            int scalar_int;
            cout<<"Введите <скаляр> ==> ";
            cin>> scalar_int;
            
            cout<<endl;
            cout<<"##### РЕЗУЛЬТАТЫ РАСЧЕТОВ #####:"<<endl;
            cout<<"Вектор А   = ";
            vector_A.Print_V();
            cout<<"Вектор B   = ";
            vector_B.Print_V();
            Vector<double> * vector_sum = vector_A.Sum_vectors(vector_B);
            cout<<"Вектор sum = ";
            (*vector_sum).Print_V();
            cout<<"Скаляр = "<< scalar_int<< endl;
            Vector<double> vector_B_scalar = vector_B.Multiply_on_scalar(scalar_int);
            cout<<"<скаляр> * Вектор В = ";
            vector_B_scalar.Print_V();
            cout<<"<Вектор В>.norm = "<< vector_B.Norm()<<endl;
            cout<<"######___________________#####"<<endl;
            
            delete [] arA;
            delete [] arB;
            
            
        }
            break;
            
        case 3: //ВЕКТОР <Complex> / ручной ввод и расчет

        {
            cout<<"Введите вектор А"<< endl;
            int count_a = input_count();
            Complex * arA = input_arr_c(count_a);
            Vector<Complex> vector_A=Vector<Complex>(arA, count_a);
            cout<<"введен вектор А : ";
            vector_A.Print_V();
            
            cout<<"Введите вектор B"<< endl;
            int count_b = input_count();
            Complex * arB = input_arr_c(count_b);
            Vector<Complex> vector_B=Vector<Complex>(arB, count_b);
            cout<<"введен вектор B : ";
            vector_B.Print_V();
            
            int scalar_int;
            cout<<"Введите <скаляр> ==> ";
            cin>> scalar_int;
            
            cout<<endl;
            cout<<"##### РЕЗУЛЬТАТЫ РАСЧЕТОВ #####:"<<endl;
            cout<<"Вектор А   = ";
            vector_A.Print_V();
            cout<<"Вектор B   = ";
            vector_B.Print_V();
            Vector<Complex> * vector_sum = vector_A.Sum_vectors(vector_B);
            cout<<"Вектор sum = ";
            (*vector_sum).Print_V();
            
            cout<<"Скаляр = "<<scalar_int<<endl;
            
            Vector<Complex> vector_B_scalar = vector_B.Multiply_on_scalar(scalar_int);
            
            cout<<"<скаляр> * Вектор В = ";
            vector_B_scalar.Print_V();
            
            cout<<"<Вектор В>.norm = ";
            vector_B.Norm().print();
            cout<<endl;
            cout<<"######___________________#####"<<endl;
            
            delete [] arA;
            delete [] arB;
            
            
        }
            
            
            
            break;
            
            
        case 4: //ВЕКТОР <int> / ручной ввод и расчет
        {
            cout<<"Введите вектор А"<< endl;
            int count_a = input_count();
            int * arA = input_arr_i(count_a);
            Vector<int> vector_A=Vector<int>(arA, count_a);
            cout<<"введен вектор А : ";
            vector_A.Print_V();
            
            cout<<"Введите вектор B"<< endl;
            int count_b = input_count();
            int * arB = input_arr_i(count_b);
            Vector<int> vector_B=Vector<int>(arB, count_b);
            cout<<"введен вектор B : ";
            vector_B.Print_V();
            
            int scalar_int;
            cout<<"Введите <скаляр> ==> ";
            cin>> scalar_int;
            
            cout<<endl;
            cout<<"##### РЕЗУЛЬТАТЫ РАСЧЕТОВ #####:"<<endl;
            cout<<"Вектор А   = ";
            vector_A.Print_V();
            cout<<"Вектор B   = ";
            vector_B.Print_V();
            Vector<int> * vector_sum = vector_A.Sum_vectors(vector_B);
            cout<<"Вектор sum = ";
            (*vector_sum).Print_V();
            cout<<"Скаляр = "<< scalar_int<< endl;
            Vector<int> vector_B_scalar = vector_B.Multiply_on_scalar(scalar_int);
            cout<<"<скаляр> * Вектор В = ";
            vector_B_scalar.Print_V();
            cout<<"<Вектор В>.norm = "<< vector_B.Norm()<<endl;
            cout<<"######___________________#####"<<endl;
            
            delete [] arA;
            delete [] arB;
            
            
        }
            
            break;
            
        case 5: //ВЕКТОР <double> / ручной ввод и расчет
        {
            cout<<"Введите вектор А"<< endl;
            int count_a = input_count();
            double * arA = input_arr_d(count_a);
            Vector<double> vector_A=Vector<double>(arA, count_a);
            cout<<"введен вектор А : ";
            vector_A.Print_V();
            
            cout<<"Введите вектор B"<< endl;
            int count_b = input_count();
            double * arB = input_arr_d(count_b);
            Vector<double> vector_B=Vector<double>(arB, count_b);
            cout<<"введен вектор B : ";
            vector_B.Print_V();
            
            int scalar_int;
            cout<<"Введите <скаляр> ==> ";
            cin>> scalar_int;
            
            cout<<endl;
            cout<<"##### РЕЗУЛЬТАТЫ РАСЧЕТОВ #####:"<<endl;
            cout<<"Вектор А   = ";
            vector_A.Print_V();
            cout<<"Вектор B   = ";
            vector_B.Print_V();
            Vector<double> * vector_sum = vector_A.Sum_vectors(vector_B);
            cout<<"Вектор sum = ";
            (*vector_sum).Print_V();
            cout<<"Скаляр = "<< scalar_int<< endl;
            Vector<double> vector_B_scalar = vector_B.Multiply_on_scalar(scalar_int);
            cout<<"<скаляр> * Вектор В = ";
            vector_B_scalar.Print_V();
            cout<<"<Вектор В>.norm = "<< vector_B.Norm()<<endl;
            cout<<"######___________________#####"<<endl;
            
            delete [] arA;
            delete [] arB;
            
            
            
        }
            
            
            break;
            
        case 6: //ВЕКТОР <Complex> / ручной ввод и расчет
            
        {
            cout<<"Введите вектор А"<< endl;
            int count_a = input_count();
            Complex * arA = input_arr_c(count_a);
            Vector<Complex> vector_A=Vector<Complex>(arA, count_a);
            cout<<"введен вектор А : ";
            vector_A.Print_V();
            
            cout<<"Введите вектор B"<< endl;
            int count_b = input_count();
            Complex * arB = input_arr_c(count_b);
            Vector<Complex> vector_B=Vector<Complex>(arB, count_b);
            cout<<"введен вектор B : ";
            vector_B.Print_V();
            
            int scalar_int;
            cout<<"Введите <скаляр> ==> ";
            cin>> scalar_int;
            
            cout<<endl;
            cout<<"##### РЕЗУЛЬТАТЫ РАСЧЕТОВ #####:"<<endl;
            cout<<"Вектор А   = ";
            vector_A.Print_V();
            cout<<"Вектор B   = ";
            vector_B.Print_V();
            Vector<Complex> * vector_sum = vector_A.Sum_vectors(vector_B);
            cout<<"Вектор sum = ";
            (*vector_sum).Print_V();
            
            cout<<"Скаляр = "<<scalar_int<<endl;
            
            Vector<Complex> vector_B_scalar = vector_B.Multiply_on_scalar(scalar_int);
            
            cout<<"<скаляр> * Вектор В = ";
            vector_B_scalar.Print_V();
            
            cout<<"<Вектор В>.norm = ";
            vector_B.Norm().print();
            cout<<endl;
            cout<<"######___________________#####"<<endl;
            
            delete [] arA;
            delete [] arB;
            
            
        }
            
            break;
            
        case 7: //сформировать тесты и записать в файл для комплексных чисел
            Test_DynamicArray();
            cout<<"#____________________________________________________________________________#"<<endl;
            cout<<"#____________________________________________________________________________#"<<endl;
            Test_ArraySequence();
            cout<<"#____________________________________________________________________________#"<<endl;
            cout<<"#____________________________________________________________________________#"<<endl;
            Test_LinkedList();
            cout<<"#____________________________________________________________________________#"<<endl;
            cout<<"#____________________________________________________________________________#"<<endl;
            Test_Vector_Complex();
            cout<<"#____________________________________________________________________________#"<<endl;
            Test_Vector();

            break;
            
    }

}
return ;
}



















void Test_DynamicArray  ()
{
    DynamicArray<int> test00 = DynamicArray<int>();
    cout<<"test00 = DynamicArray<int>() = ";
    test00.Print();
    cout<<"Size ="<< test00.GetSize()<<"  Count = "<<test00.GetCount()<<endl;
    cout<<endl;
    
    
    DynamicArray<int> test01 = DynamicArray<int>(12);
    cout<<"test01 = DynamicArray<int>(12) = ";
    test01.Print();
    cout<<"Size ="<< test01.GetSize()<<"  Count = "<<test01.GetCount()<<endl;
    cout<<endl;
    
    DynamicArray<int> test02 = DynamicArray<int>(5, 7);
    cout<<"test02 = DynamicArray<int>(5, 7) = ";
    test02.Print();
    cout<<"Size ="<< test02.GetSize()<<"  Count = "<<test02.GetCount()<<endl;
    cout<<endl;
    
    int vector[] {2,6,4,8,11,21,4,0,2,34};
    DynamicArray<int> test03 = DynamicArray<int>(vector, 9);
    cout<<"test03 = DynamicArray<int>(vector, 9) = ";
    test03.Print();
    cout<<"Size ="<< test03.GetSize()<<"  Count = "<<test03.GetCount()<<endl;
    cout<<endl;
    
    DynamicArray<int> test04 = DynamicArray<int>(&test03);
    cout<<"test04 = DynamicArray<int>(&test03) = ";
    test04.Print();
    cout<<"Size ="<< test04.GetSize()<<"  Count = "<<test04.GetCount()<<endl;
    cout<<endl;
    
    DynamicArray<int> test05 = DynamicArray<int>(test03);
    cout<<"test05 = DynamicArray<int>(test03) = ";
    test05.Print();
    cout<<"Size ="<< test05.GetSize()<<"  Count = "<<test05.GetCount()<<endl;
    cout<<endl;
    
    
    cout<<"test05.Get(5) = "<<test05.Get(5)<<endl;
    cout<<endl;
    
    test03.Set(5, 99);
    cout<<"test03.Set(5, 99) = ";
    test03.Print();
    cout<<"Size ="<< test03.GetSize()<<"  Count = "<<test03.GetCount()<<endl;
    cout<<endl;
    
    cout<<"test04 = ";
    test04.Print();
    cout<<"Size ="<< test04.GetSize()<<"  Count = "<<test04.GetCount()<<endl;
    test04.Resize(5);
    cout<<"test04.Resize(5) = ";
    test04.Print();
    cout<<"Size ="<< test04.GetSize()<<"  Count = "<<test04.GetCount()<<endl;
    cout<<endl;
    
    cout<<"test03 = ";
    test03.Print();
    cout<<"Size ="<< test03.GetSize()<<"  Count = "<<test03.GetCount()<<endl;
    test03.Resize(20);
    cout<<"test03.Resize(20) = ";
    test03.Print();
    cout<<"Size ="<< test03.GetSize()<<"  Count = "<<test03.GetCount()<<endl;
    cout<<endl;
    
    cout<<"test03 = ";
    test03.Print();
    cout<<"Size ="<< test03.GetSize()<<"  Count = "<<test03.GetCount()<<endl;
    test03.Remove(1);
    cout<<"test03.Remove(1) = ";
    test03.Print();
    cout<<"Size ="<< test03.GetSize()<<"  Count = "<<test03.GetCount()<<endl;
    cout<<endl;
    
    cout<<"#################### Тесты DynamicArray завершены - ок"<< endl;
    
}


void Test_ArraySequence ()
{
    ArraySequence<int> test00 = ArraySequence<int>();
    cout<<"test00 = ArraySequence<int>() = ";
    test00.Print();
    cout<<"test00.GetLength() = "<< test00.GetLength()<<endl;
    cout<<endl;
    
    int vector[] {12,16,41,18,11,21,4,10,21,34};
    ArraySequence<int> test01 = ArraySequence<int>(vector, 5);
    cout<<"test01 = ArraySequence<int>(vector, 5) = ";
    test01.Print();
    cout<<"test01.GetLength() = "<< test01.GetLength()<<endl;
    cout<<endl;
    
    ArraySequence<int> test02 = ArraySequence<int>(vector, 10);
    cout<<"test02 = ArraySequence<int>(vector, 10) = ";
    test02.Print();
    cout<<"test02.GetLength() = "<< test02.GetLength()<<endl;
    cout<<endl;
    
   // ArraySequence<int> * p;
   // p = & test02;
  //  ArraySequence<int> test03 = ArraySequence<int>(test02);
  //  cout<<"test03 = ArraySequence<int>(test02) = ";
  //  test03.Print();
  //  cout<<"test03.GetLength() = "<< test03.GetLength()<<endl;
  //  cout<<endl;
    
   
    cout<<"test02.GetFirst() = "<<test02.GetFirst()<< endl;
    cout<<"test02.GetLast() = "<<test02.GetLast()<< endl;
    cout<<"test02.Get(2) = "<<test02.Get(2)<< endl;
  
    test02.Remove(3);
    cout<<"test02.Remove(3) = ";
    test02.Print();
    cout<<"test02.GetLength() = "<< test02.GetLength()<<endl;
    cout<<endl;

    test02.InsertAt(99, 3);
    cout<<"test02.InsertAt(99, 3) = ";
    test02.Print();
    cout<<"test02.GetLength() = "<< test02.GetLength()<<endl;
    cout<<endl;
    
    test02.Prepend(77);
    cout<<"test02.Prepend(77) = ";
    test02.Print();
    cout<<"test02.GetLength() = "<< test02.GetLength()<<endl;
    cout<<endl;

    test02.Append(55);
    cout<<"test02.Append(55) = ";
    test02.Print();
    cout<<"test02.GetLength() = "<< test02.GetLength()<<endl;
    cout<<endl;

    
    
    ArraySequence<int>* example = &test01;
    ArraySequence<int>* example1 = &test02;
    Sequence<int> * result = example->Concat((Sequence<int>*)example1);
    
    Sequence<int> * ps = (&test02)->Concat((Sequence<int>*)&test01);
    ArraySequence<int> tr = *((ArraySequence<int> *) ps);
    
    cout<<" ((&test02)->Concat((Sequence<int>*)&test01))) = ";
    tr.Print();
    cout<<"__.GetLength() = "<< tr.GetLength()<<endl;
    cout<<endl;

    ArraySequence<int> * tyr = (ArraySequence<int>*)ps->GetSubsequence(3, 7);
    
    cout<<" GetSubsequence(3, 7) = ";
    tyr->Print();
    cout<<"__.GetLength() = "<< tyr->GetLength()<<endl;
    cout<<endl;
    cout<<"#################### Тесты ArraySequence завершены - ок"<< endl;
    
}

void Test_LinkedList()
{
    LinkedList<int> test00=LinkedList<int>();
    cout<<"test00=LinkedList<int>() = ";
    test00.Print();
    cout<<"test00.GetLength() = "<< test00.GetLength()<<endl;
    cout<<endl;
    
    
    int vector[] {2,6,4,8,11,21,4,0,2,34};
    LinkedList<int> test01=LinkedList<int>(vector, 10);
    cout<<"test01=LinkedList<int>(vector, 10) = ";
    test01.Print();
    cout<<"test01.GetLength() = "<< test01.GetLength()<<endl;
    cout<<endl;

    LinkedList<int> test02=LinkedList<int>(vector, 7);
    cout<<"test02=LinkedList<int>(vector, 7)  = ";
    test02.Print();
    cout<<"test01.GetLength() = "<< test02.GetLength()<<endl;
    cout<<endl;
    
    LinkedList<int> * list = &test02;
    LinkedList<int> test03 = test02;//LinkedList<int>( list, 5);
    cout<<"test03=LinkedList<int>(vector, 7)  = ";
    test03.Print();
    cout<<"test03.GetLength() = "<< test03.GetLength()<<endl;
    cout<<endl;
    cout<<"#################### Тесты LinkedList завершены - ок"<< endl;
    
}

void Test_Vector()
{
    Vector<int> test00=Vector<int>();
    cout<<"test00=Vector<int>() = ";
    test00.Print_V();
    cout<<"test00.GetLength() = "<< test00.GetLength()<<endl;
    cout<<endl;
    
    
    int vector[] {2,5,7,0,8,21,4,0,2,34};
    Vector<int> test01=Vector<int>(vector, 10);
    cout<<"test01=Vector<int>(vector, 10) = ";
    test01.Print_V();
    cout<<"test01.GetLength() = "<< test01.GetLength()<<endl;
    cout<<endl;

    Vector<int> test02=Vector<int>(vector, 5);
    cout<<"test02=Vector<int>(vector, 5) = ";
    test02.Print_V();
    cout<<"test02.GetLength() = "<< test02.GetLength()<<endl;
    cout<<endl;
    
    Vector<int> test03 = Vector<int>(test02);
    cout<<"test03 = test02 = ";
    test03.Print_V();
    cout<<"test03.GetLength() = "<< test03.GetLength()<<endl;
    cout<<endl;
    
    test03.Append(1);
    cout<<"test03.Append(1) = ";
    test03.Print_V();
    cout<<"test03.GetLength() = "<< test03.GetLength()<<endl;
    cout<<endl;
    
    Vector<int> * test04 = test02.Sum_vectors(test01);
    cout<<"test04 = Test02.Sum_vectors(test01) = ";
    (*test04).Print_V();
    cout<<"test03.GetLength() = "<< (*test04).GetLength()<<endl;
    cout<<endl;
    
    Vector<int> * test05 = test02.Minus_vectors(test01);
    cout<<"test05 = test02.Minus_vectors(test01) = ";
    (*test05).Print_V();
    cout<<"test03.GetLength() = "<< (*test05).GetLength()<<endl;
    cout<<endl;
    
    int scalar=7;
    Vector<int> test06 = test02.Multiply_on_scalar(scalar);
    cout<<"test06 = test02.Multiply_on_scalar(7) = ";
    test06.Print_V();
    cout<<"test03.GetLength() = "<< test06.GetLength()<<endl;
    cout<<endl;
    
    
    
    cout<<"test03 = ";
    test03.Print_V();
    cout<<"test03.GetLength() = "<<test03.GetLength()<<endl;
    cout<<"test03.Norm() = " << test03.Norm() <<endl;
    cout<<endl;
    
    
    cout<<"test06 = ";
    test06.Print_V();
    cout<<"test06.GetLength() = " << test06.GetLength()<<endl;
    cout<<"test06.Dot_product(test02) = " << test06.Dot_product(test02) <<endl;
    
   // Vector<int> test07 = (test01 + test03);
   // (test01 + test03).Print_V();
   // test03.Print_V();
   // test01.Print_V();
    
    cout<<"#################### Тесты Вектора в целых числах завершены - ок"<< endl;
    
}



void Test_Vector_Complex()
{
    Complex rt0 (7.2,4.3), rt1 (5.1,3.1), rt2 (3.0,4.1), rt3 (2.3,1.2), rt4 (5.0,9.1);
    Complex vector[] {rt0,rt1,rt2,rt3,rt4};


    Vector<Complex> test00=Vector<Complex>();
    cout<<"test00=Vector<Complex>() ";
    test00.Print_V();
    cout<<"test00.GetLength() = "<< test00.GetLength()<<endl;
    cout<<endl;


//  Complex vector[] {(2,5),(3,7),(0,8),(21,4),(0,2),(34,9)};
    Vector<Complex> test01=Vector<Complex>(vector, 5);
    cout<<"test01=LinkedList<int>(vector, 5) = ";
    test01.Print_V();
    cout<<"test01.GetLength() = "<< test01.GetLength()<<endl;
    cout<<endl;




    Vector<Complex> test02=Vector<Complex>(vector, 3);
    cout<<"test02=LinkedList<int>(vector, 3) = ";
    test02.Print_V();
    cout<<"test02.GetLength() = "<< test02.GetLength()<<endl;
    cout<<endl;

    Vector<Complex> test03 = Vector<Complex>(test02);
    cout<<"test03 = test02 = ";
    test03.Print_V();
    cout<<"test03.GetLength() = "<< test03.GetLength()<<endl;
    cout<<endl;

    test03.Append(rt0);
    cout<<"test03.Append(1) = ";
    test03.Print_V();
    cout<<"test03.GetLength() = "<< test03.GetLength()<<endl;
    cout<<endl;

    Vector<Complex> * test04 = test03.Sum_vectors(test01);
    cout<<"test04 = Test03.Sum_vectors(test01) = ";
    (*test04).Print_V();
    cout<<"test03.GetLength() = "<< (*test04).GetLength()<<endl;
    cout<<endl;

//Vector<Complex> * test05 = test02.Minus_vectors(test01);
//cout<<"test05 = test02.Minus_vectors(test01) = ";
//(*test05).Print_V();
//cout<<"test03.GetLength() = "<< (*test05).GetLength()<<endl;
//cout<<endl;


    double scalar=2.1;
    Vector<Complex> test06 = test02.Multiply_on_scalar(scalar);
    cout<<"test06 = test03.Multiply_on_scalar(7) = ";
    test06.Print_V();
    cout<<"test03.GetLength() = "<< test06.GetLength()<<endl;
    cout<<endl;



    cout<<"test03 = ";
    test03.Print_V();
    cout<<"test03.GetLength() = "<<test03.GetLength()<<endl;
    cout<<"test03.Norm() = " << test03.Norm() <<endl;
    cout<<endl;


    cout<<"test06 = ";
    test06.Print_V();
    cout<<"test06.GetLength() = " << test06.GetLength()<<endl;
    cout<<"test06.Dot_product(test02) = " << test06.Dot_product(test02) <<endl;


    cout<<"test03 = ";
    test03.Print_V();
//cout<<"test06.GetLength() = " << test06.Sum_vectors(test03)<<endl;
//cout<<"test06.Dot_product(test02) = " << test06.Dot_product(test02) <<endl;
    
    cout<<"#################### Тесты Вектора в комплексных числах завершены - ок"<<endl;

}
