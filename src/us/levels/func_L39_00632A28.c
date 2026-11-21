#include "common.h"

/* NTSC-U counterpart of func_L39_00635270 (src/levels/shared/L39_00635270.c): pulse period 18 frames (PAL 15), D_001A5990 table */
/* localdecomp:start func_L39_00632A28 */
#include "vu0.h"

typedef union Buf_00632A28 {
    u8 b[8];
    u32 w[2];
    f32 f[2];
} Buf_00632A28;

typedef struct Cam_00632A28 {
    u8 pad[0x460];
} Cam_00632A28;

extern u8 D_L39_004998A0[];
extern s32 D_L39_002412AC;
extern s32 D_L39_0024D000;
__asm__(".extern D_L39_0024D000, 4");
extern s32 D_L39_002461D4;
__asm__(".extern D_L39_002461D4, 4");
extern f32 D_L39_002461D0;
__asm__(".extern D_L39_002461D0, 4");
extern s32 D_L39_00242B84;
__asm__(".extern D_L39_00242B84, 4");
extern u8 *D_L39_0024C05C;
extern u8 *D_L39_0024C064;
extern s32 D_L39_00241298;
extern s32 D_L39_002415F0;
extern u8 *D_L39_002417C0;
extern u8 *D_L39_0024CF20[] __attribute__((section(".sdata")));
extern Cam_00632A28 D_L39_0024DF80[];
extern u8 D_L39_0024D018[][8] __attribute__((section(".sdata")));
extern s32 D_L39_0025F858[];
extern u8 D_L39_002461D8[];
extern s32 D_L39_00240490;
extern s32 D_L39_00240494;
extern s32 D_L39_00240498;
extern s32 D_L39_0024049C;
typedef struct Tab_00632A28 {
    u8 pad0[0xA4];
    u8 bA4[0x100];
} Tab_00632A28;

extern Tab_00632A28 D_001A5990;

extern u8 *func_L39_0061B038(void *);
extern void func_L39_00632738(void);
extern void func_003BFEF0(void *, s32, f32, f32);
extern f32 func_00388978(f32);
extern void func_L39_00589FE8(s32, s32, s32, s32);
extern void func_003A3EF0(s32, unsigned long);
extern void func_00389920(s32);
extern void func_00388830(void *, void *, f32);
extern f32 func_L01_0040C018(void *, void *);
extern f32 func_00388730(void *, void *);
extern void func_00381DD0(f32 *, void *);
extern u32 func_L39_00669E80(s32);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern s32 func_003894A0(s32, s32, f32);
extern s32 func_L01_00410228(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);
extern void func_L39_00586D40(void);
extern void func_00389908(void);
extern s32 func_0011FFA8(char *, s32, const char *, ...);
extern void func_00120D28(void *, void *, s32);

typedef struct Ring_00632A28 {
    u8 v[8][16];
    s32 a[8];
    f32 b[8];
    f32 c[8];
    s16 n;
} Ring_00632A28;

typedef struct Names_00632A28 {
    u8 name[8][16];
    u8 tag[8][8];
} Names_00632A28;

static __inline__ u32 obf_get_00632A28(u8 *q) {
    Buf_00632A28 buf;
    u32 a;
    u32 b;
    s32 n;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    if (*q == 0) {
        return 0;
    }
    n = *q;
    k = ((u32)q - n) & 7;
    m = n + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
    }
    a = buf.w[0] ^ (u32)q;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = b;
    return b;
}

static __inline__ s32 obf_is_00632A28(u8 *q, u32 v) {
    return obf_get_00632A28(q) == v;
}

static __inline__ f32 obf_getf_00632A28(u8 *q) {
    Buf_00632A28 buf;
    u32 a;
    u32 b;
    s32 n;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    if (*q == 0) {
        return 0.0f;
    }
    n = *q;
    k = ((u32)q - n) & 7;
    m = n + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
    }
    a = buf.w[0] ^ (u32)q;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = b;
    return buf.f[1];
}

static __inline__ s32 obf_le_00632A28(u8 *q, f32 v) {
    return obf_getf_00632A28(q) <= v;
}

