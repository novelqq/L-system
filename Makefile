Lsystem: main.cpp
	g++ main.cpp lsystem.cpp turtle.cpp -o Lsystem -lglut -lGLU -lGL -lstdc++

clean:
	rm -f *.o Lsystem