NAME := libftprintf.a
CC := gcc
CFLAGS := -Wall -Wextra -pedantic -ggdb
IFLAGS :=
LFLAGS :=

# Objects
SOURCES := $(wildcard src/*.c)
OBJECTS := $(addprefix objs/,$(SOURCES:.c=.o))

SOURCES_TEST := $(wildcard tests/*.c)
OBJECTS_TEST := $(addprefix objs/,$(SOURCES_TEST:.c=.o))

objs/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

# Library
$(NAME): $(OBJECTS)
	$(AR) rcs $@ $(OBJECTS)

# Tests
printf-tests: IFLAGS += -I./src
printf-tests: LFLAGS += $(NAME)
printf-tests: $(NAME) $(OBJECTS_TEST)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS_TEST) $(LFLAGS)

.PHONY: all
all: $(NAME)

.PHONY: clean
clean:
	$(RM) $(OBJECTS)
	$(RM) $(OBJECTS_TEST)

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME)-tests

.PHONY: re
re: fclean all
