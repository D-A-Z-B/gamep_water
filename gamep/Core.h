#pragma once
// GameManager
// 싱글톤 - 다이나믹
// 늦은 초기화(lazy initialization): 객체 생성 시점으르 지연시켜서 
// 내가 필요한 시점에 초기화할 수 있게 하는 것
#include "define.h"

class Core
{
private:
	Core();
public:
	bool Init();
	void Run();
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
private:
	static Core* m_pInst;
};

