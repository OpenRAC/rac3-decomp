#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_00356588 */
void func_L01_004443E8(s32, s32, s32);
extern void func_003C2880(s32 p);

void func_L01_00356588(char *a0) {
    char *p = *(char **)(a0 + 0x68);
    if (*(s32 *)(p + 0x360)) {
        func_003C2880(*(s32 *)(p + 0x360));
        *(s32 *)(p + 0x360) = 0;
        *(s32 *)(p + 0x240) = 0;
    }
    func_L01_004443E8((s32)a0, 0, 3);
}
/* localdecomp:end func_L01_00356588 */

/* localdecomp:start func_L01_003565E0 */
extern void func_0038CAD0(void *);
extern void func_0038CB00(void *);
extern void func_L01_00451DF8(u8 *, void *, s32, s32, f32);
extern void func_L01_00404808(void (*)(void), s32);
extern void func_L01_00356BA8(void);

void func_L01_003565E0(u8 *self) {
    u8 *v = *(u8 **)(self + 104);

    func_0038CAD0(v + 752);
    func_0038CB00(v + 756);
    if (*(u16 *)(self + 150) < 0xFFFF) {
        *(u16 *)(self + 150) += 1;
    }
    func_L01_00451DF8(self, v + 608, 2, 1, 2.5f);
    if (*(s32 *)(v + 864) != 0) {
        func_L01_00404808(func_L01_00356BA8, *(s32 *)(v + 864));
    }
}
/* localdecomp:end func_L01_003565E0 */

/* localdecomp:start func_L01_00356668 */
extern u8 *D_L01_001E001C_6668;
__asm__(".extern D_L01_001E001C_6668, 16");
extern s32 D_001E0058_sda;
__asm__(".extern D_001E0058_sda, 4");
extern s16 *D_L01_0021DE20[];

typedef struct { u8 p0[0x68]; u8 *f68; } R;
void func_L01_00356668(u8 *a0) {
    s16 *q;
    if (a0[0x21] != 0xFF) {
        q = D_L01_0021DE20[a0[0x21]];
        while (a0[0x21] != 0xFF && a0[0x21] <= D_001E0058_sda && q != 0 && (q[-1] >= 0 || q == D_L01_0021DE20[a0[0x21]])) {
            R *r = (R *)(D_L01_001E001C_6668 + ((*(u16 *)q & 0x7FFF) << 8));
            s16 t, u;
            if (r == 0) break;
            t = *(s16 *)((u8 *)r + 0xAA);
            u = *(s16 *)(a0 + 0xAA);
            if (t == u || t == 0x16E5) {
                *(s32 *)(r->f68 + 0x2F8) = 1;
            } else if (t == 0x16BD) {
                *(s32 *)(r->f68 + 0x2E8) = 1;
            }
            q++;
        }
    }
}
/* localdecomp:end func_L01_00356668 */

INCLUDE_ASM("asm/levels", func_L01_00356748);

