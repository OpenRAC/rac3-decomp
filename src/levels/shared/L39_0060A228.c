#include "common.h"

typedef struct {
    long pts;
    long dts;
    s32 pos;
    s32 len;
} Ent_0060A330;
typedef struct {
    u32 base;
    u32 pad4;
    u32 count;
    u8 pad0C[0x2C];
    u32 f38;
    u8 pad3C[4];
    void *sema;
    u8 pad44[0xC];
    Ent_0060A330 *tbl;
    s32 ntbl;
    s32 f58;
    s32 f5C;
} VB_0060A330;
typedef struct {
    long pts;
    long dts;
} TS_0060A330;

/* localdecomp:start func_L39_0060A228 */
typedef struct { long f0; long f8; s32 f10; s32 f14; } Type1;
typedef struct { u8 p0[0x40]; s32 f40; u8 p44[0xC]; Type1 *f50; s32 f54; s32 f58; s32 f5C; } Type2;
extern s32 func_001262A0(s32);
extern void func_00126280(s32);
extern s32 func_003B20A8();

/* from rac4-decomp's func_004F1848, renamed */
s32 func_L39_0060A228(Type2 *a, Type1 *b) {
    s32 r = 0;
    func_001262A0(a->f40);
    if (a->f58 < a->f54) {
        func_003B20A8(a, b);
        if (b->f0 >= 0 || b->f8 >= 0) {
        a->f50[a->f5C].f0 = b->f0;
        a->f50[a->f5C].f8 = b->f8;
        a->f50[a->f5C].f10 = b->f10;
        a->f50[a->f5C].f14 = b->f14;
        a->f58 = a->f58 + 1;
        a->f5C = (a->f5C + 1) % a->f54;
        }
        r = 1;
    }
    func_00126280(a->f40);
    return r;
}
/* localdecomp:end func_L39_0060A228 */

/* localdecomp:start func_L39_0060A330 */
extern s32 func_1262A0(void *);
extern void func_126280(void *);

s32 func_L39_0060A330(VB_0060A330 *vb, TS_0060A330 *ts) {
    u32 madr = *(volatile u32 *)0x1000B410;
    u32 top = *(volatile u32 *)0x10002020;
    s32 bp = vb->f38 & 0x7F;
    s32 size = vb->count << 11;
    s32 found = 0;
    s32 pos;
    s32 n;
    s32 end;
    s32 j;

    madr -= (((top >> 16) & 3) + ((top >> 8) & 0xF)) << 4;
    func_1262A0(vb->sema);
    ts->pts = -1;
    ts->dts = -1;
    madr += bp >> 3;
    madr += size;
    pos = (madr - vb->base) % size;
    n = vb->f58;
    end = vb->f5C;
    for (j = 0; j < n && !found; j++) {
        s32 k = (end - n + vb->ntbl + j) % vb->ntbl;
        if ((pos + size - vb->tbl[k].pos) % size < vb->tbl[k].len) {
            found = 1;
            ts->pts = vb->tbl[k].pts;
            ts->dts = vb->tbl[k].dts;
            vb->tbl[k].pts = -1;
            vb->tbl[k].dts = -1;
            vb->f58 -= (vb->f58 < 2) ? vb->f58 : 1;
        }
    }
    func_126280(vb->sema);
    return 1;
}
/* localdecomp:end func_L39_0060A330 */

/* localdecomp:start func_L39_0060A4C8 */
extern int func_L39_0060AA28(void *, int *);
extern int func_003B2A00(void);
extern int func_L01_004D5A50(void);
extern int func_L01_004D5A78(void);
extern int func_003B2A80(void *, void *);
extern void func_003B25E0(u8 *);
extern void func_00142728(void *);
extern void func_00143388(void *, int, void *, int);
extern void func_L39_006096D0(void *, int, int, int, int, int);

/* from rac2-decomp's func_00351720, renamed */
int func_L39_0060A4C8(char *object, int unused1, int unused2, int a, int b, int c, int d, int e)
{
    func_00142728(object);
    func_00143388(object, 0, func_L39_0060AA28, 0);
    func_00143388(object, 1, func_003B2A00, 0);
    func_00143388(object, 2, func_L01_004D5A50, 0);
    func_00143388(object, 3, func_L01_004D5A78, 0);
    func_00143388(object, 5, func_003B2A80, 0);
    func_003B25E0((u8 *)object);
    func_L39_006096D0(object + 0x48, a, b, c, d, e);
    return 1;
}
/* localdecomp:end func_L39_0060A4C8 */
