#include "common.h"

INCLUDE_ASM("asm/levels", func_L30_0034EB98);

/* localdecomp:start func_L30_0034EDE0 */
typedef struct { u8 pad[0x10]; u8 x10[0x9A]; s16 xAA; } M_34EDE0;
typedef struct { u8 pad[0x10]; u8 x10[0x10]; } O_34EDE0;
__asm__(".extern D_L30_001DD5E8, 4");
__asm__(".extern D_L30_001DF2C0, 4");
extern f32 D_L30_001DD5E8;
extern s32 D_L30_001DF2C0;
extern M_34EDE0 *D_L30_001E1280[4] __attribute__((section(".sdata")));
extern s32 D_L30_001E1290[4] __attribute__((section(".sdata")));
extern M_34EDE0 *D_L30_001ED080[];
extern f32 func_0038CF00(void *, void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_003D4D00(s32, s32, f32, s32, s32);

M_34EDE0 *func_L30_0034EDE0(O_34EDE0 *o) {
    f32 best = D_L30_001DD5E8;
    M_34EDE0 *res = 0;
    s32 found = 0;
    s32 i;
    s32 j;
    s32 n;
    M_34EDE0 *m;

    for (i = 0; i < 4; i++) {
        if (D_L30_001E1280[i] != 0
            && func_0038CF00(o->x10, D_L30_001E1280[i]->x10) < best
            && D_L30_001E1290[i] >= D_L30_001DF2C0 - 10
            && func_003D3CB0(o->x10, D_L30_001E1280[i]->x10, 2, o, 0) == 0) {
            res = D_L30_001E1280[i];
            found = 1;
            best = func_0038CF00(o->x10, res->x10);
        }
    }
    if (found) {
        return res;
    }
    {
        n = func_003D4D00((s32)o->x10, 1, D_L30_001DD5E8, (s32)o, 0);
        for (j = 0; j < n; j++) {
            m = D_L30_001ED080[j];
            if (m != 0 && m->xAA == 0x1946
                && func_0038CF00(o->x10, m->x10) < best
                && func_003D3CB0(o->x10, m->x10, 2, o, 0) == 0) {
                res = m;
                best = func_0038CF00(o->x10, m->x10);
                found = 1;
            }
        }
    }
    return found ? res : 0;
}
/* localdecomp:end func_L30_0034EDE0 */

INCLUDE_ASM("asm/levels", func_L30_0034EFB8);

/* localdecomp:start func_L30_0034F1A8 */
#include "vu0.h"
typedef int u128_34F1A8 __attribute__((mode(TI)));
typedef struct { f32 x0; u8 pad4[4]; f32 x8; u8 padC[4]; s32 x10; f32 x14; s32 x18; f32 x1C; } V_34F1A8;
typedef struct { u8 pad[0x10]; u128_34F1A8 pos; u8 pad20[0x10]; u8 x30; u8 pad31[0x34 - 0x31]; u16 x34; u8 pad36[0x68 - 0x36]; V_34F1A8 *x68; u8 pad6C[0x98 - 0x6C]; s32 x98; } O_34F1A8;
__asm__(".extern D_L30_001DD5FC, 4");
__asm__(".extern D_L30_001DD608, 4");
__asm__(".extern D_L30_001DD614, 4");
__asm__(".extern D_L30_001DD618, 4");
extern f32 D_L30_001DD5FC;
extern s32 D_L30_001DD608;
extern f32 D_L30_001DD614;
extern f32 D_L30_001DD618;
extern u128_34F1A8 D_L30_001E9020_0034F1A8;
extern void *func_003C24B0_0034F1A8(s32, s32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_L30_0034DB30(O_34F1A8 *);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_004AA7E8(void *, s32);
extern void func_L01_004450F0(void *, s32, s32);

O_34F1A8 *func_L30_0034F1A8(u128_34F1A8 *pos, f32 ang) {
    O_34F1A8 *o = func_003C24B0_0034F1A8(0x1678, 0x80);
    V_34F1A8 *v;

    if (o == 0) {
        return 0;
    }
    o->pos = *pos;
    o->x30 = 255;
    v = o->x68;
    qzero(v);
    v->x0 = func_0038D098(ang) * D_L30_001DD614;
    v->x8 = (func_0038D0B0(ang) + D_L30_001DD618) * D_L30_001DD614;
    v->x10 = 0;
    v->x14 = ang;
    v->x18 = D_L30_001DD608;
    v->x1C = ang;
    if (func_L30_0034DB30(o) != 0) {
        o->pos = D_L30_001E9020_0034F1A8;
        v->x10++;
        func_003A52A0(0, 0, o);
        v->x0 *= -D_L30_001DD5FC;
    }
    o->x98 = 0;
    o->x34 = (o->x34 | 0x41) & ~0x1000;
    func_L01_004AA7E8(o, 1);
    func_L01_004450F0(o, 0, -1);
    return o;
}
/* localdecomp:end func_L30_0034F1A8 */

INCLUDE_ASM("asm/levels", func_L30_0034F2D8);

INCLUDE_ASM("asm/levels", func_L30_0034F5D8);

INCLUDE_ASM("asm/levels", func_L30_0034F998);

INCLUDE_ASM("asm/levels", func_L30_0034FC30);

INCLUDE_ASM("asm/levels", func_L30_0034FE30);

INCLUDE_ASM("asm/levels", func_L30_00350050);

/* localdecomp:start func_L30_003501B0 */
typedef struct { u8 pad[0x4]; s32 x4; f32 x8; f32 xC; u8 pad10[0x30 - 0x10]; u8 x30[1]; } V_3501B0;
typedef struct { u8 pad[0x10]; u8 x10[0x10]; u8 x20; u8 pad21[0x34 - 0x21]; u16 x34; u8 pad36[0x68 - 0x36]; V_3501B0 *x68; u8 pad6C[0x98 - 0x6C]; s32 x98; } O_3501B0;
typedef struct { u8 pad[0x20]; f32 x20; u8 pad24[4]; s32 x28; s32 x2C; } G_3501B0;
__asm__(".extern D_L30_001DD734, 4");
__asm__(".extern D_L30_001DD738, 4");
__asm__(".extern D_L30_001DD73C, 4");
__asm__(".extern D_L30_001DD740, 4");
__asm__(".extern D_L30_001DD754, 4");
__asm__(".extern D_L30_001DD758, 4");
extern f32 D_L30_001DD734;
extern f32 D_L30_001DD738;
extern f32 D_L30_001DD73C;
extern s32 D_L30_001DD740;
extern s32 D_L30_001DD754;
extern s32 D_L30_001DD758;
extern G_3501B0 D_L30_001E22C0;
extern void func_L30_003509A8(O_3501B0 *);
extern void func_L30_00350A30(O_3501B0 *);
extern s32 func_L30_0034D8D8(void *, f32);
extern void func_L30_00350970(u8 *);
extern s32 func_L01_004561B8(void *);
extern void func_L01_004AA7E8(void *, s32);
extern void func_L30_0034CB68(u8 *, void *, s32, s32, s32, s32, f32, f32);
extern void func_L30_00350690(O_3501B0 *);
extern s32 func_0038CAD0(void *);

void func_L30_003501B0(O_3501B0 *o) {
    V_3501B0 *v = o->x68;

    switch (o->x20) {
    case 0:
        func_L30_003509A8(o);
        func_L30_00350A30(o);
        if (func_L30_0034D8D8(o->x10, D_L30_001DD738) == 0) {
            func_L30_00350970((u8 *)o);
        }
        break;
    case 1:
        if (func_L01_004561B8(o) != 0) {
            o->x98 = 0;
            o->x34 = (o->x34 | 0x41) & ~0x1000;
            func_L01_004AA7E8(o, 1);
            v->x4 = D_L30_001DD740;
            func_L30_0034CB68((u8 *)o, v->x30, 0, -1, 0, 0, D_L30_001DD734, D_L30_001DD73C);
            D_L30_001E22C0.x20 = D_L30_001DD754;
            D_L30_001E22C0.x28 = D_L30_001DD758;
            D_L30_001E22C0.x2C = 0;
            v->x8 = v->xC = 0.0f;
        }
        func_L30_00350690(o);
        if (func_0038CAD0(&v->x4) != 0) {
            func_L30_00350970((u8 *)o);
        }
        break;
    }
}
/* localdecomp:end func_L30_003501B0 */

INCLUDE_ASM("asm/levels", func_L30_003502D0);

INCLUDE_ASM("asm/levels", func_L30_00350690);

/* localdecomp:start func_L30_00350970 */
extern void func_L30_0034DAC0(u8 *p);
extern void func_003C2880(u8 *p);

void func_L30_00350970(u8 *a) {
    func_L30_0034DAC0(*(u8 **)(a + 104) + 16);
    func_003C2880(a);
}
/* localdecomp:end func_L30_00350970 */

INCLUDE_ASM("asm/levels", func_L30_003509A8);

INCLUDE_ASM("asm/levels", func_L30_00350A30);

INCLUDE_ASM("asm/levels", func_L30_00350DB0);

INCLUDE_ASM("asm/levels", func_L30_00350EF0);

INCLUDE_ASM("asm/levels", func_L30_00350FA8);

INCLUDE_ASM("asm/levels", func_L30_003510C8);

/* localdecomp:start func_L30_003514D8 */
extern void func_003C2880(u8 *p);
typedef struct {
    u8 pad[0x80];
} S_1A30B0;

extern S_1A30B0 D_001A30B0[];
extern s32 D_001A71A0[];
extern void func_003A4F28(s32);

void func_L30_003514D8(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    s32 i = *(s32 *)(v + 0x20);

    if (i != -1) {
        u8 *p = (u8 *)&D_001A30B0[i];
        if (*(s32 *)(p + 0xDC) == D_001A71A0[0] && *(p + 0xD0) != 0) {
            func_003A4F28(i);
        }
    }
    *(s32 *)(v + 0x20) = -1;
    ((void (*)(void *))func_003C2880)(m);
}
/* localdecomp:end func_L30_003514D8 */

INCLUDE_ASM("asm/levels", func_L30_00351558);

INCLUDE_ASM("asm/levels", func_L30_003518F0);

/* localdecomp:start func_L30_00351CB0 */
typedef int u128_350DA0 __attribute__((mode(TI)));
typedef struct { u8 pad[0x18]; s32 x18; } V_350DA0;
typedef struct { u8 pad[0x10]; u128_350DA0 pos; u8 pad20[0x10]; u8 x30; u8 pad31[0x68 - 0x31]; V_350DA0 *x68; } O_350DA0;
extern O_350DA0 *func_003C24B0(s32, s32);
extern void func_L30_00350EF0(O_350DA0 *);
O_350DA0 *func_L30_00351CB0(O_350DA0 *a) {
    O_350DA0 *o = func_003C24B0(5951, 128);
    if (o != 0) {
        o->x30 = 255;
        o->x68->x18 = 0;
        o->pos = a->pos;
        func_L30_00350EF0(o);
    }
    return o;
}
/* localdecomp:end func_L30_00351CB0 */

INCLUDE_ASM("asm/levels", func_L30_00351D10);

INCLUDE_ASM("asm/levels", func_L30_00352050);

INCLUDE_ASM("asm/levels", func_L30_00352208);
