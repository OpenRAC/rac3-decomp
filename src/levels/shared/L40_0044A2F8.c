#include "common.h"

typedef struct {
    s32 a;
    s16 b;
    s16 c;
    s32 id;
    s32 pad;
} Ent00449588;
extern Ent00449588 D_L40_00257F40[];

/* localdecomp:start func_L40_0044A2F8 */
extern s32 D_L40_00242440;
typedef struct {
    s32 lo;
    s32 hi;
} R_0044A2F8;
extern R_0044A2F8 D_L40_00242448;
extern s32 D_L40_0024243C;
extern s32 D_L40_00242438;

static __inline__ s32 wrap_0044A2F8(s32 r, s32 *z)
{
    R_0044A2F8 *t = &D_L40_00242448;
    s32 i;
    s32 n;

    if (r >= t[*z].hi) {
        i = 0;
        do {
            n = 0;
            r += t[n].lo - t[i].hi;
            i = n;
        } while (r >= t[i].hi);
        *z = i;
    }
    return r;
}

static __inline__ void decode_0044A2F8(s32 h, s16 *v, s32 *k)
{
    s32 z;
    s32 x;

    if (h & 1) {
        *k = (h >> 1) & 0x3FFFFF;
        *v = (h >> 23) << 2;
    } else {
        x = (s32)(((long)D_L40_00242440 * (long)(h >> 12)) >> 20) + D_L40_00242448.lo;
        z = 0;
        *v = (h >> 1) & 0x7FF;
        x = wrap_0044A2F8(x, &z);
        *k = x;
    }
}

s32 func_L40_0044A2F8(s32 a0, s32 *a1, s16 *a2)
{
    s16 v;
    s32 k;
    s32 i;
    Ent00449588 *p;

    decode_0044A2F8(a0, &v, &k);
    if (((D_L40_0024243C + 1) & 0xF) == D_L40_00242438) {
        return 0;
    }
    p = D_L40_00257F40;
    for (i = 0; i < 16; i++) {
        if (k == p->a && v == p->b) {
            return 0;
        }
        p++;
    }
    *a1 = k;
    *a2 = v;
    return 1;
}
/* localdecomp:end func_L40_0044A2F8 */

/* localdecomp:start func_L40_0044A430 */
extern s32 D_L40_0024243C;
extern s32 D_L40_00242428;
extern u16 D_L40_00242424;
extern s32 func_L40_0044A2F8(s32 a0, s32 *a1, s16 *a2);
s32 func_L40_0044A430(s32 a0) {
    s32 id;
    if (func_L40_0044A2F8(a0, &D_L40_00257F40[D_L40_0024243C].a, &D_L40_00257F40[D_L40_0024243C].b) != 0) {
        D_L40_00257F40[D_L40_0024243C].c = 1;
        id = (s16)(D_L40_00242424 | (*(u16 *)&D_L40_00242428 << 6));
        D_L40_00257F40[D_L40_0024243C].id = id;
        D_L40_00242428++;
        D_L40_0024243C = (D_L40_0024243C + 1) & 15;
        return id;
    }
    return 0;
}
/* localdecomp:end func_L40_0044A430 */

/* localdecomp:start func_L40_0044A4C8 */
s32 func_L40_0044A4C8(s32 a0, u8 *a1) {
    if (D_L40_00257F40[a0 & 0x2F].id == a0 && D_L40_00257F40[a0 & 0x2F].c == -1) {
        *(s32 *)a1 = D_L40_00257F40[a0 & 0x2F].pad;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L40_0044A4C8 */
