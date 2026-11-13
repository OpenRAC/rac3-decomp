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

INCLUDE_ASM("asm/levels", func_L39_005C14A0);

INCLUDE_ASM("asm/levels", func_L39_005C1700);

/* localdecomp:start func_L39_005C18C8 */
typedef struct {
    s32 handle;
    s16 track;
    s16 volume;
    s16 flags;
    s16 state;
    u8 padC[0x14];
    s32 f20;
    u8 pad24[4];
} Chan_005C18C8;
typedef struct {
    u8 pad0[0x6C];
    Chan_005C18C8 ch[2];
} State_005C18C8;
extern u8 D_00225660[];
extern void func_0038CC88(void *, void *, s32);
extern void func_0038CB78(void *, s32, s32);
extern void func_194888(s32);

s32 func_L39_005C18C8(void) {
    State_005C18C8 *s = (State_005C18C8 *)D_00225660;
    if (s->ch[0].state != 0) {
        return 0;
    }
    if (s->ch[1].state != 3) {
        return 0;
    }
    if (s->ch[1].handle == 0) {
        return 0;
    }
    func_0038CC88(&s->ch[0], &s->ch[1], 0x28);
    func_0038CB78(&s->ch[1], 0, 0x28);
    s->ch[1].track = -1;
    s->ch[1].f20 = -1;
    func_194888(s->ch[0].handle);
    s->ch[0].state = 4;
    return 1;
}
/* localdecomp:end func_L39_005C18C8 */

/* localdecomp:start func_L39_005C1968 */
extern u8 D_00225660[];
typedef struct { int offset, size; } SoundEntry_005C1968;
typedef struct { char pad[0x7a04]; int base; SoundEntry_005C1968 entries[1]; } SoundTable_005C1968;
typedef struct {
    unsigned int handle;
    short track, volume, flags, state, fade, unknown, crossfade, unknown2;
    int poll_interval, sample_rate;
    char tail[8];
} StreamChannel_005C1968;
typedef struct { u8 pad[0x44]; StreamChannel_005C1968 channel[3]; } StreamState_005C1968;
extern int D_001F0A00[];
extern int func_00194768(int, int, int, int, int, int, int, int, int, int,
                         void (*)(int, long), unsigned long);
extern void func_001325E8(int, void (*)(int, long), unsigned long);
extern void func_001336D0(void (*)(s32));
extern void func_003A2938(int, long);

/* from rac2-decomp's func_002B6D80 */
void func_L39_005C1968(int index, int mode, int volume)
{
    StreamState_005C1968 *s = (StreamState_005C1968 *)D_00225660;
    SoundTable_005C1968 *d;
    long first, second;
    int offset;
    if (s->channel[0].handle) return;
    d = (SoundTable_005C1968 *)D_001F0A00;
    offset = d->entries[index].offset;
    if (!offset) return;
    s->channel[0].handle = 0xffffffffU;
    s->channel[0].state = 1;
    s->channel[0].track = index;
    s->channel[0].flags = mode;
    s->channel[0].poll_interval = 10;
    s->channel[0].sample_rate = 48000;
    s->channel[0].volume = volume;
    s->channel[0].crossfade = 0;
    first = offset + d->base;
    second = d->entries[index + 1].offset + d->base;
    func_00194768(first, second, 0, 0, (short)volume, 0, 1, 0, 0, 1,
                  func_003A2938, (unsigned int)&s->channel[0]);
}
/* localdecomp:end func_L39_005C1968 */

/* localdecomp:start func_L39_005C1A60 */
extern s32 D_L39_00243478;
extern s32 D_L39_0024347C;
extern s16 D_L39_002256AE[];
extern s32 func_L39_005B43C8(s32 a0, s32 a1);
extern void func_L01_0045F1E8(s32 a0, s32 a1);
extern void func_L39_005C1AC0(s32 a0, s32 a1, s32 a2);

void func_L39_005C1A60(s32 a0, s32 a1) {
    s32 x;
    D_L39_00243478 = a0;
    D_L39_0024347C = a1 - a0 + 1;
    x = func_L39_005B43C8(a0, a1) * 2;
    if (D_L39_002256AE[0] == 4) {
        func_L01_0045F1E8(x, -1);
    } else {
        func_L39_005C1AC0(x, 1, 1024);
    }
}
/* localdecomp:end func_L39_005C1A60 */

/* localdecomp:start func_L39_005C1AC0 */
extern u8 D_00225660[];
typedef struct { int offset, size; } SoundEntry;
typedef struct { char pad[0x7a04]; int base; SoundEntry entries[1]; } SoundTable;
typedef struct {
    unsigned int handle;
    short track, volume, flags, state, fade, unknown, crossfade, unknown2;
    int poll_interval, sample_rate;
    char tail[8];
} StreamChannel;
typedef struct { u8 pad[0x44]; StreamChannel channel[3]; } StreamState;
extern int D_001F0A00[];
extern int func_00194768(int, int, int, int, int, int, int, int, int, int,
                         void (*)(int, long), unsigned long);
extern void func_001325E8(int, void (*)(int, long), unsigned long);
extern void func_001336D0(void (*)(s32));
extern void func_003A2A50(int, long);

/* from rac2-decomp's func_002B6E78 */
void func_L39_005C1AC0(int index, int mode, int volume)
{
    StreamState *s;
    SoundTable *d;
    long first, second;
    int offset;
    if (index < 0) return;
    s = (StreamState *)D_00225660;
    if (s->channel[0].handle) return;
    d = (SoundTable *)D_001F0A00;
    offset = d->entries[index].offset;
    if (!offset) return;
    s->channel[0].handle = 0xffffffffU;
    s->channel[0].state = 1;
    s->channel[0].poll_interval = 10;
    s->channel[0].sample_rate = 48000;
    s->channel[0].track = index;
    s->channel[0].flags = mode;
    s->channel[0].volume = volume;
    s->channel[0].crossfade = 0;
    first = offset + d->base;
    second = d->entries[index + 1].offset + d->base;
    func_00194768(first, second, 0, 0, (short)volume, 0, 1, 0, 0, 0,
                  func_003A2A50, (unsigned int)&s->channel[0]);
}
/* localdecomp:end func_L39_005C1AC0 */

/* localdecomp:start func_L39_005C1BB8 */
extern void func_003A29F8(int, long);

/* from rac2-decomp's func_002B6D80 */
void func_L39_005C1BB8(int index, int mode, int volume)
{
    StreamState *s = (StreamState *)D_00225660;
    SoundTable *d;
    long first, second;
    int offset;

    if (s->channel[0].state == 9) return;
    if (s->channel[0].handle == 0 || s->channel[0].handle == 0xffffffffU) return;
    d = (SoundTable *)D_001F0A00;
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
    func_00194768(first, second, 0, 0, (short)volume, 0, 1, s->channel[0].handle, 0, 8,
                  func_003A29F8, (unsigned int)&s->channel[0]);
}
/* localdecomp:end func_L39_005C1BB8 */

/* localdecomp:start func_L39_005C1CB8 */
extern Stream_005C1CB8 D_225660;
extern SoundTable_005C1CB8 D_1F0A00;
extern void func_003A29A8(s32 a0, long a1);
extern s32 func_194768(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7,
                       s32 a8, s32 a9, void *a10, long a11);

s32 func_L39_005C1CB8(s32 track, s32 index, s32 mode, s32 volume) {
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
                        func_003A29A8, (u32)&st->channel[0]);
        } else {
            return 0;
        }
    } else {
        return 0;
    }
    return 1;
}
/* localdecomp:end func_L39_005C1CB8 */
