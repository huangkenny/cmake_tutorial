// A simple program that computes the square root of a number
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mymath.h"

double mysqrt (double n)
{
  int a, b, m, m_sqr;

  a = 1;
  b = round(n);
  m = (a+b)/2;
  m_sqr = m*m;

  while (1)
  {
      fprintf(stdout, "m = %d\n", m); 

      if (m_sqr == n )
      {
         break; 
      }

      if (m_sqr > n) 
      {
         // too big, search left
         b = m;
         m = (a+b)/2;
         fprintf(stdout, "new m = %d\n", m); 
      }
      else if (m_sqr < n) 
      {
         // too small, search right
         a = m;
         m = (a+b)/2;
         fprintf(stdout, "new m = %d\n", m); 
      }

      
      if ((a == m) || (m == b))
      {
         break;
      }
      
      m_sqr = m*m;
  }

  return m;
}
