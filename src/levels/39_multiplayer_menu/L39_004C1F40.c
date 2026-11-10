#include "common.h"

/* declared by functions of L39_004BB4C0.c, which this file was cut from */
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

/* localdecomp:start func_L39_004C1F40 */
typedef struct B_004C1F40 {
    u8 pad0[0x10];
    u32 len;
    u8 data[1];
} B_004C1F40;

typedef struct A_004C1F40 {
    u8 pad0[0x6C];
    u32 len6C;
    u8 data70[0x90 - 0x70];
    u32 len90;
    u8 data94[0xA4 - 0x94];
    u32 total;
    u8 dataA8[1];
} A_004C1F40;

typedef struct S_004C1F40 {
    u8 pad0[0x50];
    A_004C1F40 *a;
    u8 pad54[0xB0 - 0x54];
    B_004C1F40 *b;
} S_004C1F40;

extern void *func_L39_004DE940(void);
extern s32 func_L39_004DF698(void);
extern void func_L39_004DD690(void *, s32);
extern u32 func_L39_004DE8E8(void *);
extern void func_L39_004DD778(void *, void *, u32);
extern void func_L39_004DD7A8(void *, void *, void *);
extern void func_L39_004DE9B8(void *);

typedef struct L_004C1F40 {
    u8 c;
    u32 out[3];
} L_004C1F40;

void func_L39_004C1F40(S_004C1F40 *s) {
    L_004C1F40 l;
    void *ctx;
    u32 step;
    u32 i;
    u8 *p;

    l.c = '0';
    i = 0;
    ctx = func_L39_004DE940();
    func_L39_004DD690(ctx, func_L39_004DF698());
    step = func_L39_004DE8E8(ctx);
    p = s->a->dataA8;
    while (i < s->a->total) {
        func_L39_004DD690(ctx, 0);
        i += step;
        func_L39_004DD778(ctx, s->b->data, s->b->len);
        func_L39_004DD778(ctx, &l.c, 1);
        l.c++;
        func_L39_004DD778(ctx, s->a->data70, s->a->len6C);
        func_L39_004DD778(ctx, s->a->data94, s->a->len90);
        func_L39_004DD7A8(ctx, p, l.out);
        p += step;
    }
    func_L39_004DE9B8(ctx);
}
/* localdecomp:end func_L39_004C1F40 */

/* localdecomp:start func_L39_004C2068 */
/* Near miss, ported from rac4-decomp's func_L00_004FDE68 (cross-game near pair). NEAR: SQ_RA: frame 0x20/ra@0x10 vs 0x10; v0/v1 swap in inner-pointer loads goes with it; rest of body identical */
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

extern char *func_L39_004BEED8(void);
extern int func_L39_004C2118(void *, int);
typedef struct Inner { int pad[12]; int ready; void *value; } Inner;
typedef struct Outer { char pad[80]; Inner *inner; char pad2[188]; unsigned int size; int other; } Outer;

int func_L39_004C2068(Outer *p)
{
    void *value;
    unsigned int size;
    if (p->inner->ready == 0 && func_L39_004C2118(p, p->other) == 0) goto fail;
    if (p->inner->value) goto success;
    size = p->size;
    if (size - 1 > 0x8000) { p->size = 0x8001; size = 0x8001; }
    value = ((void *(*)(unsigned int))func_L39_004BEED8)(size);
    if (!value) goto fail;
    p->inner->value = value;
success:
    return 1;
fail:
    func_L39_004BC6C8(20, 219, 33, 0, 0);
    return 0;
}
/* localdecomp:end func_L39_004C2068 */

INCLUDE_ASM("asm/levels", func_L39_004C2118);

INCLUDE_ASM("asm/levels", func_L39_004C21E0);

INCLUDE_ASM("asm/levels", func_L39_004C22B0);

INCLUDE_ASM("asm/levels", func_L39_004C23A0);

INCLUDE_ASM("asm/levels", func_L39_004C23F8);
