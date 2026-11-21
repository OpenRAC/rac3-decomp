#include "common.h"

/* declared by functions of L39_0066C808.c, which this file was cut from */
typedef struct {
    u8 pad0[52];
    u16 unk34;
} Src669F78;
typedef struct {
    u8 pad0[8];
    s32 unk8;
} Info669F78;
extern Info669F78 *func_L39_005C1018(Src669F78 *);

/* localdecomp:start func_L39_0066CDD0 */
typedef struct { u8 p0[8]; s32 w8; u8 pC[0xC]; Src669F78 *w18; u8 p1C[4]; void (*fn20)(Src669F78 *); s32 w24; u8 p28[4]; u8 b2C; u8 p2D[3]; s32 w30; u8 p34[0x10]; s32 w44; s32 w48; s32 w4C; u8 p50; u8 b51; } O_0066CDD0;
typedef struct { u8 p0[8]; s32 w8; u8 pC[0x11C]; s32 w128; } G_0066CDD0;
typedef struct { u8 p0[0x14]; void (*fn14)(Src669F78 *, s32); } V_0066CDD0;
extern s32 D_001A5CD0[];
extern s32 D_001A5DF8[];
extern s32 D_L39_00246334;
__asm__(".extern D_L39_00246334, 4");
__asm__(".extern D_L39_00246338, 4");
extern f32 D_L39_00246338;
extern s32 *D_L39_00241120;
extern s32 D_L39_0024112C;
extern Info669F78 *func_L39_005C1018(Src669F78 *);
extern s32 func_L39_0066CB78(void *);
extern s32 func_L39_0066D028(void *, f32 *, f32 *);
extern void func_L39_0066DA90(s32 *, s32, u8, u8);
extern void func_L39_0066DB50(s32 *, s32, u8, u8);
extern void func_L39_0066DC28(s32 *, u8, u8);
void func_L39_0066CDD0(O_0066CDD0 *o) {
    f32 pos[2];
    s32 n;
    s32 same;
    s32 *g;
    if (o->w18 == 0) return;
    if (o->w24 >= 0 && o->w24 <= D_001A5DF8[0]) {
        o->w24 = -1;
        ((V_0066CDD0 *)func_L39_005C1018(o->w18))->fn14(o->w18, 0);
    }
    if (o->fn20 != 0) o->fn20(o->w18);
    if (o->b2C == 0) return;
    if (o->w8 == 2) return;
    g = D_001A5CD0;
    if (!(D_L39_00246334 + 3000 < g[0x128 / 4])) return;
    if (o->w44 == -1) o->w44 = func_L39_0066CB78(o);
    same = 1;
    if (*D_L39_00241120 >= 3) { s32 t = ((s32)o->w18 >> 8 ^ D_L39_0024112C) & 0xF; same = t == 0; }
    if (!same) return;
    if (o->w44 != g[2]) return;
    if (o->w30 + 3000 >= g[0x128 / 4] && o->w48 != -1) return;
    n = func_L39_0066D028(o, &pos[0], &pos[1]);
    if (o->w48 == -1) {
        if (n != -1) {
            func_L39_0066DA90((s32 *)o, n, o->b51, ((u8 *)g)[8]);
            o->w4C = -1;
            o->w48 = n;
            o->b51++;
            return;
        }
    } else if (n == -1) {
        func_L39_0066DC28((s32 *)o, o->b51, ((u8 *)g)[8]);
        o->w48 = n;
        o->w4C = -1;
        o->b51++;
        return;
    }
    if (o->w48 == n) return;
    if (o->w48 == -1) return;
    if (n == -1) return;
    if (pos[1] > D_L39_00246338 && (pos[0] < D_L39_00246338 || pos[0] < pos[1] * 0.5f)) {
        s32 old;
        u8 *q = (u8 *)D_001A5CD0;
        func_L39_0066DB50((s32 *)o, n, o->b51, q[8]);
        old = o->w48;
        o->w48 = n;
        o->w4C = old;
        o->b51 = o->b51 + 1;
    }
}
/* localdecomp:end func_L39_0066CDD0 */

/* localdecomp:start func_L39_0066D028 */
#include "vu0.h"

typedef struct {
    u8 pad0[0x10];
    f32 pos[4];
    u8 pad20[0x30 - 0x20];
    u8 unk30;
    u8 pad31[0xBE - 0x31];
    u8 unkBE;
} Cfg_0066D028;

