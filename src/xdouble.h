/******************************************************************************
    Copyright 2009 Stefan Wolfsheimer & Gregory Nuel.

    This file is part of ppALIGN

    ppALIGN is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    ppALIGN is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with ppALIGN; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*******************************************************************************/


#ifndef _XDOUBLE_HPP_
#define _XDOUBLE_HPP_
#include <iostream>
#include <math.h>
#include <stdlib.h>


/** configure the following macros according to your maschine. 
 */
#define NTL_SNS 
#define NTL_BITS_PER_LONG (32)
#define NTL_BITS_PER_INT (32)
#define NTL_BITS_PER_SIZE_T (32)
#define NTL_MAX_INT (2147483647)
#define NTL_MIN_INT  (-NTL_MAX_INT - 1)




/** Numerical datatype for very large / small numbers.
 *  double precission with large exponent based on mantisse and exponent.
 *  The code is based on the NTL library. All methods are implemented inline. 
 *  Hence, no library is needed for xdouble.
 */
class xdouble 
{
private:
  double x;
  long e;

  xdouble(double xx, long ee) : x(xx), e(ee) { } // internal use only
  inline void from_double(double  x);
  //double to_double(const double & x);
  static inline void Error(const char * str);
public:


  /** default constructor 
   */
  xdouble()  : x(0), e(0)          {}

  /** copy constructor
   * \param a another xdouble object 
   */
  xdouble(const xdouble & a)       : x(a.x),e(a.e) { } 

  /** conversion from double 
   * \param x a double value 
   */
  xdouble(const double & x)        { from_double(x); }

  /** conversion from int 
   * \param x an int value 
   */
  xdouble(const int & x)           { from_double(x); }

  /** conversion from long
   * \param x a long value  
   */
  xdouble(const long & x)          { from_double(x); }

  /** conversion from unsigned int 
   *  \param x an unsigned int value 
   */
  xdouble(const unsigned int & x)  { from_double(x); }

  /** coversion from long 
   * \param x an unsigned long value  
   */
  xdouble(const unsigned long & x) { from_double(x); }


  /** @name assignment operators for xdouble 
   */
  // @{ 

  /** Assignment from double 
   *  \param a a double value 
   */
  inline xdouble& operator=(double a);

  /** Assignment from int 
   *  \param a an int value 
   */
  inline xdouble& operator=(int a);

  /** Assignment from long 
   *  \param a a long int value 
   */
  inline xdouble& operator=(long a);

  /** Assignment from unsigned int 
   *  \param a an unsigned int  value 
   */
  inline xdouble& operator=(unsigned int & a);

  /** Assignment from unsigned long 
   *  \param a an unsigned long  value 
   */
  inline xdouble& operator=(unsigned long & a);


  /** Assignment by addition 
   * \param b number 
   */
  inline xdouble& operator+=(const xdouble& b){ *this = *this + b; return *this; }

  /** Assignment by subtraction 
   * \param b number 
   */
  inline xdouble& operator-=(const xdouble& b){ *this = *this - b; return *this; }

  /** Assignment by multiplication 
   * \param b  number 
   */
  inline xdouble& operator*=(const xdouble& b){ *this = *this * b; return *this; }

  /** Assignment by division 
   * \param b number 
   */
  inline xdouble& operator/=(const xdouble& b){ *this = *this / b; return *this; }
  // @}


  /** Conversion to double 
   * \return value converted to double
   */
  inline double to_double() const;



  //////////////////////////////////////////////////////////////////////////////
  /** @name iostream for xdouble 
   */
  // @{ 
  /** Outstream operator for xdouble. 
   *  \note the value must not exceed the normal double */
  friend inline std::ostream & operator<<(std::ostream & ost, const xdouble & v) { ost << v.to_double(); return ost; }

  /** Instream operator for xdouble 
   */
  friend inline std::istream & operator>>(std::istream & ist, xdouble & v) { double temp; ist >> temp; v=temp; return ist; }
  // @}

  //////////////////////////////////////////////////////////////////////////////
  /** @name Unary operators for xdouble 
   */
  // @{

  /** Unary minus (negation). 
   * \return -a
   */
  friend inline xdouble operator-(const xdouble & a);
  // @} 

  //////////////////////////////////////////////////////////////////////////////
  /** @name binary operators for xdouble 
   */
  // @{ 

  /** @name Addition 
   */
  // @{
  /** Addition (sum) 
   * \return a + b 
   **/
  friend inline xdouble operator+(const xdouble & a,const xdouble & b);