/* localdecomp:start func_L01_00356818 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) W4_356818;
typedef struct { char p0[0x10]; s32 f10; char p1[0x10]; f32 f24; char p2[0x1c]; u16 f44; } C_356818;
typedef struct Q_356818 { char p0[0x24]; C_356818 *f24; char p28[4]; f32 f2c; char p30[4]; u16 f34; char p36[0x32]; struct P_356818 *f68; char p6c[0x2c]; s32 f98; } Q_356818;
typedef struct { char p0[0x10]; W4_356818 f10; char p1[0xa0]; W4_356818 fC0; char p2[0x20]; W4_356818 fF0; } R_356818;
typedef struct P_356818 { char p0[0xF8]; s32 f0F8; s32 f0FC; s32 f100; char p1[0x14]; f32 f118; char p2[4]; f32 f120; char p3[0x24]; s32 f148; char p4[0x208]; s32 f354; f32 f358; Q_356818 *f35C; Q_356818 *f360; } P_356818;
extern f32 D_001DD5D0_sda; __asm__(".extern D_001DD5D0_sda, 4");
extern s32 D_001DD61C_sda; __asm__(".extern D_001DD61C_sda, 4");
extern f32 D_001DD5C0_sda; __asm__(".extern D_001DD5C0_sda, 4");
extern f32 D_001DD5C4_sda; __asm__(".extern D_001DD5C4_sda, 4");
extern f32 D_001DD5B4_sda; __asm__(".extern D_001DD5B4_sda, 4");
extern s32 D_001DD5B0_sda; __asm__(".extern D_001DD5B0_sda, 4");
extern void func_0040EB68(void *a, void *b);
extern void func_0044FD88(void *o, void *c, s32 a, s32 b);
extern void func_0040E3C0(f32 f, void *a, void *b);
extern void func_L01_004450F0(void *o, s32 a, s32 b);
extern void func_00444CB8(void *o, s32 a, s32 b);

void func_L01_00356818(Q_356818 *a0, W4_356818 *a1, f32 f, s32 a2) {
    W4_356818 v;
    P_356818 *p;
    qzero(&v);
    p = a0->f68;
    v.z = f;
    ((R_356818 *)a0)->f10 = *a1;
    ((R_356818 *)a0)->fF0 = v;
    func_0040EB68((char *)a0 + 0xC0, &v);
    a0->f34 = (a0->f34 & 0xFFBE);
    a0->f34 |= a0->f24->f44 & 0x1000;
    a0->f98 = a0->f24->f10;
    p->f358 = D_001DD5D0_sda;
    a0->f2c = a0->f24->f24 * p->f358;
    if (p->f360) {
        func_0044FD88(a0, p->f360, 1, D_001DD61C_sda);
        p->f360->f34 &= 0xFFBE;
        p->f360->f34 |= p->f360->f24->f44 & 0x1000;
        p->f360->f98 = p->f360->f24->f10;
        p->f360->f2c = p->f360->f24->f24 * p->f358;
    }
    p->f354 = a2;
    func_0040E3C0(D_001DD5C0_sda, (char *)p + 0x110, (char *)a0 + 0xC0);
    p->f120 = D_001DD5C0_sda;
    p->f118 = D_001DD5C4_sda;
    p->f148 = -1;
    p->f100 = 0;
    p->f0F8 = 0;
    p->f0FC = 0;
    qzero((char *)p + 0xC0);
    func_L01_004450F0(a0, 0x19, 4);
    func_00444CB8(a0, D_001DD5B0_sda, (s32)D_001DD5B4_sda);
}
/* localdecomp:end func_L01_00356818 */

/* localdecomp:start func_L01_00356990 */
/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */
void func_L01_00356990(char *a0) {
    *(int *)(*(char **)(a0 + 0x68) + 0x354) = 0;
}
/* localdecomp:end func_L01_00356990 */

INCLUDE_ASM("asm/levels", func_L01_003569A0);

/* localdecomp:start func_L01_00356A98 */
/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */
typedef struct { s32 w0; f32 f4; s32 w8; f32 fc; s32 w10; s32 w14; s32 w18; } SrcData;
typedef struct {
    u8 pad0[0x2e0]; s32 w2e0; f32 f2e4; s32 w2e8; f32 f2ec;
    u8 pad2f0[0x344 - 0x2f0]; s32 w344; s32 w348; s32 w34c; s32 w350;
} DstData;
typedef struct { s32 id; u8 pad4[0x74]; s32 w78; u8 pad7c[0x118 - 0x7c]; s32 w118; } Inner;
typedef struct { u8 pad0[8]; Inner *pad8; } Mid;
typedef struct { u8 pad0[8]; Inner *f8; u8 pad[0x68 - 0xc]; void *d68; } Obj;
typedef struct { u8 pad0[0x43]; u8 b43; } X;
extern struct { u8 pad0[8]; struct { u8 pad0[0x68]; Inner *i68; } *w8; } *func_L01_00449050(void *);
extern void func_003C3A10(void *, s32, s32, s32);
void func_L01_00356A98(void *a0, void *a1) {
    DstData *d = *(DstData **)((u8 *)a0 + 0x68);
    Inner *in = func_L01_00449050(a0)->w8->i68;
    SrcData *s = *(SrcData **)((u8 *)a1 + 0x68);
    d->w2e0 = s->w0;
    if (s->f4 > 0.0f) d->f2e4 = s->f4;
    d->w2e8 = s->w8;
    if (s->fc > 0.0f) d->f2ec = s->fc;
    d->w348 = s->w10;
    d->w34c = s->w18;
    if (in->id == 0x1ab4) d->w344 = in->w118;
    else d->w344 = -1;
    d->w350 = in->w78;
    if (((X *)a0)->b43 != 5) func_003C3A10(a0, 5, 0, 0);
}
/* localdecomp:end func_L01_00356A98 */

/* localdecomp:start func_L01_00356B70 */
f32 func_L01_00356B70(void) {
    return 0.45f;
}
/* localdecomp:end func_L01_00356B70 */
