/* functional: medium. functional: medium. Control flow and all calls/args follow the retail asm; only register allocation, quad vs scalar vec copies and stack layout differ */
extern void func_L01_004CB320(void);
extern void func_L01_004CB358(void);
extern s32 func_L01_003FB640(void *, s32, void *, f32);
extern s32 func_0038CAD0(void *);
extern s32 func_003D4D00(void *, s32, f32, void *, void *);
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32);
extern void func_0038CF68(f32 *, void *, f32);
extern s32 func_0038DC20(void *, f32);
extern void func_L01_00404A10(void (*)(void *), void *);
extern void func_003CE8A8(void *);
extern s32 D_L01_001DFB40[];
extern s32 D_001D545C[];
extern f32 D_001DF1DC_sda;
extern f32 D_001DF1E0_sda;
extern f32 D_001DF1E4_sda;
extern f32 D_001DF1E8_sda;
extern f32 D_001DF1EC_sda;
extern f32 D_001DF1F4_sda;
extern f32 D_001DF1F8_sda;
extern f32 D_001DF204_sda;
extern f32 D_001DF208_sda;
__asm__(".extern D_001DF1DC_sda, 4");
__asm__(".extern D_001DF1E0_sda, 4");
__asm__(".extern D_001DF1E4_sda, 4");
__asm__(".extern D_001DF1E8_sda, 4");
__asm__(".extern D_001DF1EC_sda, 4");
__asm__(".extern D_001DF1F4_sda, 4");
__asm__(".extern D_001DF1F8_sda, 4");
__asm__(".extern D_001DF204_sda, 4");
__asm__(".extern D_001DF208_sda, 4");

void func_L01_003CE3D0(u8 *m) {
    u8 info[0x30];
    f32 sum[4];
    f32 out[4];
    u8 *vars;
    u8 *pos;
    u8 *att;
    u8 *w;
    f32 f, mx, f20, t;
    s32 r;
    s32 b;

    vars = *(u8 **)(m + 0x68);
    pos = m + 0x10;
    if (m[0x20] == 2) {
        t = *(f32 *)(vars + 0x20) - D_001DF1E4_sda;
        *(f32 *)(vars + 0x20) = t;
        if (t < 0.01f) {
            func_003C2880((s32)m);
            return;
        }
        goto tail;
    }
    f = *(f32 *)(vars + 0x20);
    mx = D_001DF1E0_sda;
    if (f < mx) {
        t = f + D_001DF1DC_sda;
        *(f32 *)(vars + 0x20) = t;
        if (mx < t) {
            *(f32 *)(vars + 0x20) = mx;
        }
    }
    sum[0] = *(f32 *)(pos + 0) + *(f32 *)(vars + 0);
    sum[1] = *(f32 *)(pos + 4) + *(f32 *)(vars + 4);
    sum[2] = *(f32 *)(pos + 8) + *(f32 *)(vars + 8);
    sum[3] = *(f32 *)(pos + 12);
    func_L01_00446760((L_3CC220 *)info, *(M_3CC220 **)(m + 0xB8), 1, (f32 *)vars, *(f32 *)(vars + 0x14));
    info[0x18] = 1;
    *(u16 *)(info + 0x1A) = *(u16 *)(m + 0xAA);
    func_L01_004CB320();
    r = func_003D3CB0((int)pos, sum, 0, *(M_3CC220 **)(m + 0xB8), (L_3CC220 *)info);
    if (r != 0) {
        w = (u8 *)D_L01_001EAA18[0];
        if (w != 0 && *(s16 *)(w + 0xAA) == 0x186D) {
            b = w[0x20];
            if (b != 2 && b != 5) {
                w[0x20] = 4;
            }
        }
    }
    func_L01_004CB358();
    if (r == 0) {
        att = *(u8 **)(m + 0xB8);
        if (((D_L01_001DFB40[0] + *(s16 *)(att + 0xB2)) & 1) != 0 &&
            func_L01_003FB640(pos, 1, att, D_001DF1E8_sda) != 0) {
            goto hit;
        }
        if (func_0038CAD0(vars + 0x18) == 0) {
            goto setpos;
        }
    }
hit:
    func_003D4D00(pos, 0, D_001DF1EC_sda, *(void **)(m + 0xB8), info);
    func_L01_003303B8(pos, 0, 5, 5, 5, 5, 5, 0,
                      0, 0, 0, 0, 0, 0, 0x1010000, 0, 0x38F7, 0xF7, 0x40FF, 0xFF, 0xFF, 0x30FF, 0x7F0060FF, 0x280000FF, 0x30FF, 0,
                      0.2f, 0.0f, 0.0f, 1.0f);
    func_003A52A0(0, 0, m);
    func_L01_004450F0((M3C7568 *)m, 2, -1);
setpos:
    *(f32 *)(m + 0x10) = sum[0];
    *(f32 *)(m + 0x14) = sum[1];
    *(f32 *)(m + 0x18) = sum[2];
    *(f32 *)(m + 0x1C) = sum[3];
tail:
    if (func_0038CAD0(vars + 0x1C) != 0) {
        mx = D_001DF1F8_sda;
        f = *(f32 *)(vars + 0x24);
        if (mx < f) {
            t = f - D_001DF1F4_sda;
            *(f32 *)(vars + 0x24) = t;
            if (t < mx) {
                *(f32 *)(vars + 0x24) = mx;
            }
        }
    }
    f20 = *(f32 *)(vars + 0x24) * *(f32 *)(vars + 0x20);
    func_0038CF68(out, m + 0xC0, -D_001DF204_sda * f20);
    out[0] += *(f32 *)(m + 0x10);
    out[1] += *(f32 *)(m + 0x14);
    out[2] += *(f32 *)(m + 0x18);
    out[3] = D_001DF208_sda * f20;
    if (D_001D545C[0] == 1 && *(s16 *)(*(u8 **)(m + 0xB8) + 0xAA) == 0xC23) {
        r = func_0038DC20(out, 255.0f);
        if (r < 0) {
            return;
        }
    } else {
        r = func_0038DC20(out, 64.0f);
        if (r < 0) {
            return;
        }
    }
    func_L01_00404A10(func_003CE8A8, m);
}
