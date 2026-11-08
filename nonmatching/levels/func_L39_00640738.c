/* func_L39_00640738: Opus handoff (prep by Sonnet worker w6, 2026-11-08)
   Size: 12968 bytes, places: 15 levels (39..53), file: src/levels/shared/L39_0063E9E8.c,
   flags: -O2 -G8 -fopt-stack -mno-check-zero-division (retail has 5 inline float constants: try @ps2as)
   Step 0: one function (prologue -0x60, one jr $ra), switch via jtbl_0047A9E0 (11 cases) near the end;
     3242 retail instructions but ~250 lines of real logic: ~45 inlined copies of two anti-tamper helpers (Set/Get).
   rac2 twin: none (opcode best 0.11 to func_L11_00420C88; callees have no rac2 twins, callfp.out mapped=0;
     no hit in rac4). Prior attempt: ~/RACSwarm/rac3-api/jobs/func_L39_00640738 (RESULTS.md has the full analysis).
   Anti-tamper scheme ("protected values"): level 39-53 code (multiplayer menu, 15 places) keeps game-state
     bytes as a 1-byte handle h in the struct; the value lives permuted/XOR-ed in the pool D_L39_004997E0
     (stride 0xFF; D_L39_00480760 stride 0xC1; D_L39_00483A00 stride 0xD1) keyed by D_L39_0024B9C8 * (u32)h % 0x1FE.
     The GET shape that MATCHES retail is the one proven in func_L39_0065D0A0 (landing/queue): see its
     Dec_/Dec2_ helpers: `if (*q==0) return 0; n=*q; k=((u32)q-n)&7; m=n+1; d=buf.b; for (i=0;i<40;i+=5)
     *d++ = pool[m + ((k+i)&7)*255]; a=buf.w[0]^(u32)q; b=buf.w[1]^a;` (32-bit var) and, for u16 vars, step 3,
     i<24, table 00483A00 stride 209 (`pool[((k+i)&7)*209+m]`), `buf.w[1]=(b>>16)/(((b^(b>>16))<<16)+1); return buf.h[2]`.
     Comparisons go through `static inline s32 DecEq(q,v){return Dec(q)==v;}` (xori/beql form). ps2as profile is
     needed for such files' inline float constants.
   Mapping: S_00640738 *s (a0), b = a1 = player index (0/1); handle bytes h19/h1F/h25/h2B indexed by b; per-player
     records Pl_00640738 pl[2] (0x50 each) at +0x450. b==0 / b==1 arms fold b into constants, hence 0x1A1A($s1) vs 0x1A19($s2).
   Draft: compiles (the prior job's func.c: goto-per-label translation, Set/Get as static inline helpers);
     3147 diff of 3243 rows at level 39 (needs the retail 'b in $s4, f in $s5, lui $s6 hoisted' register layout;
     mine has two extra long-lived pseudos: D_L39_0024B9C8 and &D_L39_0049C890). I re-tried with the matched
     Dec/Dec2-shaped Get helpers and with --as ps2as and a scalar `extern u32 D_L39_0024B9C8;`: 3224 / 3177 diff, no gain.
   Left for Opus: (1) replace the gotos by if/else once registers match; (2) the switch (jtbl_0047A9E0, case values 1..11,
     stores 200/120/35/30/0/20.0f into s->f12C0; the case->constant mapping is a guess: read the table bytes);
     (3) the first Get in the switch has a top-tested loop in retail; (4) per-use Get calls must not CSE.
*/
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
} Pl_00640738;

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

extern u32 D_L39_0024B9C8[];
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
    E_00640738 *e = &D_L39_0049C890[i];
    if (func_L39_00648AE0(s, i)) {
        e = &D_L39_0049C890[e->b21];
    }
    return e;
}

static __inline__ void SetA_00640738(u8 *h, u32 v) {
    Buf_00640738 buf;
    u32 k, o, id;
    s32 i;

    if (*h == 0) {
        *h = ++D_L39_00480760[0];
    } else {
        u8 t = *h;
        *h = D_L39_00480761[0];
        D_L39_00480761[0] = t;
    }
    k = ((u32 *)D_L39_00480760)[(D_L39_0024B9C8[0] * (u32)h) % 0x182];
    o = ((u32)h - *h) & 7;
    buf.w[1] = ((v & 0xFFFF) | (v << 16)) ^ k;
    buf.w[0] = (u32)h ^ k;
    id = *h + 1;
    for (i = 0; i < 8; i++) {
        D_L39_00480760[((o + i * 3) & 7) * 0xC1 + id] = buf.b[i];
    }
}

