#pragma once
#include <fstream>
#include <ostream>
#include "define.h"

class FileManager
{
private:
	FileManager() = default;
public:
	float GetHighScore();
	void SetHighScore(float clearTime);
private:
	std::ofstream writeFile;
	std::ifstream readFile;
	float clearTime;
public:
	static FileManager* GetInst()
	{
		if (m_pInst == nullptr)
			m_pInst = new FileManager;
		return m_pInst;
	}
	static void DestroyInst()
	{
		SAFE_DELETE(m_pInst);
		/*if (m_pInst != nullptr)
		{
			delete m_pInst;
			m_pInst = nullptr;
		}*/
	}
private:
	static FileManager* m_pInst;
};
