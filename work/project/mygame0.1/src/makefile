FINAL:=Game
OBJECT:=menu.o game.o main.o supports.o account.o
CC:=gcc
OPTIONS:=-g -Wall

$(FINAL):$(OBJECT)
	$(CC) $^ -o $@ $(OPTIONS)

%.o:%.c
	$(CC) -c $< -o $@ $(OPTIONS)

clean:
	rm -rvf $(OBJECT) $(FINAL)
