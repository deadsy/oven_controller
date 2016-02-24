//-----------------------------------------------------------------------------
/*



*/
//-----------------------------------------------------------------------------

#include <stdio.h>

#include "logger.h"

//-----------------------------------------------------------------------------

void logger(int level, char *msg) {
  switch (level) {
    case LOG_INFO:
      printf("info: %s\n", msg);
      break;
    case LOG_ERROR:
      printf("error: %s\n", msg);
      break;
    default:
      printf("??: %s\n", msg);
      break;
  }
}

//-----------------------------------------------------------------------------