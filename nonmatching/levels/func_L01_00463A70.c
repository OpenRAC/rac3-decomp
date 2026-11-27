/* func_L01_00463A70 (k8 agent 5, 2026-11-27): near miss from the functional C, 56 aligned rows of 450 (difflib over the
 * tools/check.py columns, level 01, file flags of src/levels/shared/L01_00463538.c) with a divs_nops row
 * `func_L01_00463A70 2 2 2` (not committed; add it when this lands). Fixed against the functional C (74): the scale is
 * 0.055f (0x3D6147AE) and func_0038CF68 takes (dst, src, f32) as everywhere else; every test of v+0x1B reads the byte
 * again (no b1b local: retail's `move $a0,$v1` copy).
 * Left: (1) the colour unpack: retail divides r, g, b with the ints in $f3/$f1/$f2 (cvt order r, b, g), here b's divide
 * comes before g's; (2) the rgba pack and the three byte stores: retail multiplies g*255 first and keeps the three
 * 65535 products for `sb` before the `b`, here one sb sits in the delay slot; (3) a few float registers in the alpha clamp.
 * Tried without gain: b1b as u8/s32/u32, the reads before/after the unpack, int temporaries for the three channels, b before g,
 * u8 casts and regrouped ORs in the pack. 49 places. */
