#include "common.h"

typedef struct {
    u32 handle;
    s16 track;
    s16 volume;
    s16 flags;
    s16 state;
    u8 pad8[4];
    s16 crossfade;
    u8 padE[2];
    s32 poll_interval;
    s32 sample_rate;
} Channel_005C1CB8;
typedef struct {
    u8 pad0[0xBC];
    Channel_005C1CB8 channel[1];
} Stream_005C1CB8;
typedef struct {
    s32 offset;
    s32 size;
} SoundEntry_005C1CB8;
typedef struct {
    u8 pad0[0x7A04];
    s32 base;
    SoundEntry_005C1CB8 entries[1];
} SoundTable_005C1CB8;

/* localdecomp:start func_L39_005BFC70 */
extern Stream_005C1CB8 D_225660;
extern SoundTable_005C1CB8 D_1F0A00;
extern void func_0039D920(s32 a0, long a1);
extern s32 func_194768(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7,
                       s32 a8, s32 a9, void *a10, long a11);

s32 func_L39_005BFC70(s32 track, s32 index, s32 mode, s32 volume) {
    Stream_005C1CB8 *st = &D_225660;
    SoundTable_005C1CB8 *d;
    long first;
    s32 offset;

    if (st->channel[0].handle == 0) {
        d = &D_1F0A00;
        offset = d->entries[index].offset;
        if (offset) {
            st->channel[0].flags = mode;
            st->channel[0].handle = 0xFFFFFFFFU;
            st->channel[0].track = track;
            st->channel[0].poll_interval = 10;
            st->channel[0].sample_rate = 48000;
            st->channel[0].state = 1;
            st->channel[0].crossfade = 1;
            st->channel[0].volume = volume;
            first = offset + d->base;
            func_194768(first, 0, 0, 0, (s16)volume, 0, 1, 0, 0, 32,
                        func_0039D920, (u32)&st->channel[0]);
        } else {
            return 0;
        }
    } else {
        return 0;
    }
    return 1;
}
/* localdecomp:end func_L39_005BFC70 */
