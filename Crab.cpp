// Includes
#include "template.h"

// Namespace
using namespace AGK;

app App;

float const app::PLAYER_SPEED = 200.0f;

void app::Begin(void)
{
	agk::SetVirtualResolution (1024, 768);
	background = agk::LoadSprite("media/beach.jpg");
	crab = agk::LoadSprite("media/crab.png");
	worm = agk::LoadImage("media/worm.png");

	agk::SetSyncRate(60,0);
	agk::SetScissor(0,0,0,0);

	player_x = agk::GetVirtualWidth() / 2.0f;
	player_y = agk::GetVirtualHeight() / 2.0f;

}

int app::Loop (void)
{
	float const move_this_frame = PLAYER_SPEED * agk::GetFrameTime();
	if (agk::GetRawKeyState(AGK_KEY_W)) {
		player_y -= move_this_frame;
	}
	if (agk::GetRawKeyState(AGK_KEY_S)) {
		player_y += move_this_frame;
	}
	if (agk::GetRawKeyState(AGK_KEY_A)) {
		player_x -= move_this_frame;
	}
	if (agk::GetRawKeyState(AGK_KEY_D)) {
		player_x += move_this_frame;
	}
	
	float const min_x = agk::GetSpriteWidth(crab) / 2.0f;
	float const min_y = agk::GetSpriteHeight(crab) / 2.0f;
	float const max_x = agk::GetVirtualWidth() - min_x;
	float const max_y = agk::GetVirtualHeight() - min_y;

	if (player_x < min_x) {
		player_x = min_x;
	}
	else if (player_x > max_x) {
		player_x = max_x;
	}
	if (player_y < min_y) {
		player_y = min_y;
	}
	else if (player_y > max_y) {
		player_y = max_y;
	}

	agk::SetSpritePositionByOffset(crab, player_x, player_y);
	agk::Sync();

	return 0; // return 1 to close app
}


void app::End (void)
{

}
