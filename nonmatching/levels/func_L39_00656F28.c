/* func_L39_00656F28: near miss (Opus, 2026-11-08). Multiplayer player state machine, 24,952 bytes, 15 places
   (levels 39-53), file src/levels/shared/L39_00656DB0.c. Needs `-mvu0-use-vf0-vf2 ... @ps2as` on the file's line
   (3 vadd.xyz through include/vu0.h; inline float constants).
   Measured with the stock checker: 6203 of 6238 rows (sizes within 35 instructions), 35.2% rows exact,
   89.4% opcodes equal. Every case body (31 distinct targets of jtbl_0047B090) is written from retail; the
   obfuscated-variable helpers (Dec/DecEq/DecF/Dec16/DecB/Dec3, Set/Set16/Set3) follow func_L39_0065D0A0's
   matched shapes; the `switch (Dec(s+0x19E4))` dispatch already compiles to retail's exact sequence.
   What still differs, in order of effect:
   1. Stack layout. Retail's temps are all at sp+0..0x2F (every decoder buffer at 0, the 0x7D probe's three
      vectors at 0/0x10/0x20, case 0x19's vector at 0 with its decoder at 0x10), then &n30/&n34 at 0x30/0x34
      and the a/b spills at 0x38/0x3C (frame 0xA0). In this C the probe lands at 0x10..0x3F (frame 0xC0):
      cc1 keeps an inline's frame temp alive to the end of the enclosing block when the inline is in an
      expression statement or if condition at that level, and a 48-byte request cannot reuse the freed 16-byte
      slot at 0. Retail behaves as if every full statement freed its temporaries (C++ cc1plus does that with
      expand_start/end_target_temps), which plain C here does not reproduce; tested in scratch t1-ta.
   2. Consequence: retail keeps &p1/&c of the probe in $s1/$s0 (p0 is $sp itself), so global allocation gives
      the object pointer $s2 and s+0x19E4 $s1; here the object is $s1 and s+0x19E4 $s2/$s3 (about 1,000 rows
      differ only by that). Retail also never keeps s+0x19E6 across the function (recomputed at the tail); here
      it lives in $s7. And one extra callee-saved float ($f22).
   3. Local: the t = 6 / DecEq(0x11) movz pair in case 0x7, the dead decode before DecEq(0xE), the
      (u64 at 0x14A8 & 0xFF0000FF<<32) test (written as unsigned long; u64 is 128-bit-hostile here).
   Next step: settle (1) first (anything that puts the probe at sp+0), then compare per case with
   ~/RACSwarm/plans/rac3-large/kit/casediff2.py --jt 39_multiplayer_menu:jtbl_0047B090 --cases. */
typedef int u128_t __attribute__((mode(TI)));

typedef union Buf_00656F28 {
    u8 b[8];
    u32 w[2];
    u16 h[4];
    f32 f[2];
} Buf_00656F28;

typedef struct VT_00656F28 {
    u8 pad0[0x34];
    s32 (*f34)(void *, s32, s32, s32, s32);
    u8 pad38[0x44 - 0x38];
    s32 (*f44)(void *, s32);
} VT_00656F28;

extern u8 D_L39_004997E0[];
extern u8 D_L39_004997E1[];
extern u8 D_L39_00483A00[];
extern u8 D_L39_00480760[];
extern u8 D_L39_00480761[];
extern u32 D_L39_0024B9C8;
extern f32 D_L39_0024BC30[];
extern u8 D_L39_004840A0[];
extern u8 D_L39_0049C890[];
extern u8 D_1A5810[];
extern s32 D_L39_002429C0;

extern void func_00393348(s32, s32, void *, void *, void *, s32, s32);
extern void func_L39_00675830(void);
extern void func_L39_00675908(void);
extern void func_L39_006761D0(void);
extern s32 func_L39_00626D38(void *, s32);
extern void func_L32_004F8B00(void *);
extern s32 func_L39_0065D0A0(void *);
extern s32 func_L39_0065F1A8(void *);
extern void func_L39_0063D0F8(void *);
extern void func_L39_0063D2A8(void *);
extern void func_L39_0063A0F0(void *);
extern s32 func_L39_005C42E8(s32, s32);
extern void func_L39_0062B718(void *);
extern s16 func_L39_0063D0F0(void *, s32);
extern s16 func_L39_006223B0(void *, s32);
extern void func_L39_0062B4A8(void *, s32, s32, s32, f32);
extern void func_L39_00622288(void *);
extern s32 func_L39_00648AE0(void *, s32);
extern void func_L39_00632D78(void *, s32, f32);
extern s32 func_L39_0062D7C8(void *, s32, s32);
extern s32 func_L01_004606E8(s32, s32, void *, void *);
extern s32 func_L39_005C2F50(void *);
extern s32 func_L39_0063BE00(void *, f32);
extern void func_L39_0063A4E0(void *, s32, s32, s32, s32);
extern s32 func_0038CB00(void *);
extern void func_L39_00628038(void *, s32);

static inline u32 Dec_00656F28(u8 *q) {
    Buf_00656F28 buf;
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

static inline s32 DecEq_00656F28(u8 *q, s32 v) {
    return Dec_00656F28(q) == v;
}

static inline f32 DecF_00656F28(u8 *q) {
    Buf_00656F28 buf;
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

/* s16 value: step 3 over the 255-stride table, the high half divides the low one */
static inline s16 Dec16_00656F28(u8 *q) {
    Buf_00656F28 buf;
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
        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
    }
    a = buf.w[0] ^ (u32)q;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = (b >> 16) / (((b ^ (b >> 16)) << 16) + 1);
    return buf.h[2];
}

static inline void Prep_00656F28(u8 *q) {
    u8 t;
    if (*q == 0) {
        t = D_L39_004997E0[0] + 1;
        D_L39_004997E0[0] = t;
        *q = t;
    } else {
        t = *q;
        *q = D_L39_004997E1[0];
        D_L39_004997E1[0] = t;
    }
}

static inline void Set16_00656F28(u8 *q, s16 v) {
    Buf_00656F28 buf;
    u32 key;
    s32 n;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    Prep_00656F28(q);
    buf.h[2] = v;
    key = ((u32 *)D_L39_004997E0)[(D_L39_0024B9C8 * (u32)q) % 510];
    buf.w[1] = ((buf.w[1] & 0xFFFF) | (buf.w[1] << 16)) ^ key;
    buf.w[0] = (u32)q ^ key;
    n = *q;
    k = ((u32)q - n) & 7;
    m = n + 1;
    d = buf.b;
    for (i = 0; i < 24; i += 3) {
        D_L39_004997E0[m + ((k + i) & 7) * 255] = *d++;
    }
}

static inline u8 Dead_00656F28(u8 *s) {
    return DecF_00656F28(s + 0x2476) <= 0.0f;
}

static inline s32 Busy_00656F28(u8 *s) {
    return DecEq_00656F28(s + 0x19E4, 1) || DecEq_00656F28(s + 0x19E4, 0x1D) ||
           s[0x24FE] != 0 || s[0x2500] != 0;
}

static inline void SetState_00656F28(u8 *s, s32 st) {
    (*(VT_00656F28 **)(s + 0x14))->f34(s, st, 1, 0, 1);
}

#include "vu0.h"

typedef struct V4_00656F28 {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} __attribute__((aligned(16))) V4_00656F28;

__asm__(".extern D_001D5F30_sda, 4");
__asm__(".extern D_001D5BCC_sda, 4");
__asm__(".extern D_001D6D98_sda, 1");
__asm__(".extern D_001E0434_sda, 4");
__asm__(".extern D_001DAA80_sda, 8");
__asm__(".extern D_001DAA90_sda, 8");
extern u8 *D_001D5F30_sda;
extern s32 D_001D5BCC_sda;
extern s8 D_001D6D98_sda;
extern s32 D_001E0434_sda;
extern u8 D_001DAA80_sda[8];
extern u8 D_001DAA90_sda[8];
extern u8 D_L39_0047A8A8[];
extern s32 D_L39_00246018[];
extern f32 D_L39_00246004[];
extern f32 D_L39_00246010[];

extern s32 func_L39_00648840(void *, s32);
extern void func_L39_00648960(void *, s32);
extern void func_L39_006475C0(void *);
extern void func_L39_00628428(void *);
extern f32 func_L39_0063C000(void *, f32, f32, f32);
extern void func_L39_0062B740(void *, f32, f32, f32, f32);
extern s32 func_L39_00638C28(void *);
extern void func_L39_0062B728(void *, s32);
extern s32 func_L39_00638F50(void *);
extern s32 func_L39_006212E8(void *);
extern s32 func_L39_00638DF0(void *);
extern void func_003C4BB0(void *, f32);
extern void func_L39_0062DA30(void *);
extern f32 func_0038CEA8(void *);
extern s32 func_L39_00634E58(void *, s32, f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00412FE0(void *, void *, f32, f32);
extern void func_003C2F58(void *, s32, void *);
extern void func_L39_005CF720(void *, void *, void *, void *, s32);
extern void func_L39_0063A030(void *, s32, s32);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_L39_006233A8(void *, void *, void *, s32);
extern void func_L39_0063B5E0(void *, s32);
extern void func_0019D500(s32);
extern f32 func_L39_005B44C8(void);
extern void func_0038D890(void *, void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L39_0063A2E8(void *);
extern void func_L32_004FD190(void *, s32, s32, s32, s32, f32, f32);
extern void func_L39_00632558(void *, void *, void *, f32);
extern s32 func_L01_004FF5D8(void *);
extern void func_L39_00632458(void *, void *, void *, s32 *, f32);
extern void func_L39_00647FE0(void *, s32, s32, s32);
extern void func_003C4138(void *, f32, f32);
extern s32 func_L39_00629DE0(void *);
extern void func_L39_00638848(void *);
extern f32 func_L39_00632678(void *, void *);
extern void func_L39_00656DB0(void *);
extern s32 func_L39_00632C48(void *, f32);
extern void func_L39_0063BA40(void *);

static inline void Set_00656F28(u8 *q, u32 v) {
    Buf_00656F28 buf;
    u32 key;
    s32 n;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    Prep_00656F28(q);
    key = ((u32 *)D_L39_004997E0)[(D_L39_0024B9C8 * (u32)q) % 510];
    buf.w[1] = v ^ key;
    buf.w[0] = (u32)q ^ key;
    n = *q;
    k = ((u32)q - n) & 7;
    m = n + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        D_L39_004997E0[m + ((k + i) & 7) * 255] = *d++;
    }
}

/* 16-bit flag in the 193-stride table, tested as a word */
static inline s32 Dec3_00656F28(u8 *q) {
    Buf_00656F28 buf;
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
        *d++ = D_L39_00480760[((k + i) & 7) * 193 + m];
    }
    a = buf.w[0] ^ (u32)q;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = (b >> 16) / (((b ^ (b >> 16)) << 16) + 1);
    return buf.w[1];
}

static inline void Prep3_00656F28(u8 *q) {
    u8 t;
    if (*q == 0) {
        t = D_L39_00480760[0] + 1;
        D_L39_00480760[0] = t;
        *q = t;
    } else {
        t = *q;
        *q = D_L39_00480761[0];
        D_L39_00480761[0] = t;
    }
}

static inline void Set3_00656F28(u8 *q, u32 v) {
    Buf_00656F28 buf;
    u32 key;
    s32 n;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    Prep3_00656F28(q);
    key = ((u32 *)D_L39_00480760)[(D_L39_0024B9C8 * (u32)q) % 386];
    buf.w[1] = ((v << 16) | v) ^ key;
    buf.w[0] = (u32)q ^ key;
    n = *q;
    k = ((u32)q - n) & 7;
    m = n + 1;
    d = buf.b;
    for (i = 0; i < 24; i += 3) {
        D_L39_00480760[((k + i) & 7) * 193 + m] = *d++;
    }
}

/* 16-bit flag in the 255-stride table, tested as a word */
static inline s32 DecB_00656F28(u8 *q) {
    Buf_00656F28 buf;
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
        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
    }
    a = buf.w[0] ^ (u32)q;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = (b >> 16) / (((b ^ (b >> 16)) << 16) + 1);
    return buf.w[1];
}


