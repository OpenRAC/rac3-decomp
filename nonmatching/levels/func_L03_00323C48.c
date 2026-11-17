/* NTSC-U draft (Claude wave K): C of func_L03_00323750, the NTSC-U twin of func_L03_00323C48, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 49 words differ on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (the file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division") (NTSC-U twin "func_L03_00323750", whose code is not the PAL one).
 * Worker's note: full decode of the 5-state switch (jump table D_L03_002BDA10: case0 -> 0x440, 1 -> 0xA0, 2 -> 0x1C8, 3 -> 0x21C, 4 -> 0x368; state 0 just sets 1), 49 aligned diffs of 283 with @ps2as (raw 175). Needs @ps2as (float literals lui/ori/mtc1 and macro stores in ...
 */
#include "common.h"

#include "vu0.h"

/* localdecomp:start func_L03_00323750 */
typedef struct {
    u8 pad0[0x35C];
    u8 *p35C;
    u8 pad360[0xE];
    s16 h36E;
} Hero_323750;

typedef struct {
    s32 w0;
    s32 w4;
    s32 w8;
    s32 wC;
    u8 pad10[0x10];
    f32 f20;
    f32 f24;
    f32 f28;
    f32 f2C;
    u8 pad30[4];
    f32 f34;
    s32 w38;
    s32 w3C;
    s32 w40;
    s32 w44;
    s32 w48;
} St_323750;

extern Hero_323750 D_001A4BE0;
__asm__(".extern D_001D545C, 16");
extern s32 D_001D545C;
extern u8 D_001BBC40[];
__asm__(".extern D_001D52FC, 16");
extern u8 *D_001D52FC;
__asm__(".extern D_L03_002D09F0, 16");
extern s32 D_L03_002D09F0;
__asm__(".extern D_L03_001DFA1C, 16");
extern u8 *D_L03_001DFA1C;
__asm__(".extern D_001A71C5, 16");
extern u8 D_001A71C5;
__asm__(".extern D_001427BB, 16");
extern u8 D_001427BB;
extern f32 D_001DCAA8_sda;
__asm__(".extern D_001DCAA8_sda, 4");
extern f32 D_001DCAAC_sda;
__asm__(".extern D_001DCAAC_sda, 4");
extern f32 D_001DCAB0_sda;
__asm__(".extern D_001DCAB0_sda, 4");
extern void func_L01_0044F2E8(s32, s32, s32, s32, s32, s32, s32);
extern void func_L03_00323BC0(void *);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_L01_0050DA68(void *, s32, f32);
extern void func_L01_00443648(s32, f32, s32, s32, f32, f32, s32, s32, s32);
extern s32 func_L01_0050DAC0(void);
extern s32 func_00388398(void *);
extern void func_L01_0050DB10(void);
extern void func_0038E5B8(s32, s32);
extern void func_L01_00402498(void *, void *);
extern f32 func_003BEBF8(f32 *, f32, f32);
extern void func_003BEC60(f32 *, void *, f32, f32, f32, f32);
extern void func_L01_004F12C0(void *, void *, s32, s32);
extern void func_L03_00323C98(void *);

void func_L03_00323750(u8 *o) {
    St_323750 *st = *(St_323750 **)(o + 0x68);
    u8 *t;
    u8 *q;
    vu0_v4 v;
    s32 r;

    if (st->w38 == 0) {
        if (D_001A4BE0.p35C != o) {
            return;
        }
        if (D_001A4BE0.h36E != 0) {
            return;
        }
        func_L01_0044F2E8(0, 0xC, 0x14D6, 1, 0, 0, 0);
        return;
    }
    switch (o[0x20]) {
    case 0:
        o[0x20] = 1;
        break;
    case 1:
        if (st->w8 < 0 || (D_001BBC40[st->w8 + (D_001D545C << 4)] & 0x80)) {
            if (st->w0 == -1 && st->w40 == 0 && st->w3C == 0 && st->w44 == 0) {
                return;
            }
            if (D_001A4BE0.p35C != o) {
                return;
            }
            if (D_001A4BE0.h36E != 0) {
                return;
            }
            func_L03_00323BC0(o);
            if ((*(s32 *)(D_001D52FC + 0x1A4) & 0x10) == 0) {
                return;
            }
            if (D_L03_002D09F0 != 0xC) {
                return;
            }
            func_0039FE80(0, 0, o);
            o[0x20] = 2;
            st->f28 = 0.0f;
            st->f2C = 0.0f;
            func_L01_0050DA68(o + 0x10, 0, *(f32 *)(o + 0xF8));
            st->w48 = 0xB4;
            func_L01_00443648((s32)o, 1.5f, (s32)(o + 0x10), 0x10000, 20.0f, 1.0f, 0, 1, 0);
        }
        break;
    case 2:
        r = func_L01_0050DAC0();
        if (r == 2) {
            st->f34 = 1.95f;
            o[0x20] = 3;
        } else if (r == 0) {
            o[0x20] = 4;
        } else if (func_00388398(&st->w48) != 0) {
            func_L01_0050DB10();
            o[0x20] = 1;
        }
        break;
    case 3:
        if (st->f34 == 0.0f) {
            if (st->w3C == 0 && st->w40 == 0) {
                t = D_L03_001DFA1C + (st->w0 << 8);
                if (st->w4 != -1 && (D_001BBC40[st->wC + (D_001D545C << 4)] & 0x80)) {
                    t = D_L03_001DFA1C + (st->w4 << 8);
                }
                v = *(vu0_v4 *)(t + 0x10);
                q = *(u8 **)(t + 0x68);
                v.z = v.z + 0.2f;
                func_L01_004F12C0(&v, t + 0xF0, 0, 1);
                D_001A71C5 = 1;
                t[0x20] = 4;
                *(s32 *)(q + 0x34) = 0;
                *(s32 *)(q + 0x28) = 0;
                *(s32 *)(q + 0x2C) = 0;
                *(f32 *)(q + 0x24) = 1.0f;
                *(f32 *)(q + 0x20) = 1.0f;
                func_0039FE80(1, 0, t);
                o[0x20] = 1;
                st->f34 = 1.95f;
                st->f20 = 0.0f;
                st->f24 = 0.0f;
                st->f28 = 0.0f;
                st->f2C = 0.0f;
            } else {
                D_001427BB = 0;
                func_0038E5B8(st->w40 != 0 ? 0x10 : 0x18, 1);
            }
        } else {
            func_L01_00402498(func_L03_00323C98, o);
            func_003BEBF8(&st->f34, 0.0f, 0.06666667f);
        }
        break;
    case 4:
        if (st->f34 < 1.95f) {
            func_L01_00402498(func_L03_00323C98, o);
            func_003BEBF8(&st->f34, 1.95f, 0.06666667f);
        } else if (st->f24 > 0.0f) {
            func_003BEC60(&st->f24, &st->f28, 0.0f, D_001DCAA8_sda * 0.00027777778f, D_001DCAAC_sda * 0.00027777778f, D_001DCAB0_sda * 0.016666668f);
        } else if (st->f20 > 0.0f) {
            func_003BEC60(&st->f20, &st->f2C, 0.0f, D_001DCAA8_sda * 0.00027777778f, D_001DCAAC_sda * 0.00027777778f, D_001DCAB0_sda * 0.016666668f);
        } else {
            o[0x20] = 1;
        }
        break;
    }
}
/* localdecomp:end func_L03_00323750 */
