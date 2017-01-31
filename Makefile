all: out
clean:
	rm -f out *.o
.PHONY: all clean

CXX = g++
CPPFLAGS =
CXXFLAGS = -std=c++11 -Wall -Wextra -g
LIBS = -lglfw3 -lX11 -lXrandr -lXinerama -lXi -lXxf86vm -lXcursor -lGL -ldl -lpthread -lGLEW
LDFLAGS =

out: clean
	$(CXX) $(file) $(LDFLAGS) -o $@ $(LIBS)
