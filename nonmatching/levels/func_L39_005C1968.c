/* Ported from rac2-decomp's func_002B6D80 (a twin of this function's code), names renamed from retail's
   relocations; 2 instruction(s) still differ under this file's flags. */
extern u8 D_00225660[];
typedef struct { int offset, size; } SoundEntry;
typedef struct { char pad[0x52fc]; int base; SoundEntry entries[1]; } SoundTable;
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
extern void func_003A2938(int, long);

void func_L39_005C1968(int index, int mode, int volume)
{
    StreamState *s = (StreamState *)D_00225660;
    SoundTable *d;
    long first, second;
    int offset;
    if (s->channel[0].handle) return;
    d = (SoundTable *)D_001F0A00;
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