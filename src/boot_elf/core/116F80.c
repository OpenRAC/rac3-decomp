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

/* localdecomp:start func_00118898 */
extern s32 func_00118720(File_00118720 *);
void func_00118898(void *ptr) {
    func_00119258(ptr, func_00118720);
}
/* localdecomp:end func_00118898 */

LINKER_REMNANT("asm/boot_elf/remnants", func_001188B8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001188C0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011894C);

/* localdecomp:start func_00118950 */
extern s32 func_0011C108();
s32 func_00118950(void *fp, char *fmt, ...) {
    return func_0011C108(fp, fmt, (char *)__builtin_next_arg(fmt) - 0x30);
}
/* localdecomp:end func_00118950 */

LINKER_REMNANT("asm/boot_elf/remnants", func_001189A4);

/* localdecomp:start func_001189B0 */
typedef struct Chunk_001189B0 {
    u32 prev_size;
    u32 size;
    struct Chunk_001189B0 *fd;
    struct Chunk_001189B0 *bk;
} Chunk_001189B0;
extern Chunk_001189B0 *D_0013D778[];
extern unsigned long D_0013DB80;
extern unsigned long D_0013DB88;
extern void func_0011A328(void *);
extern void func_0011A3A8(void *);
extern void func_00118CA8(void *, u32);

void func_001189B0(void *reent, void *mem)
{
    Chunk_001189B0 *p;
    u32 hd;
    u32 sz;
    s32 idx;
    Chunk_001189B0 *next;
    u32 nextsz;
    u32 prevsz;
    Chunk_001189B0 *bck;
    Chunk_001189B0 *fwd;
    s32 islr;

    if (mem == 0) {
        return;
    }
    func_0011A328(reent);
    p = (Chunk_001189B0 *)((char *)mem - 8);
    hd = p->size;
    sz = hd & ~1;
    next = (Chunk_001189B0 *)((char *)p + sz);
    nextsz = next->size & ~3;
    if (next == D_0013D778[2]) {
        sz += nextsz;
        if (!(hd & 1)) {
            prevsz = p->prev_size;
            p = (Chunk_001189B0 *)((char *)p - prevsz);
            sz += prevsz;
            bck = p->bk;
            fwd = p->fd;
            fwd->bk = bck;
            bck->fd = fwd;
        }
        p->size = sz | 1;
        D_0013D778[2] = p;
        if ((unsigned long)sz >= D_0013DB80) {
            func_00118CA8(reent, D_0013DB88);
        }
        func_0011A3A8(reent);
        return;
    }
    next->size = nextsz;
    islr = 0;
    if (!(hd & 1)) {
        prevsz = p->prev_size;
        p = (Chunk_001189B0 *)((char *)p - prevsz);
        sz += prevsz;
        if (p->fd == (Chunk_001189B0 *)((char *)&D_0013D778[4] - 8)) {
            islr = 1;
        } else {
            bck = p->bk;
            fwd = p->fd;
            fwd->bk = bck;
            bck->fd = fwd;
        }
    }
    if (!(((Chunk_001189B0 *)((char *)next + nextsz))->size & 1)) {
        sz += nextsz;
        if (!islr && next->fd == (Chunk_001189B0 *)((char *)&D_0013D778[4] - 8)) {
            Chunk_001189B0 *lr = (Chunk_001189B0 *)((char *)&D_0013D778[4] - 8);
            islr = 1;
            lr->fd = lr->bk = p;
            p->fd = p->bk = lr;
        } else {
            bck = next->bk;
            fwd = next->fd;
            fwd->bk = bck;
            bck->fd = fwd;
        }
    }
    p->size = sz | 1;
    ((Chunk_001189B0 *)((char *)p + sz))->prev_size = sz;
    if (!islr) {
        if (sz < 512) {
            idx = (unsigned long)sz >> 3;
            ((Chunk_001189B0 *)D_0013D778)->size |= (unsigned long)1 << (idx / 4);
            bck = (Chunk_001189B0 *)((char *)&D_0013D778[2 * idx + 2] - 8);
            fwd = bck->fd;
            p->bk = bck;
            p->fd = fwd;
            bck->fd = p;
            fwd->bk = p;
        } else {
            idx = ((unsigned long)sz >> 9) == 0 ? (unsigned long)sz >> 3
                : ((unsigned long)sz >> 9) <= 4 ? 56 + ((unsigned long)sz >> 6)
                : ((unsigned long)sz >> 9) <= 20 ? 91 + ((unsigned long)sz >> 9)
                : ((unsigned long)sz >> 9) <= 84 ? 110 + ((unsigned long)sz >> 12)
                : ((unsigned long)sz >> 9) <= 340 ? 119 + ((unsigned long)sz >> 15)
                : ((unsigned long)sz >> 9) <= 1364 ? 124 + ((unsigned long)sz >> 18)
                : 126;
            bck = (Chunk_001189B0 *)((char *)&D_0013D778[2 * idx + 2] - 8);
            fwd = bck->fd;
            if (fwd == bck) {
                ((Chunk_001189B0 *)D_0013D778)->size |= (unsigned long)1 << (idx / 4);
            } else {
                while (fwd != bck && sz < (fwd->size & ~3)) {
                    fwd = fwd->fd;
                }
                bck = fwd->bk;
            }
            p->bk = bck;
            p->fd = fwd;
            bck->fd = p;
            fwd->bk = p;
        }
    }
    func_0011A3A8(reent);
}
/* localdecomp:end func_001189B0 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00118CA8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00118E14);

/* localdecomp:start func_00118E18 */
extern s32 func_0011F5A8();
extern s32 D_1D48C0[];
s32 func_00118E18(s32 *p, s32 a, void *b) {
    s32 ret;
    D_1D48C0[0] = 0;
    ret = func_0011F5A8(a, b);
    if (ret == -1 && D_1D48C0[0] != 0) {
        *p = D_1D48C0[0];
    }
    return ret;
}
/* localdecomp:end func_00118E18 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00118E74);

/* localdecomp:start func_00118E78 */
typedef struct {
    u8 *base;
    u32 len;
} Iov_118E78;
typedef struct {
    Iov_118E78 *iov;
    s32 iovcnt;
    s32 resid;
} Uio_118E78;
typedef struct {
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
} F_118E78;
extern s32 func_0011E8C0(F_118E78 *);
extern u8 *func_00119F3C(u8 *, s32, u32);

