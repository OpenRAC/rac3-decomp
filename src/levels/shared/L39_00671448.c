#include "common.h"

/* declared by functions of L39_00670968.c, which this file was cut from */
extern void *func_0011D534(void *, s32, s32);

/* localdecomp:start func_L39_00671448 */
#include "vu0.h"

typedef struct {
    vu0_v4 m0;
    vu0_v4 m10;
    vu0_v4 m20;
    vu0_v4 pos;
    u8 pad40[0x30];
    vu0_v4 rot;
} Spawn_00671448;

typedef struct {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 pad20[0xE0];
} Moby_00671448;

typedef struct {
    u8 pad0[0xC60];
    s32 wC60;
    s32 wC64;
} Slot_00671448;

typedef struct {
    u8 pad0[0xA0];
    vu0_v4 pos;
    u8 padB0[0x1F4 - 0xB0];
    f32 f1F4;
    u8 pad1F8[0x19E4 - 0x1F8];
    u8 b19E4;
    u8 b19E5;
    u8 b19E6;
    u8 pad19E7[0x2524 - 0x19E7];
    u8 *p2524;
    u8 pad2528[0x2544 - 0x2528];
    s32 w2544;
    s32 w2548;
    u8 pad254C[0x2558 - 0x254C];
    Slot_00671448 *p2558;
} Player_00671448;

typedef struct {
    s32 a[8];
    s32 b[8];
    u8 pad40[0x48];
    s32 t88[8];
    s32 tA8[8];
    s32 tC8[8];
} TList_00671448;

typedef struct {
    s32 idx[64];
    u8 pad100[4];
    s32 w104;
    s32 w108;
} DList_00671448;

typedef struct {
    u8 pad0[0x20C];
    TList_00671448 *p20C;
    u8 pad210[4];
    DList_00671448 *p214;
} G_00671448;

typedef struct {
    u8 pad0[0x178];
    s32 w178;
    u8 pad17C[4];
    s32 w180;
} Mode_00671448;

typedef union {
    u8 b[8];
    u32 w[2];
} Buf_00671448;

extern G_00671448 D_L39_00352940_00671448;
extern Mode_00671448 *D_L39_00241640_00671448;
__asm__(".extern D_L39_00241640_00671448, 16");
extern Spawn_00671448 *D_L39_0024C000;
extern Spawn_00671448 *D_L39_0024C000_00671448;
__asm__(".extern D_L39_0024C000_00671448, 16");
extern Player_00671448 *D_L39_0024CE20_00671448[8] __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024CE20_00671448, 32");
extern u8 *D_L39_0024BF5C_00671448;
__asm__(".extern D_L39_0024BF5C_00671448, 16");
extern s16 D_L39_00293F38[8][64];
extern u8 D_L39_004997E0[];
extern vu0_v4 D_L39_0025F760_00671448[];
extern f32 D_L39_0024642C;
__asm__(".extern D_L39_0024642C, 4");

