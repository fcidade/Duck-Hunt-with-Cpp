#include "gameobject.h"

#ifndef DUCK_H
#define DUCK_H
class Duck : public GameObject{
    public:
        Duck(int s);
        void Move();
        void Spawn();
        bool Intersects(int cx, int cy);
        void Die();
};
#endif