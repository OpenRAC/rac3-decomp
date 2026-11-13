#include "common.h"

/* localdecomp:start func_L03_00395808 */
#include "vu0.h"
typedef struct {
    vu0_v4 v0;
    vu0_v4 v10;
    s32 i20;
    s32 i24;
    f32 f28;
    s32 i2C;
    f32 f30;
    f32 f34;
    u8 pad38[0x48 - 0x38];
    f32 f48;
    f32 f4C;
    u8 pad50[0x54 - 0x50];
    f32 f54;
    f32 f58;
    s32 i5C;
    u8 b60;
    u8 pad61;
    u8 b62;
    u8 b63;
    u8 b64;
    u8 pad65[0x70 - 0x65];
    s32 i70;
} S_00395808;
typedef struct { u8 pad0[0x10]; vu0_v4 pos; u8 b20; u8 pad21[0x47]; S_00395808 *p68; u8 pad6C[0xF0 - 0x6C]; f32 fF0; f32 fF4; f32 fF8; } A_00395808;
typedef struct { u8 pad0[0x48]; f32 f48; } P_00395808;
extern u8 *D_L03_001DF99C;
__asm__(".extern D_L03_001DF99C, 16");
extern u8 D_001A30B0[];
extern s16 D_001A4DBC[];
extern u8 D_L03_001E9220[];
extern s32 *D_L03_0021D8C0[];
__asm__(".extern D_L03_0021D8C0, 16");
extern void func_L03_00395BF0(void *);
extern void func_L03_00395CA8(void *);
extern void func_L03_003965E8(void *);
extern void func_L03_00396320(void *);
extern s32 func_003A52A0(s32, s32, void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038DAB8(f32, f32);
extern s32 func_L03_00433C70(void *, void *, void *, s32, f32, f32, s32, s32, s32);
extern void func_L01_00404808(void *, void *);
extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern void func_L03_004657D0(s32, s32, void *, void *, s32, f32);
extern void func_0038CE20(void *, void *, f32);

void func_L03_00395808(void *arg) {
    A_00395808 *a = arg;
    S_00395808 *s = a->p68;
    vu0_v4 d;
    int flag;
    f32 x;
    func_L03_00395BF0(a);
    if (a->b20 != 1) return;
    if (s->i20 != -1) {
        u8 *t;
        int idx = s->i70;
        u8 *e;
        if (idx == -1 || (e = D_001A30B0 + (idx << 7), *(void **)(e + 0xDC) != a) || e[0xD0] == 0) {
            s->i70 = func_003A52A0(0, 4, a);
        }
        t = D_L03_001DF99C + (s->i20 << 8);
        if (t != 0) {
            vec_sub_ba(&d, t + 0x10, &a->pos);
            a->fF8 = func_0038D160(*(f32 *)(t + 0x10) - a->pos.x, *(f32 *)(t + 0x14) - a->pos.y);
            a->fF4 = -func_0038D160(func_0038CF38(&a->pos, t + 0x10), *(f32 *)(t + 0x18) - a->pos.z);
            if (s->b63 == 0) {
                if (s->b62 != 0) {
                    s->f30 = func_0038DAB8(s->f30, s->f34 * 0.017453292f * 0.020000001f);
                    s->f58 = s->f58 + 0.11f;
                    if (s->f58 >= 1.0f) s->f58 = s->f58 - 1.0f;
                    if (func_L03_00433C70(a, &a->pos, t + 0x10, 1, s->f54, 1.0f, 0, 1, 0) != 0 && D_001A4DBC[0] == 0) {
                        func_L03_00396320(D_L03_001E9220);
                    }
                    func_L01_00404808(func_L03_00395CA8, a);
                }
            } else if (s->b63 == 1) {
                s->f58 = s->f58 + 0.1f;
                if (s->f58 >= 1.0f) s->f58 = s->f58 - 1.0f;
                if (s->b62 != 0) func_L01_00404808(func_L03_003965E8, a);
            }
        }
    }
    flag = 0;
    if (s->i24 != -1) {
        u8 *m = D_L03_001DF99C + (s->i24 << 8);
        if (m != 0 && *(s16 *)(m + 0xAA) == 0x18C0) {
            flag = 1;
            s->f48 = (*(P_00395808 **)(m + 0x68))->f48 + s->f28;
        }
    }
    if (flag == 0) s->f48 = s->f48 + s->f4C * 1.2f;
    if (s->b60 != 0) {
        if (s->f48 > 1.0f) s->f48 = s->f48 - 1.0f;
        x = s->f48;
    } else {
        if (s->f48 > 2.0f) s->f48 = s->f48 - 2.0f;
        x = (1.0f - func_0038D098(func_0038DB48(s->f48 * 3.1415927f))) * 0.5f;
    }
    if (s->i5C != -1) {
        if (s->b64 != 0) x = 1.0f - x;
        func_L03_004657D0(s->i5C, s->b60, &a->pos, &a->fF0, 1, x * (f32)*D_L03_0021D8C0[s->i5C]);
    } else if (s->i2C != -1) {
        func_0038CE20(&d, &s->v10, x);
        vec_add_ab(&a->pos, &s->v0, &d);
    }
}
/* localdecomp:end func_L03_00395808 */

/* localdecomp:start func_L03_00395BF0 */
#include "vu0.h"
typedef struct { u8 pad0[0x10]; vu0_v4 v10; u8 pad20[0x48]; u8 *p68; } A_00395BF0;
typedef struct { vu0_v4 v0; vu0_v4 v10; u8 pad20[0xC]; s32 i2C; u8 pad30[8]; f32 f38; u8 pad3C[4]; s32 i40; f32 f44; u8 pad48[4]; f32 f4C; s32 i50; u8 pad54[4]; s32 f58; } P_00395BF0;
typedef struct { u8 b[0x80]; } E_00395BF0;
extern E_00395BF0 *D_L03_001DFA80;
extern void func_L01_004450F0(void *, s32, s32);
void func_L03_00395BF0(void *arg) {
    A_00395BF0 *a = arg;
    P_00395BF0 *p;
    if (*(u8 *)((u8 *)arg + 0x20) == 0) {
        p = (P_00395BF0 *)a->p68;
        p->f58 = 0;
        p->v0 = *(vu0_v4 *)&a->v10;
        if (p->i2C != -1) {
            vec_sub_ba(&p->v10, D_L03_001DFA80[p->i2C].b + 0x30, &a->v10);
        }
        p->f44 = p->f38 / (f32)p->i40 * 0.017453292f;
        p->f4C = 1.0f / (f32)p->i50;
        func_L01_004450F0(arg, 1, -1);
    }
}
/* localdecomp:end func_L03_00395BF0 */

INCLUDE_ASM("asm/levels", func_L03_00395CA8);

INCLUDE_ASM("asm/levels", func_L03_00395D60);

INCLUDE_ASM("asm/levels", func_L03_00396190);

INCLUDE_ASM("asm/levels", func_L03_00396320);

/* localdecomp:start func_L03_003965E8 */
#include "vu0.h"
typedef struct { u8 pad0[0x20]; s32 i20; u8 pad24[0x58 - 0x24]; f32 f58; } S_003965E8;
typedef struct { u8 pad0[0x10]; vu0_v4 pos; u8 pad20[0x48]; S_003965E8 *p68; } A_003965E8;
extern u8 *D_L03_001DF99C;
__asm__(".extern D_L03_001DF99C, 16");
extern void func_0038CE20(void *, void *, f32);
extern void func_003C4C18(f32 *v, f32 r);
extern void func_L01_00409658(void *, f32, f32, f32, s32, s32, s32, s32, s32, s32);

void func_L03_003965E8(void *arg) {
    A_003965E8 *a = arg;
    S_003965E8 *s = a->p68;
    vu0_v4 cur;
    vu0_v4 step;
    f32 pts[24][4];
    int i;
    vec_sub_ba(&step, D_L03_001DF99C + (s->i20 << 8) + 0x10, &a->pos);
    func_0038CE20(&step, &step, 0.14285715f);
    cur = a->pos;
    for (i = 0; i < 8; i++) {
        *(vu0_v4 *)pts[i] = cur;
        if (i != 0 && i != 7) {
            func_003C4C18(pts[i], 0.5f);
        }
        pts[i][3] = 0.15f;
        vec_add_ab(&cur, &cur, &step);
    }
    func_L01_00409658(pts, 0.15f, 8.0f, s->f58, 0x17, 0x17, 9, -1, 0x60600000, 0);
}
/* localdecomp:end func_L03_003965E8 */
