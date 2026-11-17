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

/* localdecomp:start func_L39_006B8AC8 */
typedef struct S_006B8AC8 {
    /* 0x000 */ s32 f0;
    /* 0x004 */ u8 pad4[0x19];
    /* 0x01D */ u8 f1D[0x20];
    /* 0x03D */ u8 f3D[0x10];
    /* 0x04D */ u8 f4D;
    /* 0x04E */ u8 f4E;
    /* 0x04F */ u8 f4F;
    /* 0x050 */ u8 f50;
    /* 0x051 */ u8 pad51[0x11F];
    /* 0x170 */ u8 f170;
    /* 0x171 */ u8 pad171;
    /* 0x172 */ s16 f172;
    /* 0x174 */ u8 pad174[0x7C];
} S_006B8AC8;

extern u8 D_L39_0037C848[];
extern s32 D_001DDA44_sda;
extern s32 D_001DDA4C_sda;
extern u8 *func_001206F4(u8 *, u8 *);

void func_L39_006B8AC8(void *p, s32 save) {
    S_006B8AC8 *e;
    void *o;
    s32 r;

    if (save == 0) {
        e = &((S_006B8AC8 *)D_L39_0037C848)[D_001DDA44_sda];
        o = *(void **)((u8 *)p + 0x110);
        ((void (*)(void *, u8 *))*(void **)(*(u8 **)((u8 *)o + 0x60) + 0xB8))(o, e->f1D);
        o = *(void **)((u8 *)p + 0x11C);
        ((void (*)(void *, u8 *))*(void **)(*(u8 **)((u8 *)o + 0x60) + 0xB8))(o, e->f3D);
        o = *(void **)((u8 *)p + 0x118);
        ((void (*)(void *, s32))*(void **)(*(u8 **)((u8 *)o + 0x60) + 0x60))(o, e->f50 & 1);
        o = *(void **)((u8 *)p + 0x120);
        ((void (*)(void *, s32))*(void **)(*(u8 **)((u8 *)o + 0x60) + 0x88))(o, e->f4D);
        o = *(void **)((u8 *)p + 0x124);
        ((void (*)(void *, s32))*(void **)(*(u8 **)((u8 *)o + 0x60) + 0x60))(o, e->f4F == 0);
        o = *(void **)((u8 *)p + 0x128);
        ((void (*)(void *, s32))*(void **)(*(u8 **)((u8 *)o + 0x60) + 0x88))(o, e->f0);
        o = *(void **)((u8 *)p + 0x138);
        ((void (*)(void *, s32))*(void **)(*(u8 **)((u8 *)o + 0x60) + 0xA8))(o, e->f172);
        o = *(void **)((u8 *)p + 0x130);
        ((void (*)(void *, s32))*(void **)(*(u8 **)((u8 *)o + 0x60) + 0x88))(o, e->f4E);
        D_001DDA4C_sda = e->f170;
    } else {
        o = *(void **)((u8 *)p + 0x110);
        func_001206F4(((S_006B8AC8 *)D_L39_0037C848)[D_001DDA44_sda].f1D, ((u8 *(*)(void *))*(void **)(*(u8 **)((u8 *)o + 0x60) + 0xC4))(o));
        o = *(void **)((u8 *)p + 0x11C);
        func_001206F4(((S_006B8AC8 *)D_L39_0037C848)[D_001DDA44_sda].f3D, ((u8 *(*)(void *))*(void **)(*(u8 **)((u8 *)o + 0x60) + 0xC4))(o));
        o = *(void **)((u8 *)p + 0x118);
        if (((s32 (*)(void *))*(void **)(*(u8 **)((u8 *)o + 0x60) + 0x64))(o)) {
            ((S_006B8AC8 *)D_L39_0037C848)[D_001DDA44_sda].f50 |= 1;
        } else {
            ((S_006B8AC8 *)D_L39_0037C848)[D_001DDA44_sda].f50 &= ~1;
        }
        o = *(void **)((u8 *)p + 0x120);
        ((S_006B8AC8 *)D_L39_0037C848)[D_001DDA44_sda].f4D = ((s32 (*)(void *))*(void **)(*(u8 **)((u8 *)o + 0x60) + 0x8C))(o);
        o = *(void **)((u8 *)p + 0x124);
        ((S_006B8AC8 *)D_L39_0037C848)[D_001DDA44_sda].f4F = ((s32 (*)(void *))*(void **)(*(u8 **)((u8 *)o + 0x60) + 0x64))(o) ^ 1;
        o = *(void **)((u8 *)p + 0x128);
        r = ((s32 (*)(void *))*(void **)(*(u8 **)((u8 *)o + 0x60) + 0x8C))(o);
        ((S_006B8AC8 *)D_L39_0037C848)[D_001DDA44_sda].f0 = r;
        ((S_006B8AC8 *)D_L39_0037C848)[D_001DDA44_sda].f170 = D_001DDA4C_sda;
        o = *(void **)((u8 *)p + 0x138);
        ((S_006B8AC8 *)D_L39_0037C848)[D_001DDA44_sda].f172 = ((s32 (*)(void *))*(void **)(*(u8 **)((u8 *)o + 0x60) + 0xAC))(o);
        o = *(void **)((u8 *)p + 0x130);
        ((S_006B8AC8 *)D_L39_0037C848)[D_001DDA44_sda].f4E = ((s32 (*)(void *))*(void **)(*(u8 **)((u8 *)o + 0x60) + 0x8C))(o);
    }
}
/* localdecomp:end func_L39_006B8AC8 */

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

