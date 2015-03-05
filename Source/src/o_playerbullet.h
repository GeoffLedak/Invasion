#ifndef __O_PLAYERBULLET__
#define __O_PLAYERBULLET__

#include "o_player.h"

typedef struct {

	unsigned int sprite;
	int x;
	int y;
	bool live;
	int speed;

} playerbullet_t;

extern playerbullet_t playerBullet;

void InitializePlayerBullet(playerbullet_t &bullet);
void ResetPlayerBullet(playerbullet_t &bullet);
void DrawPlayerBullet(playerbullet_t &bullet);
void FirePlayerBullet(playerbullet_t &bullet, player_t &player);
void UpdatePlayerBullet(playerbullet_t &bullet);


#endif