  /*! @copydoc xdouble operator+(const xdouble & a,const xdouble & b); */
  friend inline xdouble operator+(const double & a,const xdouble & b)        { return xdouble(a) + b; }
  /*! @copydoc xdouble operator+(const xdouble & a,const xdouble & b); */
  friend inline xdouble operator+(const int & a,const xdouble & b)           { return xdouble(a) + b; }
  /*! @copydoc xdouble operator+(const xdouble & a,const xdouble & b); */
  friend inline xdouble operator+(const unsigned int & a,const xdouble & b)  { return xdouble(a) + b; }
  /*! @copydoc xdouble operator+(const xdouble & a,const xdouble & b); */
  friend inline xdouble operator+(const long & a,const xdouble & b)          { return xdouble(a) + b; }
  /*! @copydoc xdouble operator+(const xdouble & a,const xdouble & b); */
  friend inline xdouble operator+(const unsigned long & a,const xdouble & b) { return xdouble(a) + b; }
  /*! @copydoc xdouble operator+(const xdouble & a,const xdouble & b); */
  friend inline xdouble operator+(const xdouble & a,const double & b)        { return a + xdouble(b); }
  /*! @copydoc xdouble operator+(const xdouble & a,const xdouble & b); */
  friend inline xdouble operator+(const xdouble & a,const int & b)           { return a + xdouble(b); }
  /*! @copydoc xdouble operator+(const xdouble & a,const xdouble & b); */
  friend inline xdouble operator+(const xdouble & a,const unsigned int & b)  { return a + xdouble(b); }
  /*! @copydoc xdouble operator+(const xdouble & a,const xdouble & b); */
  friend inline xdouble operator+(const xdouble & a,const long & b)          { return a + xdouble(b); }
  /*! @copydoc xdouble operator+(const xdouble & a,const xdouble & b); */
  friend inline xdouble operator+(const xdouble & a,const unsigned long & b) { return a + xdouble(b); }
  // @}

  /** @name Substruction (difference) 
   */
  // @{
  /** Substruction (difference) 
   * \return a - b 
   **/
  friend inline xdouble operator-(const xdouble & a,const xdouble & b);

  /*! @copydoc xdouble operator-(const xdouble & a,const xdouble & b); */
  friend inline xdouble operator-(const double & a,const xdouble & b) { return xdouble(a) - b; }
  /*! @copydoc xdouble operator-(const xdouble & a,const xdouble & b); */
  friend inline xdouble operator-(const int & a,const xdouble & b) { return xdouble(a) - b; }
  /*! @copydoc xdouble operator-(const xdouble & a,const xdouble & b); */
  friend inline xdouble operator-(const unsigned int & a,const xdouble & b) { return xdouble(a) - b; }
  /*! @copydoc xdouble operator-(const xdouble & a,const xdouble & b); */
  friend inline xdouble operator-(const long & a,const xdouble & b) { return xdouble(a) - b; }
  /*! @copydoc xdouble operator-(const xdouble & a,const xdouble & b); */
  friend inline xdouble operator-(const unsigned long & a,const xdouble & b) { return xdouble(a) - b; }
  /*! @copydoc xdouble operator-(const xdouble & a,const xdouble & b); */
  friend inline xdouble operator-(const xdouble & a,const double & b) { return a - xdouble(b); }
  /*! @copydoc xdouble operator-(const xdouble & a,const xdouble & b); */
  friend inline xdouble operator-(const xdouble & a,const int & b) { return a - xdouble(b); }
  /*! @copydoc xdouble operator-(const xdouble & a,const xdouble & b); */
  friend inline xdouble operator-(const xdouble & a,const unsigned int & b) { return a - xdouble(b); }
  /*! @copydoc xdouble operator-(const xdouble & a,const xdouble & b); */
  friend inline xdouble operator-(const xdouble & a,const long & b) { return a - xdouble(b); }
  /*! @copydoc xdouble operator-(const xdouble & a,const xdouble & b); */
  friend inline xdouble operator-(const xdouble & a,const unsigned long & b) { return a - xdouble(b); }
  //@} 

  /** @name Multiplication (times) 
   */
  //@{ 
  /** Multiplication (times) 
   * \param a first factor 
   * \param b second factor 
   * \return a*b
   */
  friend inline xdouble operator*(const xdouble & a,const xdouble & b);