s32 func_00118E78(F_118E78 *fp, Uio_118E78 *uio) {
    u32 len;
    u8 *p;
    Iov_118E78 *iov;
    s32 w;
    s32 s;
    u8 *nl;
    s32 nlknown;
    s32 nldist;

    if ((len = uio->resid) == 0) {
        return 0;
    }
    if ((((fp->flags & 8) == 0) || (fp->base == 0)) && func_0011E8C0(fp)) {
        return -1;
    }
    iov = uio->iov;
    len = 0;
    if (fp->flags & 2) {
        do {
            while (len == 0) {
                p = iov->base;
                len = iov->len;
                iov++;
            }
            w = fp->write(fp->cookie, p, len < 0x400 ? len : 0x400);
            if (w <= 0) {
                goto err;
            }
            p += w;
            len -= w;
        } while ((uio->resid -= w) != 0);
    } else if ((fp->flags & 1) == 0) {
        do {
            while (len == 0) {
                p = iov->base;
                len = iov->len;
                iov++;
            }
            w = fp->w;
            if (fp->flags & 0x200) {
                if (len < w) {
                    w = len;
                }
                func_0011A160(fp->p, p, w);
                fp->w -= w;
                fp->p += w;
                w = len;
            } else if (fp->p > fp->base && len > w) {
                func_0011A160(fp->p, p, w);
                fp->p += w;
                if (func_00118720((File_00118720 *)fp)) {
                    goto err;
                }
            } else if (len >= (w = fp->size)) {
                w = fp->write(fp->cookie, p, w);
                if (w <= 0) {
                    goto err;
                }
            } else {
                w = len;
                func_0011A160(fp->p, p, w);
                fp->w -= w;
                fp->p += w;
            }
            p += w;
            len -= w;
        } while ((uio->resid -= w) != 0);
    } else {
        nlknown = 0;
        do {
            while (len == 0) {
                nlknown = 0;
                p = iov->base;
                len = iov->len;
                iov++;
            }
            if (!nlknown) {
                nl = func_00119F3C(p, '\n', len);
                nldist = nl ? nl + 1 - p : len + 1;
                nlknown = 1;
            }
            s = len < nldist ? len : nldist;
            w = fp->w + fp->size;
            if (fp->p > fp->base && s > w) {
                func_0011A160(fp->p, p, w);
                fp->p += w;
                if (func_00118720((File_00118720 *)fp)) {
                    goto err;
                }
            } else if (s >= (w = fp->size)) {
                w = fp->write(fp->cookie, p, w);
                if (w <= 0) {
                    goto err;
                }
            } else {
                w = s;
                func_0011A160(fp->p, p, w);
                fp->w -= w;
                fp->p += w;
            }
            if ((nldist -= w) == 0) {
                if (func_00118720((File_00118720 *)fp)) {
                    goto err;
                }
                nlknown = 0;
            }
            p += w;
            len -= w;
        } while ((uio->resid -= w) != 0);
    }
    return 0;
err:
    fp->flags |= 0x40;
    return -1;
}
/* localdecomp:end func_00118E78 */

/* localdecomp:start func_00119258 */
typedef struct {
    u8 pad0[0xC];
    s16 flags;
    u8 padE[0x58 - 0xE];
} F_119258;
typedef struct G_119258 {
    struct G_119258 *next;
    s32 niobs;
    F_119258 *iobs;
} G_119258;
typedef struct {
    u8 pad0[0x1D8];
    G_119258 glue;
} R_119258;
s32 func_00119258(void *p, void *f) {
    R_119258 *ptr = p;
    s32 (*function)(F_119258 *) = (s32 (*)(F_119258 *))f;
    F_119258 *fp;
    s32 n;
    s32 ret = 0;
    G_119258 *g;
    for (g = &ptr->glue; g != 0; g = g->next) {
        for (fp = g->iobs, n = g->niobs; --n >= 0; fp++) {
            if (fp->flags != 0) {
                ret |= (*function)(fp);
            }
        }
    }
    return ret;
}
/* localdecomp:end func_00119258 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001192EC);

LINKER_REMNANT("asm/boot_elf/remnants", func_00119308);

/* localdecomp:start func_00119310 */
extern void *D_0013D770[];
extern void *func_001192F8(void *);
void *func_00119310(void) {
    return func_001192F8(D_0013D770[0]);
}
/* localdecomp:end func_00119310 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0011932C);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00119330);

/* localdecomp:start func_00119390 */
extern s32 func_0011B460();
typedef struct {
    u8 pad0[0x3C];
    void *cleanup;
} R_119390;
typedef struct {
    u8 *p;
    s32 r;
    s32 w;
    u16 flags;
    s16 file;
    u8 *base;
    s32 size;
    s32 lbfsize;
    void *cookie;
    void *read;
    void *write;
    void *seek;
    void *close;
    u8 pad30[0x40 - 0x30];
    u8 ubuf[3];
    u8 nbuf[1];
    u8 pad44[0x4C - 0x44];
    s32 blksize;
    s32 offset;
    R_119390 *data;
} F_119390;
typedef struct {
    s16 st_dev;
    u16 st_ino;
    u32 st_mode;
    u8 rest[0x70 - 8];
} St_119390;
extern s32 func_00118E18();
extern void *func_001197E0();
extern void func_00118898();
extern s32 func_0011F5A0();

void func_00119390(F_119390 *fp)
{
    St_119390 st;
    s32 size;
    s32 couldbetty;
    u8 *p;

    if (fp->flags & 2) {
        fp->base = fp->p = fp->nbuf;
        fp->size = 1;
        return;
    }
    if (fp->file < 0 || func_00118E18(fp->data, fp->file, &st) < 0) {
        couldbetty = 0;
        size = 0x400;
        fp->flags |= 0x800;
    } else {
        couldbetty = (st.st_mode & 0xF000) == 0x2000;
        size = 0x400;
        if ((st.st_mode & 0xF000) == 0x8000 && fp->seek == (void *)func_0011B460) {
            fp->flags |= 0x400;
            fp->blksize = size;
        } else {
            fp->flags |= 0x800;
        }
    }
    p = func_001197E0(fp->data, size);
    if (p == 0) {
        fp->flags |= 2;
        fp->base = fp->p = fp->nbuf;
        fp->size = 1;
    } else {
        fp->data->cleanup = func_00118898;
        fp->flags |= 0x80;
        fp->base = fp->p = p;
        fp->size = size;
        if (couldbetty && func_0011F5A0(fp->file)) {
            fp->flags |= 1;
        }
    }
}
/* localdecomp:end func_00119390 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001194E4);

/* localdecomp:start func_001194E8 */
extern void *D_0013D770[];
extern void func_0011A328(void *);
extern void *func_001197E0(void *, u32);
extern void func_0011A3A8(void *);
void *func_001194E8(u32 n) {
    void *r;
    func_0011A328(D_0013D770[0]);
    r = func_001197E0(D_0013D770[0], n);
    func_0011A3A8(D_0013D770[0]);
    return r;
}
/* localdecomp:end func_001194E8 */

/* localdecomp:start func_00119540 */
extern void func_0011A328();
extern void func_001189B0();
extern void func_0011A3A8();

