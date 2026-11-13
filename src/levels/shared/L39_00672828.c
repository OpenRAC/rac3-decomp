#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00672828);

/* localdecomp:start func_L39_00672898 */
/* LOG
best 2 diff: abs.s lands in the bc1f delay slot; retail has it before bc1tl with the mov.s in the likely slot.
tried: if/ternary max(5,lim), operand order, abs before/after the max, abs inline in the condition, pointer e (fixed the addu regs), ee29check.
retail's abs.s is probably the original's fabs_asm (inline asm), forbidden now.
*/
#include "vu0.h"

typedef struct Ent_00672898 {
    u8 pad0[4];
    s16 h4;
    u8 pad6[0x80 - 6];
} Ent_00672898;
extern Ent_00672898 D_L39_0049C890_00672898[];

void func_L39_00672898(s32 i, f32 x, f32 *p) {
    f32 cur = *p;
    f32 lim = cur * 0.5f;
    f32 ad, m;
    Ent_00672898 *e = &D_L39_0049C890_00672898[i];
    x = x - (f32)e->h4;
    ad = fabs_asm(cur - x);
    m = 5.0f < lim ? lim : 5.0f;
    if (x > 0.0f && (x < cur || ad < m)) *p = x;
}
/* localdecomp:end func_L39_00672898 */

/* localdecomp:start func_L39_00672930 */
#include "vu0.h"

void func_L39_00672930(f32 *p, s32 n, f32 x) {
    f32 cur, half, limit, d;
    x -= (f32)n;
    cur = *p;
    half = cur * 0.5f;
    d = fabs_asm(cur - x);
    limit = (6.0f < half) ? half : 6.0f;
    if (0.0f < x && (x < cur || d < limit)) *p = x;
}
/* localdecomp:end func_L39_00672930 */

INCLUDE_ASM("asm/levels", func_L39_006729B0);

/* localdecomp:start func_L39_00672C00 */
void func_L39_00672C00(u8 *a0, s32 a1) {
    s32 i;
    s32 c = 255;
    *(s32 *)(a0 + 872) = a1;
    for (i = 9; i >= 0; i--) a0[66 + i * 80] = c;
    *(s16 *)(a0 + 876) = 0;
}
/* localdecomp:end func_L39_00672C00 */

/* localdecomp:start func_L39_00672C30 */
typedef struct G_00672C30 {
    u8 pad0[4];
    s32 w4;
    u8 pad8[0x128 - 8];
    s32 w128;
    u8 pad12C[0x170 - 0x12C];
    s32 w170;
    u8 pad174[0x7D4 - 0x174];
    u8 b7D4;
} G_00672C30;

typedef struct Msg_00672C30 {
    u8 pad0[0xC];
    s32 wC;
    s32 w10;
    s32 w14;
    s32 w18;
    u8 b1C;
} Msg_00672C30;

typedef struct Ent_00672C30 {
    u8 pad0[2];
    u8 b2;
    u8 b3;
    s32 w4;
    u8 pad8[0x20 - 8];
    struct Ent_00672C30 *p20;
} Ent_00672C30;

typedef struct Pl_00672C30 {
    u8 pad0[0x2544];
    s32 w2544;
} Pl_00672C30;

typedef struct Me_00672C30 {
    u8 pad0[0x360];
    u8 b360;
    u8 pad361[3];
    Ent_00672C30 *p364;
    Pl_00672C30 *p368;
    s16 h36C;
    s16 h36E;
    s16 h370[2];
} Me_00672C30;

extern G_00672C30 D_001A5CD0_00672C30;
extern s32 D_L39_002405AC;
extern void func_0014AD08(s32, s32, s32, s32, s32, void *);

