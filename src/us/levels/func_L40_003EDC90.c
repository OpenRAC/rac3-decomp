#include "common.h"

/* NTSC-U counterpart of func_L40_003EE130 (src/levels/shared/L40_003EE130.c): 26 -> 31 */
extern s32 D_001A5F78[];
extern void *func_L39_006699B0(void);
extern s32 func_L39_00669978(s32, void *, s32, void *, void *);

/* localdecomp:start func_L40_003EDC90 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_003EE130;

typedef struct {
    u8 b[16];
} B_003EE130;

typedef struct {
    s32 f0;
    u8 *ent;
    u8 pad[0xC68];
} P_003EE130;

extern P_003EE130 D_L40_0022F550[];
extern u8 *D_L40_0025BB18[];
extern s32 D_L40_002412AC;
extern s32 *D_L40_0028FF00[];
extern u8 D_L40_003BFF60[];

extern u8 *func_L39_00619838(u32);
extern f32 func_L01_0040C040(void *, void *);
extern f32 func_00388800(void *, void *);
extern s32 func_L40_0053B8F8(void *, s32, s32, s32, f32, f32, f32);
extern u8 *func_L40_0053BEB0(s32, void *, s32, s32);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern int func_L39_005BCB50(void *, void *, void *);
extern s32 func_L39_005B2498(s32);
extern s32 func_L39_005B24C8(s32, s32);
extern void func_L40_003EDB68(u8 *);
extern void func_L40_003F1538(V_003EE130 *);

void func_L40_003EDC90(u8 *a0) {
    u8 *v;
    s32 uid;
    f32 best;
    s32 idx;
    s32 target;
    s32 found;
    s32 i;
    V_003EE130 out;
    V_003EE130 pos;

    if (a0 == 0) {
        return;
    }
    v = *(u8 **)(a0 + 0x68);
    uid = **(s32 **)(a0 + 0x90);
    if (v[0x33D] == 0) {
        best = 99999.0f;
        idx = -1;
        if (*(s32 *)(v + 0x300) == 0) {
            *(s32 *)(v + 0x304) = -1;
            *(s32 *)(v + 0x300) = 1;
            *(s32 *)(v + 0x308) = -1;
        }
        switch (*(s32 *)(v + 0x300)) {
        case 1: {
            P_003EE130 *e;
            u8 *p;
            u8 *q;
            for (i = 0; i < 8; i++) {
                u8 *ent = D_L40_0022F550[i].ent;
                u8 *pl;
                u8 *m;
                f32 d;
                if (ent == 0) {
                    continue;
                }
                pl = func_L39_00619838(*(s32 *)(ent + 0x38));
                if (pl == 0) {
                    continue;
                }
                m = *(u8 **)(pl + 0x2558);
                if (m != 0) {
                    out = *(V_003EE130 *)(m + 0x180);
                } else {
                    out = *(V_003EE130 *)(*(u8 **)(pl + 0x2524) + 0x10);
                }
                d = func_L01_0040C040(a0 + 0x10, &out);
                if (d <= best) {
                    if (*(s32 *)(v + 0x2C0) == -1 ||
                        *(s32 *)(D_L40_0022F550[i].ent + 0x40) == *(s32 *)(v + 0x2C0)) {
                        best = d;
                        idx = i;
                    }
                }
            }
            if (!(best < 400.0f)) {
                return;
            }
            p = func_L39_006699B0();
            if (p == 0) {
                return;
            }
            q = p + func_L39_00669978(1, (void *)uid, D_001A5F78[0] + 0x1F4, 0, p);
            e = &D_L40_0022F550[idx];
            *(s32 *)q = *(s32 *)(e->ent + 0x38);
            q += 4;
            *(s32 *)(v + 0x304) = *(s32 *)(e->ent + 0x38);
            *(s32 *)p = q - p;
            *(s32 *)(v + 0x300) = 0x17;
            break;
        }
        case 2: {
            u8 *p;
            u8 *q;
            p = func_L39_006699B0();
            if (p == 0) {
                return;
            }
            q = p + func_L39_00669978(1, (void *)uid, D_001A5F78[0] + 0x1F4, 0, p);
            *(s32 *)q = *(s32 *)(v + 0x26C);
            q += 4;
            *(s32 *)(v + 0x304) = *(s32 *)(v + 0x26C);
            *(s32 *)p = q - p;
            *(s32 *)(v + 0x300) = 0x17;
            break;
        }
        case 23: {
            u8 *pl;
            u8 *m;
            u8 *p;
            u8 *q;
            if (a0[0x20] == 0x18) {
                *(s32 *)(v + 0x300) = 0x18;
            }
            target = -1;
            pl = func_L39_00619838(*(s32 *)(v + 0x304));
            if (pl != 0 && *(u8 **)(pl + 0x2558) != 0) {
                target = func_L40_0053B8F8(a0, *(s32 *)(*(u8 **)(*(u8 **)(pl + 0x2558) + 4) + 0x40), 1, 0,
                                           43.0f, -1.0f, 30.0f);
            }
            if (++*(s32 *)(v + 0x2F8) >= 61) {
                *(s32 *)(v + 0x2F8) = 0;
            }
            found = 0;
            if (target != -1) {
                m = func_L40_0053BEB0(target, &out, -1, 1);
                if (m != 0) {
                    pos = *(V_003EE130 *)(a0 + 0x10);
                    pos.z += 0.5f;
                    out.z += 0.1f;
                    if (func_003CE740(&pos, &out, 0x10, a0, 0) == 0 ||
                        (D_L40_0025BB18[0] != 0 && D_L40_0025BB18[0] == m)) {
                        found = 1;
                    } else {
                        target = -1;
                    }
                }
            }
            if (target != -1 && found) {
                p = func_L39_006699B0();
                if (p == 0) {
                    return;
                }
                q = p + func_L39_00669978(1, (void *)uid, D_001A5F78[0] + 0x1F4, (void *)1, p);
                *(s32 *)q = target;
                q += 4;
                *(s32 *)p = q - p;
                *(s32 *)(v + 0x2A4) = target;
                *(s32 *)(v + 0x300) = 0xC;
                return;
            }
            pl = func_L39_00619838(*(s32 *)(v + 0x304));
            if (pl == 0) {
                return;
            }
            {
                u8 *g = *(u8 **)(pl + 0x2528);
                if (g == 0) {
                    return;
                }
                if (*(s16 *)(g + 0x2FC) == 2) {
                    return;
                }
            }
            p = func_L39_006699B0();
            if (p == 0) {
                return;
            }
            *(s32 *)p = func_L39_00669978(1, (void *)uid, D_001A5F78[0] + 0x1F4, (void *)4, p);
            *(s32 *)(v + 0x300) = 0x1B;
            break;
        }
        case 12: {
            u8 *pl;
            u8 *m;
            u8 *p;
            u8 *q;
            if (++*(s32 *)(v + 0x2F0) >= 31) {
                *(s32 *)(v + 0x2F0) = 0;
                target = -1;
                pl = func_L39_00619838(*(s32 *)(v + 0x304));
                if (pl != 0 && *(u8 **)(pl + 0x2558) != 0) {
                    target = func_L40_0053B8F8(a0, *(s32 *)(*(u8 **)(*(u8 **)(pl + 0x2558) + 4) + 0x40), 1, 0,
                                               48.0f, -1.0f, 30.0f);
                }
                if (++*(s32 *)(v + 0x2F8) >= 61) {
                    *(s32 *)(v + 0x2F8) = 0;
                }
                if (*(s32 *)(v + 0x2A4) != target) {
                    found = 0;
                    if (target != -1) {
                        m = func_L40_0053BEB0(target, &out, -1, 1);
                        if (m != 0) {
                            pos = *(V_003EE130 *)(a0 + 0x10);
                            pos.z += 0.5f;
                            out.z += 0.1f;
                            if (func_003CE740(&pos, &out, 0x10, a0, 0) == 0 ||
                                (D_L40_0025BB18[0] != 0 && D_L40_0025BB18[0] == m)) {
                                found = 1;
                            } else {
                                target = -1;
                            }
                        }
                    }
                    if (found || target == -1) {
                        p = func_L39_006699B0();
                        if (p == 0) {
                            return;
                        }
                        q = p + func_L39_00669978(1, (void *)uid, D_001A5F78[0] + 0x1F4, (void *)1, p);
                        *(s32 *)q = target;
                        q += 4;
                        *(s32 *)p = q - p;
                        *(s32 *)(v + 0x300) = 0xC;
                        *(s32 *)(v + 0x2A4) = target;
                    }
                } else {
                    if ((D_L40_002412AC & 0x3F) == (((s32)a0 >> 8) & 0x3F) &&
                        func_L40_0053BEB0(target, &out, -1, 1) != 0 &&
                        func_L39_005BCB50(a0 + 0x10, &out, 0) == 0) {
                        target = -1;
                        p = func_L39_006699B0();
                        if (p == 0) {
                            return;
                        }
                        q = p + func_L39_00669978(1, (void *)uid, D_001A5F78[0] + 0x1F4, (void *)1, p);
                        *(s32 *)q = target;
                        q += 4;
                        *(s32 *)p = q - p;
                        *(s32 *)(v + 0x300) = 0xC;
                        *(s32 *)(v + 0x2A4) = target;
                    }
                }
                if (target == -1) {
                    *(s32 *)(v + 0x300) = 0x17;
                }
            }
            pl = func_L39_00619838(*(s32 *)(v + 0x304));
            if (pl == 0) {
                return;
            }
            {
                u8 *g = *(u8 **)(pl + 0x2528);
                if (g == 0) {
                    return;
                }
                if (*(s16 *)(g + 0x2FC) == 2) {
                    return;
                }
            }
            p = func_L39_006699B0();
            if (p == 0) {
                return;
            }
            *(s32 *)p = func_L39_00669978(1, (void *)uid, D_001A5F78[0] + 0x1F4, (void *)4, p);
            *(s32 *)(v + 0x300) = 0x1B;
            break;
        }
        case 27: {
            u8 *pl;
            u8 *p;
            u8 *q;
            s32 x;
            f32 f;
            f32 zero;
            s32 ok;
            s32 r;
            f32 fr;
            u8 *src;

            pl = func_L39_00619838(*(s32 *)(v + 0x304));
            if (pl == 0) {
                return;
            }
            if (*(u8 **)(pl + 0x2528) != 0) {
                return;
            }
            {
                u8 *b;
                u8 *pp = pl + 0x19E4;
                long t;
                x = 0;
                t = *pp;
                if (t != 0) {
                    s32 mm, k, j;
                    s32 n = *pp;
                    mm = n + 1;
                    k = ((s32)pp - n) & 7;
                    b = (u8 *)&out;
                    for (j = 0; j < 40; j += 5) {
                        *b++ = D_L40_003BFF60[mm + ((k + j) & 7) * 255];
                    }
                    ((u32 *)&out)[0] ^= (u32)pp;
                    ((u32 *)&out)[1] ^= ((u32 *)&out)[0];
                    x = ((u32 *)&out)[1];
                }
            }
            if ((x ^ 0x39) == 0) {
                return;
            }
            {
                u8 *b;
                u8 *pp = pl + 0x2476;
                long t;
                t = *pp;
                zero = 0.0f;
                if (t == 0) {
                    f = zero;
                } else {
                    s32 mm, k, j;
                    s32 n = *pp;
                    mm = n + 1;
                    k = ((s32)pp - n) & 7;
                    b = (u8 *)&out;
                    for (j = 0; j < 40; j += 5) {
                        *b++ = D_L40_003BFF60[mm + ((k + j) & 7) * 255];
                    }
                    ((u32 *)&out)[0] ^= (u32)pp;
                    ((u32 *)&out)[1] ^= ((u32 *)&out)[0];
                    f = out.y;
                }
            }
            ok = f > zero;
            if (!(u8)ok) {
                return;
            }
            p = func_L39_006699B0();
            if (p == 0) {
                return;
            }
            q = p + func_L39_00669978(1, (void *)uid, D_001A5F78[0] + 0x1F4, (void *)5, p);
            fr = func_L39_005B24C8(3, 7);
            r = func_L39_005B24C8(3, 7);
            src = *(u8 **)(pl + 0x2524);
            {
                f32 px = fr + *(f32 *)(src + 0x10);
                f32 py = (f32)r + *(f32 *)(src + 0x14);
                f32 pz = *(f32 *)(src + 0x18);
                *(f32 *)q = px;
                q += 4;
                *(f32 *)q = py;
                q += 4;
                *(f32 *)q = pz;
                q += 4;
            }
            *(s32 *)p = q - p;
            *(s32 *)(v + 0x300) = 7;
            break;
        }
        case 24:
            if (a0[0x20] == 0x18) {
                return;
            }
            /* fallthrough */
        case 7:
            *(s32 *)(v + 0x300) = 0x17;
            break;
        }
    } else {
        s32 st;
        if (*(s32 *)(v + 0x300) == 0) {
            *(s32 *)(v + 0x300) = 1;
        }
        st = *(s32 *)(v + 0x300);
        switch (st) {
        case 1:
            if (*(s32 *)(v + 0x2C0) != -1) {
                u8 *p;
                u8 *q;
                target = func_L40_0053B8F8(a0, *(s32 *)(v + 0x2C0), 1, 0, 35.0f, -1.0f, 30.0f);
                if (target == -1) {
                    return;
                }
                p = func_L39_006699B0();
                if (p == 0) {
                    return;
                }
                q = p + func_L39_00669978(1, (void *)uid, D_001A5F78[0] + 0x1F4, (void *)1, p);
                *(s32 *)q = target;
                q += 4;
                *(s32 *)p = q - p;
                *(s32 *)(v + 0x2A4) = target;
                *(s32 *)(v + 0x300) = 0xC;
            } else {
                u8 *p;
                u8 *q;
                if (func_L39_005B2498(2500000 - 1) == 0) {
                    func_L40_003EDB68(a0);
                }
                if (*(s32 *)(v + 0x2B0) == 0) {
                    return;
                }
                *(s32 *)(v + 0x2B0) = 0;
                p = func_L39_006699B0();
                if (p == 0) {
                    return;
                }
                q = p + func_L39_00669978(1, (void *)uid, D_001A5F78[0] + 0x1F4, (void *)7, p);
                *(B_003EE130 *)q = *(B_003EE130 *)(v + 0x390);
                q += 0x10;
                *(s32 *)p = q - p;
                out = *(V_003EE130 *)(v + 0x390);
                func_L40_003F1538(&out);
            }
            break;
        case 12: {
            s32 *path;
            u8 *p;
            u8 *q;
            s32 tg;
            path = 0;
            if (*(s32 *)(v + 0x2B8) != -1) {
                path = D_L40_0028FF00[*(s32 *)(v + 0x2B8)];
            }
            tg = func_L40_0053B8F8(a0, *(s32 *)(v + 0x2C0), 1, 0, 42.0f, -1.0f, 30.0f);
            if (*(s32 *)(v + 0x2A4) != tg) {
                p = func_L39_006699B0();
                if (p == 0) {
                    return;
                }
                q = p + func_L39_00669978(1, (void *)uid, D_001A5F78[0] + 0x1F4, (void *)1, p);
                *(s32 *)q = tg;
                q += 4;
                *(s32 *)p = q - p;
                *(s32 *)(v + 0x300) = st;
                *(s32 *)(v + 0x2A4) = tg;
            }
            if (tg == -1) {
                *(s32 *)(v + 0x300) = 1;
                return;
            }
            idx = *(s32 *)(v + 0x30C);
            if (*(s32 *)(v + 0x2B8) == -1) {
                return;
            }
            if (func_00388800(a0 + 0x10, (u8 *)path + (idx * 16 + 16)) < 0.5f) {
                s32 j;
                best = 99999.0f;
                if (func_L40_0053BEB0(*(s32 *)(v + 0x2A4), &out, -1, 1) == 0) {
                    return;
                }
                for (j = 0; j < path[0]; j++) {
                    f32 d = func_00388800(&out, (u8 *)path + j * 16 + 16);
                    if (d < best) {
                        best = d;
                        idx = j;
                    }
                }
            }
            if (*(s32 *)(v + 0x2B8) == -1) {
                return;
            }
            if (idx == *(s32 *)(v + 0x30C)) {
                return;
            }
            *(s32 *)(v + 0x30C) = idx;
            p = func_L39_006699B0();
            if (p == 0) {
                return;
            }
            q = p + func_L39_00669978(1, (void *)uid, D_001A5F78[0] + 0x1F4, (void *)3, p);
            *(s32 *)q = idx;
            q += 4;
            *(s32 *)p = q - p;
            break;
        }
        }
    }
}
/* localdecomp:end func_L40_003EDC90 */