void func_00119540(void *fp)
{
    func_0011A328(D_0013D770[0]);
    func_001189B0(D_0013D770[0], fp);
    func_0011A3A8(D_0013D770[0]);
}
/* localdecomp:end func_00119540 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00119588);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001197E0);

/* localdecomp:start func_00119F08 */
s32 func_00119F08(s32 r, s32 *pwc, u8 *s, u32 n, s32 *state) {
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

/* localdecomp:start func_0011A328 */
extern s32 D_0013DBD0;
extern s32 D_0013DBD4;
extern s32 D_0013E310;
extern s32 func_0011ED10(void);
extern void func_0011EE60(s32);
void func_0011A328(void *ptr) {
    s32 tid = func_0011ED10();
    if (D_0013DBD0 == tid) {
        D_0013DBD4 = D_0013DBD4 + 1;
    } else {
        func_0011EE60(D_0013E310);
        D_0013DBD0 = tid;
        D_0013DBD4 = D_0013DBD4 + 1;
    }
}
/* localdecomp:end func_0011A328 */

/* localdecomp:start func_0011A3A8 */
extern s32 D_0013DBD0;
extern s32 D_0013DBD4;
extern s32 D_0013E310;
extern void func_0011EE40(s32);
void func_0011A3A8(void *ptr) {
    D_0013DBD4 = D_0013DBD4 - 1;
    if (D_0013DBD4 == 0) {
        D_0013DBD0 = -1;
        func_0011EE40(D_0013E310);
    }
}
/* localdecomp:end func_0011A3A8 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011A3F4);

/* localdecomp:start func_0011A3F8 */
typedef struct Big_11A3F8 {
    struct Big_11A3F8 *next;
    s32 k;
    s32 maxwds;
    s32 sign;
    s32 wds;
    u32 x[1];
} Big_11A3F8;
typedef struct {
    u8 pad[0x4C];
    Big_11A3F8 **freelist;
} Reent_11A3F8;
extern void *func_001170B8();
void *func_0011A3F8(Reent_11A3F8 *ptr, s32 k) {
    s32 x;
    Big_11A3F8 *rv;
    if (ptr->freelist == 0) {
        ptr->freelist = (Big_11A3F8 **)func_001170B8(ptr, 4, 16);
        if (ptr->freelist == 0) {
            return 0;
        }
    }
    if ((rv = ptr->freelist[k]) != 0) {
        ptr->freelist[k] = rv->next;
    } else {
        x = 1 << k;
        rv = (Big_11A3F8 *)func_001170B8(ptr, 1, 0x18 + (x - 1) * 4);
        if (rv == 0) {
            return 0;
        }
        rv->k = k;
        rv->maxwds = x;
    }
    rv->sign = rv->wds = 0;
    return rv;
}
/* localdecomp:end func_0011A3F8 */

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

/* localdecomp:start func_0011A5D8 */
s32 func_0011A5D8(u32 x)
{
    s32 k = 0;

    if (!(x & 0xffff0000)) {
        k = 16;
        x <<= 16;
    }
    if (!(x & 0xff000000)) {
        k += 8;
        x <<= 8;
    }
    if (!(x & 0xf0000000)) {
        k += 4;
        x <<= 4;
    }
    if (!(x & 0xc0000000)) {
        k += 2;
        x <<= 2;
    }
    if (!(x & 0x80000000)) {
        k++;
        if (!(x & 0x40000000)) {
            return 32;
        }
    }
    return k;
}
/* localdecomp:end func_0011A5D8 */

/* localdecomp:start func_0011A658 */
s32 func_0011A658(u32 *y) {
    s32 k;
    u32 x = *y;
    if (x & 7) {
        if (x & 1) {
            return 0;
        }
        if (x & 2) {
            *y = x >> 1;
            return 1;
        }
        *y = x >> 2;
        return 2;
    }
    k = 0;
    if (!(x & 0xffff)) {
        k = 16;
        x >>= 16;
    }
    if (!(x & 0xff)) {
        k += 8;
        x >>= 8;
    }
    if (!(x & 0xf)) {
        k += 4;
        x >>= 4;
    }
    if (!(x & 0x3)) {
        k += 2;
        x >>= 2;
    }
    if (!(x & 1)) {
        k++;
        x >>= 1;
        if (!x & 1) {
            return 32;
        }
    }
    *y = x;
    return k;
}
/* localdecomp:end func_0011A658 */

/* localdecomp:start func_0011A718 */
typedef struct Big_11A718 {
    struct Big_11A718 *next;
    s32 k;
    s32 maxwds;
    s32 sign;
    s32 wds;
    u32 x[1];
} Big_11A718;
extern void *func_0011A3F8();
Big_11A718 *func_0011A718(void *ptr, s32 i) {
    Big_11A718 *b;
    b = (Big_11A718 *)func_0011A3F8(ptr, 1);
    b->x[0] = i;
    b->wds = 1;
    return b;
}
/* localdecomp:end func_0011A718 */

/* localdecomp:start func_0011A750 */
typedef struct Bigint_0011A750 {
    struct Bigint_0011A750 *next;
    s32 k;
    s32 maxwds;
    s32 sign;
    s32 wds;
    u32 x[1];
} Bigint_0011A750;
extern void *func_0011A3F8();

Bigint_0011A750 *func_0011A750(void *ptr, Bigint_0011A750 *a, Bigint_0011A750 *b)
{
    Bigint_0011A750 *c;
    s32 k;
    s32 wa;
    s32 wb;
    s32 wc;
    u32 carry;
    u32 y;
    u32 z;
    u32 *x;
    u32 *xa;
    u32 *xae;
    u32 *xb;
    u32 *xbe;
    u32 *xc;
    u32 *xc0;
    u32 z2;

    if (a->wds < b->wds) {
        c = a;
        a = b;
        b = c;
    }
    k = a->k;
    wa = a->wds;
    wb = b->wds;
    wc = wa + wb;
    if (wc > a->maxwds) {
        k++;
    }
    c = (Bigint_0011A750 *)func_0011A3F8(ptr, k);
    for (x = c->x, xa = x + wc; x < xa; x++) {
        *x = 0;
    }
    xa = a->x;
    xae = xa + wa;
    xb = b->x;
    xbe = xb + wb;
    xc0 = c->x;
    for (; xb < xbe; xb++, xc0++) {
        if ((y = *xb & 0xffff) != 0) {
            x = xa;
            xc = xc0;
            carry = 0;
            do {
                z = (*x & 0xffff) * y + (*xc & 0xffff) + carry;
                carry = z >> 16;
                z2 = (*x++ >> 16) * y + (*xc >> 16) + carry;
                carry = z2 >> 16;
                ((u16 *)xc)[1] = (u16)z2;
                ((u16 *)xc)[0] = (u16)z;
                xc++;
            } while (x < xae);
            *xc = carry;
        }
        if ((y = *xb >> 16) != 0) {
            x = xa;
            xc = xc0;
            carry = 0;
            z2 = *xc;
            do {
                z = (*x & 0xffff) * y + (*xc >> 16) + carry;
                carry = z >> 16;
                ((u16 *)xc)[1] = (u16)z;
                ((u16 *)xc)[0] = (u16)z2;
                xc++;
                z2 = (*x++ >> 16) * y + (*xc & 0xffff) + carry;
                carry = z2 >> 16;
            } while (x < xae);
            *xc = z2;
        }
    }
    for (xc0 = c->x, xc = xc0 + wc; wc > 0 && !*--xc; --wc) {
    }
    c->wds = wc;
    return c;
}
/* localdecomp:end func_0011A750 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011A960);

/* localdecomp:start func_0011AA60 */
typedef struct Bigint_0011AA60 {
    struct Bigint_0011AA60 *next;
    s32 k;
    s32 maxwds;
    s32 sign;
    s32 wds;
    u32 x[1];
} Bigint_0011AA60;
extern void *func_0011A3F8();
extern void func_0011A4A0();

Bigint_0011AA60 *func_0011AA60(void *ptr, Bigint_0011AA60 *b, s32 k)
{
    s32 i;
    s32 k1;
    s32 n;
    s32 n1;
    Bigint_0011AA60 *b1;
    u32 *x;
    u32 *x1;
    u32 *xe;
    u32 z;

    n = k >> 5;
    k1 = b->k;
    n1 = n + b->wds + 1;
    for (i = b->maxwds; n1 > i; i <<= 1) {
        k1++;
    }
    b1 = (Bigint_0011AA60 *)func_0011A3F8(ptr, k1);
    x1 = b1->x;
    for (i = 0; i < n; i++) {
        *x1++ = 0;
    }
    x = b->x;
    xe = x + b->wds;
    if ((k &= 0x1f) != 0) {
        k1 = 32 - k;
        z = 0;
        do {
            *x1++ = *x << k | z;
            z = *x++ >> k1;
        } while (x < xe);
        if ((*x1 = z) != 0) {
            ++n1;
        }
    } else {
        do {
            *x1++ = *x++;
        } while (x < xe);
    }
    b1->wds = n1 - 1;
    func_0011A4A0(ptr, b);
    return b1;
}
/* localdecomp:end func_0011AA60 */

/* localdecomp:start func_0011ABB8 */
s32 func_0011ABB8(Bigint_1171C8 *a, Bigint_1171C8 *b)
{
    u32 *xa;
    u32 *xa0;
    u32 *xb;
    u32 *xb0;
    s32 i;
    s32 j;

    i = a->wds;
    j = b->wds;
    if ((i -= j) != 0) {
        return i;
    }
    xa0 = a->x;
    xa = xa0 + j;
    xb0 = b->x;
    xb = xb0 + j;
    for (;;) {
        if (*--xa != *--xb) {
            return *xa < *xb ? -1 : 1;
        }
        if (xa <= xa0) {
            break;
        }
    }
    return 0;
}
/* localdecomp:end func_0011ABB8 */

/* localdecomp:start func_0011AC20 */
typedef struct Bigint_0011AC20 {
    struct Bigint_0011AC20 *next;
    s32 k;
    s32 maxwds;
    s32 sign;
    s32 wds;
    u32 x[1];
} Bigint_0011AC20;
extern s32 func_0011ABB8();
extern void *func_0011A3F8();

Bigint_0011AC20 *func_0011AC20(void *ptr, Bigint_0011AC20 *a, Bigint_0011AC20 *b)
{
    s32 i;
    s32 wa;
    s32 wb;
    s32 borrow;
    s32 y;
    s32 z;
    u32 *xa;
    u32 *xae;
    u32 *xb;
    u32 *xbe;
    u32 *xc;
    Bigint_0011AC20 *c;

    i = func_0011ABB8(a, b);
    if (!i) {
        c = (Bigint_0011AC20 *)func_0011A3F8(ptr, 0);
        c->wds = 1;
        c->x[0] = 0;
        return c;
    }
    if (i < 0) {
        c = a;
        a = b;
        b = c;
        i = 1;
    } else {
        i = 0;
    }
    c = (Bigint_0011AC20 *)func_0011A3F8(ptr, a->k);
    c->sign = i;
    wa = a->wds;
    xa = a->x;
    xae = xa + wa;
    wb = b->wds;
    xb = b->x;
    xbe = xb + wb;
    xc = c->x;
    borrow = 0;
    do {
        y = (*xa & 0xffff) - (*xb & 0xffff) + borrow;
        borrow = y >> 16;
        z = (*xa++ >> 16) - (*xb++ >> 16) + borrow;
        borrow = z >> 16;
        ((u16 *)xc)[1] = (u16)z;
        ((u16 *)xc)[0] = (u16)y;
        xc++;
    } while (xb < xbe);
    while (xa < xae) {
        y = (*xa & 0xffff) + borrow;
        borrow = y >> 16;
        z = (*xa++ >> 16) + borrow;
        borrow = z >> 16;
        ((u16 *)xc)[1] = (u16)z;
        ((u16 *)xc)[0] = (u16)y;
        xc++;
    }
    while (!*--xc) {
        wa--;
    }
    c->wds = wa;
    return c;
}
/* localdecomp:end func_0011AC20 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011ADB0);

LINKER_REMNANT("asm/boot_elf/remnants", func_0011AF38);

LINKER_REMNANT("asm/boot_elf/remnants", func_0011AF40);

/* localdecomp:start func_0011AF48 */
typedef struct Reent_11AF48 {
    u8 pad0[8];
    F_118838 *out;
} Reent_11AF48;
typedef char *va_list_11AF48;
extern void *D_0013D770[];
extern s32 func_0011CE78(F_118838 *, const char *, va_list_11AF48);

s32 func_0011AF48(const char *fmt, ...) {
    s32 ret;
    va_list_11AF48 ap;
    Reent_11AF48 *ptr;
    ap = (char *)__builtin_next_arg(fmt)
         - (__builtin_args_info(2) >= 8 ? 0 : (8 - __builtin_args_info(2)) * 8);
    ptr = D_0013D770[0];
    ptr->out->data = ptr;
    ret = func_0011CE78(ptr->out, fmt, ap);
    return ret;
}
/* localdecomp:end func_0011AF48 */

/* localdecomp:start func_0011AFB8 */
extern s32 D_1D48C0[];
extern s32 func_0011F468();

long func_0011AFB8(void *ptr, s32 fd, void *buf, s32 cnt)
{
    long ret;

    D_1D48C0[0] = 0;
    if ((ret = func_0011F468(fd, buf, cnt)) == -1 && D_1D48C0[0] != 0) {
        *(s32 *)ptr = D_1D48C0[0];
    }
    return ret;
}
/* localdecomp:end func_0011AFB8 */

/* localdecomp:start func_0011B018 */
typedef union {
    double value;
    struct {
        u32 lsw;
        u32 msw;
    } parts;
} Dbl_11B018;

int func_0011B018(double x)
{
    s32 hx, lx;
    do {
        Dbl_11B018 ew_u;
        ew_u.value = x;
        hx = ew_u.parts.msw;
        lx = ew_u.parts.lsw;
    } while (0);
    hx &= 0x7fffffff;
    hx |= (u32)(lx | (-lx)) >> 31;
    hx = 0x7ff00000 - hx;
    return 1 - (int)((u32)(hx | (-hx)) >> 31);
}
/* localdecomp:end func_0011B018 */

/* localdecomp:start func_0011B060 */
typedef union {
    double value;
    struct {
        u32 lsw;
        u32 msw;
    } parts;
} Dbl_11B060;
int func_0011B060(double x) {
    s32 hx, lx;
    do {
        Dbl_11B060 ew_u;
        ew_u.value = x;
        hx = ew_u.parts.msw;
        lx = ew_u.parts.lsw;
    } while (0);
    hx &= 0x7fffffff;
    hx |= (u32)(lx | (-lx)) >> 31;
    hx = 0x7ff00000 - hx;
    return (int)(((u32)hx) >> 31);
}
/* localdecomp:end func_0011B060 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011B09C);

/* localdecomp:start func_0011B0A0 */
extern s32 func_0011F4F0();
extern s32 D_1D48C0[];
s32 func_0011B0A0(s32 *p, s32 a) {
    s32 ret;
    D_1D48C0[0] = 0;
    ret = func_0011F4F0(a);
    if (ret == -1 && D_1D48C0[0] != 0) {
        *p = D_1D48C0[0];
    }
    return ret;
}
/* localdecomp:end func_0011B0A0 */

/* localdecomp:start func_0011B0F8 */
typedef struct {
    u8 pad0[0x1D4];
    u32 *freelist;
} R_11B0F8;
extern void *func_001197E0();

s32 func_0011B0F8(R_11B0F8 *r)
{
    s32 i;
    u32 *p;

    if (r->freelist == 0) {
        r->freelist = func_001197E0(r, 0x80);
        if (r->freelist == 0) {
            return -1;
        }
        p = r->freelist + 31;
        for (i = 31; i >= 0; i--) {
            *p-- = 0;
        }
    }
    return 0;
}
/* localdecomp:end func_0011B0F8 */

/* localdecomp:start func_0011B168 */
typedef void (*SigFn_11B168)(s32);
typedef struct {
    s32 err;
    u8 pad4[0x1D0];
    SigFn_11B168 *sig_func;
} Reent_11B168;
extern s32 func_0011B0F8();
extern s32 func_0011B2D0(void *);
extern s32 func_0011B270(s32 *, s32, s32);
s32 func_0011B168(void *p, s32 sig) {
    Reent_11B168 *reent = p;
    SigFn_11B168 func;
    if (sig < 0 || sig >= 32) {
        reent->err = 22;
        return -1;
    }
    if (reent->sig_func == 0) {
        if (func_0011B0F8(reent)) {
            return -1;
        }
    }
    func = reent->sig_func[sig];
    if (func == (SigFn_11B168)0) {
        return func_0011B270((s32 *)reent, func_0011B2D0(reent), sig);
    } else if (func == (SigFn_11B168)1) {
        return 0;
    } else if (func == (SigFn_11B168)-1) {
        reent->err = 22;
        return 1;
    } else {
        reent->sig_func[sig] = (SigFn_11B168)0;
        func(sig);
        return 0;
    }
}
/* localdecomp:end func_0011B168 */

/* localdecomp:start func_0011B240 */
extern s32 func_0011B168(void *, s32);
void func_0011B240(s32 a) {
    func_0011B168(D_0013D770[0], a);
}
/* localdecomp:end func_0011B240 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0011B260);

/* localdecomp:start func_0011B270 */
extern s32 func_0011F5C8(s32, s32);
extern s32 D_1D48C0[];
s32 func_0011B270(s32 *p, s32 a, s32 b) {
    s32 ret;
    D_1D48C0[0] = 0;
    ret = func_0011F5C8(a, b);
    if (ret == -1 && D_1D48C0[0] != 0) {
        *p = D_1D48C0[0];
    }
    return ret;
}
/* localdecomp:end func_0011B270 */

/* localdecomp:start func_0011B2D0 */
extern s32 func_0011F5C0(void);
s32 func_0011B2D0(void *ptr)
{
    return func_0011F5C0();
}
/* localdecomp:end func_0011B2D0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0011B2E4);

/* localdecomp:start func_0011B2E8 */
typedef struct {
    u8 *p;
    s32 r;
    s32 w;
    s16 flags;
    s16 file;
    u8 *base;
    s32 size;
    u8 pad18[0x54 - 0x18];
    void *data;
} F_11B2E8;
extern void *D_0013D770[];
extern s32 func_0011CE78();
s32 func_0011B2E8(char *str, const char *fmt, ...) {
    F_11B2E8 f;
    s32 ret;
    char *ap;
    f.flags = 0x208;
    f.base = f.p = (u8 *)str;
    f.size = f.w = 0x7FFFFFFF;
    f.data = D_0013D770[0];
    ap = (char *)__builtin_next_arg(fmt) - 0x30;
    ret = func_0011CE78(&f, fmt, ap);
    *f.p = 0;
    return ret;
}
/* localdecomp:end func_0011B2E8 */

/* localdecomp:start func_0011B378 */
typedef struct {
    u8 pad0[0xC];
    u16 flags;
    s16 file;
    u8 pad10[0x40];
    s32 off;
    void *reent;
} F_11B378;
extern long func_0011AFB8(void *, s32, void *, s32);
s32 func_0011B378(F_11B378 *fp, void *buf, s32 n) {
    s32 ret = func_0011AFB8(fp->reent, fp->file, buf, n);
    if (ret >= 0) {
        fp->off += ret;
    } else {
        fp->flags &= ~0x1000;
    }
    return ret;
}
/* localdecomp:end func_0011B378 */

/* localdecomp:start func_0011B3E0 */
typedef struct {
    u8 pad0[0xC];
    u16 flags;
    s16 file;
    u8 pad10[0x44];
    void *reent;
} F_11B3E0;
extern long func_00119330(void *, s32, s32, s32);
extern long func_0011E860(void *, s32, char *, s32);
s32 func_0011B3E0(void *cookie, char *buf, s32 n) {
    register F_11B3E0 *fp = cookie;
    if (fp->flags & 0x100)
        func_00119330(fp->reent, fp->file, 0, 2);
    fp->flags &= ~0x1000;
    return func_0011E860(fp->reent, fp->file, buf, n);
}
/* localdecomp:end func_0011B3E0 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011B460);

/* localdecomp:start func_0011B4C8 */
extern s32 func_00117170(void *, s32);

s32 func_0011B4C8(F_118838 *ptr) {
    return func_00117170(ptr->data, ptr->file);
}
/* localdecomp:end func_0011B4C8 */

ASM_FUNC("asm/boot_elf/handwritten", func_0011B4E4);

ASM_FUNC("asm/boot_elf/handwritten", func_0011B610);

ASM_FUNC("asm/boot_elf/handwritten", func_0011B754);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011B868);