void func_L39_00672C30(Me_00672C30 *a0) {
    Msg_00672C30 m;
    s32 i;
    s32 r;
    s16 *p = a0->h370;
    Ent_00672C30 *e;

    for (i = 1; i >= 0; i--, p++) {
        if (*p != -1) {
            m.b1C = 13;
            m.w18 = (a0->p368->w2544 << 16) | *p;
            m.w10 = 16;
            m.wC = D_001A5CD0_00672C30.w128;
            m.w14 = 0;
            if (D_001A5CD0_00672C30.w170 == 0) {
                func_0014AD08(D_001A5CD0_00672C30.b7D4 | 0x40, D_001A5CD0_00672C30.w4, -1, D_L39_002405AC, 0x20, &m);
            }
            *p = -1;
        }
    }
    if (*(u8 *)((u8 *)a0->p368 + 0x458) == 0) {
        a0->h36E++;
    } else {
        a0->h36E = 0;
    }
    if (a0->h36C != 0) {
        if (a0->h36E >= 0x3D) {
            a0->h36C = 0;
        }
    }
    e = a0->p364;
    if (e != 0) {
        if (D_001A5CD0_00672C30.w128 < e->w4) return;
        switch (e->b3) {
        case 1:
            a0->h36C = 1;
            a0->h36E = 0;
            r = 1;
            break;
        case 2:
            a0->h36C = 0;
            a0->h36E = 0;
            r = 1;
            break;
        default:
            r = D_001A5CD0_00672C30.w128 > a0->p364->w4 + 0x1770;
            break;
        }
        if (r) {
            a0->p364->b2 = 0xFF;
            a0->p364 = a0->p364->p20;
            a0->b360--;
        }
    }
}
/* localdecomp:end func_L39_00672C30 */

/* localdecomp:start func_L39_00672DD8 */
__asm__(".extern D_L39_002405E0, 16");

typedef struct Sub_00672DD8 {
    s16 h0;
    u8 b2;
    u8 b3;
    s32 w4;
    u32 w8;
    u8 padC[0x24 - 0xC];
} Sub_00672DD8;

typedef struct Evt_00672DD8 {
    s16 h0;
    u8 b2;
    u8 b3;
    s32 w4;
    u8 pad8[0x20 - 8];
    struct Evt_00672DD8 *next;
    Sub_00672DD8 sub;
    u8 pad48[0x50 - 0x48];
} Evt_00672DD8;

typedef struct Obj_00672DD8 {
    u8 pad0[0xAA];
    s16 hAA;
} Obj_00672DD8;

typedef struct Slot_00672DD8 {
    Obj_00672DD8 *o;
    u8 pad4[0x28 - 4];
    u16 h28;
    u8 pad2A[0x50 - 0x2A];
} Slot_00672DD8;

typedef struct Net_00672DD8 {
    u8 pad0[0x568];
    s32 w568;
} Net_00672DD8;

typedef struct G_00672DD8 {
    u8 pad0[0x450];
    Slot_00672DD8 slots[8];
    u8 pad6D0[0x1A14 - 0x6D0];
    u8 b1A14;
    u8 pad1A15[0x2534 - 0x1A15];
    Net_00672DD8 *p2534;
    u8 pad2538[0x2544 - 0x2538];
    u8 b2544;
} G_00672DD8;

typedef struct Own_00672DD8 {
    u8 pad0[0x40];
    Evt_00672DD8 evt[10];
    u8 b360;
    u8 pad361[3];
    Evt_00672DD8 *p364;
    G_00672DD8 *p368;
} Own_00672DD8;

typedef struct Def_00672DD8 {
    u8 pad0[4];
    s16 h4;
    u8 pad6[0x21 - 6];
    s8 b21;
    u8 pad22[0x70 - 0x22];
    void (*f70)(Obj_00672DD8 *, Sub_00672DD8 *);
    u8 pad74[0x80 - 0x74];
} Def_00672DD8;

typedef struct Mgr_00672DD8 {
    u8 pad0[4];
    s32 w4;
    u8 pad8[0x128 - 8];
    s32 w128;
    u8 pad12C[0x170 - 0x12C];
    s32 w170;
    u8 pad174[0x7D4 - 0x174];
    u8 b7D4;
} Mgr_00672DD8;

extern Mgr_00672DD8 D_001A5CD0;
extern Def_00672DD8 D_L39_0049C890_00672DD8[];
extern s32 D_L39_002405E0;
extern s32 func_L39_00648AE0(u8 *, s32);
extern void func_0014AD08(s32, s32, s32, s32, s32, void *);

