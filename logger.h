//-----------------------------------------------------------------------------
/*

Logger Definitions

*/
//-----------------------------------------------------------------------------

#ifndef LOGGER_H
#define LOGGER_H

//-----------------------------------------------------------------------------

enum {
  LOG_INFO,
  LOG_ERROR,
};

void logger(int level, char *msg);

//-----------------------------------------------------------------------------

#endif // LOGGER_H

//-----------------------------------------------------------------------------
