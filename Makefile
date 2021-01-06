FUNC = prhdr.cpp Absadd.o Abssub.o clearup.o construct.o constructD.o multchar.o multabs.o constructInt.o OVadd.o OVassign.o OVcin.o OVcout.o OVdec.o OVequalInt.o OVgreaterthan.o OVinc.o OVisequal.o OVlessthan.o OVmult.o OVsub.o

all : hw09

CC = g++ -g

hw09: hw09.cpp $(FUNC)
	$(CC) hw09.cpp -o hw09 $(FUNC)

Absadd.o: Absadd.cpp
	$(CC) -c Absadd.cpp -o Absadd.o

Abssub.o: Abssub.cpp
	$(CC) -c Abssub.cpp -o Abssub.o

clearup.o: clearup.cpp
	$(CC) -c clearup.cpp -o clearup.o

construct.o: construct.cpp
	$(CC) -c construct.cpp -o construct.o

constructD.o: constructD.cpp
	$(CC) -c constructD.cpp -o constructD.o

constructInt.o: constructInt.cpp
	$(CC) -c constructInt.cpp -o constructInt.o
	
multchar.o: multchar.cpp
	$(CC) -c multchar.cpp -o multchar.o
	
multabs.o: multabs.cpp
	$(CC) -c multabs.cpp -o multabs.o

OVadd.o: OVadd.cpp
	$(CC) -c OVadd.cpp -o OVadd.o

OVassign.o: OVassign.cpp
	$(CC) -c OVassign.cpp -o OVassign.o

OVcin.o: OVcin.cpp
	$(CC) -c OVcin.cpp -o OVcin.o

OVcout.o: OVcout.cpp
	$(CC) -c OVcout.cpp -o OVcout.o

OVdec.o: OVdec.cpp
	$(CC) -c OVdec.cpp -o OVdec.o

OVequalInt.o: OVequalInt.cpp
	$(CC) -c OVequalInt.cpp -o OVequalInt.o

OVgreaterthan.o: OVgreaterthan.cpp
	$(CC) -c OVgreaterthan.cpp -o OVgreaterthan.o

OVinc.o: OVinc.cpp
	$(CC) -c OVinc.cpp -o OVinc.o

OVisequal.o: OVisequal.cpp
	$(CC) -c OVisequal.cpp -o OVisequal.o

OVlessthan.o: OVlessthan.cpp
	$(CC) -c OVlessthan.cpp -o OVlessthan.o

OVmult.o: OVmult.cpp
	$(CC) -c OVmult.cpp -o OVmult.o

OVsub.o: OVsub.cpp
	$(CC) -c OVsub.cpp -o OVsub.o


clean :
	rm *.o hw09

tar :
	tar cvf hw09.tar hw09.cpp hw09.h hw09.scr Makefile prhdr.cpp Absadd.cpp Abssub.o clearup.cpp construct.cpp constructD.cpp multchar.cpp multabs.cpp constructInt.cpp OVadd.cpp OVassign.cpp OVcin.cpp OVcout.cpp OVdec.cpp OVequalInt.cpp OVgreaterthan.cpp OVinc.cpp OVisequal.cpp OVlessthan.cpp OVmult.cpp OVsub.cpp
