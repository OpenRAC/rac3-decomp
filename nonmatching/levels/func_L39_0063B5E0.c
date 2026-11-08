/* func_L39_0063B5E0: near miss (Opus L39 Sets, 2026-11-08). Multiplayer damage to the protected health
   float at g + 0x2476 (DecF/SetF, pool D_L39_004997E0), 912 bytes, 15 places, file
   src/levels/shared/L39_00639350.c (@ps2as). Stock checker 152 rows; aligned 72.4% exact, 96.9% opcodes.
   Left: retail computes q = g + 0x2476 in the delay slot of the `dmg != 0` branch and its DecF keeps a
   copy of q (`move $t5, $t3`: k uses the copy, the xor q). Passing g + 0x2476 at each call gives the
   copy but not the early address; a variable q before the test gives the early address but loses the
   copy (u32 variable, a hk-style copy inside DecF: no change). */
typedef union Buf_0063B5E0 {
    u8 b[8];
    u32 w[2];
    u16 h[4];
    f32 f[2];
} Buf_0063B5E0;

extern u8 D_L39_004997E0[];
extern u8 D_L39_004997E1[];
extern u32 D_L39_0024B9C8;

static inline void Prep_0063B5E0(u8 *q) {
    s32 t;
    if (*q == 0) {
        *q = ++D_L39_004997E0[0];
    } else {
        t = *q;
        *q = D_L39_004997E1[0];
        D_L39_004997E1[0] = t;
    }
}

static inline f32 DecF_0063B5E0(u8 *q) {
    Buf_0063B5E0 buf;
    u32 a;
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
        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
    }
    a = buf.w[0] ^ (u32)q;
    buf.w[0] = a;
    buf.w[1] ^= a;
    return buf.f[1];
}

static inline void SetF_0063B5E0(u8 *q, f32 v) {
    u8 *hk = q;
    Buf_0063B5E0 buf;
    u32 key;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    Prep_0063B5E0(q);
    key = ((u32 *)D_L39_004997E0)[((u32)hk * D_L39_0024B9C8) % 510];
    k = ((u32)q - *q) & 7;
    buf.w[0] = (u32)q ^ key;
    buf.f[1] = v;
    buf.w[1] ^= key;
    m = *q + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        D_L39_004997E0[m + ((k + i) & 7) * 255] = *d++;
    }
}

typedef struct Cam_0063B5E0 {
    u8 pad0[0x44];
    f32 f44;
} Cam_0063B5E0;

typedef struct Lnk_0063B5E0 {
    u8 pad0[4];
    Cam_0063B5E0 *p4;
} Lnk_0063B5E0;

void func_L39_0063B5E0(u8 *g, s32 dmg) {
    if (g[0x1A14] != 0 && dmg != 0) {
        f32 f = dmg;
        *(s32 *)(g + 0x24D4) = dmg;
        SetF_0063B5E0(g + 0x2476, DecF_0063B5E0(g + 0x2476) - f);
        if (DecF_0063B5E0(g + 0x2476) < 0.0f) {
            SetF_0063B5E0(g + 0x2476, 0.0f);
        }
        *(s32 *)(g + 0x2514) = 300;
        if (*(Lnk_0063B5E0 **)(g + 0x2558) != 0 && (*(Lnk_0063B5E0 **)(g + 0x2558))->p4 != 0) {
            (*(Lnk_0063B5E0 **)(g + 0x2558))->p4->f44 = DecF_0063B5E0(g + 0x2476);
        }
    }
}