extern s32 func_003D3CB0(void *, void *, s32, u8 *, s32);
extern void func_L01_00448F30(void *, void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038D328(void *, void *);
extern void func_0038D028(void *, void *, void *);
extern void func_L01_0040E6B8(void *, void *, f32);
extern s32 func_0038CB00(u8 *);
extern void func_003CD250(u8 *);
extern u8 D_L01_001EAA00[];

void func_L01_00463A70(u8 *p) {
    f32 pos[4];
    f32 hit[4];
    f32 tmp[4];
    f32 off[4];
    f32 mat[16];
    u8 *v = p + 0x20;
    u8 *cfg = *(u8 **)(v + 0xC);
    u32 flags;
    u32 rgba;
    f32 r, g, b, k, a;

    pos[0] = *(f32 *)(p + 0x10) + *(f32 *)(v + 0);
    pos[1] = *(f32 *)(p + 0x14) + *(f32 *)(v + 4);
    pos[2] = *(f32 *)(p + 0x18) + *(f32 *)(v + 8);

    if ((*(s32 *)(cfg + 0x70) & 1) && func_003D3CB0(p + 0x10, pos, 4, p, 0) != 0) {
        tmp[0] = *(f32 *)(v + 0);
        tmp[1] = *(f32 *)(v + 4);
        tmp[2] = *(f32 *)(v + 8);
        func_L01_00448F30(hit, tmp, D_L01_001EAA00 + 0x40, *(f32 *)(cfg + 0x3C));
        *(f32 *)(v + 0) = hit[0];
        *(f32 *)(v + 4) = hit[1];
        *(f32 *)(v + 8) = hit[2];
        func_0038CF68(off, D_L01_001EAA00 + 0x40, 0.055f);
        vec_add_ab(p + 0x10, D_L01_001EAA00 + 0x20, off);
    } else {
        *(vu0_q *)(p + 0x10) = *(vu0_q *)pos;
    }

    flags = *(s32 *)(cfg + 0x70);
    if (flags & 2) {
        rgba = *(u32 *)(p + 4);
        r = (f32)(s32)(((rgba & 0xFF) << 8) | *(u8 *)(v + 0x18)) / 65535.0f;
        g = (f32)(s32)((rgba & 0xFF00) | *(u8 *)(v + 0x19)) / 65535.0f;
        b = (f32)(s32)(((rgba >> 8) & 0xFF00) | *(u8 *)(v + 0x1A)) / 65535.0f;
        if (*(u8 *)(v + 0x1B) & 0x10) {
            r = r - *(f32 *)(cfg + 0x4C) * 1.2f;
        } else {
            r = r + *(f32 *)(cfg + 0x4C) * 1.2f;
        }
        if (*(u8 *)(v + 0x1B) & 0x20) {
            g = g - *(f32 *)(cfg + 0x50) * 1.2f;
        } else {
            g = g + *(f32 *)(cfg + 0x50) * 1.2f;
        }
        if (*(u8 *)(v + 0x1B) & 0x40) {
            b = b - *(f32 *)(cfg + 0x54) * 1.2f;
        } else {
            b = b + *(f32 *)(cfg + 0x54) * 1.2f;
        }
        if (*(f32 *)(cfg + 0x64) < r) {
            r = *(f32 *)(cfg + 0x64);
            if (*(s32 *)(cfg + 0x70) & 0x100) {
                *(u8 *)(v + 0x1B) = *(u8 *)(v + 0x1B) ^ 0x10;
            }
        }
        if (r < *(f32 *)(cfg + 0x58)) {
            r = *(f32 *)(cfg + 0x58);
            if (*(s32 *)(cfg + 0x70) & 0x10) {
                *(u8 *)(v + 0x1B) = *(u8 *)(v + 0x1B) ^ 0x10;
            }
        }
        if (*(f32 *)(cfg + 0x68) < g) {
            g = *(f32 *)(cfg + 0x68);
            if (*(s32 *)(cfg + 0x70) & 0x200) {
                *(u8 *)(v + 0x1B) = *(u8 *)(v + 0x1B) ^ 0x20;
            }
        }
        if (g < *(f32 *)(cfg + 0x5C)) {
            g = *(f32 *)(cfg + 0x5C);
            if (*(s32 *)(cfg + 0x70) & 0x20) {
                *(u8 *)(v + 0x1B) = *(u8 *)(v + 0x1B) ^ 0x20;
            }
        }
        if (*(f32 *)(cfg + 0x6C) < b) {
            b = *(f32 *)(cfg + 0x6C);
            if (*(s32 *)(cfg + 0x70) & 0x400) {
                *(u8 *)(v + 0x1B) = *(u8 *)(v + 0x1B) ^ 0x40;
            }
        }
        if (b < *(f32 *)(cfg + 0x60)) {
            b = *(f32 *)(cfg + 0x60);
            if (*(s32 *)(cfg + 0x70) & 0x40) {
                *(u8 *)(v + 0x1B) = *(u8 *)(v + 0x1B) ^ 0x40;
            }
        }
        *(u32 *)(p + 4) = ((s32)(r * 255.0f) & 0xFF) | (((s32)(g * 255.0f) & 0xFF) << 8) |
                          (((s32)(b * 255.0f) & 0xFF) << 16) | ((s32)(*(f32 *)(v + 0x10) * 255.0f) << 24);
        *(u8 *)(v + 0x18) = (s32)(r * 65535.0f);
        *(u8 *)(v + 0x19) = (s32)(g * 65535.0f);
        *(u8 *)(v + 0x1A) = (s32)(b * 65535.0f);
    } else if (flags & 4) {
        *(u32 *)(p + 4) = (*(u32 *)(p + 4) & 0xFFFFFF) | ((s32)(*(f32 *)(v + 0x10) * 255.0f) << 24);
    }

    if (*(s32 *)(cfg + 0x70) & 4) {
        if (*(u8 *)(v + 0x1B) & 0x80) {
            a = *(f32 *)(v + 0x10) - *(f32 *)(cfg + 0x38) * 1.2f;
        } else {
            a = *(f32 *)(v + 0x10) + *(f32 *)(cfg + 0x38) * 1.2f;
        }
        *(f32 *)(v + 0x10) = a;
        if (*(f32 *)(cfg + 0x48) < *(f32 *)(v + 0x10)) {
            *(f32 *)(v + 0x10) = *(f32 *)(cfg + 0x48);
            if (*(s32 *)(cfg + 0x70) & 0x800) {
                *(u8 *)(v + 0x1B) = *(u8 *)(v + 0x1B) ^ 0x80;
            }
        }
        if (*(f32 *)(v + 0x10) < *(f32 *)(cfg + 0x44)) {
            *(f32 *)(v + 0x10) = *(f32 *)(cfg + 0x44);
            if (*(s32 *)(cfg + 0x70) & 0x80) {
                *(u8 *)(v + 0x1B) = *(u8 *)(v + 0x1B) ^ 0x80;
            }
        }
    }

    *(u8 *)(p + 8) = (s32)(*(f32 *)(v + 0x14) * 255.0f);

    if (*(s32 *)(cfg + 0x70) & 8) {
        pos[0] = *(f32 *)(v + 0);
        pos[1] = *(f32 *)(v + 4);
        pos[2] = *(f32 *)(v + 8);
        if (*(s32 *)(cfg + 0x70) & 0x8000) {
            func_0038D328(mat, (u8 *)*(s32 *)(cfg + 0x7C) + 0xF0);
            func_0038D028(hit, cfg, mat);
        } else {
            *(vu0_q *)hit = *(vu0_q *)cfg;
        }
        vec_add_ab(pos, pos, hit);
        func_L01_0040E6B8(pos, pos, *(f32 *)(cfg + 0x40));
        *(f32 *)(v + 0) = pos[0];
        *(f32 *)(v + 4) = pos[1];
        *(f32 *)(v + 8) = pos[2];
    }

    k = *(f32 *)(p + 0xC) + *(f32 *)(cfg + 0x30) * 1.2f;
    *(f32 *)(p + 0xC) = k;
    if (k < *(f32 *)(cfg + 0x74)) {
        *(f32 *)(p + 0xC) = *(f32 *)(cfg + 0x74);
    }
    if (*(f32 *)(cfg + 0x78) < *(f32 *)(p + 0xC)) {
        *(f32 *)(p + 0xC) = *(f32 *)(cfg + 0x78);
    }

    a = *(f32 *)(v + 0x14) + *(f32 *)(cfg + 0x34) * 1.2f;
    *(f32 *)(v + 0x14) = a;
    if (*(f32 *)(v + 0x10) <= 0.0f) {
        func_003CD250(p);
        return;
    }
    if (func_0038CB00(p + 0xA) != 0 ||
        *(f32 *)(p + 0x10) < *(f32 *)(cfg + 0x10) ||
        *(f32 *)(p + 0x14) < *(f32 *)(cfg + 0x14) ||
        *(f32 *)(p + 0x18) < *(f32 *)(cfg + 0x18) ||
        *(f32 *)(cfg + 0x20) < *(f32 *)(p + 0x10) ||
        *(f32 *)(cfg + 0x24) < *(f32 *)(p + 0x14) ||
        *(f32 *)(cfg + 0x28) < *(f32 *)(p + 0x18)) {
        func_003CD250(p);
    }
}
