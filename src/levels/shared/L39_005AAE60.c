#include "common.h"

/* localdecomp:start func_L39_005AAE60 */
/* from rac2-decomp's func_L00_00310D30 */
typedef union Frame_005AAE60 {
    u32 word;
    u8 *ptr;
    f32 *duration;
} Frame_005AAE60;
typedef struct Track_005AAE60 {
    u8 pad00[0x10];
    u8 frames;
    u8 pad11[2];
    u8 extra;
    u8 pad14[8];
    Frame_005AAE60 data[1];
} Track_005AAE60;
typedef struct Model_005AAE60 {
    u8 pad00[8];
    u8 joints;
    u8 pad09[0x3f];
    Track_005AAE60 *tracks[1];
} Model_005AAE60;
typedef struct State_005AAE60 {
    s16 index, count;
    u8 mode, events, currentPacked, nextPacked;
    char pad08[8];
    char *output;
    Model_005AAE60 *model;
    char pad18[8];
    u8 currentFrame, nextFrame, currentTrack, nextTrack;
    f32 phase, rate, frameScale;
    char pad30[8];
    u8 *currentData, *nextData;
} State_005AAE60;
extern void func_L39_005AB330(State_005AAE60 *, int, int, u8 *);
extern void func_L01_0043C8F8(u8 *, u32, u8 *, int);
extern int func_001264E0(int);
extern void func_L01_0043E8D0(State_005AAE60 *);
extern void func_L01_00441658(char *, int, int, f32);
void func_L39_005AAE60(void *unused, State_005AAE60 *state)
{
    u32 data;
    s16 duration;
    f32 step;
    state->events = 0;
    {
        step = state->rate * state->frameScale;
        if (step != 0.0f) {
            state->phase += step;
            if (state->phase > 0.99f && state->phase < 1.01f)
                state->phase = 1.0f;
            while (state->phase >= 1.0f) {
                Track_005AAE60 *nextTrack, *track;
                state->events |= 1;
                state->currentFrame = state->nextFrame;
                if (state->nextPacked && !state->currentPacked)
                    state->currentData = state->nextData;
                state->currentPacked = state->nextPacked;
                state->currentTrack = state->nextTrack;
                state->nextFrame++;
                nextTrack = state->model->tracks[state->nextTrack];
                if (state->nextFrame >= nextTrack->frames) {
                    state->nextFrame = 0;
                    state->events |= 2;
                }
                state->phase = (state->phase - 1.0f) / state->frameScale;
                track = state->model->tracks[state->currentTrack];
                if (track->extra == 0xFF) {
                    state->frameScale = *track->data[state->currentFrame].duration;
                } else {
                    data = track->data[state->currentFrame].word;
                    duration = *(s16 *)(data & 0x0FFFFFFF);
                    if (duration == 0)
                        state->frameScale = 0.0f;
                    else
                        state->frameScale = 1.0f / duration;
                }
                state->phase = state->phase * state->frameScale;
            }
        }
    }
    if (state->nextPacked) {
        func_L39_005AB330(state, state->nextTrack, state->nextFrame, state->nextData);
    } else {
        Track_005AAE60 *track = state->model->tracks[state->nextTrack];
        if (track->extra == 0xFF) {
            state->nextData = track->data[state->nextFrame].ptr;
        } else {
            func_L01_0043C8F8((u8 *)(track->data + track->frames) + track->extra * 4,
                track->data[state->nextFrame].word, state->nextData, state->model->joints);
            func_001264E0(0);
        }
    }
    if (state->currentTrack == 0xFF) {
        f32 phase = state->phase;
        f32 ratio = step / (1.0f - (phase - step));
        char *output = state->output;
        u8 *cur = state->currentData;
        state->phase = 0.0f;
        state->output = 0;
        state->currentData = state->nextData;
        func_L01_0043E8D0(state);
        state->phase = phase;
        state->currentData = cur;
        state->output = output;
        func_L01_00441658(output, 0x70000000, state->count, ratio);
    } else {
        if (state->currentPacked) {
            func_L39_005AB330(state, state->currentTrack, state->currentFrame, state->currentData);
        } else {
            Track_005AAE60 *track = state->model->tracks[state->currentTrack];
            if (track->extra == 0xFF) {
                state->currentData = track->data[state->currentFrame].ptr;
            } else {
                func_L01_0043C8F8((u8 *)(track->data + track->frames) + track->extra * 4,
                    track->data[state->currentFrame].word, state->currentData, state->model->joints);
                func_001264E0(0);
            }
        }
        func_L01_0043E8D0(state);
    }
    state->mode = 2;
}
/* localdecomp:end func_L39_005AAE60 */
