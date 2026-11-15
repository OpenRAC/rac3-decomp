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

extern void *D_0013D770[];
extern void *func_001192F8(void *);

extern long func_0011B460();
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

/* localdecomp:start func_001197E0 */
void *func_001197E0(void *reent, u32 bytes)
{
    extern void func_0011A328();
    extern void func_0011A3A8();
    extern void func_00119588();
    Chunk_001189B0 *victim;
    u32 victim_size;
    s32 idx;
    Chunk_001189B0 *bin;
    Chunk_001189B0 *remainder;
    long remainder_size;
    s32 remainder_index;
    unsigned long block;
    s32 startidx;
    Chunk_001189B0 *fwd;
    Chunk_001189B0 *bck;
    Chunk_001189B0 *q;
    u32 nb = ((unsigned long)(bytes + 19) < (unsigned long)31) ? 16 : ((bytes + 19) & ~15);

    func_0011A328(reent);

    if (nb < 504) {
        idx = (unsigned long)nb >> 3;
        q = (Chunk_001189B0 *)((char *)&D_0013D778[2 * idx + 2] - 8);
        victim = q->bk;
        if (victim != q) {
            victim_size = victim->size & ~3;
            bck = victim->bk;
            fwd = victim->fd;
            fwd->bk = bck;
            bck->fd = fwd;
            ((Chunk_001189B0 *)((char *)victim + victim_size))->size |= 1;
            func_0011A3A8(reent);
            return (char *)victim + 8;
        }
        idx += 2;
    } else {
        idx = ((unsigned long)nb >> 9) == 0 ? (unsigned long)nb >> 3
            : ((unsigned long)nb >> 9) <= 4 ? 56 + ((unsigned long)nb >> 6)
            : ((unsigned long)nb >> 9) <= 20 ? 91 + ((unsigned long)nb >> 9)
            : ((unsigned long)nb >> 9) <= 84 ? 110 + ((unsigned long)nb >> 12)
            : ((unsigned long)nb >> 9) <= 340 ? 119 + ((unsigned long)nb >> 15)
            : ((unsigned long)nb >> 9) <= 1364 ? 124 + ((unsigned long)nb >> 18)
            : 126;
        bin = (Chunk_001189B0 *)((char *)&D_0013D778[2 * idx + 2] - 8);
        for (victim = bin->bk; victim != bin; victim = victim->bk) {
            victim_size = victim->size & ~3;
            remainder_size = victim_size < nb ? -(long)(nb - victim_size) : (long)(victim_size - nb);
            if (remainder_size >= (long)16) {
                --idx;
                break;
            } else if (remainder_size >= 0) {
                bck = victim->bk;
                fwd = victim->fd;
                fwd->bk = bck;
                bck->fd = fwd;
                ((Chunk_001189B0 *)((char *)victim + victim_size))->size |= 1;
                func_0011A3A8(reent);
                return (char *)victim + 8;
            }
        }
        ++idx;
    }

    if ((victim = ((Chunk_001189B0 *)((char *)&D_0013D778[2 * 1 + 2] - 8))->fd) != (Chunk_001189B0 *)((char *)&D_0013D778[2 * 1 + 2] - 8)) {
        victim_size = victim->size & ~3;
        remainder_size = victim_size < nb ? -(long)(nb - victim_size) : (long)(victim_size - nb);
        if (remainder_size >= (long)16) {
            remainder = (Chunk_001189B0 *)((char *)victim + nb);
            victim->size = nb | 1;
            ((Chunk_001189B0 *)((char *)&D_0013D778[2 * 1 + 2] - 8))->fd = ((Chunk_001189B0 *)((char *)&D_0013D778[2 * 1 + 2] - 8))->bk = remainder;
            remainder->fd = remainder->bk = (Chunk_001189B0 *)((char *)&D_0013D778[2 * 1 + 2] - 8);
            remainder->size = remainder_size | 1;
            ((Chunk_001189B0 *)((char *)remainder + remainder_size))->prev_size = remainder_size;
            func_0011A3A8(reent);
            return (char *)victim + 8;
        }
        ((Chunk_001189B0 *)((char *)&D_0013D778[2 * 1 + 2] - 8))->fd = ((Chunk_001189B0 *)((char *)&D_0013D778[2 * 1 + 2] - 8))->bk = (Chunk_001189B0 *)((char *)&D_0013D778[2 * 1 + 2] - 8);
        if (remainder_size >= 0) {
            ((Chunk_001189B0 *)((char *)victim + victim_size))->size |= 1;
            func_0011A3A8(reent);
            return (char *)victim + 8;
        }
        if (victim_size < 512) {
            remainder_index = (unsigned long)victim_size >> 3;
            ((Chunk_001189B0 *)((char *)&D_0013D778[2 * 0 + 2] - 8))->size |= (unsigned long)1 << (remainder_index / 4);
            bck = (Chunk_001189B0 *)((char *)&D_0013D778[2 * remainder_index + 2] - 8);
            fwd = bck->fd;
            victim->bk = bck;
            victim->fd = fwd;
            fwd->bk = bck->fd = victim;
        } else {
            remainder_index = ((unsigned long)victim_size >> 9) == 0 ? (unsigned long)victim_size >> 3
                : ((unsigned long)victim_size >> 9) <= 4 ? 56 + ((unsigned long)victim_size >> 6)
                : ((unsigned long)victim_size >> 9) <= 20 ? 91 + ((unsigned long)victim_size >> 9)
                : ((unsigned long)victim_size >> 9) <= 84 ? 110 + ((unsigned long)victim_size >> 12)
                : ((unsigned long)victim_size >> 9) <= 340 ? 119 + ((unsigned long)victim_size >> 15)
                : ((unsigned long)victim_size >> 9) <= 1364 ? 124 + ((unsigned long)victim_size >> 18)
                : 126;
            bck = (Chunk_001189B0 *)((char *)&D_0013D778[2 * remainder_index + 2] - 8);
            fwd = bck->fd;
            if (fwd == bck) {
                ((Chunk_001189B0 *)((char *)&D_0013D778[2 * 0 + 2] - 8))->size |= (unsigned long)1 << (remainder_index / 4);
            } else {
                while (fwd != bck && victim_size < (fwd->size & ~3)) {
                    fwd = fwd->fd;
                }
                bck = fwd->bk;
            }
            victim->bk = bck;
            victim->fd = fwd;
            fwd->bk = bck->fd = victim;
        }
    }

    if ((block = (unsigned long)1 << (idx / 4)) <= ((Chunk_001189B0 *)((char *)&D_0013D778[2 * 0 + 2] - 8))->size) {
        if ((block & ((Chunk_001189B0 *)((char *)&D_0013D778[2 * 0 + 2] - 8))->size) == 0) {
            idx = (idx & ~3) + 4;
            block <<= 1;
            while ((block & ((Chunk_001189B0 *)((char *)&D_0013D778[2 * 0 + 2] - 8))->size) == 0) {
                idx += 4;
                block <<= 1;
            }
        }
        for (;;) {
            startidx = idx;
            q = bin = (Chunk_001189B0 *)((char *)&D_0013D778[2 * idx + 2] - 8);
            do {
                for (victim = bin->bk; victim != bin; victim = victim->bk) {
                    victim_size = victim->size & ~3;
                    remainder_size = victim_size < nb ? -(long)(nb - victim_size) : (long)(victim_size - nb);
                    if (remainder_size >= (long)16) {
                        remainder = (Chunk_001189B0 *)((char *)victim + nb);
                        victim->size = nb | 1;
                        bck = victim->bk;
                        fwd = victim->fd;
                        fwd->bk = bck;
                        bck->fd = fwd;
                        ((Chunk_001189B0 *)((char *)&D_0013D778[2 * 1 + 2] - 8))->fd = ((Chunk_001189B0 *)((char *)&D_0013D778[2 * 1 + 2] - 8))->bk = remainder;
                        remainder->fd = remainder->bk = (Chunk_001189B0 *)((char *)&D_0013D778[2 * 1 + 2] - 8);
                        remainder->size = remainder_size | 1;
                        ((Chunk_001189B0 *)((char *)remainder + remainder_size))->prev_size = remainder_size;
                        func_0011A3A8(reent);
                        return (char *)victim + 8;
                    } else if (remainder_size >= 0) {
                        ((Chunk_001189B0 *)((char *)victim + victim_size))->size |= 1;
                        bck = victim->bk;
                        fwd = victim->fd;
                        fwd->bk = bck;
                        bck->fd = fwd;
                        func_0011A3A8(reent);
                        return (char *)victim + 8;
                    }
                }
                bin = (Chunk_001189B0 *)((char *)bin + 8);
                if (idx < 63) {
                    bin = (Chunk_001189B0 *)((char *)bin + 8);
                    ++idx;
                }
            } while ((++idx & 3) != 0);
            do {
                if ((startidx & 3) == 0) {
                    ((Chunk_001189B0 *)((char *)&D_0013D778[2 * 0 + 2] - 8))->size &= ~block;
                    break;
                }
                --startidx;
                q = (Chunk_001189B0 *)((char *)q - 8);
            } while (q->fd == q);
            if ((block <<= 1) <= ((Chunk_001189B0 *)((char *)&D_0013D778[2 * 0 + 2] - 8))->size && block != 0) {
                while ((block & ((Chunk_001189B0 *)((char *)&D_0013D778[2 * 0 + 2] - 8))->size) == 0) {
                    idx += 4;
                    block <<= 1;
                }
            } else {
                break;
            }
        }
    }

    remainder_size = (((Chunk_001189B0 *)((char *)&D_0013D778[2 * 0 + 2] - 8))->fd->size & ~3) < nb
        ? -(long)(nb - (((Chunk_001189B0 *)((char *)&D_0013D778[2 * 0 + 2] - 8))->fd->size & ~3))
        : (long)((((Chunk_001189B0 *)((char *)&D_0013D778[2 * 0 + 2] - 8))->fd->size & ~3) - nb);
    if ((((Chunk_001189B0 *)((char *)&D_0013D778[2 * 0 + 2] - 8))->fd->size & ~3) < nb || remainder_size < (long)16) {
        func_00119588(reent, nb);
        remainder_size = (((Chunk_001189B0 *)((char *)&D_0013D778[2 * 0 + 2] - 8))->fd->size & ~3) < nb
            ? -(long)(nb - (((Chunk_001189B0 *)((char *)&D_0013D778[2 * 0 + 2] - 8))->fd->size & ~3))
            : (long)((((Chunk_001189B0 *)((char *)&D_0013D778[2 * 0 + 2] - 8))->fd->size & ~3) - nb);
        if ((((Chunk_001189B0 *)((char *)&D_0013D778[2 * 0 + 2] - 8))->fd->size & ~3) < nb || remainder_size < (long)16) {
            func_0011A3A8(reent);
            return 0;
        }
    }

    victim = ((Chunk_001189B0 *)((char *)&D_0013D778[2 * 0 + 2] - 8))->fd;
    victim->size = nb | 1;
    ((Chunk_001189B0 *)((char *)&D_0013D778[2 * 0 + 2] - 8))->fd = (Chunk_001189B0 *)((char *)victim + nb);
    ((Chunk_001189B0 *)((char *)&D_0013D778[2 * 0 + 2] - 8))->fd->size = remainder_size | 1;
    func_0011A3A8(reent);
    return (char *)victim + 8;
}
/* localdecomp:end func_001197E0 */

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

ASM_FUNC("asm/boot_elf/handwritten", func_0011A01C);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011A0B0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011A160);

ASM_FUNC("asm/boot_elf/handwritten", func_0011A264);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011A324);
