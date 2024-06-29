#pragma once
#include "define.h"
#include "Player.h"
#include "Camera.h"

class Core
{
private:
	Core() = default;
public:
	bool Init();
	void Run();
	void Dead();
	void Clear();
	float ReturnCurrentTime() { return currentTime / CLOCKS_PER_SEC; }
private:
	void Update();
	void Render();
public:
	static Core* GetInst()
	{
		if(m_pInst == nullptr)
			m_pInst = new Core;
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
public:
	Player *player;
	Camera *cam;
	bool isDead;
	bool isClear;
private:
	clock_t startTime;
	float currentTime;
private:
	static Core* m_pInst;
};

