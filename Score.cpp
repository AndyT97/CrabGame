#include "Score.h"
#include "agk.h"

Score::Score(unsigned int font, float x) {
	text = agk::CreateText("0");
	agk::SetTextAlignment(text, 1);
	agk::SetTextFont(text, font);
	agk::SetTextSize(text, 50.0f);
	agk::SetTextPosition(text, x, agk::GetVirtualHeight() * 1.0f);
	score = 0;
}

void Score::add_point() {
	score += 1;
}

void Score::reset() {
	score = 0;
}