void func_L39_00672DD8(Own_00672DD8 *g, u8 a1, s32 a2, s16 a3, u8 a4, Sub_00672DD8 *a5) {
    Sub_00672DD8 s;
    Evt_00672DD8 *e;
    Evt_00672DD8 *p;
    s16 h;
    s32 i;
    s32 none;

    if (g->b360 < 10) {
        for (i = 0, none = -1; i < 10; i++) {
            if (g->evt[i].b2 != 0xFF) {
                continue;
            }
            e = &g->evt[i];
            e->w4 = (a2 == none) ? D_001A5CD0.w128 + (s32)((f32)g->p368->p2534->w568 * 20.0f) : a2;
            if (a3 == none) {
                e->h0 = g->p368->slots[a4].h28;
            } else {
                e->h0 = a3;
            }
            e->b2 = a4;
            e->b3 = a1;
            e->next = 0;
            if (g->p368->b1A14 != 0) {
                s.h0 = e->h0;
                s.w4 = e->w4;
                s.b3 = a1;
                s.b2 = g->p368->b2544;
                s.w8 = 0xFFFFFFFF;
                h = e->h0;
                if ((func_L39_00648AE0((u8 *)g->p368, h) ? &D_L39_0049C890_00672DD8[D_L39_0049C890_00672DD8[h].b21] : &D_L39_0049C890_00672DD8[h])->f70 != 0) {
                    h = e->h0;
                    if ((func_L39_00648AE0((u8 *)g->p368, h) ? &D_L39_0049C890_00672DD8[D_L39_0049C890_00672DD8[h].b21] : &D_L39_0049C890_00672DD8[h])->h4 == g->p368->slots[a4].o->hAA) {
                        h = e->h0;
                        (func_L39_00648AE0((u8 *)g->p368, h) ? &D_L39_0049C890_00672DD8[D_L39_0049C890_00672DD8[h].b21] : &D_L39_0049C890_00672DD8[h])->f70(g->p368->slots[a4].o, &s);
                        e->w4 = s.w4;
                    }
                }
                e->sub = s;
                if (e->w4 != none) {
                    if (D_001A5CD0.w170 == 0) {
                        func_0014AD08(D_001A5CD0.b7D4 | 0x80, D_001A5CD0.w4, -1, D_L39_002405E0, 0x24, &s);
                    }
                } else {
                    e->w4 = D_001A5CD0.w128;
                    e->sub.w4 = D_001A5CD0.w128;
                }
            } else if (a5 != 0) {
                e->sub = *a5;
            }
            p = g->p364;
            while (p != 0 && p->next != 0 && p->next->w4 < e->w4) {
                p = p->next;
            }
            if (p == 0) {
                g->p364 = e;
            } else {
                p->next = e;
            }
            g->b360++;
            break;
        }
    }
}
/* localdecomp:end func_L39_00672DD8 */

/* localdecomp:start func_L39_00673160 */
typedef struct Ent_00673160 {
    s16 h0;
    u8 b2;
    u8 b3;
    s32 w4;
    u8 pad8[0x2C - 8];
    u8 b2C;
    u8 b2D;
    u8 pad2E[0x50 - 0x2E];
} Ent_00673160;

typedef struct Lst_00673160 {
    u8 pad0[0x20];
    struct Lst_00673160 *next;
} Lst_00673160;

typedef struct Net_00673160 {
    u8 pad0[0xC31];
    u8 bC31;
    u8 padC32[2];
    s32 wC34;
} Net_00673160;

typedef struct G_00673160 {
    u8 pad0[0x1A14];
    u8 b1A14;
    u8 pad1A15[0x2558 - 0x1A15];
    Net_00673160 *p2558;
} G_00673160;

typedef struct Ctx_00673160 {
    u8 pad0[0x364];
    Ent_00673160 *p364;
    G_00673160 *p368;
} Ctx_00673160;

extern s32 D_001A5DF8[];
extern void func_0038CC88(void *, void *, s32);

s32 func_L39_00673160(void *p, s32 a1, s32 a2, s32 a3) {
    Ctx_00673160 *a0 = p;
    u8 id = a1;
    Ent_00673160 *e;
    s32 t;

    if (a0->p364 == 0) return 0;
    e = a0->p364;
    while (e->b2 != id || (a2 != 0 && (e->b3 & 0xC) == 0)) {
        e = *(Ent_00673160 **)((u8 *)e + 0x20);
        if (e == 0) return 0;
    }
    if (e == 0 || D_001A5DF8[0] < e->w4) return 0;
    if (a0->p368->b1A14 == 0) {
        t = e->h0;
        if (t == 6 || t == 12) {
            s32 b = e->b2D;
            s32 c = e->b2C;
            if ((a0->p368->p2558->wC34 < b && b - a0->p368->p2558->wC34 < 100) ||
                (b < a0->p368->p2558->wC34 && b + 256 - a0->p368->p2558->wC34 < 100)) {
                return 0;
            }
            if (a0->p368->p2558->wC34 == b && c < a0->p368->p2558->bC31) return 0;
        }
    }
    if (*(s32 *)((u8 *)a0->p368 + 0x478 + id * 0x50) != e->h0) return 0;
    if (a3 != 0) {
        func_0038CC88((void *)a3, e, 0x50);
        *(u8 *)(a3 + 2) = id;
    }
    return e->b3;
}
/* localdecomp:end func_L39_00673160 */