  /*! @copydoc xdouble operator*(const xdouble & a,const xdouble & b); */
  friend inline xdouble operator*(const double & a,const xdouble & b) { return xdouble(a) * b; }
  /*! @copydoc xdouble operator*(const xdouble & a,const xdouble & b); */
  friend inline xdouble operator*(const int & a,const xdouble & b) { return xdouble(a) * b; }
  /*! @copydoc xdouble operator*(const xdouble & a,const xdouble & b); */
  friend inline xdouble operator*(const unsigned int & a,const xdouble & b) { return xdouble(a) * b; }
  /*! @copydoc xdouble operator*(const xdouble & a,const xdouble & b); */
  friend inline xdouble operator*(const long & a,const xdouble & b) { return xdouble(a) * b; }
  /*! @copydoc xdouble operator*(const xdouble & a,const xdouble & b); */
  friend inline xdouble operator*(const unsigned long & a,const xdouble & b) { return xdouble(a) * b; }
  /*! @copydoc xdouble operator*(const xdouble & a,const xdouble & b); */
  friend inline xdouble operator*(const xdouble & a,const double & b) { return a * xdouble(b); }
  /*! @copydoc xdouble operator*(const xdouble & a,const xdouble & b); */
  friend inline xdouble operator*(const xdouble & a,const int & b) { return a * xdouble(b); }
  /*! @copydoc xdouble operator*(const xdouble & a,const xdouble & b); */
  friend inline xdouble operator*(const xdouble & a,const unsigned int & b) { return a * xdouble(b); }
  /*! @copydoc xdouble operator*(const xdouble & a,const xdouble & b); */
  friend inline xdouble operator*(const xdouble & a,const long & b) { return a * xdouble(b); }
  /*! @copydoc xdouble operator*(const xdouble & a,const xdouble & b); */
  friend inline xdouble operator*(const xdouble & a,const unsigned long & b) { return a * xdouble(b); }
  //@}


  /** @name Division (quotient) 
   */
  //@{ 
  /** Division (quotient) 
   * \return a*b
   */
  friend inline xdouble operator/(const xdouble & a,const xdouble & b);

  /*! @copydoc xdouble operator/(const xdouble & a,const xdouble & b); */
  friend inline xdouble operator/(const double & a,const xdouble & b) { return xdouble(a) / b; }
  /*! @copydoc xdouble operator/(const xdouble & a,const xdouble & b); */
  friend inline xdouble operator/(const int & a,const xdouble & b) { return xdouble(a) / b; }
  /*! @copydoc xdouble operator/(const xdouble & a,const xdouble & b); */
  friend inline xdouble operator/(const unsigned int & a,const xdouble & b) { return xdouble(a) / b; }
  /*! @copydoc xdouble operator/(const xdouble & a,const xdouble & b); */
  friend inline xdouble operator/(const long & a,const xdouble & b) { return xdouble(a) / b; }
  /*! @copydoc xdouble operator/(const xdouble & a,const xdouble & b); */
  friend inline xdouble operator/(const unsigned long & a,const xdouble & b) { return xdouble(a) / b; }
  /*! @copydoc xdouble operator/(const xdouble & a,const xdouble & b); */
  friend inline xdouble operator/(const xdouble & a,const double & b) { return a / xdouble(b); }
  /*! @copydoc xdouble operator/(const xdouble & a,const xdouble & b); */
  friend inline xdouble operator/(const xdouble & a,const int & b) { return a / xdouble(b); }
  /*! @copydoc xdouble operator/(const xdouble & a,const xdouble & b); */
  friend inline xdouble operator/(const xdouble & a,const unsigned int & b) { return a / xdouble(b); }
  /*! @copydoc xdouble operator/(const xdouble & a,const xdouble & b); */
  friend inline xdouble operator/(const xdouble & a,const long & b) { return a / xdouble(b); }
  /*! @copydoc xdouble operator/(const xdouble & a,const xdouble & b); */
  friend inline xdouble operator/(const xdouble & a,const unsigned long & b) { return a / xdouble(b); }
  // @}

  // @}


  /** @name increment / decrement operators for xdouble 
   */
  // @{ 
  /** Prefix increment ++a */
  inline xdouble & operator++() { *this+=1.0; return *this; }
 
  /** Prefix decrement --a */
  inline xdouble & operator--() { *this-=1.0; return *this; }

  /** Postfix increment a++ */
  inline xdouble  operator++(int) { xdouble a(*this);  *this=*this + 1.0; return a; }

  /** Postfix increment a-- */
  inline xdouble  operator--(int) { xdouble a(*this);  *this=*this - 1.0; return a; }
  // @} 

  /** @name comparision operators for xdouble 
   */
  // @{ 
  friend inline long xcompare(const xdouble& a, const xdouble& b);
  friend inline long xcompare(const double& a, const xdouble& b) { return xcompare(xdouble(a),b); }
  friend inline long xcompare(const xdouble& a, const double& b) { return xcompare(a,xdouble(b)); }
  
  friend inline long operator==(const xdouble & a,const xdouble & b) { return xcompare(a,b)==0; }
  friend inline long operator!=(const xdouble & a,const xdouble & b) { return xcompare(a,b)!=0; }
  friend inline long operator<=(const xdouble & a,const xdouble & b) { return xcompare(a,b)<=0; }
  friend inline long operator>=(const xdouble & a,const xdouble & b) { return xcompare(a,b)>=0; }
  friend inline long operator<(const  xdouble & a,const xdouble & b) { return xcompare(a,b)<0; }
  friend inline long operator>(const  xdouble & a,const xdouble & b) { return xcompare(a,b)>0; }

