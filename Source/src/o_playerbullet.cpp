#include "o_playerbullet.h"
#include "main.h"


playerbullet_t playerBullet;



void InitializePlayerBullet(playerbullet_t &bullet)
{
		bullet.sprite = agk::LoadSprite("Graphics/laser.png");
		agk::SetSpriteSize(bullet.sprite, 4, 16);
		agk::SetSpritePosition(bullet.sprite, -20, -20);
		agk::SetSpriteShape(bullet.sprite, 2);

		bullet.speed = 8;
		bullet.live = false;
}


void ResetPlayerBullet(playerbullet_t &bullet)
{
	agk::SetSpriteVisible(bullet.sprite, false);
	bullet.live = false;
}


void DrawPlayerBullet(playerbullet_t &bullet)
{
		if (bullet.live)
			agk::SetSpritePosition(bullet.sprite, bullet.x, bullet.y);
}


void FirePlayerBullet(playerbullet_t &bullet, player_t &player)
{
		if (!bullet.live)
		{
			agk::SetSpriteVisible(bullet.sprite, true);
			bullet.x = player.x + 11;
			bullet.y = player.y - 4;
			bullet.live = true;
//			agk::PlaySound(player.fire_sound, 50, 0);
		}
	

}


void UpdatePlayerBullet(playerbullet_t &bullet)
{
		if (bullet.live)
		{
			bullet.y -= bullet.speed;

			//If the enemy bullet goes off the screen, deactivate it
			if (bullet.y < -20)
				bullet.live = false;
		}	
}