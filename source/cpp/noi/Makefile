TARGETS = p1000 p1000-ex p1001 p1009
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -O2 -std=c++11
# CXXFLAGS += -fmax-errors=10
CXXFLAGS += -ferror-limit=10

all:$(TARGETS)

$(TARGETS):%:%.o
	$(CXX) -o $@ $<

%.o:%.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

.PHONY: clean

clean:
	rm -f *.o $(TARGETS)
