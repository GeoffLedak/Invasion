#include "o_enemy.h"
#include "main.h"


bool enemy_direction = true;
float ENEMY_SPEED = 0.3;
float ENEMY_SPEED_MODIFIER = 0.02;
float ENEMY_DOWN_SPEED = 2;
float ENEMY_ANIMATION_SPEED = 3.0;

enemy_t enemyArray[NUM_ENEMY];


void EnemyInitialize(enemy_t enemy[], int size)
{
	for (int i = 0; i < size; i++)
	{
		enemy[i].active = true;
		enemy[i].sprite = agk::LoadSprite("Graphics/space_invader_sheet.png");
//		agk::SetSpriteSize(enemy[i].id, 24, 16);

		//row 1
		if (i < 10)
		{
			enemy[i].x = 4 + 60 * i;
			enemy[i].y = 20;
		}

		//row 2
		else if (i >= 10 && i < 20)
		{
			enemy[i].x = 4 + 60 * (i - 10);
			enemy[i].y = 45;
		}

		//row 3
		else if (i >= 20 && i < 30)
		{
			enemy[i].x = 4 + 60 * (i - 20);
			enemy[i].y = 70;
		}

		//row 4
		else if (i >= 30 && i < 40)
		{
			enemy[i].x = 4 + 60 * (i - 30);
			enemy[i].y = 95;
		}

		//row 5
		else if (i >= 40 && i < 50)
		{
			enemy[i].x = 4 + 60 * (i - 40);
			enemy[i].y = 120;
		}

		//row 6
		else if (i >= 50 && i < 60)
		{
			enemy[i].x = 4 + 60 * (i - 50);
			enemy[i].y = 145;
		}

		agk::SetSpritePosition(enemy[i].sprite, enemy[i].x, enemy[i].y);
//		agk::SetSpriteShape(enemy[i].sprite, 2);
		agk::SetSpriteAnimation(enemy[i].sprite, 24, 16, 2);
		agk::PlaySprite(enemy[i].sprite, ENEMY_ANIMATION_SPEED, 1);
	}

}


void EnemyMove(enemy_t enemy[], int size)
{
	for (int i = 0; i < size; i++)
	{
		//Stop moving left, instead move right
		//Increase enemy speed and move enemies down
		if (enemy[i].active == true && enemy[i].x <= 4)
		{
			enemy_direction = true;
			ENEMY_SPEED += ENEMY_SPEED_MODIFIER;
			enemy[i].x += ENEMY_SPEED;
			ENEMY_ANIMATION_SPEED += 0.4;

			for (int j = 0; j < size; j++)
			{
				enemy[j].y += ENEMY_DOWN_SPEED;
			}
		}
		if (enemy[i].active == true && enemy_direction == true)
			enemy[i].x += ENEMY_SPEED;


		//Stop moving right, instead move left
		//Increase enemy speed and move enemies down
		if (enemy[i].active == true && enemy[i].x >= 610)
		{
			enemy_direction = false;
			ENEMY_SPEED += 0.01;
			enemy[i].x -= ENEMY_SPEED;
			ENEMY_ANIMATION_SPEED += 0.4;

			for (int j = 0; j < size; j++)
			{
				enemy[j].y += ENEMY_DOWN_SPEED;
			}
		}
		if (enemy[i].active == true && enemy_direction == false)
			enemy[i].x -= ENEMY_SPEED;


		//Set actual sprite position
		if (enemy[i].active == true)
			agk::SetSpritePosition(enemy[i].sprite, enemy[i].x, enemy[i].y);
	}
}


void EnemyResetPositions(enemy_t enemy[], int size)
{


}


void EnemyHitCheck(enemy_t enemyArray[], playerbullet_t &playerBullet)
{
	if (playerBullet.live == true)
	{
		for (int i = 0; i < NUM_ENEMY; i++)
		{
			if ((agk::GetSpriteCollision(playerBullet.sprite, enemyArray[i].sprite) == true) && enemyArray[i].active == true)
			{
				//			agk::PlaySound(enemyArray[0].explode_sound, 50, 0);
				enemyArray[i].active = false;
				ResetPlayerBullet(playerBullet);

				agk::SetSpriteVisible(enemyArray[i].sprite, false);
				//			agk::DeleteSprite(enemyArray[i].sprite);
				//			agk::SetSpriteVisible(playerBulletArray[i].sprite, false);

				//			enemy_count -= 1;
				enemyArray[i].active = false;
				//			enemy[i].x = -500;
				//			ENEMY_DISTANCE_LEFT = 100000;
				//			ENEMY_DISTANCE_RIGHT = 100000;
				//			player.score += 10;
			}
		}
	}


}