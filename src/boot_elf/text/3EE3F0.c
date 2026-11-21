#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 3EE290.c's earlier functions */
extern s32 *func_003E6FC0();
extern s32 func_003E74D0();
typedef struct { s32 a[0x12]; s32 x48; } S_E8;
typedef struct { u8 p[0x2C]; S_E8 *x2C; } T_E8;
extern u8 D_001D9708[8];
void **func_003E7078(s32 *, s32);
extern void func_003EE290(T_E8 *a0);

typedef struct { s32 *arr[16]; s32 x40; s32 x44; } O_3E8AD0;
typedef struct { u8 p0[8]; void *f8; u8 p1[0x2C - 0xC]; O_3E8AD0 *x2C; } T_3E8AD0;
typedef struct { u8 p0[4]; s32 f4; } S_3E8AD0;
typedef struct { s32 (*f0)(); s32 (*f4)(); s32 (*f8)(); s32 (*fC)(); } VT_3E8AD0;
extern u8 D_001D9708[8];
extern u8 D_001D9670_003EE3F0[8];
extern S_3E8AD0 D_001DA938_003EE3F0[];
extern s32 *func_003E6FC0();
extern s32 **func_003E7078_003EE3F0();
extern s32 func_003E74D0();
/* localdecomp:start func_003EE3F0 */
extern s32 func_003F2738();
static __inline__ S_3E8AD0 *get_003EE3F0(void) {
    S_3E8AD0 *d = D_001DA938_003EE3F0;
    if (d->f4 != 0) return d;
    return (S_3E8AD0 *)func_003E6FC0(d);
}
void func_003EE3F0(T_3E8AD0 *p, s32 flags) {
    O_3E8AD0 *a, *b;
    void **t;
    s32 **w;
    p->f8 = D_001D9708;
    func_003EE290((T_E8 *)p);
    a = p->x2C;
    if (a->x44 != 0) func_003E74D0(a->x44);
    a->x44 = 0;
    b = p->x2C;
    if (b->x44 != 0) func_003E74D0(b->x44);
    b->x44 = 0;
    if (b != 0) {
        w = b->arr + 16;
        while (b->arr != w) {
            w--;
            if (*w) func_003E74D0(*w);
            *w = 0;
        }
    }
    t = func_003E7078((s32 *)get_003EE3F0(), 1);
    if (t != 0) {
        ((VT_3E8AD0 *)*t)->fC(t, p->x2C);
        p->x2C = 0;
    }
    p->f8 = D_001D9670_003EE3F0;
    if (flags & 1) func_003F2738(p);
}
/* localdecomp:end func_003EE3F0 */
