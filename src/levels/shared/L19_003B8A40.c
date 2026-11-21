#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L19_003B8A40 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003B6D90;
typedef struct {
    u8 pad0[0x24];
    f32 f24;
} W_003B6D90;
typedef struct {
    u8 pad0[0x30];
    f32 f30;
    s16 h34;
    u8 pad36[3];
    u8 b39;
    u8 pad3A[4];
    u8 b3E;
    u8 pad3F;
    f32 f40;
    u8 pad44[0x14];
    u8 b58;
    u8 pad59;
    u8 b5A;
    u8 pad5B[0x35];
    s32 w90;
} S_003B6D90;
typedef struct {
    u8 pad0[0x10];
    V4_003B6D90 v10;
    u8 b20;
    u8 pad21[3];
    W_003B6D90 *w24;
    u8 pad28[4];
    f32 f2C;
    u8 pad30[4];
    u16 h34;
    u8 pad36[0x32];
    S_003B6D90 *p68;
    u8 pad6C[0x2C];
    s32 w98;
    u8 pad9C[0xE];
    s16 hAA;
    u8 padAC[0x4C];
    f32 fF8;
} O_003B6D90;

extern f32 D_L19_001DE668;
__asm__(".extern D_L19_001DE668, 4");
extern u8 D_001A30B0[];
extern u8 D_001A4C60[];
extern u8 D_L19_001D66F0[8];
extern s32 func_L01_0044C108(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00456BD0(void *, s32);
extern f32 func_0038CF38(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00446A70(s32, void *, s32, void *, void *, f32);
extern void *func_L01_00447490(void *, s32, s32);
extern s32 func_L01_004561B8(void *);
extern void func_003A4F28(s32);
extern void func_L01_0044AF78(void *, void *, s32, f32, f32, s32, s32, s32, f32, f32, f32, f32, s32, s32, f32, s32, s32, s32, s32);
extern void func_L01_00451FE0(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_L01_004AA7E8(void *, s32);
extern void func_003C2880(void *);
extern f32 func_0038DAB8(f32, f32);

void func_L19_003B8A40(O_003B6D90 *a) {
    S_003B6D90 *s;
    V4_003B6D90 d;
    f32 dist;

    if (func_L01_0044C108((u8 *)a + 0x10) == 0) {
        return;
    }
    s = a->p68;
    if (a->b20 == 0) {
        s->b58 = 0x14;
        s->b5A = 0xE;
        if (s->h34 == 0) {
            s->f30 = 100.0f;
            s->h34 = 100;
        }
        s->b3E = 1;
        s->w90 = -1;
        s->f40 = 1.0f;
        s->b39 = 0;
        a->h34 |= 0x1000;
        func_L01_004450F0(a, 1, -1);
    } else if (a->b20 == 1) {
        s32 id = s->w90;
        u8 *e;
        if (id == -1 || *(s32 *)((e = (u8 *)((id << 7) + (s32)D_001A30B0)) + 0xDC) != (s32)a) {
            s->w90 = func_003A52A0(0, 4, a);
        }
        func_L01_00456BD0(a, 3);
        dist = func_0038CF38((u8 *)a + 0x10, D_001A4C60);
        if (dist < a->f2C * 2.1f / a->w24->f24) {
            vec_sub_ab(&d, D_001A4C60, &a->v10);
            func_0038CF68(&d, &d, 0.20000002f);
            func_L01_00446A70(*(s32 *)(D_001A4C60 + 0x2540), a, 0x10001, D_001A4C60, &d, 1.0f);
        }
        if (func_L01_00447490(a, -1, 0) != 0) {
            func_L01_004450F0(a, 2, -1);
        }
    } else if (a->b20 == 2) {
        if (func_L01_004561B8(a) != 0) {
            s32 id = s->w90;
            if (id != -1) {
                u8 *e = (u8 *)((id << 7) + (s32)D_001A30B0);
                if (*(s32 *)(e + 0xDC) == (s32)a && *(u8 *)(e + 0xD0) != 0) {
                    func_003A4F28(id);
                }
            }
            s->w90 = -1;
            qzero(&d);
            func_L01_0044AF78(a, &d, 0, 2.0f, 4.0f, 10, 3, 16, 4.0f, 2.0f, 9.0f, 1.0f, -1, 1, 15.0f, 1, -1, 0, 0x1010001);
            func_003A52A0(1, 0, a);
            func_L01_00451FE0(a, 0x3F, D_L19_001D66F0, 2.0f, 4.0f, 2.0f, 4.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
            a->h34 = (a->h34 | 0x41) & 0xEFFF;
            a->w98 = 0;
            func_L01_004AA7E8(a, 1);
            func_003C2880(a);
            return;
        }
    }
    if (a->hAA != 0x1B28) {
        a->fF8 = func_0038DAB8(a->fF8, D_L19_001DE668);
    }
}
/* localdecomp:end func_L19_003B8A40 */