ASM_FUNC("asm/boot_elf/handwritten", func_0011B9A0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011BB58);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011BD14);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011BD9C);

/* localdecomp:start func_0011BFD8 */
extern void *D_0013D770[];
extern long func_0011BDA0(void *, s32, s32, s32);

long func_0011BFD8(s32 s, s32 endp, s32 base)
{
    return func_0011BDA0(D_0013D770[0], s, endp, base);
}
/* localdecomp:end func_0011BFD8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0011C004);

/* localdecomp:start func_0011C008 */
s32 func_0011C008(F_118E78 *a, Uio_118E78 *p) {
    s32 r;
    if (p->resid == 0) {
        p->iovcnt = 0;
        return 0;
    }
    r = func_00118E78(a, p);
    p->resid = 0;
    p->iovcnt = 0;
    return r;
}
/* localdecomp:end func_0011C008 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011C050);

/* localdecomp:start func_0011C108 */
extern s32 func_0011C180(void *, F_118838 *, const char *, va_list_11AF48);

s32 func_0011C108(F_118838 *fp, const char *fmt, va_list_11AF48 ap)
{
    do {
        if (fp->data == 0) {
            fp->data = D_0013D770[0];
        }
        if (((Reent_00118720 *)fp->data)->cleanup == 0) {
            func_001188C0(fp->data);
        }
    } while (0);
    return func_0011C180(fp->data, fp, fmt, ap);
}
/* localdecomp:end func_0011C108 */

