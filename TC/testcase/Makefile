UTILS_OBJECTS = utils.o

TCS_LIST = $(shell ls -1 utc_*.c | cut -d. -f1)
#PKGS = capi-base-common dlog gthread-2.0
PKGS = libpng pixman-1

LDFLAGS = `pkg-config --libs $(PKGS)`
LDFLAGS += -lm
LDFLAGS += $(TET_ROOT)/lib/tet3/tcm_s.o
LDFLAGS += -L$(TET_ROOT)/lib/tet3 -ltcm_s
LDFLAGS += -L$(TET_ROOT)/lib/tet3 -lapi_s

CFLAGS = -I. `pkg-config --cflags $(PKGS)`
CFLAGS += -I.
CFLAGS += -I$(TET_ROOT)/inc/tet3
CFLAGS += -Wall

all: utils tcs
utils: $(UTILS_OBJECTS)
	$(CC) -c utils.c $(CFLAGS) $(LDFLAGS)

tcs : $(TCS_LIST)
%: %.c
	$(CC) -o $@ $< utils.o $(CFLAGS) $(LDFLAGS) /usr/lib/libpixman-1.so.0

clean:
	rm -f $(TCS_LIST) *.o
