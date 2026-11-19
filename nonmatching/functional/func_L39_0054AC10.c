/* functional: medium. Spawns a multiplayer-menu homing projectile object (allocated with func_003C24B0 size 0x108C): picks its owner slot from the rolling counter at D_L39_0024B078 (mod 0xC0), registers it in the per-owner table D_L39_003BDD20_0054AC10, aims it at the target object (or along dir), randomises its spin/wobble, adjusts its speed scale from the target player's latency (func_0014AA48, opaque here, called as in retail) and distance, sweeps once with func_003D3CB0 and snaps to the hit point. Returns the new object, or 0. */
typedef int q128_0054AC10 __attribute__((mode(TI)));
extern u8 D_L39_004997E0[];
extern u8 D_L39_0049C890_0054AC10[];
extern u8 *D_L39_0024CE20[8] __attribute__((section(".sdata")));
extern f32 D_L39_0025F760[4];
extern s32 D_L39_003BDD20_0054AC10[];
extern u8 D_L39_003BE020[];
extern s16 D_L39_0024C040[];
extern s32 D_L39_002429BC;
__asm__(".extern D_L39_0024B078, 4");
extern s32 D_L39_0024B078;

extern u8 *func_003C24B0(s32, s32);
extern s32 func_L39_00648AE0(void *, s32);
extern void func_L39_0054AB58(s32);
extern u8 *func_L39_0061D7B0(s32);
extern f32 func_0038CF00(void *, void *);
extern void func_0014AA48(s32 *, s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_0038CE68(void *, void *);
extern f32 func_L39_005B4410(f32, f32);
extern f32 func_L39_005B4468(f32, f32);
extern f32 func_L39_005B44C8(void);
extern void func_L39_005FFB78(void *, void *, void *, f32, f32, f32);
extern f32 *func_00382348(void *);
extern void func_L39_005BC330(void *, void *, s32);
extern void func_L39_005FFDF8(s32);
extern void func_L39_005FFE78(void);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_L01_00399D78(void *, void *);
extern void func_003C7C38(void *);
extern void func_L01_0044BE50(void *, short *, short);
extern s32 func_L39_005FF538(void *, s32, f32, f32, f32);

typedef union {
    u8 b[8];
    u32 w[2];
} Buf_0054AC10;

static __inline__ u32 decode_0054AC10(u8 *p) {
    Buf_0054AC10 buf;
    s32 n;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    if (*p == 0) {
        return 0;
    }
    n = *p;
    k = ((u32)p - n) & 7;
    m = n + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
    }
    buf.w[0] ^= (u32)p;
    buf.w[1] ^= buf.w[0];
    return buf.w[1];
}

/* owner has a valid network slot record: not the 0x92 mode, record present and its +4 word set */
static __inline__ s32 slot_ok_0054AC10(u8 *p) {
    u8 *rec;
    if (p == 0) {
        return 0;
    }
    if (decode_0054AC10(p + 0x19E4) == 0x92) {
        return 0;
    }
    rec = *(u8 **)(p + 0x2558);
    if (rec == 0) {
        return 0;
    }
    return *(s32 *)(rec + 4) != 0;
}