  friend inline long operator==(const double & a,const xdouble & b) { return xcompare(xdouble(a),b)==0; }
  friend inline long operator!=(const double & a,const xdouble & b) { return xcompare(xdouble(a),b)!=0; }
  friend inline long operator<=(const double & a,const xdouble & b) { return xcompare(xdouble(a),b)<=0; }
  friend inline long operator>=(const double & a,const xdouble & b) { return xcompare(xdouble(a),b)>=0; }
  friend inline long operator<(const  double & a,const xdouble & b) { return xcompare(xdouble(a),b)<0; }
  friend inline long operator>(const  double & a,const xdouble & b) { return xcompare(xdouble(a),b)>0; }

  friend inline long operator==(const int & a,const xdouble & b) { return xcompare(xdouble(a),b)==0; }
  friend inline long operator!=(const int & a,const xdouble & b) { return xcompare(xdouble(a),b)!=0; }
  friend inline long operator<=(const int & a,const xdouble & b) { return xcompare(xdouble(a),b)<=0; }
  friend inline long operator>=(const int & a,const xdouble & b) { return xcompare(xdouble(a),b)>=0; }
  friend inline long operator<(const  int & a,const xdouble & b) { return xcompare(xdouble(a),b)<0; }
  friend inline long operator>(const  int & a,const xdouble & b) { return xcompare(xdouble(a),b)>0; }

  friend inline long operator==(const unsigned int & a,const xdouble & b) { return xcompare(xdouble(a),b)==0; }
  friend inline long operator!=(const unsigned int & a,const xdouble & b) { return xcompare(xdouble(a),b)!=0; }
  friend inline long operator<=(const unsigned int & a,const xdouble & b) { return xcompare(xdouble(a),b)<=0; }
  friend inline long operator>=(const unsigned int & a,const xdouble & b) { return xcompare(xdouble(a),b)>=0; }
  friend inline long operator<(const  unsigned int & a,const xdouble & b) { return xcompare(xdouble(a),b)<0; }
  friend inline long operator>(const  unsigned int & a,const xdouble & b) { return xcompare(xdouble(a),b)>0; }

  friend inline long operator==(const long & a,const xdouble & b) { return xcompare(xdouble(a),b)==0; }
  friend inline long operator!=(const long & a,const xdouble & b) { return xcompare(xdouble(a),b)!=0; }
  friend inline long operator<=(const long & a,const xdouble & b) { return xcompare(xdouble(a),b)<=0; }
  friend inline long operator>=(const long & a,const xdouble & b) { return xcompare(xdouble(a),b)>=0; }
  friend inline long operator<(const  long & a,const xdouble & b) { return xcompare(xdouble(a),b)<0; }
  friend inline long operator>(const  long & a,const xdouble & b) { return xcompare(xdouble(a),b)>0; }

  friend inline long operator==(const unsigned long & a,const xdouble & b) { return xcompare(xdouble(a),b)==0; }
  friend inline long operator!=(const unsigned long & a,const xdouble & b) { return xcompare(xdouble(a),b)!=0; }
  friend inline long operator<=(const unsigned long & a,const xdouble & b) { return xcompare(xdouble(a),b)<=0; }
  friend inline long operator>=(const unsigned long & a,const xdouble & b) { return xcompare(xdouble(a),b)>=0; }
  friend inline long operator<(const  unsigned long & a,const xdouble & b) { return xcompare(xdouble(a),b)<0; }
  friend inline long operator>(const  unsigned long & a,const xdouble & b) { return xcompare(xdouble(a),b)>0; }

  friend inline long operator==(const xdouble & a,const double & b) { return xcompare(a,xdouble(b))==0; }
  friend inline long operator!=(const xdouble & a,const double & b) { return xcompare(a,xdouble(b))!=0; }
  friend inline long operator<=(const xdouble & a,const double & b) { return xcompare(a,xdouble(b))<=0; }
  friend inline long operator>=(const xdouble & a,const double & b) { return xcompare(a,xdouble(b))>=0; }
  friend inline long operator<(const  xdouble & a,const double & b) { return xcompare(a,xdouble(b))<0; }
  friend inline long operator>(const  xdouble & a,const double & b) { return xcompare(a,xdouble(b))>0; }

