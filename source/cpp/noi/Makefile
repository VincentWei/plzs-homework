TARGETS = p1000 p1000-ex p1001 p1009

all:$(TARGETS)

% : %.o
	g++ -o $@ $<

%.o : %.cpp
	g++ -c -Wall -Wextra -O2 -fmax-errors=10 $< -o $@

.PHONY: clean

clean:
	rm -f *.o $(TARGETS)
