#include "common.h"

/* NTSC-U counterpart of func_L39_00664760 (src/levels/shared/L39_00663950.c): 60 Hz timer limits and turn rates, core callee at 0x19B5B8 */
/* localdecomp:start func_L39_00661E88 */
#include "vu0.h"

typedef union Buf_00661E88 {
    u8 b[8];
    u32 w[2];
} Buf_00661E88;

extern s32 D_001D5A1C_sda;
extern u8 D_L39_004998A0[];
extern void func_00388550(void *, void *, s32);
extern void func_L39_005B8460(void *, void *);
extern s32 func_L39_006346E8(u8 *, s32, s32);
extern f32 func_00389468(f32, f32);
extern void func_00388BD0(f32 *, f32 *);
extern void func_L39_00630AC0(void *, s32, f32, f32, f32);
extern s32 func_L02_003E4788(f32, void *, void *);
extern void func_L39_00635680(void *, void *, void *, s32, s32, s32, s32);
extern void func_0019B5B8(void *);

static __inline__ u32 decode_00661E88(u8 *p) {
    Buf_00661E88 buf;
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
        *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
    }
    buf.w[0] ^= (u32)p;
    buf.w[1] ^= buf.w[0];
    return buf.w[1];
}

static __inline__ void set_00661E88(vu0_v4 *d, f32 *s) {
    d->x = s[0];
    d->y = s[1];
    d->z = s[2];
    ((s32 *)d)[3] = 0;
}

static __inline__ s32 flag_00661E88(u8 *o, u32 st) {
    u8 r;

    if (*(u8 **)(o + 0x2530) != 0) {
        r = 0;
        if ((*(u8 **)(o + 0x2530))[0x27B] != 0 && (decode_00661E88(o + 0x19E4) ^ st) == 0) {
            r |= 1;
        }
    } else {
        r = 0;
    }
    return r;
}

