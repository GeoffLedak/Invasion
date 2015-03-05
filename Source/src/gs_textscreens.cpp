#include "main.h"
#include "gs_textscreens.h"
#include "i_timing.h"
#include "s_functions.h"


unsigned int titleScreenSprite;
unsigned int gameOverSprite;
unsigned int nextWaveSprite;
unsigned int getReadyGameSprite;
unsigned int pressSpaceBarSprite;

unsigned short alphaValue;



void InitializeTextScreens()
{
	titleScreenSprite = agk::LoadSprite("Graphics/title_screen.png");
	agk::SetSpriteSize(titleScreenSprite, 640, 480);
	agk::SetSpritePosition(titleScreenSprite, 0, 0);
	agk::SetSpriteDepth(titleScreenSprite, 1);

	gameOverSprite = agk::LoadSprite("Graphics/game_over.png");
	agk::SetSpriteSize(gameOverSprite, 640, 480);
	agk::SetSpritePosition(gameOverSprite, 0, 0);
	agk::SetSpriteDepth(gameOverSprite, 2);
	agk::SetSpriteVisible(gameOverSprite, 0);

	nextWaveSprite = agk::LoadSprite("Graphics/next_wave.png");
	agk::SetSpriteSize(nextWaveSprite, 640, 480);
	agk::SetSpritePosition(nextWaveSprite, 0, 0);
	agk::SetSpriteDepth(nextWaveSprite, 2);
	agk::SetSpriteVisible(nextWaveSprite, 0);

	getReadyGameSprite = agk::LoadSprite("Graphics/get_ready.png");
	agk::SetSpriteSize(getReadyGameSprite, 640, 480);
	agk::SetSpritePosition(getReadyGameSprite, 0, 0);
	agk::SetSpriteDepth(getReadyGameSprite, 2);
	agk::SetSpriteVisible(getReadyGameSprite, 0);

	pressSpaceBarSprite = agk::LoadSprite("Graphics/press_spacebar.png");
	agk::SetSpriteSize(pressSpaceBarSprite, 270, 43);
	agk::SetSpriteAnimation(pressSpaceBarSprite, 270, 43, 2);
	agk::SetSpritePosition(pressSpaceBarSprite, 130, 432);

	agk::SetSpriteDepth(pressSpaceBarSprite, 1);
	agk::SetSpriteDepth(titleScreenSprite, 2);
	agk::PlaySprite(pressSpaceBarSprite, 7, 1);

	alphaValue = 255;
}



void HideTextScreens()
{
	agk::SetSpriteVisible(titleScreenSprite, false);
	agk::SetSpriteVisible(gameOverSprite, false);
	agk::SetSpriteVisible(nextWaveSprite, false);
	agk::SetSpriteVisible(getReadyGameSprite, false);
	agk::SetSpriteVisible(pressSpaceBarSprite, false);
}



void GS_TitleScreen()
{
	agk::SetSpriteVisible(titleScreenSprite, true);
	agk::SetSpriteVisible(pressSpaceBarSprite, true);
}



void GS_StartingRound()
{
	agk::Print(MASTER_CLOCK);
	agk::Print("Round beginning...");

	HideTextScreens();
	S_SpritesVisable(true);
	agk::SetSpriteVisible(getReadyGameSprite, true);

	if ( !StateDuration(128) )
	{
		agk::SetSpriteColorAlpha(getReadyGameSprite, alphaValue);
		alphaValue -= 2;
	}
	else
	{
		S_SpritesVisable(true);
		gameState = PLAY;

	}

}



void GS_GameOver() {


}


void GS_NextWave() {


}


