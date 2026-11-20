#include "common.h"
#include "vu0.h"

typedef struct { u8 pad0[0x98]; s32 f98; } Slot_3626F0;

/* localdecomp:start func_L04_00362568 */
typedef struct {
    u8 pad0[0x47];
    u8 b47;
    u8 *p48;
} S_362568;
extern s32 D_001D545C_sda;
__asm__(".extern D_001D545C_sda, 4");
extern s32 D_L04_001D67AC_00362568;
__asm__(".extern D_L04_001D67AC_00362568, 4");
extern s32 D_L04_001D67AC;
__asm__(".extern D_L04_001D67AC, 16");
extern s32 D_L04_001D67B4_00362568;
__asm__(".extern D_L04_001D67B4_00362568, 4");
extern s32 D_L04_001D67B4;
__asm__(".extern D_L04_001D67B4, 16");
extern s32 D_L04_001D67C0_00362568;
__asm__(".extern D_L04_001D67C0_00362568, 4");
extern s32 D_L04_001D67C0;
__asm__(".extern D_L04_001D67C0, 16");
extern s32 D_L04_001DD6C8;
__asm__(".extern D_L04_001DD6C8, 4");
extern void func_L01_00459C50(s32);
extern void func_003C2880(s32);
extern void func_L01_004443E8(u8 *, s32, s32);
void func_L04_00362568(u8 *a0) {
    S_362568 *s = *(S_362568 **)(a0 + 0x68);
    if (s == 0) {
        return;
    }
    if (D_001D545C_sda == 4 && s->p48 != 0 && (*(s16 *)(s->p48 + 0xAA) == 0x185E || *(s16 *)(s->p48 + 0xAA) == 0x11C1)) {
        D_L04_001D67AC_00362568 = D_L04_001D67AC + 1;
        if (D_L04_001D67AC_00362568 >= 0x19) {
            func_L01_00459C50(6);
        }
    } else if (D_001D545C_sda == 0xC && s->p48 != 0 && s->b47 == 9) {
        D_L04_001D67B4_00362568 = D_L04_001D67B4 + 1;
        if (D_L04_001D67B4_00362568 >= 0x14) {
            func_L01_00459C50(0xF);
        }
    } else if (D_001D545C_sda == 0x12 && s->p48 != 0 && (*(s16 *)(s->p48 + 0xAA) == 0x185E || *(s16 *)(s->p48 + 0xAA) == 0x11C1)) {
        D_L04_001D67C0_00362568 = D_L04_001D67C0 + 1;
        if (D_L04_001D67C0_00362568 >= 0x14) {
            func_L01_00459C50(0x15);
        }
    }
    if (*(s32 *)((u8 *)s + 0x2FC) != 0) {
        func_003C2880(*(s32 *)((u8 *)s + 0x2FC));
        *(s32 *)((u8 *)s + 0x2FC) = 0;
        *(s32 *)((u8 *)s + 0x240) = 0;
    }
    if (*(s32 *)((u8 *)s + 0x4F8) != 0 && s->b47 == 0x6F) {
        D_L04_001DD6C8++;
        if (D_L04_001DD6C8 >= 10) {
            func_L01_00459C50(0xD);
        }
    }
    func_L01_004443E8(a0, 0, 3);
}
/* localdecomp:end func_L04_00362568 */

/* localdecomp:start func_L04_003626F0 */
extern void func_0038CAD0(void *p);
extern void func_0038CB00(void *p);
extern void func_003C7C38(void *p);
extern void func_L01_00451DF8(void *a, void *b, s32 c, s32 d, f32 e);
extern void func_L01_0044E850(void *a, void *b, s32 c, f32 d, f32 e);

void func_L04_003626F0(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    Slot_3626F0 **p = (Slot_3626F0 **)(s + 0x4B0);
    s32 i;
    func_0038CAD0(s + 0x2F0);
    func_0038CB00(s + 0x2F4);
    for (i = 7; i >= 0; i--) {
        if (*p != 0) {
            (*p)->f98 = 0;
            func_003C7C38(*p);
        }
        p++;
    }
    if (*(u16 *)(a0 + 0x96) < 0xFFFF) {
        *(u16 *)(a0 + 0x96) += 1;
    }
    func_L01_00451DF8(a0, s + 0x260, 2, 1, 2.5f);
    func_L01_0044E850(a0, s + 0x390, 1, 0.0432f, 0.43200004f);
}
/* localdecomp:end func_L04_003626F0 */

