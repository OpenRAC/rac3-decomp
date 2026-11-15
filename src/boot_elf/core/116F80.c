#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* localdecomp:start func_00116F80 */
extern void func_0011B240(s32);
extern void func_0013AFE8(s32) __attribute__((noreturn));
void func_00116F80(void) {
    while (1) {
        func_0011B240(6);
        func_0013AFE8(1);
    }
}
/* localdecomp:end func_00116F80 */

/* localdecomp:start func_00116F98 */
typedef struct Reent_116F98 {
    u8 pad0[0xC];
    void *err;
} Reent_116F98;
extern void *D_0013D770[];
extern char D_00150080[];
extern s32 func_00118950(void *, char *, ...);
extern void func_00116F80(void);

void func_00116F98(char *file, s32 line, char *expr) {
    func_00118950(((Reent_116F98 *)D_0013D770[0])->err, D_00150080, expr, file, line);
    func_00116F80();
}
/* localdecomp:end func_00116F98 */

LINKER_REMNANT("asm/boot_elf/remnants", func_00116FCC);

/* localdecomp:start func_00116FD0 */
typedef struct At_116FD0 {
    struct At_116FD0 *next;
    s32 ind;
    void (*fns[32])(void);
} At_116FD0;
typedef struct {
    u8 pad148[0x148];
    At_116FD0 *atexit;
    At_116FD0 atexit0;
} Reent_116FD0;
extern void *D_0013D770[];
extern void *func_001194E8(u32);
s32 func_00116FD0(void (*fn)(void)) {
    At_116FD0 *p;
    if ((p = ((Reent_116FD0 *)D_0013D770[0])->atexit) == 0) {
        ((Reent_116FD0 *)D_0013D770[0])->atexit = p = &((Reent_116FD0 *)D_0013D770[0])->atexit0;
    }
    if (p->ind >= 0x20) {
        if ((p = (At_116FD0 *)func_001194E8(0x88)) == 0) {
            return -1;
        }
        p->ind = 0;
        p->next = ((Reent_116FD0 *)D_0013D770[0])->atexit;
        ((Reent_116FD0 *)D_0013D770[0])->atexit = p;
    }
    p->fns[p->ind++] = fn;
    return 0;
}
/* localdecomp:end func_00116FD0 */

/* localdecomp:start func_00117070 */
extern long func_0011BFD8(s32, s32, s32);
s32 func_00117070(s32 a) {
    return func_0011BFD8(a, 0, 10);
}
/* localdecomp:end func_00117070 */

/* localdecomp:start func_00117098 */
extern s32 func_0011A160();
s32 func_00117098(s32 a, s32 b) {
    return func_0011A160(b, a);
}
/* localdecomp:end func_00117098 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001170B8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011716C);

/* localdecomp:start func_001171C8 */
typedef struct Bigint_1171C8 {
    struct Bigint_1171C8 *next;
    s32 k;
    s32 maxwds;
    s32 sign;
    s32 wds;
    u32 x[1];
} Bigint_1171C8;
extern s32 func_0011ABB8(Bigint_1171C8 *, Bigint_1171C8 *);

