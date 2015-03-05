#ifndef __GS_TITLESCREEN__
#define __GS_TITLESCREEN__

#include <string>

using namespace std;

void InitializeTextScreens();
void HideTextScreens();
void GS_TitleScreen();
void GS_GameOver();
void GS_NextWave();
void GS_StartingRound();

extern unsigned int titleScreenSprite;
extern unsigned int gameOverSprite;
extern unsigned int nextWaveSprite;
extern unsigned int getReadyGameSprite;
extern unsigned int pressSpaceBarSprite;

extern unsigned short alphaValue;

#endif