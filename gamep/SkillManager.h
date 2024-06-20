#pragma once
#include "define.h"
class SkillManager
{
private:
	SkillManager() = default;
public:
	bool Init();
	void Run();
private:
	void Update();
	void Render();
public:
	static SkillManager* GetInst()
	{
		if (m_pInst == nullptr)
			m_pInst = new SkillManager;
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
	SkillManager* player;
private:
	static SkillManager* m_pInst;
};

