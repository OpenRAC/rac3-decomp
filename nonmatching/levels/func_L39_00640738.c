/* func_L39_00640738: near miss (Opus, 2026-11-08). Multiplayer per-player state update, 12,968 bytes,
   15 places (levels 39-53), file src/levels/shared/L39_0063E9E8.c. Needs `@ps2as` on the file's line
   (scalar D_L39_0024B9C8 read through lui/lw, inline float constants in the 0x47A9E0 switch); the other C
   functions of that file have not been checked with it (split at an 8-aligned start if they differ).
   Stock checker, level 39, --as ps2as: 3242 of 3242 instructions, frame 0x60 and the prologue's register
   assignment (s in $s1, b in $s4) equal retail; 95.0% of opcodes equal when registers are masked; most rows
   still differ by register numbering (3140 rows).
   Shapes found against retail (2026-11-08, from 3147 rows / 66% opcodes at the Sonnet prep):
   - Set (anti-tamper store): key index `((u32 *)tbl)[(D * (u32)h) % 0x182]`, `buf.w[1] = ((v & 0xFFFF) |
     (v << 16)) ^ k; buf.w[0] = (u32)h ^ k;`, id = *h + 1 read after the stores, then
     `for (i = 0; i < 24; i += 3) tbl[((o + i) & 7) * 0xC1 + id] = *p++;` with p = buf.b (0x1FE / 0xFF for
     D_L39_004997E0). Gets follow func_L39_0065D0A0's Dec/Dec2 (step 5, i < 40, no division, for b19E4/b19E6).
   - Constant arguments 0xA, 0xB, 0xE, 0xF and 1: retail builds `K << 16` at run time (li/sll/ori, or `or`
     with a register already holding K), as if the value reached Set through a parameter copy; passing them
     through a block variable (`{ u32 st = K; SetA(h, st); }`) reproduces it. The two 0x19 calls must stay
     literal. Making v modified inside Set does it for every call but breaks the 0x19 pair.
   - Comparisons of a Get against a value go through `EqX(q, v) { return GetX(q) == v; }` (xori/beql).
   - FindE: nothing computed before func_L39_00648AE0 (`if (call) return &D[D[i].b21]; return &D[i];`): this
     put b back in $s4 and keeps only the lui of D_L39_0049C890 live across the call ($s6), as retail.
   Set copy (2026-11-08, docs/protected_values.md): retail's second register copy of a Set's h
   (`addiu $t2, $s2, 0x1a25; move $t0, $t2`, used only by the key mult) comes from a second user
   variable `u8 *hk = h;` used only by the key, `(u32)hk * D` (h first). Zero stores have no copy,
   so they go through ClrA/ClrB3. That took the stock checker from 3140 to 1242 differing rows (aligned
   opcodes 96.5% to 97.4%), and every Set site's copy now follows retail.
   Left: the control flow is still a goto translation of retail's labels.
   The 0x47A9E0 switch's cases are read from the table: 3 -> 200, 4 -> 120, 1 -> 35, 2 -> 30, 10/11 -> 0, else 20.
   Work files: ~/RACSwarm/opus-l4/w/0738 (greedy.py / greedy2.py try per-site variants).
   Opus L39 Sets (2026-11-08): the 0xE/0xF blocks are `if (w != 0) SetA(h25, w); else { u32 st = 0x19;
   SetA(h25, st); }` (retail falls through to the variable store and builds 0x19 with li/sll/ori), and
   the 0x13 test is EqB5 (xori). Stock checker 1210 rows (was 1242), aligned 88.9% exact / 97.9% opcodes,
   61 opcode-diff regions (was 79). The variable-value SetA sites still differ by scheduling: retail keeps
   the value in $a1 and builds (v & 0xFFFF) | (v << 16) before the table lui; moving the mix inside SetA
   does not change it (sched2 follows the register choice). Moving it before Prep breaks every site.
   Opus mp39b (2026-11-08): stock checker 1210 -> 1021 rows, aligned 95.8% exact / 99.3% opcodes, 24
   opcode-diff regions (was 61). What did it:
   - Variable-value Sets write buf.w[0] before buf.w[1] (SetAV); constant ones keep w[1] first (SetA).
     That alone put the value in $a1 and the mix back in place (local-alloc order follows sched1's).
   - Pl_00640738 aligned(16): get_inner_reference's alignment is min(Pl, S), and with exactly 4 bytes
     expand_expr folds the field offset into the base first ((s + 0x474) + b*0x50, which GCSE then hoists
     into $s3/$s5/$s6). With 16, retail's (s + b*0x50) + 0x474 / `lw 0x474($v0)` comes back.
   - A Get whose value is dropped still assigns it (`y = GetA(&s->h25[1])`): the dead `= 0` arm keeps
     the body a jump target until flow, so *q is reloaded as in retail.
   - Get-then-Set copies pass the Get as the Set's argument (SetAV(&s->h1F[b], GetA(&s->h19[b]))).
   - The 0x19-folded v at L1CEC goes through a Set without hk (SetAVN); ((u32)c >> 14) & 1 (srl).
   - One w variable per site (w1..w6) instead of one w reused.
   Left: the (b + s) + 0x1A19 recomputed for the Get at 00642AAC (mine reuses $s2), branch-likely
   choices at 0064136C/00642A08, the final ClrA after L38EC (retail forms h only after the Prep), the
   0x0C test at 00642EF8 (retail materialises a 0/1 flag), and a few delay-slot nops. */
