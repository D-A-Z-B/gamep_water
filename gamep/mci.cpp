#include <Windows.h>
#include <mmsystem.h>
#include <Digitalv.h>
#include "mci.h"
#pragma comment(lib, "winmm.lib")

UINT BgmId;
UINT Effectid;

void PlayBgm(LPCWSTR _soundname)
{
	MCI_OPEN_PARMS openBgm;
	openBgm.lpstrElementName = _soundname;
	// mp3: mpegvideo, wav: waveaudio
	openBgm.lpstrDeviceType = TEXT("mpegvideo");
	mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD_PTR)&openBgm);
	BgmId = openBgm.wDeviceID;
	MCI_PLAY_PARMS playBgm;
	mciSendCommand(BgmId, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD_PTR)&playBgm);
}

void PlayEffect(LPCWSTR _soundname)
{
    // PLAY
    MCI_PLAY_PARMS playEffect;
    if (Effectid != 0)
    {
        mciSendCommand(Effectid, MCI_SEEK, MCI_SEEK_TO_START, (DWORD_PTR)&playEffect);
        mciSendCommand(Effectid, MCI_CLOSE, NULL, (DWORD)NULL); // RAII
        Effectid = 0;
    }
    // OPEN
    MCI_OPEN_PARMS openEffect;
    // mp3: mpegvideo, wav: waveaudio, avi: avivideo
    openEffect.lpstrDeviceType = TEXT("mpegvideo");
    openEffect.lpstrElementName = _soundname;
    mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD_PTR)&openEffect);
    Effectid = openEffect.wDeviceID;


    mciSendCommand(Effectid, MCI_PLAY, MCI_NOTIFY, (DWORD_PTR)&playEffect);
    while (mciSendCommand(Effectid, MCI_STATUS, MCI_STATUS_MODE, (DWORD_PTR)&playEffect))
    {
        break;
    }
}
