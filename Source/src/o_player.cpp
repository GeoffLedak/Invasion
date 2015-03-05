#include "main.h"
#include "o_player.h"
#include "s_functions.h"

player_t playerOne;

void PlayerInitialize(player_t& player) {

	player.shipSprite = agk::LoadSprite( "Graphics/ship.png" );
	player.explodeSprite = agk::LoadSprite("Graphics/explode.png");

	agk::SetSpriteAnimation(player.explodeSprite, 30, 16, 2);
	agk::PlaySprite(player.explodeSprite, 10, 1);
	agk::SetSpriteVisible(player.explodeSprite, false);

	player.sprite = player.shipSprite;
	
	player.velocity = 4;
}


void PlayerReset(player_t& player) {

	player.x = 230;
	player.y = 420;
	agk::SetSpritePosition(player.sprite, player.x, player.y);

}