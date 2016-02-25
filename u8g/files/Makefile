TOP = ../..

LIBRARY_BUILD = 1

TARGET = u8g

SRC = ./src/u8g_com_io.c \
      ./src/u8g_dev_st7565_nhd_c12864.c \
      ./src/u8g_ll_api.c \
      ./src/u8g_clip.c \
      ./src/u8g_delay.c \
      ./src/u8g_com_api.c \
      ./src/u8g_pb16v1.c \
      ./src/u8g_pb8v1.c \
      ./src/u8g_pb.c \
      ./src/u8g_com_atmega_sw_spi.c \
      ./src/u8g_com_atmega_hw_spi.c \
      ./src/u8g_state.c \
      ./src/u8g_page.c \
      ./src/u8g_font.c \

# select the fonts
#SRC += ./src/u8g_font_data.c
SRC += ./src/bogo_small.c
SRC += ./src/nokia_small.c
SRC += ./src/nokia_large.c

include $(TOP)/mk/common.mk
