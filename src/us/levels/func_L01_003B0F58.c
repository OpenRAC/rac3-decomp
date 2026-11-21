#include "common.h"

/* NTSC-U counterpart of func_L01_003B2728 (src/levels/shared/L01_003B2728.c): 17 -> 20 */
extern u8 *D_L01_001E009C;
extern void func_L01_00441FB8(s32, s32, s32);

/* localdecomp:start func_L01_003B0F58 */
extern u8 *D_L01_001E009C;
extern f32 D_L01_001DF9D0;
extern s32 D_001A7430[];
extern s32 D_00142668[];
extern void func_L01_00441FB8(s32, s32, s32);
extern void func_L01_003B15F8_003B0F58(void);
extern s32 func_L01_00326F08(void);
extern void func_L01_00452F40(void *, s32);
extern void func_L01_003B12D0(void *, void *);

typedef struct {
    u8 pad0[0x30];
    s32 (*fn30)(s32);
    s32 (*fn34)(void);
    u8 pad38[4];
    s32 (*fn3C)(s32);
} T_003B2728;
extern T_003B2728 *func_L01_00438468(s32, s32);

typedef struct {
    u8 pad0[0x30];
    s32 w30;
    s32 w34;
    u8 pad38[4];
    s32 w3C;
    u8 pad40[0x50 - 0x40];
    u8 b50;
    u8 pad51[0x64 - 0x51];
    s32 w64;
} V_003B2728;
typedef struct {
    u8 pad0[0x30];
    u8 b30;
    u8 pad31[3];
    u16 h34;
    u8 pad36[0x68 - 0x36];
    V_003B2728 *w68;
} M_003B2728;

void func_L01_003B0F58(u8 *moby) {
    M_003B2728 *a0 = (M_003B2728 *)moby;
    V_003B2728 *v = a0->w68;
    T_003B2728 *t = func_L01_00438468(0x19E1, 0x6C);
    s32 id;
    M_003B2728 *q;

    func_L01_003B15F8_003B0F58();
    if (v->w30 == 0) {
        D_001A7430[0] = D_00142668[0];
    }
    a0->h34 &= ~2;
    id = v->w30 == 0 ? -2 : v->b50 != 0 ? -3 : v->w34;
    if (t->fn30(id) == 0 && func_L01_00326F08() == 0 && t->fn34() != 0) {
        D_L01_001DF9D0 = 2.0f;
        v->w64 = 0x14;
        func_L01_00441FB8((s32)a0, 2, -1);
        return;
    }
    if (v->w3C != -1) {
        q = (M_003B2728 *)(D_L01_001E009C + (v->w3C << 8));
        q->b30 = 0xFF;
        q->h34 &= ~2;
        func_L01_00452F40(q, 1);
        func_L01_00441FB8((s32)a0, 4, -1);
        D_L01_001DF9D0 = 2.0f;
        return;
    }
    if (id != -3 && t->fn30(id) == 0) {
        if (t->fn3C(id) != 0) {
            D_L01_001DF9D0 = 2.0f;
            v->w64 = 0x14;
            func_L01_00441FB8((s32)a0, 3, -1);
            return;
        }
    }
    func_L01_003B12D0(a0, v);
}
/* localdecomp:end func_L01_003B0F58 */
