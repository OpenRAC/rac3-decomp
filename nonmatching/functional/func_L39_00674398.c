/* functional: medium. Compiles at level 39 (no draft; written from the PAL asm). Notes: retail tests a 64-bit word at 0x1C0 against 0xA000<<27, written as the upper 32-bit word & 0x50 (SN cc1 rejects the wide constant); for actor sound kinds other than 1/2 retail reuses a stale register as the sound id, kept as a persistent local 'snd' (0 at start); per-function aliases D_L39_*_00674398 for globals typed differently by other files. */
#include "common.h"
typedef union Buf_00674398 {
    u8 b[8];
    u16 h[4];
    u32 w[2];
} Buf_00674398;

typedef struct Ent_00674398 {
    u8 pad0[8];
    u8 b8;
    u8 pad9[9];
    u16 h12;
    u8 pad14[10];
    s16 h1E;
    u8 pad20;
    s8 b21;
    u8 pad22[0x5E];
} Ent_00674398;

extern Ent_00674398 D_L39_0049C890_00674398[];
extern u8 D_L39_004997E0[];
extern u8 D_L39_00483A00[];
extern u8 D_L39_00352940_00674398[];
extern u8 *D_L39_00241640_00674398;
extern s32 *D_L39_00241120;
extern s32 D_L39_00240370[] __attribute__((section(".sdata")));
extern u8 D_001FC6B0[];
__asm__(".extern D_L39_002464A8, 8");
__asm__(".extern D_L39_00246488, 8");
__asm__(".extern D_L39_002464C8, 4");
__asm__(".extern D_L39_002464CC, 4");
extern s32 D_L39_002464A8[];
extern s32 D_L39_00246488[];
extern s32 D_L39_002464C8;
extern s32 D_L39_002464CC;
extern u8 *func_L39_0061BF38(s32);
extern void func_L39_005D72E8(s32, void *);
extern s32 func_L39_006212E8(void *);
extern void func_L39_005DA870(s32, s32, s32, s32);
extern void func_L39_005DADF8(s32, s32, s32);
extern void func_L39_005DA7A8(s32, s32);
extern void func_L39_005DAC98(s32, s32, s32);
extern s32 func_L39_00648AE0(void *, s32);
extern void func_L39_005DAEB8(s32, void *);
extern s32 func_L39_00677398(s32);
extern void func_L39_006773E0(s32, s32);
extern s32 func_L01_0040E020(void *);
extern s32 func_L39_00677430(s32);
extern void func_L39_00677478(s32, s32);
extern void func_L39_005E04A0(s32, s32);
extern void func_L39_005E20A8(s32, s32);
extern void func_L39_005D8D18(s32, f32 *, f32 *);
extern void func_L39_005DEBD0(s32);
extern void func_L39_005DEC68(s32);
extern void func_L39_005E2010(void);
extern void func_0038CAD0(s32 *);

/* the 5-byte-stride keyed decode of a protected word (D_004997E0 table) */
static u32 dec5_00674398(u8 *q) {
    Buf_00674398 buf;
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
        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
    }
    a = buf.w[0] ^ (u32)q;
    b = buf.w[1] ^ a;
    return b;
}

/* the 3-byte-stride keyed decode (D_00483A00 table), returns the 16-bit result */
static u16 dec3_00674398(u8 *q) {
    Buf_00674398 buf;
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
    for (i = 0; i < 24; i += 3) {
        *d++ = D_L39_00483A00[((k + i) & 7) * 209 + m];
    }
    a = buf.w[0] ^ (u32)q;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = (b >> 16) / (((b ^ (b >> 16)) << 16) + 1);
    return buf.h[2];
}

/* Per-frame HUD/scoreboard update of every player: icon/sound state per actor, and the shared
   score bars for the match mode. */
