# Makefile

CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET1 = stack1
TARGET2 = stack2
TARGET3 = stack3
SRC = stacklist2.c calc.c getNum.c
M1 = upn.c
M2 = upn2.c
M3 = upn3.c
OBJ = $(SRC:.c=.o)
LIBS = -lm

$(TARGET1): $(OBJ) $(M1)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)
$(TARGET2): $(OBJ) $(M2)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)
$(TARGET3): $(OBJ) $(M3)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

run1: $(TARGET1)
	./$(TARGET1)
run2: $(TARGET2)
	./$(TARGET2)
run3: $(TARGET3)
	./$(TARGET3)

clean:
	rm -f $(TARGET1) $(TARGET2) $(OBJ)
cleanall:
	rm -f *.o *.csv $(TARGET)
	find . -maxdepth 1 -type f -executable -delete

testgetNum: testgetNum.c getNum.c
	gcc -o test testgetNum.c getNum.c -lm