typedef union {
    u8 b[8];
    u16 h[4];
    u32 w[2];
} Buf_00640738;

typedef struct { u8 pad0[0xC]; u8 b0C; } N_00640738;
typedef struct { u8 pad0[0x24]; N_00640738 *p24; } M_00640738;
typedef struct { u8 pad0[0x1A4]; u32 w1A4; } P_00640738;
typedef struct { u8 pad0[0x34]; s32 w34; } Q_00640738;

typedef struct {
    M_00640738 *p00;
    M_00640738 *p04;
    u8 pad08[0x11];
    u8 b19;
    u8 b1A;
    u8 pad1B;
    u8 b1C;
    u8 b1D;
    u8 pad1E[2];
    s32 w20;
    s32 w24;
    s32 w28;
    u8 pad2C[0x24];
} __attribute__((aligned(16))) Pl_00640738;

typedef struct {
    u8 pad000[0x2D8];
    s16 h2D8;
    u8 pad2DA[0x16];
    s32 w2F0;
    u8 pad2F4[0x83];
    u8 b377;
    u8 pad378[0xD8];
    Pl_00640738 pl[2];
    u8 pad4F0[0x250];
    Q_00640738 *p740;
    Q_00640738 *p744;
    s32 w748;
    u8 pad74C[8];
    s32 w754;
    u8 pad758[0x948];
    s32 w10A0;
    u8 pad10A4[0x1DC];
    u16 h1280;
    u8 pad1282[0x3E];
    f32 f12C0;
    u8 pad12C4[0x60C];
    s32 w18D0[2];
    u8 pad18D8[0x10C];
    u8 b19E4;
    u8 pad19E5;
    u8 b19E6;
    u8 pad19E7[0x1E];
    u8 b1A05;
    u8 pad1A06;
    u8 b1A07;
    u8 pad1A08[4];
    u8 b1A0C;
    u8 pad1A0D;
    u8 b1A0E;
    u8 pad1A0F[3];
    u8 b1A12;
    u8 b1A13;
    u8 pad1A14[3];
    u8 b1A17;
    u8 pad1A18;
    u8 h19[2];
    u8 pad1A1B[4];
    u8 h1F[2];
    u8 pad1A21[4];
    u8 h25[2];
    u8 pad1A27[4];
    u8 h2B[2];
    u8 pad1A2D[4];
    u8 b1A31;
    u8 pad1A32[0xE];
    u8 b1A40;
    u8 pad1A41[0xABE];
    u8 b24FF;
    u8 pad2500[0x1C];
    s32 w251C;
    u8 pad2520[0x14];
    P_00640738 *p2534;
} S_00640738;

