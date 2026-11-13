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

/* localdecomp:start func_L39_0054AA20 */
typedef struct {
    u8 pad0[8];
    s32 w8;
    u8 pad0C[0x128 - 0xC];
    s32 w128;
} S_1A5CD0_0054AA20;

extern S_1A5CD0_0054AA20 D_001A5CD0_0054AA20;
extern s32 D_L39_0024B038_0054AA20;
__asm__(".extern D_L39_0024B038_0054AA20, 4");
extern s32 D_L39_003BDD20[][24];

s32 func_L39_0054AA20(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 24; i++) {
        if (D_L39_003BDD20[D_001A5CD0_0054AA20.w8][i] == 0) {
            for (j = 0; j < 8; j++) {
                if ((&D_L39_0024B038_0054AA20)[j * 2] == i && D_001A5CD0_0054AA20.w128 - 2000 < (&D_L39_0024B038_0054AA20)[j * 2 + 1]) {
                    break;
                }
                if ((&D_L39_0024B038_0054AA20)[j * 2] == i) {
                    (&D_L39_0024B038_0054AA20)[j * 2] = -1;
                }
            }
            if (j < 8) {
                continue;
            }
            for (j = 0; j < 8; j++) {
                if ((&D_L39_0024B038_0054AA20)[j * 2] == -1) {
                    (&D_L39_0024B038_0054AA20)[j * 2] = i;
                    (&D_L39_0024B038_0054AA20)[j * 2 + 1] = D_001A5CD0_0054AA20.w128;
                    break;
                }
            }
            return i;
        }
    }
    return -1;
}
/* localdecomp:end func_L39_0054AA20 */

/* localdecomp:start func_L39_0054AB58 */
typedef struct {
    u8 pad0[0x128];
    s32 w128;
} S_1A5CD0_0054AB58;
typedef struct {
    s32 id;
    s32 t;
} E_0054AB58;

extern S_1A5CD0_0054AB58 D_001A5CD0;
extern E_0054AB58 D_L39_0024B038;
__asm__(".extern D_L39_0024B038, 8");
extern s32 D_L39_0024B03C[] __attribute__((section(".sdata")));

void func_L39_0054AB58(s32 a) {
    s32 i;

    for (i = 0; i < 8; i++) {
        if ((&D_L39_0024B038)[i].id == a) {
            if (D_001A5CD0.w128 - 2000 < D_L39_0024B03C[i * 2]) {
                (&D_L39_0024B038)[i].id = -1;
                return;
            }
        }
    }
}
/* localdecomp:end func_L39_0054AB58 */

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
