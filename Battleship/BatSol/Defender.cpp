#include "Defender.h"

Defender::Defender(){
  dmap = new CBattleShipMap(3);
  dmap->Draw();

  AirCraft = new Ship('A');
  BattleShip = new Ship('B');
  Cruiser = new Ship('C');
  Destroyer1 = new Ship('D');
  Destroyer2 = new Ship('D');
}

Defender::~Defender(){
  delete dmap;
}

void Defender::setShip(Ship *s){
  srand((unsigned int)time(NULL));
  int rowcol = rand()%2;
  int x,y;
  Point *p = new Point[s->getSize()];

  while(1){
    bool check =true;
    switch (rowcol) {
      case 0:
        x = rand()%(8-s->getSize());
        y = rand()%8;

        for (int i = 0; i < s->getSize(); i++) {
          if(x+i > 7){
            check = false;
          }
          if(dmap->m_mapData[x+i][y] != '0'){
            check = false;
          }
        }
        if(!check){
          continue;
        }

        for (int i = 0; i < s->getSize(); i++) {
          dmap->m_mapData[x+i][y] = s->getType();
          dmap->drawShip(x+i,y);
          p[i].x = y;
          p[i].y = x+i;
        }
        s->setPosition(p);
        break;
      case 1:
        srand((unsigned int)time(NULL));
        x = rand()%8;
        y = rand()%(8-s->getSize());

        for (int i = 0; i < s->getSize(); i++) {
          if(y+i > 7){
            check = false;
          }
          if(dmap->m_mapData[x][y+i] != '0'){
            check = false;
          }
        }
        if(!check){
          continue;
        }

        for (int i = 0; i < s->getSize(); i++) {
          dmap->m_mapData[x][y+i] = s->getType();
          dmap->drawShip(x,y+i);
          p[i].x = y+i;
          p[i].y = x;
        }
        s->setPosition(p);
        break;
    }
    break;

  }
  delete p;
}

bool Defender::isHit(int x, int y){
  if( dmap->m_mapData[x][y] != '0'){
    Point *p = new Point[2];
    bool check1 = false;
    char t = dmap->m_mapData[x][y];
    switch (t) {
      case 'A':
        AirCraft->getDamage();
        break;
      case 'B':
        BattleShip->getDamage();
        break;
      case 'C':
        Cruiser->getDamage();
        break;
      case 'D':
        Destroyer1->getPosition(p);
        for (int i = 0; i < 2; i++) {
          if(p[i].x == y && p[i].y == x){
            check1 = true;
          }
        }

        if(check1){
          Destroyer1->getDamage();

        }
        else{
          Destroyer2->getDamage();
        }
        break;
    }
    delete p;
    return true;
  }
  else{
    return false;
  }
}

bool Defender::isDestroyed(int x,int y){
  Point *p = new Point[2];
  bool check1 = false;
  char t = dmap->m_mapData[x][y];
  switch (t) {
    case 'A':
      return AirCraft->isDestroyed();
      break;
    case 'B':
      return BattleShip->isDestroyed();
      break;
    case 'C':
      return Cruiser->isDestroyed();
      break;
    case 'D':
      Destroyer1->getPosition(p);
      for (int i = 0; i < 2; i++) {
        if(p[i].x == y && p[i].y == x){
          check1 = true;
        }
      }

      if(check1){
        return Destroyer1->isDestroyed();

      }
      else{
        return Destroyer2->isDestroyed();
      }
      break;
  }
  delete p;
}

void Defender::setting(){
  setShip(AirCraft);
  setShip(BattleShip);
  setShip(Cruiser);
  setShip(Destroyer1);
  setShip(Destroyer2);
}

bool Defender::gameset(){
  if(AirCraft->isDestroyed()){
    if(BattleShip->isDestroyed()){
      if(Cruiser->isDestroyed()){
        if(Destroyer1->isDestroyed()){
          if(Destroyer2->isDestroyed()){
            return true;
          }
        }
      }
    }
  }
  return false;
}

Ship* Defender::getDestroyedShip(int x,int y){
  Point *p = new Point[2];
  bool check1 = false;
  char t = dmap->m_mapData[x][y];
  switch (t) {
    case 'A':
      return AirCraft;
      break;
    case 'B':
      return BattleShip;
      break;
    case 'C':
      return Cruiser;
      break;
    case 'D':
      Destroyer1->getPosition(p);
      for (int i = 0; i < 2; i++) {
        if(p[i].x == y && p[i].y == x){
          check1 = true;
        }
      }

      if(check1){
        return Destroyer1;

      }
      else{
        return Destroyer2;
      }
      break;

  }
  delete p;
}

char Defender::getType(int x, int y){
  return dmap->m_mapData[x][y];
}
