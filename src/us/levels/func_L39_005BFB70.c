#include "common.h"

/* NTSC-U counterpart of func_L39_005C1BB8 (src/levels/shared/L39_005C14A0.c) */
extern u8 D_L39_002257E0[];
extern u8 D_L39_002257E0[];
extern int D_L39_001F0B80[];
extern int func_00194858(int, int, int, int, int, int, int, int, int, int,
                         void (*)(int, long), unsigned long);
extern u8 D_L39_002257E0[];
typedef struct { int offset, size; } SoundEntry;
typedef struct { char pad[0x7a04]; int base; SoundEntry entries[1]; } SoundTable;
typedef struct {
    unsigned int handle;
    short track, volume, flags, state, fade, unknown, crossfade, unknown2;
    int poll_interval, sample_rate;
    char tail[8];
} StreamChannel;
typedef struct { u8 pad[0x44]; StreamChannel channel[3]; } StreamState;
extern int D_L39_001F0B80[];
extern int func_00194858(int, int, int, int, int, int, int, int, int, int,
                         void (*)(int, long), unsigned long);

/* localdecomp:start func_L39_005BFB70 */
extern void func_0039D970(int, long);

/* from rac2-decomp's func_002B6D80 */
void func_L39_005BFB70(int index, int mode, int volume)
{
    StreamState *s = (StreamState *)D_L39_002257E0;
    SoundTable *d;
    long first, second;
    int offset;

    if (s->channel[0].state == 9) return;
    if (s->channel[0].handle == 0 || s->channel[0].handle == 0xffffffffU) return;
    d = (SoundTable *)D_L39_001F0B80;
    offset = d->entries[index + 1].offset;
    if (!offset) return;
    s->channel[0].track = index;
    s->channel[0].state = 9;
    s->channel[0].flags = mode;
    s->channel[0].poll_interval = 10;
    s->channel[0].sample_rate = 48000;
    s->channel[0].volume = volume;
    s->channel[0].crossfade = 0;
    first = offset + d->base;
    second = d->entries[index].offset + d->base;
    func_00194858(first, second, 0, 0, (short)volume, 0, 1, s->channel[0].handle, 0, 8,
                  func_0039D970, (unsigned int)&s->channel[0]);
}
/* localdecomp:end func_L39_005BFB70 */
