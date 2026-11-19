/* functional: high. Multiplayer in-game HUD update for the local player (sibling of func_L39_005DF8F8): per-player gp counter/flag, then (if D_L39_0024C3F8[me]) the score line 0x50023 from the decoded fields p+0x19E4/p+0x31C, the two marker elements 0x50007/0x50008 (tint from their object's byte 0x3B and the D_0049A008/A010 colours, placed at the player's/target's map position), the eight team-position icons 0x5000B..0x50012, the eight player blips 0x50013..0x5001A (visible via func_L39_005DC508, tint by team, spin by func_L39_005DD370, icon from the decoded p+0x19E6 flag) and the eight extra blips 0x5001B..0x50022 for the first func_L01_004D5DE8() entries. The decoders are the game's own protected-value readers (as in L39_005601D0.c). */
typedef union {
    u8 b[8];
    u32 w[2];
    u16 h[4];
} Buf_005DD810;
extern u8 D_L39_004997E0[];
extern s32 D_001D81C8_sda[] __attribute__((section(".sdata")));
extern u8 D_001D81D8_sda[] __attribute__((section(".sdata")));
extern s32 D_001DA5F0_sda;
extern u8 D_L39_0024C3F8[];
extern s32 D_L39_0024C400[];
extern s32 D_L39_0024C420[];
extern s32 D_L39_0024C430[];
extern u8 D_L39_0024CD50[];
extern u8 *D_L39_0024CE20[] __attribute__((section(".sdata")));
extern u8 D_L39_002438F8[];
extern u8 D_L39_002B58B0[];
extern u8 D_L39_00499FF0[];
extern u8 D_L39_00499FF8[];
extern u8 D_L39_0049A000[];
extern u8 D_L39_0049A008[];
extern u8 D_L39_0049A010[];
extern s32 D_L39_0024112C;
extern s32 *D_L39_00241120;
extern s32 func_L01_00517688(void);
extern s32 func_L01_0047C368(s32);
extern s32 func_L39_00610490(s32);
extern u8 *func_L39_0061BF38(s32);
extern u8 *func_L39_00666F88(s32);
extern s32 func_L01_004D5DE8(void);
extern s32 func_L06_004F7AC8(s32);
extern void func_L01_00517538(s32, f32, f32);
extern void func_L01_00517190(s32, s32);
extern void func_L01_005168F0(s32, f32);
extern s32 func_L39_005DC4C0(s32, s32 *, s32 *);
extern s32 func_L39_005DC508(void *, s32, s32);
extern f32 func_L39_005DD370(void *);
extern void func_0038CAD0(void *);
extern u8 *func_003E6C08(u8 *);
extern u8 *func_003E6DE8(u8 *);
extern u8 *func_003E6378(u8 *, s32);
extern s32 func_1321C8(f32);
extern s32 func_120048();

static __inline__ u32 dec5_005DD810(u8 *p) {
    Buf_005DD810 buf;
    u32 a;
    u32 b;
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
    a = buf.w[0] ^ (u32)p;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = b;
    return b;
}

static __inline__ u16 dec3_005DD810(u8 *p) {
    Buf_005DD810 buf;
    u32 a;
    u32 b;
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
    for (i = 0; i < 24; i += 3) {
        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
    }
    a = buf.w[0] ^ (u32)p;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = (b >> 16) / (((b ^ (b >> 16)) << 16) + 1);
    return buf.h[2];
}

static __inline__ u8 *find_005DD810(u8 *x, s32 id) {
    u8 *o = func_003E6378(func_003E6DE8(*(s32 *)(x + 4) != 0 ? x : func_003E6C08(x)), id);
    if (o != 0 && ((s32 (*)(u8 *, s32))(*(s32 *)(*(s32 *)(o + 8) + 0x10)))(o, D_001DA5F0_sda) != 0) {
        return o;
    }
    return 0;
}

static __inline__ s32 col_005DD810(u8 *c, s32 hi) {
    return hi | (c[2] << 16) | (c[1] << 8) | c[0];
}

