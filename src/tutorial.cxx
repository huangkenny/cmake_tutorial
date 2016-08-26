// A simple program that computes the square root of a number
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "TutorialConfig.h"
#ifdef USE_MYMATH
#include "mymath.h"
#endif

int main (int argc, char *argv[])
{
  if (argc < 2)
    {
    fprintf(stdout, "%s Version %d.%d\n",
            argv[0],
            Tutorial_VERSION_MAJOR,
            Tutorial_VERSION_MINOR); 

    fprintf(stdout,"Usage: %s number\n",argv[0]);
    return 1;
    }
  double inputValue = atof(argv[1]);
#if defined (HAVE_LOG) && (HAVE_EXP)
  fprintf(stdout,"Using log and exp \n");
  double outputValue = exp(log(inputValue)*0.5);
#elif defined (USE_MYMATH)
  fprintf(stdout,"Using mysqrt\n");
  double outputValue = mysqrt(inputValue);
#else
  // fprintf(stdout,"Using sqrt\n");
  double outputValue = sqrt(inputValue);
#endif
  fprintf(stdout,"The square root of %g is %g\n",
          inputValue, outputValue);
  return 0;
}
