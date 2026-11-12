#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_0054A250);

/* localdecomp:start func_L39_0054A8E0 */
extern s32 D_L39_00241118;
extern void func_L39_005FE358(u8 *, u8 *, s32, s32, f32);

void func_L39_0054A8E0(u8 *m) {
    u8 *p;
    u8 *q;

    if (m == 0) {
        return;
    }
    if (m[32] == 254) {
        return;
    }
    if (m[32] == 253) {
        return;
    }
    p = *(u8 **)(m + 104);
    if (p == 0) {
        return;
    }
    q = *(u8 **)(p + 64);
    if (q == 0) {
        return;
    }
    if (q[9417] != D_L39_00241118) {
        return;
    }
    if (*(s32 *)(p + 52) == 0) {
        return;
    }
    func_L39_005FE358(p, p + 16, 0, 1, 1.0f);
}
/* localdecomp:end func_L39_0054A8E0 */

/* localdecomp:start func_L39_0054A960 */
typedef struct {
    float pos[3];
    char pad0C[52];
    struct { char pad[728]; short h; } *p64;
    int p68;
} Src0054A040;

typedef struct {
    char pad0[104];
    Src0054A040 *src;
} Obj0054A040;

typedef struct {
    char pad0[2];
    unsigned char flags;
    unsigned char type;
    char pad4[4];
    unsigned int w8;
    float a[3];
    float b[3];
} Msg0054A040;

extern int func_L39_0061D780(int);

void func_L39_0054A960(Obj0054A040 *obj, Msg0054A040 *msg)
{
    Src0054A040 *s;
    float *d;
    float *p;

    if (msg->type != 8)
        return;
    s = obj->src;
    d = msg->b;
    p = (float *)((char *)s + 32);
    d[0] = p[0];
    d[1] = p[1];
    d[2] = p[2];
    if (s->p68) {
        msg->w8 = func_L39_0061D780(s->p68);
    } else {
        if (s->p64 && s->p64->h) {
            msg->flags |= 0x80;
        }
        msg->w8 = 0xFFFFFFFF;
    }
    {
        float *dd = msg->a;
        float *pp = s->pos;
        dd[0] = pp[0];
        dd[1] = pp[1];
        dd[2] = pp[2];
    }
}
/* localdecomp:end func_L39_0054A960 */

INCLUDE_ASM("asm/levels", func_L39_0054AA20);

INCLUDE_ASM("asm/levels", func_L39_0054AB58);

/* localdecomp:start func_L39_0054ABC0 */
typedef struct {
    u8 pad0[0x64];
    s32 w64;
    s32 w68;
} S_0054ABC0;
typedef struct {
    u8 pad0[0x68];
    S_0054ABC0 *p68;
    u8 pad6C[0x94 - 0x6C];
    u8 b94;
} O_0054ABC0;

extern s32 D_L39_003BDD20[][24];

void func_L39_0054ABC0(O_0054ABC0 *o) {
    S_0054ABC0 *s = o->p68;

    if (s->w64 != -1) {
        o->b94 = s->w64;
        D_L39_003BDD20[s->w68][s->w64] = 0;
    }
}
/* localdecomp:end func_L39_0054ABC0 */

INCLUDE_ASM("asm/levels", func_L39_0054AC10);

INCLUDE_ASM("asm/levels", func_L39_0054B4B8);

INCLUDE_ASM("asm/levels", func_L39_0054C2B0);

INCLUDE_ASM("asm/levels", func_L39_0054C400);
