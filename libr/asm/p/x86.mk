OBJ_X86=asm_x86.o
# udis86
SHARED_X86=../../shlr/udis86/decode.o
SHARED_X86+=../../shlr/udis86/input.o
SHARED_X86+=../../shlr/udis86/itab.o
SHARED_X86+=../../shlr/udis86/syn-att.o
SHARED_X86+=../../shlr/udis86/syn-intel.o
SHARED_X86+=../../shlr/udis86/syn.o
SHARED_X86+=../../shlr/udis86/udis86.o

STATIC_OBJ+=${OBJ_X86}
SHARED_OBJ+=${SHARED_X86}
TARGET_X86=asm_x86.${EXT_SO}

ALL_TARGETS+=${TARGET_X86}

${TARGET_X86}: ${OBJ_X86}
	${CC} $(call libname,asm_x86) ${LDFLAGS} ${CFLAGS} -o ${TARGET_X86} ${OBJ_X86}
