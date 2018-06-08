# C++ BattleShip Project
# 작성일자 2018-06-02
# 학번 : 20132651 이름 : 이성재
CC = g++
TARGET = test
SOURCES = main.o BattleShipApp.o GameManager.o Pane.o \
					BattleShipMap.o InputPane.o StatPane.o \
					Player.o Attacker.o Defender.o \
					Ship.o Aircraft.o Battleship.o Cruiser.o Destroyer.o
LDFLAGS = -lncurses

all : $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) -o $@ $^ $(LDFLAGS)

clean:
	rm -rf *.o *.gch $(TARGET)
