FINAL:=Student
OBJECT:=func.o main.o
CC:=gcc
OPTIONS:=-g -Wall

$(FINAL):$(OBJECT)
	$(CC) $^ -o $@ $(OPTIONS)

%.o:%.c
	$(CC) -c $< -o $@ $(OPTIONS)

clean:
	rm -rvf $(OBJECT) $(FINAL)
