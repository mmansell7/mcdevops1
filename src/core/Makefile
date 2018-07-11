CChen:=mpicc
#CCmac:=/usr/local/bin/gcc-7
CCmac:=g++
CFLAGShen:=-Wall -lgsl -O3
CFLAGSmac:=-Wall -lgsl -O3
EXE:=core_check.exe
INCSmac:=/usr/local/include
LIBSmac:=/usr/local/lib

mac : 
	${CCmac} -I${INCSmac} -L${LIBSmac} ${CFLAGSmac} item.cpp -c
	${CCmac} -I${INCSmac} -L${LIBSmac} ${CFLAGSmac} core_check.cpp -c
	${CCmac} -I${INCSmac} -L${LIBSmac} ${CFLAGSmac} item.o core_check.o -o ${EXE}

clean :
	rm -f *.o *.exe