extern s32 func_L39_005B4398(s32);
extern f32 func_0038CF00(void *, void *);
extern f32 func_L01_0040E4C0(void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_L01_003FB640(void *, s32, f32, u8 *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_00382760(void *, f32, f32, f32);

static __inline__ u8 *moby_00671448(Player_00671448 *g) { return g->p2524; }

static __inline__ f32 radius_00671448(Player_00671448 *g) { return g->f1F4; }

static __inline__ u32 decode_00671448(u8 *p) {
    Buf_00671448 buf;
    s32 n;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    if (*p == 0) {
        return 0;
    }
    n = *p;
    k = ((u32)p - n) & 7;
    m = n + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
    }
    buf.w[0] ^= (u32)p;
    buf.w[1] ^= buf.w[0];
    return buf.w[1];
}

void func_L39_00671448(void *arg0, void *arg1, void *arg2, s32 arg3) {
    Player_00671448 *p = arg0;
    vu0_v4 *pos = arg1;
    vu0_v4 v0;
    vu0_v4 v10;
    f32 best = 0.0f;
    s32 *list = 0;
    s32 *list2 = 0;
    s32 idx = -1;
    s32 i;
    s32 j;
    s32 k;
    s32 n;
    s32 c;
    s32 r;

    switch (D_L39_00241640_00671448->w180) {
    case 0:
        list = D_L39_00352940_00671448.p20C->a;
        list2 = D_L39_00352940_00671448.p20C->b;
        break;
    case 1:
        list = D_L39_00352940_00671448.p20C->a;
        list2 = D_L39_00352940_00671448.p20C->b;
        break;
    case 2:
        list = D_L39_00352940_00671448.p214->idx;
        break;
    default:
        list = D_L39_00352940_00671448.p20C->a;
        list2 = D_L39_00352940_00671448.p20C->b;
        break;
    }

    if (D_L39_00241640_00671448->w180 == 2) {
        if (arg3 != 0) {
            k = 0;
            for (i = 0; i < 64; i++) {
                if (list[i] != -1) {
                    k++;
                }
            }
            n = k / D_L39_00241640_00671448->w178;
            if (n < 2) {
                k = 0;
                for (i = 0; i < 64; i++) {
                    if (list[i] != -1) {
                        if (k == p->w2544) {
                            idx = list[i];
                            break;
                        }
                        k++;
                    }
                }
            } else {
                s32 t;
                r = func_L39_005B4398(n);
                k = 0;
                t = n * p->w2544 + r;
                for (i = 0; i < 64; i++) {
                    if (list[i] != -1) {
                        if (k == t) {
                            idx = list[i];
                            break;
                        }
                        k++;
                    }
                }
            }
        } else if (D_L39_00352940_00671448.p214->w104 != 0) {
            i = 0;
            r = func_L39_005B4398(64);
            while (r > 0 || list[i] == -1) {
                i++;
                if (i >= 64) {
                    i = 0;
                }
                if (r > 0 && list[i] != -1) {
                    r--;
                }
            }
            idx = list[i];
        } else {
            f32 score[64];
            f32 bs[64];
            s32 bi[64];
            f32 near;

            func_0011D534(score, 0, 0x100);
            near = 0.00390625f;
            for (j = 0; j < 8; j++) {
                if (D_L39_0024CE20_00671448[j] != 0) {
                    for (i = 0; i < 64; i++) {
                        if (list[i] != -1) {
                            f32 d;
                            v10 = D_L39_0024C000[list[i]].pos;
                            d = func_0038CF00(&D_L39_0024CE20_00671448[j]->pos, &v10);
                            if (d >= 40.0f) {
                                d -= 40.0f;
                                score[i] += (1.0f - d * d * 0.00006103515625f) * 1000.0f;
                            } else {
                                d -= 40.0f;
                                score[i] += (1.0f - d * d * near) * 1000.0f;
                            }
                        }
                    }
                }
            }
            for (j = 0; j < 8; j++) {
                if (j != p->w2544) {
                    s32 m;
                    for (m = 1; m <= D_L39_00293F38[j][0]; m++) {
                        Moby_00671448 *o = (Moby_00671448 *)D_L39_0024BF5C_00671448 + D_L39_00293F38[j][m];
                        if (o != 0) {
                            for (i = 0; i < 64; i++) {
                                if (list[i] != -1) {
                                    v10 = D_L39_0024C000[list[i]].pos;
                                    if (func_0038CF00(&o->pos, &v10) < 4.0f) {
                                        score[i] += -1000.0f;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            for (i = 0; i < 64; i++) {
                bs[i] = -1000000.0f;
                bi[i] = -1;
            }
            for (i = 0; i < 64; i++) {
                for (j = 0; j < D_L39_00352940_00671448.p214->w108; j++) {
                    if (list[i] != -1 && score[i] > bs[j]) {
                        s32 m;
                        for (m = D_L39_00352940_00671448.p214->w108 - 1; m >= j + 1; m--) {
                            bs[m] = bs[m - 1];
                            bi[m] = bi[m - 1];
                        }
                        bs[j] = score[i];
                        bi[j] = list[i];
                        break;
                    }
                }
            }
            {
                s32 pick = func_L39_005B4398(D_L39_00352940_00671448.p214->w108);
                for (i = 0; i < D_L39_00352940_00671448.p214->w108; i++) {
                }
                idx = bi[pick];
            }
        }
    } else {
        if (p->p2558 != 0) {
            Slot_00671448 *s = p->p2558;
            if (s->wC60 != -1) {
                if (p->w2548 == D_L39_00352940_00671448.p20C->t88[s->wC60]) {
                    idx = list[s->wC60];
                }
            } else if (s->wC64 != -1) {
                if (p->w2548 == D_L39_00352940_00671448.p20C->tA8[s->wC64]) {
                    idx = list2[s->wC64];
                }
            }
        }
    }

    if (idx == -1) {
        for (i = 0; i < 8; i++) {
            if (list[i] != -1 && D_L39_00352940_00671448.p20C->tC8[i] == p->w2548) {
                f32 far = 0.0f;
                v10 = D_L39_0024C000_00671448[list[i]].pos;
                j = 0;
                do {
                    Player_00671448 *o = D_L39_0024CE20_00671448[j];
                    f32 d;
                    if (o == 0) {
                        break;
                    }
                    if (o != p) {
                        vec_sub_ab(&v0, &o->pos, &v10);
                        d = func_L01_0040E4C0(&v0);
                        if (far < d) {
                            far = d;
                        }
                    }
                    j++;
                } while (j < 8);
                if (best < far || idx == -1) {
                    best = far;
                    idx = list[i];
                }
            }
        }
        if (idx == -1) {
            idx = list[0];
            if (idx == -1) {
                return;
            }
        }
    }

    *(vu0_q *)pos = *(vu0_q *)&D_L39_0024C000[idx].pos;
    {
        if (D_L39_00241640_00671448->w180 != 2) {
            c = 0;
            func_0038CE20(&v0, &D_L39_0024C000_00671448[idx].m10, (f32)p->w2544 * radius_00671448(p) * 2.0f);
            vec_add_ba(pos, pos, &v0);
            func_0038CE20(&v0, &D_L39_0024C000_00671448[idx].m20, radius_00671448(p) * 1.05f);
            vec_add_ab(pos, pos, &v0);
            while (func_L01_003FB640(pos, 0x24, radius_00671448(p), moby_00671448(p)) != 0 && c < 4) {
                c++;
                {
                    vu0_v4 t;
                    vec_sub_ba(&t, &D_L39_0025F760_00671448[1], pos);
                    vec_add_ab(pos, pos, &t);
                }
            }
            vec_sub_ab(pos, pos, &v0);
        } else {
            c = 0;
            for (i = 0; i < 8; i++) {
                if (D_L39_0024CE20_00671448[i] != 0) {
                    Player_00671448 *o = D_L39_0024CE20_00671448[i];
                    if ((decode_00671448(&o->b19E6) ^ 0x14) == 0 || (decode_00671448(&o->b19E4) ^ 0x7A) == 0) {
                        c++;
                    }
                }
            }
            if (c >= 2) {
                func_00382760(&v0, radius_00671448(p), (f32)p->w2544 * 6.2831855f * 0.125f, 0.0f);
                vec_add_ab(pos, pos, &v0);
            }
            func_0038CE20(&v0, &D_L39_0024C000_00671448[idx].m20, radius_00671448(p) * 1.05f);
            vec_add_ab(pos, pos, &v0);
            if (func_L01_003FB640(pos, 0x25, radius_00671448(p), moby_00671448(p)) != 0) {
                vu0_v4 t20;
                func_0038CF68(&t20, &D_L39_0024C000_00671448[idx].m0, radius_00671448(p) * 4.8f);
                vec_sub_ab(pos, pos, &t20);
                func_0038CF68(&t20, &D_L39_0024C000_00671448[idx].m0, radius_00671448(p) * 2.2f);
                while (func_L01_003FB640(pos, 0x25, radius_00671448(p), moby_00671448(p)) != 0 && c < 4) {
                    vec_add_ab(pos, pos, &t20);
                    c++;
                }
            }
            vec_sub_ab(pos, pos, &v0);
        }
    }
    {
        vu0_v4 t20;
        vu0_v4 t30;
        t20 = *pos;
        t30 = *pos;
        func_0038CE20(&v0, &D_L39_0024C000_00671448[idx].m20, 2.0f);
        vec_add_ba(&t20, &t20, &v0);
        func_0038CE20(&v0, &D_L39_0024C000_00671448[idx].m20, -30.0f);
        vec_add_ab(&t30, &t30, &v0);
        if (func_003D3CB0(&t20, &t30, 0x32, moby_00671448(p), 0) != 0) {
            *(vu0_q *)pos = *(vu0_q *)&D_L39_0025F760_00671448[0];
            func_0038CF68(&v0, &D_L39_0025F760_00671448[2], D_L39_0024642C);
            vec_add_ab(pos, pos, &v0);
        }
        *(vu0_v4 *)arg2 = D_L39_0024C000_00671448[idx].rot;
    }
}
/* localdecomp:end func_L39_00671448 */
