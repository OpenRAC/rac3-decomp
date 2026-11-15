#include "common.h"

/* localdecomp:start func_L31_003A5CB0 */
extern s32 D_L31_001DF340;
__asm__(".extern D_L31_001DF340, 16");
extern s32 D_L31_001DEA20;
extern f32 D_L31_001DEA18;
extern f32 D_L31_001DEA1C;
__asm__(".extern D_L31_001DEA20, 4");
__asm__(".extern D_L31_001DEA18, 4");
__asm__(".extern D_L31_001DEA1C, 4");
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_004561B8(void *);
extern s32 func_L01_00456250(void *);
extern f32 func_L03_0034B148(s32, s32, f32);
extern f32 func_0038DB48(f32);
extern f32 func_0038D0B0(f32);
extern void func_L01_0043B9E8(void *, s32, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L03_0034A4B8(void *, s32);
extern void func_L01_004AA7E8(void *, s32);

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_003A5CB0;
typedef int Q_003A5CB0 __attribute__((mode(TI)));

typedef struct {
    char pad0[0x10];
    u32 f10;
    char pad14[0x30];
    u16 f44;
} H_003A5CB0;

typedef struct {
    char pad0[0x10];
    V_003A5CB0 pos;
    u8 state;
    char pad21[3];
    H_003A5CB0 *h;
    char pad28[4];
    f32 f2C;
    char pad30[4];
    u16 f34;
    char pad36[0x32];
    V_003A5CB0 *p;
    char pad6C[0x2C];
    s32 f98;
} O_003A5CB0;

void func_L31_003A5CB0(O_003A5CB0 *o) {
    V_003A5CB0 *p = o->p;
    H_003A5CB0 *h;
    f32 t;
    s32 n;

    switch (o->state) {
    case 0:
        *(Q_003A5CB0 *)p = *(Q_003A5CB0 *)&o->pos;
        func_L01_004450F0(o, 1, -1);
        break;
    case 1:
        if (func_L01_004561B8(o)) {
            o->f34 &= ~0x41;
            h = o->h;
            o->f34 |= h->f44 & 0x1000;
            o->f98 = h->f10;
        }
        *(Q_003A5CB0 *)&o->pos = *(Q_003A5CB0 *)p;
        n = D_L31_001DEA20;
        t = func_0038D0B0(func_0038DB48(func_L03_0034B148(D_L31_001DF340 % n, n, 0.0f) * 6.2831855f));
        o->pos.z += D_L31_001DEA18 * t;
        o->f2C = D_L31_001DEA1C * *(f32 *)((u8 *)o->h + 0x24);
        func_L01_0043B9E8(o, 0, 0xFF, 0);
        if (func_L01_00456250(o)) {
            func_L01_004450F0(o, 2, -1);
        }
        break;
    case 2:
        if (func_L01_004561B8(o)) {
            func_003A52A0(0, 0, o);
            func_L03_0034A4B8(&o->pos, 0x1E);
            o->f98 = 0;
            o->f34 = (o->f34 | 0x41) & ~0x1000;
            func_L01_004AA7E8(o, 1);
        }
        break;
    }
}
/* localdecomp:end func_L31_003A5CB0 */
