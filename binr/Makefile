include ../config-user.mk
PWD=$(shell pwd)

.PHONY: all clean install install-symlink deinstall uninstall mrproper

PFX=${DESTDIR}/${PREFIX}
BFX=${DESTDIR}/${BINDIR}
LFX=${DESTDIR}/${LIBDIR}

BINS=rax2 rasm2 rabin2 rahash2 radiff2 radare2 rafind2 ranal2 rarun2 ragg2
#rsc2

all:
	@for a in ${BINS} ; do (cd $$a && ${MAKE} all) || exit 1; done

install:
	mkdir -p ${BFX}
	pwd
	for a in ${BINS} ; do ${INSTALL_PROGRAM} $$a/$$a ${BFX}/$$a ; done
	${INSTALL_SCRIPT} ragg2/ragg2-cc ${BFX}/ragg2-cc
	#cp -f rarc2/rarc2 rarc2/rarc2-tool ${BFX}
	# shortcut
	-cd ${BFX} && rm -f r2 ; ln -fs radare2 r2

install-rsc2:
	mkdir -p ${LFX}/radare2/bin
	cp -f rsc2/scripts/* ${LFX}/radare2/bin
	chmod +x ${LFX}/radare2/bin/*

symstall-rsc2:
	mkdir -p ${LFX}/radare2/bin
	chmod +x rsc2/scripts/*
	cd rsc2/scripts ; for a in * ; do ln -fs ${PWD}/rsc2/scripts/$$a ${LFX}/radare2/bin/$$a ; done

symstall install-symlink:
	mkdir -p ${BFX}
	for a in ${BINS} ; do ln -fs ${PWD}/$$a/$$a ${BFX}/$$a ; done
	ln -fs ${PWD}/ragg2/ragg2-cc ${BFX}/ragg2-cc
	-ln -fs ${PFX}/bin/radare2 ${BFX}/r2

deinstall uninstall:
	for a in ${BINS} ; do rm -f ${BFX}/$$a ; done
	#rm -f ${BFX}/rarc2-tool
	-rm -f ${BFX}/r2

clean:
	@for a in ${BINS} ; do (cd $$a && ${MAKE} clean); done

mrproper:
	@for a in ${BINS} ; do (cd $$a && ${MAKE} mrproper); done
