#include "indieStudio.hpp"

static void AudioProcessEffectLPF(void *buffer, unsigned int frames)
{
    static float low[2] = { 0.0f, 0.0f };
    static const float cutoff = 70.0f / 44100.0f;
    const float k = cutoff / (cutoff + 0.1591549431f);

    for (unsigned int i = 0; i < frames*2; i += 2)
    {
        float l = ((float *)buffer)[i], r = ((float *)buffer)[i + 1];
        low[0] += k * (l - low[0]);
        low[1] += k * (r - low[1]);
        ((float *)buffer)[i] = low[0];
        ((float *)buffer)[i + 1] = low[1];
    }
}

static float *delayBuffer = NULL;
static unsigned int delayBufferSize = 0;
static unsigned int delayReadIndex = 2;
static unsigned int delayWriteIndex = 0;

int main(void) {
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
    InitWindow(screenWidth, screenHeight, "[PLATANOS STUDIOS] Bomberman - Indie Studio");
    SetWindowMinSize(1, 1);
    InitAudioDevice();
    Music music = LoadMusicStream("assets/SplashScreen/audios/log_in.ogg");
    music.looping = false;
    delayBufferSize = 48000 * 2;
    delayBuffer = (float *)RL_CALLOC(delayBufferSize, sizeof(float));

    PlayMusicStream(music);

    float timePlayed = 0.0f;
    bool pause = false;
    bool hasFilter = true;
    bool hasDelay = true;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
       //i would like to update music stream from SplashScreenAudio()
        UpdateMusicStream(music);
        BeginDrawing();
            ClearBackground(RAYWHITE);
            SplashScreen splashScreen;
            splashScreen.SplashScreenImage(screenWidth, screenHeight);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}