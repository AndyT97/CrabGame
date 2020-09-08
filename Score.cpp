#include "Score.h"
#include "agk.h"

Score::Score(unsigned int font, float x) {
	text = agk::CreateText("0");
	agk::SetTextAlignment(text, 1);
	agk::SetTextFont(text, font);
	agk::SetTextColor(text, 245, 66, 66);
	agk::SetTextSize(text, 50.0f);
	agk::SetTextPosition(text, x, agk::GetVirtualHeight() * 0.1f);
	score = 0;
}

Score::~Score() {

}
void Score::update_text() {
	char* str_score = agk::Str(score);
	agk::SetTextString(text, str_score);
	agk::DeleteString(str_score);
}

void Score::add_point() {
	score += 1;
	update_text();
}

void Score::reset() {
	score = 0;
	update_text();
}

