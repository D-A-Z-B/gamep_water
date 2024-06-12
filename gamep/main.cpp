#include "TitleScene.h"
#include "console.h"
#include "Core.h"

int main() {
	SetCursorVis(false, 1);
	if (!TitleScene()) {
		return 0;
	}
	else
	{
		if (Core::GetInst()->Init())
		{
			cout << "Game Init Error" << endl;
			Core::DestroyInst();
			return 0;
		}
		Core::GetInst()->Run();
		Core::DestroyInst();
	}
}