void func_L39_00674398(void) {
    f32 bar[2];
    f32 cd[2];
    s32 found = 0;
    s32 doBars;
    s32 i;
    s32 j;
    s32 snd = 0;
    u8 *a;

    for (i = 0; i < *D_L39_00241120; i++) {
        a = func_L39_0061BF38(i);
        if (a[0x2518] != 0) {
            func_L39_005D72E8(0, a);
            found = 1;
            continue;
        } else {
            s32 id = func_L39_006212E8(a);
            u8 *ent = 0;
            u8 *s;
            s32 pn;

            if (id != -1) {
                ent = (u8 *)&D_L39_0049C890_00674398[id];
            }
            s = *(u8 **)(a + 0x2528);
            pn = a[0x24C9];
            if (s != 0) {
                s32 h = *(s16 *)(s + 0x2FC);
                s32 a17;
                s32 a19 = 5;

                if (h == 1) {
                    s32 st = *(s32 *)(a + 0x254C);

                    snd = 0xED37;
                    if (st == 5 || st == 3) {
                        a19 = 8;
                        a17 = *(s32 *)(*(u8 **)(*(u8 **)(s + 0x2D0) + 0x68) + 0x3D4);
                    } else {
                        a17 = *(s32 *)(*(u8 **)(*(u8 **)(s + 0x2D0) + 0x68) + 0x3DC);
                    }
                } else {
                    if (h == 2) {
                        snd = 0xED4B;
                    }
                    a17 = 5;
                }
                func_L39_005DA870(snd, 0, 0, pn);
                func_L39_005DA870(-1, 0, 1, pn);
                func_L39_005DADF8(a17, a19, pn);
                func_L39_005DA7A8(pn, 8);
                func_L39_005D72E8(8, a);
                func_L39_005DAC98(snd, *(u8 **)(s + 0x2D8) != 0, *(u8 **)(s + 0x2DC) != 0);
            } else if (ent != 0) {
                for (j = 0; j < 3; j++) {
                    s32 v = dec3_00674398(a + 0x1A32 + j) & 0xFF;
                    u8 *e2;
                    s32 bits;

                    if (v == 0) {
                        func_L39_005DA870(0, 0, j, pn);
                        continue;
                    }
                    if (func_L39_00648AE0(a, v) != 0) {
                        e2 = (u8 *)&D_L39_0049C890_00674398[D_L39_0049C890_00674398[v].b21];
                    } else {
                        e2 = (u8 *)&D_L39_0049C890_00674398[v];
                    }
                    bits = (s16)dec3_00674398(a + 0x1A41);
                    func_L39_005DA870(((Ent_00674398 *)e2)->h12, (bits >> v) & 1, j, pn);
                    if (j != 0) {
                        continue;
                    }
                    if (v != 9) {
                        s32 t = (s16)dec3_00674398(a + v + 0x1A52);

                        if (func_L39_00648AE0(a, v) != 0) {
                            e2 = (u8 *)&D_L39_0049C890_00674398[D_L39_0049C890_00674398[v].b21];
                        } else {
                            e2 = (u8 *)&D_L39_0049C890_00674398[v];
                        }
                        func_L39_005DADF8(t, ((Ent_00674398 *)e2)->h1E, pn);
                    }
                    func_L39_005DAEB8(v, a);
                    if (D_L39_0049C890_00674398[id].b8 != 0 || id == 0xC) {
                        func_L39_005DA7A8(pn, 8);
                    }
                }
            }
        }
        if (*(s32 *)(a + 0x2514) == 0) {
            if ((*(u32 *)(*(u8 **)(a + 0x2534) + 0x1A4) & 0x200) && (dec5_00674398(a + 0x19E4) ^ 0x31) != 0) {
                *(s32 *)(a + 0x2514) = 0x12C;
            }
        }
        if (a[0x2518] != 0) {
            continue;
        } else {
            s32 flag = 0;
            s32 b4d;
            u8 *ctl;

            if (*(s32 *)(a + 0x2514) > 0) {
                func_L39_005D72E8(*(s32 *)(a + 0x2514), a);
                *(s32 *)(a + 0x2514) = 0;
            }
            b4d = D_001FC6B0[D_L39_00240370[a[0x24C9]] * 0x1F0 + 0x4D];
            ctl = *(u8 **)(a + 0x2534);
            if (b4d == 1) {
                flag = (*(s32 *)(ctl + 0x1C4) >> 10) & 1;
            } else if (b4d == 0) {
                flag = (*(s32 *)(ctl + 0x1C4) >> 8) & 1;
            } else if (b4d == 2) {
                flag = (*(u32 *)(ctl + 0x1C4) & 0x50) != 0; /* retail tests the 64-bit word at 0x1C0 against 0xA000 << 27 */
            }
            if (flag != 0) {
                a[0x44F0] = 8;
                if (*(u32 *)(*(u8 **)(a + 0x2534) + 0x1C4) & 0x100) {
                    func_L39_006773E0(i, (func_L39_00677398(i) ^ 1) & 0xFF);
                }
            } else if (func_L01_0040E020(a + 0x44F0) == 2 && (*(u32 *)(*(u8 **)(a + 0x2534) + 0x1C0) & 0x400)) {
                func_L39_006773E0(i, (func_L39_00677398(i) ^ 1) & 0xFF);
            }
            if (func_L39_00677430(i) != 0) {
                func_L39_00677478(i, 10);
            } else {
                func_L39_005E04A0(i, 10);
                if (*(s32 *)D_L39_00352940_00674398 != -1) {
                    func_L39_005E20A8(i, 10);
                }
            }
        }
    }

    doBars = 1;
    if (*(s32 *)(D_L39_00241640_00674398 + 0x180) == 0) {
        for (j = 0; j < 2; j++) {
            u8 *T2 = *(u8 **)(D_L39_00352940_00674398 + 0x20C);
            f32 *p128 = (f32 *)(T2 + 0x128 + j * 4);
            f32 *p148 = (f32 *)(T2 + 0x148 + j * 4);
            f32 r;
            s32 den;

            if (*p128 != *p148) {
                D_L39_002464A8[j] = (D_L39_002464C8 * 5 + 2) / 6;
                *p128 = *p148;
            }
            if (D_L39_002464A8[j] > 0) {
                if (!(D_L39_00246488[j] > 0)) {
                    D_L39_00246488[j] = (D_L39_002464CC * 5 + 2) / 6;
                }
            }
            den = (D_L39_002464CC * 5 + 2) / 6;
            cd[j] = (f32)(D_L39_00246488[j] / den);
            r = *(f32 *)(T2 + 0x128 + j * 4) / *(f32 *)(T2 + 0x108 + j * 4);
            bar[j] = r;
            if (1.0f < r) {
                bar[j] = 1.0f;
            }
            if (bar[j] < 0.0f) {
                bar[j] = 0.0f;
            }
            func_0038CAD0(&D_L39_00246488[j]);
            func_0038CAD0(&D_L39_002464A8[j]);
        }
    } else if (*(s32 *)(D_L39_00241640_00674398 + 0x180) == 1) {
        s32 sb = *(s8 *)(D_L39_00241640_00674398 + 0x198);
        u8 *X;
        f32 m;
        f32 c;

        if (sb > 0) {
            m = (f32)sb;
        } else {
            X = *(u8 **)(D_L39_00352940_00674398 + 0x210);
            m = (f32)*(s32 *)(X + 8);
            if (m < 3.0f) {
                m = 3.0f;
            }
            c = (f32)*(s32 *)(X + 0xC);
            if (c < m) {
                c = m;
            }
            m = c;
        }
        X = *(u8 **)(D_L39_00352940_00674398 + 0x210);
        bar[0] = (f32)*(s32 *)(X + 8) / m;
        bar[1] = (f32)*(s32 *)(X + 0xC) / m;
        cd[0] = 0.0f;
        cd[1] = 0.0f;
        if (1.0f < bar[0]) {
            bar[0] = 1.0f;
        }
        if (bar[0] < 0.0f) {
            bar[0] = 0.0f;
        }
        if (1.0f < bar[1]) {
            bar[1] = 1.0f;
        }
        if (bar[1] < 0.0f) {
            bar[1] = 0.0f;
        }
    } else {
        doBars = 0;
    }

    if (doBars != 0) {
        if (found == 0 || *D_L39_00241120 == 2) {
            func_L39_005D8D18(10, bar, cd);
        }
    }
    if (*D_L39_00241120 == 2) {
        func_L39_005DEBD0(10);
    } else if (*D_L39_00241120 == 3) {
        func_L39_005DEC68(10);
    }
    if (*(s32 *)D_L39_00352940_00674398 != -1 && (found == 0 || *D_L39_00241120 == 2) && *D_L39_00241120 < 3) {
        func_L39_005E20A8(0, 10);
    } else {
        func_L39_005E2010();
    }
}