/* localdecomp:start func_L39_006B8D88 */
extern s32 func_L39_006B8D48(void *, u32);
__asm__(".extern D_001DDA44_sda, 4");
extern s32 D_001DDA44_sda;
extern u8 D_L39_0037C848[];
extern u8 D_L39_0037C865[];
extern s32 func_00120884(u8 *);
extern u8 *func_001206F4(u8 *, u8 *);
__asm__(".extern D_L39_0024D760, 16");
__asm__(".extern D_L39_00241164, 16");
__asm__(".extern D_L39_00247914_6B8D88, 16");
extern u8 *D_L39_0024D760;
extern u8 *D_L39_00241164;
extern void *D_L39_00247914_6B8D88;
extern u8 D_L39_00249170[];
extern void func_L39_006DD5B8(void *, u8 *);
extern s32 func_00381FF0(s32);
extern s32 func_L39_006872E8(void *, s32, void *, s32, s32, f32);

void func_L39_006B8D88(void *p) {
    u8 buf[32];
    s32 n;
    s32 i;
    u32 h;
    u32 a;
    s32 sh;
    u32 mk;
    s32 r;
    u32 m;
    void *obj;
    u8 *rec;
    void *d;

    n = func_00120884(D_L39_0037C865 + D_001DDA44_sda * 0x1F0);
    if (n == 0) {
        return;
    }
    func_001206F4(buf, D_L39_0037C865 + D_001DDA44_sda * 0x1F0);
    func_L39_006DD5B8(*(void **)(D_L39_0024D760 + 0x54), buf);
    h = 0;
    for (i = 0; i < n; i++) {
        h += buf[i] * (i + 1);
    }
    a = h * 0xE1234567;
    h = h * 0xE76B492C;
    if (*(s32 *)((u8 *)p + 0x2B4) >= 0) {
        sh = *(s32 *)((u8 *)p + 0x2B4) * 4;
        mk = 0xF << sh;
        r = ((s32 (*)(void *, u32, s32))func_L39_006B8D48)(p, (h & mk) >> sh, 0);
        m = *(u32 *)(D_L39_00241164 + 0x1C4);
        if (m & r) {
            if (++*(s32 *)((u8 *)p + 0x2B4) == 8) {
                d = D_L39_00247914_6B8D88;
                func_L39_006872E8(d, func_00381FF0(0x1A5E), D_L39_00249170, 4, 0, 0.0f);
                rec = D_L39_0037C848 + D_001DDA44_sda * 0x1F0;
                rec[0x50] |= 0x80;
                obj = *(void **)((u8 *)p + 0x128);
                (*(void (**)(void *, s32))(*(u8 **)((u8 *)obj + 0x60) + 0x88))(obj, 0x15);
                *(s32 *)((u8 *)p + 0x2B4) = -2;
            }
        } else if (m & 0xF000) {
            *(s32 *)((u8 *)p + 0x2B4) = -1;
        }
    }
    if (*(s32 *)((u8 *)p + 0x2B8) >= 0) {
        sh = *(s32 *)((u8 *)p + 0x2B8) * 4;
        mk = 0xF << sh;
        r = ((s32 (*)(void *, u32, s32))func_L39_006B8D48)(p, (a & mk) >> sh, 0);
        m = *(u32 *)(D_L39_00241164 + 0x1C4);
        if (m & r) {
            if (++*(s32 *)((u8 *)p + 0x2B8) == 8) {
                d = D_L39_00247914_6B8D88;
                func_L39_006872E8(d, func_00381FF0(0x1A5D), D_L39_00249170, 4, 0, 0.0f);
                rec = D_L39_0037C848 + D_001DDA44_sda * 0x1F0;
                rec[0x50] |= 0x40;
                obj = *(void **)((u8 *)p + 0x128);
                (*(void (**)(void *, s32))(*(u8 **)((u8 *)obj + 0x60) + 0x88))(obj, 0x12);
                *(s32 *)((u8 *)p + 0x2B8) = -2;
            }
        } else if (m & 0xF000) {
            *(s32 *)((u8 *)p + 0x2B8) = -1;
        }
    }
}
/* localdecomp:end func_L39_006B8D88 */

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

