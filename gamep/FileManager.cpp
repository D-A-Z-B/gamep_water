#include "FileManager.h"
FileManager* FileManager::m_pInst = nullptr;

float FileManager::GetHighScore()
{
	readFile.open("Score.txt");
	readFile >> clearTime;
	readFile.close();
	return clearTime;
}

void FileManager::SetHighScore(float clearTime)
{
	if (clearTime > GetHighScore() && GetHighScore() != 0)
	{
		return;
	}
	writeFile.open("Score.txt");
	writeFile << clearTime;
	writeFile.close();
}
