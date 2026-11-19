/* functional: high. Multiplayer-menu team scoreboard update for the local player (sister of func_L39_005DF060's setup): counts down / sets the per-player gp counters, picks the header labels 0x60006/0x60007 by D_L39_00241640's mode word, shows the 0x60038 score line (text from the player's decoded fields p+0x19E4 and p+0x31C, scale by player count), then lays out the team rows (func_L39_005DF510 builds them): per team a header row (name, two numbers) and per member a row, writing label text, positions, flags and colours into elements 0x60008/0x60018/0x60028 + row; unused rows are cleared. The two inlined decoders are the game's own protected-value readers (as in L39_005601D0.c). */
typedef union {
    u8 b[8];
    u32 w[2];
    u16 h[4];
} Buf_005DF8F8;
extern u8 D_L39_004997E0[];
extern s32 D_001D8208_sda[] __attribute__((section(".sdata")));
extern u8 D_001D8218_sda[] __attribute__((section(".sdata")));
extern u8 D_001D8228_sda[] __attribute__((section(".sdata")));
extern u8 D_L39_0024C4E0[];
extern u8 D_L39_00243930[];
extern u8 D_L39_00243938[];
extern u8 D_L39_002B59B0[];
extern u8 D_L39_002B5AB0[];
extern u8 D_L39_002B5B50[];
extern s32 *D_L39_00241120;
extern s32 func_L01_00517688(void);
extern s32 func_L39_005E0310(s32);
extern s32 func_L39_00610490(s32);
extern u8 *func_L39_0061BF38(s32);
extern void func_L01_00517538(s32, f32, f32);
extern s32 func_L39_0066C788(s32);
extern s32 func_1321C8(f32);
extern s32 func_120048();

