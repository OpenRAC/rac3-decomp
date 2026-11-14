#include "common.h"

/* localdecomp:start func_L21_00337BF0 */
extern s32 func_L01_0043B568(s32, s32, s32);
extern s32 func_L21_003AA068(void *arg0);
extern void func_L01_0047C990(s32 a0, s32 idx, u8 flag, f32 f);
extern u8 *D_L21_001DED9C_00337BF0;
typedef struct {
    u8 pad[0x144];
    u8 *unk144;
    s32 unk148;
} S_00337BF0;
extern S_00337BF0 D_L21_001E1700;
extern u16 *D_L21_0021B860[];
extern s32 D_L21_001DEDD8;

typedef struct {
    u8 pad0[0x24];
    s32 unk24;
    s32 idx;
    u8 pad2C[0x60 - 0x2C];
    u8 *slots[6];
    u8 pad78[2];
    u8 n7A;
    u8 n7B;
    u8 n7C;
    u8 pad7D;
    u8 n7E;
} V_00337BF0;

typedef s32 (*Fn1_00337BF0)(u8 *);
typedef void (*Fn2_00337BF0)(u8 *, s32);

/* from rac2-decomp's func_00325DA0 (the list walk) */
void func_L21_00337BF0(void *arg0) {
    V_00337BF0 *s;
    u8 *base;
    u8 *q;
    u8 *r;
    u8 *r2;
    u8 *e;
    u16 *p;
    s32 a;
    s32 b;
    s32 flag;

    s = *(V_00337BF0 **)((u8 *)arg0 + 0x68);
    base = D_L21_001DED9C_00337BF0 + (s->unk24 << 8);
    q = *(u8 **)(base + 0x68);
    r = (u8 *)func_L01_0043B568(0x1BC5, 0, 0x44);
    r2 = (u8 *)func_L01_0043B568(0x1C18, 0, 0x44);
    s->n7C = 0;
    s->n7E = 0;
    s->n7A = 0;
    s->n7B = 0;
    if (((Fn1_00337BF0)(*(void **)(r + 0x1C)))(base) == 2) {
        s->n7A++;
    } else if (((Fn1_00337BF0)(*(void **)(r + 0x2C)))(base) != -1) {
        if (s->slots[((Fn1_00337BF0)(*(void **)(r + 0x2C)))(base)] == base) {
            s->slots[((Fn1_00337BF0)(*(void **)(r + 0x2C)))(base)] = 0;
        }
    }
    flag = 0;
    if (((Fn1_00337BF0)(*(void **)(r + 0x30)))(base) == 0 && func_L21_003AA068(base) == 0) {
        if (D_L21_001E1700.unk144 == 0) {
            D_L21_001E1700.unk144 = base;
            D_L21_001E1700.unk148 = 0;
        }
    } else {
        if (D_L21_001E1700.unk144 == base) {
            D_L21_001E1700.unk144 = 0;
        }
        flag = 1;
    }
    func_L01_0047C990(1, 0, flag, *(f32 *)(q + 0x30) / (f32)*(s16 *)(q + 0x34));
    for (p = D_L21_0021B860[s->idx];
         (s->idx & 0xFF) != 0xFF && s->idx <= D_L21_001DEDD8 && p != 0 &&
         ((p != 0 && (s16)p[-1] >= 0) || p == D_L21_0021B860[s->idx]);
         p++) {
        e = D_L21_001DED9C_00337BF0 + ((*p & 0x7FFF) << 8);
        if (e == 0) {
            return;
        }
        a = ((Fn1_00337BF0)(*(void **)(r2 + 0x1C)))(e);
        b = ((Fn1_00337BF0)(*(void **)(r2 + 0x24)))(e);
        if (((Fn1_00337BF0)(*(void **)(r2 + 0x30)))(e) != 0 ? a == 1 : (b == 1 || a == 1)) {
            s->n7E++;
        } else if (a == 2) {
            s->n7A++;
        } else if (a == 3) {
            s->n7B++;
        } else if (a == 0) {
            s->n7C++;
        }
        if (a != 2 && ((Fn1_00337BF0)(*(void **)(r2 + 0x2C)))(e) != -1) {
            s->slots[((Fn1_00337BF0)(*(void **)(r2 + 0x2C)))(e)] = 0;
            ((Fn2_00337BF0)(*(void **)(r2 + 0x28)))(e, -1);
        }
    }
}
/* localdecomp:end func_L21_00337BF0 */

/* localdecomp:start func_L21_00337F08 */
#include "vu0.h"
extern s32 func_L01_0043B568(s32, s32, s32);
extern f32 func_0038D160(f32, f32);
extern void func_L21_00337BF0(void *arg0);
extern u8 *D_L21_001DED9C_00337F08;
extern u16 *D_L21_0021B860[];
extern vu0_v4 D_L21_001D66B0 __attribute__((section(".sdata")));
extern f32 D_L21_001DCF40;
__asm__(".extern D_L21_001DCF40, 4");
extern f32 D_L21_001DCF44;

typedef struct {
    u8 pad0[0x24];
    s32 unk24;
    s32 idx;
    u8 pad2C[4];
    s32 list;
    u8 pad34[0x60 - 0x34];
    u8 *slots[6];
} V_00337F08;


s32 func_L21_00337F08(void *arg0, s32 idx, s32 flag) {
    V_00337F08 *s;
    u8 *base;
    u8 *r;
    u8 *e;
    u16 *list;
    vu0_v4 rot;

    s = *(V_00337F08 **)((u8 *)arg0 + 0x68);
    base = D_L21_001DED9C_00337F08 + (s->unk24 << 8);
    r = (u8 *)func_L01_0043B568(0x1BC5, 0, 0x44);
    if (s->slots[idx] != 0) {
        return;
    }
    s->slots[idx] = base;
    list = D_L21_0021B860[s->list] + idx;
    e = D_L21_001DED9C_00337F08 + ((*list & 0x7FFF) << 8);
    rot = D_L21_001D66B0;
    rot.z = func_0038D160(D_L21_001DCF40 - *(f32 *)(e + 0x10), D_L21_001DCF44 - *(f32 *)(e + 0x14));
    if (flag != 0) {
        *(vu0_v4 *)(base + 0x10) = *(vu0_v4 *)(e + 0x10);
        *(vu0_v4 *)(base + 0xF0) = rot;
    } else {
        ((void (*)(u8 *, s32, void *, void *))(*(void **)(r + 0xC)))(base, 2, e + 0x10, &rot);
    }
    ((void (*)(u8 *, s32))(*(void **)(r + 0x18)))(base, 2);
    ((void (*)(u8 *, s32))(*(void **)(r + 0x28)))(base, idx);
    ((void (*)(u8 *, s32))(*(void **)(r + 0x10)))(base, 0);
    *(f32 *)(base + 0x2C) *= 1.2f;
    func_L21_00337BF0(arg0);
}
/* localdecomp:end func_L21_00337F08 */
