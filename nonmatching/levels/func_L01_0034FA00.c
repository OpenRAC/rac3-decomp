/* PAL near miss (Codex wave 8): near miss: 115 words differ with the file's flags.
 * Worker's note: Best 115 diff / 138 retail words: func_L01_0034FA00.c03.log (c04/c06 same residual). Compiler strength-reduces loop to separate pointers/countdown; retail keeps index and byte offset. Colour-sum association and allocation differ. Six selector branches decoded ...
 */
#include "common.h"
/* localdecomp:start func_L01_0034FA00 */
#include "vu0.h"
typedef struct {
    u8 *owner;
    s32 initialized;
    f32 value8;
    s32 valueC;
    s16 alpha[16];
    s16 interval[16];
    s32 color[16];
    f32 phase[16];
    f32 size[16];
} State_0034FA00;
extern State_0034FA00 D_L01_001E2EC0;
/* Retail compares the random selector with 1, then 0, 2 and 3; all other values use the base colour. */
void func_L01_0034FA00(u8 *obj) {
    extern s32 func_00382468(s32);
    extern f32 func_0038DB48(f32);
    extern f32 func_0038D098(f32);
    State_0034FA00 *s=&D_L01_001E2EC0;
    s32 i;
    s32 off=4;
    s32 *color;
    s16 *alpha;
    s16 *interval;
    s32 value;
    s32 r,g;
    f32 t;
    if (s->initialized==1) return;
    s->owner=obj;
    s->initialized=1;
    color=&s->color[1];
    alpha=&s->alpha[1];
    i=1;
    do {
        value=func_00382468(63)+1;
        switch (func_00382468(6)) {
        case 0: r=value+0x202080; *color=r-(value<<16); break;
        case 1: *color=(value<<8)+(value+0x202080); break;
        case 2: *color=(func_00382468(value)<<8)+(value+0x202080); break;
        case 3:
            r=func_00382468(value);
            g=func_00382468(value);
            *color=(r<<16)+(0x202080+(g<<8))+value;
            break;
        default: *color=0x202080; break;
        }
        interval=s->interval;
        *(s16 *)((i<<1)+(s32)interval)=func_00382468(30)/10+1;
        i++;
        *(f32 *)((s32)s+off+0x90)=func_003824E0(-0.95f,2.4f);
        t=fabs_asm(func_0038D098(func_0038DB48(*(f32 *)((s32)s+off+0x90)+1.0f)));
        *(f32 *)((s32)s+off+0xD0)=t*t*t*1.4f;
        *alpha=32;
        off+=4;
        color++;
        alpha++;
    } while (i<14);
    s=(State_0034FA00 *)((u8 *)interval-0x30);
    s->alpha[0]=127;
    s->phase[0]=-1.0f;
    s->size[0]=2.0f;
    s->color[0]=0x808080;
    s->interval[0]=0;
}
/* localdecomp:end func_L01_0034FA00 */
