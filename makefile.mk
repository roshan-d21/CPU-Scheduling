a: main.o queue.o time.o fcfs.o prioritybased.o sjf.o roundrobin.o
	gcc main.o queue.o time.o fcfs.o prioritybased.o sjf.o roundrobin.o

main.o: main.c headers.h queue.c time.c
	gcc -c main.c queue.c time.c

fcfs.o: fcfs.c headers.h queue.c time.c
	gcc -c fcfs.c queue.c time.c

prioritybased.o: prioritybased.c headers.h queue.c time.c
	gcc -c prioritybased.c queue.c time.c

sjf.o: sjf.c headers.h queue.c time.c
	gcc -c sjf.c queue.c time.c

roundrobin.o: roundrobin.c headers.h  queue.c time.c
	gcc -c roundrobin.c queue.c time.c

queue.o: queue.c headers.h
	gcc -c queue.c

time.o: time.c headers.h
	gcc -c time.c

.INTERMEDIATE: main.o queue.o time.o fcfs.o prioritybased.o sjf.o roundrobin.o