#include "common.h"

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

INCLUDE_ASM("asm/levels", func_L01_00356818);

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
