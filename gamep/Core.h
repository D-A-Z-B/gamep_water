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
private:
	static Core* m_pInst;
};

