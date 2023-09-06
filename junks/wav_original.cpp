#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
#include <tchar.h>

#pragma comment(lib, "winmm.lib")

int main() {
    // Nome do arquivo de áudio a ser reproduzido
    LPSTR audioFilePath = "untitled.wav";

    // Abre o arquivo de áudio
    HWAVEOUT hWaveOut;
    WAVEFORMATEX waveFormat;
    MMRESULT result = 0;

    result = waveOutOpen(&hWaveOut, WAVE_MAPPER, &waveFormat, 0, 0, CALLBACK_NULL);
    if (result != MMSYSERR_NOERROR) {
        std::cerr << "Erro ao abrir o dispositivo de áudio." << std::endl;
        return 1;
    }

    // Prepara a estrutura para reprodução
    WAVEHDR waveHeader = {
        .lpData = audioFilePath,
        .dwBufferLength = 0,
        .dwFlags = 0,
        .dwLoops = 0,
    };
    // ZeroMemory(&waveHeader, sizeof(WAVEHDR));

    // Carrega o arquivo de áudio
    result = waveOutPrepareHeader(hWaveOut, &waveHeader, sizeof(WAVEHDR));
    if (result != MMSYSERR_NOERROR) {
        std::cerr << "Erro ao preparar o cabeçalho do áudio." << std::endl;
        waveOutClose(hWaveOut);
        return 1;
    }

    // Abre o arquivo de áudio
    result = waveOutOpen(&hWaveOut, WAVE_MAPPER, &waveFormat, 0, 0, CALLBACK_NULL);
    if (result != MMSYSERR_NOERROR) {
        std::cerr << "Erro ao abrir o dispositivo de áudio." << std::endl;
        return 1;
    }

    // Reproduz o áudio
    result = waveOutWrite(hWaveOut, &waveHeader, sizeof(WAVEHDR));
    if (result != MMSYSERR_NOERROR) {
        std::cerr << "Erro ao reproduzir o áudio." << std::endl;
        waveOutUnprepareHeader(hWaveOut, &waveHeader, sizeof(WAVEHDR));
        waveOutClose(hWaveOut);
        return 1;
    }

    // Aguarda a reprodução terminar
    while (waveHeader.dwFlags & WAVERR_STILLPLAYING) {
        Sleep(100); // Aguarda 100ms
    }

    // Libera recursos
    waveOutUnprepareHeader(hWaveOut, &waveHeader, sizeof(WAVEHDR));
    waveOutClose(hWaveOut);

    return 0;
}
