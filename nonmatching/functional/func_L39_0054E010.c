/* functional: medium. Multiplayer-menu pawn/hero controller (state machine on object+0x20: 0 init, 1 active look/aim + hit handling, 2 wait for input release); written from the PAL assembly block by block. Retail inlines the table-decode check word (dec_0054E010), vector add/sub (vu0 vadd/vsub.xyz, w kept from the first operand) and the look-effect drop/ensure code; those are static helpers here, so the call graph is equal but 1319 words differ. Unverified: the sp+0x40 result record of func_L39_006732D0 is a byte array indexed by offset (0x26 flags, 0x2C id, 0x30/0x3C vectors); vB is zero-initialised where retail leaves stale stack when the target lookup fails; names of the player-block fields (pl+0x1A14 human flag, 0x24C9 slot, 0x2534 character record) are by offset only. */
#include "common.h"
#include "vu0.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_0054E010;

typedef void (*PlFn34_0054E010)(u8 *, s32, s32, s32, s32);
typedef u8 *(*ObjFn10_0054E010)(u8 *);

extern f32 D_L39_0024B700[];
extern f32 D_L39_0024B710[];
extern f32 D_L39_0024B720[];
extern f32 D_L39_0024B730[];
extern s32 D_L39_0024BD18;
extern f32 D_L39_0025D770;
extern u8 D_L39_002667D0[];
extern u8 D_L39_00470600[];
extern u8 D_L39_004997E0[];
extern s32 *D_L39_00241120;
extern u8 D_001A5810[];
extern u8 D_001FE020[];
extern f32 D_001DF998[];
extern f32 D_001DF9A8[];
extern f32 D_001DF9B8[];
extern f32 D_001DF9C8[];
extern s32 D_001D80E8;

