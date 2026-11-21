#include "common.h"
#include "vu0.h"

typedef struct {
    u8 p0[0x30];
    u8 v30[0x0E];
    u8 b3E;
    u8 p3F[0x5E - 0x3F];
    u8 b5E;
    u8 b5F;
    u8 p60[0x160 - 0x60];
    u8 v160[0x304 - 0x160];
    s32 i304;
    f32 f308;
} S_Vars3A1638;
typedef struct {
    u8 p0[0x20]; u8 state;
    u8 p21[0x68 - 0x21]; S_Vars3A1638 *vars;
} S_Moby3A1638;
typedef struct {
    u8 pad0[16];
    u8 pos[33];
    u8 b49;
    u8 pad32[61];
    u8 b111;
    u8 pad70[38];
    u16 h150;
} Moby_3A1DD8;

/* localdecomp:start func_L08_003A16C8 */
extern void func_L08_003A16C8(s32);
__asm__(".extern D_L05_001DD7E0, 8");
extern u8 D_L05_001DD7E0[8];
__asm__(".extern D_L05_001DD7F0, 4");
extern f32 D_L05_001DD7F0;
__asm__(".extern D_L05_001DD7D0, 4");
extern s32 D_L05_001DD7D0;
__asm__(".extern D_L05_001DD7D8, 4");
extern f32 D_L05_001DD7D8;
__asm__(".extern D_L05_001DD7D4, 4");
extern f32 D_L05_001DD7D4;
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038D028(void *, void *, void *);
extern void func_003C5458(void *, s32, f32, f32);
__asm__(".extern D_L08_001DE228, 8");
extern s32 D_L08_001DE228[2];
__asm__(".extern D_L08_001DE200, 8");
extern u8 D_L08_001DE200[8];
__asm__(".extern D_L08_001DE220, 8");
extern s32 D_L08_001DE220[2];
__asm__(".extern D_L08_001DE1F0, 8");
extern f32 D_L08_001DE1F0[2];
__asm__(".extern D_L08_001DE1E8, 8");
extern f32 D_L08_001DE1E8[2];
extern void func_003C2F58(u8 *a0, s32 a1, u8 *a2);

void func_L08_003A16C8(s32 a0)
{
    s32 i;
    vu0_v4 p;
    u8 m[0x40];
    vu0_v4 d;
    for (i = 0; i < 2; i++) {
        func_003C2F58((u8 *)a0, D_L08_001DE228[i], (u8 *)&p);
        func_003C2EC0((void *)a0, D_L08_001DE228[i], m);
        func_0038D028(&d, D_L08_001DE200 + i * 0x10, m);
        vec_add_ab(&p, &p, &d);
        func_003C5458(&p, D_L08_001DE220[i], D_L08_001DE1F0[i], D_L08_001DE1E8[i]);
    }
}
/* localdecomp:end func_L08_003A16C8 */
