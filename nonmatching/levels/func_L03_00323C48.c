/* PAL draft (2026-11-21, Promises): written from level 3's assembly. 4 words differ at level 03
 * with its file's line once that has @ps2as (added with func_L03_00324190's match; 209 diff
 * without). Left: retail puts `li $v1, -1` before the lui/lw of D_L03_001DF99C, ours after, and
 * the register of the beq that follows. About 15 wordings tried. */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L03_00323C48 */
typedef struct {
    u8 pad0[0x35C];
    u8 *p35C;
    u8 pad360[0xE];
    s16 h36E;
} Hero_00323C48;

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
} St_00323C48;

extern Hero_00323C48 D_001A4BE0;
extern s32 D_001D545C;
extern u8 D_001BBC40[];
extern u8 *D_001D52FC;
extern s32 D_L03_002D09B0 __attribute__((section(".data")));
extern u8 *D_L03_001DF99C __attribute__((section(".data")));
extern u8 D_001A71C5 __attribute__((section(".data")));
extern u8 D_001427BB __attribute__((section(".data")));
extern f32 D_L03_001DCA68;
__asm__(".extern D_L03_001DCA68, 4");
extern f32 D_L03_001DCA6C;
__asm__(".extern D_L03_001DCA6C, 4");
extern f32 D_L03_001DCA70;
__asm__(".extern D_L03_001DCA70, 4");
extern void func_L01_00452560(s32, s32, s32, s32, s32, s32, s32);
extern void func_L03_003240B8(u8 *);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00511A40(void *, s32, f32);
extern void func_L01_00446780(s32, f32, s32, s32, f32, f32, s32, s32, s32);
extern s32 func_L01_00511A98(void);
extern s32 func_0038CAD0(void *);
extern void func_L01_00511AE8(void);
extern void func_00392DF0(s32, s32);
extern void func_L01_00404808(void *, void *);
extern f32 func_003C4138(f32 *, f32, f32);
extern void func_003C41A0(f32 *, void *, f32, f32, f32, f32);
extern void func_L01_004F50C8(void *, void *, s32, s32);
extern void func_L03_00324190(void *);

void func_L03_00323C48(u8 *o) {
    St_00323C48 *st = *(St_00323C48 **)(o + 0x68);
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
        func_L01_00452560(0, 0xC, 0x14D6, 1, 0, 0, 0);
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
            func_L03_003240B8(o);
            if ((*(s32 *)(D_001D52FC + 0x1A4) & 0x10) == 0) {
                return;
            }
            if (D_L03_002D09B0 != 0xC) {
                return;
            }
            func_003A52A0(0, 0, o);
            o[0x20] = 2;
            st->f28 = 0.0f;
            st->f2C = 0.0f;
            func_L01_00511A40(o + 0x10, 0, *(f32 *)(o + 0xF8));
            st->w48 = 150;
            func_L01_00446780((s32)o, 1.5f, (s32)(o + 0x10), 0x10000, 20.0f, 1.0f, 0, 1, 0);
        }
        break;
    case 2:
        r = func_L01_00511A98();
        if (r == 2) {
            st->f34 = 1.95f;
            o[0x20] = 3;
        } else if (r == 0) {
            o[0x20] = 4;
        } else if (func_0038CAD0(&st->w48) != 0) {
            func_L01_00511AE8();
            o[0x20] = 1;
        }
        break;
    case 3:
        if (st->f34 == 0.0f) {
            if (st->w3C == 0 && st->w40 == 0) {
                s32 idx = st->w0;
                t = D_L03_001DF99C + (idx << 8);
                if (st->w4 != -1 && (D_001BBC40[st->wC + (D_001D545C << 4)] & 0x80)) {
                    t = D_L03_001DF99C + (st->w4 << 8);
                }
                q = *(u8 **)(t + 0x68);
                v = *(vu0_v4 *)(t + 0x10);
                v.z = v.z + 0.2f;
                func_L01_004F50C8(&v, t + 0xF0, 0, 1);
                D_001A71C5 = 1;
                t[0x20] = 4;
                *(s32 *)(q + 0x34) = 0;
                *(s32 *)(q + 0x28) = 0;
                *(s32 *)(q + 0x2C) = 0;
                *(f32 *)(q + 0x20) = 1.0f;
                *(f32 *)(q + 0x24) = 1.0f;
                func_003A52A0(1, 0, t);
                o[0x20] = 1;
                st->f20 = 0.0f;
                st->f24 = 0.0f;
                st->f28 = 0.0f;
                st->f2C = 0.0f;
                st->f34 = 1.95f;
            } else {
                if (st->w40 != 0) {
                    D_001427BB = 0;
                    func_00392DF0(0x10, 1);
                } else {
                    D_001427BB = 0;
                    func_00392DF0(0x18, 1);
                }
            }
        } else {
            func_L01_00404808(func_L03_00324190, o);
            func_003C4138(&st->f34, 0.0f, 0.080000006f);
        }
        break;
    case 4:
        if (st->f34 < 1.95f) {
            func_L01_00404808(func_L03_00324190, o);
            func_003C4138(&st->f34, 1.95f, 0.080000006f);
        } else if (st->f24 > 0.0f) {
            func_003C41A0(&st->f24, &st->f28, 0.0f, D_L03_001DCA68 * 0.00040000002f, D_L03_001DCA6C * 0.00040000002f, D_L03_001DCA70 * 0.020000001f);
        } else if (st->f20 > 0.0f) {
            func_003C41A0(&st->f20, &st->f2C, 0.0f, D_L03_001DCA68 * 0.00040000002f, D_L03_001DCA6C * 0.00040000002f, D_L03_001DCA70 * 0.020000001f);
        } else {
            o[0x20] = 1;
        }
        break;
    }
}
/* localdecomp:end func_L03_00323C48 */
