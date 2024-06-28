#include "FileManager.h"
FileManager* FileManager::m_pInst = nullptr;

int FileManager::GetHighScore()
{
	readFile.open("Score.txt");
	readFile >> score;
	readFile.close();
	return score;
}

void FileManager::SetHighScore(int newScore)
{
	writeFile.open("Score.txt");
	writeFile << newScore;
	writeFile.close();
}