/* localdecomp:start func_0011C180 */
extern void *D_0013D770[];
extern s32 D_0013D774[];
extern char D_00150390[];
extern char D_001503A0[];
extern char D_001503B0[];
extern char D_001503C8[];
extern char D_001503D0[];
extern char D_001503E8[];
extern s32 func_0011C050();
extern s32 func_0011B868();

s32 func_0011C180(void *unused, F_118838 *fp, const char *fmt0, va_list_11AF48 ap0)
{
    extern u64 func_00128580();
    extern u64 func_00127FB0();
    __builtin_va_list ap = ap0;
    char *fmt;
    s32 ch;
    s32 n;
    s32 m;
    char *cp;
    Iov_118E78 *iovp;
    s32 flags;
    s32 ret;
    s32 width;
    s32 prec;
    char sign;
    s32 wc;
    s32 state;
    u64 uquad;
    enum { OCT, DEC, HEX } base;
    s32 dprec;
    s32 realsz;
    s32 size;
    char *xdigs;
    Uio_118E78 uio;
    Iov_118E78 iov[8];
    char buf[40];
    char ox[2];

    state = 0;
    if (!(fp->flags & 8) || fp->base == 0) {
        if (func_0011E8C0((F_118E78 *)fp)) {
            return -1;
        }
    }
    if ((fp->flags & 0x1A) == 0xA && fp->file >= 0) {
        return func_0011C050(fp, fmt0, ap);
    }
    fmt = (char *)fmt0;
    uio.iov = iovp = iov;
    uio.resid = 0;
    uio.iovcnt = 0;
    ret = 0;
    for (;;) {
        cp = fmt;
        while ((n = func_00119F08(D_0013D770[0], &wc, fmt, D_0013D774[0], &state)) > 0) {
            fmt += n;
            if (wc == '%') {
                fmt--;
                break;
            }
        }
        if ((m = fmt - cp) != 0) {
            {
                iovp->base = (u8 *)(cp);
                iovp->len = (m);
                uio.resid += (m);
                iovp++;
                if (++uio.iovcnt >= 8) {
                    if (func_0011C008((F_118E78 *)fp, &uio)) {
                        goto error;
                    }
                    iovp = iov;
                }
            }
            ret += m;
        }
        if (n <= 0) {
            goto done;
        }
        fmt++;
        flags = 0;
        dprec = 0;
        width = 0;
        prec = -1;
        sign = '\0';
rflag:
        ch = *fmt++;
reswitch:
        switch (ch) {
        case ' ':
            if (!sign) {
                sign = ' ';
            }
            goto rflag;
        case '#':
            flags |= 1;
            goto rflag;
        case '*':
            width = __builtin_va_arg(ap, s32);
            if (width >= 0) {
                goto rflag;
            }
            width = -width;
        case '-':
            flags |= 4;
            goto rflag;
        case '+':
            sign = '+';
            goto rflag;
        case '.':
            if ((ch = *fmt++) == '*') {
                n = __builtin_va_arg(ap, s32);
                prec = n < 0 ? -1 : n;
                goto rflag;
            }
            n = 0;
            while ((u32)(ch - '0') <= 9) {
                n = 10 * n + (ch - '0');
                ch = *fmt++;
            }
            prec = n < 0 ? -1 : n;
            goto reswitch;
        case '0':
            flags |= 0x80;
            goto rflag;
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            n = 0;
            do {
                n = 10 * n + (ch - '0');
                ch = *fmt++;
            } while ((u32)(ch - '0') <= 9);
            width = n;
            goto reswitch;
        case 'h':
            flags |= 0x40;
            goto rflag;
        case 'l':
            if (*fmt == 'l') {
                fmt++;
                flags |= 0x20;
            } else {
                flags |= 0x10;
            }
            goto rflag;
        case 'q':
            flags |= 0x20;
            goto rflag;
        case 'c':
            cp = buf;
            *cp = __builtin_va_arg(ap, s32);
            size = 1;
            sign = '\0';
            break;
        case 'D':
            flags |= 0x10;
        case 'd':
        case 'i':
            if (flags & 0x10) {
                uquad = __builtin_va_arg(ap, long);
            } else if (flags & 0x40) {
                uquad = (short)__builtin_va_arg(ap, s32);
            } else {
                uquad = __builtin_va_arg(ap, s32);
            }
            if ((long)uquad < 0) {
                uquad = -uquad;
                sign = '-';
            }
            base = DEC;
            goto number;
        case 'n':
            if (flags & 0x10) {
                *__builtin_va_arg(ap, long *) = ret;
            } else if (flags & 0x40) {
                *__builtin_va_arg(ap, short *) = ret;
            } else {
                *__builtin_va_arg(ap, s32 *) = ret;
            }
            continue;
        case 'O':
            flags |= 0x10;
        case 'o':
            if (flags & 0x10) {
                uquad = __builtin_va_arg(ap, u64);
            } else if (flags & 0x40) {
                uquad = (u16)__builtin_va_arg(ap, s32);
            } else {
                uquad = __builtin_va_arg(ap, u32);
            }
            base = OCT;
            goto nosign;
        case 'p':
            uquad = (u64)(long)__builtin_va_arg(ap, void *);
            base = HEX;
            xdigs = D_001503B0;
            flags |= 2;
            ch = 'x';
            goto nosign;
        case 's':
            if ((cp = __builtin_va_arg(ap, char *)) == 0) {
                cp = D_001503C8;
            }
            if (prec >= 0) {
                char *p = (char *)func_00119F3C((u8 *)cp, 0, prec);
                if (p != 0) {
                    size = p - cp;
                    if (size > prec) {
                        size = prec;
                    }
                } else {
                    size = prec;
                }
            } else {
                size = func_0011B868(cp);
            }
            sign = '\0';
            break;
        case 'U':
            flags |= 0x10;
        case 'u':
            if (flags & 0x10) {
                uquad = __builtin_va_arg(ap, u64);
            } else if (flags & 0x40) {
                uquad = (u16)__builtin_va_arg(ap, s32);
            } else {
                uquad = __builtin_va_arg(ap, u32);
            }
            base = DEC;
            goto nosign;
        case 'X':
            xdigs = D_001503D0;
            goto hex;
        case 'x':
            xdigs = D_001503B0;
hex:
            if (flags & 0x10) {
                uquad = __builtin_va_arg(ap, u64);
            } else if (flags & 0x40) {
                uquad = (u16)__builtin_va_arg(ap, s32);
            } else {
                uquad = __builtin_va_arg(ap, u32);
            }
            base = HEX;
            if (flags & 1 && uquad != 0) {
                flags |= 2;
            }
nosign:
            sign = '\0';
number:
            if ((dprec = prec) >= 0) {
                flags &= ~0x80;
            }
            cp = buf + 40;
            if (uquad != 0 || prec != 0) {
                switch (base) {
                case OCT:
                    do {
                        *--cp = (uquad & 7) + '0';
                        uquad >>= 3;
                    } while (uquad);
                    if (flags & 1 && *cp != '0') {
                        *--cp = '0';
                    }
                    break;
                case DEC:
                    while (uquad >= 10) {
                        *--cp = func_00128580(uquad, 10) + '0';
                        uquad = func_00127FB0(uquad, 10);
                    }
                    *--cp = uquad + '0';
                    break;
                case HEX:
                    do {
                        *--cp = xdigs[uquad & 15];
                        uquad >>= 4;
                    } while (uquad);
                    break;
                default:
                    cp = D_001503E8;
                    size = func_0011B868(cp);
                    goto skipsize;
                }
            }
            size = buf + 40 - cp;
skipsize:
            break;
        default:
            if (ch == '\0') {
                goto done;
            }
            cp = buf;
            *cp = ch;
            size = 1;
            sign = '\0';
            break;
        }
        realsz = dprec > size ? dprec : size;
        if (sign) {
            realsz++;
        } else if (flags & 2) {
            realsz += 2;
        }
        if ((flags & 0x84) == 0) {
            if ((n = (width - realsz)) > 0) {
                while (n > 16) {
                    {
                        iovp->base = (u8 *)(D_00150390);
                        iovp->len = (16);
                        uio.resid += (16);
                        iovp++;
                        if (++uio.iovcnt >= 8) {
                            if (func_0011C008((F_118E78 *)fp, &uio)) {
                                goto error;
                            }
                            iovp = iov;
                        }
                    }
                    n -= 16;
                }
                {
                    iovp->base = (u8 *)(D_00150390);
                    iovp->len = (n);
                    uio.resid += (n);
                    iovp++;
                    if (++uio.iovcnt >= 8) {
                        if (func_0011C008((F_118E78 *)fp, &uio)) {
                            goto error;
                        }
                        iovp = iov;
                    }
                }
            }
        }
        if (sign) {
            {
                iovp->base = (u8 *)(&sign);
                iovp->len = (1);
                uio.resid += (1);
                iovp++;
                if (++uio.iovcnt >= 8) {
                    if (func_0011C008((F_118E78 *)fp, &uio)) {
                        goto error;
                    }
                    iovp = iov;
                }
            }
        } else if (flags & 2) {
            ox[0] = '0';
            ox[1] = ch;
            {
                iovp->base = (u8 *)(ox);
                iovp->len = (2);
                uio.resid += (2);
                iovp++;
                if (++uio.iovcnt >= 8) {
                    if (func_0011C008((F_118E78 *)fp, &uio)) {
                        goto error;
                    }
                    iovp = iov;
                }
            }
        }
        if ((flags & 0x84) == 0x80) {
            if ((n = (width - realsz)) > 0) {
                while (n > 16) {
                    {
                        iovp->base = (u8 *)(D_001503A0);
                        iovp->len = (16);
                        uio.resid += (16);
                        iovp++;
                        if (++uio.iovcnt >= 8) {
                            if (func_0011C008((F_118E78 *)fp, &uio)) {
                                goto error;
                            }
                            iovp = iov;
                        }
                    }
                    n -= 16;
                }
                {
                    iovp->base = (u8 *)(D_001503A0);
                    iovp->len = (n);
                    uio.resid += (n);
                    iovp++;
                    if (++uio.iovcnt >= 8) {
                        if (func_0011C008((F_118E78 *)fp, &uio)) {
                            goto error;
                        }
                        iovp = iov;
                    }
                }
            }
        }
        if ((n = (dprec - size)) > 0) {
            while (n > 16) {
                {
                    iovp->base = (u8 *)(D_001503A0);
                    iovp->len = (16);
                    uio.resid += (16);
                    iovp++;
                    if (++uio.iovcnt >= 8) {
                        if (func_0011C008((F_118E78 *)fp, &uio)) {
                            goto error;
                        }
                        iovp = iov;
                    }
                }
                n -= 16;
            }
            {
                iovp->base = (u8 *)(D_001503A0);
                iovp->len = (n);
                uio.resid += (n);
                iovp++;
                if (++uio.iovcnt >= 8) {
                    if (func_0011C008((F_118E78 *)fp, &uio)) {
                        goto error;
                    }
                    iovp = iov;
                }
            }
        }
        {
            iovp->base = (u8 *)(cp);
            iovp->len = (size);
            uio.resid += (size);
            iovp++;
            if (++uio.iovcnt >= 8) {
                if (func_0011C008((F_118E78 *)fp, &uio)) {
                    goto error;
                }
                iovp = iov;
            }
        }
        if (flags & 4) {
            if ((n = (width - realsz)) > 0) {
                while (n > 16) {
                    {
                        iovp->base = (u8 *)(D_00150390);
                        iovp->len = (16);
                        uio.resid += (16);
                        iovp++;
                        if (++uio.iovcnt >= 8) {
                            if (func_0011C008((F_118E78 *)fp, &uio)) {
                                goto error;
                            }
                            iovp = iov;
                        }
                    }
                    n -= 16;
                }
                {
                    iovp->base = (u8 *)(D_00150390);
                    iovp->len = (n);
                    uio.resid += (n);
                    iovp++;
                    if (++uio.iovcnt >= 8) {
                        if (func_0011C008((F_118E78 *)fp, &uio)) {
                            goto error;
                        }
                        iovp = iov;
                    }
                }
            }
        }
        ret += width > realsz ? width : realsz;
        if (uio.resid && func_0011C008((F_118E78 *)fp, &uio)) {
            goto error;
        }
        uio.iovcnt = 0;
        iovp = iov;
    }
done:
    if (uio.resid && func_0011C008((F_118E78 *)fp, &uio)) {
        goto error;
    }
    uio.iovcnt = 0;
    iovp = iov;
error:
    return (fp->flags & 0x40) ? -1 : ret;
}
/* localdecomp:end func_0011C180 */