  friend inline long operator==(const xdouble & a,const int & b) { return xcompare(a,xdouble(b))==0; }
  friend inline long operator!=(const xdouble & a,const int & b) { return xcompare(a,xdouble(b))!=0; }
  friend inline long operator<=(const xdouble & a,const int & b) { return xcompare(a,xdouble(b))<=0; }
  friend inline long operator>=(const xdouble & a,const int & b) { return xcompare(a,xdouble(b))>=0; }
  friend inline long operator<(const  xdouble & a,const int & b) { return xcompare(a,xdouble(b))<0; }
  friend inline long operator>(const  xdouble & a,const int & b) { return xcompare(a,xdouble(b))>0; }

  friend inline long operator==(const xdouble & a,const unsigned int & b) { return xcompare(a,xdouble(b))==0; }
  friend inline long operator!=(const xdouble & a,const unsigned int & b) { return xcompare(a,xdouble(b))!=0; }
  friend inline long operator<=(const xdouble & a,const unsigned int & b) { return xcompare(a,xdouble(b))<=0; }
  friend inline long operator>=(const xdouble & a,const unsigned int & b) { return xcompare(a,xdouble(b))>=0; }
  friend inline long operator<(const  xdouble & a,const unsigned int & b) { return xcompare(a,xdouble(b))<0; }
  friend inline long operator>(const  xdouble & a,const unsigned int & b) { return xcompare(a,xdouble(b))>0; }

  friend inline long operator==(const xdouble & a,const long & b) { return xcompare(a,xdouble(b))==0; }
  friend inline long operator!=(const xdouble & a,const long & b) { return xcompare(a,xdouble(b))!=0; }
  friend inline long operator<=(const xdouble & a,const long & b) { return xcompare(a,xdouble(b))<=0; }
  friend inline long operator>=(const xdouble & a,const long & b) { return xcompare(a,xdouble(b))>=0; }
  friend inline long operator<(const  xdouble & a,const long & b) { return xcompare(a,xdouble(b))<0; }
  friend inline long operator>(const  xdouble & a,const long & b) { return xcompare(a,xdouble(b))>0; }

  friend inline long operator==(const xdouble & a,const unsigned long & b) { return xcompare(a,xdouble(b))==0; }
  friend inline long operator!=(const xdouble & a,const unsigned long & b) { return xcompare(a,xdouble(b))!=0; }
  friend inline long operator<=(const xdouble & a,const unsigned long & b) { return xcompare(a,xdouble(b))<=0; }
  friend inline long operator>=(const xdouble & a,const unsigned long & b) { return xcompare(a,xdouble(b))>=0; }
  friend inline long operator<(const  xdouble & a,const unsigned long & b) { return xcompare(a,xdouble(b))<0; }
  friend inline long operator>(const  xdouble & a,const unsigned long & b) { return xcompare(a,xdouble(b))>0; }
  //@} 
  
  /** @name internal structure */


  /** @name mathematical functions 
   */
  //@{ 
  friend inline xdouble sqrt(const xdouble&);
  friend inline long    sign(const xdouble&);
  friend inline xdouble trunc(const xdouble&);
  friend inline xdouble floor(const xdouble&);
  friend inline xdouble ceil(const xdouble&);
  friend inline xdouble fabs(const xdouble&);
  friend inline void  power2(xdouble& z, long e);
  friend inline xdouble power(const xdouble& z, long e);
  friend inline xdouble power2_xdouble(long e);
  friend inline double log(const xdouble& a);
  friend inline xdouble xexp(double a);
  //@} 
  
  /** @name combined arithmetric
   */
  //@{ 

  /** z = a + b*c 
   * \param z  object that is changed 
   * \param a  first term 
   * \param b  prefactor second term 
   * \param c  number 
   */
  friend inline void MulAdd(xdouble& z, 
			    const xdouble& a, 
			    const xdouble& b, 
			    const xdouble& c);

  /** z = a - b*c 
   * \param z  object that is changed 
   * \param a  first term 
   * \param b  prefactor second term 
   * \param c  number 
   */
  friend inline void MulSub(xdouble& z, 
			    const xdouble& a, 
			    const xdouble& b, 
			    const xdouble& c)  ;
  //@} 

  //@{ 
  /** Normalize the value.
   *  Usually this function need not be called manually.
   */
  inline void normalize();

  /** Mantissa 
   *  \return the mantissa of the number 
   */
  inline double mantissa() const { return x; }

  /** Exponent 
   *  \return the exponent of the number 
   */
  inline long exponent() const { return e; }
  //@} 
  

private:
  /**
   * An IEEE double x is finite if and only if x - x == 0.
   * The function _ntl_IsFinite implements this logic;  however,
   * it does not completely trust that an optimizing compiler
   * really implements this correctly, and so it goes out of its way to
   * confuse the compiler.  For a good compiler that respects IEEE floating
   * point arithmetic, this is not be necessary, but it is better
   * to be a bit paranoid.
   *
   * Like the routine _ntl_ForceToMem below, this routine has the
   * side effect of forcing its argument into memory.
   */
  static inline long IsFinite(const double *p);

