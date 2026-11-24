#include "common.h"

/* NTSC-U counterpart of func_L09_00317D00 (src/levels/09_tyhrranosis/L09_00317D00.c) */
extern u8 *D_L09_001E011C;
extern void func_L09_003179E0(void);

/* localdecomp:start func_L09_003179E0 */
#include "vu0.h"

typedef struct { u8 _p0[0x25C0]; u8 *x25C0; s32 x25C4; } H_00317D00;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00317D00;
typedef struct { V_00317D00 r[3]; } M_00317D00;
typedef struct { s32 c[4]; f32 x, y; } S_00317D00;

extern u8 *D_L09_001DC750;
__asm__(".extern D_L09_001DC750, 4");
extern H_00317D00 D_001A4BE0;
extern V_00317D00 D_L09_001E2F90;
extern s32 D_L09_001DC75C;
__asm__(".extern D_L09_001DC75C, 16");
extern f32 D_L09_001E12A4;
extern s32 D_L09_001E12A0;
extern s32 D_001D4BC0;
__asm__(".extern D_001D4BC0, 16");
extern s32 D_001D4BC4;
__asm__(".extern D_001D4BC4, 16");
extern u8 *D_L09_001E011C_2 __attribute__((section(".sdata")));
extern u8 *D_L09_001E011C;
__asm__(".extern D_L09_001E011C, 16");
extern s32 D_L09_001E0158 __attribute__((section(".sdata")));
extern u16 *D_L09_0021CE20[];
extern u32 D_00142BA0[];
extern u8 D_0014271D[];
extern long func_00384EC0(s32);
extern void func_00388BD0(void *, void *);
extern void func_00388758(void *, void *, void *);
extern void func_00388830(void *, void *, f32);
extern void func_00388EB8(void *, void *, void *);
extern void func_L01_0040C920(void *, void *);
extern s32 func_00392108(s32, s32);
extern void func_00392A40(s32, void *, f32, f32, f32, f32, f32);
extern void func_L09_00317570(void *, s32, void *, void *, long);
extern void func_L09_00317800(void *, void *, long);

void func_L09_003179E0(void) {
    V_00317D00 pos;
    V_00317D00 rot;
    M_00317D00 mtx;
    V_00317D00 dir;
    V_00317D00 a;
    V_00317D00 b;
    S_00317D00 s;
    u8 *st = *(u8 **)(D_L09_001DC750 + 0x68);
    long t = func_00384EC0(0x3B);
    f32 fx, fy;
    f32 sx, sy;
    s32 c;
    s32 y;
    s32 h;
    s32 idx;
    u16 *p;
    u8 *e;

    qzero(&rot);
    rot.z = -1.57079637f;
    func_00388BD0(&mtx, &rot);
    pos = *(V_00317D00 *)(D_001A4BE0.x25C0 + 0xE0);
    a = D_L09_001E2F90;
    b = pos;
    func_00388758(&dir, &a, &b);
    func_00388830(&dir, &dir, 1.0f);
    func_00388EB8(&dir, &dir, &mtx);
    func_L01_0040C920(&dir, &dir);
    s.x = (f32)D_001D4BC0 * 0.86650002f;
    {
        f32 z0 = 0.0f, z1 = 0.0f;
        y = (s32)((f32)D_001D4BC4 * 0.838999987f * D_L09_001E12A4 + 0.5f + (D_L09_001E12A0 == 1 ? z0 : z1));
    }
    sx = (f32)D_001D4BC0 * 0.0130000003f;
    s.y = (f32)y;
    {
        f32 z0 = 0.0f, z1 = 0.0f;
        h = (s32)((f32)D_001D4BC4 * 0.0160000008f * D_L09_001E12A4 + 0.5f + (D_L09_001E12A0 == 1 ? z0 : z1));
    }
    c = D_L09_001DC75C;
    sy = (f32)h;
    s.c[3] = c;
    s.c[2] = c;
    s.c[1] = c;
    s.c[0] = c;
    func_00392A40(func_00392108(0xE99A, 3), &s, s.x, s.y, sx, sy, 0.0f);

    if (D_001A4BE0.x25C4 != 0x31) {
        idx = *(s32 *)(st + 0x68);
        if (idx != -1) {
            e = D_L09_001E011C_2 + (idx << 8);
            if (e != 0 && e[0x20] != 0xFE && e[0x20] != 0xFD) {
                func_L09_00317570(e, 1, &pos, &dir, t);
            }
        }
    }

    for (p = D_L09_0021CE20[*(s32 *)(st + 4)];
         (*(s32 *)(st + 4) & 0xFF) != 0xFF && *(s32 *)(st + 4) <= D_L09_001E0158 && p != 0 &&
         ((s16)p[-1] >= 0 || p == D_L09_0021CE20[*(s32 *)(st + 4)]);
         p++) {
        u8 *m = D_L09_001E011C + ((*p & 0x7FFF) << 8);
        if (m == 0) {
            break;
        }
        if (m[0x20] == 0xFE) {
            continue;
        }
        if (m[0x20] == 0xFD) {
            continue;
        }
        func_L09_00317570(m, 3, &pos, &dir, t);
    }

    if ((D_00142BA0[0x94 / 4] & 0x800000) && D_0014271D[0] == 0) {
        func_L09_00317800(&pos, &dir, t);
    }
}
/* localdecomp:end func_L09_003179E0 */
