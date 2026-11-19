/* functional: medium-high. Written from the asm (no family copy found), compiles in context (628 diff; plain-C vector ops instead of lqc2/vsub, locals add stack). All constants and offsets checked against the asm; block structure follows the asm control flow with labels. func_0012FE98 is an unnamed boot_elf entry (inside func_0012FE78): vector normalize dst=a0, src=a1 xyz, w=0; the port must supply it. Level ids per level (2,5,8,0xA,0x15) set h[0x147F]. */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_4E3CB8;
extern u8 D_001A4BE0[];
extern u8 D_001E8E40[];
extern u8 D_001E8E60[];
extern u8 D_001E8E80[];
extern s32 D_001D545C;
extern s32 D_001D677C;
extern s32 func_L01_004E9308(void);
extern void func_L01_004EF6F0(void *, void *, f32, f32, s32);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern s32 func_L01_003FE908(void);
extern s32 func_003D5630(void);
extern f32 func_003C3EC8(void *, void *);
extern s32 func_003C4B50(void *);
extern u8 *func_00382348(void *);
extern u8 *func_003C4D58(void *);
extern f32 func_L01_00451580(void *);
extern f32 func_0038CF00(void *, void *);
extern void func_0012FE98(void *, void *);
extern f32 func_L01_00511848(void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CE68(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_003C4138(void *, f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_004F40A8(void *, void *);
extern void func_L01_00511038(void *, s32, f32, f32, f32);

void func_L19_004E3CB8(void) {
    u8 *h = D_001A4BE0;
    u8 *g = D_001E8E40;
    V4_4E3CB8 vb;
    V4_4E3CB8 va;
    V4_4E3CB8 vc;
    V4_4E3CB8 ve;
    V4_4E3CB8 vf;
    V4_4E3CB8 vg;
    V4_4E3CB8 vi;
    f32 f20;
    f32 t;
    f32 a;
    s32 lvl;
    s32 id;
    s32 k;
    s32 i;
    s32 s;
    s16 st;
    u8 *r;
    s32 ok;

    {
        V4_4E3CB8 z;
        z.x = 0.0f; z.y = 0.0f; z.z = 0.0f; z.w = 0.0f;
        *(V4_4E3CB8 *)(h + 0x2F0) = z;
    }
    *(u16 *)(h + 0x36E) = *(u16 *)(h + 0x36E) + 1;
    *(u16 *)(h + 0x36C) = *(u16 *)(h + 0x36C) + 1;
    k = *(s32 *)(h + 0x358);
    *(f32 *)(h + 0x2C8) = 1.0f;
    *(f32 *)(h + 0x33C) = 32.0f;
    *(s32 *)(h + 0x2C0) = 0;
    *(s32 *)(h + 0x2C4) = 0;
    *(s32 *)(h + 0x340) = 0;
    *(s32 *)(h + 0x338) = 0;
    *(s16 *)(h + 0x36A) = 0;
    *(s32 *)(h + 0x35C) = 0;
    if (k != 0)
        *(s32 *)(h + 0x358) = k + 1;

    f20 = *(f32 *)(h + 0x284) * 2.2f;
    if (*(s32 *)(h + 0x25CC) == 2)
        f20 = *(f32 *)(h + 0x284) * 2.9f;
    if (func_L01_004E9308() != 0)
        f20 = 0.0f;
    func_L01_004EF6F0(&va, &vb, f20, -48.0f, 1);

    if (func_003D3CB0(&va, &vb, 2, *(void **)(h + 0x25C0), 0) == 0)
        goto tail;
    *(u8 *)(h + 0x147F) = func_L01_003FE908();

    if (*(s32 *)(g + 0x18) != 0) {
        lvl = D_001D545C;
        *(u8 *)(h + 0x147F) = 0;
        if (lvl == 2) {
            if (*(s16 *)(*(u8 **)(g + 0x18) + 0xAA) == 0x18C6)
                *(u8 *)(h + 0x147F) = 2;
            if (*(s16 *)(*(u8 **)(g + 0x18) + 0xAA) == 0x18AF)
                *(u8 *)(h + 0x147F) = 2;
        }
        if (D_001D545C == 5) {
            id = *(s16 *)(*(u8 **)(g + 0x18) + 0xAA);
            if (id == 0x1607)
                *(u8 *)(h + 0x147F) = 2;
            id = *(s16 *)(*(u8 **)(g + 0x18) + 0xAA);
            if (id == 0x1681)
                *(u8 *)(h + 0x147F) = 2;
            id = *(s16 *)(*(u8 **)(g + 0x18) + 0xAA);
            if (id == 0x15F7)
                *(u8 *)(h + 0x147F) = 2;
            id = *(s16 *)(*(u8 **)(g + 0x18) + 0xAA);
            if (id == 0x16BB)
                *(u8 *)(h + 0x147F) = 3;
        }
        if (D_001D545C == 8) {
            if (*(s16 *)(*(u8 **)(g + 0x18) + 0xAA) == 0x1A44)
                *(u8 *)(h + 0x147F) = 2;
        }
        if (D_001D545C == 0xA) {
            if (*(s16 *)(*(u8 **)(g + 0x18) + 0xAA) == 0x1645)
                *(u8 *)(h + 0x147F) = 3;
            if (*(s16 *)(*(u8 **)(g + 0x18) + 0xAA) == 0x162E)
                *(u8 *)(h + 0x147F) = 1;
        }
        if (D_001D545C == 0x15) {
            if (*(s16 *)(*(u8 **)(g + 0x18) + 0xAA) == 0x1BA9)
                *(u8 *)(h + 0x147F) = 3;
        }
    }

    st = func_003D5630();
    *(s16 *)(h + 0x1470) = st;
    if (st == 0) {
        t = func_003C3EC8(D_001E8E60, h + 0x2D0);
        *(f32 *)(h + 0x350) = t;
        if (*(f32 *)(h + 0x88) < t) {
            if (!(*(s32 *)(h + 0x358) > 0))
                *(s32 *)(h + 0x358) = 1;
        }
        if (func_003D3CB0(&va, &vb, 0x24, *(void **)(h + 0x25C0), 0) == 0)
            goto tail;
        *(u8 *)(h + 0x147F) = func_L01_003FE908();
    }
    if (*(s16 *)(h + 0x1470) == 0xD) {
        t = *(f32 *)(g + 0x28);
        *(f32 *)(h + 0x350) = t;
        va.z = t - 0.01f;
        if (func_003D3CB0(&va, &vb, 4, *(void **)(h + 0x25C0), 0) == 0)
            goto tail;
    }
    st = *(s16 *)(h + 0x1470);
    if (st == 0xB) {
        *(f32 *)(h + 0x354) = *(f32 *)(g + 0x28);
        goto tail;
    }
    if (st == 1) {
        if ((u32)(*(s32 *)(h + 0x25C4) - 0x7E) < 2)
            goto tail;
    }
    if (*(s32 *)(g + 0x18) != 0) {
        if (func_003C4B50(*(void **)(g + 0x18)) != 0)
            *(s16 *)(h + 0x36A) = 1;
        r = func_00382348(*(void **)(g + 0x18));
        if (r != 0 && (*(u16 *)(r + 0x1E) & 8) != 0)
            *(s16 *)(h + 0x36A) = 1;
        r = func_003C4D58(*(void **)(g + 0x18));
        if (r != 0 && (*(s32 *)(r + 0x3C) & 8) != 0)
            *(s16 *)(h + 0x36A) = 1;
    }
    if (*(s32 *)(g + 0x1C) > 0) {
        *(V4_4E3CB8 *)(h + 0x2F0) = *(V4_4E3CB8 *)(g + 0x20);
        *(f32 *)(h + 0x338) = *(f32 *)(g + 0x28);
        if (D_001D677C != 0)
            *(f32 *)(h + 0x338) = func_L01_00451580(g + 0x20);
        t = func_0038CF00(h + 0x80, h + 0x2F0);
        *(f32 *)(h + 0x33C) = t;
        *(s32 *)(h + 0x35C) = *(s32 *)(g + 0x18);
        func_0012FE98(h + 0x2C0, g + 0x40);
        *(f32 *)(h + 0x340) = func_L01_00511848(g + 0x40);
        *(f32 *)(h + 0x34C) = func_0038D160(*(f32 *)(g + 0x40), *(f32 *)(g + 0x44));
        vc = *(V4_4E3CB8 *)(h + 0x2F0);
        vc.x -= *(f32 *)(h + 0x80);
        vc.y -= *(f32 *)(h + 0x84);
        vc.z -= *(f32 *)(h + 0x88);
        t = func_0038CE68(&vc, h + 0x2C0);
        if (0.0f < t)
            *(f32 *)(h + 0x33C) = -*(f32 *)(h + 0x33C);
        if (*(f32 *)(h + 0x33C) < 0.02f) {
            *(u16 *)(h + 0x36C) = 0;
            if (*(f32 *)(h + 0x340) <= 0.87266463f || h[0x25F4] != 0) {
                *(u16 *)(h + 0x36E) = 0;
                *(s32 *)(h + 0xBF0) = *(s32 *)(g + 0x18);
            }
        }
    }

tail:
    if (*(f32 *)(h + 0x350) < *(f32 *)(h + 0x88))
        *(s32 *)(h + 0x358) = 0;
    if (*(s16 *)(h + 0x36E) != 0) {
        *(s32 *)(h + 0x360) = 0;
    } else {
        k = *(s32 *)(h + 0x360);
        *(V4_4E3CB8 *)(h + 0x300) = *(V4_4E3CB8 *)(h + 0x2F0);
        *(s32 *)(h + 0x360) = k + 1;
    }
    {
        V4_4E3CB8 z;
        z.x = 0.0f; z.y = 0.0f; z.z = 0.0f; z.w = 0.0f;
        *(V4_4E3CB8 *)(h + 0x2E0) = z;
    }
    switch (h[0x25F4]) {
    case 0:
        *(f32 *)(h + 0x2E8) = -1.0f;
        break;
    case 1:
        if (*(f32 *)(h + 0x31C) == 0.0f) {
            *(V4_4E3CB8 *)(h + 0x2E0) = *(V4_4E3CB8 *)(h + 0x2C0);
            func_0038CE20(h + 0x2E0, h + 0x2E0, -1.0f);
        } else {
            func_003C4138(h + 0x31C, 0.0f, 1.0f);
            *(V4_4E3CB8 *)(h + 0x2E0) = *(V4_4E3CB8 *)(h + 0x310);
            func_0038CE20(h + 0x2C0, h + 0x2E0, -1.0f);
        }
        break;
    case 2:
        a = -1.0f;
        if (0.0f < *(f32 *)(h + 0xBC))
            a = 1.0f;
        vc = *(V4_4E3CB8 *)(h + 0xB0);
        vc.x -= *(f32 *)(h + 0x80);
        vc.y -= *(f32 *)(h + 0x84);
        vc.z -= *(f32 *)(h + 0x88);
        *(V4_4E3CB8 *)(h + 0x2E0) = vc;
        func_0038CF68(h + 0x2E0, h + 0x2E0, a);
        break;
    }
    *(s32 *)(h + 0x344) = 0;
    *(s32 *)(h + 0x348) = 0;
    *(s32 *)(h + 0x330) = 0;
    *(s32 *)(h + 0x334) = 0;
    *(s32 *)(h + 0x328) = 0;
    *(s32 *)(h + 0x32C) = 0;
    *(s32 *)(h + 0x320) = 0;
    *(s32 *)(h + 0x324) = 0;
    if (!(*(f32 *)(h + 0x33C) < 0.25f))
        return;
    s = *(s32 *)(h + 0x25CC);
    ok = 0;
    if (s == 0 || s == 0xC || s == 9 || s == 7 || s == 1)
        ok = 1;
    else if (s == 4 && h[0x46C] != 0)
        ok = 1;
    if (!ok)
        return;
    func_L01_004F40A8(h + 0x2C0, &vc);
    if (-0.7853982f < vc.y) {
        if (vc.y < 0.7853982f)
            *(f32 *)(h + 0x344) = vc.y;
    }
    if (-0.7853982f < vc.x) {
        if (vc.x < 0.7853982f)
            *(f32 *)(h + 0x348) = vc.x;
    }
    for (i = 0; i < 2; i++) {
        f20 = 1.5707964f;
        if (i == 1)
            f20 = -f20;
        func_L01_00511038(&ve, 1, 0.2f, f20, 0.45f);
        func_L01_00511038(&vf, 1, 0.2f, f20, -0.45f);
        if (func_003D3CB0(&ve, &vf, 0x22, *(void **)(h + 0x25C0), 0) != 0) {
            if (D_001D677C != 0) {
                f20 = func_L01_00451580(D_001E8E60);
                a = func_L01_00451580(h + 0x2F0);
                *(f32 *)(h + 0x320 + i * 4) = f20 - a;
            } else {
                *(f32 *)(h + 0x320 + i * 4) = *(f32 *)(g + 0x28) - *(f32 *)(h + 0x338);
            }
            t = *(f32 *)(h + 0x320 + i * 4);
            if (t < 0.0f)
                t = -t;
            if (0.4f < t)
                *(s32 *)(h + 0x320 + i * 4) = 0;
            func_0012FE98(&vi, D_001E8E80);
            func_L01_004F40A8(&vi, &vg);
            if (-0.7853982f < vg.y) {
                if (vg.y < 0.7853982f)
                    *(f32 *)(h + 0x328 + i * 4) = vg.y;
            }
            if (-0.7853982f < vg.x) {
                if (vg.x < 0.7853982f)
                    *(f32 *)(h + 0x330 + i * 4) = vg.x;
            }
        } else {
            *(s32 *)(h + 0x320 + i * 4) = 0;
            *(f32 *)(h + 0x328 + i * 4) = *(f32 *)(h + 0x344);
            *(f32 *)(h + 0x330 + i * 4) = *(f32 *)(h + 0x348);
        }
    }
}
