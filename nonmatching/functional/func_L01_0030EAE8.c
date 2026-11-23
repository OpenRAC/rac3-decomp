/* functional: medium. Decoded by hand from PAL asm (no draft); all branches traced incl. delay slots; vu0 ops as plain C; leftover f12 passed to func_003C2880 in retail not modelled. */
/* vsub.xyz / vadd.xyz: xyz from the operands, w kept from the first operand */
static void vsub3(f32 *d, f32 *a, f32 *b) { f32 x = a[0] - b[0], y = a[1] - b[1], z = a[2] - b[2], w = a[3]; d[0] = x; d[1] = y; d[2] = z; d[3] = w; }
static void vadd3(f32 *d, f32 *a, f32 *b) { f32 x = a[0] + b[0], y = a[1] + b[1], z = a[2] + b[2], w = a[3]; d[0] = x; d[1] = y; d[2] = z; d[3] = w; }
extern u8 D_001A4C60[];
extern u8 D_001425C0[];
extern u8 D_L01_002C5600[];
extern s32 D_001427F0[];
extern s32 D_001A71A0[];
extern s32 D_L01_001D6694;
__asm__(".extern D_L01_001D6694, 16");
extern s32 D_L01_001DFB40;
__asm__(".extern D_L01_001DFB40, 16");
extern s32 D_L01_001E1728;
__asm__(".extern D_L01_001E1728, 4");
extern s32 func_L01_004BA800(void);
extern s32 func_L01_0030F0B0(u8 *, s32);
extern s32 func_L01_003F7EE8(u8 *);
extern f32 func_L01_0040E548(void *, void *);
extern f32 func_L01_0040E4C0(void *);
extern void func_L01_00511958(s32, s32);
extern void func_L01_00451FB8(s32, s32, s32, s32);
extern void func_L01_004450F0(u8 *, s32, s32);
extern s32 func_L01_0040E5D8(u8 *, s32);
extern s32 func_003A52A0(s32, s32, u8 *);
extern void func_0038D000(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_0038CEA8(void *);
extern f32 func_003C4138(f32 *, f32, f32);
extern void func_003C4CE8(void *, void *, f32);
extern void func_0038D810(void *, void *);
extern void func_0038D5F0(void *, void *, void *);
extern void func_003C2880(void *);

void func_L01_0030EAE8(u8 *obj) {
    u8 *vars;
    s32 i, idx, flag, old, now, diff, t, b23;
    f32 tmp[4] __attribute__((aligned(16)));
    f32 t10[4] __attribute__((aligned(16)));
    f32 t20[4] __attribute__((aligned(16)));
    f32 t30[4] __attribute__((aligned(16)));
    f32 t40[4] __attribute__((aligned(16)));
    f32 t50[4] __attribute__((aligned(16)));
    f32 t60[4] __attribute__((aligned(16)));
    f32 t70[4] __attribute__((aligned(16)));
    f32 t80[16] __attribute__((aligned(16)));
    f32 s, f20, d2;

    vars = *(u8 **)(obj + 0x68);
    if (D_L01_001D6694 == 2) {
        obj[0x31] = 0;
        *(u16 *)(obj + 0x34) |= 1;
    } else if (func_L01_004BA800() == 0) {
        obj[0x31] = 1;
        *(u16 *)(obj + 0x34) &= 0xFFFE;
    }

    switch (obj[0x20]) {
    case 0:
        obj[0x20] = 1;
        for (i = 0; i < 0x9C; i++) {
            if (*(s16 *)(D_L01_002C5600 + D_001425C0[i] * 0xF0 + 0x3A) == *(s16 *)(obj + 0xAA)) {
                *(s32 *)(vars + 0x68) = i;
            }
        }
        break;
    case 1:
        flag = 0;
        if (!(vars[0x79] >= 8 && (D_L01_001DFB40 & 0xF) != (((s32)obj >> 8) & 0xF))) {
            if (vars[0x5C] == 3 && (D_L01_001DFB40 & 0xF) == (((s32)obj >> 8) & 0xF)) {
                *(s128 *)vars = 0;
                *(s32 *)(vars + 0x10) = 0;
                *(s32 *)(vars + 0x14) = 0;
                *(s32 *)(vars + 0x18) = 0;
                *(f32 *)(vars + 0x1C) = 1.0f;
                vars[0x5C] = 0;
            }
            *(s128 *)tmp = *(s128 *)vars;
            func_L01_003F7EE8(obj);
            f20 = *(f32 *)(vars + 0x48);
            f20 = f20 + f20;
            d2 = func_L01_0040E548(tmp, vars);
            f20 = f20 * f20;
            if (f20 < d2) {
                flag = 1;
            }
            if (func_L01_0040E4C0(vars) < 4.0e-6f && func_L01_0040E4C0(vars + 0x10) < 9.0e-6f) {
                vars[0x79] = vars[0x79] + 1;
            } else {
                vars[0x79] = 0;
            }
        }
        if (func_L01_0030F0B0(obj, flag) != 0) {
            idx = *(s32 *)(vars + 0x68);
            old = D_001427F0[idx];
            func_L01_00511958(idx, *(s32 *)(vars + 0x60));
            now = D_001427F0[idx];
            diff = now - old;
            if (old < now) {
                if (diff == 1) {
                    t = *(s16 *)(D_L01_002C5600 + D_001425C0[idx] * 0xF0 + 0x36);
                } else {
                    t = *(s16 *)(D_L01_002C5600 + D_001425C0[idx] * 0xF0 + 0x34);
                }
                func_L01_00451FB8(t, diff, -1, 0);
            }
            func_L01_004450F0(obj, 2, -1);
            *(s128 *)vars = 0;
            *(f32 *)(vars + 0x70) = 0.16f;
            t = D_L01_001DFB40 - D_L01_001E1728;
            if (t <= 0) {
                t = -t;
            }
            if (t >= 9) {
                func_003A52A0(0, 0, obj);
                D_L01_001E1728 = D_L01_001DFB40;
            }
        }
        break;
    case 2:
        vsub3(tmp, (f32 *)(obj + 0x10), (f32 *)D_001A4C60);
        func_0038D000(tmp, tmp, D_001A4C60 - 0x40);
        s = 8.0f;
        if (0.0f < tmp[2]) {
            s = 0.0f;
        }
        func_003C4138((f32 *)(vars + 0x70), s, 0.0096f);
        func_0038CF68(t10, D_001A4C60 - 0x60, *(f32 *)(vars + 0x70));
        vadd3((f32 *)(obj + 0x10), (f32 *)(obj + 0x10), t10);
        vadd3((f32 *)(obj + 0x10), (f32 *)(obj + 0x10), (f32 *)(D_001A4C60 + 0xD0));
        s = func_0038CEA8(vars);
        func_003C4138(&s, 1.28f, 0.0096f);
        vsub3(t20, (f32 *)(D_001A4C60 + 0x60), (f32 *)(obj + 0x10));
        f20 = func_0038CEA8(t20) / s;
        if (f20 < 25.0f) {
            func_003C4138((f32 *)(obj + 0x2C), 0.0f, *(f32 *)(*(u8 **)(obj + 0x24) + 0x24) / 25.0f);
        }
        if (*(f32 *)(obj + 0x2C) == 0.0f || f20 <= 1.0f) {
            func_003C2880(obj);
            return;
        }
        func_0038CF68(vars, t20, s);
        vadd3((f32 *)(obj + 0x10), (f32 *)(obj + 0x10), (f32 *)vars);
        func_0038CE90(t30, D_001A4C60 - 0x60, vars);
        func_003C4CE8(t30, t30, 0.10471976f);
        *(s128 *)t70 = 0;
        t70[2] = 0.3f;
        func_0038D000(t40, t70, obj + 0xC0);
        func_0038D810(t30, t80);
        func_0038D5F0(obj + 0xC0, t80, obj + 0xC0);
        func_0038D000(t50, t70, obj + 0xC0);
        vsub3(t60, t50, t40);
        vsub3((f32 *)(obj + 0x10), (f32 *)(obj + 0x10), t60);
        break;
    default:
        break;
    }

    if (obj[0x20] == 1 && func_L01_0040E5D8(obj, D_001A71A0[0]) != 0) {
        b23 = obj[0x23];
        if (b23 < 0x25) {
            b23 = 0x24;
        } else {
            b23 = b23 - 4;
        }
    } else {
        b23 = obj[0x23];
        if (b23 < 0x7C) {
            b23 = b23 + 4;
        } else {
            b23 = 0x80;
        }
    }
    obj[0x23] = b23;
    if ((s8)obj[0x23] < 0) {
        *(u16 *)(obj + 0x34) &= 0xDFFF;
    } else {
        *(u16 *)(obj + 0x34) |= 0x2000;
    }
}
