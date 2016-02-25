//-----------------------------------------------------------------------------
/*



*/
//-----------------------------------------------------------------------------

#include "common.h"
#include "program.h"
#include "logger.h"
#include "hal.h"

//-----------------------------------------------------------------------------

static int run_name(uint8_t *prog UNUSED, int n UNUSED) {
  logger(LOG_INFO, "name");
  return 1;
}

static int run_start(uint8_t *prog UNUSED, int n UNUSED) {
  logger(LOG_INFO, "start");
  return 1;
}

static int run_ramp(uint8_t *prog UNUSED, int n UNUSED) {
  logger(LOG_INFO, "ramp");
  return 1;
}

static int run_hold(uint8_t *prog UNUSED, int n UNUSED) {
  logger(LOG_INFO, "hold");
  return 1;
}

static int run_end(uint8_t *prog UNUSED, int n UNUSED) {
  logger(LOG_INFO, "end");
  return 1;
}

//-----------------------------------------------------------------------------

int run_program(uint8_t *prog, int n) {
  int normal_end = 0;
  int pc = 0;

  while (pc < n) {
    switch(prog[pc]) {
      case OPCODE_NAME:
        pc += run_name(&prog[pc], n - pc);
        break;
      case OPCODE_START:
        pc += run_start(&prog[pc], n - pc);
      case OPCODE_RAMP:
        pc += run_ramp(&prog[pc], n - pc);
        break;
      case OPCODE_HOLD:
        pc += run_hold(&prog[pc], n - pc);
        break;
      case OPCODE_END:
        pc += run_end(&prog[pc], n - pc);
        if (pc != n) {
          logger(LOG_ERROR, "opcodes after end");
          pc = n;
        } else {
          normal_end = 1;
        }
        break;
      default:
        logger(LOG_ERROR, "bad opcode");
        // abandon program
        pc = n;
        break;
    }
  }

  if (!normal_end) {
    // abnormal program ending- turn the oven off
    logger(LOG_ERROR, "abnormal program end");
    oven_control(0);
  } else {
    // normal program ending - leave the end state
    logger(LOG_INFO, "normal program end");
  }

  return 0;
}

//-----------------------------------------------------------------------------
