/* func_L39_00638848: near miss (Opus L39 Sets, 2026-11-08). Multiplayer player hit reaction, 992 bytes,
   15 places, file src/levels/shared/L39_00637D38.c (needs @ps2as: inline float constants).
   Stock checker 12 rows; aligned 96.4% exact, 98.8% opcodes. Everything but one call matches: the
   `g[0x14AC] >= 5 ? 0xC : 7` argument converted with cvt.s.w. Retail computes it in $v1 after loading
   D_L39_0024601C into $a2 and sets $a3 = 0 before the mtc1; here the int lands in $a3. Tried: a block
   variable (s32/u8/s16/s8), if/else, an inline wrapper with an int parameter, the (void *, s32, s32,
   f32, s32) prototype for func_L39_0062B4A8 (same code). D_L39_0024601C must be an array (lui/lw). A
   candidate for the permuter. */
typedef union Buf_00638848 {
    u8 b[8];
    u32 w[2];
    u16 h[4];
    f32 f[2];
} Buf_00638848;

extern u8 D_L39_004997E0[];
extern u8 D_L39_004997E1[];
extern u32 D_L39_0024B9C8;

static inline u32 Dec_00638848(u8 *q) {
    Buf_00638848 buf;
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
    buf.w[0] = a;
    buf.w[1] = b;
    return b;
}

static inline s32 DecEq_00638848(u8 *q, s32 v) {
    return Dec_00638848(q) == v;
}

static inline void Prep_00638848(u8 *q) {
    s32 t;
    if (*q == 0) {
        *q = ++D_L39_004997E0[0];
    } else {
        t = *q;
        *q = D_L39_004997E1[0];
        D_L39_004997E1[0] = t;
    }
}

static inline void Set_00638848(u8 *q, u32 v) {
    u8 *hk = q;
    Buf_00638848 buf;
    u32 key;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    Prep_00638848(q);
    key = ((u32 *)D_L39_004997E0)[((u32)hk * D_L39_0024B9C8) % 510];
    k = ((u32)q - *q) & 7;
    buf.w[0] = (u32)q ^ key;
    buf.w[1] = v ^ key;
    m = *q + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        D_L39_004997E0[m + ((k + i) & 7) * 255] = *d++;
    }
}

typedef struct VT_00638848 {
    u8 pad0[0x34];
    s32 (*f34)(void *, s32, s32, s32, s32);
} VT_00638848;

typedef struct Ply_00638848 {
    u8 pad0[0x1A0];
    s32 w1A0;
} Ply_00638848;

extern void func_L39_00632D78(void *, s32, f32);
extern s32 func_L39_005C42E8(s32, s32);
extern s32 func_L39_005C2F50(void *);
extern void func_L39_0062B4A8(void *, s32, s32, s32, f32);
extern void func_L39_0062B6D8(void *, s32, s32);
extern s32 func_L39_006223B0(void *, s32);
extern void func_003C4BB0(void *, f32);
extern s32 D_L39_0024601C[];

void func_L39_00638848(u8 *g) {
    *(s32 *)(g + 0x2450) = 0;
    func_L39_00632D78(g, 0, 1.0f);
    if (((*(Ply_00638848 **)(g + 0x2534))->w1A0 & func_L39_005C42E8(8, *(s32 *)(g + 0x2544))) &&
        !(func_L39_005C2F50(*(Ply_00638848 **)(g + 0x2534)) & 0x10)) {
        (*(VT_00638848 **)(g + 0x14))->f34(g, 4, 0, 0, 1);
        func_L39_0062B4A8(g, 0xD, 2, 0, -2.0f);
        func_L39_0062B6D8(g, 3, 0x12);
        return;
    }
    if (*(f32 *)(g + 0x2468) > 0.3f && *(s16 *)(g + 0x320) == 0) {
        if (g[0x372] != 0 || g[0x1A09] != 0) {
            (*(VT_00638848 **)(g + 0x14))->f34(g, 2, 1, 0, 1);
            return;
        }
        if ((*(VT_00638848 **)(g + 0x14))->f34(g, 2, 0, 0, 1) != 0) {
            Set_00638848(g + 0x19E5, 1);
            {
                s32 n = g[0x14AC] >= 5 ? 0xC : 7;
                func_L39_0062B4A8(g, 4, D_L39_0024601C[0], 0, n);
            }
            g[0x142E] = 1;
        }
        return;
    }
    if ((*(f32 *)(g + 0x1A8) > 0.060000002f && g[0x14AC] >= 3) || DecEq_00638848(g + 0x19E4, 0x10)) {
        if ((*(VT_00638848 **)(g + 0x14))->f34(g, 3, 0, 0, 1) != 0) {
            func_L39_0062B4A8(g, 5, 0, 0, -1.0f);
            func_003C4BB0(g + 0x190, 0.10000001f);
        }
        return;
    }
    if ((g[0x14AC] >= 0xB || (*(s32 *)(g + 0x618) & 2)) && (*(VT_00638848 **)(g + 0x14))->f34(g, 0, 0, 0, 1) != 0 &&
        (*(s32 *)(g + 0x618) & 2)) {
        func_L39_0062B4A8(g, func_L39_006223B0(g, 0), 0, 0, -2.0f);
    }
}