s32 func_001171C8(Bigint_1171C8 *b, Bigint_1171C8 *S)
{
    s32 n;
    s32 borrow, y;
    u32 carry, q, ys;
    u32 *bx, *bxe, *sx, *sxe;
    s32 z;
    u32 si, zs;

    n = S->wds;
    if (b->wds < n) {
        return 0;
    }
    sx = S->x;
    sxe = sx + --n;
    bx = b->x;
    bxe = bx + n;
    q = *bxe / (*sxe + 1);
    if (q) {
        borrow = 0;
        carry = 0;
        do {
            si = *sx++;
            ys = (si & 0xFFFF) * q + carry;
            zs = (si >> 16) * q + (ys >> 16);
            carry = zs >> 16;
            y = (*bx & 0xFFFF) - (ys & 0xFFFF) + borrow;
            borrow = y >> 16;
            z = (*bx >> 16) - (zs & 0xFFFF) + borrow;
            borrow = z >> 16;
            ((u16 *)bx)[1] = (u16)z;
            ((u16 *)bx)[0] = (u16)y;
            bx++;
        } while (sx <= sxe);
        if (!*bxe) {
            bx = b->x;
            while (--bxe > bx && !*bxe) {
                --n;
            }
            b->wds = n;
        }
    }
    if (func_0011ABB8(b, S) >= 0) {
        q++;
        borrow = 0;
        carry = 0;
        bx = b->x;
        sx = S->x;
        do {
            si = *sx++;
            ys = (si & 0xFFFF) + carry;
            zs = (si >> 16) + (ys >> 16);
            carry = zs >> 16;
            y = (*bx & 0xFFFF) - (ys & 0xFFFF) + borrow;
            borrow = y >> 16;
            z = (*bx >> 16) - (zs & 0xFFFF) + borrow;
            borrow = z >> 16;
            ((u16 *)bx)[1] = (u16)z;
            ((u16 *)bx)[0] = (u16)y;
            bx++;
        } while (sx <= sxe);
        bx = b->x;
        bxe = bx + n;
        if (!*bxe) {
            while (--bxe > bx && !*bxe) {
                --n;
            }
            b->wds = n;
        }
    }
    return q;
}
/* localdecomp:end func_001171C8 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001173F8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011865C);

/* localdecomp:start func_00118660 */
/* func_00118660: returns the global pointer stored at D_0013D770.
   Retail reaches D_0013D770 through lui/%lo, so the global is declared as an
   unsized array (never small data) and read at offset 0. */

extern void *D_0013D770[];

void *func_00118660(void) {
    return D_0013D770[0];
}
/* localdecomp:end func_00118660 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011866C);

LINKER_REMNANT("asm/boot_elf/remnants", func_0011871C);

/* localdecomp:start func_00118720 */
typedef struct Reent_00118720 {
    u8 pad0[0x38];
    void *cleanup;
} Reent_00118720;
typedef struct File_00118720 {
    u8 *p;
    s32 r;
    s32 w;
    s16 flags;
    s16 file;
    u8 *base;
    s32 size;
    s32 lbfsize;
    void *cookie;
    void *read;
    s32 (*write)(void *, u8 *, s32);
    void *seek;
    void *close;
    u8 pad30[0x24];
    Reent_00118720 *data;
} File_00118720;
extern void *D_0013D770[];
extern void func_001188C0(Reent_00118720 *);
extern s32 func_00119258(void *, void *);