/* localdecomp:start func_L39_006732D0 */
typedef struct Ent_006732D0 {
    s16 h0;
    u8 b2;
    u8 b3;
    s32 w4;
    u8 pad8[0x2C - 8];
    u8 b2C;
    u8 b2D;
    u8 pad2E[0x50 - 0x2E];
} Ent_006732D0;

typedef struct Lst_006732D0 {
    u8 pad0[0x20];
    struct Lst_006732D0 *next;
} Lst_006732D0;

typedef struct Net_006732D0 {
    u8 pad0[0xC31];
    u8 bC31;
    u8 padC32[2];
    s32 wC34;
} Net_006732D0;

typedef struct Slot_006732D0 {
    u8 pad0[0x28];
    s32 w28;
    u8 pad2C[0x50 - 0x2C];
} Slot_006732D0;

typedef struct G_006732D0 {
    u8 pad0[0x450];
    Slot_006732D0 slots[8];
    u8 pad6D0[0x1A14 - 0x6D0];
    u8 b1A14;
    u8 pad1A15[0x2558 - 0x1A15];
    Net_006732D0 *p2558;
} G_006732D0;

typedef struct Ctx_006732D0 {
    u8 pad0[0x360];
    u8 b360;
    u8 pad361[3];
    Ent_006732D0 *p364;
    G_006732D0 *p368;
} Ctx_006732D0;

extern s32 D_001A5DF8[];
extern void func_0038CC88(void *, void *, s32);
extern void func_L39_00620E28(void *, s32, s32);

s32 func_L39_006732D0(void *p, s32 a1, s32 a2, s32 a3) {
    Ctx_006732D0 *a0 = p;
    u8 id = a1;
    Ent_006732D0 *e;
    Ent_006732D0 *prev;
    s32 t;

    if (a0->p364 == 0) return 0;
    e = a0->p364;
    prev = 0;
    while (e->b2 != id || (a2 != 0 && (e->b3 & 0xC) == 0)) {
        prev = e;
        e = *(Ent_006732D0 **)((u8 *)e + 0x20);
        if (e == 0) return 0;
    }
    if (e == 0 || D_001A5DF8[0] < e->w4) return 0;
    if (a0->p368->b1A14 == 0) {
        t = e->h0;
        if (t == 6 || t == 12) {
            s32 b = e->b2D;
            s32 c = e->b2C;
            if ((a0->p368->p2558->wC34 < b && b - a0->p368->p2558->wC34 < 100) ||
                (b < a0->p368->p2558->wC34 && b + 256 - a0->p368->p2558->wC34 < 100)) {
                return 0;
            }
            if (a0->p368->p2558->wC34 == b && c < a0->p368->p2558->bC31) return 0;
        }
    }
    if (prev != 0) {
        *(Ent_006732D0 **)((u8 *)prev + 0x20) = *(Ent_006732D0 **)((u8 *)e + 0x20);
    } else {
        a0->p364 = *(Ent_006732D0 **)((u8 *)e + 0x20);
    }
    a0->b360--;
    e->b2 = 0xFF;
    if (a0->p368->b1A14 == 0) {
        if (e->b3 == 8) {
            func_L39_00620E28(a0->p368, e->h0, 1);
        }
    }
    if (a0->p368->slots[id].w28 != e->h0) return 0;
    if (a3 != 0) {
        func_0038CC88((void *)a3, e, 0x50);
        *(u8 *)(a3 + 2) = id;
    }
    return e->b3;
}
/* localdecomp:end func_L39_006732D0 */

INCLUDE_ASM("asm/levels", func_L39_00673498);

INCLUDE_ASM("asm/levels", func_L39_00673540);

/* localdecomp:start func_L39_00673A80 */
typedef union Buf_00673A80 {
    u8 b[8];
    u32 w[2];
    u16 h[4];
} Buf_00673A80;

typedef struct Ctx_00673A80 {
    u8 pad0[0x368];
    u8 *p368;
} Ctx_00673A80;

extern u8 D_L39_00483A00[];
extern void func_L39_0063E3D0(void *);

