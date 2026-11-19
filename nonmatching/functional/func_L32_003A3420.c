/* functional: medium. Written from the PAL asm (no draft). 268 diff vs retail bytes (regalloc/scheduling), structure and every offset re-checked by hand: 3 groups of 4-float arrays at v+0x100..0x1B0 filled for 2N steps, each with a collision-clipped end point (func_003D3CB0 modes 0,2,2; on hit the point becomes D_L32_001E99A0). Uninitialised 'unused' vec is the retail sp+0x20 scratch (written by func_0038CF68, never read here). */
extern f32 D_L32_001DE640, D_L32_001DE650, D_L32_001DE658, D_L32_001DE65C, D_L32_001DE660;
extern f32 D_L32_001DE668, D_L32_001DE66C, D_L32_001DE670;
extern s32 D_L32_001DE63C;
extern u8 D_L32_001E2AA0[];
extern vu0_v4 D_L32_001E99A0;
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L30_0034CC28(void *, void *, void *, s32, s32, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);

void func_L32_003A3420(u8 *a0, f32 t) {
    u8 *v = *(u8 **)(a0 + 0x68);
    vu0_v4 d, side, unused, blk[3], a, b, tmp;
    f32 w, x, f20;
    s32 i, k;
    u8 **nodes;

    if (t < D_L32_001DE640) {
        w = t / D_L32_001DE640;
    } else if (1.0f - D_L32_001DE640 < t) {
        w = (1.0f - t) / D_L32_001DE640;
    } else {
        w = 1.0f;
    }
    d = *(vu0_v4 *)(v + 0x1C0);
    vec_sub_ab(&d, &d, a0 + 0x10);
    func_0038CE90(&side, &d, D_L32_001E2AA0);
    nodes = (u8 **)(v + 0x200);
    func_0038CF68(&d, &d, *(f32 *)(v + 0x1F0));
    func_0038CF68(&unused, &d, 1.0f);
    func_L30_0034CC28(blk, a0, &d, 1, 0, (f32)D_L32_001DE63C);
    for (k = 0; k < 6; k++) {
        if (nodes[k] != 0) {
            *(s32 *)(nodes[k] + 0x98) = 0;
        }
    }
    for (i = 0; (f32)i < D_L32_001DE650 + D_L32_001DE650; i++) {
        if ((f32)i < D_L32_001DE650) {
            x = (f32)i - D_L32_001DE650;
        } else {
            x = (f32)(i + 1) - D_L32_001DE650;
        }
        f20 = w * x / D_L32_001DE650;

        func_0038CF68(&a, &side, f20 * D_L32_001DE668);
        vec_add_ba(&a, &a, a0 + 0x10);
        func_0038CF68(&b, &side, f20 * D_L32_001DE658);
        vec_add_ba(&b, &b, &d);
        vec_copy(&tmp, a0 + 0x10);
        vec_add_ab(&b, &b, &tmp);
        if (func_003D3CB0(&a, &b, 0, a0, (s32)blk) != 0) {
            b = D_L32_001E99A0;
        }
        *(f32 *)(v + i * 4 + 0x160) = a.x;
        *(f32 *)(v + i * 4 + 0x190) = a.z;
        *(f32 *)(v + i * 4 + 0x100) = b.x;
        *(f32 *)(v + i * 4 + 0x130) = b.z;

        func_0038CF68(&a, &side, f20 * D_L32_001DE66C);
        vec_add_ba(&a, &a, a0 + 0x10);
        func_0038CF68(&b, &side, f20 * D_L32_001DE65C);
        vec_add_ba(&b, &b, &d);
        vec_copy(&tmp, a0 + 0x10);
        vec_add_ab(&b, &b, &tmp);
        if (func_003D3CB0(&a, &b, 2, a0, (s32)blk) != 0) {
            b = D_L32_001E99A0;
        }
        *(f32 *)(v + i * 4 + 0x170) = a.x;
        *(f32 *)(v + i * 4 + 0x1A0) = a.z;
        *(f32 *)(v + i * 4 + 0x110) = b.x;
        *(f32 *)(v + i * 4 + 0x140) = b.z;

        func_0038CF68(&a, &side, f20 * D_L32_001DE670);
        vec_add_ba(&a, &a, a0 + 0x10);
        func_0038CF68(&b, &side, f20 * D_L32_001DE660);
        vec_add_ba(&b, &b, &d);
        vec_copy(&tmp, a0 + 0x10);
        vec_add_ab(&b, &b, &tmp);
        if (func_003D3CB0(&a, &b, 2, a0, (s32)blk) != 0) {
            b = D_L32_001E99A0;
        }
        *(f32 *)(v + i * 4 + 0x180) = a.x;
        *(f32 *)(v + i * 4 + 0x1B0) = a.z;
        *(f32 *)(v + i * 4 + 0x120) = b.x;
        *(f32 *)(v + i * 4 + 0x150) = b.z;
    }
    for (k = 0; k < 6; k++) {
        if (nodes[k] != 0) {
            *(s32 *)(nodes[k] + 0x98) = *(s32 *)(*(u8 **)(nodes[k] + 0x24) + 0x10);
        }
    }
}
