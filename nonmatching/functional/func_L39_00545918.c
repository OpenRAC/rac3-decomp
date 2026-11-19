/* functional: high. Per-frame update of the menu camera's HUD marker/blip: spawns the effect at the player's matrix position scaled by 250 plus the object's position, ticks the 0x3E4 counter (cap 10) and 0x3D4/0x3D8 timers, and on a press (buttons 0x28) fires func_L01_003F1F20 and func_L39_00545740. The w lane of the vadd.xyz'd vector is whatever func_0038CE20 leaves, as in retail. */
__asm__(".extern D_L39_00241164, 16");
extern u8 *D_L39_00241164;
__asm__(".extern D_L39_00241640, 16");
extern u8 *D_L39_00241640;
__asm__(".extern D_L39_0024AEB8, 4");
extern s32 D_L39_0024AEB8;
extern u8 D_L39_0024DE80[];
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CB00(void *);
extern void func_L01_003F6F20(s32, void *, u32, void *, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
extern s32 func_L01_003F1F20(s32, s32);
extern void func_L39_00545740(u8 *, u8 *, u32);

void func_L39_00545918(u8 *a) {
    u8 *o = *(u8 **)(a + 0x68);
    u8 *g = *(u8 **)(o + 0x384);
    u8 *pad;
    u8 *base = D_L39_0024DE80;
    s32 kind = 0;
    f32 v[4] __attribute__((aligned(16)));
    u8 *pl;
    s32 n;

    pad = D_L39_00241164;
    if (g != 0) {
        pl = *(u8 **)(g + 0x2D8);
        if (pl != 0) {
            kind = *(u8 *)(pl + 0x24C9);
            pad = *(u8 **)(pl + 0x2534);
            base = *(u8 **)(pl + 0x2530);
        }
    }
    *(s32 *)(a + 0x98) = 0;
    func_0038CE20(v, base + 0x380, 250.0f);
    v[0] += *(f32 *)(a + 0x10);
    v[1] += *(f32 *)(a + 0x14);
    v[2] += *(f32 *)(a + 0x18);
    func_L01_003F6F20(kind, a, 0xFF0FFF0F, v, 0x23, -1, 4, 1.0f, 0.0f, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);

    if (*(s32 *)(o + 0x3D4) <= 0) {
        *(s32 *)(o + 0x3E4) = 0;
    } else {
        n = *(s32 *)(o + 0x3E4) + 1;
        *(s32 *)(o + 0x3E4) = n;
        if (n >= 11) {
            *(s32 *)(o + 0x3E4) = 10;
        }
    }

    if ((*(s32 *)(pad + 0x1A0) & 0x28) != 0
        && *(u8 **)(o + 0x384) != 0
        && *(u8 **)(*(u8 **)(o + 0x384) + 0x2D8) != 0
        && *(s16 *)(*(u8 **)(*(u8 **)(o + 0x384) + 0x2D8) + 0x320) == 0
        && *(s16 *)(o + 0x37E) == 0
        && *(s32 *)(o + 0x3D4) > 0
        && *(s32 *)(o + 0x3E4) >= 3) {
        s32 cnt = *(s32 *)(o + 0x3D4);
        s32 t;
        if (*(s8 *)(D_L39_00241640 + 0x19B) == 0) {
            *(s32 *)(o + 0x3D4) = cnt - 1;
            t = 0x15;
        } else {
            t = 0x15;
        }
        *(s32 *)(o + 0x3D8) = t;
        if (*(u8 **)(o + 0x384) != 0) {
            pl = *(u8 **)(*(u8 **)(o + 0x384) + 0x2D8);
            if (pl != 0 && *(u8 *)(pl + 0x1A14) != 0) {
                func_L01_003F1F20(D_L39_0024AEB8, *(s32 *)(pl + 0x2534));
            }
        }
        func_L39_00545740(a, (u8 *)v, 0xFFFFFFFF);
    }
    func_0038CB00(o + 0x37E);
    *(s32 *)(o + 0x3D8) -= 1;
    if (*(s32 *)(o + 0x3D8) <= 0 && *(s32 *)(o + 0x3D4) < 8) {
        *(s32 *)(o + 0x3D4) += 1;
        *(s32 *)(o + 0x3D8) = 0x15;
    }
    *(s32 *)(a + 0x98) = *(s32 *)(*(u8 **)(a + 0x24) + 0x10);
}
