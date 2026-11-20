/* functional: medium. Behaviour follows the PAL asm: debris/fire-bolt style object that, in state 3, bursts into particles and frees its sound slot once its timer passes a random threshold; otherwise tracks collision against the player-side line (D_L19_001E2080), emits impact particles and re-registers its draw callback. The w lanes follow retail's .xyz ops (v10.w = s60.w, v30.w = s60.w). The collision-query local is 0x30 bytes as in retail (it was a 16-byte array, so func_L01_00446748 and the 0x1A store overwrote the saved $s registers); the frame is retail's 0xC0 with the same local offsets. */
extern f32 D_L19_001DE5A8;
extern f32 D_L19_001DE5AC;
extern f32 D_L19_001DE5B0;
extern f32 D_L19_001DE5B4;
extern s32 D_L19_001DE5B8;
extern s32 D_L19_001DE5BC;
extern s32 D_L19_001DE5C0;
extern s32 D_L19_001DE5C4;
extern s32 D_L19_001DF240;
extern f32 D_L19_001E2080[];
extern u8 D_L19_001E8E60[];
extern s32 D_1A71A0[];
extern u8 D_1A30B0[];
extern u8 D_1A3190[];
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_L01_00463378(void *, void *, void *, s32, s32, s32, s32, s32, s32);
extern void func_003A4F28(s32);
extern s32 func_003A52A0(s32, s32, void *);
extern f32 func_L01_0040E570(void *, void *);
extern void func_L01_00446748(void *, void *, s32, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern s32 func_00382348(s32);
extern void func_L01_00466F50(void *, void *, s32, f32, f32);
extern s32 func_0038CAD0(void *);
extern void func_L01_00404808(void *, void *);
extern void func_L19_003AEC08(u8 *);

void func_L19_003AE5A8(void *obj) {
    u8 *o = obj;
    u8 *s = *(u8 **)(o + 0x68);
    f32 v10[4] __attribute__((aligned(16)));
    f32 v20[4] __attribute__((aligned(16)));
    f32 v30[12] __attribute__((aligned(16))); /* 0x30 bytes as retail (sp+0x30..0x5F): func_L01_00446748 fills a collision-query struct here (fields to 0x20, 0x1A set below) and func_003D3CB0 reads it */
    s32 hit;
    s32 slot;
    u8 *rec;
    f32 dist;

    if (o[0x20] == 3 && func_00382498(0, 0x19) < *(u16 *)(o + 0x96)) {
        f32 *op = (f32 *)(o + 0x10);
        f32 *s60 = (f32 *)(s + 0x60);
        s32 c1, c2;
        v10[0] = s60[0] - op[0];
        v10[1] = s60[1] - op[1];
        v10[2] = s60[2] - op[2];
        v10[3] = s60[3];
        func_0038CF68(v10, v10, D_L19_001DE5A8);
        v10[0] += func_003824E0(-D_L19_001DE5AC, D_L19_001DE5AC);
        v10[1] += func_003824E0(-D_L19_001DE5AC, D_L19_001DE5AC);
        v10[2] += func_003824E0(-D_L19_001DE5AC, D_L19_001DE5AC);
        v10[3] = func_003824E0(D_L19_001DE5B0, D_L19_001DE5B4);
        func_0038CE20(v20, v10, 0.5f);
        v20[2] -= 0.12133334f;
        c1 = func_0038DBD8(D_L19_001DE5B8, D_L19_001DE5BC, func_003824E0(0.0f, 1.0f));
        c2 = func_0038DBD8(D_L19_001DE5C0, D_L19_001DE5C4, func_003824E0(0.0f, 1.0f));
        func_L01_00463378(op, v10, v20, c1, c2, 8, 0x11, 5, 0x1003C);
        slot = *(s32 *)(s + 8);
        if (slot != -1) {
            rec = D_1A30B0 + (slot << 7);
            if (*(u8 **)(rec + 0xDC) == o && rec[0xD0] != 0) {
                func_003A4F28(slot);
            }
        }
        *(s32 *)(s + 8) = -1;
        return;
    }
    hit = 0;
    dist = func_L01_0040E570(s + 0x40, D_L19_001E2080);
    if (dist < 256.0f) {
        func_L01_00446748(v30, o, 0x110001, 10.0f);
        *(u16 *)((u8 *)v30 + 0x1A) = *(u16 *)(o + 0xAA);
        *(Q *)(s + 0x50) = *(Q *)(s + 0x60);
        if (func_003D3CB0(o + 0x10, s + 0x40, 0, o, o[0x20] != 3 ? (void *)v30 : 0) != 0) {
            s32 id;
            *(Q *)(s + 0x60) = *(Q *)D_L19_001E8E60;
            id = *(s32 *)(D_L19_001E8E60 - 8);
            if (id == D_1A71A0[0] || func_00382348(id) != 0) {
                hit = 1;
            }
        } else {
            *(Q *)(s + 0x60) = *(Q *)(s + 0x40);
        }
    } else {
        *(Q *)(s + 0x60) = *(Q *)(s + 0x40);
    }
    {
        f32 *s60 = (f32 *)(s + 0x60);
        v10[0] = s60[0] - D_L19_001E2080[0];
        v10[1] = s60[1] - D_L19_001E2080[1];
        v10[2] = s60[2] - D_L19_001E2080[2];
        v10[3] = s60[3];
    }
    if (*(s32 *)s != 3 && dist < 256.0f && 0.0f < D_L19_001E2080[8] * v10[0] + D_L19_001E2080[9] * v10[1]) {
        if (*(s32 *)s != 2) {
            *(Q *)v20 = 0;
            func_L01_00466F50(s + 0x60, v20, 0, -1.0f, 0.0f);
            if (dist < 128.0f) {
                f32 *a = (f32 *)(s + 0x60);
                f32 *b = (f32 *)(s + 0x50);
                v30[0] = a[0] + b[0];
                v30[1] = a[1] + b[1];
                v30[2] = a[2] + b[2];
                v30[3] = a[3];
                func_0038CE20(v30, v30, 0.5f);
                func_L01_00466F50(v30, v20, 0, -1.0f, 0.0f);
            }
        }
        if (dist < 128.0f) {
            if (D_L19_001DF240 & 1) {
                *(Q *)v20 = 0;
                v20[0] = func_003824E0(-0.005f, 0.005f);
                v20[1] = func_003824E0(-0.005f, 0.005f);
                *(Q *)v30 = 0;
                v20[2] = 0.03f;
                v20[3] = 0.1f;
                v30[0] = v20[0] * 0.5f;
                v30[1] = v20[1] * 0.5f;
                v30[2] = 0.01f;
                v30[3] = 0.4f;
                func_L01_00463378(s + 0x60, v20, v30, 0x75000000, 0x60404040, 4, 8, 8, -1);
            } else {
                *(Q *)v20 = 0;
                v20[0] = func_003824E0(-0.01f, 0.01f);
                v20[1] = func_003824E0(-0.01f, 0.01f);
                *(Q *)v30 = 0;
                v20[2] = 0.03f;
                v20[3] = 0.1f;
                v30[0] = v20[0] * 0.5f;
                v30[1] = v20[1] * 0.5f;
                v30[2] = 0.0f;
                v30[3] = 0.2f;
                func_L01_00463378(s + 0x60, v20, v30, 0x7F0040FF, 0x40204060, 2, 5, 3, -1);
            }
        }
    }
    slot = *(s32 *)(s + 8);
    rec = D_1A30B0 + (slot << 7);
    if (slot < 0 || *(u8 **)(rec + 0xDC) != o) {
        *(s32 *)(s + 8) = func_003A52A0(0, 0xC, o);
    }
    slot = *(s32 *)(s + 8);
    if (slot >= 0) {
        *(Q *)(D_1A3190 + (slot << 7)) = *(Q *)(s + 0x60);
    }
    if (func_0038CAD0(s + 0x14) != 0 && hit != 0) {
        func_003A52A0(1, 0, o);
        *(s32 *)(s + 0x14) = 0x19;
    }
    func_L01_00404808((void *)func_L19_003AEC08, o);
}
