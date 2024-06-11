#pragma once
// GameManager
// �̱��� - ���̳���
// ���� �ʱ�ȭ(lazy initialization): ��ü ���� �������� �������Ѽ� 
// ���� �ʿ��� ������ �ʱ�ȭ�� �� �ְ� �ϴ� ��
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

