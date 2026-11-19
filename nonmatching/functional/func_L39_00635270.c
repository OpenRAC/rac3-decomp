/* functional: medium. Multiplayer HUD: draws a name tag over each other visible player (projects the position to the screen, picks the colour/alpha, formats or copies the name and draws it twice, shadow first). The 8-byte obfuscated-state decode is a helper here (retail inlines it); globals use the level's real addresses (gp 0x247FC0), names assumed from the D_L39_/D_0024xxxx patterns of the neighbours. The meaning of the state values 0x14/0x76/0x90/0x03/0x39 is unknown. a0 is forwarded to func_L39_0061D7B0 as retail leaves it in the register. */
extern u8 D_L39_004997E0[];
extern s32 D_0024112C;
extern s32 D_00241118;
extern s32 D_00241470;
extern u8 *D_00241640;
extern s32 D_00240310;
extern s32 D_00240314;
extern s32 D_00240318;
extern s32 D_0024031C;
extern s32 D_L39_0024CF00;
extern s32 D_L39_00246054;
extern s32 D_L39_00242A04;
extern f32 D_L39_00246050;
extern u8 *D_L39_0024BF5C;
extern u32 D_L39_0024BF64;
extern u8 *D_L39_0024CE20[];
extern u8 D_L39_0024CF18[];
extern u8 D_L39_0024DE80[];
extern u8 D_001A5810[];
extern s32 D_L39_0025F758;
extern char D_L39_00246058[];
extern void func_L39_00634F80(void);
extern void *func_L39_0061D7B0(void *);
extern void func_003C5458(void *, s32, f32, f32);
extern f32 func_0038D0B0(f32);
extern void func_L39_0058B1B8(s32, s32, s32, s32);
extern void func_003A9440(s32, long);
extern void func_0038E150(s32);
extern void func_0038E138(void);
extern void func_L39_00587E80(void);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern f32 func_L01_0040E548(void *, void *);
extern void func_003860A8(f32 *, void *);
extern s32 func_L39_0066C788(s32);
extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
extern s32 func_0038DBD8(s32, s32, f32);
extern s32 func_0011FFA8(char *, s32, char *, ...);
extern char *func_00120D28(char *, const char *, s32);
extern s32 func_L01_00412858(s32, s32, s32, s32, s32);

/* the obfuscated 32-bit state whose index byte is *q (0 when unset) */
static u32 dec_state_00635270(u8 *q) {
    u32 buf[2];
    u8 *b;
    s32 n, m, k, i;
    if (*q == 0) {
        return 0;
    }
    n = *q;
    m = n + 1;
    k = ((u32)q - n) & 7;
    b = (u8 *)buf;
    for (i = 0; i < 40; i += 5) {
        *b++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
    }
    buf[0] ^= (u32)q;
    buf[1] ^= buf[0];
    return buf[1];
}