/* localdecomp:start func_L39_006B9F80 */
/* vtable slot 0x1C is cast as returning s64 (result unused): that gives retail's $v0/$v1 in the
 * first loop's call. D_001FD638[i - 1].unk20 is what retail reads (-0x28 from the unk20 pointer). */
typedef struct S_006B9F80_W {
    u8 pad[0x60];
    void **vt;
} S_006B9F80_W;
typedef struct S_006B9F80 {
    u8 pad[0x110];
    S_006B9F80_W *w[27];
    u8 pad17C[0x2A8 - 0x17C];
    s32 unk2A8;
    s32 unk2AC;
    s32 unk2B0;
} S_006B9F80;
typedef struct S_006B9F80_E {
    u8 name[0x20];
    s32 unk20;
    s32 unk24;
} S_006B9F80_E;
extern S_006B9F80_E D_001FD638[];
extern f32 D_001DDC54_sda;
extern f32 D_001DDC58_sda;
extern f32 D_001DDC5C_sda;
extern f32 D_001DDC60_sda;
extern f32 D_001DDC64_sda;
extern f32 D_001DDC68_sda;
extern f32 D_001DDC6C_sda;
extern f32 D_001DDC70_sda;
extern f32 D_001DDC74_sda;
extern f32 D_001DDC80_sda;
extern f32 D_001DDC84_sda;
extern void func_L39_0067F100(s32);
extern void func_L39_0068A9B8(s32);
extern void func_L39_00689BD8(void *, s32);
extern void func_L39_00689D28(void *, s32);
extern void func_L39_00689DB8(void *, s32);
extern void func_L39_0068A6D0(void *, s32, f32, f32, f32, f32, s32);
extern void func_L39_0068A7B8(void *, s32, f32, f32, f32, f32, s32);
extern void func_L39_0068A4A8(void *, s32, s32, f32, f32, f32, f32, s32);
extern void func_L39_00689F00(void *, s32, s32, s32, f32, f32, f32, f32, f32, f32);
extern void func_L39_0068AAB8(void *);
extern void func_L39_0068B2F8(void *, s32, s32);
void func_L39_006B9F80(S_006B9F80 *p) {
    s32 i;
    s32 j;
    func_L39_0067F100(0x3E0000);
    func_L39_0068A9B8(0);
    func_L39_00689BD8(p, func_00381FF0(0x10ED));
    func_L39_00689D28(p, func_00381FF0(0x124));
    func_L39_00689DB8(p, func_00381FF0(0xCD5));
    func_L39_0068A6D0(p, 0, D_001DDC54_sda, D_001DDC58_sda, D_001DDC5C_sda, D_001DDC60_sda, 0x332299DE);
    func_L39_0068A6D0(p, 1, D_001DDC64_sda, D_001DDC68_sda, D_001DDC6C_sda, D_001DDC70_sda, 0x332299DE);
    func_L39_0068A7B8(p, 0, D_001DDC54_sda,
        D_001DDC58_sda + (D_001DDC60_sda - D_001DDC74_sda) * -5.0f / 12.0f,
        (D_001DDC58_sda + (D_001DDC60_sda - D_001DDC74_sda) * 5.5f / 12.0f) -
            (D_001DDC58_sda + (D_001DDC60_sda - D_001DDC74_sda) * -5.5f / 12.0f),
        D_001DDC5C_sda - D_001DDC74_sda, 0x332299DE);
    func_L39_0068A4A8(p, 0, 10, D_001DDC64_sda,
        D_001DDC68_sda + (D_001DDC70_sda - D_001DDC74_sda) * -4.5f / 11.0f,
        (D_001DDC68_sda + (D_001DDC70_sda - D_001DDC74_sda) * -4.0f / 11.0f) -
            (D_001DDC68_sda + (D_001DDC70_sda - D_001DDC74_sda) * -5.0f / 11.0f),
        D_001DDC6C_sda - D_001DDC74_sda * 2.0f, 0x332299DE);
    func_L39_00689F00(p, 0, 3, 3, 2.0f, 2.0f, D_001DDC5C_sda - D_001DDC74_sda, D_001DDC80_sda, D_001DDC84_sda, 1.0f);
    func_L39_0068AAB8(p);
    p->unk2A8 = 0;
    p->unk2AC = -1;
    p->unk2B0 = -1;
    for (i = 0, j = 1; i < 11; i++, j++) {
        ((void (*)(void *, s32, f32, f32))p->w[j]->vt[0x44 / 4])(p->w[j], 1, D_001DDC5C_sda - D_001DDC74_sda * 2.0f, 0.0f);
        ((void (*)(void *, s32))p->w[j]->vt[0x40 / 4])(p->w[j], 1);
        ((void (*)(void *, u8 *))p->w[j]->vt[0x24 / 4])(p->w[j], D_001FD638[i].name);
        ((s64 (*)(void *, s32, s32))p->w[j]->vt[0x1C / 4])(p->w[j], D_001FD638[i - 1].unk20 < 0 ? 0 : 3, 0);
        ((void (*)(void *, s32, s32))p->w[j]->vt[0x48 / 4])(p->w[j], 1, 3);
        if (D_001FD638[i].unk20 >= 0) {
            p->unk2A8++;
        }
    }
    if (p->unk2A8 > 0) {
        func_L39_0068B2F8(p, 1, 0);
    }
    func_L39_0068A4A8(p, 1, p->unk2A8 < 11 ? p->unk2A8 : 10, D_001DDC54_sda,
        D_001DDC58_sda + (D_001DDC60_sda - D_001DDC74_sda) * -4.0f / 12.0f,
        (D_001DDC58_sda + (D_001DDC60_sda - D_001DDC74_sda) * -4.5f / 12.0f) -
            (D_001DDC58_sda + (D_001DDC60_sda - D_001DDC74_sda) * -5.5f / 12.0f),
        D_001DDC5C_sda - D_001DDC74_sda, 0x331465B7);
    ((void (*)(void *, s32, s32))p->w[0]->vt[0x4C / 4])(p->w[0], 0x40, 1);
    ((void (*)(void *, s32, f32, f32))p->w[0]->vt[0x44 / 4])(p->w[0], 1, D_001DDC5C_sda - D_001DDC74_sda * 2.0f, 0.0f);
    ((void (*)(void *, s32))p->w[0]->vt[0x40 / 4])(p->w[0], 0);
    ((s64 (*)(void *, s32, s32))p->w[0]->vt[0x1C / 4])(p->w[0], 1, 0);
    for (j = 0; j < 11; j++) {
        ((void (*)(void *, s32))p->w[j + 12]->vt[0x40 / 4])(p->w[j + 12], 1);
        ((void (*)(void *, s32, s32))p->w[j + 12]->vt[0x4C / 4])(p->w[j + 12], 0x40, 1);
        ((s64 (*)(void *, s32, s32))p->w[j + 12]->vt[0x1C / 4])(p->w[j + 12], 1, 0);
        ((void (*)(void *))p->w[j + 12]->vt[0xB4 / 4])(p->w[j + 12]);
    }
    ((s64 (*)(void *, s32, s32))p->w[23]->vt[0x1C / 4])(p->w[23], 0, 0);
    ((s64 (*)(void *, s32, s32))p->w[24]->vt[0x1C / 4])(p->w[24], 0, 0);
    ((s64 (*)(void *, s32, s32))p->w[25]->vt[0x1C / 4])(p->w[25], 0, 0);
    ((s64 (*)(void *, s32, s32))p->w[26]->vt[0x1C / 4])(p->w[26], 0, 0);
}
/* localdecomp:end func_L39_006B9F80 */

