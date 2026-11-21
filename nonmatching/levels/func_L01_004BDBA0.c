/* PAL near miss (sonnet-b30-j1, round 19): 15 words differ at level 01 with `--as ps2as` (S mode; the default assembler gives 187: the function needs
 * `@ps2as`, because retail's delay-slot copies of the macro loads D_001D52FC / D_001D545C / D_L01_001E0F90 are $gp loads that only Ps2EeAs writes,
 * so it also needs a cut: a file of its own at 0x4BDBA0 (8-aligned; it is 868 bytes, so the next function starts 4 bytes after its end).
 * The first 0x2B0 bytes match exactly. What differs: (1) the two address sums of the tail: retail has `addu $v0, $a0, $a2` (product first) for the
 * `lbu 0x144($v0)` check and `addu $v1, $a2, $a0` (base first) for the `lw $s0, 0x140($v1)` id read, mine the opposite
 * (a pointer variable `gp` for the first part gave retail's forms there: `gp[cur * 20 + 0x152]`; for the tail every spelling I tried
 * (pointer variable, cast index, struct chunks, `eb` first) either keeps the wrong order or merges the two sums into one);
 * (2) $s1 / $s2 swapped in the last block (retail: s1 = &D_001425C0[id], s2 = &D_L01_002C5600; mine the reverse) and the `beql`/slot of the
 * `info->b0 != 0` test (about 8 words).
 * Check: python tools/check.py nonmatching/levels/func_L01_004BDBA0.c func_L01_004BDBA0 --as ps2as --no-context
 */
