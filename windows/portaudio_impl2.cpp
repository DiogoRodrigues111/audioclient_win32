/**
 * AudioAW version 2 - library and program part of the AbrilOS
 * 
 * Main Programmer: Diogo Rodrigues Roessler
*/

#include <iostream>
#include <inttypes.h>
#include <portaudio.h>

/* Frame Rates CONFIGURATION */

#define FRAME_RATE_192000       (192000)
#define FRAME_RATE_96000         (96000)
#define FRAME_RATE_88200         (88200)
#define FRAME_RATE_48000         (48000)
#define FRAME_RATE_44100         (44100)

/* Frame per Buffer CONFIGURATION */

#define FRAME_PER_BUFFER_16         (16)
#define FRAME_PER_BUFFER_32         (32)
#define FRAME_PER_BUFFER_64         (64)
#define FRAME_PER_BUFFER_128        (128)
#define FRAME_PER_BUFFER_256        (256)
#define FRAME_PER_BUFFER_512        (512)
#define FRAME_PER_BUFFER_1024       (1024)
#define FRAME_PER_BUFFER_2048       (2048)
#define FRAME_PER_BUFFER_4096       (4096)

typedef struct {
    float d_phase_right;
    float d_phase_left;
    float d_bass_boost;
    float d_clear_according;
} CALLBACK_INFORMATION_FN, *CALLBACK_INFORMATION_FN_PTR;

static CALLBACK_INFORMATION_FN data;

static float _bass_boost_alternative_ns = 0.96F;
static float _clear_according = 0.96F;

// Callback 1 - used for function
static int audioCallback_1(const void *inputBuffer,
                         void *outputBuffer,
                         unsigned long framesPerBuffer,
                         const PaStreamCallbackTimeInfo *timeInfo,
                         PaStreamCallbackFlags statusFlags,
                         void *userData)
{
    CALLBACK_INFORMATION_FN *pData = (CALLBACK_INFORMATION_FN_PTR)userData;

    // Cast the output buffer to the appropriate data type
    // float *in = (float*)inputBuffer;

    // Reserve right for unsed warning
    // (void)inputBuffer;

    // Cast the output buffer to the appropriate data type
    float *out = (float *)outputBuffer;

    // Generate audio samples here and fill the output buffer
    for (unsigned int i = 0; i < framesPerBuffer; i++)
    {
        // Generate your audio samples (e.g., sine wave, white noise, etc.)
        // and write them to the 'out' buffer.
        // Example: out[i] = ...;

        *out++ = pData->d_phase_left;   /* Left */
        *out++ = pData->d_phase_right;  /* Right */
        *out++ = _bass_boost_alternative_ns;   /* Bass Boost */
        *out++ = _clear_according;      /* Clear according of the song */

        /* higher pitch so we can distinguish left and right. */
        pData->d_phase_left = 0.01F;
        if (pData->d_phase_left >= 1.0F)
            { pData->d_phase_left -= 2.0F; }

        /* Generate simple sawtooth phaser that ranges between -1.0 and 1.0. */
        pData->d_phase_right = 0.03F;
        if (pData->d_phase_right >= 1.0F)
            { pData->d_phase_right -= 2.0F; }
        
        /* Generate simple clear according phaser that ranges between -1.0 and 1.0. */
        if (_clear_according >= 0.010F)
        {
            float j;
            for (j = 0; j < _clear_according * 0.013F; --j) {
                _clear_according = _clear_according * j;
            }
        }
        else
            { out = &_clear_according; }

        /* Generate simple bass boost phaser that ranges between -1.0 and 1.0. */
        if (_bass_boost_alternative_ns >= 0.04F)
        {
            float j, k;
            
            for (k = 0; k < 0x0CA; k++) {
                k++;
            }

            for (j = 0; j < k * 0.8133796F +1.0F; ++j) {
                _bass_boost_alternative_ns = j * k + (0.95644F - 0xFA5);
            }
        }
        else
            { out = &_bass_boost_alternative_ns; }
    }

    return paContinue;
}

int main()
{
    PaError err;

    // Initialize PortAudio
    err = Pa_Initialize();
    if (err != paNoError)
    {
        std::cerr << "PortAudio initialization error: " << Pa_GetErrorText(err) << std::endl;
        return 1;
    }

    // Create the audio stream
    PaStream *stream;

   // Open in default audio selected for operationg system
   err = Pa_OpenDefaultStream( &stream,
                                 0,                 /* no input channels */
                                 2,                 /* stereo output */
                                 paFloat32,           /* 32 bit floating point output */
                                 FRAME_RATE_96000,         /* SAMPLE RATE */
                                 FRAME_PER_BUFFER_2048,     /* frames per buffer, i.e. the number
                                                            of sample frames that PortAudio will
                                                            request from the callback. Many apps
                                                            may want to use
                                                            paFramesPerBufferUnspecified, which
                                                            tells PortAudio to pick the best,
                                                            possibly changing, buffer size. */
                                 audioCallback_1,   /* this is your callback function */
                                 &data              /*This is a pointer that will be passed to
                                                        your callback */
    );

    if (err != paNoError)
    {
        std::cerr << "Stream open error: " << Pa_GetErrorText(err) << std::endl;
        Pa_Terminate();
        return 1;
    }

    // Start the audio stream
    err = Pa_StartStream(stream);
    if (err != paNoError)
    {
        std::cerr << "Stream start error: " << Pa_GetErrorText(err) << std::endl;
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

    err = Pa_CloseStream(stream);
    if (err != paNoError)
    {
        std::cerr << "Stream close error: " << Pa_GetErrorText(err) << std::endl;
    }

    // Terminate PortAudio
    Pa_Terminate();

    return 0;
}
