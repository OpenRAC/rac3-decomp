#include "common.h"

/* NTSC-U counterpart of func_L01_003B3C48 (src/levels/shared/L01_003B3C48.c): 50 -> 60 */
extern u8 *D_L01_001E009C;
extern s32 func_L01_003B2450(u8 *, u8 *);
extern s32 D_L01_001DE674_003B2450;
extern s32 func_L01_003B4368(u8 *);

/* localdecomp:start func_L01_003B2450 */
typedef struct {
    u8 p0[0x58];
    u8 *next;
    u8 p5C[4];
    s32 time;
} St_003B3C48;
typedef struct {
    u8 p0[0x68];
    St_003B3C48 *st;
} Ob_003B3C48;
typedef struct {
    s32 w0;
    s32 time;
    Ob_003B3C48 *obj;
    s32 group;
    u8 p10[0x6C];
    s32 timeout;
    s32 timeout2;
    s32 check;
    s32 first;
    s32 second;
    s32 single;
    s32 all;
    s32 dead;
    s32 other;
    f32 val;
    s32 count;
    f32 val2;
    s32 count2;
} Cond_003B3C48;

extern s16 *D_L01_0021DEA0[];
extern s32 D_L01_001DFBC0_003B2450;
__asm__(".extern D_L01_001DFBC0_003B2450, 16");
extern u8 *D_L01_001E009C_003B2450;
__asm__(".extern D_L01_001E009C_003B2450, 16");
extern s32 D_L01_001E00D8;
__asm__(".extern D_L01_001E00D8, 4");
extern u8 D_001A4C60[];
extern s32 func_L01_00453210(void *, s32);
extern s32 func_L01_00452F60(void *);
extern s32 func_L01_00442998(s32, s32, s32);
extern s32 func_L01_003B4710(u8 *);
extern f32 func_L01_003B4480(u8 *, s32, s32, s32, s32);
extern s32 func_L01_003B4388_003B2450(u8 *, s32);
extern s32 func_L01_003B4730_003B2450(u8 *, s32);
extern s32 func_L01_003B46F0_003B2450(u8 *, s32);
extern f32 func_L01_003B4760_003B2450(u8 *, s32);
extern s32 func_L01_003B47C8_003B2450(u8 *, s32);

s32 func_L01_003B2450(u8 *a0, u8 *a1) {
    Cond_003B3C48 *c = (Cond_003B3C48 *)a1;
    St_003B3C48 *init = c->obj->st;

    if (c->timeout != 0 && c->timeout * 60 < D_L01_001DFBC0_003B2450 - c->time) {
        return 1;
    }
    if (c->timeout2 != 0 && c->timeout2 * 60 < D_L01_001DFBC0_003B2450 - init->time) {
        return 1;
    }
    if (c->first != 0) {
        s16 *q = D_L01_0021DEA0[c->group];
        while ((c->group & 0xFF) != 0xFF && c->group <= D_L01_001E00D8 && q != 0 &&
               (q[-1] >= 0 || q == D_L01_0021DEA0[c->group])) {
            u8 *r = D_L01_001E009C_003B2450 + ((*(u16 *)q & 0x7FFF) << 8);
            if (r == 0) break;
            if (func_L01_003B4368(r) && func_L01_003B4388_003B2450(r, 1)) {
                return 1;
            }
            q++;
        }
    }
    if (c->second != 0) {
        s16 *q = D_L01_0021DEA0[c->group];
        while ((c->group & 0xFF) != 0xFF && c->group <= D_L01_001E00D8 && q != 0 &&
               (q[-1] >= 0 || q == D_L01_0021DEA0[c->group])) {
            u8 *r = D_L01_001E009C_003B2450 + ((*(u16 *)q & 0x7FFF) << 8);
            if (r == 0) break;
            if (func_L01_003B4710(r) && func_L01_003B4730_003B2450(r, 1)) {
                return 1;
            }
            q++;
        }
    }
    if (D_L01_001DE674_003B2450 != 0) {
        u8 *o = (u8 *)D_L01_001DE674_003B2450;
        f32 sum, sum2;
        s32 n, n2, total, total2;
        sum2 = 0.0f;
        total = 0;
        total2 = 0;
        n = 0;
        n2 = 0;
        sum = sum2;
        do {
            St_003B3C48 *p = ((Ob_003B3C48 *)o)->st;
            if (func_L01_003B4368(o)) {
                if (c->val >= 0.0f) {
                    f32 v = func_L01_003B4480(o, 1, 1, 0, 0);
                    if (v >= 0.0f) {
                        sum += v;
                        n++;
                    }
                } else if (c->count >= 0) {
                    total += func_L01_003B46F0_003B2450(o, 1);
                    n++;
                } else if (func_L01_003B4388_003B2450(o, 1)) {
                    return 1;
                }
            } else if (func_L01_003B4710(o)) {
                if (c->val2 >= 0.0f) {
                    sum2 += func_L01_003B4760_003B2450(o, 1);
                    n2++;
                } else if (c->count2 < 0) {
                    if (func_L01_003B4730_003B2450(o, 1)) {
                        return 1;
                    }
                } else {
                    total2 += func_L01_003B47C8_003B2450(o, 1);
                    n2++;
                }
            }
            o = p->next;
        } while (o != 0);
        if (c->val >= 0.0f) {
            if (n >= 2) sum /= n;
            if (c->val <= sum) return 1;
        } else if (c->count >= 0 && total >= c->count) {
            return 1;
        }
        if (c->val2 >= 0.0f) {
            if (n2 >= 2) sum2 /= n2;
            if (c->val2 <= sum2) return 1;
        } else if (c->count2 >= 0 && total2 >= c->count2) {
            return 1;
        }
    }
    if (c->check != -1 && func_L01_00453210(D_001A4C60, c->check)) {
        return 1;
    }
    if (c->single != -1 && func_L01_00452F60(D_L01_001E009C + (c->single << 8))) {
        return 1;
    }
    if (c->all != -1) {
        s32 ok = 1;
        s16 *q = D_L01_0021DEA0[c->all];
        while ((c->all & 0xFF) != 0xFF && c->all <= D_L01_001E00D8 && q != 0 &&
               (q[-1] >= 0 || q == D_L01_0021DEA0[c->all])) {
            u8 *r = D_L01_001E009C_003B2450 + ((*(u16 *)q & 0x7FFF) << 8);
            if (r == 0) break;
            if (!func_L01_00452F60(r)) {
                ok = 0;
                break;
            }
            q++;
        }
        if (ok) return 1;
    }
    if (c->dead != -1) {
        u8 *r = D_L01_001E009C + (c->dead << 8);
        if (r == 0) return 1;
        if (r[0x20] == 0xFE) return 1;
        if (r[0x20] == 0xFD) return 1;
    }
    if (c->other != -1 && !func_L01_00442998(c->other, -1, 0)) {
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_003B2450 */