typedef struct {
    u8 pad00[4];
    s16 h04;
    u8 pad06[5];
    s8 b0B;
    u8 pad0C[0x10];
    s16 h1C;
    u8 pad1E[3];
    s8 b21;
    u8 pad22[0x5E];
} E_00640738;

extern u32 D_L39_0024B9C8;
extern u8 D_L39_00480760[];
extern u8 D_L39_00480761[];
extern u8 D_L39_004997E0[];
extern u8 D_L39_004997E1[];
extern u8 D_L39_00483A00[];
extern E_00640738 D_L39_0049C890[];

extern s32 func_L01_004606E8(s32, s32, s32, s32);
extern s32 func_L39_00639D90(void *);
extern s32 func_L39_00648AE0(void *, s32);
extern s32 func_L01_0040E020(void *);
extern void func_L39_00621D30(void *);
extern s32 func_L39_005B43C8(s32, s32);
extern void func_L39_00622288(void *);
extern s32 func_L01_004944E8(s32);
extern void func_L01_003EE640(s32);
extern void func_003C3A10(void *, s32, s32, s32);

static __inline__ E_00640738 *FindE_00640738(S_00640738 *s, s32 i) {
    if (func_L39_00648AE0(s, i)) {
        return &D_L39_0049C890[D_L39_0049C890[i].b21];
    }
    return &D_L39_0049C890[i];
}

/* Store v into the protected variable whose handle byte is *h. The key multiply reads hk, a second
   copy of the handle pointer: retail keeps that copy in its own register (`move $t0, $t2` ahead of the
   *h == 0 test) and uses it for nothing else; see docs/protected_values.md. */
static __inline__ void SetA_00640738(u8 *h, u32 v) {
    u8 *hk = h;
    Buf_00640738 buf;
    u32 k;
    s32 o;
    s32 id;
    s32 i;
    u8 *p;

    if (*h == 0) {
        *h = ++D_L39_00480760[0];
    } else {
        u8 t = *h;
        *h = D_L39_00480761[0];
        D_L39_00480761[0] = t;
    }
    k = ((u32 *)D_L39_00480760)[((u32)hk * D_L39_0024B9C8) % 0x182];
    o = ((u32)h - *h) & 7;
    buf.w[1] = ((v & 0xFFFF) | (v << 16)) ^ k;
    buf.w[0] = (u32)h ^ k;
    id = *h + 1;
    p = buf.b;
    for (i = 0; i < 24; i += 3) {
        D_L39_00480760[((o + i) & 7) * 0xC1 + id] = *p++;
    }
}

static __inline__ void SetAV_00640738(u8 *h, u32 v) {
    u8 *hk = h;
    Buf_00640738 buf;
    u32 k;
    s32 o;
    s32 id;
    s32 i;
    u8 *p;

    if (*h == 0) {
        *h = ++D_L39_00480760[0];
    } else {
        u8 t = *h;
        *h = D_L39_00480761[0];
        D_L39_00480761[0] = t;
    }
    k = ((u32 *)D_L39_00480760)[((u32)hk * D_L39_0024B9C8) % 0x182];
    o = ((u32)h - *h) & 7;
    buf.w[0] = (u32)h ^ k;
    buf.w[1] = ((v & 0xFFFF) | (v << 16)) ^ k;
    id = *h + 1;
    p = buf.b;
    for (i = 0; i < 24; i += 3) {
        D_L39_00480760[((o + i) & 7) * 0xC1 + id] = *p++;
    }
}

static __inline__ void SetAVN_00640738(u8 *h, u32 v) {
    Buf_00640738 buf;
    u32 k;
    s32 o;
    s32 id;
    s32 i;
    u8 *p;

    if (*h == 0) {
        *h = ++D_L39_00480760[0];
    } else {
        u8 t = *h;
        *h = D_L39_00480761[0];
        D_L39_00480761[0] = t;
    }
    k = ((u32 *)D_L39_00480760)[((u32)h * D_L39_0024B9C8) % 0x182];
    o = ((u32)h - *h) & 7;
    buf.w[0] = (u32)h ^ k;
    buf.w[1] = ((v & 0xFFFF) | (v << 16)) ^ k;
    id = *h + 1;
    p = buf.b;
    for (i = 0; i < 24; i += 3) {
        D_L39_00480760[((o + i) & 7) * 0xC1 + id] = *p++;
    }
}

