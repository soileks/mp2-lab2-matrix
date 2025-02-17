﻿// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
//

#ifndef __TDynamicMatrix_H__
#define __TDynamicMatrix_H__

#include <iostream>

using namespace std;

const int MAX_VECTOR_SIZE = 100000000;
const int MAX_MATRIX_SIZE = 10000;

// Динамический вектор - 
// шаблонный вектор на динамической памяти
template<typename T>
class TDynamicVector
{
protected:
  size_t sz;
  T* pMem;
public:
  TDynamicVector(size_t size = 1) : sz(size)
  {
 
    if ((sz == 0))

      throw out_of_range("Vector size should be greater than zero");
    if (sz > MAX_VECTOR_SIZE)
        throw - 1;
    pMem = new T[sz]();// {}; // У типа T д.б. констуктор по умолчанию
  }
  TDynamicVector(T* arr, size_t s) : sz(s)
  {
    assert(arr != nullptr && "TDynamicVector ctor requires non-nullptr arg");
    pMem = new T[sz];
    std::copy(arr, arr + sz, pMem);
  }
  TDynamicVector(const TDynamicVector& v)
  {
      sz = v.sz;
      pMem = new T[sz];
      std::copy(v.pMem,v.pMem + sz,pMem);
  }

  TDynamicVector(TDynamicVector&& v) noexcept
  {
      pMem = nullptr;
      swap(*this, v);
  }

  ~TDynamicVector()
  {
      if (pMem != nullptr)
      delete[] pMem;
  }
  TDynamicVector& operator=(const TDynamicVector& v)
  {
      if (this == &v)
          return *this;
      if (sz != v.sz) {
          T* p = new T[v.sz];
          delete[] pMem;
          sz = v.sz;
          pMem = p;
      }
      std::copy(v.pMem, v.pMem + sz, pMem);
      return *this;
  }
  TDynamicVector& operator=(TDynamicVector&& v) noexcept
  {
      swap(*this, v);
      return *this;
  }

  size_t size() const noexcept { return sz; }

  // индексация
  T& operator[](size_t ind)
  {

      if (ind < 0 || ind >= sz)
          throw - 1;

      
      return pMem[ind];
  }
  const T& operator[](size_t ind) const
  {
 
      if (ind < 0 || ind >= sz)
          throw - 1;

      
      return pMem[ind];

  }
  // индексация с контролем
  T& at(size_t ind)

  {
      if (ind < 0 || ind >= sz)
          throw "Error";
      return pMem[ind];
  }
  const T& at(size_t ind) const
  {
      if (ind < 0 || ind >= sz)
          throw "Error";
      return pMem[ind];
  }

  // сравнение
  bool operator==(const TDynamicVector& v) const noexcept
  {
      if (sz != v.sz)
          return false;
      for (int i = 0; i <sz; i++)
          if (pMem[i] != v.pMem[i])
              return false;
      return true;
  }
  bool operator!=(const TDynamicVector& v) const noexcept
  {
      return !(*this == v);
  }

  // скалярные операции
  TDynamicVector operator+(T val)
  {
      TDynamicVector tmp(sz);
      for (size_t i = 0; i < sz; i++) 
          tmp.pMem[i] = pMem[i] + val;
          return tmp;
      
  }
  TDynamicVector operator-(double val)
  {
      TDynamicVector tmp(sz);
      for (size_t i = 0; i < sz; i++)
          tmp.pMem[i] = pMem[i] - val;
      return tmp;
  }
  TDynamicVector operator*(double val)
  {
      TDynamicVector tmp(sz);
      for (size_t i = 0; i < sz; i++)
          tmp.pMem[i] = pMem[i] * val;
      return tmp;
  }

  // векторные операции
  TDynamicVector operator+(const TDynamicVector& v)
  {
      if (v.size() != sz)
          throw out_of_range("error");
      TDynamicVector tmp(sz);
      for (size_t i = 0; i < sz; i++) 
          tmp.pMem[i] = pMem[i] + v.pMem[i];
          return tmp;
      
  }
  TDynamicVector operator-(const TDynamicVector& v)
  {
      if (v.size() != sz)
          throw out_of_range("error");
      TDynamicVector tmp(sz);
      for (size_t i = 0; i < sz; i++)
          tmp.pMem[i] = pMem[i] - v.pMem[i];
      return tmp;
  }
  T operator*(const TDynamicVector& v) noexcept(noexcept(T()))
 
  { 
      T tmp = 0;
      if (sz != v.sz) {
         // return tmp;
          throw out_of_range ("Vectors are different size");
      }
     
      for (int i = 0; i < sz; i++) {
          tmp += pMem[i] * v.pMem[i];
      }
       return tmp;

  }

