#pragma once
class Score
{
	unsigned int text;
	int score;

public:
	Score(unsigned int font, float x);
	~Score();

	void add_point();
	void reset();

private:
	void update_text();
};