/* localdecomp:start func_L39_006BA468 */
extern void func_L39_0068ADC8(void *);
extern void func_L39_006BA468(void *);

extern void func_L39_0067F168();
void func_L39_006BA468(void *p) {
    func_L39_0067F168(p);
    func_L39_0068ADC8(p);
}
/* localdecomp:end func_L39_006BA468 */

/* localdecomp:start func_L39_006BA498 */
typedef struct S_006BA498_e S_006BA498_e;
typedef struct {
    u8 pad[0x30];
    void (*f30)(S_006BA498_e *, f32 *, f32 *);
} S_006BA498_vt;
struct S_006BA498_e {
    u8 pad[0x60];
    S_006BA498_vt *f60;
};
typedef struct {
    s32 w0;
    u8 pad[0x24];
} S_006BA498_rec;

typedef struct {
    u8 pad[0x110];
    S_006BA498_e *w[11];
} S_006BA498_o;
extern S_006BA498_rec D_001FD630[];
typedef struct {
    u8 pad0[0xD0];
    void *fD0;
    u8 padD4[0x284 - 0xD4];
    s32 f284;
} G_006BA498;
__asm__(".extern D_L39_00247914, 16");
extern G_006BA498 *D_L39_00247914;
extern f32 D_001DDC54_sda;
extern void func_L39_006BA5C0(void *, s32);
extern void func_L39_006B5288(void *arg0, s32 arg1, s8 arg2);
extern s32 func_L39_0068AEF8(void *, s32);
void func_L39_0068A2D0(void *, s32, s32, s32, f32, f32);

