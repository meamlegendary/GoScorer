#include "GoScorer.h"
#include <iostream>
using namespace std;

//const int ROWS = 19;
//const int COLS = 19;

GoScorer::GoScorer() {
	whiteScore = 0;
	blackScore = 0;
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			board[i][j] = ' ';
		}
	}
}

GoScorer::GoScorer(const GoScorer &g) {
	whiteScore = g.whiteScore;
	blackScore = g.blackScore;
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			board[i][j] = g.board[i][j];
		}
	}
}

void GoScorer::calculateScore() {
	score(0, 0);
	fixBoard();
}
void GoScorer::fixBoard() {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			if (board[i][j] == 'X' || board[i][j] == 'P')
				board[i][j] = ' ';
		}
	}
}

void GoScorer::score(int row, int col) {
	char space = board[row][col];
	int score = 0;
	char player = 'N';
	for (row; row < ROWS; row++) {
		for (int j = col; j < COLS; j++) {
			space = board[row][j];
			if (space == ' ') {
				player = playerArea(row, j, player);
				score = calculatePoints(row, j, space);
				if (player == 'B')
					blackScore += score;
				if (player == 'W')
					whiteScore += score;
			}
		}
	}
	
}

int GoScorer::calculatePoints(int row, int col, char player) {
	
	char space = board[row][col];
	int score = 0;
	/*if (space == 'X') {
		board[row][col] = ' ';
	}*/
	if (row >= 0 && row <= ROWS && col >= 0 && col <= COLS && space == 'X') {
		board[row][col] = 'P';
		score++;

		score += calculatePoints(row + 1, col, player);
		score += calculatePoints(row - 1, col, player);
		score += calculatePoints(row, col + 1, player);
		score += calculatePoints(row, col - 1, player);
	}
	return score;
}

char GoScorer::playerArea(int row, int col, char player) {
	char space = board[row][col];
	//char player = ' '; // B - black, W - white, N - neutral
	if (space == 'B' || space == 'W') {
		player = space;
	}
	if (row >= 0 && row <= ROWS && col >= 0 && col <= COLS && space == ' ') {
		 board[row][col] = 'X';

		 player = playerArea(row + 1, col, player);
		 player = playerArea(row - 1, col, player);
		 player = playerArea(row, col + 1, player);
		 player = playerArea(row, col - 1, player);
	}
	/*if ((space != ' ' || space != 'X') && space != player) {
		return 'N';
	}*/
	return player;
}

ostream &operator << (ostream &out, GoScorer g) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			out.put(g.board[i][j]);
		}
		out.put('\n');
	}
	return out;
}

istream &operator >> (istream &in, GoScorer &g) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			g.board[i][j] = in.get();
		}
		char newLine = in.get();
	}
	return in;
}

int GoScorer::getWhiteScore() {
	return whiteScore;
}

int GoScorer::getBlackScore() {
	return blackScore;
}