  /**
   * On machines with wide floating point registers, the routine _ntl_ForceToMem
   * is used to force a floating point double to a memory location.
   * This relies on "separate compilation" model, so that optimizing
   * compilers cannot "optimize away" the whole thing.
   */
  static inline void ForceToMem(double *p) {}

  /**
   * The routine _ntl_ldexp(x, e) is like the standard ldexp(x, e) routine,
   * except that it takes a long exponent e, rather than an int exponenet.
   * Some care is taken to ensure reasonable overflow/undeflow behavior.
   * If the value of e does not fit into an int, then the result
   * is x*infinity or x*0, as appropriate.
   * Of course, this can only happen on platforms where long is wider
   * than int (e.g., most 64-bit platforms).
   *
   * We go out of our way to hide the fact that we are multiplying/dividing
   * by zero, so as to avoid unnecessary warnings, and to prevent 
   * overly-agressive optimizing compilers from screwing things up.
   */
  static inline double _ntl_ldexp(double x, long e);
};



///////////////////////////////////////////////////////////////////////
// Implementation
///////////////////////////////////////////////////////////////////////
#if (NTL_DOUBLE_PRECISION > NTL_BITS_PER_LONG)

#define NTL_XD_HBOUND (NTL_FDOUBLE_PRECISION*32.0)
#define NTL_XD_HBOUND_LOG (NTL_DOUBLE_PRECISION+4)

#else

#define NTL_XD_HBOUND (double(1L << (NTL_BITS_PER_LONG - 2))*64.0)
#define NTL_XD_HBOUND_LOG (NTL_BITS_PER_LONG+4)

#endif

#define NTL_XD_HBOUND_INV (double(1)/NTL_XD_HBOUND)

#define NTL_XD_BOUND (NTL_XD_HBOUND*NTL_XD_HBOUND)
#define NTL_XD_BOUND_INV (double(1)/NTL_XD_BOUND)

#define NTL_OVFBND (1L << (NTL_BITS_PER_LONG-4))
#define NTL_OVERFLOW(n, a, b) \
   (((b) >= NTL_OVFBND) || (((long) (n)) > 0 && (((a) >= NTL_OVFBND) || \
    (((long) (n)) >= (NTL_OVFBND-((long)(b))+((long)(a))-1)/((long)(a))))))


/*
 * An IEEE double x is finite if and only if x - x == 0.
 * The function _ntl_IsFinite implements this logic;  however,
 * it does not completely trust that an optimizing compiler
 * really implements this correctly, and so it goes out of its way to
 * confuse the compiler.  For a good compiler that respects IEEE floating
 * point arithmetic, this is not be necessary, but it is better
 * to be a bit paranoid.
 *
 * Like the routine _ntl_ForceToMem below, this routine has the
 * side effect of forcing its argument into memory.
 */
long xdouble::IsFinite(const double *p)
{
  static double _ntl_IsFinite__local;
  double *_ntl_IsFinite__ptr1 = &_ntl_IsFinite__local;
  double *_ntl_IsFinite__ptr2 = &_ntl_IsFinite__local;
  double *_ntl_IsFinite__ptr3 = &_ntl_IsFinite__local;
  double *_ntl_IsFinite__ptr4 = &_ntl_IsFinite__local;
   *_ntl_IsFinite__ptr1 = *p;
   *_ntl_IsFinite__ptr3 = (*_ntl_IsFinite__ptr2 - *p);
   if (*_ntl_IsFinite__ptr4 != 0.0) return 0;
   return 1;
}


void xdouble::Error(const char * str)
{
  //std::cerr << str << std::endl;
  //exit(8);
}

double xdouble::_ntl_ldexp(double x, long e)
{
  static const double _ntl_ldexp_zero = 0.0;
   if (e > NTL_MAX_INT)
     return x/_ntl_ldexp_zero;
   else if (e < NTL_MIN_INT)
     return x*_ntl_ldexp_zero;
   else
     return ldexp(x, ((int) e));
}


///////////////////////////////////////////////////////////////////////
void xdouble::from_double(double  a)
{

   if (a == 0 || a == 1 || (a > 0 && a >= NTL_XD_HBOUND_INV && a <= NTL_XD_HBOUND)
       || (a < 0 && a <= -NTL_XD_HBOUND_INV && a >= -NTL_XD_HBOUND)) 
     {
       x = a;
       e = 0;
     }
   if (!xdouble::IsFinite(&a))
     {
       xdouble::Error("double to xdouble conversion: non finite value");
     }
   x=a;
   e=0;
   normalize();
}