s32 func_00118720(File_00118720 *fp)
{
    u8 *p;
    s32 n;
    s32 t;

    if (fp == 0) {
        return func_00119258(D_0013D770[0], func_00118720);
    }
    if (fp->data == 0) {
        fp->data = D_0013D770[0];
    }
    do {
        if (fp->data->cleanup == 0) {
            func_001188C0(fp->data);
        }
    } while (0);
    t = fp->flags;
    if ((t & 8) != 0) {
        p = fp->base;
        if (p != 0) {
            n = fp->p - p;
            fp->p = p;
            fp->w = (t & 3) ? 0 : fp->size;
            while (n > 0) {
                t = fp->write(fp->cookie, p, n);
                if (t <= 0) {
                    fp->flags |= 0x40;
                    return -1;
                }
                p += t;
                n -= t;
            }
        }
    }
    return 0;
}
/* localdecomp:end func_00118720 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00118834);

/* localdecomp:start func_00118838 */
typedef struct { u8 *p; s32 r; s32 w; s16 flags; s16 file; u8 *base; s32 size; s32 lbfsize; void *cookie; void *read; void *write; void *seek; void *close; u8 pad[0x24]; void *data; } F_118838;
extern s32 func_0011B378();
extern s32 func_0011B3E0();
extern s32 func_0011B460();
extern s32 func_0011B4C8();
void func_00118838(F_118838 *ptr, s32 flags, s32 file, void *data) {
    ptr->p = 0;
    ptr->r = 0;
    ptr->w = 0;
    ptr->flags = flags;
    ptr->file = file;
    ptr->base = 0;
    ptr->size = 0;
    ptr->lbfsize = 0;
    ptr->cookie = ptr;
    ptr->read = func_0011B378;
    ptr->write = func_0011B3E0;
    ptr->seek = func_0011B460;
    ptr->close = func_0011B4C8;
    ptr->data = data;
}
/* localdecomp:end func_00118838 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00118898);

LINKER_REMNANT("asm/boot_elf/remnants", func_001188B8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001188C0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011894C);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00118950);

LINKER_REMNANT("asm/boot_elf/remnants", func_001189A4);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001189B0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00118CA8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00118E14);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00118E18);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00118E74);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00118E78);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00119258);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001192EC);

LINKER_REMNANT("asm/boot_elf/remnants", func_00119308);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00119310);

LINKER_REMNANT("asm/boot_elf/remnants", func_0011932C);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00119330);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00119390);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001194E4);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001194E8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00119540);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00119588);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001197E0);

/* localdecomp:start func_00119F08 */
s32 func_00119F08(s32 r, s32 *pwc, u8 *s, u32 n) {
    s32 dummy;
    s32 ret = 0;
    if (pwc == 0) {
        pwc = &dummy;
    }
    if (s != 0) {
        ret = -1;
        if (n != 0) {
            *pwc = *s;
            ret = *s; ret = ret != 0;
        }
    }
    return ret;
}
/* localdecomp:end func_00119F08 */

ASM_FUNC("asm/boot_elf/handwritten", func_00119F3C);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011A01C);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011A0B0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011A160);

ASM_FUNC("asm/boot_elf/handwritten", func_0011A264);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011A324);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011A328);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011A3A8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011A3F4);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011A3F8);

/* localdecomp:start func_0011A4A0 */
typedef struct N_11A4A0 { struct N_11A4A0 *next; s32 idx; } N_11A4A0;
typedef struct { u8 pad[0x4C]; N_11A4A0 **tab; } S_11A4A0;
void func_0011A4A0(S_11A4A0 *p, N_11A4A0 *n) {
    if (n != 0) {
        N_11A4A0 **f = p->tab;
        n->next = f[n->idx];
        f[n->idx] = n;
    }
}
/* localdecomp:end func_0011A4A0 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011A4D0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011A5D8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011A658);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011A718);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011A750);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011A960);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011AA60);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011ABB8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011AC20);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011ADB0);

LINKER_REMNANT("asm/boot_elf/remnants", func_0011AF38);

LINKER_REMNANT("asm/boot_elf/remnants", func_0011AF40);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011AF48);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011AFB8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011B018);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011B060);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011B09C);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011B0A0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011B0F8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011B168);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011B240);

LINKER_REMNANT("asm/boot_elf/remnants", func_0011B260);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011B270);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011B2D0);

LINKER_REMNANT("asm/boot_elf/remnants", func_0011B2E4);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011B2E8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011B378);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011B3E0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011B460);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011B4C8);

ASM_FUNC("asm/boot_elf/handwritten", func_0011B4E4);

ASM_FUNC("asm/boot_elf/handwritten", func_0011B610);

ASM_FUNC("asm/boot_elf/handwritten", func_0011B754);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011B868);

ASM_FUNC("asm/boot_elf/handwritten", func_0011B9A0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011BB58);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011BD14);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011BD9C);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011BFD8);

LINKER_REMNANT("asm/boot_elf/remnants", func_0011C004);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011C008);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011C050);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011C108);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011C180);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011CD78);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011CDC0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011CE78);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011CEF0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011E560);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011E720);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011E7FC);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011E858);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011E860);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011E8C0);

ASM_FUNC("asm/boot_elf/handwritten", func_0011E9CC);