/* localdecomp:start func_0011CD78 */
s32 func_0011CD78(F_118E78 *a, Uio_118E78 *p) {
    s32 r;
    if (p->resid == 0) {
        p->iovcnt = 0;
        return 0;
    }
    r = func_00118E78(a, p);
    p->resid = 0;
    p->iovcnt = 0;
    return r;
}
/* localdecomp:end func_0011CD78 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011CDC0);

/* localdecomp:start func_0011CE78 */
extern s32 func_0011CEF0(void *, F_118838 *, const char *, va_list_11AF48);

s32 func_0011CE78(F_118838 *fp, const char *fmt, va_list_11AF48 ap)
{
    do {
        if (fp->data == 0) {
            fp->data = D_0013D770[0];
        }
        if (((Reent_00118720 *)fp->data)->cleanup == 0) {
            func_001188C0(fp->data);
        }
    } while (0);
    return func_0011CEF0(fp->data, fp, fmt, ap);
}
/* localdecomp:end func_0011CE78 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011CEF0);

/* localdecomp:start func_0011E560 */
typedef union {
    double d;
    struct {
        s32 lo;
        s32 hi;
    } w;
} Dbl_11E560;
extern char *func_001173F8();

char *func_0011E560(void *data, double value, s32 ndigits, s32 flags, char *sign, s32 *decpt, s32 ch, s32 *length)
{
    Dbl_11E560 u;
    s32 mode;
    s32 dsgn;
    char *digits;
    char *bp;
    char *rve;

    if (ch == 'f') {
        mode = 3;
    } else {
        if (ch == 'e' || ch == 'E') {
            ndigits++;
        }
        mode = 2;
    }
    u.d = value;
    if (u.w.hi < 0) {
        value = -value;
        *sign = '-';
    } else {
        *sign = 0;
    }
    digits = func_001173F8(data, value, mode, ndigits, decpt, &dsgn, &rve);
    if ((ch != 'g' && ch != 'G') || (flags & 1)) {
        bp = digits + ndigits;
        if (ch == 'f') {
            if (*digits == '0' && value) {
                *decpt = -ndigits + 1;
            }
            bp += *decpt;
        }
        if (value == 0) {
            rve = bp;
        }
        while (rve < bp) {
            *rve++ = '0';
        }
    }
    *length = rve - digits;
    return digits;
}
/* localdecomp:end func_0011E560 */