static __inline__ u32 GetA_00640738(u8 *h) {
    Buf_00640738 buf;
    u32 r = 0;
    u32 o, id;
    s32 i;

    if (*h != 0) {
        id = *h + 1;
        o = ((u32)h - *h) & 7;
        for (i = 0; i < 8; i++) {
            buf.b[i] = D_L39_00480760[((o + i * 3) & 7) * 0xC1 + id];
        }
        buf.w[0] ^= (u32)h;
        buf.w[1] ^= buf.w[0];
        buf.w[1] = (buf.w[1] >> 16) / (((buf.w[1] ^ (buf.w[1] >> 16)) << 16) + 1);
        r = buf.w[1];
    }
    return r;
}

static __inline__ void SetB3_00640738(u8 *h, u32 v) {
    Buf_00640738 buf;
    u32 k, o, id;
    s32 i;

    if (*h == 0) {
        *h = ++D_L39_004997E0[0];
    } else {
        u8 t = *h;
        *h = D_L39_004997E1[0];
        D_L39_004997E1[0] = t;
    }
    k = ((u32 *)D_L39_004997E0)[(D_L39_0024B9C8[0] * (u32)h) % 0x1FE];
    o = ((u32)h - *h) & 7;
    buf.w[1] = ((v & 0xFFFF) | (v << 16)) ^ k;
    buf.w[0] = (u32)h ^ k;
    id = *h + 1;
    for (i = 0; i < 8; i++) {
        D_L39_004997E0[((o + i * 3) & 7) * 0xFF + id] = buf.b[i];
    }
}

static __inline__ u32 GetB3_00640738(u8 *h) {
    Buf_00640738 buf;
    u32 r = 0;
    u32 o, id;
    s32 i;

    if (*h != 0) {
        id = *h + 1;
        o = ((u32)h - *h) & 7;
        for (i = 0; i < 8; i++) {
            buf.b[i] = D_L39_004997E0[((o + i * 3) & 7) * 0xFF + id];
        }
        buf.w[0] ^= (u32)h;
        buf.w[1] ^= buf.w[0];
        buf.w[1] = (buf.w[1] >> 16) / (((buf.w[1] ^ (buf.w[1] >> 16)) << 16) + 1);
        r = buf.w[1];
    }
    return r;
}

static __inline__ u32 GetB3b_00640738(u8 *h) {
    Buf_00640738 buf;
    u32 r = 0;
    u32 o, id;
    s32 i;

    if (*h != 0) {
        id = *h + 1;
        o = ((u32)h - *h) & 7;
        for (i = 0; i < 8; i++) {
            buf.b[i] = D_L39_004997E0[((o + i * 3) & 7) * 0xFF + id];
        }
        buf.w[0] ^= (u32)h;
        buf.w[1] ^= buf.w[0];
        buf.w[1] = (buf.w[1] >> 16) / (((buf.w[1] ^ (buf.w[1] >> 16)) << 16) + 1);
        r = buf.b[4];
    }
    return r;
}

static __inline__ u32 GetB5_00640738(u8 *h) {
    Buf_00640738 buf;
    u32 r = 0;
    u32 o, id;
    s32 i;

    if (*h != 0) {
        id = *h + 1;
        o = ((u32)h - *h) & 7;
        for (i = 0; i < 8; i++) {
            buf.b[i] = D_L39_004997E0[((o + i * 5) & 7) * 0xFF + id];
        }
        buf.w[0] ^= (u32)h;
        buf.w[1] ^= buf.w[0];
        buf.w[1] = (buf.w[1] >> 16) / (((buf.w[1] ^ (buf.w[1] >> 16)) << 16) + 1);
        r = buf.w[1];
    }
    return r;
}

static __inline__ u32 GetC_00640738(u8 *h) {
    Buf_00640738 buf;
    u32 r = 0;
    u32 o, id;
    s32 i;

    if (*h != 0) {
        id = *h + 1;
        o = ((u32)h - *h) & 7;
        for (i = 0; i < 8; i++) {
            buf.b[i] = D_L39_00483A00[((o + i * 3) & 7) * 0xD1 + id];
        }
        buf.w[0] ^= (u32)h;
        buf.w[1] ^= buf.w[0];
        buf.w[1] = (buf.w[1] >> 16) / (((buf.w[1] ^ (buf.w[1] >> 16)) << 16) + 1);
        r = buf.h[2];
    }
    return r;
}

