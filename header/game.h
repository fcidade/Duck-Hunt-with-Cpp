#ifndef GAME_H
#define GAME_H
class Game{
    public:
        static unsigned int round, counter, match;
        static bool hasStart;
        Game();
        static void Start();
        static void SpawnEnemy();
        static void IncreaseCounter();
        static void Loose();
        static void Win();
        static void NextMatch();
};
#endif