/* localdecomp:start func_0011E720 */
s32 func_0011E720(char *p0, s32 exp, s32 fmtch)
{
    char *p;
    char *t;
    char expbuf[308];

    p = p0;
    *p++ = fmtch;
    if (exp < 0) {
        exp = -exp;
        *p++ = '-';
    } else {
        *p++ = '+';
    }
    t = expbuf + 308;
    if (exp > 9) {
        do {
            *--t = exp % 10 + '0';
        } while ((exp /= 10) > 9);
        *--t = exp + '0';
        for (; t < expbuf + 308; *p++ = *t++) {
        }
    } else {
        *p++ = '0';
        *p++ = exp + '0';
    }
    return p - p0;
}
/* localdecomp:end func_0011E720 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011E7FC);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011E858);

/* localdecomp:start func_0011E860 */
extern s32 D_1D48C0[];
extern s32 func_0011F3E8();

long func_0011E860(void *ptr, s32 fd, char *buf, s32 n)
{
    long r;

    D_1D48C0[0] = 0;
    r = func_0011F3E8(fd, buf, n);
    if (r == -1 && D_1D48C0[0] != 0) {
        *(s32 *)ptr = D_1D48C0[0];
    }
    return r;
}
/* localdecomp:end func_0011E860 */

/* localdecomp:start func_0011E8C0 */
typedef struct Reent_11E8C0 {
    u8 pad0[0x38];
    s32 didinit;
} Reent_11E8C0;
typedef struct F_11E8C0 {
    u8 *p;
    s32 r;
    s32 w;
    s16 flags;
    s16 file;
    u8 *base;
    s32 size;
    s32 lbfsize;
    u8 pad1C[0x30 - 0x1C];
    u8 *ub;
    u8 pad34[0x40 - 0x34];
    u8 ubuf[4];
    u8 pad44[0x54 - 0x44];
    Reent_11E8C0 *data;
} F_11E8C0;

s32 func_0011E8C0(F_118E78 *p) {
    F_11E8C0 *fp = (F_11E8C0 *)p;

    if (fp->data == 0) {
        fp->data = D_0013D770[0];
    }
    do {
        if (fp->data->didinit == 0) {
            func_001188C0((Reent_00118720 *)fp->data);
        }
    } while (0);
    if ((fp->flags & 8) == 0) {
        if ((fp->flags & 0x10) == 0) {
            return -1;
        }
        if (fp->flags & 4) {
            if (fp->ub != 0) {
                if (fp->ub != fp->ubuf) {
                    func_001189B0(fp->data, fp->ub);
                }
                fp->ub = 0;
            }
            fp->flags &= ~0x24;
            fp->r = 0;
            fp->p = fp->base;
        }
        fp->flags |= 8;
    }
    if (fp->base == 0) {
        func_00119390((F_119390 *)fp);
    }
    if (fp->flags & 1) {
        fp->w = 0;
        fp->lbfsize = -fp->size;
    } else {
        fp->w = (fp->flags & 2) ? 0 : fp->size;
    }
    return 0;
}
/* localdecomp:end func_0011E8C0 */

ASM_FUNC("asm/boot_elf/handwritten", func_0011E9CC);
