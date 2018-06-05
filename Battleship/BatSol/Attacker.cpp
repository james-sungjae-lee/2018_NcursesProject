#include "Attacker.h"

Attacker::Attacker(){
  amap = new CBattleShipMap(15);
  amap->Draw();
}

Attacker::~Attacker(){
  delete amap;
}

void Attacker::inputAttack(int x,int y,Defender *d){

  if(d->isHit(x,y)){
    if(d->isDestroyed(x,y)){
      showDestroy(d->getDestroyedShip(x,y));
    }
    else{
      showHit(x,y);
    }
  }
  else {
    showMiss(x,y);
  }

}

void Attacker::showHit(int x, int y){
  if(amap->m_mapData[x][y] != 'D'){
    amap->m_mapData[x][y] = 'H';
    amap->drawStatus(x,y);
  }
}

void Attacker::showMiss(int x, int y){
  amap->m_mapData[x][y] = 'M';
  amap->drawStatus(x,y);
}

void Attacker::showDestroy(Ship *s){
  Point *p = new Point[s->getSize()];
  s->getPosition(p);

  for (int i = 0; i < s->getSize(); i++) {
    amap->m_mapData[p[i].y][p[i].x] = 'D';
    amap->drawStatus(p[i].y,p[i].x);
  }
}