void xdouble::normalize() 
{
   if (x == 0) 
      e = 0;
   else if (x > 0) {
      while (x < NTL_XD_HBOUND_INV) { x *= NTL_XD_BOUND; e--; }
      while (x > NTL_XD_HBOUND) { x *= NTL_XD_BOUND_INV; e++; }
   }
   else {
      while (x > -NTL_XD_HBOUND_INV) { x *= NTL_XD_BOUND; e--; }
      while (x < -NTL_XD_HBOUND) { x *= NTL_XD_BOUND_INV; e++; }
   }

   if (e >= NTL_OVFBND)
      Error("xdouble: overflow");

   if (e <= -NTL_OVFBND)
      Error("xdouble: underflow");
}

double xdouble::to_double() const
{
   double tx;
   long te;

   tx = x;
   te = e;

   while (te > 0) { tx *= NTL_XD_BOUND; te--; }
   while (te < 0) { tx *= NTL_XD_BOUND_INV; te++; }

   return tx;
}


xdouble& xdouble::operator=(double a) { from_double(a); return *this; }
xdouble& xdouble::operator=(int a)    { from_double(a); return *this;}
xdouble& xdouble::operator=(long a)   { from_double(a); return *this; }
xdouble& xdouble::operator=(unsigned int & a) { from_double(a); return *this; }
xdouble& xdouble::operator=(unsigned long & a)         { from_double(a); return *this; }

inline xdouble operator+(const xdouble& a, const xdouble& b)
{
   xdouble z;

   if (a.x == 0) 
      return b;

   if (b.x == 0)
     return a;
      

   if (a.e == b.e) {
      z.x = a.x + b.x;
      z.e = a.e;
      z.normalize();
      return z;
   }
   else if (a.e > b.e) {
      if (a.e > b.e+1)
         return a;

      z.x = a.x + b.x*NTL_XD_BOUND_INV;
      z.e = a.e;
      z.normalize();
      return z;
   }
   else {
      if (b.e > a.e+1)
         return b;

      z.x = a.x*NTL_XD_BOUND_INV + b.x;
      z.e = b.e;
      z.normalize();
      return z;
   }
}


inline xdouble operator-(const xdouble& a, const xdouble& b)
{
   xdouble z;

   if (a.x == 0)
      return -b;

   if (b.x == 0)
      return a;

   if (a.e == b.e) {
      z.x = a.x - b.x;
      z.e = a.e;
      z.normalize();
      return z;
   }
   else if (a.e > b.e) {
      if (a.e > b.e+1)
         return a;

      z.x = a.x - b.x*NTL_XD_BOUND_INV;
      z.e = a.e;
      z.normalize();
      return z;
   }
   else {
      if (b.e > a.e+1)
         return -b;

      z.x = a.x*NTL_XD_BOUND_INV - b.x;
      z.e = b.e;
      z.normalize();
      return z;
   }
}

inline xdouble operator-(const xdouble& a)
{
   xdouble z;
   z.x = -a.x;
   z.e = a.e;
   return z;
}

inline xdouble operator*(const xdouble& a, const xdouble& b)
{
   xdouble z;

   z.e = a.e + b.e;
   z.x = a.x * b.x;
   z.normalize();
   return z;
}

inline xdouble operator/(const xdouble& a, const xdouble& b)
{
   xdouble z;

   if (b.x == 0) xdouble::Error("xdouble division by 0");

   z.e = a.e - b.e;
   z.x = a.x / b.x;
   z.normalize();
   return z;
}

///////////////////////////////////////////////////////////////////////
inline xdouble sqrt(const xdouble& a)
{
   if (a == 0)
      return 0;

   if (a < 0)
     xdouble::Error("xdouble: sqrt of negative number");

   xdouble t;

   if (a.e & 1) {
      t.e = (a.e - 1)/2;
      t.x = sqrt(a.x * NTL_XD_BOUND);
   }
   else {
      t.e = a.e/2;
      t.x = sqrt(a.x);
   }

   t.normalize();

   return t;
}


inline long xcompare(const xdouble& a, const xdouble& b)
{
   xdouble z = a - b;

   if (z.x < 0)
      return -1;
   else if (z.x == 0)
      return 0;
   else
      return 1;
}

inline long sign(const xdouble& z)
{
   if (z.x < 0)
      return -1;
   else if (z.x == 0)
      return 0;
   else
      return 1;
}

inline xdouble trunc(const xdouble& a)
{
   if (a.x >= 0)
      return floor(a);
   else
      return ceil(a);
}

inline xdouble floor(const xdouble& aa)
{
   xdouble z;

   xdouble a = aa;
   xdouble::ForceToMem(&a.x);

   if (a.e == 0) {
      z.x = floor(a.x);
      z.e = 0;
      z.normalize();
      return z;
   }
   else if (a.e > 0) {
      return a;
   }
   else {
      if (a.x < 0)
	return -1;
      else
         return 0;
   }
}


