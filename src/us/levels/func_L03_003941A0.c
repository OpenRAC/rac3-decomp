#include "common.h"

/* NTSC-U counterpart of func_L03_00395808 (src/levels/03_starship_phoenix/L03_00395808.c) */
/* localdecomp:start func_L03_003941A0 */
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
extern u8 *D_L03_001DFA1C;
__asm__(".extern D_L03_001DFA1C, 16");
extern u8 D_001A30B0[];
extern s16 D_001A4DBC[];
extern u8 D_L03_001E92A0[];
extern s32 *D_L03_0021D940[];
__asm__(".extern D_L03_0021D940, 16");
extern void func_L03_00394578(void *);
extern void func_L03_00394630(void *);
extern void func_L03_00394F70(void *);
extern void func_L03_00394CA8(void *);
extern s32 func_0039FE80(s32, s32, void *);
extern f32 func_00388A28(f32, f32);
extern f32 func_00388800(void *, void *);
extern f32 func_00389380(f32, f32);
extern s32 func_L03_004307B8(void *, void *, void *, s32, f32, f32, s32, s32, s32);
extern void func_L01_00402498(void *, void *);
extern f32 func_00389410(f32);
extern f32 func_00388960(f32);
extern void func_L03_00461B90(s32, s32, void *, void *, s32, f32);
extern void func_003886E8(void *, void *, f32);

void func_L03_003941A0(void *arg) {
    A_00395808 *a = arg;
    S_00395808 *s = a->p68;
    vu0_v4 d;
    int flag;
    f32 x;
    func_L03_00394578(a);
    if (a->b20 != 1) return;
    if (s->i20 != -1) {
        u8 *t;
        int idx = s->i70;
        u8 *e;
        if (idx == -1 || (e = D_001A30B0 + (idx << 7), *(void **)(e + 0xDC) != a) || e[0xD0] == 0) {
            s->i70 = func_0039FE80(0, 4, a);
        }
        t = D_L03_001DFA1C + (s->i20 << 8);
        if (t != 0) {
            vec_sub_ba(&d, t + 0x10, &a->pos);
            a->fF8 = func_00388A28(*(f32 *)(t + 0x10) - a->pos.x, *(f32 *)(t + 0x14) - a->pos.y);
            a->fF4 = -func_00388A28(func_00388800(&a->pos, t + 0x10), *(f32 *)(t + 0x18) - a->pos.z);
            if (s->b63 == 0) {
                if (s->b62 != 0) {
                    s->f30 = func_00389380(s->f30, s->f34 * 0.017453292f * 0.0166666675f);
                    s->f58 = s->f58 + 0.11f;
                    if (s->f58 >= 1.0f) s->f58 = s->f58 - 1.0f;
                    if (func_L03_004307B8(a, &a->pos, t + 0x10, 1, s->f54, 1.0f, 0, 1, 0) != 0 && D_001A4DBC[0] == 0) {
                        func_L03_00394CA8(D_L03_001E92A0);
                    }
                    func_L01_00402498(func_L03_00394630, a);
                }
            } else if (s->b63 == 1) {
                s->f58 = s->f58 + 0.1f;
                if (s->f58 >= 1.0f) s->f58 = s->f58 - 1.0f;
                if (s->b62 != 0) func_L01_00402498(func_L03_00394F70, a);
            }
        }
    }
    flag = 0;
    if (s->i24 != -1) {
        u8 *m = D_L03_001DFA1C + (s->i24 << 8);
        if (m != 0 && *(s16 *)(m + 0xAA) == 0x18C0) {
            flag = 1;
            s->f48 = (*(P_00395808 **)(m + 0x68))->f48 + s->f28;
        }
    }
    if (flag == 0) s->f48 = s->f48 + s->f4C;
    if (s->b60 != 0) {
        if (s->f48 > 1.0f) s->f48 = s->f48 - 1.0f;
        x = s->f48;
    } else {
        if (s->f48 > 2.0f) s->f48 = s->f48 - 2.0f;
        x = (1.0f - func_00388960(func_00389410(s->f48 * 3.1415927f))) * 0.5f;
    }
    if (s->i5C != -1) {
        if (s->b64 != 0) x = 1.0f - x;
        func_L03_00461B90(s->i5C, s->b60, &a->pos, &a->fF0, 1, x * (f32)*D_L03_0021D940[s->i5C]);
    } else if (s->i2C != -1) {
        func_003886E8(&d, &s->v10, x);
        vec_add_ab(&a->pos, &s->v0, &d);
    }
}
/* localdecomp:end func_L03_003941A0 */
