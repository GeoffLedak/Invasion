#ifndef __O_ENEMY__
#define __O_ENEMY__

#include "e_direction.h"
#include "o_playerbullet.h"


#define NUM_ENEMY 60

extern bool enemy_direction;
extern float ENEMY_SPEED;
extern float ENEMY_SPEED_MODIFIER;
extern float ENEMY_DOWN_SPEED;
extern float ENEMY_ANIMATION_SPEED;


typedef struct {

	unsigned int sprite;
	float x;
	float y;
	Direction direction;
	bool active;
} enemy_t;

extern enemy_t enemyArray[];


void EnemyInitialize(enemy_t enemy[], int size);
void EnemyMove(enemy_t enemy[], int size);
void EnemyResetPositions(enemy_t enemy[], int size);
void EnemyHitCheck(enemy_t[], playerbullet_t &playerBullet);


#endif