SRCS := $(wildcard *.cpp)
TARGETS := $(SRCS:.cpp=.out)

all: $(TARGETS)

$(TARGETS): %.out: %.cpp
	g++ -std=c++11 -Wall --pedantic-errors $< -o $@

.PHONY: clean
clean:
	rm -f $(TARGETS)
