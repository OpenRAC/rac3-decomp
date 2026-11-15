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

/* localdecomp:start func_00118838 */
typedef struct { u8 *p; s32 r; s32 w; s16 flags; s16 file; u8 *base; s32 size; s32 lbfsize; void *cookie; void *read; void *write; void *seek; void *close; u8 pad[0x24]; void *data; } F_118838;
extern s32 func_0011B378();
extern s32 func_0011B3E0();
extern long func_0011B460();
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

/* localdecomp:start func_001188C0 */
typedef struct {
    u8 pad0[0x38];
    s32 sdidinit;
    void (*cleanup)(void *);
    u8 pad40[0x1D8 - 0x40];
    void *glue_next;
    s32 glue_niobs;
    F_118838 *glue_iobs;
    F_118838 sf[3];
} Reent_1188C0;
extern void func_00118898(void *);
void func_001188C0(Reent_00118720 *p) {
    Reent_1188C0 *s = (Reent_1188C0 *)p;

    s->cleanup = func_00118898;
    s->sdidinit = 1;
    func_00118838(&s->sf[0], 4, 0, s);
    func_00118838(&s->sf[1], 9, 1, s);
    func_00118838(&s->sf[2], 0xA, 2, s);
    s->glue_next = 0;
    s->glue_niobs = 3;
    s->glue_iobs = &s->sf[0];
}
/* localdecomp:end func_001188C0 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011894C);