void func_L39_005DD810(void) {
    f32 pos0[2];
    f32 pos1[2];
    f32 pos2[2];
    f32 pos3[2];
    f32 pos4[2];
    u8 *p;
    u8 *p2;
    u8 *g;
    u8 *e;
    u8 *q;
    u8 *obj;
    u8 *col;
    s32 me;
    s32 id;
    s32 k;
    s32 j;
    s32 v8;
    s32 color;
    s32 vis;
    s32 team;
    s32 fp;
    s32 t;
    f32 sc;
    f32 spin;

    me = func_L01_00517688();
    if (D_001D81C8_sda[me] != 0) {
        D_001D81C8_sda[me] = D_001D81C8_sda[me] - 1;
    } else {
        func_L39_005DBF90(-1);
        D_001D81D8_sda[me] = 1;
    }
    if (D_001D81D8_sda[me] != 0) {
        return;
    }
    if (func_L39_00610490(func_L01_0047C368(me)) != 1) {
        return;
    }
    p = func_L39_0061BF38(me);
    g = *(u8 **)(p + 0x2558);
    if (*(long *)(g + 0xC60) == -1) {
        *(s32 *)(g + 0xC60) = (s32)func_L39_005DD258(p);
    }
    if (D_L39_0024C3F8[me] != 0) {
        func_0038CAD0(&D_L39_0024C400[me]);
        if (D_L39_0024C400[me] == 0) {
            func_L39_005DD3C0(p);
        }
        if ((dec5_005DD810(p + 0x19E4) ^ 0x90) != 0) {
            func_L01_00516AA0(0x50023, 1, 0);
        } else {
            func_L01_00516AA0(0x50023, 1, 1);
            if ((s16)dec3_005DD810(p + 0x31C) > 0) {
                t = func_1321C8((f32)(s16)dec3_005DD810(p + 0x31C) / 50.0f);
                func_120048(D_L39_002B58B0 + me * 64, D_L39_002438F8, t, func_00381FF0(0x12BD));
                func_L01_00516FD8(0x50023, (s32)(D_L39_002B58B0 + me * 64));
            } else {
                func_L01_00516FD8(0x50023, func_00381FF0(0x12A5));
            }
            if (*D_L39_00241120 >= 3) {
                sc = 0.6f;
            } else if (*D_L39_00241120 >= 2) {
                sc = 1.0f;
            } else {
                sc = 0.8f;
            }
            func_L01_00517538(0x50023, sc, sc);
        }
        obj = find_005DD810(D_L39_0024CD50, 0x50007);
        if (obj != 0) {
            v8 = obj[0x3B];
            if (v8 == 0) {
                D_L39_0024C420[me] = 7;
            } else if (v8 >= 0x80) {
                D_L39_0024C420[me] = -7;
            }
            func_L01_005170B8(0x50007, col_005DD810(D_L39_0049A008, (v8 + D_L39_0024C420[me]) << 24));
        }
        g = *(u8 **)(p + 0x2558);
        if (*(s32 *)(g + 0xC64) != -1) {
            e = *(u8 **)((u8 *)&D_L39_00352940 + 0x20C);
            func_L01_00451388(D_L39_0024BF5C + (*(s32 *)(e + 0x60 + *(s32 *)(g + 0xC64) * 4) << 8), (s32 *)&pos0[0], (s32 *)&pos0[1]);
            func_L01_00516470(0x50007, pos0[0] + 0.002f, pos0[1] + 0.001f);
            func_L01_00516AA0(0x50007, 1, 1);
            func_L01_00517538(0x50007, 0.075f, 0.093f);
        } else if (*(s32 *)(g + 0xC60) != -1) {
            e = *(u8 **)((u8 *)&D_L39_00352940 + 0x20C);
            func_L01_00451388(D_L39_0024BF5C + (*(s32 *)(e + 0x40 + *(s32 *)(g + 0xC60) * 4) << 8), (s32 *)&pos1[0], (s32 *)&pos1[1]);
            func_L01_00516470(0x50007, pos1[0] + 0.002f, pos1[1] + 0.001f);
            func_L01_00516AA0(0x50007, 1, 1);
            func_L01_00517538(0x50007, 0.075f, 0.093f);
        }
    } else {
        func_L01_00516AA0(0x50023, 1, 0);
        func_L01_00516AA0(0x50007, 1, 0);
    }
    obj = find_005DD810(D_L39_0024CD50, 0x50008);
    if (obj != 0) {
        v8 = obj[0x3B];
        if (v8 == 0) {
            D_L39_0024C430[me] = 7;
        } else if (v8 >= 0x80) {
            D_L39_0024C430[me] = -7;
        }
        func_L01_005170B8(0x50008, col_005DD810(D_L39_0049A010, (v8 + D_L39_0024C430[me]) << 24));
    }
    for (id = 0x5000B; id <= 0x50012; id++) {
        k = id - 0x5000B;
        e = *(u8 **)((u8 *)&D_L39_00352940 + 0x20C);
        if (func_L39_005DC4C0(*(s32 *)(e + 0x60 + k * 4), (s32 *)&pos2[0], (s32 *)&pos2[1]) != 0) {
            color = col_005DD810(D_L39_0049A000, 0x60000000);
            if (func_L06_004F7AC8(k) != 0) {
                if ((D_L39_0024112C & 0x10) != 0) {
                    color = col_005DD810(D_L39_00499FF0, 0x60000000);
                } else {
                    color = col_005DD810(D_L39_00499FF8, 0x60000000);
                }
            } else {
                t = *(s32 *)(e + 0xA8 + k * 4);
                if (t == 0) {
                    color = col_005DD810(D_L39_00499FF0, 0x60000000);
                } else if (t == 1) {
                    color = col_005DD810(D_L39_00499FF8, 0x60000000);
                }
            }
            func_L01_00516470(id, pos2[0], pos2[1]);
            func_L01_00516AA0(id, 1, 1);
            func_L01_00517538(id, 0.05f, 0.062f);
            func_L01_005170B8(id, color);
        } else {
            func_L01_00516AA0(id, 1, 0);
        }
    }
    p2 = func_L39_0061BF38(me);
    if (*(s32 *)(p2 + 0x2528) != 0) {
        func_L01_00451388(*(u8 **)(*(u8 **)(p2 + 0x2528) + 0x2D0), (s32 *)&pos3[0], (s32 *)&pos3[1]);
    } else {
        func_L01_00451388(*(u8 **)(p2 + 0x2524), (s32 *)&pos3[0], (s32 *)&pos3[1]);
    }
    func_L01_00516470(0x50008, pos3[0] + 0.0035f, pos3[1] + 0.002f);
    func_L01_00516AA0(0x50008, 1, 1);
    func_L01_00517538(0x50008, 0.05f, 0.062f);
    fp = *(s32 *)(p2 + 0x2548);
    for (id = 0x50013; id <= 0x5001A; id++) {
        j = id - 0x50013;
        q = D_L39_0024CE20[j];
        vis = 0;
        if (q != 0 && *(s32 *)(q + 0x2528) == 0) {
            vis = func_L39_005DC508(q + 0xA0, *(s32 *)(q + 0x2548), fp);
            q = D_L39_0024CE20[j];
            if (*(s32 *)(q + 0x2548) != *(s32 *)(p2 + 0x2548)) {
                if (dec5_005DD810(q + 0x19E6) == 3) {
                    vis = 0;
                }
            }
            if (vis != 0) {
                q = D_L39_0024CE20[j];
                if (*(s32 *)(q + 0x2548) == 0) {
                    color = col_005DD810(D_L39_00499FF0, 0x70000000);
                } else {
                    color = col_005DD810(D_L39_00499FF8, 0x70000000);
                }
                q = D_L39_0024CE20[j];
                func_L01_00451388(*(u8 **)(q + 0x2524), (s32 *)&pos4[0], (s32 *)&pos4[1]);
                func_L01_00516470(id, pos4[0], pos4[1]);
                func_L01_00517538(id, 0.035f, 0.0434f);
                func_L01_005170B8(id, color);
                spin = func_L39_005DD370(*(u8 **)(D_L39_0024CE20[j] + 0x2524));
                q = D_L39_0024CE20[j];
                if (dec5_005DD810(q + 0x19E6) != 0x14) {
                    func_L01_00517190(id, 0xED35);
                    func_L01_005168F0(id, spin);
                } else {
                    func_L01_00517190(id, 0xED3B);
                    func_L01_005168F0(id, 0.0f);
                }
            }
        }
        func_L01_00516AA0(id, 1, vis);
    }
    for (id = 0x5001B; id <= 0x50022; id++) {
        k = id - 0x5001B;
        vis = 0;
        if (k < func_L01_004D5DE8()) {
            q = func_L39_00666F88(k);
            if (q != 0) {
                obj = *(u8 **)(q + 0x2D0);
                t = obj[0xBC];
                if (t != 8 && t != 7) {
                    team = -1;
                    if (*(s32 *)(q + 0x2D8) != 0) {
                        team = *(s32 *)(*(s32 *)(q + 0x2D8) + 0x2548);
                    } else if (*(s32 *)(q + 0x2DC) != 0) {
                        team = *(s32 *)(*(s32 *)(q + 0x2DC) + 0x2548);
                    }
                    vis = func_L39_005DC508(obj + 0x10, team, fp);
                    if (vis != 0) {
                        color = col_005DD810(D_L39_0049A000, 0x70000000);
                        if (team == 0) {
                            color = col_005DD810(D_L39_00499FF0, 0x70000000);
                        } else if (team == 1) {
                            color = col_005DD810(D_L39_00499FF8, 0x70000000);
                        }
                        func_L01_00451388(*(u8 **)(q + 0x2D0), (s32 *)&pos4[0], (s32 *)&pos4[1]);
                        func_L01_00516470(id, pos4[0], pos4[1]);
                        func_L01_00517538(id, 0.05f, 0.062f);
                        func_L01_005170B8(id, color);
                        func_L01_005168F0(id, func_L39_005DD370(*(u8 **)(q + 0x2D0)));
                        t = *(s16 *)(*(u8 **)(q + 0x2D0) + 0xAA);
                        if (t == 0x107E) {
                            func_L01_00517190(id, 0xED37);
                        } else if (t == 0x107C) {
                            func_L01_00517190(id, 0xED36);
                        } else if (t == 0x10C2) {
                            func_L01_00517190(id, 0xED4B);
                        }
                    }
                }
            }
        }
        func_L01_00516AA0(id, 1, vis);
    }
}
