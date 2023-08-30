#include <iostream>
#include <portaudio.h>
#include <sndfile.h> // For reading audio files

static int audioCallback(const void *inputBuffer,
                         void *outputBuffer,
                         unsigned long framesPerBuffer,
                         const PaStreamCallbackTimeInfo *timeInfo,
                         PaStreamCallbackFlags statusFlags,
                         void *userData)
{
    // Cast the output buffer to the appropriate data type
    float *out = (float *)outputBuffer;
    
    // Get the user data (file handle) passed from main()
    SNDFILE *file = (SNDFILE *)userData;

    // Read audio data from the file
    sf_count_t numFramesRead = sf_readf_float(file, out, framesPerBuffer);

    // If we reach the end of the file, start reading from the beginning again
    if (numFramesRead < framesPerBuffer)
    {
        sf_seek(file, 0, SEEK_SET);
        sf_readf_float(file, out + numFramesRead, framesPerBuffer - numFramesRead);
    }

    return paContinue;
}

int main()
{
    // ... (Initialize PortAudio and create the audio stream as shown in the previous example)

    // Open the audio file for reading
    const char *filename = "untitled.wav"; // Change this to your audio file path
    SF_INFO file_info;
    SNDFILE *file = sf_open(filename, SFM_READ, &file_info);
    PaStream *stream;
    PaError err;

    err = Pa_Initialize();

    if (!file)
    {
        std::cerr << "Error opening audio file" << std::endl;
        Pa_Terminate();
        return 1;
    }

    // Define parameters for audio stream
    PaStreamParameters outputParameters;
    outputParameters.device = Pa_GetDefaultOutputDevice();
    outputParameters.channelCount = 2; // Stereo output
    outputParameters.sampleFormat = paFloat32; // 32-bit floating-point audio
    outputParameters.suggestedLatency = Pa_GetDeviceInfo(outputParameters.device)->defaultLowOutputLatency;
    outputParameters.hostApiSpecificStreamInfo = nullptr;

    err = Pa_OpenStream(&stream,
                        nullptr, // No input
                        &outputParameters,
                        44100,   // Sample rate
                        paFramesPerBufferUnspecified,
                        paClipOff, // Disable clipping
                        audioCallback,
                        nullptr);  // User data (not used in this example)

    if (err != paNoError)
    {
        std::cerr << "Stream open error: " << Pa_GetErrorText(err) << std::endl;
        Pa_Terminate();
        return 1;
    }

    // Start the audio stream, passing the file handle as user data
    err = Pa_StartStream(stream);
    if (err != paNoError)
    {
        std::cerr << "Stream start error: " << Pa_GetErrorText(err) << std::endl;
        sf_close(file);
        Pa_CloseStream(stream);
        Pa_Terminate();
        return 1;
    }

    // Wait for a key press before stopping the stream
    std::cout << "Press Enter to stop..." << std::endl;
    std::cin.get();

    // Stop and close the audio stream
    err = Pa_StopStream(stream);
    if (err != paNoError)
    {
        std::cerr << "Stream stop error: " << Pa_GetErrorText(err) << std::endl;
    }

    // Close the audio file
    sf_close(file);

    // ... (Terminate PortAudio and clean up as shown in the previous example)

    return 0;
}