void func_L39_00640738(S_00640738 *s, s32 b) {
    s32 f, g;
    u32 t, v, w, x, y, z;
    s32 sel;
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
    w = s->pl[0].w28;
    if (w == 10) {
        goto L9D0;
    }
    if (s->b1A13 != 0) {
        goto L9D0;
    }
    if (s->b1A12 != 0 && w != 0) {
        SetA_00640738(&s->h25[b], w);
    }
    SetA_00640738(&s->h1F[b], 10);
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
    if (GetA_00640738(&s->h1F[0]) == 0xB) {
        goto LCD0;
    }
    if (GetB5_00640738(&s->b19E6) == 0x14) {
        goto LCD0;
    }
    w = s->pl[0].w28;
    if (w != 0) {
        SetA_00640738(&s->h25[0], w);
    }
    SetA_00640738(&s->h1F[0], 0xB);
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
    x = GetB5_00640738(&s->b19E4);
    if (x == 0x13 && s->w2F0 < 8) {
        goto F34;
    }
    if (GetB5_00640738(&s->b19E4) == 0x14) {
        goto F30;
    }
    w = s->w18D0[b];
    if (s->pl[0].w28 == w) {
        goto F34;
    }
    if (w == 0) {
        goto F34;
    }
    SetA_00640738(&s->h1F[b], w);
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
    if (((c >> 14) & 1) == 0) {
        goto L12B4;
    }
    if (s->w18D0[1] == 0xE && s->pl[b].w28 != 0) {
        goto L12B8;
    }
    SetA_00640738(&s->h19[1], 0xE);
    w = s->pl[b].w28;
    if (w == 0) {
        SetA_00640738(&s->h25[b], 0x19);
    } else {
        SetA_00640738(&s->h25[b], w);
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
    SetA_00640738(&s->h19[1], 0xF);
    w = s->pl[b].w28;
    if (w == 0) {
        SetA_00640738(&s->h25[b], 0x19);
    } else {
        SetA_00640738(&s->h25[b], w);
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
        SetA_00640738(&s->h2B[1], 1);
    }
L17B0:
    if (GetA_00640738(&s->h2B[b]) == 0) {
        goto L20B8;
    }
    SetA_00640738(&s->h2B[b], 0);
    if (GetA_00640738(&s->h25[b]) == 0) {
        goto L20B8;
    }
    w = s->pl[b].w28;
    if (GetA_00640738(&s->h25[b]) == w) {
        goto L20B8;
    }
    if (GetA_00640738(&s->h25[b]) == 0x19) {
        goto L1CEC;
    }
    if (GetA_00640738(&s->h25[b]) == 0xA) {
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
    if (GetA_00640738(&s->h25[b]) != 0xA) {
        s->w18D0[b] = v;
    }
    SetA_00640738(&s->h1F[b], v);
    SetA_00640738(&s->h25[b], 0);
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
    if (GetA_00640738(&s->h1F[b]) == 0xB) {
        goto L2630;
    }
    if (GetA_00640738(&s->h1F[b]) == 0xA) {
        goto L2630;
    }
    f = 0;
    SetA_00640738(&s->h1F[b], 0);
    SetB3_00640738(&s->b1A31, 0);
    SetA_00640738(&s->h19[b], 0);
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
        GetA_00640738(&s->h25[1]);
    }
    if (GetA_00640738(&s->h19[b]) == 0x19) {
        SetA_00640738(&s->h1F[b], 0);
        s->w18D0[b] = 0;
        goto L2DA4;
    }
    if (b == 0 && s->w18D0[0] != 0) {
        GetA_00640738(&s->h19[0]);
    }
    x = GetA_00640738(&s->h19[b]);
    SetA_00640738(&s->h1F[b], x);
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
    SetA_00640738(&s->h19[b], 0);
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
    x = GetA_00640738(&s->h1F[0]);
    SetB3_00640738(&s->b1A31, x);
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
    x = GetB3_00640738(&s->b1A31);
    SetA_00640738(&s->h1F[b], x);
    SetB3_00640738(&s->b1A31, 0);
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
        case 1:
            s->f12C0 = 200.0f;
            break;
        case 2:
            s->f12C0 = 120.0f;
            break;
        case 3:
            s->f12C0 = 35.0f;
            break;
        case 4:
            s->f12C0 = 30.0f;
            break;
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
    SetA_00640738(&s->h19[b], 0);
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
    SetA_00640738(&s->h1F[b], 0);
}
