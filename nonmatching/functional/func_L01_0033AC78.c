/* functional: medium. 526 diff words at the file's flags (frame 0xB0 vs 0xA0, register allocation, a different arm order); structure taken from the NTSC-U draft but every constant re-derived from the PAL assembly (PAL timers: (r*5+2)/6, %50 with 47/34/12/11, 149 frames, p[0xFA] < 18 and /17.0, not the NTSC 60 Hz values), jump table read from the retail ELF (states 1..6 -> ADC8, AFD0, AFF8, B4E4, B3A4, B1A8), end labels with and without the m[0xA8]=0xFF store checked per path. */
typedef struct { f32 x, y, z, w; } V4;
typedef int Q16 __attribute__((mode(TI)));
typedef unsigned long U64;
extern u8 D_001A4BE0[];
extern s32 D_001A5E08[];
extern s32 D_001A71AC[];
extern s32 D_L01_001DFB40[];
extern u8 D_L01_001EEA80[];
extern s32 D_001D545C_sda;
extern void func_003C2880(u8 *);
extern void func_L01_0033B530(u8 *);
extern s32 func_L01_0044C108(void *);
extern void func_L01_0033CBC0(u8 *);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038CF38(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern u8 *func_L01_00447490(u8 *, u32, s32);
extern s32 func_L01_004561B8(u8 *);
extern void func_L01_0033C520(u8 *, s32, u8 *);
extern void func_L01_0033C030(u8 *);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern u8 *func_003D4D00(void *, s32, void *, void *, f32);
extern void func_L01_00447718(u8 *, void *, void *, u8 *, s32, s32, s32, s32, s32, f32, f32, f32);
extern void func_L01_0033D188(u8 *, s32);
extern void func_L01_004AA7E8(u8 *, s32);
extern s32 func_0038DC20(void *, f32);
extern s32 func_L01_0040E020(void *);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_L01_00445C48(u8 **, s32, s32, s32);
extern void func_L01_00445D30(u8 **, u8 *, s32, s32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern void func_003A52A0(s32, s32, u8 *);
extern void func_L01_0043B9E8(u8 *, s32, s32, s32);

void func_L01_0033AC78(u8 *m) {
    u8 *p = *(u8 **)(m + 0x68);
    u8 *hero;
    u8 *h;
    u8 *o;
    u8 *other;
    u8 *rec;
    u8 *eff;
    s32 special;
    s32 ok;
    s32 type;
    s32 r;
    f32 f;
    struct {
        Q16 v;
        u8 *m;
        s32 flags;
        s32 pad;
        f32 f;
        s32 zero;
    } hit;
    V4 pos;

    if (*(s16 *)(m + 0xAA) == 0x1FA) {
        func_003C2880(m);
        return;
    }
    if ((*(u16 *)(m + 0x34) & 0x80) != 0 && D_001D545C_sda == 4) {
        return;
    }
    if (m[0x20] == 0) {
        func_L01_0033B530(m);
    }
    if (func_L01_0044C108(m + 0x10) == 0) {
        return;
    }
    if (((*(s32 *)(p + 0xDC) & 0xC) != 0 && *(s32 *)(p + 0xE4) != D_L01_001DFB40[0]) ||
        0.0f < func_0038CE68(p + 0xC0, p + 0xC0)) {
        func_L01_0033CBC0(m);
    }
    if (*(s32 *)(p + 0xD0) == 0) {
        *(u16 *)(p + 0x4E) = *(u16 *)(p + 0x4E) | 1;
    }
    h = func_L01_00447490(m, 0x0B030001, 0);
    special = 0;
    if (h != 0) {
        if (*(s32 *)(h + 0x24) == 0x2000000) {
            h = 0;
            special = 1;
        }
    }
    hero = D_001A4BE0;
    switch (m[0x20]) {
    case 1:
        if (func_L01_004561B8(m) != 0) {
            *(s32 *)(p + 0x130) = 0;
        }
        if (*(s16 *)(m + 0xAA) == 0x1F9) {
            if (*(u8 **)(hero + 0x290) == m || *(u8 **)(hero + 0x28C) == m ||
                (*(u8 **)(hero + 0x35C) == m && *(s16 *)(hero + 0x36E) == 0) ||
                *(u8 **)(hero + 0x538) == m || special != 0) {
                if (*(s32 *)(hero + 0x25CC) == 15) {
                    func_L01_0033C520(m, 1, 0);
                    func_L01_0033C030(m);
                    return;
                }
                m[0xBC] = 0;
                m[0x20] = 5;
                return;
            }
        }
        if (h == 0) {
            return;
        }
        if (!(0.0f < *(f32 *)(h + 0x2C))) {
            return;
        }
        type = *(s16 *)(m + 0xAA);
        ok = 1;
        if (type == 0x1F6) {
            if ((*(s32 *)(h + 0x24) & 0x20000) == 0) {
                o = *(u8 **)(h + 0x20);
                if ((*(s16 *)(o + 0xAA) ^ 0x1F9) != 0) {
                    ok = 0;
                }
            }
        }
        if (type == 0x1F9) {
            m[0x20] = 5;
            if ((*(s32 *)(h + 0x24) & 0x20000) == 0) {
                m[0xBC] = (s32)((func_003824E0(5.0f, 15.0f) * 5.0f + 2.0f) / 6.0f);
            } else {
                m[0xBC] = 1;
            }
            *(U64 *)(p + 0xE8) = *(U64 *)(m + 0x38);
            ok = 0;
        }
        if (ok == 0) {
            break;
        }
        type = *(s16 *)(m + 0xAA);
        if (type == 0x1F8) {
            o = *(u8 **)(h + 0x20);
            if (o == 0) {
                break;
            }
            r = *(s16 *)(o + 0xAA);
            if (r != 0x47 && r != 0) {
                break;
            }
            if (D_001A5E08[0] != 9) {
                break;
            }
            func_L01_0033C520(m, 0, h);
            func_L01_0033C030(m);
        } else {
            func_L01_0033C520(m, (type ^ 0x1F9) < 1u, h);
            func_L01_0033C030(m);
        }
        break;
    case 2:
        m[0xBC] = m[0xBC] - 1;
        if (m[0xBC] == 0xFF) {
            m[0xA8] = 0xFF;
            m[0x20] = 1;
        }
        return;
    case 3:
        if (*(s16 *)(m + 0xAA) == 0x1F9 && p[0xFA] < 0x12) {
            *(Q16 *)&hit.v = *(Q16 *)(m + 0xC0);
            hit.f = 2.0f;
            hit.m = m;
            hit.zero = 0;
            func_0038CF68(&pos, m + 0xE0, 0.5f);
            pos.x = pos.x + *(f32 *)(m + 0x10);
            pos.y = pos.y + *(f32 *)(m + 0x14);
            pos.z = pos.z + *(f32 *)(m + 0x18);
            hit.flags = 0x30001;
            f = (f32)p[0xFA] / 17.0f;
            func_003D4D00(&pos, 0x10, m, &hit, f + f);
            hit.flags = 0x30000;
            eff = func_003D4D00(&pos, 0x10, *(void **)(hero + 0x25C0), 0, f * 3.0f);
            if (eff != 0) {
                func_L01_00447718(m, &pos, D_L01_001EEA80, eff, *(s32 *)(hero + 0x25C0), 0x10000, 0, 0x30000,
                                  -1, 4.0f, 1.0f, 1.0f);
            }
            p[0xFA] = p[0xFA] + 1;
            break;
        }
        if (p[0xF8] != 0) {
            *(s32 *)(m + 0x98) = 0;
            *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x41) & 0xEFFF;
            func_L01_004AA7E8(m, 1);
            if (*(s16 *)(m + 0xB4) >= 2) {
                *(s16 *)(m + 0xB4) = 1;
            }
            m[0x20] = 6;
            if (p[0xF9] != 0xFF) {
                p[0xF9] = func_00382498(0x1E, 0x3C);
            }
        } else {
            func_L01_0033D188(m, 1);
            return;
        }
        break;
    case 6:
        *(s32 *)(p + 0x130) = *(s32 *)(p + 0x130) + 1;
        if (p[0xF9] == 0xFF) {
            return;
        }
        *(Q16 *)&hit.v = *(Q16 *)(m + 0x10);
        *(f32 *)((u8 *)&hit + 8) = *(f32 *)((u8 *)&hit + 8) + 0.5f;
        *(f32 *)((u8 *)&hit + 12) = 1.0f;
        if (func_0038DC20(&hit, (f32)*(s16 *)(m + 0x32)) != -1) {
            break;
        }
        if (func_L01_0040E020(p + 0xF9) == 0) {
            break;
        }
        m[0x7F] = 0;
        if (m[0x21] == 0xFF) {
            func_L01_004450F0(m, 1, -1);
            *(u16 *)(m + 0x34) = *(u16 *)(m + 0x34) & 0xFFBE;
            rec = *(u8 **)(m + 0x24);
            *(u16 *)(m + 0x34) = *(u16 *)(m + 0x34) | (*(u16 *)(rec + 0x44) & 0x1000);
            *(s32 *)(m + 0x98) = *(s32 *)(rec + 0x10);
            return;
        }
        func_L01_00445C48(&other, m[0x21], 0, 0);
        while (other != 0) {
            if (other != m && func_0038CF38(m + 0x10, other + 0x10) <= 0.1f && other[0x20] == 1 &&
                *(s32 *)(*(u8 **)(other + 0x68) + 0xD0) == 0) {
                *(Q16 *)(m + 0x10) = *(Q16 *)(other + 0x10);
                *(f32 *)(m + 0x18) = *(f32 *)(m + 0x18) + 1.0f;
                *(u8 **)(*(u8 **)(other + 0x68) + 0xD0) = m;
                *(s32 *)(p + 0xD0) = 0;
                *(u8 **)(p + 0xD4) = other;
                m[0x31] = 1;
                m[0x20] = 1;
                *(u16 *)(m + 0x34) = *(u16 *)(m + 0x34) & 0xFFFE;
                *(s32 *)(m + 0x98) = *(s32 *)(*(u8 **)(m + 0x24) + 0x10);
                *(u16 *)(m + 0x34) = *(u16 *)(m + 0x34) | 0x1000;
                break;
            }
            func_L01_00445D30(&other, other, 0, 0);
        }
        if (m[0x20] != 1) {
            *(f32 *)(m + 0x18) = func_003C3D30(m + 0x10, 0, 0, 0.5f);
            m[0x20] = 1;
            *(s32 *)(p + 0xD4) = 0;
            *(s32 *)(p + 0xD0) = 0;
            m[0x31] = 1;
            *(u16 *)(m + 0x34) = *(u16 *)(m + 0x34) & 0xFFFE;
            *(s32 *)(m + 0x98) = *(s32 *)(*(u8 **)(m + 0x24) + 0x10);
        }
        break;
    case 5:
        if (m[0xBC] == 0) {
            m[0xBC] = 0x95;
            *(U64 *)(p + 0xE8) = *(U64 *)(m + 0x38);
        } else if (m[0xBC] >= 13 && h != 0) {
            m[0xBC] = (s32)((func_003824E0(5.0f, 15.0f) * 5.0f + 2.0f) / 6.0f);
        }
        if (m[0xBC] % 50 == 0x2F || m[0xBC] == 0xB) {
            func_003A52A0(1, 0x20, m);
        }
        if (m[0xBC] % 50 >= 0x22 || m[0xBC] < 12) {
            func_L01_0043B9E8(m, 200, 64, 64);
        } else {
            *(U64 *)(m + 0x38) = *(U64 *)(p + 0xE8);
        }
        if (m[0xBC] == 1 || D_001A71AC[0] == 0x16) {
            *(U64 *)(m + 0x38) = *(U64 *)(p + 0xE8);
            func_L01_0033C520(m, 1, 0);
            func_L01_0033C030(m);
        }
        m[0xA8] = 0xFF;
        m[0xBC] = m[0xBC] - 1;
        return;
    case 4:
        if (func_L01_0040E020(m + 0xBC) != 0) {
            m[0x20] = 1;
            *(u16 *)(m + 0x34) = *(u16 *)(m + 0x34) & 0xFFFE;
        }
        break;
    default:
        return;
    }
    m[0xA8] = 0xFF;
}
