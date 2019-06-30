SRCS := $(wildcard *.cpp)
TARGETS := $(SRCS:.cpp=.out)

all: $(TARGETS)

$(TARGETS): %.out: %.cpp
	g++ $< -o $@

.PHONY: clean
clean:
	rm -f $(TARGETS)
