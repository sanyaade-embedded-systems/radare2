CC?=gcc
LINK=
CC_AR=ar -r ${LIBAR}
CFLAGS+=-fPIC
CC_LIB=${CC} -shared -o ${LIBSO}
CFLAGS_INCLUDE=-I
LDFLAGS_LINK=-l
LDFLAGS_LINKPATH=-Wl,-R
CFLAGS_OPT0=-O0
CFLAGS_OPT1=-O1
CFLAGS_OPT2=-O2
CFLAGS_OPT3=-O3
CFLAGS_DEBUG=-g