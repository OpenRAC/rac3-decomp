#include "common.h"

/* declared by functions of L21_00336EF0.c, which this file was cut from */
extern s32 func_L01_0043B568(s32, s32, s32);
extern s32 func_00382468(s32);

/* localdecomp:start func_L21_003383A8 */
#include "vu0.h"
extern s32 func_L01_0043B568(s32, s32, s32);
extern s32 func_00382468(s32);
extern f32 func_0038D160(f32, f32);
extern void func_L21_00337BF0(void *arg0);
extern u8 *D_L21_001DED9C_003383A8;
extern u16 *D_L21_0021B860[];
extern s32 D_L21_001DEDD8;
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
    u8 pad78[5];
    u8 n7D;
} V_003383A8;

typedef s32 (*Fn1_003383A8)(u8 *);

void func_L21_003383A8(void *arg0, s32 count) {
    V_003383A8 *s;
    u8 *r;
    u8 *e;
    u8 *e2;
    u16 *p;
    u16 *list;
    s32 n;
    s32 i;
    s32 k;
    s32 free[6];
    vu0_v4 rot;

    s = *(V_003383A8 **)((u8 *)arg0 + 0x68);
    r = (u8 *)func_L01_0043B568(0x1C18, 0, 0x44);
    if (r == 0) {
        return;
    }
    for (;;) {
        if (count - s->n7D <= 0) {
            return;
        }
        n = 0;
        for (i = 0; i < 6; i++) {
            if (s->slots[i] == 0) {
                free[n++] = i;
            }
        }
        if (n <= 0) {
            return;
        }
        k = free[func_00382468(n)];
        for (p = D_L21_0021B860[s->idx];
             (s->idx & 0xFF) != 0xFF && s->idx <= D_L21_001DEDD8 && p != 0 &&
             ((s16)p[-1] >= 0 || p == D_L21_0021B860[s->idx]);
             p++) {
            e = D_L21_001DED9C_003383A8 + ((*p & 0x7FFF) << 8);
            if (e == 0) {
                break;
            }
            if (((Fn1_003383A8)(*(void **)(r + 0x1C)))(e) == 0) {
                do {
                    s->slots[k] = e;
                    list = D_L21_0021B860[s->list] + k;
                    e2 = D_L21_001DED9C_003383A8 + ((*list & 0x7FFF) << 8);
                    rot = D_L21_001D66B0;
                    rot.z = func_0038D160(D_L21_001DCF40 - *(f32 *)(e2 + 0x10), D_L21_001DCF44 - *(f32 *)(e2 + 0x14));
                    ((void (*)(u8 *, s32, void *, void *))(*(void **)(r + 0xC)))(e, 2, e2 + 0x10, &rot);
                    ((void (*)(u8 *, s32))(*(void **)(r + 0x18)))(e, 2);
                    ((void (*)(u8 *, s32))(*(void **)(r + 0x28)))(e, k);
                    ((void (*)(u8 *, s32))(*(void **)(r + 0x10)))(e, 0);
                    s->n7D++;
                    func_L21_00337BF0(arg0);
                } while (0);
                break;
            }
        }
    }
}
/* localdecomp:end func_L21_003383A8 */
