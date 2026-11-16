#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 116F80.c's earlier functions */
extern void func_0011B240(s32);
extern void func_0013AFE8(s32) __attribute__((noreturn));

typedef struct Reent_116F98 {
    u8 pad0[0xC];
    void *err;
} Reent_116F98;
extern void *D_0013D770[];
extern char D_00150080[];
extern s32 func_00118950(void *, char *, ...);
extern void func_00116F80(void);

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

extern long func_0011BFD8(s32, s32, s32);

extern s32 func_0011A160();

typedef struct Bigint_1171C8 {
    struct Bigint_1171C8 *next;
    s32 k;
    s32 maxwds;
    s32 sign;
    s32 wds;
    u32 x[1];
} Bigint_1171C8;
extern s32 func_0011ABB8(Bigint_1171C8 *, Bigint_1171C8 *);

/* func_00118660: returns the global pointer stored at D_0013D770.
   Retail reaches D_0013D770 through lui/%lo, so the global is declared as an
   unsized array (never small data) and read at offset 0. */

extern void *D_0013D770[];

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

typedef struct { u8 *p; s32 r; s32 w; s16 flags; s16 file; u8 *base; s32 size; s32 lbfsize; void *cookie; void *read; void *write; void *seek; void *close; u8 pad[0x24]; void *data; } F_118838;
extern s32 func_0011B378();
extern s32 func_0011B3E0();
extern long func_0011B460();
extern s32 func_0011B4C8();

extern s32 func_00118720(File_00118720 *);

extern s32 func_0011C108();

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
extern s32 func_00118CA8(void *, u32);

extern s32 func_0011F5A8();
extern s32 D_1D48C0[];

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

LINKER_REMNANT("asm/boot_elf/remnants", func_001192EC);