#include "common.h"
/* localdecomp:start func_L01_004BDBA0 */
typedef struct {
    s32 id;
    s32 val;
    s32 idx;
    s32 pad;
} Item_004BDBA0;
typedef struct {
    s32 id;
    u8 b4;
    u8 p5[13];
    u8 b12;
    u8 b13;
} Ent_004BDBA0;
typedef struct {
    u8 p0[0x28];
    void *f28;
    u8 p2C[0x24];
    s32 f50;
    u8 p54[8];
    s32 f5C;
    u8 p60[0x18];
    s32 f78;
    s32 f7C;
    s32 cur;
    s32 state;
    u8 b88;
    u8 p89[3];
    s32 f8C;
    u8 p90[0xB0];
    Item_004BDBA0 items[96];
} G_004BDBA0;
typedef struct { u8 p0[0x140]; Ent_004BDBA0 e[1]; } GE_004BDBA0;
typedef struct { u8 p0[0x758]; u8 b758; u8 p759[3]; s32 f75C; s32 f760; } GT_004BDBA0;
typedef struct { u8 b0; u8 p1[0x37]; u16 h38; u8 p3A[0x50]; u16 h8A; u8 p8C[0x64]; } Info_004BDBA0;
typedef struct { u8 p0[0x1C4]; s32 w1C4; } P_004BDBA0;
extern G_004BDBA0 D_L01_002446C0_004BDBA0;
extern P_004BDBA0 *D_001D52FC_004BDBA0;
extern s32 D_L01_001E0F90_004BDBA0;
extern s32 D_001D545C_004BDBA0;
extern u8 D_001425C0_004BDBA0[];
extern Info_004BDBA0 D_L01_002C5600_004BDBA0[];
extern u8 D_00142CA0_004BDBA0[];
extern s32 D_001427F0_004BDBA0[];
extern s16 D_001426A0_004BDBA0[];
extern u8 D_L01_001DABC8_004BDBA0;
extern s32 D_L01_001DABCC_004BDBA0;
extern s32 D_L01_001DABD0_004BDBA0;
extern s32 D_L01_001DABD8_004BDBA0;
extern s32 *func_003B9BD0(s32);
extern s32 func_003B9C58(s32 *);
extern void func_003BA4F8(void *, s32);
extern void func_003935B0(s32, s32);
extern s32 func_L01_004BB0F0_004BDBA0(s32);
extern void func_L01_004C4E60(void);
extern s32 func_L01_005147A8(s32);
extern void func_L01_00425978(s32);
extern void func_003A2750(s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_004BD170(void);
extern void func_L01_0047B798(s32, s32);
extern void func_L01_0047B820(s32, s32);
extern void func_L01_0047B9B8(s32);
__asm__(".extern D_001D52FC_004BDBA0, 16");
__asm__(".extern D_L01_001E0F90_004BDBA0, 16");
__asm__(".extern D_001D545C_004BDBA0, 16");
__asm__(".extern D_L01_001DABC8_004BDBA0, 1");
__asm__(".extern D_L01_001DABCC_004BDBA0, 4");
__asm__(".extern D_L01_001DABD0_004BDBA0, 4");
__asm__(".extern D_L01_001DABD8_004BDBA0, 4");

void func_L01_004BDBA0(void) {
    s32 changed;
    s32 s0;
    s32 v;
    s32 *p;
    u8 *gp;
    u8 *eb;
    s32 s;
    s32 id;
    u8 *s1;

    if (D_L01_002446C0_004BDBA0.state == 0) {
        changed = 0;
        s0 = func_003B9C58(func_003B9BD0(0));
        func_003BA4F8(func_003B9BD0(0), D_001D52FC_004BDBA0->w1C4);
        v = func_003B9C58(func_003B9BD0(0));
        if (s0 != v) {
            D_L01_002446C0_004BDBA0.cur = v;
            changed = 1;
        }
        if (changed) {
            if (D_L01_002446C0_004BDBA0.b88 != 0) {
                D_L01_002446C0_004BDBA0.f8C = (D_L01_002446C0_004BDBA0.f50 != 2) ? 1 : 3;
            }
            if (D_L01_002446C0_004BDBA0.f78 != -1 && D_L01_002446C0_004BDBA0.f50 == 0) {
                func_003935B0(D_L01_002446C0_004BDBA0.f78, 0);
            }
            D_L01_002446C0_004BDBA0.f78 = -1;
        }
        if (D_001D52FC_004BDBA0->w1C4 & 0x40) {
            if (!(D_L01_001E0F90_004BDBA0 & 0x40)) {
                if (func_L01_004BB0F0_004BDBA0(D_L01_002446C0_004BDBA0.items[D_L01_002446C0_004BDBA0.cur].idx)) {
                    D_L01_001DABC8_004BDBA0 = 1;
                    D_L01_001DABD0_004BDBA0 = D_L01_002446C0_004BDBA0.items[D_L01_002446C0_004BDBA0.cur].idx;
                    func_L01_004C4E60();
                    if (D_L01_001DABD0_004BDBA0 == -1) {
                        func_L01_005147A8(D_L01_001DABCC_004BDBA0);
                        func_L01_00425978(D_001426A0_004BDBA0[0]);
                    } else {
                        D_L01_001DABCC_004BDBA0 = D_L01_002446C0_004BDBA0.items[D_L01_002446C0_004BDBA0.cur].idx;
                        func_L01_005147A8(D_L01_002446C0_004BDBA0.items[D_L01_002446C0_004BDBA0.cur].idx);
                        func_L01_00425978(D_001426A0_004BDBA0[0]);
                    }
                    func_003A2750(1);
                } else {
                    D_L01_002446C0_004BDBA0.state = 1;
                }
                if (D_L01_002446C0_004BDBA0.f50 == 3 || D_L01_002446C0_004BDBA0.f50 == 5) {
                    func_003A52A0(0, 0x11, D_L01_002446C0_004BDBA0.f28);
                }
            }
        }
        if (D_001D545C_004BDBA0 == 3) {
            if (D_L01_002446C0_004BDBA0.f5C == 0) {
                gp = (u8 *)&D_L01_002446C0_004BDBA0;
                if (gp[D_L01_002446C0_004BDBA0.cur * 20 + 0x152] == 0) {
                    if (gp[D_L01_002446C0_004BDBA0.cur * 20 + 0x153] == 0) {
                        p = (s32 *)((u8 *)&D_L01_002446C0_004BDBA0 + 0x140 + D_L01_002446C0_004BDBA0.cur * 20);
                        if (*p != 0x67) {
                            if (*p != 0x16) {
                                if (D_L01_002446C0_004BDBA0.f50 == 0) {
                                    if (D_001D52FC_004BDBA0->w1C4 & 0x80) {
                                        D_L01_001DABD8_004BDBA0 = 0;
                                        ((GT_004BDBA0 *)&D_L01_002446C0_004BDBA0)->b758 = 1;
                                        ((GT_004BDBA0 *)&D_L01_002446C0_004BDBA0)->f760 = *p;
                                        ((GT_004BDBA0 *)&D_L01_002446C0_004BDBA0)->f75C = *p;
                                        func_L01_004BD170();
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (D_001D52FC_004BDBA0->w1C4 & 0x10) {
            func_L01_004BD170();
        }
    }
    if (((u8 *)&D_L01_002446C0_004BDBA0)[D_L01_002446C0_004BDBA0.cur * 20 + 0x144] == 1) {
        eb = (u8 *)&D_L01_002446C0_004BDBA0 + D_L01_002446C0_004BDBA0.cur * 20;
        id = *(s32 *)(eb + 0x140);
        s1 = &D_001425C0_004BDBA0[id];
        if (D_L01_002C5600_004BDBA0[*s1].b0 != 0 && D_00142CA0_004BDBA0[id] != 0) {
            func_L01_0047B798(D_L01_002C5600_004BDBA0[*s1].h38, 0);
            func_L01_0047B820(D_001427F0_004BDBA0[id], D_L01_002C5600_004BDBA0[*s1].h8A);
            func_L01_0047B9B8(id);
        }
    }
}
/* localdecomp:end func_L01_004BDBA0 */
