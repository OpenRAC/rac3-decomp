#include "common.h"

typedef struct { u8 pad[0x2D8]; s32 x2D8; s32 x2DC; u8 pad2E0[0x2F8 - 0x2E0]; s32 x2F8; } X_006683F8;
typedef struct { u8 pad[0x2528]; X_006683F8 *x2528; u8 pad2[0x254C - 0x252C]; s32 x254C; } P_006683F8;

/* declared by functions of L39_00666F88.c, which this file was cut from */
extern s32 func_L39_0061BF68(void *);
extern void func_L01_003F2278(s32, void *);

/* localdecomp:start func_L39_00667700 */
#include "vu0.h"
typedef struct T_00667700 { u8 p0[0xB8]; s32 wB8; u8 pBC[2]; u8 bBE; } T_00667700;
typedef struct Q_00667700 { u8 p0[0x2524]; s32 w2524; } Q_00667700;
typedef struct X_00667700 { u8 p0[0x2D0]; T_00667700 *w2D0; u8 p2D4[4]; void *w2D8; Q_00667700 *w2DC; u8 p2E0[0x306 - 0x2E0]; s16 h306; } X_00667700;
typedef struct E_00667700 { s32 w0; s32 w4; s32 w8; u8 pad[0x10]; } E_00667700;
extern E_00667700 D_L39_004840A0[];
extern u8 D_L39_004997E0[];
__asm__(".extern D_L39_00243F20, 16");
extern s32 D_L39_00243F20[2];
extern void func_0038CF68(void *, void *, f32);

typedef union Buf_00667700 { u8 b[8]; u32 w[2]; } Buf_00667700;

/* the 0x19E4 check-byte decode and state test, as func_L39_00663DA8's Dec_/IsState_ helpers in L39_00663950.c */
static __inline__ u32 Dec_00667700(u8 *q) {
    Buf_00667700 buf;
    u32 r;
    s32 n;
    s32 m;
    s32 k;
    s32 i;
    u8 *d;

    if (*q == 0) {
        r = 0;
    } else {
        n = *q;
        m = n + 1;
        k = ((s32)q - n) & 7;
        d = buf.b;
        for (i = 0; i < 40; i += 5) {
            *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
        }
        buf.w[0] ^= (u32)q;
        buf.w[1] ^= buf.w[0];
        r = buf.w[1];
    }
    return r;
}

static __inline__ s32 IsState_00667700(u8 *o, u32 st) {
    u8 r;

    if (*(u8 **)(o + 0x2530) != 0) {
        r = 0;
        if ((*(u8 **)(o + 0x2530))[0x27B] != 0 && (Dec_00667700(o + 0x19E4) ^ st) == 0) {
            r |= 1;
        }
    } else {
        r = 0;
    }
    return r;
}

void func_L39_00667700(X_00667700 *x, u8 *g, s32 keep) {
    u8 saved;

    saved = g[0x1A0A];
    x->w2D8 = 0;
    if (g != 0) {
        *(T_00667700 **)(g + 0x2578) = x->w2D0;
        *(s32 *)(g + 0x360) = 0x32;
        D_L39_004840A0[*(s32 *)(g + 0x2544)].w0 = 5;
        D_L39_004840A0[*(s32 *)(g + 0x2544)].w8 = 10;
        *(s32 *)(g + 0x2528) = 0;
        *(s32 *)(g + 0x254C) = 0;
        *(s32 *)(g + 0xB0) = 0;
        *(s32 *)(g + 0xB4) = 0;
        if (!(u8)IsState_00667700(g, 0x31)) {
            (*(void (**)(void *, s32, s32, s32, s32))(*(u8 **)(g + 0x14) + 0x34))(g, 0, 1, 0, 1);
            if (keep != 0) {
                g[0x1A0A] = 0;
            } else {
                g[0x1A0A] = saved;
            }
        }
        x->h306++;
        if (x->h306 >= 4) {
            x->h306 = 0;
        }
        if (g[0x1A14] != 0) {
            u32 buf[4] __attribute__((aligned(16)));
            func_0038CF68(buf, D_L39_00243F20, *(f32 *)(g + 0x132C));
            vec_add_ab(g + 0x1180, g + 0xA0, buf);
        }
    }
    if (x->w2DC != 0) {
        x->w2D0->wB8 = x->w2DC->w2524;
    } else {
        x->w2D0->bBE &= 0xF7;
        x->w2D0->bBE &= 0xEF;
        x->w2D0->wB8 = 0;
    }
}
/* localdecomp:end func_L39_00667700 */
