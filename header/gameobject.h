struct SDL_Surface;

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
class GameObject{
    public:
        GameObject();
        bool isDead = false;
        int VEL=1, SPEED = 50;
        int x, y, w, h, dirx, diry, timer;
        SDL_Surface *sprite;
};
#endif