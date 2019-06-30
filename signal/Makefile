SRCS := $(wildcard *.c)
TARGETS := $(SRCS:.c=.out)

all: $(TARGETS)

$(TARGETS): %.out: %.c
	gcc $< -o $@

.PHONY: clean
clean:
	rm -f $(TARGETS)
