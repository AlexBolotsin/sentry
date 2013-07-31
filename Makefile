SRC=$(wildcard src/event/*.cpp src/input/*.cpp src/asset/*.cpp src/render/*.cpp src/util/*.cpp src/game/*.cpp src/loader/*.cpp)
INCLUDES=-Isrc/event -Isrc/input -Isrc/util -Isrc/render -Isrc/asset -Isrc/util -Isrc/game -Isrc/loader
LIBS=-L/usr/lib/x86-64-linux-gnu -lSDL -lSDL_image -lSDL_gfx -ltinyxml
FLAGS=-std=c++11 -g -Wall #-DLOG

all: objs
	g++ main.cpp $(FLAGS) $(INCLUDES) -o bin/run $(wildcard bin/*.o) $(LIBS)

objs: $(SRC)
	g++ $(FLAGS) $(INCLUDES) -c $^
	mv *.o bin

tests: objs
	g++ tests/drawSpriteTest.cpp $(FLAGS) $(INCLUDES) -o bin/drawSpriteTest $(wildcard bin/*.o) $(LIBS)
	#g++ tests/drawTextTest.cpp $(FLAGS) $(INCLUDES) -o bin/drawTextTest $(wildcard bin/*.o) $(LIBS)
	g++ tests/xmlReadTest.cpp $(FLAGS) $(INCLUDES) -o bin/xmlReadTest $(wildcard bin/*.o) $(LIBS)
	g++ tests/sceneLoadingTest.cpp $(FLAGS) $(INCLUDES) -o bin/sceneLoadingTest $(wildcard bin/*.o) $(LIBS)
	g++ tests/loadingTest.cpp $(FLAGS) $(INCLUDES) -o bin/loadingTest $(wildcard bin/*.o) $(LIBS)

info:
	./stats.sh

todo:
	find . -name "*.[ch]pp" | xargs grep -Rn "TODO"

clean:
	rm bin/*
	find -name "*.*~" -exec rm {} \;