inline xdouble ceil(const xdouble& aa)
{
   xdouble z;

   xdouble a = aa;
   xdouble::ForceToMem(&a.x);

   if (a.e == 0) {
      z.x = ceil(a.x);
      z.e = 0;
      z.normalize();
      return z;
   }
   else if (a.e > 0) {
      return a;
   }
   else {
      if (a.x < 0)
         return 0;
      else
         return 1;
   }
}


inline xdouble fabs(const xdouble& a)
{
   xdouble z;

   z.e = a.e;
   z.x = fabs(a.x);
   return z;
}

inline xdouble power(const xdouble& z, long e)
{
  xdouble x(z);
  power2(x,e);
  return x;
}

inline void power2(xdouble& z, long e)
{
   long hb = NTL_XD_HBOUND_LOG;
   long b = 2*hb;

   long q, r;

   q = e/b;
   r = e%b;

   while (r >= hb) {
      r -= b;
      q++;
   }

   while (r < -hb) {
      r += b;
      q--;
   }

   if (q >= NTL_OVFBND)
     xdouble::Error("xdouble: overflow");

   if (q <= -NTL_OVFBND)
     xdouble::Error("xdouble: underflow");

   double x = xdouble::_ntl_ldexp(1.0, r);

   z.x = x;
   z.e = q;
}

inline void MulAdd(xdouble& z, const xdouble& a, const xdouble& b, const xdouble& c)
// z = a + b*c
{
   double x;
   long e;

   e = b.e + c.e;
   x = b.x * c.x;

   if (x == 0) { 
      z = a;
      return;
   }

   if (a.x == 0) {
      z.e = e;
      z.x = x;
      z.normalize();
      return;
   }
      

   if (a.e == e) {
      z.x = a.x + x;
      z.e = e;
      z.normalize();
      return;
   }
   else if (a.e > e) {
      if (a.e > e+1) {
         z = a;
         return;
      }

      z.x = a.x + x*NTL_XD_BOUND_INV;
      z.e = a.e;
      z.normalize();
      return;
   }
   else {
      if (e > a.e+1) {
         z.x = x;
         z.e = e;
         z.normalize();
         return;
      }

      z.x = a.x*NTL_XD_BOUND_INV + x;
      z.e = e;
      z.normalize();
      return;
   }
}

inline void MulSub(xdouble& z, const xdouble& a, const xdouble& b, const xdouble& c)
// z = a - b*c
{
   double x;
   long e;

   e = b.e + c.e;
   x = b.x * c.x;

   if (x == 0) { 
      z = a;
      return;
   }

   if (a.x == 0) {
      z.e = e;
      z.x = -x;
      z.normalize();
      return;
   }
      

   if (a.e == e) {
      z.x = a.x - x;
      z.e = e;
      z.normalize();
      return;
   }
   else if (a.e > e) {
      if (a.e > e+1) {
         z = a;
         return;
      }

      z.x = a.x - x*NTL_XD_BOUND_INV;
      z.e = a.e;
      z.normalize();
      return;
   }
   else {
      if (e > a.e+1) {
         z.x = -x;
         z.e = e;
         z.normalize();
         return;
      }

      z.x = a.x*NTL_XD_BOUND_INV - x;
      z.e = e;
      z.normalize();
      return;
   }
}

inline double log(const xdouble& a)
{
   static double LogBound = log(NTL_XD_BOUND);
   if (a.x <= 0) {
     xdouble::Error("log(xdouble): argument must be positive");
   }

   return log(a.x) + a.e*LogBound;
}

inline xdouble xexp(double x)
{
   const double LogBound = log(NTL_XD_BOUND);

   double y = x/LogBound;
   double iy = floor(y+0.5);

   if (iy >= NTL_OVFBND)
     xdouble::Error("xdouble: overflow");

   if (iy <= -NTL_OVFBND)
     xdouble::Error("xdouble: underflow");


   double fy = y - iy;

   xdouble res;
   res.e = long(iy);
   res.x = exp(fy*LogBound);
   res.normalize();
   return res;
}


inline xdouble power2_xdouble(long e)
   { xdouble z; power2(z, e); return z; }


inline void MulAdd(xdouble& z, const xdouble& a, const xdouble& b, const xdouble& c);
inline xdouble MulAdd(const xdouble& a, const xdouble& b, 
                            const xdouble& c)
   { xdouble z; MulAdd(z, a, b, c); return z; }


inline void MulSub(xdouble& z, const xdouble& a, const xdouble& b, const xdouble& c);
inline xdouble MulSub(const xdouble& a, const xdouble& b, 
                            const xdouble& c)
   { xdouble z; MulSub(z, a, b, c); return z; }


#endif 
