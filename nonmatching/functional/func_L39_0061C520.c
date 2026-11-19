/* functional: high. Near miss (236 words differ, register allocation/addressing form: retail loads the count pointer with lui, one more saved reg). Ported from the NTSC-U twin draft; every global, callee, offset and decode constant (0x314/0x19E4/0x19E6, 0x18/0x28 loops, xor masks 1,0x1D,0x14,0x7A,0x31) re-read against the PAL asm. */
extern u8 D_L39_004997E0[];
extern u8 D_L39_002FB000[];
extern s32 *D_L39_00241120;
extern s32 D_L39_00241118;
extern s32 D_L39_00241128;
extern u8 D_001A5810[];
extern s32 func_L39_00639D90(void *);
extern void func_L39_00646660(void *, s32);
extern void func_L39_0066ADA0(void);

typedef union {
    u8 b[8];
    u16 h[4];
    u32 w[2];
} Buf_0061C520;

typedef struct {
    u8 pad0[0x34];
    u16 h34;
} Sub_0061C520;

void func_L39_0061C520(void) {
    Buf_0061C520 buf;
    u8 *g;
    s32 i;
    s32 j;
    s32 s6;
    s32 s5;
    s32 s2;
    s32 s1;
    s32 t3;
    u8 *p;

    for (i = 0; i < *D_L39_00241120; ) {
        g = D_L39_002FB000 + i * 0x4500;
        if (g != 0) {
            s6 = 0;
            if ((s16)({
                u8 *q = g + 0x314;
                u32 r;
                if (*q == 0) {
                    r = 0;
                } else {
                    u32 a;
                    u32 b;
                    s32 n = *q;
                    s32 k = ((u32)q - n) & 7;
                    s32 m = n + 1;
                    s32 i;
                    u8 *d = buf.b;
                    for (i = 0; i < 24; i += 3) {
                        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
                    }
                    a = buf.w[0] ^ (u32)q;
                    b = buf.w[1] ^ a;
                    buf.w[0] = a;
                    buf.w[1] = (b >> 16) / (((b ^ (b >> 16)) << 16) + 1);
                    r = buf.h[2];
                }
                r;
            }) != 0 || (g[0x1A0A] != 0 && ((({
                u8 *q = g + 0x19E4;
                u32 a;
                u32 r;
                if (*q == 0) {
                    r = 0;
                } else {
                    s32 n = *q;
                    s32 k = ((u32)q - n) & 7;
                    s32 m = n + 1;
                    s32 i;
                    u8 *d = buf.b;
                    for (i = 0; i < 40; i += 5) {
                        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
                    }
                    a = buf.w[0] ^ (u32)q;
                    buf.w[0] = a;
                    buf.w[1] ^= a;
                    r = buf.w[1];
                }
                r;
            }) ^ 1) == 0 || (({
                u8 *q = g + 0x19E4;
                u32 a;
                u32 r;
                if (*q == 0) {
                    r = 0;
                } else {
                    s32 n = *q;
                    s32 k = ((u32)q - n) & 7;
                    s32 m = n + 1;
                    s32 i;
                    u8 *d = buf.b;
                    for (i = 0; i < 40; i += 5) {
                        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
                    }
                    a = buf.w[0] ^ (u32)q;
                    buf.w[0] = a;
                    buf.w[1] ^= a;
                    r = buf.w[1];
                }
                r;
            }) ^ 0x1D) == 0))) {
                s6 = 1;
            }
            s5 = 0;
            if (D_001A5810[*(s32 *)(g + 0x2544) + 0xA4] == 1) {
                s5 = ((({
                u8 *q = g + 0x19E4;
                u32 a;
                u32 r;
                if (*q == 0) {
                    r = 0;
                } else {
                    s32 n = *q;
                    s32 k = ((u32)q - n) & 7;
                    s32 m = n + 1;
                    s32 i;
                    u8 *d = buf.b;
                    for (i = 0; i < 40; i += 5) {
                        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
                    }
                    a = buf.w[0] ^ (u32)q;
                    buf.w[0] = a;
                    buf.w[1] ^= a;
                    r = buf.w[1];
                }
                r;
            }) ^ 1) == 0 || (({
                u8 *q = g + 0x19E4;
                u32 a;
                u32 r;
                if (*q == 0) {
                    r = 0;
                } else {
                    s32 n = *q;
                    s32 k = ((u32)q - n) & 7;
                    s32 m = n + 1;
                    s32 i;
                    u8 *d = buf.b;
                    for (i = 0; i < 40; i += 5) {
                        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
                    }
                    a = buf.w[0] ^ (u32)q;
                    buf.w[0] = a;
                    buf.w[1] ^= a;
                    r = buf.w[1];
                }
                r;
            }) ^ 0x1D) == 0 || g[0x24FE] != 0 || g[0x2500] != 0);
            }
            s2 = 0;
            t3 = (func_L39_00639D90(g) == 2);
            if ((({
                u8 *q = g + 0x19E6;
                u32 a;
                u32 r;
                if (*q == 0) {
                    r = 0;
                } else {
                    s32 n = *q;
                    s32 k = ((u32)q - n) & 7;
                    s32 m = n + 1;
                    s32 i;
                    u8 *d = buf.b;
                    for (i = 0; i < 40; i += 5) {
                        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
                    }
                    a = buf.w[0] ^ (u32)q;
                    buf.w[0] = a;
                    buf.w[1] ^= a;
                    r = buf.w[1];
                }
                r;
            }) ^ 0x14) == 0 || (({
                u8 *q = g + 0x19E4;
                u32 a;
                u32 r;
                if (*q == 0) {
                    r = 0;
                } else {
                    s32 n = *q;
                    s32 k = ((u32)q - n) & 7;
                    s32 m = n + 1;
                    s32 i;
                    u8 *d = buf.b;
                    for (i = 0; i < 40; i += 5) {
                        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
                    }
                    a = buf.w[0] ^ (u32)q;
                    buf.w[0] = a;
                    buf.w[1] ^= a;
                    r = buf.w[1];
                }
                r;
            }) ^ 0x7A) == 0) {
                s2 = 1;
                if (g[0x1A0A] == 0) {
                    s2 = 0;
                }
            }
            s1 = 0;
            if (t3 || s6 || s5 || s2) {
                if (i == D_L39_00241118) {
                    s1 = 1;
                    ((Sub_0061C520 *)*(u8 **)(g + 0x424))->h34 |= 1;
                    for (j = 0, p = g; j < 6; j++, p += 0x50) {
                        if (j != 0) {
                            if (*(u8 **)(p + 0x450) != 0) {
                                ((Sub_0061C520 *)*(u8 **)(p + 0x450))->h34 |= 1;
                            }
                            if (*(u8 **)(p + 0x454) != 0) {
                                ((Sub_0061C520 *)*(u8 **)(p + 0x454))->h34 |= 1;
                            }
                        }
                    }
                    if (*(s32 *)(g + 0x478) == 10 && *(u8 **)(g + 0x450) != 0 && D_L39_00241128 == 0 &&
                        (*(u8 **)(g + 0x450))[0x20] != 0) {
                        ((Sub_0061C520 *)*(u8 **)(g + 0x450))->h34 &= 0xFFBE;
                    }
                    func_L39_00646660(g, 1);
                }
            }
            if (s1 == 0) {
                if ((({
                u8 *q = g + 0x19E4;
                u32 a;
                u32 r;
                if (*q == 0) {
                    r = 0;
                } else {
                    s32 n = *q;
                    s32 k = ((u32)q - n) & 7;
                    s32 m = n + 1;
                    s32 i;
                    u8 *d = buf.b;
                    for (i = 0; i < 40; i += 5) {
                        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
                    }
                    a = buf.w[0] ^ (u32)q;
                    buf.w[0] = a;
                    buf.w[1] ^= a;
                    r = buf.w[1];
                }
                r;
            }) ^ 0x31) != 0 && s2 == 0) {
                    ((Sub_0061C520 *)*(u8 **)(g + 0x424))->h34 &= 0xFFFE;
                    for (p = g; (s32)p < (s32)(g + 0x1E0); p += 0x50) {
                        if (*(u8 **)(p + 0x450) != 0) {
                            ((Sub_0061C520 *)*(u8 **)(p + 0x450))->h34 &= 0xFFFE;
                        }
                        if (*(u8 **)(p + 0x454) != 0) {
                            ((Sub_0061C520 *)*(u8 **)(p + 0x454))->h34 &= 0xFFFE;
                        }
                    }
                    func_L39_00646660(g, 0);
                }
                if (*(s32 *)(g + 0x251C) != 0 && *(s32 *)(g + 0x478) == 10) {
                    if (*(u8 **)(g + 0x450) != 0) {
                        ((Sub_0061C520 *)*(u8 **)(g + 0x450))->h34 |= 1;
                    }
                    if (*(u8 **)(g + 0x454) != 0) {
                        ((Sub_0061C520 *)*(u8 **)(g + 0x454))->h34 |= 1;
                    }
                }
                if (g[0x1A10] != 0 && *(s32 *)(g + 0x478) == 10 || g[0x1A0B] != 0) {
                    if (*(u8 **)(g + 0x450) != 0) {
                        ((Sub_0061C520 *)*(u8 **)(g + 0x450))->h34 |= 0x41;
                    }
                }
            }
        }
        i = i + 1;
    }
    func_L39_0066ADA0();
}