void func_L39_00632A28(void *a0) {
    u8 *p;
    u8 *m;
    s32 k;
    s32 i;
    s32 side;
    s32 saved;
    s32 los;
    s32 vis;
    s32 x;
    s32 y;
    s32 color;
    Names_00632A28 *names;
    Cam_00632A28 *cam;

    p = func_L39_0061B038(a0);
    if (D_L39_0024D000 != D_L39_002412AC) {
        D_L39_0024D000 = D_L39_002412AC;
        D_L39_002461D4 = (D_L39_002461D4 + 1) & 3;
    }
    if (p == 0) {
        return;
    }
    if (D_L39_00242B84 != 0) {
        func_L39_00632738();
    }
    if (D_L39_002461D0 == 0.0f) {
        D_L39_002461D0 = 1.0f;
        for (m = D_L39_0024C05C; m < D_L39_0024C064; m += 0x100) {
            if (*(s16 *)(m + 0xAA) == 0x1C57) {
                D_L39_002461D0 = *(f32 *)(m + 0x18) + 10.0f;
                break;
            }
        }
    }
    side = *(f32 *)(p + 0xA8) < D_L39_002461D0;
    for (k = 0; k < ((Ring_00632A28 *)(p + 0x1900))->n; k++) {
        Ring_00632A28 *r = (Ring_00632A28 *)(p + 0x1900);
        func_003BFEF0(r->v[k], r->a[k], r->b[k], r->c[k]);
    }
    if (*(u8 *)(p + 0x24C9) == D_L39_00241298) {
        if (*(s16 *)(p + 0x342) != 0) {
            f32 s = func_00388978((f32)*(s16 *)(p + 0x342) * 3.1415927f / 18.0f);
            func_L39_00589FE8(0xAA, 0, 0, (s32)((s * 0.5f + 0.5f) * 80.0f));
            func_003A3EF0(0x47, 0x5360B);
        }
        saved = D_L39_002415F0;
        func_00389920(1);
        if (D_L39_002417C0 != 0 && D_L39_002417C0[0x19F] == 0) {
            return;
        }
        for (i = 0; i < 8; i++) {
            u8 *q = D_L39_0024CF20[i];
            if (q == 0 || q == p) {
                continue;
            }
            if (side != (*(f32 *)(q + 0xA8) < D_L39_002461D0)) {
                continue;
            }
            if (obf_is_00632A28(q + 0x19E6, 0x14) && D_L39_0024CF20[i][0x1A0A] != 0) {
                continue;
            }
            if (obf_is_00632A28(D_L39_0024CF20[i] + 0x19E4, 0x76)) {
                continue;
            }
            if (obf_is_00632A28(D_L39_0024CF20[i] + 0x19E7, 0x76) &&
                obf_is_00632A28(D_L39_0024CF20[i] + 0x19E4, 0x90)) {
                continue;
            }
            {
                vu0_v4 pos;
                vu0_v4 ofs;

                los = 1;
                q = D_L39_0024CF20[i];
                pos = *(vu0_v4 *)(q + 0xA0);
                func_00388830(&ofs, *(u8 **)(q + 0x2524) + 0xE0, 1.75f);
                vec_add_ab(&pos, &pos, &ofs);
                if (D_001A5990.bA4[*(s32 *)(p + 0x2544)] == 0
                        ? *(void **)(p + 0x24E8) == *(void **)(D_L39_0024CF20[i] + 0x2524)
                        : *(void **)(p + 0x122C) == *(void **)(D_L39_0024CF20[i] + 0x2524) &&
                              *(f32 *)(p + 0x1250) > 0.7f) {
                    los = 0;
                } else {
                    if (obf_is_00632A28(D_L39_0024CF20[i] + 0x19E6, 3)) {
                        continue;
                    }
                    if (func_L01_0040C018(&D_L39_0024DF80[D_L39_00241298], &pos) > 1225.0f) {
                        continue;
                    }
                }
                {
                    vu0_v4 dir;
                    u8 dead;

                    cam = &D_L39_0024DF80[D_L39_00241298];
                    vec_sub_ab(&dir, &pos, cam);
                    func_00388830(&dir, &dir, 1.0f);
                    if (func_00388730(&dir, (u8 *)&D_L39_0024DF80[D_L39_00241298] + 0x380) < 0.5f) {
                        continue;
                    }
                    func_00381DD0((f32 *)&dir, &pos);
                    x = (dir.x - (f32)D_L39_00240490) * 0.0625f;
                    y = (dir.y - (f32)D_L39_00240494) * 0.0625f;
                    if (x > D_L39_00240498 + 0x40 || x < -0x40 || y > D_L39_0024049C + 0x40 || y < -0x40) {
                        continue;
                    }
                    color = func_L39_00669E80(*(s32 *)(D_L39_0024CF20[i] + 0x2548));
                    if (D_L39_002461D4 == (i & 3)) {
                        vis = 1;
                        if (los) {
                            if (func_003CE740(&D_L39_0024DF80[D_L39_00241298], &pos, 0x82, 0, 0) != 0) {
                                s32 hit = D_L39_0025F858[0];
                                vis = 0;
                                if (hit != 0) {
                                    u8 *t = *(u8 **)(D_L39_0024CF20[i] + 0x2528);
                                    if (t != 0 && *(s32 *)(t + 0x2D0) != 0) {
                                        vis = hit == *(s32 *)(t + 0x2D0);
                                    }
                                }
                            }
                        }
                        D_L39_0024D018[D_L39_00241298][i] = vis;
                    }
                    if (D_L39_0024D018[D_L39_00241298][i] == 0) {
                        continue;
                    }
                    dead = obf_le_00632A28(D_L39_0024CF20[i] + 0x2476, 0.0f);
                    if (dead ||
                        obf_is_00632A28(D_L39_0024CF20[i] + 0x19E4, 0x39) ||
                        obf_is_00632A28(D_L39_0024CF20[i] + 0x19E4, 0x90)) {
                        color = func_003894A0(color, 0x80002000, 0.5f);
                    }
                    {
                        char text[32];

                        names = (Names_00632A28 *)D_L39_002417C0;
                        if (names->tag[i][0] != 0) {
                            func_0011FFA8(text, 0x17, D_L39_002461D8, names->name[i], names->tag[i]);
                        } else {
                            func_00120D28(text, names->name[i], 0xF);
                        }
                        text[0x18] = 0;
                        func_003A3EF0(0x42, 0x8000000044UL);
                        ((s32 (*)(s32, s32, unsigned long, char *, s32))func_L01_00410228)(x, y - 3, 0x80000000UL, text, -1);
                        ((s32 (*)(s32, s32, unsigned long, char *, s32))func_L01_00410228)(x - 1, y - 4, color, text, -1);
                        func_003A3EF0(0x47, 0x5360B);
                    }
                }
            }
        }
        func_00389920(saved);
    }
    func_L39_00586D40();
    func_00389908();
}
/* localdecomp:end func_L39_00632A28 */