void func_L39_00635270(void *arg) {
    f32 v0[4] __attribute__((aligned(16)));
    f32 v10[4] __attribute__((aligned(16)));
    f32 v20[4] __attribute__((aligned(16)));
    char buf[0x1C];
    u8 *g;
    u8 *p;
    u8 *q;
    u8 *cam;
    u32 w;
    f32 f;
    f32 fv;
    s32 behind;
    s32 i;
    s32 fp;
    s32 n;
    s32 saved;
    s32 vis;
    s32 near;
    s32 sx;
    s32 sy;
    s32 col;
    s32 hit;
    s32 flag;

    g = (u8 *)func_L39_0061D7B0(arg);
    if (D_L39_0024CF00 != D_0024112C) {
        D_L39_0024CF00 = D_0024112C;
        D_L39_00246054 = (D_L39_00246054 + 1) & 3;
    }
    if (g == 0) {
        return;
    }
    if (D_L39_00242A04 != 0) {
        func_L39_00634F80();
    }
    if (D_L39_00246050 == 0.0f) {
        D_L39_00246050 = 1.0f;
        for (p = D_L39_0024BF5C; (u32)p < D_L39_0024BF64; p += 0x100) {
            if (*(s16 *)(p + 0xAA) == 0x1C57) {
                D_L39_00246050 = *(f32 *)(p + 0x18) + 10.0f;
                break;
            }
        }
    }
    vis = (*(f32 *)(g + 0xA8) < D_L39_00246050) ? 1 : 0;

    n = *(s16 *)(g + 0x19E0);
    for (i = 0; i < n; i++) {
        func_003C5458(g + 0x1900 + i * 16, ((s32 *)(g + 0x1980))[i], ((f32 *)(g + 0x19A0))[i], ((f32 *)(g + 0x19C0))[i]);
    }

    if (g[0x24C9] != D_00241118) {
        func_L39_00587E80();
        func_0038E138();
        return;
    }

    if (*(s16 *)(g + 0x342) != 0) {
        f = (f32)*(s16 *)(g + 0x342);
        f = f * 3.14159274f / 15.0f;
        fv = func_0038D0B0(f);
        func_L39_0058B1B8(0xAA, 0, 0, (s32)((fv * 0.5f + 0.5f) * 80.0f));
        func_003A9440(0x47, 0x5360B);
    }
    saved = D_00241470;
    func_0038E150(1);
    if (D_00241640 != 0 && D_00241640[0x19F] == 0) {
        return;
    }

    for (fp = 0; fp < 8; fp++) {
        q = D_L39_0024CE20[fp];
        if (q == 0) continue;
        if (q == g) continue;
        if (vis != ((*(f32 *)(q + 0xA8) < D_L39_00246050) ? 1 : 0)) continue;
        if (dec_state_00635270(q + 0x19E6) == 0x14) {
            if (D_L39_0024CE20[fp][0x1A0A] != 0) continue;
        }
        if (dec_state_00635270(D_L39_0024CE20[fp] + 0x19E4) == 0x76) continue;
        if (dec_state_00635270(D_L39_0024CE20[fp] + 0x19E7) == 0x76) {
            if (dec_state_00635270(D_L39_0024CE20[fp] + 0x19E4) == 0x90) continue;
        }

        q = D_L39_0024CE20[fp];
        flag = 1;
        v0[0] = ((f32 *)(q + 0xA0))[0];
        v0[1] = ((f32 *)(q + 0xA0))[1];
        v0[2] = ((f32 *)(q + 0xA0))[2];
        v0[3] = ((f32 *)(q + 0xA0))[3];
        func_0038CF68(v10, *(u8 **)(q + 0x2524) + 0xE0, 1.75f);
        v0[0] = v0[0] + v10[0];
        v0[1] = v0[1] + v10[1];
        v0[2] = v0[2] + v10[2];
        q = D_L39_0024CE20[fp];
        flag = 1;
        if (D_001A5810[*(s32 *)(g + 0x2544) + 0xA4] == 0) {
            if (*(s32 *)(g + 0x24E8) == *(s32 *)(q + 0x2524)) {
                flag = 0;
            }
        } else {
            if (*(s32 *)(g + 0x122C) == *(s32 *)(q + 0x2524) && 0.7f < *(f32 *)(g + 0x1250)) {
                flag = 0;
            }
        }
        if (flag != 0) {
            if (dec_state_00635270(D_L39_0024CE20[fp] + 0x19E6) == 0x03) continue;
            if (1225.0f < func_L01_0040E548(D_L39_0024DE80 + D_00241118 * 0x460, v0)) continue;
        }

        cam = D_L39_0024DE80 + D_00241118 * 0x460;
        v20[0] = v0[0] - ((f32 *)cam)[0];
        v20[1] = v0[1] - ((f32 *)cam)[1];
        v20[2] = v0[2] - ((f32 *)cam)[2];
        func_0038CF68(v20, v20, 1.0f);
        if (func_0038CE68(v20, D_L39_0024DE80 + 0x380 + D_00241118 * 0x460) < 0.5f) continue;
        func_003860A8(v20, v0);
        sx = (s32)((v20[0] - (f32)D_00240310) * 0.0625f);
        sy = (s32)((v20[1] - (f32)D_00240314) * 0.0625f);
        if (D_00240318 + 0x40 < sx) continue;
        if (sx < -0x40) continue;
        if (D_0024031C + 0x40 < sy) continue;
        if (sy < -0x40) continue;

        col = func_L39_0066C788(*(s32 *)(D_L39_0024CE20[fp] + 0x2548));
        if (D_L39_00246054 == (fp & 3)) {
            hit = 1;
            if (flag != 0) {
                if (func_003D3CB0(D_L39_0024DE80 + D_00241118 * 0x460, v0, 0x82, 0, 0) != 0) {
                    hit = 0;
                    if (D_L39_0025F758 != 0) {
                        w = *(u32 *)(D_L39_0024CE20[fp] + 0x2528);
                        if (w != 0) {
                            s32 x = *(s32 *)(w + 0x2D0);
                            if (x != 0) {
                                hit = (D_L39_0025F758 == x);
                            }
                        }
                    }
                }
            }
            D_L39_0024CF18[fp + D_00241118 * 8] = hit;
        }
        if (D_L39_0024CF18[fp + D_00241118 * 8] == 0) continue;

        q = D_L39_0024CE20[fp];
        if (q[0x2476] == 0) {
            w = 0;
        } else {
            w = dec_state_00635270(q + 0x2476);
        }
        fv = *(f32 *)&w;
        if (fv <= 0.0f ||
            dec_state_00635270(D_L39_0024CE20[fp] + 0x19E4) == 0x39 ||
            dec_state_00635270(D_L39_0024CE20[fp] + 0x19E4) == 0x90) {
            col = func_0038DBD8(col, (s32)0x80002000, 0.5f);
        }
        p = D_00241640;
        if (p[fp * 8 + 0x80] != 0) {
            func_0011FFA8(buf, 0x17, D_L39_00246058, p + fp * 16, p + fp * 8 + 0x80);
        } else {
            func_00120D28(buf, (char *)(p + fp * 16), 0xF);
        }
        buf[0x18] = 0;
        func_003A9440(0x42, 0x8000000044L);
        func_L01_00412858(sx, sy - 3, 0x80000000, (s32)buf, -1);
        func_L01_00412858(sx - 1, sy - 4, col, (s32)buf, -1);
        func_003A9440(0x47, 0x5360B);
    }
    func_0038E150(saved);
    func_L39_00587E80();
    func_0038E138();
}
