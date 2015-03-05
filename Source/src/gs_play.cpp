#include "gs_play.h"
#include "o_enemy.h"
#include "o_playerbullet.h"

using namespace std;


void GS_Play() {

	Play_ReadKeys();
	Play_MovePlayer(playerOne);

	EnemyMove(enemyArray, NUM_ENEMY);
	DrawPlayerBullet(playerBullet);
	UpdatePlayerBullet(playerBullet);
	EnemyHitCheck(enemyArray, playerBullet);

}


void Play_ReadKeys()
{
	//TURN LEFT    
	if (agk::GetRawKeyState(37))
	{
		playerOne.x = playerOne.x - playerOne.velocity;
		if (playerOne.x <= 4)
			playerOne.x = 4;
	}

	//TURN RIGHT    
	if (agk::GetRawKeyState(39))
	{
		playerOne.x = playerOne.x + playerOne.velocity;
		if (playerOne.x >= 610)
			playerOne.x = 610;
	}

	//FIRE BULLET
	if (agk::GetRawKeyState(32))
	{
		FirePlayerBullet(playerBullet, playerOne);
	}



}


void Play_MovePlayer(player_t &player) {

	agk::SetSpritePosition(player.sprite, player.x, player.y);
}


