#include "common.h"

/* localdecomp:start func_L05_003DB1C0 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3DB1C0;

struct R_3DB1C0 {
    u8 pad[0x24];
    f32 f24;
};

typedef struct S_3DB1C0 {
    u8 pad0[0x10];
    u128_t v10;
    u8 pad1[4];
    struct R_3DB1C0 *p24;
    u8 pad2[4];
    f32 f2c;
    u8 f30;
    u8 f31;
    u16 f32h;
    u16 f34;
    u8 pad3[2];
    unsigned long f38;
    u8 pad4[0xB0];
    u128_t vF0;
} S_3DB1C0;

extern S_3DB1C0 *func_003C24B0(s32, s32);
extern s32 func_00382468(s32);
extern void func_0038D328(void *, void *);
extern void func_0038D890(void *, void *, void *, f32);
extern void func_003C48A8(void *, void *);
extern void func_003C7C38(void *);

S_3DB1C0 *func_L05_003DB1C0(S_3DB1C0 *src, s32 arg1, s32 arg2) {
    S_3DB1C0 *s;
    V4_3DB1C0 t0, t1, t2;
    unsigned long v;
    char buf[0x10];

    s = func_003C24B0(arg1, 0x80);
    if (s != 0) {
        s->f32h = 0xFF;
        s->f31 = 1;
        s->f2c = s->f2c * (src->f2c / src->p24->f24);
        s->v10 = src->v10;
        if (func_00382468(2)) {
            func_0038D328(&t0, &src->vF0);
            func_0038D890(&t1, &t1, &t0, 3.1415927f);
            func_0038D890(&t2, &t2, &t0, 3.1415927f);
            func_003C48A8(&t0, &s->vF0);
        } else {
            s->vF0 = src->vF0;
        }
        v = src->f38;
        s->f30 = arg2;
        s->f34 = 0;
        s->f38 = v;
        func_003C7C38(s);
        return s;
    }
    return 0;
}
/* localdecomp:end func_L05_003DB1C0 */

INCLUDE_ASM("asm/levels", func_L05_003DB2D0);

/* localdecomp:start func_L05_003DB580 */
s32 func_L01_00447490(s32, s32, s32);
void func_L05_003DB2D0(s32);

void func_L05_003DB580(s32 arg0) {
    if (func_L01_00447490(arg0, -1, 0) != 0) {
        func_L05_003DB2D0(arg0);
    }
}
/* localdecomp:end func_L05_003DB580 */

INCLUDE_ASM("asm/levels", func_L05_003DB5C0);
