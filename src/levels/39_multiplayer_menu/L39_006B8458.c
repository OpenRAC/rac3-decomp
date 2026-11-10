#include "common.h"

/* localdecomp:start func_L39_006B8458 */
extern s32 func_00381FF0(s32);
extern void func_L39_006B8AC8(void *, s32);
extern s32 D_L39_004B1578[];

void func_L39_006B8458(void *p) {
    s32 buf[32];
    s32 *src;
    s32 *dst;
    s32 i;
    void *obj;
    void (*fn)(void *, s32, void *);

    src = D_L39_004B1578;
    dst = buf;
    *(s32 *)((u8 *)p + 0x2AC) = 0;
    i = 0x15;
    do {
        i--;
        *dst = func_00381FF0(*src);
        src++;
        dst++;
    } while (i >= 0);

    obj = *(void **)((u8 *)p + 0x128);
    fn = *(void (**)(void *, s32, void *))(*(u8 **)((u8 *)obj + 0x60) + 0x6C);
    fn(obj, 0x16, buf);
    func_L39_006B8AC8(p, 0);
}
/* localdecomp:end func_L39_006B8458 */

INCLUDE_ASM("asm/levels", func_L39_006B84E8);

/* localdecomp:start func_L39_006B8698 */
typedef struct S_006B8698_W {
    u8 pad[0x60];
    void **vt;
} S_006B8698_W;
typedef struct S_006B8698 {
    u8 pad[0x110];
    S_006B8698_W *w[11];
} S_006B8698;
typedef struct S_006B8698_A {
    f32 x, y, w, h;
    s32 c;
} S_006B8698_A;
typedef struct S_006B8698_B {
    s32 n;
    f32 x, y, w, h;
    s32 c;
} S_006B8698_B;
typedef struct S_006B8698_C {
    f32 x, y, w, h;
    f32 unk10;
    f32 dy;
} S_006B8698_C;
extern S_006B8698_A D_L39_004B15D0;
extern S_006B8698_B D_L39_004B15E8;
extern S_006B8698_C D_L39_004B1600;
extern S_006B8698_C D_L39_004B1638;
extern S_006B8698_A D_L39_004B1670;
extern u8 D_L39_004B1690[];
extern S_006B8698_A D_L39_004B16A0;
extern S_006B8698_C D_L39_004B16B8;
extern S_006B8698_C D_L39_004B16F0;
extern void func_L39_0068A6D0(void *, s32, f32, f32, f32, f32, s32);
extern void func_L39_0068A4A8(void *, s32, s32, f32, f32, f32, f32, s32);
extern void func_L39_006B7E68(void *);
void func_L39_006B8698(S_006B8698 *p) {
    s32 i;
    f32 y;
    func_L39_0068A6D0(p, 0, D_L39_004B15D0.x, D_L39_004B15D0.y, D_L39_004B15D0.w, D_L39_004B15D0.h, D_L39_004B15D0.c);
    func_L39_0068A4A8(p, 0, D_L39_004B15E8.n, D_L39_004B15E8.x, D_L39_004B15E8.y, D_L39_004B15E8.w, D_L39_004B15E8.h, D_L39_004B15E8.c);
    y = D_L39_004B1600.y;
    for (i = 0; i < 7; i++) {
        if (i == 1) {
            ((void (*)(void *, s32, s32))p->w[1]->vt[0x48 / 4])(p->w[1], 1, 3);
            ((void (*)(void *, f32, f32))p->w[1]->vt[0x28 / 4])(p->w[1], D_L39_004B1600.x, y);
            ((void (*)(void *, f32, f32))p->w[1]->vt[0x2C / 4])(p->w[1], D_L39_004B1600.w, D_L39_004B1600.h);
            ((void (*)(void *, s32, s32))p->w[1]->vt[0x4C / 4])(p->w[1], 0x40, 1);
            ((void (*)(void *, s32))p->w[1]->vt[0x40 / 4])(p->w[1], 1);
        } else {
            ((void (*)(void *, f32, f32))p->w[i]->vt[0x28 / 4])(p->w[i], D_L39_004B1600.x, y);
            ((void (*)(void *, f32, f32))p->w[i]->vt[0x2C / 4])(p->w[i], D_L39_004B1600.w, D_L39_004B1600.h);
            ((void (*)(void *, s32))p->w[i]->vt[0x40 / 4])(p->w[i], 1);
            ((void (*)(void *, s32, s32))p->w[i]->vt[0x4C / 4])(p->w[i], 0x40, 1);
        }
        y += D_L39_004B1600.dy;
    }
    ((void (*)(void *, f32, f32))p->w[10]->vt[0x28 / 4])(p->w[10], D_L39_004B1638.x, D_L39_004B1638.y);
    ((void (*)(void *, f32, f32))p->w[10]->vt[0x2C / 4])(p->w[10], D_L39_004B1638.w, D_L39_004B1638.h);
    ((void (*)(void *, s32, s32))p->w[10]->vt[0x4C / 4])(p->w[10], 0x40, 1);
    ((void (*)(void *, s32))p->w[10]->vt[0x40 / 4])(p->w[10], 1);
    ((void (*)(void *, s32, s32))p->w[10]->vt[0x1C / 4])(p->w[10], 1, 0);
    ((void (*)(void *, f32, f32))p->w[7]->vt[0x28 / 4])(p->w[7], D_L39_004B1600.x, y);
    ((void (*)(void *, f32, f32))p->w[7]->vt[0x2C / 4])(p->w[7], D_L39_004B1600.w, D_L39_004B1600.h);
    ((void (*)(void *, s32))p->w[7]->vt[0x40 / 4])(p->w[7], 1);
    ((void (*)(void *, s32, s32))p->w[7]->vt[0x4C / 4])(p->w[7], 0x40, 1);
    ((void (*)(void *, s32, s32))p->w[7]->vt[0x1C / 4])(p->w[7], 3, 0);
    func_L39_0068A6D0(p, 1, D_L39_004B1670.x, D_L39_004B1670.y, D_L39_004B1670.w, D_L39_004B1670.h, D_L39_004B1670.c);
    func_L39_006B7E68(D_L39_004B1690);
    func_L39_0068A6D0(p, 2, D_L39_004B16A0.x, D_L39_004B16A0.y, D_L39_004B16A0.w, D_L39_004B16A0.h, D_L39_004B16A0.c);
    ((void (*)(void *, f32, f32))p->w[8]->vt[0x28 / 4])(p->w[8], D_L39_004B16B8.x, D_L39_004B16B8.y);
    ((void (*)(void *, f32, f32))p->w[8]->vt[0x2C / 4])(p->w[8], D_L39_004B16B8.w, D_L39_004B16B8.h);
    ((void (*)(void *, s32, s32))p->w[8]->vt[0x4C / 4])(p->w[8], 0x40, 1);
    ((void (*)(void *, s32, s32))p->w[8]->vt[0x48 / 4])(p->w[8], 3, 3);
    ((void (*)(void *, s32))p->w[8]->vt[0x40 / 4])(p->w[8], 1);
    ((void (*)(void *, s32, s32))p->w[9]->vt[0x48 / 4])(p->w[9], 3, 3);
    ((void (*)(void *, f32, f32))p->w[9]->vt[0x28 / 4])(p->w[9], D_L39_004B16F0.x, D_L39_004B16F0.y);
    ((void (*)(void *, f32, f32))p->w[9]->vt[0x2C / 4])(p->w[9], D_L39_004B16F0.w, D_L39_004B16F0.h);
    ((void (*)(void *, s32, s32))p->w[9]->vt[0x4C / 4])(p->w[9], 0x40, 1);
    ((void (*)(void *, s32, s32))p->w[9]->vt[0x1C / 4])(p->w[9], 1, 0);
}
/* localdecomp:end func_L39_006B8698 */