u8 *func_L39_0054AC10(u8 *src, f32 *dir, u8 *tgt, f32 *pos, u8 *g, s32 slot, f32 off, f32 f13) {
    f32 pos0[4] __attribute__((aligned(16)));
    f32 v10[4] __attribute__((aligned(16)));
    f32 v20[4] __attribute__((aligned(16)));
    f32 v30[4] __attribute__((aligned(16)));
    s32 tmp40;
    u8 *obj;
    u8 *ex;
    u8 *cfg;
    u8 *pl;
    u8 *ent;
    u8 *rec;
    f32 *hp;
    f32 f22, f24, f21, f20, f2, f3, f0;
    s32 v;
    s32 id;
    s32 hit;
    f32 lat;
    u32 ut;

    *(q128_0054AC10 *)pos0 = *(q128_0054AC10 *)pos;
    if (g == 0) {
        return 0;
    }
    obj = func_003C24B0(0x108C, 0x80);
    if (obj == 0) {
        return obj;
    }
    obj[0x30] = 0xFF;
    obj[0x31] = 1;
    obj[0x20] = 0;
    *(u16 *)(obj + 0x32) = 0xFF;
    *(u16 *)(obj + 0x34) |= 0x100;
    ex = *(u8 **)(obj + 0x68);
    *(u8 **)(obj + 0xB8) = src;
    if (!((u32)D_L39_0024B078 < 0xC1)) {
        D_L39_0024B078 = 0;
    }
    v = D_L39_0024B078;
    *(s32 *)(ex + 0x2C) = v;
    D_L39_0024B078 = (v + 1) % 0xC0;
    *(u8 **)(ex + 0x58) = g;
    *(s32 *)(obj + 0x90) = *(s32 *)g;
    if (func_L39_00648AE0(g, 4) != 0) {
        cfg = D_L39_0049C890_0054AC10 + ((s8)D_L39_0049C890_0054AC10[0x221] << 7);
    } else {
        cfg = D_L39_0049C890_0054AC10 + 0x200;
    }
    f22 = *(f32 *)(cfg + 0x24) * 0.0200000014f;
    *(s32 *)(ex + 0x64) = -1;
    *(s32 *)(ex + 0x68) = -1;
    if (g[0x1A14] != 0) {
        func_L39_0054AB58(slot);
    }
    f24 = f13 * f13;
    if (tgt != 0) {
        pl = 0;
        ent = func_L39_0061D7B0((s32)tgt);
        if (ent != 0) {
            if ((ent[3] & 0xF) == 0) {
                pl = ent;
            }
        }
        if (pl == 0) {
            *(q128_0054AC10 *)(obj + 0x10) = *(q128_0054AC10 *)dir;
        } else {
            if (slot_ok_0054AC10(g) && slot != -1) {
                rec = *(u8 **)(g + 0x2558);
                *(s32 *)(ex + 0x64) = slot;
                *(s32 *)(ex + 0x68) = *(s32 *)rec;
                *(u8 **)((u8 *)D_L39_003BDD20_0054AC10 + slot * 4 + *(s32 *)rec * 0x60) = obj;
            }
            if (pl[0x1A14] != 0) {
                ex[0x6D] = 1;
                *(q128_0054AC10 *)(obj + 0x10) = *(q128_0054AC10 *)dir;
            } else if (!slot_ok_0054AC10(pl)) {
                *(q128_0054AC10 *)(obj + 0x10) = *(q128_0054AC10 *)dir;
            } else {
                f20 = func_0038CF00(pl + 0xA0, dir);
                f21 = 6.0f;
                if (f21 < f20) {
                    rec = *(u8 **)(pl + 0x2558);
                    tmp40 = 0;
                    func_0014AA48(&tmp40, *(s32 *)rec);
                    rec = *(u8 **)(pl + 0x2558);
                    f2 = f21 / f20;
                    f0 = (f32)(*(s32 *)(rec + 0xC38) << 2) * 20.0f;
                    f3 = f2 * 3.0f;
                    tmp40 = tmp40 + (s32)f0;
                    if (3.0f < f3) {
                        f3 = 3.0f;
                    }
                    ut = (u32)tmp40;
                    if ((s32)ut < 0) {
                        lat = (f32)((ut >> 1) | (ut & 1));
                        lat = lat + lat;
                    } else {
                        lat = (f32)(s32)ut;
                    }
                    f0 = (lat * 50.0f) / 1000.0f + f3;
                    f2 = f0 / f20;
                    if (0.600000024f / f22 < f2) {
                        ex[0x6F] = 1;
                    }
                    f0 = 0.649999976f / f22;
                    if (f0 < f2) {
                        f2 = f0;
                    }
                    f22 = 1.0f / (1.0f / f22 + f2);
                } else {
                    ex[0x6F] = 1;
                }
                *(q128_0054AC10 *)(obj + 0x10) = *(q128_0054AC10 *)dir;
            }
        }
    } else {
        *(q128_0054AC10 *)(obj + 0x10) = *(q128_0054AC10 *)dir;
    }

    if (tgt != 0) {
        func_0038CE20(v20, tgt + 0xE0, off);
        v10[0] = *(f32 *)(tgt + 0x10) + v20[0];
        v10[1] = *(f32 *)(tgt + 0x14) + v20[1];
        v10[2] = *(f32 *)(tgt + 0x18) + v20[2];
        v10[3] = *(f32 *)(tgt + 0x1C);
    } else {
        v10[0] = 0.0f;
        v10[1] = 0.0f;
        v10[2] = 0.0f;
        v10[3] = 0.0f;
    }
    if (tgt != 0) {
        *(f32 *)(obj + 0xC0) = v10[0] - *(f32 *)(obj + 0x10);
        *(f32 *)(obj + 0xC4) = v10[1] - *(f32 *)(obj + 0x14);
        *(f32 *)(obj + 0xC8) = v10[2] - *(f32 *)(obj + 0x18);
        *(f32 *)(obj + 0xCC) = v10[3];
        func_0038CF68(obj + 0xC0, obj + 0xC0, 1.0f);
        func_0038CE90(obj + 0xD0, obj + 0xC0, *(u8 **)(g + 0x2524) + 0xE0);
        func_0038CF68(obj + 0xD0, obj + 0xD0, 1.0f);
        func_0038CE90(obj + 0xE0, obj + 0xD0, obj + 0xC0);
    } else {
        *(q128_0054AC10 *)(obj + 0xC0) = *(q128_0054AC10 *)pos0;
        if (*(s32 *)(g + 0x1310) != 0 && g[0x1A08] == 0) {
            func_L39_005FFB78(g, obj + 0xC0, dir, 1.0f, 75.0f, 0.52359879f);
        }
        func_0038CE90(obj + 0xD0, obj + 0xC0, g + 0x3A0);
        func_0038CF68(obj + 0xD0, obj + 0xD0, 1.0f);
        func_0038CE90(obj + 0xE0, obj + 0xD0, obj + 0xC0);
    }
    f20 = 0.0f;
    *(f32 *)(obj + 0xEC) = f20;
    *(f32 *)(obj + 0xDC) = f20;
    *(f32 *)(obj + 0xCC) = f20;
    *(f32 *)(ex + 0x60) = f24;
    *(u8 **)(ex + 0xC) = src;
    *(f32 *)(ex + 0x1C) = func_L39_005B4410(2.0f, 5.0f);
    if (tgt != 0) {
        *(f32 *)(ex + 0x1C) = f20;
    }
    *(f32 *)(ex + 0x20) = func_L39_005B4468(6.0f, 10.0f);
    *(f32 *)(ex + 0x18) = f22;
    *(f32 *)(ex + 0x28) = func_L39_005B44C8();
    ex[0x26] = 1;
    *(f32 *)(ex + 0x5C) = 3.0f;
    *(u8 **)(ex + 0x10) = tgt;
    ex[0x27] = 1;
    if (g[0x1A14] != 0) {
        *(f32 *)(ex + 0x5C) = 1.0f;
    }
    *(q128_0054AC10 *)(ex + 0x40) = 0;
    *(q128_0054AC10 *)(ex + 0x30) = *(q128_0054AC10 *)(obj + 0xC0);
    if (D_L39_002429BC != 0) {
        func_L39_005BC330(obj + 0x10, v20, 1);
        f0 = func_0038CE68(v20, ex + 0x30);
        func_0038CE20(v30, v20, f0);
        *(f32 *)(ex + 0x30) = *(f32 *)(ex + 0x30) - v30[0];
        *(f32 *)(ex + 0x34) = *(f32 *)(ex + 0x34) - v30[1];
        *(f32 *)(ex + 0x38) = *(f32 *)(ex + 0x38) - v30[2];
    }
    if (tgt != 0) {
        u8 *e = (u8 *)func_00382348(tgt);
        if (e != 0) {
            *(u16 *)(e + 0x1E) |= 0x80;
            if (e[0xB] != 0) {
                ex[0x26] = 0;
            }
        }
    }
    *(s16 *)(ex + 0x24) = (s32)(95.0f / f22);
    if (tgt != 0) {
        func_0038CE20(v20, tgt + 0xE0, off);
        v20[0] = *(f32 *)(tgt + 0x10) + v20[0];
        v20[1] = *(f32 *)(tgt + 0x14) + v20[1];
        v20[2] = *(f32 *)(tgt + 0x18) + v20[2];
        *(f32 *)ex = v20[0];
        *(f32 *)(ex + 4) = v20[1];
        *(f32 *)(ex + 0x14) = off;
        *(f32 *)(ex + 8) = v20[2];
    }
    *(q128_0054AC10 *)v20 = *(q128_0054AC10 *)(src + 0x10);
    v20[2] = dir[2];
    ent = D_L39_0024CE20[*(s32 *)(g + 0x2544)];
    id = -1;
    if (ent != 0) {
        id = *(s32 *)(ent + 0x2548);
    }
    func_L39_005FFDF8(id);
    hit = func_003D3CB0(v20, dir, 0, *(void **)(g + 0x2524), 0);
    func_L39_005FFE78();
    if (hit != 0) {
        obj[0xBC] = 1;
        *(q128_0054AC10 *)(obj + 0x10) = *(q128_0054AC10 *)D_L39_0025F760;
    }
    func_L01_00399D78(obj, D_L39_003BE020 + (*(s32 *)(ex + 0x2C) << 6));
    func_003C7C38(obj);
    func_L01_0044BE50(obj, D_L39_0024C040, 0x1F);
    *(f32 *)(obj + 0x2C) = *(f32 *)(obj + 0x2C) * 2.5f;
    *(s32 *)(ex + 0x50) = func_L39_005FF538(obj, 0, 1.0f, 1.0f, 1.0f);
    return obj;
}
