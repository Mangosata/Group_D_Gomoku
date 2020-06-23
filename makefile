CC = gcc
CFLAGS = `pkg-config --cflags --libs  gtk+-3.0` -lm

main: src/main.c build/graphic.o build/button_logic.o build/game_logic.o
	$(CC) src/main.c build/graphic.o build/button_logic.o build/game_logic.o $(CFLAGS) -o bin/main

build/graphic.o: src/graphic/graphic.c
	$(CC) -c src/graphic/graphic.c $(CFLAGS) -o build/graphic.o
	
build/button_logic.o: src/button_logic/button_logic.c
	$(CC) -c src/button_logic/button_logic.c $(CFLAGS) -o build/button_logic.o
	
build/game_logic.o: src/game_logic/game_logic.c
	$(CC) -c src/game_logic/game_logic.c $(CFLAGS) -o build/game_logic.o
	
clean:
	rm build/*.o bin/main
