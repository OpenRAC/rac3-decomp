/* functional: medium. Written from the asm (no draft/twin); compiles with the vu0 flag and --no-context (the file's own hero struct context clashes with the u8[] used here, and its line lacks -mvu0-use-vf0-vf2). 479 words differ (frame 0x1c0 vs 0x1b0: retail reuses stack slots), structure and calls follow retail block by block. */
/* localdecomp:start func_L30_004E6200 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) PV4;
static void pv_add(void *d, void *a, void *b) {
    f32 *o = (f32 *)d, *p = (f32 *)a, *q = (f32 *)b;
    f32 x = p[0] + q[0], y = p[1] + q[1], z = p[2] + q[2];
    o[0] = x; o[1] = y; o[2] = z;
}
static void pv_sub(void *d, void *a, void *b) {
    f32 *o = (f32 *)d, *p = (f32 *)a, *q = (f32 *)b;
    f32 x = p[0] - q[0], y = p[1] - q[1], z = p[2] - q[2];
    o[0] = x; o[1] = y; o[2] = z;
}
extern u8 D_001A4C00[];
extern u8 D_001A50E0[];
extern PV4 D_L30_001E9020;
extern PV4 D_L30_001E9040;
extern s32 D_L30_001E9018;
extern void func_0038CF68(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_003D5630(void);
extern u8 *func_00382348(s32);
extern u8 *func_003C4D58(s32);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038D098(f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_L01_00511848(void *);
extern f32 func_L01_005114B0(void *);
extern void func_L01_00511508(void *, void *, f32);
extern s32 func_L01_003FB640(void *, s32, void *, f32);

s32 func_L30_004E6200(PV4 *pos, s32 a1, u8 *a2) {
    PV4 v00, v10, v20, v30, v40, v50, v60, v70, v80, v90, vA0, vB0, vC0, vD0, vE0, vF0, v100, v110, v120, v130;
    s32 flag, found, hit, i, ok, owner;
    f32 f, a, t;
    u8 *p;
    u8 *q;
    u8 *hero = (u8 *)&D_001A4BE0;

    if (a2 != 0 && *(s32 *)(hero + 0x25C4) != 0xA8) {
        *(s32 *)(a2 + 0x28) = 0;
    }
    if (*(s16 *)(hero + 0x1D0) != 0) {
        return 0;
    }
    flag = 0;
    if (*(s32 *)(hero + 0x25CC) == 4 && *(s32 *)(hero + 0x1B8) >= 9 &&
        (*(u8 *)(hero + 0x46E) != 0 || *(f32 *)(hero + 0x118) < 0.10000001f)) {
        flag = 1;
    } else if (*(s32 *)(hero + 0x25CC) == 2) {
        flag = 1;
    }
    if (a2 != D_001A50E0) {
        flag = 1;
    }
    if (flag == 0) {
        return 0;
    }

    /* four-step sweep ahead of the hero looking for a surface that is nearly vertical */
    v00 = *pos;
    func_0038CF68(&v40, hero, *(f32 *)(hero + 0x284));
    pv_add(&v00, &v00, &v40);
    func_0038CF68(&v40, D_001A4C00, 2.8500001f);
    pv_add(&v10, &v00, &v40);
    func_0038CF68(&v40, D_001A4C00, 2.15f);
    pv_add(&v20, &v00, &v40);
    func_0038CF68(&v30, hero, 0.125f);
    found = 0;
    for (i = 0; i < 4; i++) {
        pv_add(&v10, &v10, &v30);
        pv_add(&v20, &v20, &v30);
        if (func_003D3CB0(&v10, &v20, 4, *(u8 **)(hero + 0x25C0), 0)) {
            s32 r = func_003D5630();
            if (r != 9 && r != 12 && r != 0) {
                if (func_L01_00511848(&D_L30_001E9040) < 0.34906584f) {
                    found = 1;
                }
            }
        }
        if (found) {
            break;
        }
    }
    if (!found) {
        return 0;
    }

    owner = 0;
    if (D_L30_001E9018 != 0) {
        ok = 0;
        p = func_00382348(D_L30_001E9018);
        q = func_003C4D58(D_L30_001E9018);
        if (p != 0 && (*(u16 *)(p + 0x1E) & 1)) {
            ok = 1;
        } else if (q != 0) {
            ok = *(s32 *)(q + 0x3C) & 1;
        }
        if (!ok) {
            return 0;
        }
        owner = D_L30_001E9018;
    }
    if (a2 != 0) {
        *(s32 *)(a2 + 0x38) = D_L30_001E9018;
    }
    v60 = D_L30_001E9020;
    pv_sub(&v50, &v60, pos);
    if (func_L01_005114B0(&v50) > 2.7f) {
        return 0;
    }
    func_0038CF68(&v70, D_001A4C00, 0.005f);
    pv_add(&v70, &v70, &v60);
    func_0038CF68(&v80, hero, -1.0f);
    pv_add(&v80, &v80, &v70);
    if (func_003D3CB0(&v80, &v70, 2, *(u8 **)(hero + 0x25C0), 0)) {
        if (D_L30_001E9018 == 0 || D_L30_001E9018 != owner) {
            return 0;
        }
    }
    if (a2 != 0) {
        func_0038CF68(&v90, D_001A4C00, 0.6f);
        pv_add(&v90, &v90, &v60);
        if (func_L01_003FB640(&v90, 4, *(u8 **)(hero + 0x25C0), *(f32 *)(hero + 0x284))) {
            *(s32 *)(a2 + 0x34) |= 1;
        } else {
            *(s32 *)(a2 + 0x34) &= ~1;
        }
    }
    f = func_L01_005114B0(&v50);
    if (f + *(f32 *)(hero + 0x33C) < 4.1f) {
        return 0;
    }
    if (f < 0.5f) {
        return 0;
    }

    /* probe from the hero toward the hit point for the wall behind it */
    vB0.x = 1.0f;
    vB0.y = 0.0f;
    vB0.z = -0.7f;
    vB0.w = 0.0f;
    func_0038D000(&vB0, &vB0, hero);
    hit = 0;
    pv_add(&vB0, &vB0, &v60);
    pv_sub(&v90, pos, &vB0);
    func_L01_00511508(&v90, &v90, 0.0f);
    pv_add(&v90, &v90, &vB0);
    func_0038CF68(&vA0, D_001A4C00, 0.7f / 5.0f);
    for (i = 0; i < 5; i++) {
        if (func_003D3CB0(&v90, &vB0, 2, 0, 0)) {
            func_0038CF68(&vC0, &D_L30_001E9040, 1.0f);
            hit = 1;
            func_L01_00511508(&vC0, &vC0, 0.0f);
            break;
        }
        pv_add(&v90, &v90, &vA0);
        pv_add(&vB0, &vB0, &vA0);
    }
    if (!hit) {
        return 0;
    }
    a = func_0038CE68(hero, &vC0);
    if (!(a < func_0038D098(1.3962634f))) {
        return 0;
    }

    /* march the landing point out along the wall until it is free */
    v120 = v60;
    func_0038CF68(&v110, hero + 0x2E0, -0.05f);
    func_0038CF68(&v100, &vC0, 0.03f);
    pv_add(&vF0, &v100, &v110);
    pv_sub(&v100, &v100, &v110);
    pv_add(&vD0, &v120, &v100);
    pv_add(&vE0, &v120, &vF0);
    t = 0.0f;
    do {
        if (func_003D3CB0(&vE0, &vD0, 2, *(u8 **)(hero + 0x25C0), 0) == 0) {
            if (a2 != 0) {
                *(PV4 *)(a2 + 0x10) = v120;
                func_0038CF68(&v130, &vC0, 0.9f);
                func_0038CF68(a2, hero + 0x2E0, 2.5f);
                pv_add(a2, &v130, a2);
                pv_add(a2, a2 + 0x10, a2);
                *(s32 *)(a2 + 0x28) = 1;
                *(f32 *)(a2 + 0x24) = func_0038D160(vC0.x, vC0.y);
            }
            return 1;
        }
        t += 0.03f;
        v120 = D_L30_001E9020;
        pv_add(&vE0, &v120, &vF0);
        pv_add(&vD0, &v120, &v100);
    } while (t < 2.4f);
    return 0;
}
/* localdecomp:end func_L30_004E6200 */