typedef struct {
    u8 pad0[0x18];
    Cfg_0066D028 *unk18;
    u8 pad1C[0x48 - 0x1C];
    s32 unk48;
} Obj_0066D028;

typedef struct {
    s32 w0;
    s32 w4;
} Lnk_0066D028;

typedef struct {
    u8 pad0[0xA0];
    f32 pos[4];
    u8 padB0[0x19E4 - 0xB0];
    u8 b19E4;
    u8 pad19E5;
    u8 b19E6;
    u8 pad19E7[0x2528 - 0x19E7];
    s32 w2528;
    u8 pad252C[0x2548 - 0x252C];
    s32 w2548;
    u8 pad254C[0x2558 - 0x254C];
    Lnk_0066D028 *p2558;
} Pl_0066D028;

extern Pl_0066D028 *D_L39_0024CE20[] __attribute__((section(".sdata")));
extern u8 D_L39_004997E0[];
extern f32 func_L01_0040E548(void *, void *);
extern f32 D_L39_0024633C;
extern f32 D_L39_00246340;
extern f32 D_L39_00246344;
__asm__(".extern D_L39_0024633C, 4");
__asm__(".extern D_L39_00246340, 4");
__asm__(".extern D_L39_00246344, 4");

typedef union Buf_0066D028 {
    u8 b[8];
    u32 w[2];
} Buf_0066D028;

/* reads an obfuscated 32-bit state stored as an index byte at q */
static __inline__ s32 get_state_0066D028(u8 *q) {
    Buf_0066D028 buf;
    u8 *w;
    s32 m;
    s32 k;
    s32 n;
    s32 j;
    long t;

    t = *q;
    if (t == 0) {
        return 0;
    }
    n = *q;
    m = n + 1;
    k = ((u32)q - n) & 7;
    w = buf.b;
    for (j = 0; j < 40; j += 5) {
        *w++ = D_L39_004997E0[m + ((k + j) & 7) * 255];
    }
    buf.w[0] ^= (u32)q;
    buf.w[1] ^= buf.w[0];
    return buf.w[1];
}

static __inline__ s32 get_team_0066D028(s32 n) {
    Pl_0066D028 *p;
    s32 x;
    s16 flag;

    if ((u32)n < 8 && D_L39_0024CE20[n] != 0) {
        flag = 0;
        p = D_L39_0024CE20[n];
        x = get_state_0066D028(&p->b19E4);
        if ((x ^ 0x92) != 0) {
            if (p->p2558 != 0) {
                if (p->p2558->w4 != 0) {
                    flag++;
                }
            }
        }
        if ((u8)flag) {
            return D_L39_0024CE20[n]->p2558->w0;
        }
    }
    return -1;
}

s32 func_L39_0066D028(void *obj, f32 *a, f32 *b) {
    Obj_0066D028 *o = obj;
    s32 best = -1;
    s32 i;
    Pl_0066D028 *p;
    f32 r;
    f32 r2;
    f32 d;
    f32 dist;
    f32 len;
    s32 x;
    s16 flag;

    r = o->unk18->unk30;
    if (o->unk18->unk30 == 0xFF) {
        r = 1024.0f;
    }
    r2 = r * r;
    *a = r + 1.0f;
    *b = r + 1.0f;
    for (i = 0; i < 8; i++) {
        p = D_L39_0024CE20[i];
        if (p == 0) {
            continue;
        }
        dist = func_L01_0040E548(p->pos, o->unk18->pos);
        if (dist < r2) {
            len = sqrt_asm(dist);
            d = len;
            if (p->w2548 == 0 && (o->unk18->unkBE & 0x10)) {
                d += D_L39_0024633C;
            } else if (p->w2548 == 1 && (o->unk18->unkBE & 8)) {
                d = len + D_L39_0024633C;
            }
            x = get_state_0066D028(&p->b19E6);
            if ((x ^ 0x14) == 0) {
                d += D_L39_00246340;
            }
            if (p->w2528 != 0) {
                d += D_L39_00246344;
            }
            if (r < d) {
                d = r;
            }
            if (i == o->unk48) {
                *b = d;
            }
            if (d < *a) {
                *a = d;
                best = i;
            }
        }
    }
    best = get_team_0066D028(best);
    return best;
}
/* localdecomp:end func_L39_0066D028 */
