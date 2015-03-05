#include "s_functions.h"


void S_SpritesVisable(bool flag)
{
	if (flag)
	{
		agk::SetSpriteVisible(playerOne.sprite, true);
	}

	else
	{
		agk::SetSpriteVisible(playerOne.sprite, false);
	}
}