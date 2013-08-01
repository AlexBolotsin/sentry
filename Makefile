SRC=$(wildcard src/event/*.cpp src/input/*.cpp src/asset/*.cpp src/render/*.cpp src/util/*.cpp src/game/*.cpp src/loader/*.cpp)
INCLUDES=-Isrc/event -Isrc/input -Isrc/util -Isrc/render -Isrc/asset -Isrc/util -Isrc/game -Isrc/loader
LIBS=-L/usr/lib/x86-64-linux-gnu -lSDL -lSDL_image -lSDL_gfx -ltinyxml
FLAGS=-std=c++11 -g -Wall #-DLOG

all: objs
	g++ main.cpp $(CXXFLAGS) $(FLAGS) $(INCLUDES) -o bin/run $(wildcard obj/*.o) $(LIBS)

objs: $(SRC)
	g++ $(CXXFLAGS) $(FLAGS) $(INCLUDES) -c $^
	mv *.o obj

tests: objs
	g++ tests/drawSpriteTest.cpp $(CXXFLAGS) $(FLAGS) $(INCLUDES) -o bin/drawSpriteTest $(wildcard obj/*.o) $(LIBS)
	g++ tests/xmlReadTest.cpp $(CXXFLAGS) $(FLAGS) $(INCLUDES) -o bin/xmlReadTest $(wildcard obj/*.o) $(LIBS)
	g++ tests/sceneLoadingTest.cpp $(CXXFLAGS) $(FLAGS) $(INCLUDES) -o bin/sceneLoadingTest $(wildcard obj/*.o) $(LIBS)
	g++ tests/loadingTest.cpp $(CXXFLAGS) $(FLAGS) $(INCLUDES) -o bin/loadingTest $(wildcard obj/*.o) $(LIBS)

info:
	./stats.sh

todo:
	find . -name "*.[ch]pp" | xargs grep -Rn "TODO"

clean:
	#rm bin/*
	find -name "*.*~" -exec rm {} \;