/* localdecomp:start func_L04_003627C8 */
extern u16 *D_L04_0021C9A0[];
extern u8 *D_L04_001DFD9C;
__asm__(".extern D_L04_001DFD9C, 16");
extern s32 D_L04_001DFDD8;
extern void func_L01_00445BE0(s32 a, s32 b);

void func_L04_003627C8(u8 *object) {
    u16 *p;
    u8 *e;
    s16 t;
    if (object[0x21] == 0xFF)
        return;
    func_L01_00445BE0(object[0x21], 0);
    p = D_L04_0021C9A0[object[0x21]];
    while (object[0x21] != 0xFF && object[0x21] <= D_L04_001DFDD8 && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L04_0021C9A0[object[0x21]])) {
        e = D_L04_001DFD9C + ((*p & 0x7FFF) << 8);
        if (e == 0)
            break;
        t = *(s16 *)(e + 0xAA);
        if (t == *(s16 *)(object + 0xAA))
            *(s32 *)(*(u8 **)(e + 0x68) + 0x2F8) = 1;
        else if (t == 0x16BD)
            *(s32 *)(*(u8 **)(e + 0x68) + 0x2E8) = 1;
        else if (t == 0x1B39)
            *(s32 *)(*(u8 **)(e + 0x68) + 0x3E4) = 1;
        p++;
    }
}
/* localdecomp:end func_L04_003627C8 */

/* localdecomp:start func_L04_003628D8 */
extern s32 D_L04_001DFDD8_003628D8;
__asm__(".extern D_L04_001DFDD8_003628D8, 16");

u8 *func_L04_003628D8(s32 n) {
    u16 *p;
    u8 *e;
    p = D_L04_0021C9A0[n];
    for (;;) {
        if ((n & 0xFF) == 0xFF) break;
        if (D_L04_001DFDD8_003628D8 < n) break;
        if (p == 0) break;
        if ((s16)p[-1] < 0 && p != D_L04_0021C9A0[n]) break;
        e = D_L04_001DFD9C + ((*p & 0x7FFF) << 8);
        if (e == 0)
            break;
        if (*(s16 *)(e + 0xAA) == 0x16E5 && e[0x20] == 0x1A)
            return e;
        p++;
    }
    return 0;
}
/* localdecomp:end func_L04_003628D8 */

/* localdecomp:start func_L04_003629A8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) W4_003629A8;
typedef struct { char p0[0x10]; s32 f10; char p1[0x10]; f32 f24; char p2[0x1c]; u16 f44; } C_003629A8;
typedef struct Q_003629A8 { char p0[0x20]; u8 f20; char p21[2]; u8 f23; C_003629A8 *f24; char p28[4]; f32 f2c; char p30[4]; u16 f34; char p36[0x32]; struct P_003629A8 *f68; char p6c[0x2c]; s32 f98; } Q_003629A8;
typedef struct { char p0[0x10]; W4_003629A8 f10; char p1[0xa0]; W4_003629A8 fC0; char p2[0x20]; W4_003629A8 fF0; } R_003629A8;
typedef struct P_003629A8 { char p0[0xC0]; W4_003629A8 fC0; char p1[0x28]; s32 f0F8; s32 f0FC; s32 f100; char p2[0x14]; f32 f118; char p3[4]; f32 f120; char p4[0x24]; s32 f148; char p5[0x1B0]; Q_003629A8 *f2FC; char p6[0x78]; s32 f378; f32 f37C; } P_003629A8;
__asm__(".extern D_L04_001DD750_003629A8, 4");
__asm__(".extern D_L04_001DD748_003629A8, 4");
__asm__(".extern D_L04_001DD74C_003629A8, 4");
__asm__(".extern D_L04_001DD760_003629A8, 4");
__asm__(".extern D_L04_001DD73C_003629A8, 4");
__asm__(".extern D_L04_001DD738_003629A8, 4");
extern f32 D_L04_001DD750_003629A8;
extern f32 D_L04_001DD748_003629A8;
extern f32 D_L04_001DD74C_003629A8;
extern f32 D_L04_001DD760_003629A8;
extern f32 D_L04_001DD73C_003629A8;
extern s32 D_L04_001DD738_003629A8;
extern void func_0038D308(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_0044FD88(void *, void *, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3938(void *, s32, s32);

void func_L04_003629A8(Q_003629A8 *a0, W4_003629A8 *a1, s32 a2, f32 f) {
    W4_003629A8 v;
    P_003629A8 *p;
    s32 c;
    qzero(&v);
    p = a0->f68;
    v.z = f;
    ((R_003629A8 *)a0)->f10 = *a1;
    ((R_003629A8 *)a0)->fF0 = v;
    func_0038D308((char *)a0 + 0xC0, &v);
    a0->f34 = (a0->f34 & 0xFFBE);
    a0->f34 |= a0->f24->f44 & 0x1000;
    a0->f98 = a0->f24->f10;
    p->f37C = D_L04_001DD750_003629A8;
    a0->f2c = a0->f24->f24 * p->f37C;
    if (p->f2FC) {
        func_L01_0044FD88(a0, p->f2FC, 0, 0);
        p->f2FC->f34 &= 0xFFBE;
        p->f2FC->f34 |= p->f2FC->f24->f44 & 0x1000;
        p->f2FC->f98 = p->f2FC->f24->f10;
        p->f2FC->f2c = p->f2FC->f24->f24 * p->f37C;
    }
    p->f378 = a2;
    func_0038CE20((char *)p + 0x110, (char *)a0 + 0xC0, D_L04_001DD748_003629A8 * 0.020000001f);
    p->f148 = -1;
    p->f100 = 0;
    p->f120 = D_L04_001DD748_003629A8 * 0.020000001f;
    p->f118 = D_L04_001DD74C_003629A8 * 0.020000001f;
    p->f0F8 = 0;
    p->f0FC = 0;
    qzero((char *)p + 0xC0);
    c = (s32)(D_L04_001DD760_003629A8 * 0.020000001f * 127.0f);
    a0->f34 |= 0x2800;
    a0->f23 = c;
    if (p->f2FC) {
        p->f2FC->f23 = c;
        p->f2FC->f34 |= 0x2800;
    }
    func_L01_004450F0(a0, 0x1B, 8);
    func_003C3938(a0, D_L04_001DD738_003629A8, (s32)D_L04_001DD73C_003629A8);
}
/* localdecomp:end func_L04_003629A8 */

