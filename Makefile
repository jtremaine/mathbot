OBJS = mathbot.c integralbot.o interpolbot.o
CC = gcc
LFLAGS = -Wall

mathbot: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o mathbot

mathbot.o: mathbot.c mathbot.h integralbot.h
	$(CC) $(LFLAGS) -c mathbot.c

integralbot.o: integralbot.c integralbot.h
	$(CC) $(LFLAGS) -c integralbot.c

interpolbot.o: interpolbot.c interpolbot.h
	$(CC) $(LFLAGS) -c interpolbot.c

clean:
	rm *.o *~ mathbot