static __inline__ u32 dec5_005DF8F8(u8 *p) {
    Buf_005DF8F8 buf;
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

static __inline__ u16 dec3_005DF8F8(u8 *p) {
    Buf_005DF8F8 buf;
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

void func_L39_005DF8F8(void) {
    A_005DF510 a[8];
    B_005DF510 b[8];
    u8 *p;
    s32 me;
    s32 mode;
    s32 n;
    s32 i;
    s32 j;
    s32 row;
    s32 off;
    s32 id1;
    s32 id2;
    s32 id3;
    s32 color;
    f32 y;
    f32 yc;
    f32 xoff;
    f32 sc;
    B_005DF510 *nd;

    me = func_L01_00517688();
    if (D_001D8208_sda[me] != 0) {
        D_001D8208_sda[me] = D_001D8208_sda[me] - 1;
    } else {
        func_L39_005DEDD8();
        D_001D8218_sda[me] = 1;
    }
    if (D_001D8218_sda[me] != 0) {
        return;
    }
    mode = func_L39_00610490(func_L39_005E0310(me));
    if (mode != 1) {
        return;
    }
    p = func_L39_0061BF38(me);
    if (D_L39_00241640 != 0) {
        s32 w = *(s32 *)(D_L39_00241640 + 0x180);
        if (w == 2) {
            func_L01_00516FD8(0x60006, func_00381FF0(0x1336));
            func_L01_00516FD8(0x60007, func_00381FF0(0x1337));
        } else if (w == mode) {
            func_L01_00516FD8(0x60006, func_00381FF0(0x1B73));
            func_L01_00516FD8(0x60007, func_00381FF0(0x1B74));
        }
    }
    if (D_L39_0024C4E0[me] != 0) {
        if (dec5_005DF8F8(p + 0x19E4) ^ 0x90) {
            func_L01_00516AA0(0x60038, 1, 0);
        } else {
            func_L01_00516AA0(0x60038, 1, 1);
            if ((s16)dec3_005DF8F8(p + 0x31C) > 0) {
                s32 t = func_1321C8((f32)(s16)dec3_005DF8F8(p + 0x31C) / 50.0f);
                func_120048(D_L39_002B59B0 + me * 64, D_L39_00243930, t, func_00381FF0(0x12BD));
                func_L01_00516FD8(0x60038, (s32)(D_L39_002B59B0 + me * 64));
            } else {
                func_L01_00516FD8(0x60038, func_00381FF0(0x12A5));
            }
            if (*D_L39_00241120 >= 3) {
                sc = 0.6f;
            } else if (*D_L39_00241120 >= 2) {
                sc = 1.0f;
            } else {
                sc = 0.8f;
            }
            func_L01_00517538(0x60038, sc, sc);
        }
    } else {
        func_L01_00516AA0(0x60038, 1, 0);
    }
    func_L01_00516470(0x60005, 0.28f, 0.25f);
    func_L01_00516470(0x60006, 0.62f, 0.25f);
    func_L01_00516470(0x60007, 0.83f, 0.25f);
    func_L01_00516AA0(0x60005, 1, 1);
    func_L01_00516AA0(0x60006, 1, 1);
    func_L01_00516AA0(0x60007, 1, 1);
    n = func_L39_005DF510(a, b);
    row = 0;
    off = 0;
    yc = 0.06f;
    xoff = 0.0f;
    if (*(s8 *)(D_L39_00241640 + 0x19D) != 0) {
        xoff = 0.13f;
    }
    for (i = 0; i < n; i++) {
        if (*(s8 *)(D_L39_00241640 + 0x19D) != 0) {
            id1 = 0x60008 + row;
            id2 = 0x60018 + row;
            id3 = 0x60028 + row;
            func_120048(D_L39_002B5AB0 + off, D_001D8228_sda, a[i].f4);
            y = yc + 0.25f;
            func_120048(D_L39_002B5B50 + off, D_001D8228_sda, a[i].f8);
            row++;
            func_L01_00516FD8(id1, (s32)a[i].f0);
            func_L01_00516FD8(id2, (s32)(D_L39_002B5AB0 + off));
            func_L01_00516FD8(id3, (s32)(D_L39_002B5B50 + off));
            off += 10;
            func_L01_00516AA0(id1, 0x200, 1);
            func_L01_00516AA0(id1, 0x400, 0);
            func_L01_00516470(id1, 0.28f - xoff, y);
            func_L01_00516470(id2, 0.62f, y);
            func_L01_00516470(id3, 0.83f, y);
            func_L01_00516AA0(id1, 1, 1);
            func_L01_00516AA0(id2, 1, 1);
            func_L01_00516AA0(id3, 1, 1);
            color = func_L39_0066C788(a[i].f10);
            func_L01_005170B8(id1, color);
            func_L01_005170B8(id2, color);
            func_L01_005170B8(id3, color);
            yc += 0.04f;
        }
        nd = a[i].f14;
        while (nd != 0) {
            id1 = 0x60008 + row;
            id2 = 0x60018 + row;
            id3 = 0x60028 + row;
            y = yc + 0.25f;
            func_120048(D_L39_002B5AB0 + off, D_L39_00243938, nd->f4);
            func_120048(D_L39_002B5B50 + off, D_L39_00243938, nd->f8);
            func_L01_00516FD8(id1, (s32)nd->f0);
            func_L01_00516FD8(id2, (s32)(D_L39_002B5AB0 + off));
            func_L01_00516FD8(id3, (s32)(D_L39_002B5B50 + off));
            func_L01_00516470(id1, 0.28f, y);
            func_L01_00516470(id2, 0.62f, y);
            func_L01_00516470(id3, 0.83f, y);
            func_L01_00516AA0(id1, 0x200, 1);
            func_L01_00516AA0(id1, 0x400, 1);
            func_L01_00516AA0(id1, 1, 1);
            func_L01_00516AA0(id2, 1, 1);
            func_L01_00516AA0(id3, 1, 1);
            if (nd->f10 == *(s32 *)(p + 0x2544)) {
                color = 0x8000FF00;
            } else {
                color = 0x8066CCFF;
            }
            func_L01_005170B8(id1, color);
            func_L01_005170B8(id2, color);
            func_L01_005170B8(id3, color);
            off += 10;
            yc += 0.04f;
            row++;
            nd = nd->f18;
        }
    }
    for (j = row; j < 16; j++) {
        func_L01_00516AA0(0x60008 + j, 1, 0);
        func_L01_00516AA0(0x60018 + j, 1, 0);
        func_L01_00516AA0(0x60028 + j, 1, 0);
    }
}