s32 func_L39_00673A80(void *p, s32 a1) {
    Ctx_00673A80 *a0 = p;
    s32 ret = 0;
    u8 *q = a0->p368 + 0x1A40;
    u16 v;

    if (*q == 0) {
        v = 0;
    } else {
        Buf_00673A80 buf;
        u32 a;
        u32 b;
        s32 n;
        s32 k;
        s32 m;
        s32 i;
        u8 *d;

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
        v = buf.h[2];
    }
    if (((s16)v >> a1) & 1) {
        func_L39_0063E3D0(a0->p368);
        ret = 1;
    }
    return ret;
}
/* localdecomp:end func_L39_00673A80 */

/* localdecomp:start func_L39_00673B68 */
typedef union Buf_00673B68 {
    u8 b[8];
    u32 w[2];
    u16 h[4];
} Buf_00673B68;

typedef struct Ent_00673B68 {
    u8 pad0[8];
    u8 b8;
    u8 pad9[0x1E - 9];
    s16 h1E;
    u8 pad20;
    s8 b21;
    u8 pad22[0x80 - 0x22];
} Ent_00673B68;

extern u8 D_L39_00483A00[];
extern u8 D_L39_00483A01[];
extern u8 D_L39_0049C340[];
extern u8 D_L39_0049C341[];
extern u32 D_L39_0024B9C8;
extern Ent_00673B68 D_L39_0049C890[];

static inline void PrepC_00673B68(u8 *q) {
    s32 t;
    if (*q == 0) {
        *q = ++D_L39_00483A00[0];
    } else {
        t = *q;
        *q = D_L39_00483A01[0];
        D_L39_00483A01[0] = t;
    }
}

static inline u16 Dec16C_00673B68(u8 *q) {
    Buf_00673B68 buf;
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

static inline void Set16C_00673B68(u8 *q, s16 v) {
    u8 *hk = q;
    Buf_00673B68 buf;
    u32 key;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    PrepC_00673B68(q);
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

static inline void PrepD_00673B68(u8 *q) {
    s32 t;
    if (*q == 0) {
        *q = ++D_L39_0049C340[0];
    } else {
        t = *q;
        *q = D_L39_0049C341[0];
        D_L39_0049C341[0] = t;
    }
}

static inline void Set16D_00673B68(u8 *q, s16 v) {
    u8 *hk = q;
    Buf_00673B68 buf;
    u32 key;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    PrepD_00673B68(q);
    key = ((u32 *)D_L39_0049C340)[((u32)hk * D_L39_0024B9C8) % 258];
    k = ((u32)q - *q) & 7;
    buf.h[2] = v;
    buf.w[0] = (u32)q ^ key;
    buf.w[1] = ((buf.w[1] & 0xFFFF) | (buf.w[1] << 16)) ^ key;
    m = *q + 1;
    d = buf.b;
    for (i = 0; i < 24; i += 3) {
        D_L39_0049C340[m + ((k + i) & 7) * 129] = *d++;
    }
}

typedef struct Rec_00673B68 {
    u8 b0;
    u8 b1;
    u8 pad2[0x10];
    u8 a12[0x10];
    u8 a22[0x10];
} Rec_00673B68;

void func_L39_00673B68(Rec_00673B68 *p, s32 b) {
    s16 v;
    s16 bit = 1 << b;
    u8 *q = &p->b1;

    Set16C_00673B68(q, bit | Dec16C_00673B68(q));
    Set16D_00673B68(&p->a22[b], 0);
    v = (D_L39_0049C890 + D_L39_0049C890[b].b21)->h1E;
    if (v != 0) {
        Set16C_00673B68(&p->a12[b], v);
    }
}
/* localdecomp:end func_L39_00673B68 */

INCLUDE_ASM("asm/levels", func_L39_00673EF0);

INCLUDE_ASM("asm/levels", func_L39_00674190);

/* localdecomp:start func_L39_00674320 */
extern u32 D_L39_002404C0;
extern u8 *func_L39_0061BFB0(u32);
void func_L39_00674320(u8 *a0) {
    if (a0[6676] == 0) {
        u32 v = *(u32 *)(*(u8 **)(*(u8 **)(a0 + 9560) + 4) + 80) ^ D_L39_002404C0;
        if (v != 0xFFFFFFFF) {
            u8 *r = func_L39_0061BFB0(v);
            if (r != 0) {
                *(s32 *)(a0 + 4216) = *(s32 *)(r + 9508);
            }
        }
    }
}
/* localdecomp:end func_L39_00674320 */
