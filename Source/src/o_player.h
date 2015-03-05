#ifndef __O_PLAYER__
#define __O_PLAYER__

#include "e_direction.h"


typedef struct {

	unsigned int sprite;
	unsigned int shipSprite;
	unsigned int explodeSprite;
	Direction direction;
	short x;
	short y;
	short velocity;

} player_t;

extern player_t playerOne;

void PlayerInitialize(player_t&);
void PlayerReset(player_t&);

#endif