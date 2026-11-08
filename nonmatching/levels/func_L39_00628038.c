/* func_L39_00628038: near miss (Opus L39 Sets, 2026-11-08). Multiplayer state 0x90 entry: sends a 12-byte
   packet (func_14AD08) and stores func_L39_0053D838's result with Set16, 1004 bytes, 15 places, file
   src/levels/shared/L39_00622990.c (@ps2as). Stock checker 110 rows; aligned 68.9% exact, 90.4% opcodes.
   Found: the packet part is an inline (Report_00628038: its frame holds pk and the nested Dec, as one
   0x18 slot), the 0x19E8 test is `t = DecEq(...)` before the 0x1A14 test, and the id is assigned on each
   path (no -1 default live across the calls). Left: the frame is 0x60 (retail 0x50): Report's slot lands
   at sp+0x10 because the earlier Dec temps keep sp+0 (8 bytes) and the 0x18 request does not fit
   there; retail has pk at 0 and the Set16 buffer at 0 too. */
typedef union Buf_00628038 {
    u8 b[8];
    u32 w[2];
    u16 h[4];
    f32 f[2];
} Buf_00628038;

extern u8 D_L39_004997E0[];
extern u8 D_L39_004997E1[];
extern u32 D_L39_0024B9C8;

static inline u32 Dec_00628038(u8 *q) {
    Buf_00628038 buf;
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

static inline s32 DecEq_00628038(u8 *q, s32 v) {
    return Dec_00628038(q) == v;
}

static inline void Prep_00628038(u8 *q) {
    s32 t;
    if (*q == 0) {
        *q = ++D_L39_004997E0[0];
    } else {
        t = *q;
        *q = D_L39_004997E1[0];
        D_L39_004997E1[0] = t;
    }
}

static inline void Set16_00628038(u8 *q, s16 v) {
    u8 *hk = q;
    Buf_00628038 buf;
    u32 key;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    Prep_00628038(q);
    buf.h[2] = v;
    key = ((u32 *)D_L39_004997E0)[((u32)hk * D_L39_0024B9C8) % 510];
    k = ((u32)q - *q) & 7;
    buf.w[1] = ((buf.w[1] & 0xFFFF) | (buf.w[1] << 16)) ^ key;
    buf.w[0] = (u32)q ^ key;
    m = *q + 1;
    d = buf.b;
    for (i = 0; i < 24; i += 3) {
        D_L39_004997E0[m + ((k + i) & 7) * 255] = *d++;
    }
}

typedef struct Pkt_00628038 {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    u8 b4;
    u8 pad5[3];
    s32 w8;
} Pkt_00628038;

typedef struct VT_00628038 {
    u8 pad0[0x1C];
    s32 (*f1C)(void *, s32);
    u8 pad20[0x34 - 0x20];
    s32 (*f34)(void *, s32, s32, s32, s32);
} VT_00628038;

typedef struct Sub_00628038 {
    u8 pad0[0xAA];
    s16 hAA;
} Sub_00628038;

typedef struct Obj_00628038 {
    u8 pad0[3];
    u8 b3;
    u8 pad4[0x14 - 4];
    VT_00628038 *vt;
    u8 pad18[0x1C - 0x18];
    Sub_00628038 *p1C;
    u8 pad20[0x2544 - 0x20];
    u8 b2544;
} Obj_00628038;

typedef struct Net_00628038 {
    u8 pad0[4];
    s32 w4;
    u8 pad8[0x170 - 8];
    s32 w170;
    u8 pad174[0x7D4 - 0x174];
    u8 b7D4;
} Net_00628038;

extern Net_00628038 D_1A5CD0;
extern s32 D_L39_002405B8[];
extern Obj_00628038 *func_L39_0061D1D8(s32);
extern s32 func_L39_0066F558(s32);
extern s32 func_L39_005B4398(s32, u32);
extern void func_14AD08(s32, s32, s32, s32, s32, void *);
extern void func_L39_00670AE0(void *);
extern s32 func_L39_0053D838(void *);

static inline void Report_00628038(u8 *g) {
    Pkt_00628038 pk;
    Obj_00628038 *o;
    s32 id;
    u32 c;

    o = func_L39_0061D1D8(*(s32 *)(g + 0x24CC));
    if (o != 0 && (o->b3 & 0xF) == 0 && o->vt->f1C(o, *(s32 *)(g + 0x2548)) == 0) {
        id = o->b2544;
    } else if (o != 0 && (o->b3 & 0xF) == 2 && o->p1C != 0) {
        id = func_L39_0066F558(o->p1C->hAA);
    } else {
        id = -1;
    }
    pk.b0 = id;
    pk.b2 = g[0x2544];
    c = Dec_00628038(g + 0x19E4);
    pk.b1 = c;
    pk.b3 = g[0x24D0];
    pk.w8 = *(s32 *)(g + 0x24CC);
    pk.b4 = func_L39_005B4398(0x10, c);
    if (D_1A5CD0.w170 == 0) {
        func_14AD08(D_1A5CD0.b7D4 | 0x40, D_1A5CD0.w4, -1, D_L39_002405B8[0], 0xC, &pk);
    }
    func_L39_00670AE0(&pk);
}

void func_L39_00628038(u8 *g, s32 on) {
    s32 t;

    if (DecEq_00628038(g + 0x19E4, 0x90)) {
        return;
    }
    if (on != 0) {
        g[0x2501] = 1;
    } else {
        g[0x2501] = 0;
    }
    t = DecEq_00628038(g + 0x19E8, 0x14);
    if (g[0x1A14] != 0 && !t) {
        Report_00628038(g);
    }
    Set16_00628038(g + 0x31C, func_L39_0053D838(g));
    *(s32 *)(g + 0x610) = 0;
    g[0x1A13] = 0;
    (*(VT_00628038 **)(g + 0x14))->f34(g, 0x90, 0, 1, 1);
}
