CPP       = g++

# sans -pedantic en raison de la syntaxe de main
CPPFLAGS0 = -ansi -Wall -W -g
CPPFLAGS0 +=  -Wextra -Wold-style-cast \
-Woverloaded-virtual -Wfloat-equal -Wshadow -Wwrite-strings -Wpointer-arith \
-Wcast-qual -Wcast-align -Wconversion -Weffc++ -Wunreachable-code

# avec pedantic
CPPFLAGS = $(CPPFLAGS0) -pedantic

SRC = exo01-1.cc  exo11-1.cc  exo20-1.cc              exo43-1.cc  exo56-1.cc             \
      exo01-2.cc  exo12-1.cc  exo21-1.cc  exo32-1.cc  exo44-1.cc  exo57-1.cc  exo69-1.cc \
      exo01-3.cc  exo12-2.cc  exo22-1.cc  exo33-1.cc  exo45-1.cc  exo58-1.cc  exo70-1.cc \
      exo02-1.cc  exo12-3.cc  exo23-1.cc  exo34-1.cc  exo46-1.cc  exo59-1.cc  exo71-1.cc \
      exo03-1.cc  exo13-1.cc  exo24-1.cc  exo35-1.cc  exo47-1.cc  exo60-1.cc  exo72-1.cc \
      exo04-1.cc  exo13-2.cc  exo25-1.cc  exo36-1.cc  exo48-1.cc  exo61-1.cc  exo73-1.cc \
      exo04-2.cc  exo14-1.cc  exo26-1.cc  exo36-2.cc  exo49-1.cc  exo62-1.cc  exo74-1.cc \
      exo05-1.cc  exo15-1.cc  exo26-2.cc  exo37-1.cc  exo50-1.cc  exo63-1.cc \
      exo06-1.cc  exo16-1.cc  exo27-1.cc  exo38-1.cc  exo51-1.cc  exo64-1.cc \
      exo07-1.cc  exo16-2.cc  exo28-1.cc  exo39-1.cc  exo52-1.cc  exo65-1.cc \
      exo08-1.cc  exo17-1.cc  exo29-1.cc  exo40-1.cc  exo53-1.cc  exo66-1.cc \
      exo09-1.cc  exo17-2.cc  exo30-1.cc  exo41-1.cc  exo54-1.cc  exo67-1.cc \
      exo10-1.cc  exo19-1.cc  exo31-1.cc  exo42-1.cc  exo55-1.cc  exo67-2.cc

TARGETS=$(SRC:.cc=)

# sans -pedantic en raison de la syntaxe de main
exo01-1: exo01-1.cc
	$(CPP) $(CPPFLAGS0) -o $@ $<
exo01-2: exo01-2.cc
	$(CPP) $(CPPFLAGS0) -o $@ $<
exo01-3: exo01-3.cc
	$(CPP) $(CPPFLAGS0) -o $@ $<
exo02-1: exo02-1.cc
	$(CPP) $(CPPFLAGS0) -o $@ $<
exo03-1: exo03-1.cc
	$(CPP) $(CPPFLAGS0) -o $@ $<
exo04-1: exo04-1.cc
	$(CPP) $(CPPFLAGS0) -o $@ $<
exo04-2: exo04-2.cc
	$(CPP) $(CPPFLAGS0) -o $@ $<
exo05-1: exo05-1.cc
	$(CPP) $(CPPFLAGS0) -o $@ $<
exo06-1: exo06-1.cc
	$(CPP) $(CPPFLAGS0) -o $@ $<
exo07-1: exo07-1.cc
	$(CPP) $(CPPFLAGS0) -o $@ $<
exo08-1: exo08-1.cc
	$(CPP) $(CPPFLAGS0) -o $@ $<
exo09-1: exo09-1.cc
	$(CPP) $(CPPFLAGS0) -o $@ $<
exo10-1: exo10-1.cc
	$(CPP) $(CPPFLAGS0) -o $@ $<

check: $(TARGETS)

clean:
	-@/bin/rm -f *.o *~ toto*
	@echo "Cleaned"

new: clean
	/bin/rm -f $(TARGETS)
