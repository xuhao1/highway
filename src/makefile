highway:highway.o car.o display.o
	g++-4.9 -o highway highway.o car.o display.o -std=c++0x -framework GLUT -framework OpenGL -framework Cocoa
highway.o: highway.cpp highway.h
	g++-4.9 -c highway.cpp -std=c++0x
display.o: display.cpp highway.h
	g++-4.9 -c display.cpp -std=c++0x -framework GLUT -framework OpenGL -framework Cocoa
car.o:car.cpp car.h
	g++-4.9 -c car.cpp -std=c++0x
.PHONY:clean,run
clean:
	rm *.o
	rm highway
run:highway
	./highway
