#
# Makefile
#
# Computer 50
# evo1 project test
# 

all: driver 

driver: driver.c ndice.c ndice.h mutate.c mutate.h
	gcc -ggdb3 -O0 -std=c11 -Wall -Werror -o driver driver.c ndice.c mutate.c

#clean:
#    rm -f *.o a.out core find generate