static inline void Push_00656F28(u8 *s) {
    V4_00656F28 p;

    func_0038CF68(&p, s + 0x40, *(f32 *)(s + 0x132C));
    vec_add_ab(&p, &p, s + 0xA0);
    func_L01_00412FE0(s + 0x11A0, &p, *(f32 *)(s + 0xB8), 0.0f);
}

static inline void Probe_00656F28(u8 *s) {
    V4_00656F28 p0;
    V4_00656F28 p1;
    V4_00656F28 c;

    *(u128_t *)&c = 0;
    c.x = -0.10000001f;
    func_003C2F58(*(void **)(s + 0x2524), 0x16, &p0);
    func_003C2F58(*(void **)(s + 0x2524), 0x17, &p1);
    func_L39_005CF720(*(void **)(s + 0x2524), &p0, &c, &D_001DAA80_sda, 1);
    func_L39_005CF720(*(void **)(s + 0x2524), &p0, &c, &D_001DAA90_sda, 1);
    func_L39_005CF720(*(void **)(s + 0x2524), &p1, &c, &D_001DAA80_sda, 1);
    func_L39_005CF720(*(void **)(s + 0x2524), &p1, &c, &D_001DAA90_sda, 1);
}

static inline s32 Step_00656F28(u8 *s, f32 a) {
    V4_00656F28 v;

    *(u128_t *)&v = *(u128_t *)(s + 0xA0);
    v.x += func_0038D098(func_0038DAB8(*(f32 *)(s + 0xB8), a)) * 0.3f;
    v.y += func_0038D0B0(func_0038DAB8(*(f32 *)(s + 0xB8), a)) * 0.3f;
    return func_L39_006233A8(s, &v, s + 0xB0, 0);
}

static inline void Spot_00656F28(u8 *s) {
    V4_00656F28 v0;
    V4_00656F28 v1;
    s32 i;
    f32 x;

    for (i = 0; i < 10; i++) {
        func_0019D500(s[0x44ED]);
        if (i < 4) {
            x = (f32)i * 1.5707964f;
        } else {
            x = func_L39_005B44C8();
        }
        func_0038D890(&v0, s + 0x20, s + 0x40, x);
        func_0038CF68(&v0, &v0, 0.3f);
        func_0038CF68(&v1, &v0, 0.75f);
        vec_add_ab(&v1, &v1, s + 0xE0);
        if (func_003D3CB0(s + 0xE0, &v1, 2, 0, 0) == 0) {
            func_0038CE20(&v0, &v0, -1.0f);
            *(u128_t *)(s + 0x15A0) = *(u128_t *)&v0;
            break;
        }
    }
}

static inline void St19_00656F28(u8 *s) {
    V4_00656F28 v;
    f32 x;

    x = 1.5707964f;
    *(u128_t *)&v = *(u128_t *)(s + 0xA0);
    if (DecEq_00656F28(s + 0x19E4, 0x1A)) {
        x = -1.5707964f;
    }
    v.x += func_0038D098(func_0038DAB8(*(f32 *)(s + 0xB8), x)) * 0.3f;
    v.y += func_0038D0B0(func_0038DAB8(*(f32 *)(s + 0xB8), x)) * 0.3f;
    func_L39_00632D78(s, 0, 1.0f);
    if ((*(f32 *)(s + 0x2468) < 0.5f ||
         func_0038DBA0(*(f32 *)(s + 0xFD0), func_0038DAB8(*(f32 *)(s + 0xB8), x)) > 0.7853982f ||
         func_L39_006233A8(s, &v, s + 0xB0, 0) == 0) &&
        (*(s32 *)(s + 0x618) & 2)) {
        SetState_00656F28(s, 0x18);
        return;
    }
    if (*(f32 *)(s + 0x2468) > 0.5f &&
        func_L01_004606E8(func_L39_005C42E8(0x40, *(s32 *)(s + 0x2544)), 7, 0,
                          *(void **)(s + 0x2534)) != 0 &&
        func_0038DBA0(*(f32 *)(s + 0xFD0), *(f32 *)(s + 0xB8)) > 2.3561945f) {
        SetState_00656F28(s, 6);
        s[0x1A0B] = 1;
        *(s16 *)(s + 0x308) = 0x21;
        return;
    }
    if (func_L01_004606E8(func_L39_005C42E8(0x40, *(s32 *)(s + 0x2544)), 7, 0,
                          *(void **)(s + 0x2534)) != 0) {
        SetState_00656F28(s, 0x1B);
    }
}

static inline void St7D_00656F28(u8 *s) {
    V4_00656F28 p0;
    V4_00656F28 p1;
    V4_00656F28 c;
    f32 x;

    if (s[0x216] != 0) {
        x = func_0038CEA8(s + 0x140);
        if (x < func_0038CEA8(s + 0x120) * 0.75f || func_L39_00634E58(s, 0, 1.0f, 1.25f) != 0) {
            if (D_1A5810[*(s32 *)(s + 0x2544) + 0xA4] == 1) {
                func_0038CF68(&p0, s + 0x40, *(f32 *)(s + 0x132C));
                vec_add_ab(&p0, &p0, s + 0xA0);
                func_L01_00412FE0(s + 0x11A0, &p0, *(f32 *)(s + 0xB8), 0.0f);
            }
            SetState_00656F28(s, 0x79);
            return;
        }
    }
    *(u128_t *)&c = 0;
    c.x = -0.10000001f;
    func_003C2F58(*(void **)(s + 0x2524), 0x16, &p0);
    func_003C2F58(*(void **)(s + 0x2524), 0x17, &p1);
    func_L39_005CF720(*(void **)(s + 0x2524), &p0, &c, &D_001DAA80_sda, 1);
    func_L39_005CF720(*(void **)(s + 0x2524), &p0, &c, &D_001DAA90_sda, 1);
    func_L39_005CF720(*(void **)(s + 0x2524), &p1, &c, &D_001DAA80_sda, 1);
    func_L39_005CF720(*(void **)(s + 0x2524), &p1, &c, &D_001DAA90_sda, 1);
}

