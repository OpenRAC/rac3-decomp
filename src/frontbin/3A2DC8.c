#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

typedef struct {
    u8 pad0[0x100];
    f32 cur[16];
    f32 prev[16];
    u8 pad180[0xE];
    s16 head;
    s32 cnt;
    u8 pad194[0xC];
    s32 x1A0;
    s32 x1A4;
    s32 x1A8;
    s32 x1AC;
    s32 x1B0;
    s32 x1B4;
    s32 x1B8;
    s32 x1BC;
    s32 x1C0;
    s32 x1C4;
    s32 x1C8;
    s32 x1CC;
    s32 x1D0;
    s32 x1D4;
    s32 x1D8;
    u8 pad1DC[4];
    s32 hist[30];
    f32 ang[30];
    f32 mag[30];
    s32 x348;
    s32 idx;
    s32 count;
    s32 btn[7];
    s32 btn2[7];
    f32 an[7][16];
    u8 pad54C;
    u8 x54D;
    u8 x54E;
    u8 x54F;
    u8 pad550[0x18];
    s32 delay;
} Pad_39DB38;
extern s32 D_001D5B94;
extern u8 D_001D5477[];
extern f32 func_0038CED8(f32 *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
#define SWAP_LR(x) \
    if ((x) & 0x8000) { (x) = ((x) & ~0x8000) | 0x2000; } \
    else if ((x) & 0x2000) { (x) = ((x) & ~0x2000) | 0x8000; }
INCLUDE_ASM("asm/nonmatchings/text", func_003A2DC8);

LINKER_REMNANT("asm/remnants", func_003A3738);

/* localdecomp:start func_003A3740 */
typedef struct P_39E4B0 {
    u8 pad[0x188]; u8 f188; u8 f189; u8 pad18A[0x198 - 0x18A];
    s32 f198; s32 f19C; s32 f1A0; u8 pad1A4[8]; s32 f1AC; s32 f1B0; u8 pad1B4[8]; s32 f1BC;
    u8 pad1C0[0x1DC - 0x1C0]; s32 f1DC; u8 pad1E0[0x348 - 0x1E0]; s32 f348;
    u8 pad34C[0x54C - 0x34C]; u8 f54C; u8 pad54D[3]; u8 f550; u8 f551[6]; u8 f557; u8 f558; u8 pad559[3];
    s32 f55C; s32 f560; s32 f564; u8 pad568[4];
    void (*f56C)(struct P_39E4B0 *, u8 *, s32, s32); s32 f570; u8 f574; u8 f575;
} P_39E4B0;
extern P_39E4B0 *D_001D52FC_003A3740;
extern u8 D_001D4CF4;
extern u8 D_001D6DF0[8];
extern void func_003A2DC8(Pad_39DB38 *, u8 *, s32);
extern s32 func_12F470(s32, s32);
extern s32 func_12F728(s32, s32, s32, s32);
extern s32 func_12F860(s32, s32, s32, s32);
extern s32 func_12F5A8(s32, s32);
extern s32 func_12F608(s32, s32, s32, s32);
extern s32 func_12F9E0(s32, s32, u8 *);
extern s32 func_12FC18(s32, s32);
extern s32 func_12FC78(s32, s32);
extern s32 func_12EBB8(s32);
extern s32 func_12F3F8(s32, s32, u8 *);
extern s32 func_12F918(s32, s32, u8 *);
__asm__(".extern D_001D6DF0, 8");
void func_003A3740(P_39E4B0 *o) {
    s32 port, slot, t, r;
    o->f1A0 = 0;
    t = o->f1B0;
    port = o->f54C;
    slot = o->f557;
    o->f1B0 = 0;
    o->f1AC = o->f348;
    o->f1BC = t;
    r = func_12F470(port, slot);
    o->f19C = r;
    if (r == 0) o->f198 = 0;
    if (o == D_001D52FC_003A3740) D_001D4CF4 = 0;
    switch (o->f198) {
    case 0:
        if (o == D_001D52FC_003A3740) D_001D4CF4 = 1;
        if (o->f19C != 6 && o->f19C != 2) {
            if (o->f56C) o->f56C(o, D_001D6DF0, 0x20, o->f570);
            func_003A2DC8((Pad_39DB38 *)o, D_001D6DF0, 0x20);
            o->f558 = 0;
            break;
        }
        r = func_12F728(port, slot, 1, 0);
        o->f560 = r;
        if (r == 0) break;
        r = func_12F728(port, slot, 2, 0);
        o->f564 = r;
        if (r > 0) o->f560 = r;
        o->f55C = 0;
        switch (o->f560) {
        case 4: o->f198 = 0x28; break;
        case 7: o->f198 = 0x46; break;
        default: o->f198 = 0x63; break;
        }
        break;
    case 40:
        if (func_12F728(port, slot, 2, 0) == 0) {
            o->f198 = 0x63;
            break;
        }
        o->f198++;
    case 41:
        if (func_12F860(port, slot, 1, 3) != 1) break;
        o->f198++;
        break;
    case 42:
        if (func_12F5A8(port, slot) == 1) o->f198--;
        if (func_12F5A8(port, slot) == 0) o->f198 = 0;
        break;
    case 70: {
        s32 i;
        if (func_12F608(port, slot, -1, 0) == 0) o->f198 = 0x63;
        o->f551[1] = 1;
        o->f551[0] = 0;
        for (i = 2; i < 6; i++) o->f551[i] = 0xFF;
        if (func_12F9E0(port, slot, o->f551) == 0) break;
        o->f198++;
        break;
    }
    case 72:
        if (func_12FC18(port, slot) == 0) {
            o->f55C = 0;
            o->f198 = 0x63;
        } else {
            o->f198 = 0x4C;
        }
        break;
    case 76:
        if (func_12FC78(port, slot) != 0) {
            o->f198++;
            break;
        }
        o->f198 = 0x48;
        break;
    case 71:
    case 77:
        if (func_12F5A8(port, slot) == 1) o->f198--;
        if (func_12F5A8(port, slot) != 0) break;
        o->f198++;
        break;
    case 78:
        o->f198 = 0x63;
        break;
    default:
        if (o->f558 == 0) o->f550 = func_12EBB8(o->f54C);
        o->f558 = 1;
        if (o->f19C == 6 || o->f19C == 2) {
            u8 *buf = &o->f574;
            s32 v;
            if (func_12F3F8(port, slot, buf) == 0) break;
            if (o->f574 == 0) {
                s32 n = (o->f575 & 0xF) * 2 + 2;
                if (n >= 21) n = 20;
                if (o->f56C) o->f56C(o, buf, n, o->f570);
                func_003A2DC8((Pad_39DB38 *)o, buf, n);
                o->f1DC = o->f575;
            }
            v = o->f1DC;
            if (v > 0 && o->f55C != 0 && v != o->f55C) {
                o->f55C = 0;
                o->f198 = 0;
            } else if (v > 0) {
                o->f55C = v;
            }
            func_12F918(port, slot, &o->f188);
            o->f188 = 0;
            o->f189 = 0;
        }
        break;
    }
}
/* localdecomp:end func_003A3740 */