INCLUDE_ASM("asm/levels", func_L39_006B8AC8);

/* localdecomp:start func_L39_006B8D48 */
s32 func_L39_006B8D48(void *object, u32 n) {
    if (n < 4) {
        return 0x1000;
    }
    if (n - 4 < 4) {
        return 0x4000;
    }
    return (n - 8 >= 4) ? 0x2000 : 0x8000;
}
/* localdecomp:end func_L39_006B8D48 */

INCLUDE_ASM("asm/levels", func_L39_006B8D88);

LINKER_REMNANT("asm/levels", func_L39_006B9000);

INCLUDE_ASM("asm/levels", func_L39_006B9008);

LINKER_REMNANT("asm/levels", func_L39_006B9F50);

/* localdecomp:start func_L39_006B9F58 */
extern u8 D_L39_0047E780[];
extern void func_L39_00688400(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_006B9F58(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047E780;
    func_L39_00688400(object, flags);
}
/* localdecomp:end func_L39_006B9F58 */

INCLUDE_ASM("asm/levels", func_L39_006B9F80);

/* localdecomp:start func_L39_006BA468 */
extern void func_L39_0068ADC8(void *);
extern void func_L39_006BA468(void *);

extern void func_L39_0067F168();
void func_L39_006BA468(void *p) {
    func_L39_0067F168(p);
    func_L39_0068ADC8(p);
}
/* localdecomp:end func_L39_006BA468 */

INCLUDE_ASM("asm/levels", func_L39_006BA498);
