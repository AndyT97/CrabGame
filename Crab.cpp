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

	//agk::SetClearColor( 151,170,204 ); // light blue
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
	agk::SetSpritePositionByOffset(crab, player_x, player_y);
	agk::Sync();

	return 0; // return 1 to close app
}


void app::End (void)
{

}