extern void func_L01_00444F38(u8 *, s32, s32, s32, s32);
extern void func_00382810(s32, s32, s32, f32, f32, f32, f32);
extern void func_L01_004B14C8(s32);
extern void func_L01_00424D88(s32);
extern void func_L01_00404AD8(void *, u8 *);
extern void func_L39_0054FAB8(u8 *);
extern s32 func_L39_00620CF8(u8 *, s32);
extern void func_L01_003F6F20(s32, u8 *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
extern s32 func_L39_00639D90(u8 *);
extern s32 func_L39_005FFD20(void *, void *, f32);
extern void func_L39_005F3088(s32);
extern s32 func_L39_005F33E0(s32, s32, u8 *);
extern f32 func_0038D160(f32, f32);
extern void func_L39_0061C4D0(u8 *, void *);
extern s32 func_L39_006732D0(void *, s32, s32, void *);
extern void func_L39_00621D60(u8 *, s32);
extern s32 func_L01_003F2058(void *, void *);
extern void func_L01_003F2278(s32, void *);
extern u8 *func_L39_0061D1D8(s32);
extern void func_003C2F58(u8 *, s32, void *);
extern f32 func_0038CF00(void *, void *);
extern s32 func_L39_00550638(u8 *, void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern f32 func_L39_00632678(u8 *, void *);
extern void func_L01_00511158(u8 *, void *, void *, f32);
extern s32 func_00382348(u8 *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern void func_003C3A10(u8 *, s32, s32, s32);
extern void func_L39_0054F4E0(u8 *, void *, u8 *, s32, void *);
extern s32 func_L39_0059EA90(void *, s32, f32, f32);
extern s32 func_0038CAD0(void *);
extern s32 func_L01_0040E050(void *);

/* retail's inlined check word: 8 bytes picked from D_L39_004997E0 by the key byte at k, xored with k's address; 0 when the key is 0 */
static s32 dec_0054E010(u8 *k) {
    u8 buf[8];
    u32 *w = (u32 *)buf;
    s32 key = *k;
    s32 j;
    s32 idx;

    if (key == 0) return 0;
    for (j = 0; j < 8; j++) {
        idx = (((s32)(u32)k - key) + 5 * j) & 7;
        buf[j] = D_L39_004997E0[key + 1 + idx * 255];
    }
    w[0] ^= (u32)k;
    w[1] ^= w[0];
    return (s32)w[1];
}

static void vadd_0054E010(void *d, void *a, void *b) {
    V4_0054E010 r;
    r.x = ((V4_0054E010 *)a)->x + ((V4_0054E010 *)b)->x;
    r.y = ((V4_0054E010 *)a)->y + ((V4_0054E010 *)b)->y;
    r.z = ((V4_0054E010 *)a)->z + ((V4_0054E010 *)b)->z;
    r.w = ((V4_0054E010 *)a)->w;
    *(V4_0054E010 *)d = r;
}

static void vsub_0054E010(void *d, void *a, void *b) {
    V4_0054E010 r;
    r.x = ((V4_0054E010 *)a)->x - ((V4_0054E010 *)b)->x;
    r.y = ((V4_0054E010 *)a)->y - ((V4_0054E010 *)b)->y;
    r.z = ((V4_0054E010 *)a)->z - ((V4_0054E010 *)b)->z;
    r.w = ((V4_0054E010 *)a)->w;
    *(V4_0054E010 *)d = r;
}

/* ends the look-effect slot of the state (p+0x20) if this object owns it */
static void drop_effect_0054E010(u8 *m, u8 *p) {
    s32 id = *(s32 *)(p + 0x20);
    u8 *e;

    if (id != -1) {
        e = D_001FE020 + (id << 7);
        if (*(u8 **)(e + 0xDC) == m && e[0xD0] != 0) func_L39_005F3088(id);
    }
    *(s32 *)(p + 0x20) = -1;
}

/* starts the look-effect of kind `kind` unless this object already owns the slot's live effect */
static void ensure_effect_0054E010(u8 *m, u8 *p, s32 kind) {
    s32 id = *(s32 *)(p + 0x20);
    u8 *e;
    s32 need = 1;

    if (id != -1) {
        e = D_001FE020 + (id << 7);
        if (*(u8 **)(e + 0xDC) == m && e[0xD0] != 0) need = 0;
    }
    if (need) *(s32 *)(p + 0x20) = func_L39_005F33E0(kind, 4, m);
}

void func_L39_0054E010(u8 *m) {
    u8 *p;
    u8 *pl;
    u8 res[0x50];
    V4_0054E010 vA;
    V4_0054E010 vB;
    V4_0054E010 vC;
    V4_0054E010 vD;
    V4_0054E010 vE;
    V4_0054E010 vF;
    u8 *o;
    u8 *o2;
    u8 *x1;
    u8 *o3;
    u8 *q;
    u8 *t;
    f32 f20;
    f32 f;
    f32 ratio;
    s32 dec;
    s32 ok;
    s32 idx;
    s32 r;
    s32 flagC0;
    s32 flagCC;
    s32 flagD0;
    s32 i;
    f32 d2;

    p = *(u8 **)(m + 0x68);
    pl = *(u8 **)(p + 0x3C);
    if (m[0x42] == m[0x43] && (m[0x60] & 2) != 0) {
        func_L01_00444F38(m, 1, 0, 2, 0);
    }

    if (pl != 0 && *(s32 *)(pl + 0x474) == 3) {
        if (m[0x20] == 0) return;
        if (pl[0x1A14] != 0) {
            idx = pl[0x24C9];
            D_L39_0024B710[idx] = D_001DF998[idx];
            D_L39_0024B720[idx] = D_001DF9A8[idx];
            D_L39_0024B730[idx] = D_001DF9B8[idx];
            D_L39_0024B700[idx] = D_001DF9C8[idx];
            func_00382810(idx, 0, 3, 1.1100293f, 0.005f, 0.2f, 0.0f);
            D_001D80E8 = 0xE0;
            func_L01_004B14C8(1);
        }
        if (*(s32 *)(p + 0x10) >= 0) {
            func_L01_00424D88(*(s32 *)(p + 0x10));
        }
        *(s32 *)(p + 0x10) = -1;
        return;
    }

    if (pl != 0) {
        dec = dec_0054E010(pl + 0x19E4);
        if (dec == 0x1D && m[0x20] != 0) {
            if (pl[0x1A14] != 0) {
                *(u16 *)(m + 0x34) |= 1;
                m[0x31] = 0;
                func_L01_00404AD8((void *)func_L39_0054FAB8, m);
                if (*D_L39_00241120 == 1) D_L39_0024BD18 = 1;
            }
            if (pl[0x1A08] != 0) {
                *(s16 *)(p + 0x2C) = 0;
                *(s32 *)(p + 0x30) = 0;
            } else if (1.0f <= *(f32 *)(pl + 0x1250)) {
                *(s16 *)(p + 0x2C) = 1;
                *(s32 *)(p + 0x30) = *(s32 *)(pl + 0x122C);
            } else {
                *(s16 *)(p + 0x2C) = 0;
                *(s32 *)(p + 0x30) = 0;
            }
            if (*(s32 *)(pl + 0x2470) == 0 && *(s16 *)(p + 0x2C) != 0) {
                *(s16 *)(p + 0x2E) = (s16)(*(s16 *)(p + 0x2E) + 1);
                if (!(*(s16 *)(p + 0x2E) < 0x1A)) *(s16 *)(p + 0x2E) = 0;
                if (*(f32 *)(p + 4) <= 0.0f) {
                    if (func_L39_00620CF8(pl, -1) != 0 && *(s16 *)(p + 0x2E) >= 5 && pl[0x1A14] != 0) {
                        func_L01_003F6F20(pl[0x24C9], m, 0x200000FF, 0, 0x20, -1, 4, 0.8f, 0.0f, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
                    }
                }
            }
        } else {
            if (func_L39_00639D90(pl) != 0) {
                r = func_L39_005FFD20(pl + 0x1338, pl + 0x133C, 150.0f);
                if (pl[0x1A14] != 0) {
                    func_L01_003F6F20(pl[0x24C9], m, r, 0, 0x20, -1, 4, 0.5f, 0.0f, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
                }
            }
            if (pl[0x1A14] != 0) D_L39_0024BD18 = 0;
        }
    }

    switch (m[0x20]) {
    case 0:
        *(s16 *)p = 0;
        *(f32 *)(p + 4) = 0.36666667f;
        m[0x20] = 2;
        f = func_0038D160(1.0f, D_L39_0025D770);
        *(f32 *)(p + 8) = f + f;
        *(f32 *)(p + 0xC) = *(f32 *)(p + 8) + (0.17453292f - *(f32 *)(p + 8)) * 0.25f;
        func_L39_0061C4D0(m, p + 0x3C);
        pl = *(u8 **)(p + 0x3C);
        if (pl[0x1A14] != 0) {
            idx = pl[0x24C9];
            D_001DF998[idx] = D_L39_0024B710[idx];
            D_001DF9A8[idx] = D_L39_0024B720[idx];
            D_001DF9B8[idx] = D_L39_0024B730[idx];
            D_001DF9C8[idx] = D_L39_0024B700[idx];
        }
        *(s32 *)(p + 0x14) = 0;
        *(s32 *)(p + 0x24) = -1;
        *(s32 *)(p + 0x10) = -1;
        *(s32 *)(p + 0x20) = -1;
        *(s16 *)(p + 0x2C) = 0;
        *(s16 *)(p + 0x2E) = 0;
        *(s32 *)(p + 0x30) = 0;
        return;
    case 2:
        pl[0x1A0D] = 1;
        if (func_L01_0040E050(p + 4) != 0) {
            pl[0x1A0D] = 0;
            m[0x20] = 1;
        }
        break;
    case 1:
        flagC0 = 0;
        dec = dec_0054E010(pl + 0x19E4);
        if (dec == 1) {
            (*(PlFn34_0054E010 *)(*(u8 **)(pl + 0x14) + 0x34))(pl, 0x1D, 1, 0, 1);
        }
        ok = 0;
        dec = dec_0054E010(pl + 0x19E4);
        if (dec == 1) {
            ok = 1;
        } else {
            dec = dec_0054E010(pl + 0x19E4);
            if (dec == 0x1D || pl[0x24FE] != 0 || pl[0x2500] != 0) ok = 1;
        }
        if (ok) {
            if (*(s16 *)p == 0) {
                if (pl[0x1A14] != 0) D_001D80E8 = 0;
                *(s16 *)p = 1;
            }
        }
        if (*(s32 *)(pl + 0x3E0) != 0) *(s32 *)(pl + 0x1078) = *(s32 *)(pl + 0x3E0);

        ok = 0;
        dec = dec_0054E010(pl + 0x19E4);
        if (dec == 1) {
            ok = 1;
        } else {
            dec = dec_0054E010(pl + 0x19E4);
            if (dec == 0x1D || pl[0x24FE] != 0 || pl[0x2500] != 0) ok = 1;
        }
        if (ok) {
            q = *(u8 **)(pl + 0x2534);
            if (D_001A5810[*(s32 *)(pl + 0x2544) + 0xA4] != 0) {
                f20 = -*(f32 *)(q + 0x10C);
            } else {
                f20 = *(f32 *)(q + 0x134);
                if (f20 < *(f32 *)(q + 0x13C)) f20 = -*(f32 *)(q + 0x13C);
            }
            f = f20;
            if (f < 0.0f) f = -f;
            if (1.0f <= f) f20 = f20 + f20;
            if (0.0f < f20) {
                if (0.17453292f < *(f32 *)(p + 0xC)) {
                    ensure_effect_0054E010(m, p, 2);
                    *(f32 *)(p + 0xC) = *(f32 *)(p + 0xC) - f20 * 0.02f;
                } else {
                    drop_effect_0054E010(m, p);
                }
            } else if (f20 < 0.0f) {
                if (*(f32 *)(p + 0xC) < *(f32 *)(p + 8)) {
                    ensure_effect_0054E010(m, p, 3);
                    *(f32 *)(p + 0xC) = *(f32 *)(p + 0xC) - f20 * 0.02f;
                } else {
                    drop_effect_0054E010(m, p);
                }
            } else {
                drop_effect_0054E010(m, p);
            }
            if (*(f32 *)(p + 8) < *(f32 *)(p + 0xC)) {
                *(f32 *)(p + 0xC) = *(f32 *)(p + 8);
            } else if (*(f32 *)(p + 0xC) < 0.17453292f) {
                *(f32 *)(p + 0xC) = 0.17453292f;
            }
            if (pl[0x1A14] != 0) {
                func_00382810(pl[0x24C9], 0, 3, *(f32 *)(p + 0xC), 0.02f, 0.2f, 0.0f);
                func_L01_004B14C8(0);
            }
            *(f32 *)(*(u8 **)(p + 0x3C) + 0x12C0) = 200.0f;
            *(u16 *)(*(u8 **)(p + 0x3C) + 0x1280) |= 0x20;
        } else {
            drop_effect_0054E010(m, p);
            if (*(s16 *)p != 0) {
                *(f32 *)(p + 0xC) = *(f32 *)(p + 8) + (0.17453292f - *(f32 *)(p + 8)) * 0.25f;
                if (pl[0x1A14] != 0) {
                    func_00382810(pl[0x24C9], 0, 3, *(f32 *)(p + 8), 0.005f, 0.2f, 0.0f);
                }
                *(s16 *)p = 0;
                if (pl[0x1A14] != 0) {
                    D_001D80E8 = 0xE0;
                    func_L01_004B14C8(1);
                }
            }
            *(f32 *)(*(u8 **)(p + 0x3C) + 0x12C0) = 75.0f;
            *(u16 *)(*(u8 **)(p + 0x3C) + 0x1280) &= 0xFFDF;
        }

        ratio = (*(f32 *)(p + 0xC) - 0.17453292f) / (*(f32 *)(p + 8) - 0.17453292f);
        if (pl[0x1A14] != 0) {
            idx = pl[0x24C9];
            D_L39_0024B710[idx] = (D_001DF998[idx] - 0.03f) * ratio + 0.03f;
            idx = pl[0x24C9];
            D_L39_0024B720[idx] = (D_001DF9A8[idx] - 0.4f) * ratio + 0.4f;
            idx = pl[0x24C9];
            D_L39_0024B700[idx] = (D_001DF9C8[idx] - 0.010471975f) * ratio + 0.010471975f;
        }
        r = func_L39_006732D0(pl + 0x1A40, 0, 1, res);
        if (r == 8) {
            func_L39_00621D60(pl, -1);
            *(s32 *)(p + 0x24) = func_L01_003F2058(D_L39_00470600, *(void **)(pl + 0x2534));
            o = func_L39_0061D1D8(*(s32 *)(res + 0x2C));
            o2 = 0;
            if (o != 0) o2 = (*(ObjFn10_0054E010 *)(*(u8 **)(o + 0x14) + 0x10))(o);
            x1 = 0;
            if (o != 0 && (o[3] & 0xF) == 0) x1 = o;
            o3 = 0;
            if (o != 0 && (o[3] & 0xF) == 3) o3 = o;
            flagD0 = 0;
            vB.x = 0.0f; vB.y = 0.0f; vB.z = 0.0f; vB.w = 0.0f;
            if (pl[0x1A14] == 0) {
                func_003C2F58(m, 0, &vA);
                f20 = 0.0f;
                if (o2 != 0) f20 = func_0038CF00(&vA, o2 + 0x10);
                if ((res[0x26] & 0x40) != 0) flagCC = (o2 != 0);
                else flagCC = 1;
                if ((res[0x26] & 0x80) != 0) {
                    if (func_L39_00550638(m, &vA) == 0) {
                        flagD0 = 1;
                        vA.x = *(f32 *)(res + 0x30);
                        vA.y = *(f32 *)(res + 0x34);
                        vA.z = *(f32 *)(res + 0x38);
                        vA.w = 0.0f;
                    }
                }
                if (o2 == 0 || o2[0x20] == 0xFE || o2[0x20] == 0xFD || 190.0f < f20) {
                    if (pl[0x1A08] == 1) {
                        func_0038CF68(p + 0x40, m + 0xD0, -1.0f);
                    } else if ((res[0x26] & 0x40) != 0) {
                        if (o2 != 0 && *(s32 *)(res + 0x2C) != -1) {
                            vB.x = *(f32 *)(res + 0x3C);
                            vB.y = *(f32 *)(res + 0x40);
                            vB.z = *(f32 *)(res + 0x44);
                            vB.w = 0.0f;
                            vadd_0054E010(p + 0x40, o2 + 0x10, &vB);
                        } else {
                            *(f32 *)(p + 0x40) = *(f32 *)(res + 0x3C);
                            *(f32 *)(p + 0x44) = *(f32 *)(res + 0x40);
                            *(f32 *)(p + 0x48) = *(f32 *)(res + 0x44);
                            *(s32 *)(p + 0x4C) = 0;
                        }
                        vsub_0054E010(p + 0x40, p + 0x40, &vA);
                        func_0038CF68(p + 0x40, p + 0x40, 1.0f);
                    } else {
                        *(f32 *)(p + 0x40) = *(f32 *)(res + 0x3C);
                        *(f32 *)(p + 0x44) = *(f32 *)(res + 0x40);
                        *(f32 *)(p + 0x48) = *(f32 *)(res + 0x44);
                        *(s32 *)(p + 0x4C) = 0;
                    }
                } else {
                    if ((res[0x26] & 0x40) != 0) {
                        vB.x = *(f32 *)(res + 0x3C);
                        vB.y = *(f32 *)(res + 0x40);
                        vB.z = *(f32 *)(res + 0x44);
                        vB.w = 0.0f;
                        vadd_0054E010(&vB, &vB, o2 + 0x10);
                    } else {
                        t = (u8 *)func_00382348(o2);
                        if (t != 0) {
                            if (x1 != 0) {
                                f = *(f32 *)(t + 0x10);
                                dec = dec_0054E010(x1 + 0x19E6);
                                if (dec == 0xC) f = f - 0.1f;
                                else f = f + 0.5f;
                                func_L01_00511158(x1, &vB, o2 + 0x10, f);
                            } else {
                                vB = *(V4_0054E010 *)(o2 + 0x10);
                                vB.z = vB.z + *(f32 *)(t + 0x10);
                            }
                        }
                    }
                    if (flagD0 == 0) {
                        if (func_003D3CB0(&vA, &vB, 2, 0, 0) != 0) {
                            vD.x = *(f32 *)(res + 0x30);
                            vD.y = *(f32 *)(res + 0x34);
                            vD.z = *(f32 *)(res + 0x38);
                            vD.w = 0.0f;
                            vsub_0054E010(&vC, &vD, &vA);
                            f = func_L39_00632678(pl, &vC);
                            func_L01_00511158(pl, &vA, &vA, f);
                        }
                    }
                    if (x1 != 0) vE = *(V4_0054E010 *)(x1 + 0x170);
                    else if (o3 != 0) vE = *(V4_0054E010 *)(o3 + 0x270);
                    else {
                        vE.x = 0.0f; vE.y = 0.0f; vE.z = 0.0f; vE.w = 0.0f;
                    }
                    i = (s32)(f20 / 32.000004f + 0.9f);
                    flagC0 = 1;
                    func_0038CE20(&vE, &vE, (f32)i);
                    vadd_0054E010(&vF, &vB, &vE);
                    vsub_0054E010(&vC, &vF, &vA);
                    func_0038CF68(p + 0x40, &vC, 1.0f);
                    d2 = func_0038CE68(p + 0x40, m + 0xD0);
                    if (0.4f < d2) {
                        func_0038CF68(p + 0x40, m + 0xD0, -1.0f);
                        flagC0 = 0;
                        func_003C2F58(m, 0, &vA);
                    }
                }
            } else {
                *(f32 *)(p + 0x40) = *(f32 *)(res + 0x3C);
                *(f32 *)(p + 0x44) = *(f32 *)(res + 0x40);
                *(f32 *)(p + 0x48) = *(f32 *)(res + 0x44);
                *(s32 *)(p + 0x4C) = 0;
                vA.x = *(f32 *)(res + 0x30);
                vA.y = *(f32 *)(res + 0x34);
                vA.z = *(f32 *)(res + 0x38);
                vA.w = 0.0f;
                flagCC = ((res[0x26] & 0x40) != 0);
            }
            func_003C3A10(m, 2, 0, 0);
            drop_effect_0054E010(m, p);
            func_L39_005F33E0(0, 0, m);
            func_L39_0054F4E0(m, &vA, o2, flagCC, flagC0 != 0 ? (void *)&vF : 0);
        } else if (r == 4) {
            func_L39_005F33E0(1, 0, m);
        }
        if (r != 8 || pl[0x1A07] == 0) {
            if (*(s32 *)(p + 0x24) >= 0) {
                func_L01_003F2278(*(s32 *)(p + 0x24), *(void **)(pl + 0x2534));
                *(s32 *)(p + 0x24) = -1;
            }
        }
        break;
    default:
        break;
    }

    if (*(s32 *)(p + 0x14) == 0) return;
    if (func_0038CAD0(p + 0x14) != 0) {
        if (*(s32 *)(p + 0x10) >= 0) func_L01_00424D88(*(s32 *)(p + 0x10));
        *(s32 *)(p + 0x10) = -1;
        return;
    }
    if (*(s32 *)(p + 0x10) == -1) {
        *(s32 *)(p + 0x10) = func_L39_0059EA90(m + 0x10, 0xFF0000FF, 10.0f, 0.0f);
    }
    if (*(s32 *)(p + 0x10) < 0) return;
    if (pl[0x1A08] == 1) {
        func_003C2F58(m, 0, &vE);
        func_0038CF68(&vF, m + 0xD0, -1.5f);
    } else {
        func_003C2F58(m, 0, &vE);
        func_0038CF68(&vF, pl + 0x3B0, 1.5f);
    }
    i = *(s32 *)(p + 0x10);
    vadd_0054E010(D_L39_002667D0 + (i << 5), &vE, &vF);
    *(f32 *)(D_L39_002667D0 - 0x10 + (i << 5) + 0x1C) = 10.0f;
    f = (f32)*(s32 *)(p + 0x14) / 25.0f;
    *(f32 *)(D_L39_002667D0 - 0x10 + (i << 5) + 4) = f;
    *(f32 *)(D_L39_002667D0 - 0x10 + (i << 5)) = f * 0.75f;
    *(s32 *)(D_L39_002667D0 - 0x10 + (i << 5) + 8) = 0;
}
