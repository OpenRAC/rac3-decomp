/* func_L39_00620E28: draft (Opus L39 Sets, 2026-11-08). Uses n units of the protected ammo count of
   weapon w (Dec16/Set16 on pool D_L39_00483A00 at g + w + 0x1A52), refills from the weapon table when
   D_L39_00241640->b19B is set, 1212 bytes, 15 places, file src/levels/shared/L39_00620638.c.
   Stock checker 132 rows; aligned 65.7% exact, 95.7% opcodes. Left: retail takes n as an int and
   truncates it with sll 16 at its use, keeps FindE's pieces in $s3/$s5, and needs one callee-saved
   register less (an s32 n and a struct g with &g->a1A52[w] did not get closer). */
typedef union Buf_00620E28 {
    u8 b[8];
    u32 w[2];
    u16 h[4];
} Buf_00620E28;

typedef struct Ent_00620E28 {
    u8 pad0[0x1E];
    s16 h1E;
    u8 pad20;
    s8 b21;
    u8 pad22[0x80 - 0x22];
} Ent_00620E28;

typedef struct Mp_00620E28 {
    u8 pad0[0x19B];
    s8 b19B;
} Mp_00620E28;

extern u8 D_L39_00483A00[];
extern u8 D_L39_00483A01[];
extern u32 D_L39_0024B9C8;
extern Ent_00620E28 D_L39_0049C890[];
extern Mp_00620E28 *D_L39_00241640;
extern s32 func_L39_00648AE0(u8 *, s32);

static inline void PrepC_00620E28(u8 *q) {
    s32 t;
    if (*q == 0) {
        *q = ++D_L39_00483A00[0];
    } else {
        t = *q;
        *q = D_L39_00483A01[0];
        D_L39_00483A01[0] = t;
    }
}

static inline u16 Dec16C_00620E28(u8 *q) {
    Buf_00620E28 buf;
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

static inline void Set16C_00620E28(u8 *q, s16 v) {
    u8 *hk = q;
    Buf_00620E28 buf;
    u32 key;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    PrepC_00620E28(q);
    key = ((u32 *)D_L39_00483A00)[((u32)hk * D_L39_0024B9C8) % 418];
    k = ((u32)q - *q) & 7;
    buf.h[2] = v;
    buf.w[0] = (u32)q ^ key;
    buf.w[1] = ((buf.w[1] & 0xFFFF) | (buf.w[1] << 16)) ^ key;
    m = *q + 1;
    d = buf.b;
    for (i = 0; i < 24; i += 3) {
        D_L39_00483A00[((k + i) & 7) * 209 + m] = *d++;
    }
}

static inline Ent_00620E28 *FindE_00620E28(u8 *g, s32 i) {
    if (func_L39_00648AE0(g, i)) {
        return D_L39_0049C890 + D_L39_0049C890[i].b21;
    }
    return &D_L39_0049C890[i];
}

s32 func_L39_00620E28(u8 *g, s32 w, s16 n) {
    if (g[0x1A14] != 0) {
        if (w == -1) {
            w = *(s32 *)(g + 0x478);
        }
        if (FindE_00620E28(g, w)->h1E != 0) {
            if ((s16)Dec16C_00620E28(g + w + 0x1A52) < n) {
                return 0;
            }
            Set16C_00620E28(g + w + 0x1A52, Dec16C_00620E28(g + w + 0x1A52) - n);
            if (D_L39_00241640->b19B != 0 && (s16)Dec16C_00620E28(g + w + 0x1A52) <= 0) {
                Set16C_00620E28(g + w + 0x1A52, FindE_00620E28(g, w)->h1E);
            }
        }
    }
    return 1;
}
