/* functional: high. Compiles in file context, frame 0x60; the instruction mix (calls, fp ops, constants, loads/stores) equals retail except retail tests the u64 flag word at +0x48 with ld/mask where this C tests the +0x4C half with lw (same bits: 0x3, 0x30, 0x300, 0x3000) and mask-clear sequences. Block-by-block read against retail; dynamic-light animator object. */
typedef struct {
    f32 f00, f04, f08;
    s32 w0C;
    u8 q10[0x0C];
    u8 b1C;
    u8 p1D[3];
    u8 *p20;
    u8 b24, b25, b26, b27, b28, b29, b2A, b2B, b2C, b2D, b2E, b2F, b30, b31, b32, b33;
    f32 f34, f38, f3C, f40, f44;
    s32 w48, w4C, w50;
    f32 f54, f58, f5C, f60;
    s32 w64;
    u8 b68, b69, b6A, b6B;
    u16 h6C, h6E, h70, h72;
    u16 h74, h76, h78, h7A;
    u8 b7C, b7D, b7E, b7F;
} Light_00300890;
__asm__(".extern D_L01_001E001C, 16");
extern u8 *D_L01_001E001C;
extern u8 D_L01_001F1B40[];
void func_L01_00300890(u8 *obj) {
    extern s32 func_0038CAD0(void *);
    extern s32 func_0038CB00(void *);
    extern s32 func_L01_0040E020(void *);
    extern void func_L01_00424D88(s32);
    extern s32 func_L01_00424CB0(void *, f32, f32, f32, f32, f32);
    extern void func_003C2880(u8 *);
    extern s32 func_0038DC20(void *, f32);
    extern f32 func_003824E0(f32, f32);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_0038D000(void *, void *, void *);
    Light_00300890 *g;
    f32 v[4] __attribute__((aligned(16)));
    f32 base[4] __attribute__((aligned(16)));
    f32 offs[4] __attribute__((aligned(16)));
    s32 idx;
    s32 expired = 0;
    u8 *l;
    if (obj == 0) return;
    g = *(Light_00300890 **)(obj + 0x68);
    if (g == 0) return;
    if (obj[0x20] == 0) {
        vu0_q q = *(vu0_q *)(obj + 0x10);
        f32 r, gr, bl;
        obj[0x30] = 0xFF;
        obj[0xBC] = g->b1C;
        *(vu0_q *)g->q10 = q;
        r = (f32)g->b25 / 100.0f;
        gr = (f32)g->b2A / 100.0f;
        bl = (f32)g->b2F / 100.0f;
        g->b1C = obj[0xBC];
        g->w0C = g->w4C;
        g->h74 = g->h6C;
        g->h76 = g->h6E;
        g->h78 = g->h70;
        g->h7A = g->h72;
        g->f54 = r;
        g->f58 = gr;
        g->f5C = bl;
        g->f60 = g->f34;
        g->w50 = -1;
        if (g->w64 != -1) g->p20 = D_L01_001E001C + (g->w64 << 8);
        if (g->f40 < 0.0f) g->f40 = -g->f40;
        if (g->f44 < 0.0f) g->f44 = -g->f44;
        obj[0x20] = 1;
    }
    if (obj[0xBC] != 0) {
        obj[0xBC]--;
        return;
    }
    if (g->w48 != -1 && func_0038CAD0(&g->w48) != 0) {
        if (g->w50 != -1) {
            func_L01_00424D88(g->w50);
            g->w50 = -1;
        }
        func_003C2880(obj);
        return;
    }
    *(vu0_q *)v = *(vu0_q *)(obj + 0x10);
    v[3] = g->f60;
    idx = func_0038DC20(v, 255.0f);
    if (idx == -1) {
        if (g->w50 != -1) {
            func_L01_00424D88(g->w50);
            g->w50 = -1;
        }
        return;
    }
    if (g->p20 == 0) *(vu0_q *)base = *(vu0_q *)g->q10;
    else *(vu0_q *)base = *(vu0_q *)(g->p20 + 0x10);
    if (g->w4C & 0x800000) {
        *(vu0_q *)(obj + 0x10) = *(vu0_q *)base;
    } else {
        if (g->w4C & 0x100000) {
            if (g->w4C & 0x200000) {
                offs[0] = func_003824E0(-g->f00, g->f00);
                offs[1] = func_003824E0(-g->f04, g->f04);
                offs[2] = func_003824E0(-g->f08, g->f08);
            } else {
                s32 saved = g->w0C;
                g->w0C = 0;
                func_0038CE20(offs, g, func_003824E0(*(f32 *)&g->w0C, 1.0f));
                g->w0C = saved;
            }
        } else {
            s32 saved = g->w0C;
            g->w0C = 0;
            *(vu0_q *)offs = *(vu0_q *)g;
            g->w0C = saved;
        }
        if ((g->w4C & 0x400000) && g->p20 != 0) func_0038D000(offs, offs, g->p20 + 0xC0);
        vec_add_ab(obj + 0x10, base, offs);
    }
    if (g->h72 != 0) {
        if (func_0038CB00(&g->h7A) != 0) {
            g->h7A = (g->h72 * 5 + 2) / 6;
            if (g->w4C & 4) {
                g->w4C &= ~8;
                g->f60 = g->f3C;
                expired = 1;
            }
        }
    }
    if (!(g->w4C & 0x80000)) {
        if ((g->w4C & 3) == 2) g->w4C ^= 2;
        if (g->w4C & 2) {
            if (g->b6B != 0 && func_L01_0040E020(&g->b7F) != 0) g->w4C ^= 2;
        } else if (g->w4C & 8) {
            g->f60 = g->f60 - g->f44 * 1.2f;
            if (g->f60 <= g->f3C) {
                g->f60 = g->f3C;
                if (g->w4C & 4) {
                    if ((g->h72 * 5 + 2) / 6 == 0) g->w4C ^= 8;
                }
            }
        } else {
            g->f60 = g->f60 + g->f40 * 1.2f;
            if (g->f38 <= g->f60) {
                g->f60 = g->f38;
                if (g->w4C & 1) {
                    g->w4C = (g->w4C | 2) ^ 8;
                    g->b7F = (g->b6B * 5 + 2) / 6;
                } else {
                    g->w4C ^= 8;
                }
            }
        }
    } else if (g->h72 == 0 || expired == 1) {
        g->f60 = func_003824E0(g->f3C, g->f38);
    }
    if (g->h6C != 0) {
        if (func_0038CB00(&g->h74) != 0) {
            g->f54 = (f32)g->b27;
            g->w4C &= ~0x80;
            g->h74 = (g->h6C * 5 + 2) / 6;
        }
    }
    if (!(g->w4C & 0x10000)) {
        if ((g->w4C & 0x30) == 0x20) g->w4C ^= 0x20;
        if (g->w4C & 0x20) {
            if (g->b68 != 0 && func_L01_0040E020(&g->b7C) != 0) g->w4C ^= 0x20;
        } else if (g->w4C & 0x80) {
            g->f54 = g->f54 - (f32)g->b29 / 100.0f * 1.2f;
            if (g->f54 <= (f32)g->b27 / 100.0f) {
                g->f54 = (f32)g->b27 / 100.0f;
                if (g->w4C & 0x40) {
                    if (g->h6C == 0) g->w4C ^= 0x80;
                }
            }
        } else {
            g->f54 = g->f54 + (f32)g->b28 / 100.0f * 1.2f;
            if ((f32)g->b26 / 100.0f <= g->f54) {
                g->f54 = (f32)g->b26 / 100.0f;
                if (g->w4C & 0x10) {
                    g->w4C = (g->w4C | 0x20) ^ 0x80;
                    g->b7C = (g->b68 * 5 + 2) / 6;
                } else {
                    g->w4C ^= 0x80;
                }
            }
        }
    } else if (g->h6C == 0) {
        g->f54 = func_003824E0((f32)g->b27 / 100.0f, (f32)g->b26 / 100.0f);
    }
    if (g->h6E != 0) {
        if (func_0038CB00(&g->h76) != 0) {
            g->f58 = (f32)g->b2C;
            g->w4C &= ~0x800;
            g->h76 = (g->h6E * 5 + 2) / 6;
        }
    }
    if (!(g->w4C & 0x20000)) {
        if ((g->w4C & 0x300) == 0x200) g->w4C ^= 0x200;
        if (g->w4C & 0x200) {
            if (g->b69 != 0 && func_L01_0040E020(&g->b7D) != 0) g->w4C ^= 0x200;
        } else if (g->w4C & 0x800) {
            g->f58 = g->f58 - (f32)g->b2E / 100.0f * 1.2f;
            if (g->f58 <= (f32)g->b2C / 100.0f) {
                g->f58 = (f32)g->b2C / 100.0f;
                if (g->w4C & 0x400) {
                    if (g->h6E == 0) g->w4C ^= 0x800;
                }
            }
        } else {
            g->f58 = g->f58 + (f32)g->b2D / 100.0f * 1.2f;
            if ((f32)g->b2B / 100.0f <= g->f58) {
                g->f58 = (f32)g->b2B / 100.0f;
                if (g->w4C & 0x100) {
                    g->w4C = (g->w4C | 0x200) ^ 0x800;
                    g->b7D = (g->b69 * 5 + 2) / 6;
                } else {
                    g->w4C ^= 0x800;
                }
            }
        }
    } else if (g->h6E == 0) {
        g->f58 = func_003824E0((f32)g->b2C / 100.0f, (f32)g->b2B / 100.0f);
    }
    if (g->h70 != 0) {
        if (func_0038CB00(&g->h78) != 0) {
            g->f5C = (f32)g->b31;
            g->w4C &= ~0x8000;
            g->h78 = (g->h70 * 5 + 2) / 6;
        }
    }
    if (!(g->w4C & 0x40000)) {
        if ((g->w4C & 0x3000) == 0x2000) g->w4C ^= 0x2000;
        if (g->w4C & 0x2000) {
            if (g->b6A != 0 && func_L01_0040E020(&g->b7E) != 0) g->w4C ^= 0x2000;
        } else if (g->w4C & 0x8000) {
            g->f5C = g->f5C - (f32)g->b33 / 100.0f * 1.2f;
            if (g->f5C <= (f32)g->b31 / 100.0f) {
                g->f5C = (f32)g->b31 / 100.0f;
                if (g->w4C & 0x4000) {
                    if (g->h70 == 0) g->w4C ^= 0x8000;
                }
            }
        } else {
            g->f5C = g->f5C + (f32)g->b32 / 100.0f * 1.2f;
            if ((f32)g->b30 / 100.0f <= g->f5C) {
                g->f5C = (f32)g->b30 / 100.0f;
                if (g->w4C & 0x1000) {
                    g->w4C = (g->w4C | 0x2000) ^ 0x8000;
                    g->b7E = (g->b6A * 5 + 2) / 6;
                } else {
                    g->w4C ^= 0x8000;
                }
            }
        }
    } else if (g->h70 == 0) {
        g->f5C = func_003824E0((f32)g->b31 / 100.0f, (f32)g->b30 / 100.0f);
    }
    if (g->w50 == -1) {
        g->w50 = func_L01_00424CB0(obj + 0x10, g->f60 * 0.8f, (f32)g->b24 / 100.0f, g->f54, g->f58, g->f5C);
    } else {
        l = D_L01_001F1B40 + g->w50 * 32;
        *(vu0_q *)(l + 0x10) = *(vu0_q *)(obj + 0x10);
        *(f32 *)(l + 0x1C) = g->f60 * 0.8f;
        *(f32 *)(l + 0) = g->f54;
        *(f32 *)(l + 4) = g->f58;
        *(f32 *)(l + 8) = g->f5C;
        *(f32 *)(l + 0xC) = (f32)g->b24 / 100.0f;
    }
}