/* localdecomp:start func_L04_00362B88 */
void func_L04_00362B88(void *arg0) {
    *(s32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x378) = 0;
}
/* localdecomp:end func_L04_00362B88 */

/* localdecomp:start func_L04_00362B98 */
extern u8 *func_L01_00449050(void *, void *);
extern void func_003C3A10(void *, s32, s32, s32);

void func_L04_00362B98(u8 *a0, u8 *a1) {
    u8 *v = *(u8 **)(a0 + 0x68);
    u8 *r = func_L01_00449050(a0, a1);
    u8 *c = *(u8 **)(a1 + 0x68);
    u8 *x = *(u8 **)(*(u8 **)(r + 8) + 0x68);
    f32 f;
    v[0x25D] = c[0x80];
    *(s32 *)(v + 0x2E0) = *(s32 *)(c + 0x0);
    f = *(f32 *)(c + 0x4);
    if (f > 0.0f) {
        *(f32 *)(v + 0x2E4) = f;
    }
    *(s32 *)(v + 0x2E8) = *(s32 *)(c + 0x8);
    f = *(f32 *)(c + 0xC);
    if (f > 0.0f) {
        *(f32 *)(v + 0x2EC) = f;
    }
    *(s32 *)(v + 0x300) = *(s32 *)(c + 0x14);
    *(s32 *)(v + 0x304) = *(s32 *)(c + 0x20);
    *(s32 *)(v + 0x38C) = *(s32 *)(c + 0x68);
    *(s32 *)(v + 0x308) = *(s32 *)(c + 0x24);
    *(s32 *)(v + 0x30C) = *(s32 *)(c + 0x10);
    *(s32 *)(v + 0x310) = *(s32 *)(c + 0x28);
    *(s32 *)(v + 0x314) = *(s32 *)(c + 0x2C);
    *(s32 *)(v + 0x318) = *(s32 *)(c + 0x1C);
    *(s32 *)(v + 0x31C) = *(s32 *)(c + 0x18);
    *(s32 *)(v + 0x4D0) = *(s32 *)(c + 0x74);
    *(s32 *)(v + 0x4D4) = *(s32 *)(c + 0x78);
    *(s32 *)(v + 0x500) = *(s32 *)(c + 0x88);
    *(s32 *)(v + 0x374) = *(s32 *)(x + 0x78);
    if (a0[0x43] != 0) {
        func_003C3A10(a0, 0, 0, 0);
    }
}
/* localdecomp:end func_L04_00362B98 */
