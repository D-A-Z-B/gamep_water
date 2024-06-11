#include "Core.h"
Core* Core::m_pInst = nullptr;

bool Core::Init()
{
	//m_pPlayer->Init();
	return false;
}

void Core::Run()
{
	while (true)
	{
		Update();
		//Gotoxy(0, 0);
		Render();
		// 시간동기화
		//FrameSync(60);
	}
}

void Core::Update()
{
	// Obejct;
}

void Core::Render()
{
	// Render();
}
