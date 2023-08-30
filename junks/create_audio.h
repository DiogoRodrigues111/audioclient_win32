#include <audioclient.h>
#include <windows.h>
#include <mmdeviceapi.h>

HRESULT CreateAudioClient(IMMDevice* pDevice, IAudioClient** ppAudioClient);