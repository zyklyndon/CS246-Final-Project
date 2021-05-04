CXX=g++
CXXFLAGS=-std=c++14 -Wextra -Wpedantic -Wall -MMD -g -Werror=vla
OBJECTS= floor.o cell.o character.o normal.o troll.o vampire.o drow.o goblin.o enemy.o human.o dragon.o elf.o merchant.o orcs.o halfling.o dwarf.o potion.o RH.o BA.o BD.o PH.o WA.o WD.o treasure.o small.o midgold.o mhoard.o dhoard.o main.o xman.o superman.o
DEPENDS=${OBJECTS:.o=.d}
EXEC=cc3k

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean: 
	rm ${OBJECTS} ${DEPENDS} ${EXEC}
.PHONY: clean