s32 func_L39_006BA498(u8 *obj, s32 arg1)
{
    s32 r;
    s32 x;
    s32 i;
    s32 mode;
    f32 v[2];

    func_L39_006BA5C0(obj, arg1);
    if (arg1 == 7) {
        x = *(s32 *)(obj + 0x290);
        if ((u32)(x - 1) < 11) {
            i = x - 1;
            func_L39_006B5288(D_L39_00247914->fD0, D_001FD630[i].w0, 1);
            D_L39_00247914->f284 = 0x1B;
            return 1;
        }
    }
    r = func_L39_0068AEF8(obj, arg1);
    if (*(s32 *)(obj + 0x2A8) > 0) {
        i = *(s32 *)(obj + 0x290);
        if (i >= 0) {
            S_006BA498_e *e = ((S_006BA498_o *)obj)->w[i];
            e->f60->f30(e, &v[0], &v[1]);
            mode = *(s32 *)(obj + 0x290) >= 2;
            if (*(s32 *)(obj + 0x290) < *(s32 *)(obj + 0x2A8)) {
                mode |= 2;
            }
            {
                f32 y = v[1];
                func_L39_0068A2D0(obj, mode, 3, 3, D_001DDC54_sda, y);
            }
        }
    }
    return r;
}
/* localdecomp:end func_L39_006BA498 */
