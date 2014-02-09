highway:highway.o car.o display.o
	g++-4.9 -o highway highway.o car.o display.o -std=c++0x -framework GLUT -framework OpenGL -framework Cocoa \
		`pkg-config --libs --cflags glfw3` -g -fopenmp
highway.o: highway.cpp highway.h
	g++-4.9 -c highway.cpp -std=c++0x -g -fopenmp
display.o: display.cpp highway.h
	g++-4.9 -c display.cpp -std=c++0x -framework GLUT -framework OpenGL -framework Cocoa -g
car.o:car.cpp car.h
	g++-4.9 -c car.cpp -std=c++0x -g
.PHONY:clean,run
clean:
	rm *.o
	rm highway
run:highway
	./highway
