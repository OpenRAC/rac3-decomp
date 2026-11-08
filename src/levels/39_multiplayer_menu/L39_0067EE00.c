#include "common.h"

typedef struct S_0067EE40 {
    s32 f00;
    u8 pad04[0x08];
    u8 f0C;
    u8 pad0D[0x03];
    s32 f10;
    u8 pad14[0x4C];
    void *f60;
} S_0067EE40;
typedef struct SrcS_0067EE40 {
    s32 f00;
    u8 pad04[0x34];
    f32 f38;
    f32 f3C;
    f32 f40;
    f32 f44;
} SrcS_0067EE40;

INCLUDE_ASM("asm/levels", func_L39_0067EE00);

/* localdecomp:start func_L39_0067EE40 */
extern u8 D_L39_0047B5D0[];
extern void func_00120D28(s32, s32, s32);


S_0067EE40 *func_L39_0067EE40(S_0067EE40 *p, SrcS_0067EE40 *q) {
    p->f60 = D_L39_0047B5D0;
    p->f00 = q->f00;
    func_00120D28((s32)((u8 *)p + 0x14), (s32)((u8 *)q + 4), 0x33);
    *(u8 *)((u8 *)p + 0x47) = 0;
    *(f32 *)((u8 *)p + 0x50) = q->f38;
    *(f32 *)((u8 *)p + 0x54) = q->f3C;
    *(f32 *)((u8 *)p + 0x58) = q->f40;
    *(f32 *)((u8 *)p + 0x5C) = q->f44;
    *(s32 *)((u8 *)p + 0x48) = 0;
    p->f10 = 0;
    p->f0C = 0;
    return p;
}
/* localdecomp:end func_L39_0067EE40 */

/* localdecomp:start func_L39_0067EEC8 */
extern s32 func_L01_004D3BD0();
extern u8 D_L39_0047B5D0[];

/* from rac4-decomp's func_004EE6E8, renamed, constants adapted */
void func_L39_0067EEC8(u8 *p, s32 f) {
    *(void **)(p + 96) = D_L39_0047B5D0;
    if (f & 1) func_L01_004D3BD0(p);
}
/* localdecomp:end func_L39_0067EEC8 */
