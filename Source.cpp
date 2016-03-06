#include <iostream>
#include <fstream>
using namespace std;
#include "GoScorer.h"

int main() {
	GoScorer game;
	ifstream input("GoBoard.txt");
	input >> game;
	input.close();
	game.calculateScore();
	cout << game << endl << endl << "Black Score:  " << game.getBlackScore() << endl << "White Score:  " << game.getWhiteScore() << endl;
	//game.calculateScore();
	//cout << game.getWhiteScore() << endl << game.getBlackScore();
	system("pause");
}