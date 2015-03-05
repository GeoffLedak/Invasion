#include "main.h"

using namespace std;
Main main;


void Main::begin(void) 
{
	MASTER_CLOCK = 0;
	timerRemaining = false;

	agk::SetVirtualResolution(640, 480);
	agk::SetSyncRate(60, 0);
	agk::SetScissor(0, 0, 0, 0);

	gameState = TITLE_SCREEN;

	InitializeTextScreens();

	PlayerInitialize(playerOne);
	PlayerReset(playerOne);

	EnemyInitialize(enemyArray, NUM_ENEMY);

	InitializePlayerBullet(playerBullet);

	// Hide sprites
	S_SpritesVisable(false);

	HideTextScreens();


}


void Main::loop(void)
{
	switch (gameState) {

		case TITLE_SCREEN:
			agk::Print("Game State: Title Screen");
			GS_TitleScreen();

			// If user presses the Space Bar, start the round
			if (agk::GetButtonPressed(1) == 1) {
				gameState = STARTING_ROUND;
			}
			break;

		case STARTING_ROUND:
			agk::Print("Game State: Starting Round");
			GS_StartingRound();
			break;

		case PLAY:
			agk::Print("Game State: Play");
			agk::PrintC("playerOne x: "); agk::Print(playerOne.x);
			agk::PrintC("playerOne y: "); agk::Print(playerOne.y);
			GS_Play();
			break;

		case PAUSE:
			agk::Print("Game State: Pause");
			agk::Print("PAUSE");
			break;

		default:
			agk::Print("Error, not a valid game state");
		}


	agk::Sync();
}


void Main::end(void)
{

}

