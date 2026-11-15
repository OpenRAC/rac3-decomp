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
extern s32 func_00118CA8(void *, u32);

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
