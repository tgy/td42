BUILDIR=build

all: ${BUILDIR}
	cd ${BUILDIR} && cmake .. && make debug

debug: ${BUILDIR}
	cd ${BUILDIR} && cmake .. && make debug

${BUILDIR}:
	mkdir $@

clean:
	rm -rf ${BUILDIR}
