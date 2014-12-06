BUILDIR=build

all: ${BUILDIR}
	cd ${BUILDIR} && cmake .. && make

${BUILDIR}:
	mkdir $@

clean:
	rm -rf ${BUILDIR}
