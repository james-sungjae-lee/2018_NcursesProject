# Makefile example
CC = g++
TARGET = BattleShip
SOURCES = BattleShipApp.cpp \
	  BattleShipMap.cpp \
	  Main.cpp \
	  Pane.cpp \
	  StatPane.cpp \
		InputStat.cpp\
		Ship.cpp\
		Attacker.cpp\
		Defender.cpp
LDFLAGS = -lncurses

all:
	$(CC) -o $(TARGET) $(SOURCES) $(LDFLAGS)
clean:
	rm -rf *.o $(TARGET)