void func_L39_00656F28(u8 *s) {
    u32 a;
    u32 b;
    u8 *s23;
    u8 fp;
    u8 *o;
    u8 f;
    s32 v;
    s32 t;
    s16 h;
    u8 *r;
    u8 *g;
    s32 k;
    f32 x;
    s32 w;
    s32 i;
    s32 n30;
    s32 n34;

    s23 = *(u8 **)(s + 0x2524);
    a = Dec_00656F28(s + 0x19E6);
    b = Dec_00656F28(s + 0x19E5);
    fp = s23[0x43];
    if (func_L39_00626D38(s, 1) == 0) {
        func_L32_004F8B00(s);
        if (Dead_00656F28(s)) {
            if (Dec_00656F28(s + 0x19E4) == 0 || DecEq_00656F28(s + 0x19E4, 2) ||
                DecEq_00656F28(s + 0x19E4, 0x7D)) {
                SetState_00656F28(s, 0x39);
                goto tail;
            }
        }
        if (func_L39_0065D0A0(s) != 0) {
            goto tail;
        }
        if (func_L39_0065F1A8(s) != 0) {
            goto tail;
        }
        o = *(u8 **)(s + 0x2534);
        if ((*(s32 *)(o + 0x1A4) & 0x10) || (*(s32 *)(o + 0x1C4) & 0x10)) {
            if (s[0x46C] != 2 && *(s32 *)(D_L39_004840A0 + *(s32 *)(s + 0x2544) * 0x1C) == 0 &&
                D_001E0434_sda >= 8) {
                f = Busy_00656F28(s);
                if (f == 0) {
                    if (!DecEq_00656F28(s + 0x19E6, 0x14) && s[0x1A13] == 0 &&
                        !(s[0x1A0C] != 0 && *(s16 *)(s + 0x30A) == 0) &&
                        !(s[0x1A0E] != 0 && *(s16 *)(s + 0x30A) == 0)) {
                        *(s16 *)(s + 0x24A4) = *(s16 *)(s + 0x24A8) ? 0x16 : 0xC;
                        func_00393348((s[0x24C9] + 8) | 0x20, 0, func_L39_00675830,
                                      func_L39_00675908, func_L39_006761D0, 0, 0);
                        *(s32 *)(s + 0x2514) = 300;
                    }
                }
            }
        }
        func_L39_0063D0F8(s);
        func_L39_0063D2A8(s);
        if (*(f32 *)(s + 0xA8) < D_L39_0024BC30[0] && *(f32 *)(s + 0x2AC) > 2.0f && s[0x1A15] == 0) {
            if (!DecEq_00656F28(s + 0x19E4, 0x76) && !DecEq_00656F28(s + 0x19E4, 0x90)) {
                SetState_00656F28(s, 0x76);
                goto tail;
            }
        }
        switch (Dec_00656F28(s + 0x19E4)) {
        case 0x0:
            o = *(u8 **)(s + 0x2534);
            if ((*(s32 *)(o + 0x1A0) & func_L39_005C42E8(4, *(s32 *)(s + 0x2544))) &&
                *(s32 *)(s + 0x2F0) > 0 &&
                (D_1A5810[*(s32 *)(s + 0x2544) + 0xA4] != 2 || *(s32 *)(s + 0x478) == 3)) {
                if (!DecEq_00656F28(s + 0x19E6, 0x14) &&
                    (*(VT_00656F28 **)(s + 0x14))->f44(s, 2) == 0) {
                    SetState_00656F28(s, 1);
                    break;
                }
            }
            func_L39_0062B718(s);
            s[0x3E6] = 0;
            if (func_L39_0063D0F0(s, s23[0x43]) != func_L39_006223B0(s, 0)) {
                if (*(s32 *)(s + 0x618) & 2) {
                    f = 0;
                    if (s[0x1A07] != 0 && s[0x1A05] != 0 &&
                        ((*(u8 **)(s + 0x2524))[0x43] == *(s32 *)(s + 0x2448) ||
                         *(s32 *)(s + 0x748) != 0)) {
                        f = 1;
                    }
                    if (f == 0) {
                        s[0x1A07] = 0;
                        func_L39_0062B4A8(s, func_L39_006223B0(s, 0), 0, 0, -2.0f);
                    }
                }
            }
            if (s[0x1A07] != 0 && *(s32 *)(s + 0x61C) == 0 && s[0x1A05] != 0 && s[0x1A08] == 0) {
                t = -1;
                if (*(s32 *)(s + 0x474) == 2) {
                    t = *(s32 *)(s + 0x478);
                }
                if (t != *(s32 *)(s + 0x244C)) {
                    func_L39_00622288(s);
                } else {
                    if (func_L39_00648AE0(s, t) != 0) {
                        r = D_L39_0049C890 + (*(s8 *)(D_L39_0049C890 + (t << 7) + 0x21) << 7);
                    } else {
                        r = D_L39_0049C890 + (t << 7);
                    }
                    h = *(s16 *)(r + 0xC);
                    if ((*(u8 **)(s + 0x2524))[0x43] != h) {
                        if (*(s32 *)(s + 0x748) != 0) {
                            *(s32 *)(s + 0x754) = 1;
                        }
                        *(s32 *)(s + 0x2448) = h;
                        func_L39_0062B4A8(s, h, 0, 0, -4.0f);
                    }
                }
            }
            func_L39_00632D78(s, 0, 1.0f);
            if (s[0x378] != 0 && *(s16 *)(s + 0x2DC) == 0) {
                SetState_00656F28(s, 0x78);
            } else if (*(s16 *)(s + 0x2DE) >= 4 && *(f32 *)(s + 0x2AC) > 0.4f) {
                if (!DecEq_00656F28(s + 0x19E7, 8) || *(s32 *)(s + 0x2F0) >= 0xC) {
                    SetState_00656F28(s, 6);
                }
            } else if (*(s16 *)(s + 0x320) == 0) {
                v = 1;
                if (DecEq_00656F28(s + 0x19E7, 1) || DecEq_00656F28(s + 0x19E7, 0x1D)) {
                    v = *(s32 *)(s + 0x2F0) > 3;
                }
                if (v != 0 && *(s16 *)(s + 0x2D8) != 1) {
                    if (func_L39_0062D7C8(s, *(s16 *)(s + 0x32C) ? 1 : 6, 0) != 0) {
                        break;
                    }
                }
                if (*(s16 *)(s + 0x2D8) == 1 && D_L39_002429C0 == 0 &&
                    func_L01_004606E8(func_L39_005C42E8(0x40, *(s32 *)(s + 0x2544)), 6, 0,
                                      *(void **)(s + 0x2534)) != 0) {
                    SetState_00656F28(s, 0x70);
                    break;
                }
                o = *(u8 **)(s + 0x2534);
                if ((*(s32 *)(o + 0x1A0) & func_L39_005C42E8(8, *(s32 *)(s + 0x2544))) &&
                    !(func_L39_005C2F50(o) & 0x10) && *(s32 *)(s + 0x2D0) != 0 &&
                    ((*(u8 **)(s + 0x2524))[0x43] != 0x1A || !(*(f32 *)(s + 0x628) < 108.0f))) {
                    SetState_00656F28(s, 4);
                    break;
                }
                if (DecEq_00656F28(s + 0x19E7, 1) || DecEq_00656F28(s + 0x19E7, 0x1D)) {
                    if (*(s32 *)(s + 0x2F0) < 0x14 && *(s16 *)(s + 0x2D8) != 1) {
                        func_L39_00632D78(s, 0, 1.0f);
                    }
                }
                if (func_L39_0063BE00(s, 0.17453292f) != 0 || *(f32 *)(s + 0x2468) > 0.22f) {
                    f = s[0x37B];
                    func_L39_0063A4E0(s, f, 0, 0, 0x1E);
                    func_L39_0063A4E0(s, f, 1, 0, 0x1E);
                    SetState_00656F28(s, 2);
                }
            }
            break;
        case 0x39:
        case 0x69:
        case 0x7F:
        case 0x81:
            if ((*(s32 *)(s + 0x618) & 2) || s[0x1A0F] != 0) {
                if (*(s16 *)(s + 0x344) != 0) {
                    *(f32 *)(s + 0x610) = 0.0f;
                    s[0x1A0F] = 1;
                    func_0038CB00(s + 0x344);
                } else {
                    func_L39_00628038(s, 0);
                }
            }
            break;
        case 0x7E:
            if (*(s32 *)(s + 0x2F0) >= 0xB8) {
                func_L39_00628038(s, 1);
            }
            break;
        case 0x90:
            g = D_001D5F30_sda;
            if (s[0x1A14] != 0) {
                if (g != 0 && *(s8 *)(g + 0x18F) != 0 && D_001D5BCC_sda % 10 < 6) {
                    if (func_L39_00648840(s, 0x24) == 0) {
                        func_L39_00648960(s, 0x24);
                    }
                }
                if (Dec16_00656F28(s + 0x31C) == 0) {
                    if (*(s32 *)(*(u8 **)(s + 0x2534) + 0x1A4) & 0x40) {
                        func_L39_006475C0(s);
                        func_L39_00628428(s);
                    }
                } else if (Dec16_00656F28(s + 0x31C) > 0) {
                    Set16_00656F28(s + 0x31C, Dec16_00656F28(s + 0x31C) - 1);
                } else {
                    Set16_00656F28(s + 0x31C, 0);
                }
            }
            break;
        case 0x14:
            if (DecEq_00656F28(s + 0x19E4, 0x14)) {
                t = func_L39_0063C000(s, 60.0f, 0.052f, -1.0f);
                if (*(s16 *)(s + 0x2DE) != 0 && t >= 0x10) {
                    *(f32 *)(s + 0x610) = 0.01f;
                } else {
                    k = 0x1A;
                    if (*(f32 *)(s + 0x1080) == 0.0f) {
                        *(f32 *)(s + 0x610) = 0.33f;
                    } else if (*(f32 *)(s + 0x1080) != 0.0f && *(s16 *)(s + 0x2DE) != 0 && t != 0 &&
                               (f32)k - *(f32 *)(s + 0x628) > 1.0f) {
                        func_L39_0062B740(s, (f32)k, (f32)t, 0.5f, -1.0f);
                        if (*(f32 *)(s + 0x2AC) < 0.7f && *(f32 *)(s + 0x610) < 0.75f) {
                            *(f32 *)(s + 0x610) = 0.75f;
                        }
                    } else if (*(s16 *)(s + 0x2DE) == 0 && *(f32 *)(s + 0x628) < (f32)k) {
                        *(f32 *)(s + 0x610) = 2.0f;
                    } else {
                        *(f32 *)(s + 0x610) = 1.0f;
                    }
                }
            }
            r = D_L39_0047A8A8 + *(s16 *)(s + 0x107C) * 0x2C;
            t = ((s32)*(f32 *)(s + 0x628) - *(s32 *)(r + 0xC)) * 2;
            if ((f32)*(s32 *)(r + 0x14) < *(f32 *)(s + 0x628)) {
                if (*(s32 *)(s + 0x61C) != 0) {
                    break;
                }
                if (func_L01_004606E8(func_L39_005C42E8(0x40, *(s32 *)(s + 0x2544)), t, 0,
                                      *(void **)(s + 0x2534)) != 0) {
                    if (!(*(s32 *)(*(u8 **)(s + 0x2534) + 0x1A0) &
                          func_L39_005C42E8(8, *(s32 *)(s + 0x2544)))) {
                        SetState_00656F28(s, 7);
                        break;
                    }
                    if (func_L39_00638C28(s) != 0) {
                        break;
                    }
                }
            }
            if (*(s32 *)(s + 0x61C) == 0 && (f32)*(s32 *)(r + 0x18) < *(f32 *)(s + 0x628)) {
                (*(VT_00656F28 **)(s + 0x14))->f34(s, 0, 0, 0, 1);
            }
            break;
        case 0x13:
        case 0x15:
            r = D_L39_0047A8A8 + *(s16 *)(s + 0x107C) * 0x2C;
            t = DecEq_00656F28(s + 0x19E4, 0x15) ? 7
                                                 : ((s32)*(f32 *)(s + 0x628) - *(s32 *)(r + 0xC)) * 2;
            if (s[0x24FE] == 0 && (f32)*(s32 *)(r + 0x14) < *(f32 *)(s + 0x628) &&
                *(s32 *)(s + 0x61C) == 0) {
                if ((!DecEq_00656F28(s + 0x19E4, 0x15) || *(s16 *)(s + 0x2D8) != 1) &&
                    func_L01_004606E8(func_L39_005C42E8(0x40, *(s32 *)(s + 0x2544)), t, 0,
                                      *(void **)(s + 0x2534)) != 0) {
                    if (!(*(s32 *)(*(u8 **)(s + 0x2534) + 0x1A0) &
                          func_L39_005C42E8(8, *(s32 *)(s + 0x2544)))) {
                        SetState_00656F28(s, 7);
                        break;
                    }
                    if (func_L39_00638C28(s) != 0) {
                        break;
                    }
                }
            }
            if (*(s32 *)(s + 0x61C) == 0) {
                if (*(f32 *)(s + 0x628) > 34.0f) {
                    if (s[0x24FE] != 0) {
                        SetState_00656F28(s, 1);
                        break;
                    }
                    if (*(f32 *)(s + 0x2468) > 0.9f) {
                        (*(VT_00656F28 **)(s + 0x14))->f34(s, 2, 0, 0, 1);
                        func_L39_0062B4A8(s, 3, D_L39_00246018[Dec_00656F28(s + 0x19E5)], 0, 11.0f);
                        break;
                    }
                }
                if ((f32)*(s32 *)(r + 0x18) < *(f32 *)(s + 0x628)) {
                    if (*(f32 *)(s + 0x2468) > 0.8f) {
                        SetState_00656F28(s, 2);
                        break;
                    }
                    if ((f32)(*(s32 *)(r + 0x18) + 5) < *(f32 *)(s + 0x628) || (*(s32 *)(s + 0x618) & 2)) {
                        (*(VT_00656F28 **)(s + 0x14))->f34(s, 0, 0, 0, 1);
                    }
                    break;
                }
            }
            if (DecEq_00656F28(s + 0x19E4, 0x15) && *(s32 *)(s + 0x478) != 0xA) {
                SetState_00656F28(s, 0);
                break;
            }
            if (DecEq_00656F28(s + 0x19E4, 0x15) && *(s32 *)(s + 0x2F0) >= 0x54 &&
                *(s32 *)(s + 0x634) < 0xD) {
                func_L39_0062B728(s, 2);
                *(s32 *)(s + 0x634) = 0xD;
            }
            break;
        case 0x85:
            if (*(f32 *)(s + 0x628) > 37.0f && *(s32 *)(s + 0x61C) == 0) {
                if (func_L01_004606E8(func_L39_005C42E8(0x40, *(s32 *)(s + 0x2544)), 6, 0,
                                      *(void **)(s + 0x2534)) != 0) {
                    if (!(*(s32 *)(*(u8 **)(s + 0x2534) + 0x1A0) &
                          func_L39_005C42E8(8, *(s32 *)(s + 0x2544)))) {
                        SetState_00656F28(s, 7);
                        break;
                    }
                    if (func_L39_00638C28(s) != 0) {
                        break;
                    }
                }
            }
            if (*(s32 *)(s + 0x61C) == 0 && *(f32 *)(s + 0x628) > 37.0f) {
                (*(VT_00656F28 **)(s + 0x14))->f34(s, 0, 0, 0, 1);
                func_L39_0062B4A8(s, func_L39_006223B0(s, 0), 0, 0, 12.0f);
                break;
            }
            if (DecEq_00656F28(s + 0x19E4, 0x15) && *(s32 *)(s + 0x2F0) >= 0x54 &&
                *(s32 *)(s + 0x634) < 0xD) {
                func_L39_0062B728(s, 2);
                *(s32 *)(s + 0x634) = 0xD;
            }
            break;
        case 0x79:
            if (*(s32 *)(s + 0x618) & 2) {
                SetState_00656F28(s, 0);
            }
            break;
        case 0x2:
        case 0x2E:
        case 0x72:
            if (s[0x142E] != 0 && (*(f32 *)(s23 + 0x44) > 0.9f || s23[0x42] != 0xFF)) {
                s[0x142E] = 0;
            }
            if (s[0x378] != 0 && *(s16 *)(s + 0x2DC) == 0) {
                SetState_00656F28(s, 0x78);
                break;
            }
            if (*(s16 *)(s + 0x2DE) >= 6) {
                if ((!DecEq_00656F28(s + 0x19E8, 0x12) || s[0x1A09] == 0) &&
                    *(f32 *)(s + 0x2AC) > 1.35f && func_L39_00638F50(s) == 0) {
                    SetState_00656F28(s, 6);
                    break;
                }
            }
            t = *(s16 *)(s + 0x32C) ? 1 : 7;
            if (func_L01_004606E8(func_L39_005C42E8(0x40, *(s32 *)(s + 0x2544)), t, 0,
                                  *(void **)(s + 0x2534)) != 0 &&
                !(*(s16 *)(s + 0x2DE) >= 7 && *(s16 *)(s + 0x330) == 0)) {
                func_L39_00632D78(s, 0, 1.0f);
                if (func_L39_0062D7C8(s, t, 1) == 0) {
                    if (*(f32 *)(s + 0x2468) > 0.85f) {
                        if (*(s16 *)(s + 0x3E4) != 0 ||
                            (*(s32 *)(s + 0x1310) == 1 &&
                             func_L01_004606E8(0x28, 2, 0, *(void **)(s + 0x2534)) != 0 &&
                             func_L39_006212E8(s) != 0xA)) {
                            if (!DecEq_00656F28(s + 0x19E4, 0x10)) {
                                SetState_00656F28(s, 7);
                                break;
                            }
                        }
                        SetState_00656F28(s, 9);
                    } else {
                        SetState_00656F28(s, 7);
                    }
                }
                break;
            }
            if (*(s16 *)(s + 0x2DE) == 0) {
                if (s[0x372] == 0 ||
                    (*(f32 *)(s + 0x1A4) < 0.040000003f && *(f32 *)(s + 0x2B0) < 0.08726646f)) {
                    o = *(u8 **)(s + 0x2534);
                    if ((*(s32 *)(o + 0x1A0) & func_L39_005C42E8(4, *(s32 *)(s + 0x2544))) &&
                        *(s32 *)(s + 0x2F0) > 0 &&
                        (D_1A5810[*(s32 *)(s + 0x2544) + 0xA4] != 2 || *(s32 *)(s + 0x478) == 3)) {
                        if (!DecEq_00656F28(s + 0x19E6, 0x14) &&
                            (*(VT_00656F28 **)(s + 0x14))->f44(s, 2) == 0) {
                            SetState_00656F28(s, 1);
                            break;
                        }
                    }
                }
                o = *(u8 **)(s + 0x2534);
                if ((*(s32 *)(o + 0x1A0) & func_L39_005C42E8(8, *(s32 *)(s + 0x2544))) &&
                    !(func_L39_005C2F50(o) & 0x10)) {
                    SetState_00656F28(s, 4);
                    break;
                }
                t = func_L39_0063BE00(s, 0.034906585f);
                if (DecEq_00656F28(s + 0x19E4, 2)) {
                    if ((*(f32 *)(s + 0x2468) < 0.17f || *(s16 *)(s + 0x320) != 0) && t == 0 &&
                        (*(s32 *)(s + 0x1430) == 0 || fabs_asm(*(f32 *)(s + 0xFD8)) < 0.017453292f)) {
                        if (func_L39_00638DF0(s) == 0) {
                            if (s[0x1A07] == 0 || *(s32 *)(s + 0x3FC) >= 3) {
                                if ((*(VT_00656F28 **)(s + 0x14))->f34(s, 0, 0, 0, 1) != 0) {
                                    func_003C4BB0(s + 0x190, 0.03f);
                                    if (*(f32 *)(s + 0xFB4) > 0.03f) {
                                        *(f32 *)(s + 0xFB4) = 0.03f;
                                    }
                                    func_L39_0062B4A8(s, func_L39_006223B0(s, 1), 0, 0, -1.0f);
                                }
                            } else {
                                func_L39_0062DA30(s);
                            }
                        }
                    } else {
                        func_L39_0062DA30(s);
                    }
                }
            }
            break;
        case 0x7D:
            f = s[0x1A07] ? 1 : (*(s32 *)(s + 0x2F0) >= 0x33 ? 1 : (*(s16 *)(s + 0x2D8) != 0 ? 1 : 0));
            if (f == 0) {
                St7D_00656F28(s);
            } else {
                if (Dec3_00656F28(s + 0x1A26) != 0) {
                    Set3_00656F28(s + 0x1A2C, 1);
                }
                if (D_1A5810[*(s32 *)(s + 0x2544) + 0xA4] == 1) {
                    Push_00656F28(s);
                }
                func_L39_0063A030(s, 9, 0);
                *(s16 *)(s + 0x320) = 0x19;
                (*(VT_00656F28 **)(s + 0x14))->f34(s, 3, 0, 0, 1);
                func_L39_0062B4A8(s, 6, 4, 0, 9.0f);
            }
            break;
        case 0x64:
            if (func_0038CF38(s + 0xA0, s + 0x13C0) < 0.2f) {
                if (*(f32 *)(s + 0x1A0) < 0.054000005f &&
                    func_0038DBA0(*(f32 *)(s + 0xB8), *(f32 *)(s + 0x13CC)) < 0.034906585f) {
                    SetState_00656F28(s, 0x66);
                }
            } else {
                func_L39_0062DA30(s);
            }
            break;
        case 0x65:
            if (*(s32 *)(s + 0x618) & 2) {
                SetState_00656F28(s, 0x64);
            }
            break;
        case 0x66:
            if (*(s32 *)(s + 0x13D4) == 0) {
                if ((*(s32 *)(s + 0x618) & 2) || *(s32 *)(s + 0x13D0) != 0) {
                    (*(VT_00656F28 **)(s + 0x14))->f34(s, 0, 1, 0, 1);
                }
                if (*(s32 *)(s + 0x13D4) == 0 && func_0038CF38(s + 0xA0, s + 0x13C0) > 0.2f) {
                    SetState_00656F28(s, 0x64);
                }
            }
            break;
        case 0x7A:
            if (*(f32 *)(s + 0xA8) < *(f32 *)(s + 0x2C4) - 1.2f || *(s32 *)(s + 0x2F0) >= 0x7E) {
                func_L39_00628038(s, 1);
            }
            break;
        case 0x6F:
            if ((f32)*(s32 *)(D_L39_0047A8A8 + *(s16 *)(s + 0x107C) * 0x2C + 0x18) < *(f32 *)(s + 0x628)) {
                SetState_00656F28(s, 0);
            }
            break;
        case 0x3:
            o = *(u8 **)(s + 0x2534);
            if ((*(s32 *)(o + 0x1A0) & func_L39_005C42E8(4, *(s32 *)(s + 0x2544))) &&
                *(s32 *)(s + 0x2F0) > 0 &&
                (D_1A5810[*(s32 *)(s + 0x2544) + 0xA4] != 2 || *(s32 *)(s + 0x478) == 3)) {
                if (!DecEq_00656F28(s + 0x19E6, 0x14) &&
                    (*(VT_00656F28 **)(s + 0x14))->f44(s, 2) == 0) {
                    SetState_00656F28(s, 1);
                    break;
                }
            }
            if (*(s16 *)(s + 0x320) == 0 &&
                (*(s32 *)(*(u8 **)(s + 0x2534) + 0x1A4) & func_L39_005C42E8(0x40, *(s32 *)(s + 0x2544)))) {
                SetState_00656F28(s, 7);
                break;
            }
            o = *(u8 **)(s + 0x2534);
            if (*(s16 *)(s + 0x320) == 0 && (*(s32 *)(o + 0x1A0) & func_L39_005C42E8(8, *(s32 *)(s + 0x2544))) &&
                !(func_L39_005C2F50(o) & 0x10)) {
                SetState_00656F28(s, 4);
                break;
            }
            if (*(s16 *)(s + 0x2DE) >= 8 && *(f32 *)(s + 0x2AC) > 0.3f) {
                SetState_00656F28(s, 6);
                break;
            }
            if (*(s32 *)(s + 0x618) & 2) {
                SetState_00656F28(s, 0);
                break;
            }
            x = *(f32 *)(s + 0x2468);
            if (x > 0.2f && *(s16 *)(s + 0x320) == 0) {
                if (*(f32 *)(s + 0xFB4) == 0.0f) {
                    (*(VT_00656F28 **)(s + 0x14))->f34(s, 0, 0, 0, 1);
                } else if (x > 0.5f) {
                    SetState_00656F28(s, 2);
                }
            }
            break;
        case 0x4:
            o = *(u8 **)(s + 0x2534);
            if ((*(s32 *)(o + 0x1A0) & func_L39_005C42E8(4, *(s32 *)(s + 0x2544))) &&
                *(s32 *)(s + 0x2F0) > 0 &&
                (D_1A5810[*(s32 *)(s + 0x2544) + 0xA4] != 2 || *(s32 *)(s + 0x478) == 3)) {
                if (!DecEq_00656F28(s + 0x19E6, 0x14) &&
                    (*(VT_00656F28 **)(s + 0x14))->f44(s, 2) == 0) {
                    (*(VT_00656F28 **)(s + 0x14))->f34(s, 1, 0, 0, 1);
                    break;
                }
            }
            if (*(s32 *)(s + 0x2F0) < 0xA ||
                ((*(s32 *)(*(u8 **)(s + 0x2534) + 0x1A0) & func_L39_005C42E8(8, *(s32 *)(s + 0x2544))) &&
                 *(s16 *)(s + 0x320) == 0)) {
                if (s[0x378] != 0 && *(s16 *)(s + 0x2DC) == 0) {
                    SetState_00656F28(s, 0x78);
                    break;
                }
                if (func_L39_00638C28(s) == 0) {
                    if (func_L01_004606E8(0x80, 0xC, 0, *(void **)(s + 0x2534)) != 0 && s[0x46A] == 0 &&
                        *(s32 *)(s + 0x478) == 0xA) {
                        if (*(s32 *)(s + 0x251C) != 0) {
                            func_L39_0063D240(s, 0);
                        } else {
                            SetState_00656F28(s, 0x15);
                        }
                    }
                    if (*(s16 *)(s + 0x2DE) >= 8 &&
                        (!DecEq_00656F28(s + 0x19E7, 8) || *(s32 *)(s + 0x2F0) >= 0xC)) {
                        SetState_00656F28(s, 6);
                    }
                }
            } else {
                (*(VT_00656F28 **)(s + 0x14))->f34(s, 0, 0, 0, 1);
                func_L39_0062B4A8(s, func_L39_006223B0(s, 0), 0, 0, -2.0f);
            }
            break;
        case 0x2B:
            if (!(*(s32 *)(*(u8 **)(s + 0x2534) + 0x1A0) & *(s32 *)(s + 0x460)) &&
                *(s32 *)(s + 0x2F0) >= 9) {
                SetState_00656F28(s, 0x2C);
                *(f32 *)(s + 0x15C4) = 0.0028000001f;
                *(f32 *)(s + 0x15C0) = 0.0108f;
            }
            break;
        case 0x17:
            if (*(f32 *)(s + 0x628) > 13.5f) {
                (*(VT_00656F28 **)(s + 0x14))->f34(s, 0x18, 0, 0, 1);
            }
            break;
        case 0x18:
            if ((*(s32 *)(s + 0x618) & 2) && (*(u8 **)(s + 0x2524))[0x43] == 0x20) {
                func_L39_0062B4A8(s, 0x21, 0, 0, 5.0f);
            }
            func_L39_00632D78(s, 0, 1.0f);
            if (func_L39_006233A8(s, s + 0xA0, s + 0xB0, 0) != 0) {
                if (*(f32 *)(s + 0x2468) > 0.5f &&
                    func_L01_004606E8(func_L39_005C42E8(0x40, *(s32 *)(s + 0x2544)), 7, 0,
                                      *(void **)(s + 0x2534)) != 0 &&
                    func_0038DBA0(*(f32 *)(s + 0xFD0), *(f32 *)(s + 0xB8)) > 2.3561945f) {
                    goto turn_0x18;
                }
                if (!(*(s32 *)(*(u8 **)(s + 0x2534) + 0x1A4) & func_L39_005C42E8(8, *(s32 *)(s + 0x2544)))) {
                    if (func_L01_004606E8(func_L39_005C42E8(0x40, *(s32 *)(s + 0x2544)), 0xE, 0,
                                          *(void **)(s + 0x2534)) != 0) {
                        SetState_00656F28(s, 0x1B);
                        break;
                    }
                    if (*(f32 *)(s + 0x2468) > 0.5f) {
                        if (func_0038DBA0(*(f32 *)(s + 0xFD0),
                                          func_0038DAB8(*(f32 *)(s + 0xB8), 1.5707964f)) < 0.7853982f) {
                            if (Step_00656F28(s, 1.5707964f) != 0) {
                                SetState_00656F28(s, 0x19);
                                break;
                            }
                        } else if (*(f32 *)(s + 0x2468) > 0.5f &&
                                   func_0038DBA0(*(f32 *)(s + 0xFD0),
                                                 func_0038DAB8(*(f32 *)(s + 0xB8), -1.5707964f)) < 0.7853982f) {
                            if (Step_00656F28(s, -1.5707964f) != 0) {
                                SetState_00656F28(s, 0x1A);
                                break;
                            }
                        }
                    }
                } else {
                turn_0x18:
                    SetState_00656F28(s, 6);
                    s[0x1A0B] = 1;
                    *(s16 *)(s + 0x308) = 8;
                }
            } else {
                SetState_00656F28(s, 6);
                *(s16 *)(s + 0x308) = 8;
            }
            break;
        case 0x19:
        case 0x1A:
            St19_00656F28(s);
            break;
        case 0x78:
            if (s[0x1A14] != 0 && *(s32 *)(s + 0x2F0) >= 0xFB) {
                func_L39_0063B5E0(s, 0xF);
                (*(VT_00656F28 **)(s + 0x14))->f34(s, 0x76, 0, 0, 0);
                func_L39_00628038(s, 1);
            }
            if (s[0x378] == 0) {
                SetState_00656F28(s, *(s16 *)(s + 0x2DE) != 0 ? 6 : 0);
            }
            break;
        case 0x6:
        case 0x2C:
            if (Dec_00656F28(s + 0x19E5) == 0 &&
                (*(s32 *)(s + 0x2F0) >= 0xF || *(f32 *)(s + 0x2AC) > 1.75f)) {
                func_L39_0062B4A8(s, 0xB, 0, 0, 13.0f);
                Set_00656F28(s + 0x19E5, 1);
                if (DecEq_00656F28(s + 0x19E4, 0x2C)) {
                    *(s32 *)(s + 0x2450) = 7;
                } else {
                    *(s32 *)(s + 0x2450) = 0;
                }
            }
            if (*(s16 *)(s + 0x2DE) != 0) {
                if (!Dead_00656F28(s)) {
                    if (*(s16 *)(s + 0x330) >= 0x12) {
                        if (func_L39_0062D7C8(s, *(s16 *)(s + 0x32C) == 0 ? 5 : 1, 0) != 0) {
                            break;
                        }
                        if (s[0x1A14] != 0) {
                            Spot_00656F28(s);
                        }
                    }
                    if (*(s32 *)(s + 0x1568) != 0) {
                        SetState_00656F28(s, 0x17);
                    }
                }
            } else {
                func_L39_0063A2E8(s);
                if (*(f32 *)(s + 0x148) < -0.18f) {
                    *(f32 *)(s + 0x148) = -0.18f;
                }
                if (*(f32 *)(s + 0x128) < -0.18f) {
                    *(f32 *)(s + 0x128) = -0.18f;
                }
                if (Dead_00656F28(s)) {
                    SetState_00656F28(s, 0x39);
                    break;
                }
                v = *(s32 *)(s + 0x2CC) == 0;
                if (*(s32 *)(s + 0x2F0) >= 0x4B) {
                    if ((*(VT_00656F28 **)(s + 0x14))->f34(s, 0, 0, 0, 1) != 0) {
                        func_L39_0062B4A8(s, 0xC, 4, 0, 5.0f);
                    }
                    if (v != 0) {
                        *(s16 *)(s + 0x320) = 0x12;
                    }
                    func_L32_004FD190(s, 0xA, 4, 0, 1, 0.022f, 0.004f);
                } else if (!DecEq_00656F28(s + 0x19E5, 1)) {
                    if (*(f32 *)(s + 0x2468) > 0.5f && *(s16 *)(s + 0x320) == 0) {
                        (*(VT_00656F28 **)(s + 0x14))->f34(s, 2, 1, 0, 1);
                        func_L32_004FD190(s, 7, 2, 0, 1, 0.016f, 0.002f);
                    } else if (*(f32 *)(s + 0x1A4) > 0.060000002f) {
                        if ((*(VT_00656F28 **)(s + 0x14))->f34(s, 3, 0, 0, 1) != 0) {
                            func_L39_0062B4A8(s, 6, 0, 0, 10.0f);
                            func_003C4BB0(s + 0x190, 0.15400001f);
                        }
                    } else {
                        (*(VT_00656F28 **)(s + 0x14))->f34(s, 0, 1, 0, 1);
                        func_L32_004FD190(s, 5, 2, 0, 1, 0.016f, 0.002f);
                    }
                } else {
                    if ((*(VT_00656F28 **)(s + 0x14))->f34(s, 0, 0, 0, 1) != 0) {
                        func_L39_0062B4A8(s, 0xC, 9, 0, -1.0f);
                    }
                    func_L39_00632558(s, s + 0x190, s + 0x190, 0.0f);
                    func_003C4BB0(s + 0x190, 0.14000002f);
                    *(s16 *)(s + 0x320) = 6;
                    if (DecEq_00656F28(s + 0x19E7, 0x2C)) {
                        *(s16 *)(s + 0x320) = 8;
                    }
                    if (v != 0 && *(s32 *)(s + 0x2F0) >= 0x2B) {
                        *(s16 *)(s + 0x320) = 0xF;
                    }
                    func_L32_004FD190(s, 0xA, 2, 0, 1, 0.019f, 0.002f);
                }
            }
            break;
        case 0x76:
            if (*(s32 *)(s + 0x2F0) >= 0x65) {
                func_L39_00628038(s, 1);
            }
            break;
        case 0x7:
        case 0x9:
        case 0xA:
        case 0xB:
        case 0xC:
        case 0xD:
        case 0xE:
        case 0xF:
        case 0x10:
        case 0x11:
        case 0x12:
        case 0x1B:
        case 0x38:
        case 0x68:
        case 0x70:
        case 0x83:
            if (s[0x153E] != 0) {
                t = func_L01_004FF5D8(s);
                if (t > 0 && (*(s32 *)(s + 0x2F0) < t || s[0x14AC] != 0) && *(s32 *)(s + 0x2D0) != 0) {
                    if (!DecEq_00656F28(s + 0x19E4, 0xB) ||
                        func_L01_004606E8(func_L39_005C42E8(0x40, *(s32 *)(s + 0x2544)), 6, 0,
                                          *(void **)(s + 0x2534)) != 0) {
                        v = 1;
                        if (DecEq_00656F28(s + 0x19E4, 0x1B) || s[0x14AC] != 0) {
                            v = func_L01_004606E8(func_L39_005C42E8(0x40, *(s32 *)(s + 0x2544)), 6, 0,
                                                  *(void **)(s + 0x2534)) != 0;
                        }
                        if (D_1A5810[*(s32 *)(s + 0x2544) + 0xA4] == 2) {
                            if (s[0x3E7] == 3) {
                                v = 0;
                            }
                        }
                        if (DecEq_00656F28(s + 0x19E4, 0xB)) {
                            if (s[0x14AC] == 0) {
                                v = 0;
                            }
                        }
                        if (v != 0 && func_L01_004606E8(0x1F000, 4, 0, *(void **)(s + 0x2534)) != 0 &&
                            (*(s32 *)(*(u8 **)(s + 0x2534) + 0x1A0) & func_L39_005C42E8(8, *(s32 *)(s + 0x2544)))) {
                            SetState_00656F28(s, 0xB);
                            break;
                        }
                    }
                }
            }
            if (DecEq_00656F28(s + 0x19E4, 0x1B) && *(s32 *)(s + 0x2F0) >= 0x12 && *(f32 *)(s + 0x208) > 0.7f) {
                s[0x1A0B] = 0;
                s[0x1A0C] = 0;
            }
            if (*(s16 *)(s + 0x152A) < *(s32 *)(s + 0x2F0)) {
                if (s[0x14AC] == 0) {
                    SetState_00656F28(s, 6);
                    break;
                }
            } else if (s[0x14AC] == 0 && (DecEq_00656F28(s + 0x19E4, 0xA) || DecEq_00656F28(s + 0x19E4, 0x10))) {
                if (*(f32 *)(s + 0x208) < 0.9f && s[0x216] != 0 && func_0038CEA8(s + 0x120) > 0.14000002f) {
                    x = func_0038CEA8(s + 0x140);
                    if (x < func_0038CEA8(s + 0x120) * 0.5f && *(s32 *)(s + 0x1568) == 0 &&
                        *(f32 *)(s + 0x2AC) < 2.0f) {
                        SetState_00656F28(s, 0x79);
                        break;
                    }
                }
            }
            w = 0;
            if (DecEq_00656F28(s + 0x19E4, 0xE) && *(f32 *)(s + 0x628) < 35.0f) {
                w = 1;
            }
            h = *(s16 *)(s + 0x14BC);
            t = *(s32 *)(s + 0x2F0);
            if (h < t) {
                if (t == h + 1) {
                    if (s[0x14AD] == 0) {
                        if (!DecEq_00656F28(s + 0x19E4, 0xE)) {
                            func_L39_00632458(s, s + 0xA0, s + 0x120, &n30, *(f32 *)(s + 0x1530));
                            func_L39_0062B740(s, *(f32 *)(s + 0x14D8), (f32)n30, *(f32 *)(s + 0x1524), -1.0f);
                            if (*(f32 *)(s + 0x610) > 1.5f) {
                                *(f32 *)(s + 0x610) = 1.5f;
                            }
                        }
                    } else {
                        x = (f32)(*(s32 *)(s + 0x1440) - t);
                        if (x > 0.0f) {
                            func_L39_0062B740(s, *(f32 *)(s + 0x1448), x, *(f32 *)(s + 0x1524), -1.0f);
                        }
                    }
                    break;
                }
                if (s[0x14AD] != 0 && t >= *(s32 *)(s + 0x1440) && t < *(s32 *)(s + 0x1444)) {
                    x = (f32)(*(s32 *)(s + 0x1450) - *(s32 *)(s + 0x1440));
                    if (x > 0.0f) {
                        func_L39_0062B740(s, *(f32 *)(s + 0x14D8), x, *(f32 *)(s + 0x1524), -1.0f);
                    }
                    break;
                }
                if (*(s32 *)(s + 0x2C8) == 1) {
                    func_L39_00647FE0(s, 3, 0x18, 1);
                }
                if (s[0x14AC] != 0) {
                    s[0x14AC]++;
                } else if (*(s16 *)(s + 0x2DE) == 0 && s[0x14AE] != 0 && w == 0) {
                    func_L39_0063A2E8(s);
                    s[0x14AC] = 1;
                    if (*(f32 *)(s + 0x2468) < 0.2f && *(f32 *)(s + 0xFB4) > 0.050000004f) {
                        *(f32 *)(s + 0xFB4) = 0.050000004f;
                    }
                    func_L32_004FD190(s, 5, 2, 0, 1, 0.016f, 0.002f);
                    if (w == 0 && *(f32 *)(s + 0x628) < *(f32 *)(s + 0x14DC) - 1.5f) {
                        func_L39_0062B4A8(s, func_L39_0063D0F0(s, s23[0x43]), (s32)*(f32 *)(s + 0x14E0) + 2, 0, 6.0f);
                    }
                }
                if (s[0x14AC] != 0) {
                    *(f32 *)(s + 0x610) = 1.0f;
                } else if (s[0x14AE] != 0) {
                    if (s23[0x41] < (s32)*(f32 *)(s + 0x14E0)) {
                        if (DecEq_00656F28(s + 0x19E4, 0xE) && *(f32 *)(s + 0x628) < 37.0f) {
                            func_003C4138(s + 0x610, 1.0f, 0.216f);
                        } else {
                            h = func_L39_0063C000(s, 60.0f, *(f32 *)(s + 0x1530), -1.0f);
                            *(s16 *)(s + 0x14BE) = h;
                            func_L39_0062B740(s, *(f32 *)(s + 0x14DC), (f32)h, *(f32 *)(s + 0x1524), 0.288f);
                        }
                        if (w == 0 && *(f32 *)(s + 0x610) > 1.8f) {
                            func_L39_0062B4A8(s, func_L39_0063D0F0(s, s23[0x43]), (s32)*(f32 *)(s + 0x14E0) + 2, 0,
                                              (f32)(*(s16 *)(s + 0x14BE) + 3));
                        }
                        if (*(f32 *)(s + 0x610) < 0.2f) {
                            *(f32 *)(s + 0x610) = 0.2f;
                        }
                        if (*(f32 *)(s + 0x610) > 2.7f) {
                            *(f32 *)(s + 0x610) = 2.7f;
                        }
                    }
                    if (DecEq_00656F28(s + 0x19E4, 9) && *(f32 *)(s + 0x14DC) - *(f32 *)(s + 0x628) > 6.0f &&
                        (func_L39_0063D0F0(s, s23[0x42]) == 8 || func_L39_0063D0F0(s, s23[0x42]) == 9) &&
                        s23[0x42] == s23[0x43] &&
                        *(f32 *)(s + 0xFB0) < D_L39_00246010[0] * 0.020000001f * 0.1f &&
                        *(f32 *)(s + 0x1A4) < 0.050000004f) {
                        x = 7.0f / *(f32 *)(s + 0x610);
                        if (x > 8.0f) {
                            x = 8.0f;
                        }
                        func_L39_0062B4A8(s, 7, ((s32)*(f32 *)(s + 0x628) + 4) / 2, 0, x);
                        Set_00656F28(s + 0x19E4, 7);
                    }
                    if ((s32)*(f32 *)(s + 0x628) == (s32)*(f32 *)(s + 0x14DC)) {
                        *(f32 *)(s + 0x610) = 0.0f;
                    }
                }
                if (s[0x14AC] != 0 && DecEq_00656F28(s + 0x19E4, 0xA)) {
                    if ((*(VT_00656F28 **)(s + 0x14))->f34(s, 3, 0, 0, 1) != 0) {
                        func_L39_0062B4A8(s, 5, 0, 0, -2.0f);
                        func_0038CE20(s + 0x190, s + 0x190, 0.8f);
                    }
                } else if (s[0x14AC] != 0 && s[0x378] == 0 && *(s16 *)(s + 0x320) == 0 &&
                           func_L01_004606E8(func_L39_005C42E8(0x40, *(s32 *)(s + 0x2544)), 7, 0,
                                             *(void **)(s + 0x2534)) != 0 &&
                           *(s16 *)(s + 0x2DE) < 3) {
                    if (*(s16 *)(s + 0x3E4) != 0 ||
                        (*(s32 *)(s + 0x1310) == 1 && func_L01_004606E8(0x28, 2, 0, *(void **)(s + 0x2534)) != 0 &&
                         func_L39_006212E8(s) != 0xA)) {
                        if (!DecEq_00656F28(s + 0x19E4, 0x10) && *(f32 *)(s + 0x2468) > 0.9f &&
                            func_L39_00629DE0(s) != 2 &&
                            (D_1A5810[*(s32 *)(s + 0x2544) + 0xA4] != 2 || s[0x3E7] != 3)) {
                            SetState_00656F28(s, 0xB);
                            break;
                        }
                    }
                    if (D_L39_00246004[0] < *(f32 *)(s + 0xFB0) &&
                        func_0038DBA0(*(f32 *)(s + 0xFD0), *(f32 *)(s + 0xB8)) < 1.0471976f &&
                        D_L39_00246010[0] * 0.020000001f * 0.85f < *(f32 *)(s + 0x1A4)) {
                        SetState_00656F28(s, 9);
                    } else {
                        SetState_00656F28(s, 7);
                    }
                } else {
                    if (s[0x14AC] < 2 || DecEq_00656F28(s + 0x19E4, 0xA)) {
                        if (s[0x14AE] != 0 && *(s32 *)(s + 0x2F0) >= *(s16 *)(s + 0x153A) &&
                            *(f32 *)(s + 0x1520) < *(f32 *)(s + 0x2AC)) {
                            SetState_00656F28(s, 6);
                        }
                    } else {
                        func_L39_00638848(s);
                    }
                    if (DecEq_00656F28(s + 0x19E4, 0x10) && *(s32 *)(s + 0x2F0) >= 0x33 &&
                        *(f32 *)(s + 0x2AC) > 1.5f) {
                        SetState_00656F28(s, 6);
                        break;
                    }
                    v = 0;
                    if (DecEq_00656F28(s + 0x19E4, 7) || DecEq_00656F28(s + 0x19E4, 9) ||
                        DecEq_00656F28(s + 0x19E4, 0x11)) {
                        v = 1;
                    }
                    if (DecB_00656F28(s + 0x310) && s[0x14AC] == 0 && v != 0 &&
                        (!DecEq_00656F28(s + 0x19E4, 0x11) || *(s32 *)(s + 0x2F0) >= 0x16)) {
                        t = 6;
                        if (DecEq_00656F28(s + 0x19E4, 0x11)) {
                            t = 6;
                        }
                        if (func_L01_004606E8(func_L39_005C42E8(0x40, *(s32 *)(s + 0x2544)), t, &n34,
                                              *(void **)(s + 0x2534)) != 0 &&
                            n34 < *(s32 *)(s + 0x2F0)) {
                            SetState_00656F28(s, 0x11);
                            break;
                        }
                    }
                    if (DecEq_00656F28(s + 0x19E4, 0xA) || DecEq_00656F28(s + 0x19E4, 0x10)) {
                        if (*(s32 *)(s + 0x2F0) >= 0x16 && *(s16 *)(s + 0x2DA) != 0) {
                            *(s16 *)(s + 0x1536) = 0x11;
                        }
                    }
                    Dec_00656F28(s + 0x19E4);
                    if (DecEq_00656F28(s + 0x19E4, 0xE) && *(f32 *)(s + 0x2AC) > 4.0f) {
                        if (s[0x14AE] == 0 && *(f32 *)(s + 0x610) < 1.3f) {
                            func_003C4138(s + 0x610, 1.3f, 0.12f);
                        }
                        *(s16 *)(s + 0x1536) = 0xE;
                    }
                    t = *(s32 *)(s + 0x2F0) - 4;
                    if (t <= 1) {
                        t = 2;
                    }
                    if (t >= 0x1A) {
                        t = 0x19;
                    }
                    if (!(*(unsigned long *)(s + 0x14A8) & ((unsigned long)0xFF0000FF << 32))) {
                        if (func_L01_004606E8(func_L39_005C42E8(0x40, *(s32 *)(s + 0x2544)), t, 0,
                                              *(void **)(s + 0x2534)) != 0 ||
                            DecEq_00656F28(s + 0x19E4, 0xE) || DecEq_00656F28(s + 0x19E4, 0xF) ||
                            DecEq_00656F28(s + 0x19E4, 0xD)) {
                            if (!DecEq_00656F28(s + 0x19E4, 0xE) && s[0x1A07] == 0 &&
                                (s[0x378] == 0 || !(*(f32 *)(s + 0x2AC) < 0.4f)) && s[0x153F] != 0 &&
                                *(s32 *)(s + 0x2F0) >= 0xD &&
                                (s[0x14AE] == 0 ||
                                 (*(f32 *)(s + 0x2AC) > 0.7f &&
                                  fabs_asm(func_L39_00632678(s, s + 0x120)) < 0.11600001f))) {
                                SetState_00656F28(s, 0xE);
                            }
                        }
                    }
                    if (*(s32 *)(s + 0x1568) != 0 && !DecEq_00656F28(s + 0x19E4, 0xB)) {
                        SetState_00656F28(s, 0x17);
                    }
                }
            }
            break;
        case 0x16:
            if (*(f32 *)(s + 0x628) > 12.5f && *(s16 *)(s + 0x2DE) != 0 && *(f32 *)(s + 0x2AC) > 1.0f) {
                SetState_00656F28(s, 6);
                break;
            }
            if (*(s32 *)(s + 0x2F0) >= 0x17) {
                if (Dead_00656F28(s)) {
                    SetState_00656F28(s, 0x39);
                } else if (s[0x2500] != 0) {
                    SetState_00656F28(s, 0x1D);
                } else {
                    (*(VT_00656F28 **)(s + 0x14))->f34(s, 0, 0, 0, 1);
                }
            }
            break;
        case 0x8E:
            if (*(s32 *)(s + 0x618) & 2) {
                func_L39_0062B4A8(s, 0x41, 0, 0, 2.0f);
            }
            if (*(s32 *)(s + 0x2F0) >= 0x33) {
                func_L39_00628038(s, 0);
            }
            break;
        case 0x1:
        case 0x1D:
            if (s[0x24FE] == 0) {
                if (func_L39_0063D0F0(s, s23[0x43]) != func_L39_006223B0(s, 0) && (*(s32 *)(s + 0x618) & 2)) {
                    f = 0;
                    if (s[0x1A07] != 0 && s[0x1A05] != 0 &&
                        ((*(u8 **)(s + 0x2524))[0x43] == *(s32 *)(s + 0x2448) || *(s32 *)(s + 0x748) != 0)) {
                        f = 1;
                    }
                    if (f == 0) {
                        s[0x1A07] = 0;
                        if (s[0x24FD] != 0) {
                            func_L39_0062B4A8(s, 0xD, 0, 0, 7.0f);
                        } else {
                            func_L39_0062B4A8(s, func_L39_006223B0(s, 0), 0, 0, -2.0f);
                        }
                    }
                }
                if (s[0x1A05] == 0 || s[0x1A0A] != 0) {
                    if (s[0x24FD] == 0 &&
                        (*(s32 *)(*(u8 **)(s + 0x2534) + 0x1A0) & func_L39_005C42E8(8, *(s32 *)(s + 0x2544))) &&
                        *(s16 *)(s + 0x320) == 0) {
                        func_L39_0062B4A8(s, 0xD, 0, 0, 7.0f);
                        s[0x24FD] = 1;
                        func_L39_00656DB0(s);
                    } else if (!(*(s32 *)(*(u8 **)(s + 0x2534) + 0x1A0) &
                                 func_L39_005C42E8(8, *(s32 *)(s + 0x2544)))) {
                        f = (*(u8 **)(s + 0x2524))[0x43];
                        if (f != 0 && f != 3) {
                            s[0x24FD] = 0;
                        }
                    }
                }
                if (!(*(s32 *)(*(u8 **)(s + 0x2534) + 0x1A0) & func_L39_005C42E8(4, *(s32 *)(s + 0x2544)))) {
                    o = *(u8 **)(s + 0x2534);
                    if ((*(s32 *)(o + 0x1A0) & func_L39_005C42E8(8, *(s32 *)(s + 0x2544))) &&
                        !(func_L39_005C2F50(o) & 0x10) && *(s16 *)(s + 0x320) == 0) {
                        SetState_00656F28(s, 4);
                        D_001D6D98_sda = 0;
                    } else {
                        (*(VT_00656F28 **)(s + 0x14))->f34(s, 0, 0, 0, 1);
                        if (s[0x1A07] == 0 || (func_L39_006212E8(s) != 6 && func_L39_006212E8(s) != 0xC)) {
                            t = func_L39_006223B0(s, 1);
                            f = (*(u8 **)(s + 0x2524))[0x43];
                            if (f != t) {
                                func_L39_0062B4A8(s, t, 0, 0, (f32)(f == 0x1A ? 10 : 7));
                            }
                        }
                        D_001D6D98_sda = 0;
                    }
                }
            } else {
                if (*(f32 *)(s + 0x628) > 34.0f) {
                    s[0x24FE] = 0;
                }
                if (s[0x1A14] != 0 && func_L39_00632C48(s, 32.0f) != 0) {
                    func_L39_0063BA40(s);
                }
            }
            break;
        case 0x1F:
            if (*(s32 *)(s + 0x450) != 0 && *(s32 *)(s + 0x61C) == 0 && *(f32 *)(s + 0x628) > 20.0f) {
                (*(VT_00656F28 **)(s + 0x14))->f34(s, 0, 0, 0, 1);
            }
            break;
        case 0x22:
            if (*(f32 *)(s + 0x628) > 19.0f &&
                func_L01_004606E8(func_L39_005C42E8(0x40, *(s32 *)(s + 0x2544)), 9, 0, *(void **)(s + 0x2534)) != 0) {
                if (*(s32 *)(*(u8 **)(s + 0x2534) + 0x1A0) & func_L39_005C42E8(8, *(s32 *)(s + 0x2544))) {
                    func_L39_00638C28(s);
                } else {
                    SetState_00656F28(s, 7);
                }
            } else if (*(f32 *)(s + 0x628) >= 21.0f) {
                (*(VT_00656F28 **)(s + 0x14))->f34(s, 0, 0, 0, 1);
            }
            break;
        }
    }
tail:
    if (a != Dec_00656F28(s + 0x19E6)) {
        func_L39_0063A0F0(s);
    }
    if (b != Dec_00656F28(s + 0x19E5)) {
        *(s32 *)(s + 0x2F8) = 0;
    }
    if (fp != s23[0x43]) {
        *(s32 *)(s + 0x2FC) = 0;
    }
}
