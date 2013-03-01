#include <stdio.h>

#include "integralbot.h"

int main(void)
{
  int ret;

  // Integrate.
  ret = integralbot(0);
  printf("%d", ret);

  return 0;
}
