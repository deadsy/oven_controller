# Make libu8g.a for an AVR microcontroller  

VERSION = _avr_v1.18.1
PKG = u8glib
TARBALL = $(PKG)$(VERSION).tar.bz2

PATCHFILES = $(sort $(wildcard *.patch ))

PATCH_CMD = \
  for f in $(PATCHFILES); do\
      echo $$f ":"; \
      patch -d $(PKG) -p0 -b -z .original < $$f; \
  done

COPY_CMD = \
  cd files; tar -c -f - * | (cd ../$(PKG) ; tar xfp -)

all:
	-rm -rf $(PKG)
	tar jxf $(TARBALL)
	$(COPY_CMD) 
	$(PATCH_CMD)  
	make -C $(PKG) all

clean:
	-rm -rf $(PKG)