void func_L39_00661E88(u8 *o) {
    u8 *a = *(u8 **)(o + 0x2558);
    u8 *q = *(u8 **)(a + 0xC44);
    u8 *t;
    u8 *r;
    s32 idx;

    if (q != 0 && (a[0xC42] == 0 || D_001D5A1C_sda - *(s32 *)(a + 0xC3C) >= *(s8 *)(a + 0xC41))) {
        t = q;
    } else {
        t = 0;
    }
    if (t == 0) {
        return;
    }
    idx = (*(u8 **)(o + 0x2558))[0xC31];
    if (idx == 2) {
        *(vu0_q *)(o + 0x4D40) = *(vu0_q *)(o + 0xA0);
        *(vu0_q *)(o + 0x4D70) = *(vu0_q *)(o + 0xB0);
        o[0x4D24] = decode_00661E88(o + 0x19E4);
        *(s32 *)(o + 0x4D88) = t[0x16];
        {
            u8 *c = *(u8 **)(*(u8 **)(o + 0x2558) + 0xC44);

            r = 0;
            if (c != 0) {
                r = *(u8 **)(c + 0x98);
            }
        }
        if (r == 0) {
            goto end;
        }
        if (r[0x16] != (t[0x16] + 1) % 256) {
            goto end;
        }
        {
            vu0_v4 v __attribute__((aligned(16)));
            f32 f;

            ((s32 *)&v)[3] = 0;
            if (*(u32 *)(r + 0x14) & 0x1000000) {
                u8 id = r[0x6C];

                func_00388550(&v, r + 0x6D, 12);
                if (decode_00661E88(o + 0x19E4) == id) {
                    goto copy;
                }
                if (id != 0) {
                    if ((decode_00661E88(o + 0x19E6) ^ 0x14) != 0) {
                        goto copy;
                    }
                    if (id == 0x76) {
                        goto copy;
                    }
                }
                if ((decode_00661E88(o + 0x19E4) ^ 0x37) == 0) {
                    goto copy;
                }
                if (id == 0x37) {
                    goto copy;
                }
                if ((decode_00661E88(o + 0x19E4) ^ 0x66) == 0) {
                    goto copy;
                }
                if (id == 0x16) {
                    goto copy;
                }
                if (id == 0x2B) {
                    goto copy;
                }
                if ((decode_00661E88(o + 0x19E4) ^ 0x8F) == 0) {
                    goto copy;
                }
                if ((decode_00661E88(o + 0x19E4) ^ 0x8E) == 0) {
                    goto copy;
                }
                if ((decode_00661E88(o + 0x19E4) ^ 0x22) == 0) {
                    goto copy;
                }
                if ((decode_00661E88(o + 0x19E4) ^ 0x31) == 0 && *(s32 *)(o + 0x2F0) < 501) {
                    goto copy;
                }
                {
                    u8 found = flag_00661E88(o, 0x31);
                    if (found) {
                        goto copy;
                    }
                }
                if (func_L39_006346E8(o, 0x8F, 10)) {
                    goto copy;
                }
                if ((decode_00661E88(o + 0x19E4) ^ 0x16) == 0 && *(s32 *)(o + 0x2F0) < 38) {
                    goto copy;
                }
                if ((decode_00661E88(o + 0x19E6) ^ 0x14) == 0 && *(s32 *)(o + 0x2F0) < 211) {
                    goto copy;
                }
                (*(void (**)(void *, s32, s32, s32, s32))(*(u8 **)(o + 0x14) + 0x34))(o, id, 1, 1, 1);
copy:
                {
                vu0_v4 w __attribute__((aligned(16)));
                s32 b4;

                func_00388550(&b4, r + 0x68, 4);
                func_L39_005B8460(&w, &b4);
                ((s32 *)&w)[3] = 0;
                if ((decode_00661E88(o + 0x19E6) ^ 0xE) != 0 &&
                    func_00389468(*(f32 *)(o + 0xB8), ((f32 *)&w)[2]) > 229.18311f) {
                    vu0_v4 n[3];

                    *(f32 *)(o + 0xFD0) = ((f32 *)&w)[2];
                    func_00388BD0((f32 *)n, (f32 *)&w);
                    *(vu0_q *)(o + 0xFC0) = *(vu0_q *)&n[0];
                    func_L39_00630AC0(o, 0, 0.2f, 0.45f, 0.40724349f);
                }
                }
            } else {
                ((f32 *)&v)[0] = *(u16 *)(r + 0x10) * 0.015625f;
                ((f32 *)&v)[1] = *(u16 *)(r + 0x12) * 0.015625f;
                ((f32 *)&v)[2] = *(u16 *)(r + 0x14) * 0.015625f;
            }
            f = 0.3f;
            if (*(u32 *)(r + 0x14) & 0x1000000) {
                f = 0.2f;
            }
            vec_sub_ab(o + 0x4D50, o + 0x4D30, &v);
            if ((decode_00661E88(o + 0x19E6) ^ 0xE) != 0) {
                if (func_L02_003E4788(f, o + 0xA0, &v) == 0) {
                    o[0x4D23] = 4;
                    vec_sub_ab(o + 0x4D50, o + 0x4D30, o + 0x4D40);
                    goto end;
                }
            }
            if ((decode_00661E88(o + 0x19E6) ^ 0xE) != 0) {
                o[0x4D23] = 0;
            }
        }
    }
end:
    if (idx >= o[0x255F] && o[0x255E] == t[0x16]) {
        if (decode_00661E88(o + 0x19E4) != o[0x255D]) {
            vu0_v4 v0 __attribute__((aligned(16)));
            vu0_v4 v1 __attribute__((aligned(16)));

            set_00661E88(&v0, (f32 *)(o + 0x2560));
            set_00661E88(&v1, (f32 *)(o + 0x256C));
            if (o[0x255D] != 0x76) {
                if (o[0x255D] != 0x39 ||
                    ((decode_00661E88(o + 0x19E4) ^ 0x8F) != 0 && (decode_00661E88(o + 0x19E4) ^ 0x39) != 0 &&
                     (decode_00661E88(o + 0x19E7) ^ 0x8F) != 0)) {
                    func_L39_00635680(o, &v0, &v1, o[0x255D], 0, 0, 0);
                }
            }
        }
        o[0x255D] = 0;
        o[0x255F] = 0xFF;
    }
    (*(u8 **)(o + 0x2558))[0xC31]++;
    if ((*(u8 **)(o + 0x2558))[0xC31] == 4) {
        func_0019B5B8(*(u8 **)(o + 0x2558));
        if (++o[0x4D22] >= 11) {
            o[0x4D20] = 1;
        }
    }
}
/* localdecomp:end func_L39_00661E88 */
