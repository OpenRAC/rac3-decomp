/* PAL near miss (Codex wave 8): near miss: 87 words differ with the file's flags.
 * Worker's note: 87/113 differing words; w428/func_003A19D0.try3.log; retained typed slot draft; id/object saved registers exchanged, table/state address forms and init/callback-argument scheduling differ; nested guards give identical residual (try6)
 */
#include "common.h"
/* localdecomp:start func_003A19D0 */
#include "vu0.h"
typedef struct {
    u32 handle;
    s16 id, volume, flags, state;
    u8 padC[4];
    s16 crossfade;
    u8 pad12[2];
    s32 interval, rate, object, index, distance;
} Stream_003A19D0;
typedef struct { u8 pad[0x1A]; u16 field; } State_003A19D0;
typedef struct {
    u32 handle;
    State_003A19D0 *state;
    u16 id;
    s16 track, volume, flags;
    u8 mode;
    u8 pad11[3];
    s32 unused;
    u8 pad18[4];
    s32 object;
    vu0_v4 pos, velocity;
    s32 zero;
    u8 pad44[0x14];
    s32 kind;
    u8 pad5C[0x24];
} Slot_003A19D0;
typedef struct { u8 pad[0xC0]; Slot_003A19D0 slots[1]; } Table_003A19D0;
extern Table_003A19D0 D_001A30B0_003A19D0;
extern State_003A19D0 D_001D6DC0 __attribute__((section(".sdata")));
__asm__(".extern D_001D6DC0, 8");
void func_003A19D0(s32 id, s32 flags, s32 object, s32 *channel, s32 volume) {
    extern void func_003A1770(s32, s32 *, s32 *);
    extern void func_003A1750(s32, s32 *);
    extern s32 func_003A5380(s32);
    extern void func_003A2CB8(s32, long);
    extern int func_0013CB20(int, int, int, int, int, int, int, int, int, int, void (*)(int, long), unsigned long);
    s32 first, second, mode;
    s32 index, kind;
    Slot_003A19D0 *p;
    Stream_003A19D0 *s=(Stream_003A19D0 *)channel;
    if(s->handle) return;
    func_003A1770(id,&first,&second);
    func_003A1750(id,&mode);
    if(!first) return;
    index=func_003A5380(object);
    if(index==-1) return;
    s->interval=10;
    s->handle=0xFFFFFFFF;
    s->rate=48000;
    s->state=1;
    s->distance=600;
    s->id=id;
    s->flags=flags;
    s->volume=volume;
    s->crossfade=0;
    s->object=object;
    s->index=index;
    p=&D_001A30B0_003A19D0.slots[index];
    p->track=-1;
    p->id=D_001D6DC0.field;
    p->volume=volume;
    p->state=&D_001D6DC0;
    p->object=object;
    p->zero=0;
    qzero(&p->velocity);
    kind=0;
    if(object) {
        *(vu0_q *)&p->pos=*(vu0_q *)((u8 *)object+0x10);
        p->pos.z+=1.0f;
    } else {
        qzero(&p->pos);
        kind=0x11;
    }
    p=&D_001A30B0_003A19D0.slots[index];
    p->handle=0xFFFFFFFF;
    p->kind=kind;
    p->mode=8;
    p->flags=0;
    p->unused=0;
    func_0013CB20(first,second,0,0,s->volume,0,mode,0,0,1,func_003A2CB8,(u32)channel);
}
/* localdecomp:end func_003A19D0 */