/* Store 0: retail's zero stores keep no second copy of h. */
static __inline__ void ClrA_00640738(u8 *h) {
    Buf_00640738 buf;
    u32 k;
    s32 o;
    s32 id;
    s32 i;
    u8 *p;

    if (*h == 0) {
        *h = ++D_L39_00480760[0];
    } else {
        u8 t = *h;
        *h = D_L39_00480761[0];
        D_L39_00480761[0] = t;
    }
    k = ((u32 *)D_L39_00480760)[((u32)h * D_L39_0024B9C8) % 0x182];
    o = ((u32)h - *h) & 7;
    buf.w[1] = k;
    buf.w[0] = (u32)h ^ k;
    id = *h + 1;
    p = buf.b;
    for (i = 0; i < 24; i += 3) {
        D_L39_00480760[((o + i) & 7) * 0xC1 + id] = *p++;
    }
}

/* Store v into the protected variable whose handle byte is *h. The key multiply reads hk, a second
   copy of the handle pointer: retail keeps that copy in its own register (`move $t0, $t2` ahead of the
   *h == 0 test) and uses it for nothing else; see docs/protected_values.md. */
static __inline__ void SetB3_00640738(u8 *h, u32 v) {
    u8 *hk = h;
    Buf_00640738 buf;
    u32 k;
    s32 o;
    s32 id;
    s32 i;
    u8 *p;

    if (*h == 0) {
        *h = ++D_L39_004997E0[0];
    } else {
        u8 t = *h;
        *h = D_L39_004997E1[0];
        D_L39_004997E1[0] = t;
    }
    k = ((u32 *)D_L39_004997E0)[((u32)hk * D_L39_0024B9C8) % 0x1FE];
    o = ((u32)h - *h) & 7;
    buf.w[1] = ((v & 0xFFFF) | (v << 16)) ^ k;
    buf.w[0] = (u32)h ^ k;
    id = *h + 1;
    p = buf.b;
    for (i = 0; i < 24; i += 3) {
        D_L39_004997E0[((o + i) & 7) * 0xFF + id] = *p++;
    }
}

/* Store 0: retail's zero stores keep no second copy of h. */
static __inline__ void ClrB3_00640738(u8 *h) {
    Buf_00640738 buf;
    u32 k;
    s32 o;
    s32 id;
    s32 i;
    u8 *p;

    if (*h == 0) {
        *h = ++D_L39_004997E0[0];
    } else {
        u8 t = *h;
        *h = D_L39_004997E1[0];
        D_L39_004997E1[0] = t;
    }
    k = ((u32 *)D_L39_004997E0)[((u32)h * D_L39_0024B9C8) % 0x1FE];
    o = ((u32)h - *h) & 7;
    buf.w[1] = k;
    buf.w[0] = (u32)h ^ k;
    id = *h + 1;
    p = buf.b;
    for (i = 0; i < 24; i += 3) {
        D_L39_004997E0[((o + i) & 7) * 0xFF + id] = *p++;
    }
}

static __inline__ u32 GetA_00640738(u8 *q) {
    Buf_00640738 buf;
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
        *d++ = D_L39_00480760[((k + i) & 7) * 0xC1 + m];
    }
    a = buf.w[0] ^ (u32)q;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = (b >> 16) / (((b ^ (b >> 16)) << 16) + 1);
    return buf.w[1];
}


static __inline__ u32 GetB3_00640738(u8 *q) {
    Buf_00640738 buf;
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
        *d++ = D_L39_004997E0[((k + i) & 7) * 0xFF + m];
    }
    a = buf.w[0] ^ (u32)q;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = (b >> 16) / (((b ^ (b >> 16)) << 16) + 1);
    return buf.w[1];
}

static __inline__ u32 GetB3b_00640738(u8 *q) {
    Buf_00640738 buf;
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
        *d++ = D_L39_004997E0[((k + i) & 7) * 0xFF + m];
    }
    a = buf.w[0] ^ (u32)q;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = (b >> 16) / (((b ^ (b >> 16)) << 16) + 1);
    return buf.b[4];
}