  friend void swap(TDynamicVector& lhs, TDynamicVector& rhs) noexcept
  {
    std::swap(lhs.sz, rhs.sz);
    std::swap(lhs.pMem, rhs.pMem);
  }

  // ввод/вывод
  friend istream& operator>>(istream& istr, TDynamicVector& v)
  {
    for (size_t i = 0; i < v.sz; i++)
      istr >> v.pMem[i]; // требуется оператор>> для типа T
    return istr;
  }
  friend ostream& operator<<(ostream& ostr, const TDynamicVector& v)
  {
    for (size_t i = 0; i < v.sz; i++)
      ostr << v.pMem[i] << ' '; // требуется оператор<< для типа T
    return ostr;
  }
};


// Динамическая матрица - 
// шаблонная матрица на динамической памяти
template<typename T>
class TDynamicMatrix : private TDynamicVector<TDynamicVector<T>>
{
  using TDynamicVector<TDynamicVector<T>>::pMem;
  using TDynamicVector<TDynamicVector<T>>::sz;
  
public:
  TDynamicMatrix(size_t s = 1) : TDynamicVector<TDynamicVector<T>>(s)
  {
 
      if ((sz == 0) || (sz > MAX_MATRIX_SIZE)||(sz<0))
          throw -1;


    for (size_t i = 0; i < sz; i++)
      pMem[i] = TDynamicVector<T>(sz);
  }
  TDynamicMatrix(const TDynamicVector<TDynamicVector<T>>& V) : TDynamicVector<TDynamicVector<T>>(V) {}

  using TDynamicVector<TDynamicVector<T>>::operator[];
 
 using TDynamicVector<TDynamicVector<T>>::size;
  using TDynamicVector<TDynamicVector<T>>::at;
  


  // сравнение
  bool operator==(const TDynamicMatrix& m) const noexcept
  {

      //if (&m == this)
        //  return true;
     return TDynamicVector<TDynamicVector<T>>::operator==(m);

      /*if (this->sz != m.sz)
          return false;
      for (int i = 0; i < this->sz; i++)
          if (this->pMem[i] != m.pMem[i])
              return false;
      return true;*/
  }

  // матрично-скалярные операции
  TDynamicVector<T> operator*(const T& val)
  {
      return TDynamicVector<TDynamicVector<T>>::operator*(val);
     /*TDynamicMatrix tmp(sz);
      for (size_t i = 0; i < sz; i++) {
          tmp.pMem[i] = pMem[i] * val;
          return tmp;
      }*/
  }

  // матрично-векторные операции
  TDynamicVector<T> operator*(const TDynamicVector<T>& v)
  {
      //return TDynamicVector<TDynamicVector<T>>::operator*(v);
      TDynamicVector<T> tmp(sz);
      for (size_t i = 0; i < sz; i++) 
          tmp.pMem[i] = pMem[i] *v;
          return tmp;
      
  }

  // матрично-матричные операции
  TDynamicMatrix operator+(const TDynamicMatrix& m)
  { 
      /*if (m.size() != sz)

          throw out_of_range("error");
      TDynamicMatrix tmp(sz);
      for (size_t i = 0; i < sz; i++) 
          tmp.pMem[i] = pMem[i] + m.pMem[i];
          return tmp;*/
      return TDynamicVector<TDynamicVector<T>>::operator+(m);
      
  }
  TDynamicMatrix operator-(const TDynamicMatrix& m)
  {
 
      return TDynamicVector<TDynamicVector<T>>::operator-(m);
      /*if (m.size() != sz)

          throw out_of_range("error");
      TDynamicMatrix tmp(sz);
      for (size_t i = 0; i < sz; i++)
          tmp.pMem[i] = pMem[i] - m.pMem[i];
      return tmp;*/
  }
  TDynamicMatrix operator*(const TDynamicMatrix& m)
  {
      if (sz != m.sz)
      {
          throw -1;
      }
      
    
      TDynamicMatrix tmp(sz);
      for (size_t i = 0; i < sz; i++) 
          for (size_t j = 0; j < sz; j++)
              for (size_t k = 0; k < sz; k++)
          tmp.pMem[i][j] += pMem[i][k] *m.pMem[k][j];
          return tmp;
      
  }

  // ввод/вывод
  friend istream& operator>>(istream& istr, TDynamicMatrix& v)
  {
     
          for (size_t i = 0; i < v.sz; i++)
              istr >> v.pMem[i]; 
          return istr;
     
      
  }
  friend ostream& operator<<(ostream& ostr, const TDynamicMatrix& v)
  {
     
          for (size_t i = 0; i < v.sz; i++)
              ostr << v.pMem[i] << ' '; 
          return ostr;
     
  }
};

#endif
