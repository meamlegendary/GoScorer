#pragma once

#include <iostream>
using namespace std;

const int ROWS = 19;
const int COLS = 19;

class GoScorer
{
public:
	GoScorer();
	GoScorer(const GoScorer &g);
	int getWhiteScore();
	int getBlackScore();
	friend ostream &operator << (ostream &out, GoScorer $g);
	friend istream &operator >> (istream &in, GoScorer &g);
	void calculateScore();

private:
	int blackScore;
	int whiteScore;
	char board[19][20];
	void score(int row, int col);
	void fixBoard();
	int calculatePoints(int row, int col, char player);
	char playerArea(int row, int col, char player);
};