static __inline__ u32 GetB5_00640738(u8 *q) {
    Buf_00640738 buf;
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

static __inline__ u32 GetC_00640738(u8 *q) {
    Buf_00640738 buf;
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
        *d++ = D_L39_00483A00[((k + i) & 7) * 0xD1 + m];
    }
    a = buf.w[0] ^ (u32)q;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = (b >> 16) / (((b ^ (b >> 16)) << 16) + 1);
    return buf.h[2];
}

static __inline__ s32 EqA_00640738(u8 *q, u32 v) { return GetA_00640738(q) == v; }
static __inline__ s32 EqB3_00640738(u8 *q, u32 v) { return GetB3_00640738(q) == v; }
static __inline__ s32 EqB5_00640738(u8 *q, u32 v) { return GetB5_00640738(q) == v; }
static __inline__ s32 EqC_00640738(u8 *q, u32 v) { return GetC_00640738(q) == v; }

void func_L39_00640738(S_00640738 *s, s32 b) {
    s32 f, g;
    u32 t, v, x, y, z;
    s32 sel;
    u32 w1, w2, w3, w4, w5, w6;
    s32 c;
    E_00640738 *e;

    if (b == 0 && s->b1A0E != 0 && s->pl[0].w28 != 10) {
        s->b1A12 = 1;
    }
    if (s->b1A0C != 0 && b == 0 && (s->b1A12 == 0 || s->pl[0].w28 == 10)) {
        s->b1A12 = 0;
        return;
    }
    f = 0;
    if (func_L01_004606E8(0x80, 3, 0, (s32)s->p2534) == 0 && s->b1A12 == 0) {
        goto L9D0;
    }
    if (b != 0) {
        goto F30;
    }
    w1 = s->pl[0].w28;
    if (w1 == 10) {
        goto L9D0;
    }
    if (s->b1A13 != 0) {
        goto L9D0;
    }
    if (s->b1A12 != 0 && w1 != 0) {
        SetAV_00640738(&s->h25[b], w1);
    }
    { u32 st = 10; SetA_00640738(&s->h1F[b], st); }
    f = 1;
L9D0:
    if (b != 0) {
        goto F34;
    }
    if (s->b1A13 == 0) {
        goto LCDC;
    }
    if (s->pl[0].w28 == 0xB) {
        goto LCD0;
    }
    if (EqA_00640738(&s->h1F[0], 0xB)) {
        goto LCD0;
    }
    if (EqB5_00640738(&s->b19E6, 0x14)) {
        goto LCD0;
    }
    w2 = s->pl[0].w28;
    if (w2 != 0) {
        SetAV_00640738(&s->h25[0], w2);
    }
    { u32 st = 0xB; SetA_00640738(&s->h1F[0], st); }
    f = 1;
LCD0:
    if (s->b1A13 != 0) {
        goto F34;
    }
LCDC:
    t = s->p2534->w1A4;
    if (!(t & 0x20)) {
        if (!(t & 8)) {
            goto F34;
        }
        if (func_L39_00639D90(s) == 0) {
            goto F34;
        }
    }
    if (s->b1A0E != 0) {
        goto F34;
    }
    if (EqB5_00640738(&s->b19E4, 0x13) && s->w2F0 < 8) {
        goto F34;
    }
    if (EqB5_00640738(&s->b19E4, 0x14)) {
        goto F30;
    }
    w3 = s->w18D0[b];
    if (s->pl[0].w28 == w3) {
        goto F34;
    }
    if (w3 == 0) {
        goto F34;
    }
    SetAV_00640738(&s->h1F[b], w3);
    f = 1;
F30:
F34:
    if (b != 1) {
        goto L17B0;
    }
    if (s->b377 == 0) {
        goto L12C0;
    }
    c = GetC_00640738(&s->b1A40);
    if ((((u32)c >> 14) & 1) == 0) {
        goto L12B4;
    }
    if (s->w18D0[1] == 0xE && s->pl[b].w28 != 0) {
        goto L12B8;
    }
    { u32 st = 0xE; SetA_00640738(&s->h19[1], st); }
    w4 = s->pl[b].w28;
    if (w4 != 0) {
        SetAV_00640738(&s->h25[b], w4);
    } else {
        u32 st = 0x19;
        SetA_00640738(&s->h25[b], st);
    }
    goto L17B0;
L12B4:
L12B8:
    if (s->b377 != 0) {
        goto L162C;
    }
L12C0:
    c = GetC_00640738(&s->b1A40);
    if ((s16)c >= 0) {
        goto L162C;
    }
    if (s->w18D0[1] == 0xF && s->pl[b].w28 != 0) {
        goto L162C;
    }
    { u32 st = 0xF; SetA_00640738(&s->h19[1], st); }
    w5 = s->pl[b].w28;
    if (w5 != 0) {
        SetAV_00640738(&s->h25[b], w5);
    } else {
        u32 st = 0x19;
        SetA_00640738(&s->h25[b], st);
    }
    goto L17B0;
L162C:
    if (s->h2D8 != 0) {
        goto L17B0;
    }
    if (s->pl[1].w28 != 0xE) {
        goto L17B0;
    }
    if (GetA_00640738(&s->h25[1]) != 0) {
        { u32 st = 1; SetA_00640738(&s->h2B[1], st); }
    }
L17B0:
    if (GetA_00640738(&s->h2B[b]) == 0) {
        goto L20B8;
    }
    ClrA_00640738(&s->h2B[b]);
    if (GetA_00640738(&s->h25[b]) == 0) {
        goto L20B8;
    }
    w6 = s->pl[b].w28;
    if (GetA_00640738(&s->h25[b]) == w6) {
        goto L20B8;
    }
    if (EqA_00640738(&s->h25[b], 0x19)) {
        goto L1CEC;
    }
    if (EqA_00640738(&s->h25[b], 0xA)) {
        goto L1CEC;
    }
    y = GetA_00640738(&s->h25[b]);
    c = GetC_00640738(&s->b1A40);
    if (!((((s16)c) >> y) & 1)) {
        goto L20B8;
    }
L1CEC:
    v = GetA_00640738(&s->h25[b]);
    if (v == 0x19) {
        v = 0;
    }
    if (!EqA_00640738(&s->h25[b], 0xA)) {
        s->w18D0[b] = v;
    }
    SetAVN_00640738(&s->h1F[b], v);
    ClrA_00640738(&s->h25[b]);
    f = 1;
    if (b != 0) {
        goto L20B8;
    }
    z = GetA_00640738(&s->h1F[0]);
    e = FindE_00640738(s, z);
    e->h1C = 0x20;
    f = 1;
L20B8:
    if (b != 0) {
        goto L2630;
    }
    if (s->w251C == 0) {
        goto L2630;
    }
    if (f == 0) {
        if (GetA_00640738(&s->h19[0]) == 0) {
            goto L2630;
        }
        x = GetA_00640738(&s->h1F[b]);
        if (GetA_00640738(&s->h19[b]) == x) {
            goto L2630;
        }
    }
    if (EqA_00640738(&s->h1F[b], 0xB)) {
        goto L2630;
    }
    if (EqA_00640738(&s->h1F[b], 0xA)) {
        goto L2630;
    }
    f = 0;
    ClrA_00640738(&s->h1F[b]);
    ClrB3_00640738(&s->b1A31);
    ClrA_00640738(&s->h19[b]);
L2630:
    g = 0;
    if (GetA_00640738(&s->h19[b]) == 0) {
        goto L2E78;
    }
    x = GetA_00640738(&s->h1F[b]);
    if (GetA_00640738(&s->h19[b]) == x) {
        goto L2DB0;
    }
    if (b == 1) {
        y = GetA_00640738(&s->h25[1]);
    }
    if (EqA_00640738(&s->h19[b], 0x19)) {
        ClrA_00640738(&s->h1F[b]);
        s->w18D0[b] = 0;
        goto L2DA4;
    }
    if (b == 0 && s->w18D0[0] != 0) {
        y = GetA_00640738(&s->h19[0]);
    }
    SetAV_00640738(&s->h1F[b], GetA_00640738(&s->h19[b]));
    s->w18D0[b] = GetA_00640738(&s->h1F[b]);
    if (b != 0) {
        goto L2DA4;
    }
    z = GetA_00640738(&s->h1F[0]);
    e = FindE_00640738(s, z);
    e->h1C = 0x20;
L2DA4:
    f = 1;
    g = 1;
    goto L2E74;
L2DB0:
    ClrA_00640738(&s->h19[b]);
L2E74:
L2E78:
    if (s->pl[b].b1C == 2) {
        f = 0;
    }
    if (s->pl[b].b1C == 1) {
        if (s->pl[b].b19 == 0) {
            s->pl[b].b19 = s->pl[b].b1D;
        }
    }
    if (func_L01_0040E020(&s->pl[b].b19) == 0) {
        if (s->b1A13 == 0) {
            f = 0;
            goto L2F44;
        }
        if (s->b1A07 == 0) {
            f = 0;
            goto L2F44;
        }
        sel = -1;
        if (s->pl[0].w24 == 2) {
            sel = s->pl[0].w28;
        }
        if (sel != 6 && sel != 12) {
            f = 0;
            goto L2F44;
        }
        if (s->w748 != 0) {
            s->w754 = 1;
        }
        s->b24FF = 1;
        s->b1A07 = 0;
        s->b1A05 = 0;
        s->pl[b].b19 = 0;
    }
L2F44:
    if (b != 0) {
        goto L3474;
    }
    if (f == 0) {
        goto L30BC;
    }
    SetB3_00640738(&s->b1A31, GetA_00640738(&s->h1F[0]));
    f = 0;
L30BC:
    if (GetB3_00640738(&s->b1A31) == 0) {
        goto L3474;
    }
    z = GetB3_00640738(&s->b1A31);
    e = FindE_00640738(s, z);
    z = e->h04;
    if (func_L01_004944E8(z) == 0) {
        func_L01_003EE640(z);
        goto L3474;
    }
    SetAV_00640738(&s->h1F[b], GetB3_00640738(&s->b1A31));
    ClrB3_00640738(&s->b1A31);
    f = 1;
L3474:
    if (f == 0) {
        goto L38EC;
    }
    s->pl[b].w20 = 3;
    func_L39_00621D30(s);
    s->w10A0 = func_L39_005B43C8(0x2A, 0x4B);
    if (s->b1A07 != 0) {
        func_L39_00622288(s);
    }
    if (b == 0) {
        switch (GetA_00640738(&s->h1F[0])) {
        case 3:
            s->f12C0 = 200.0f;
            break;
        case 4:
            s->f12C0 = 120.0f;
            break;
        case 1:
            s->f12C0 = 35.0f;
            break;
        case 2:
            s->f12C0 = 30.0f;
            break;
        case 10:
        case 11:
            s->f12C0 = 0.0f;
            break;
        default:
            s->f12C0 = 20.0f;
            break;
        }
        s->h1280 &= 0xFFDF;
    }
    s->pl[b].b1A = 0;
    ClrA_00640738(&s->h19[b]);
    s->b1A12 = 0;
    z = GetA_00640738(&s->h1F[b]);
    if (b == 0) {
        e = FindE_00640738(s, z);
        if (e->b0B != GetB3b_00640738(&s->b1A17)) {
            if (s->p740 != 0) {
                s->p740->w34 = 1;
            }
            if (s->p744 != 0) {
                s->p744->w34 = 1;
            }
        }
    }
    if (s->pl[b].p00 != 0 && s->pl[b].p00->p24->b0C >= 3) {
        func_003C3A10(s->pl[b].p00, 2, 0, 2);
    }
    if (s->pl[b].p04 != 0 && b != 3 && s->pl[b].p04->p24->b0C >= 3) {
        func_003C3A10(s->pl[b].p04, 2, 0, 2);
    }
    s->pl[b].w24 = 3;
    return;
L38EC:
    if (g == 0) {
        return;
    }
    ClrA_00640738(&s->h1F[b]);
}
