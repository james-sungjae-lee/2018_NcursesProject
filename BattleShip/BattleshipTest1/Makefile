# C++ Battleship Project Version 2
# Makefile
# 작성일자 : 2018_06_06
# 학번 : 20132651
# 이름 : 이 성 재

CC = g++
TARGET = test
SOURCES = main.o BattleShipApp.o GameManager.o Pane.o \
					BattleShipMap.o InputPane.o StatPane.o \
					Player.o Attacker.o Defender.o \
					Ship.o Aircraft.o Battleship.o Cruiser.o Destroyer.o Enums.o Position.o
LDFLAGS = -lncurses

all : $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) -o $@ $^ $(LDFLAGS)

clean:
	rm -rf *.o *.gch $(TARGET)
