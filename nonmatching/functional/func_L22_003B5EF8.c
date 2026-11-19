/* functional: medium. Per-frame update of a Mylon tile-bound moby (PAL L22): runs the init in state 0, tracks the tile counters in D_001BBE90 and the player direction, applies the pending impulse vectors, and every 8th frame fires the effect call and the ground test. Prototype of func_L22_003B72F0 and a few helper argument types are inferred from the asm; the stack words passed as zero args are explicit. */
typedef int Q __attribute__((mode(TI)));
extern u8 D_L22_00236640[];
extern u8 D_001BBE90[];
extern s32 D_001D545C;
extern s32 D_L22_001DF8C0;
extern u8 *D_L22_001DFD9C;
extern s32 D_L22_001E9858;
extern f32 D_001A4BE0[];
extern f32 D_L22_001DE460;
extern f32 D_L22_001DE464;
extern f32 D_L22_001DE468;
extern u8 D_L22_001DE470[];
extern s32 func_L22_003B6698(void *);
extern void func_L03_0043BE98(void *, void *, s32, s32, s32);
extern void func_L01_00452860(void *, void *, s32);
extern f32 func_L01_0040E570(void *, void *);
extern f32 func_0038D160(f32, f32);
extern void func_L22_003B72F0(void *, void *, s32, f32);
extern void func_L01_0044FD88(void *, void *, s32, s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D570(void *, void *);
extern void func_0038D328(void *, void *);
extern void func_0038D640(void *, void *, void *);
extern void func_0038D590(void *, void *);
extern s32 func_L01_00452F78(void *, s32, s32, s32);
extern void func_L22_003B6C58(void *);
extern void func_L02_003A5010(void *);
extern void func_L01_00456BD0(void *, s32);
extern void func_L01_00456C98(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);

static s32 tile_count(u16 h, s32 lvl) {
    s32 idx = (s16)h;
    u8 b = D_001BBE90[(idx >> 1) + (lvl << 10)];
    return ((h & 1) ? (b >> 4) : b) & 7;
}

s32 func_L22_003B5EF8(void *obj) {
    u8 *o = obj;
    u8 *p = *(u8 **)(o + 0x68);
    u16 h;
    s32 idx;
    u8 *r;
    s32 frame;
    s32 hit;

    if (o[0x20] == 0) {
        if (func_L22_003B6698(o)) return 1;
    }
    func_L03_0043BE98(o, p + 0x240, 0, 4, o[0x20] != 6);
    h = *(u16 *)(o + 0xB2);
    idx = (s16)h;
    if (D_L22_00236640[0x464 + idx] == 0 && tile_count(h, D_001D545C) == 0) {
        if (D_001D545C != 0x16) func_L01_00452860(o, p + 0x30, 0);
    }

    if (*(s32 *)(p + 0x4A0) > 0 && *(s32 *)(p + 0x464) != -1 && o[0x95] == 1 &&
        (D_L22_001DF8C0 & 0x1F) == (((s32)o >> 8) & 0x1F)) {
        r = D_L22_001DFD9C + (*(s32 *)(p + 0x464) << 8);
        if (0.1f < func_L01_0040E570(o + 0x10, r + 0x10)) {
            Q v = *(Q *)(r + 0x10);
            func_L22_003B72F0(o, &v, 1,
                              func_0038D160(D_001A4BE0[0x80 / 4] - *(f32 *)(r + 0x10),
                                            D_001A4BE0[0x84 / 4] - *(f32 *)(r + 0x14)));
        }
        if (*(s32 *)(p + 0x530) != 0) {
            u8 *tp = &D_001BBE90[((s16)h >> 1) + (D_001D545C << 10)];
            if (h & 1) {
                if (((*tp >> 4) & 7) != 7) *tp += 0x10;
            } else {
                if ((*tp & 7) != 7) *tp += 1;
            }
        }
    }
    if (*(s32 *)(p + 0x530) != 0) {
        if ((D_L22_00236640[0x464 + idx] != 0 || tile_count(h, D_001D545C) != 0) && o[0x95] == 1) {
            r = D_L22_001DFD9C + (*(s32 *)(p + 0x464) << 8);
            *(s32 *)(p + 0x4A0) += 1;
            if (0.1f < func_L01_0040E570(o + 0x10, r + 0x10)) {
                Q v = *(Q *)(r + 0x10);
                func_L22_003B72F0(o, &v, 1,
                                  func_0038D160(D_001A4BE0[0x80 / 4] - *(f32 *)(r + 0x10),
                                                D_001A4BE0[0x84 / 4] - *(f32 *)(r + 0x14)));
            }
        }
    }

    if (*(u8 **)(p + 0x48C) != 0) {
        f32 d[4] __attribute__((aligned(16)));
        f32 m[16] __attribute__((aligned(16)));
        f32 n[16] __attribute__((aligned(16)));
        u8 *q;
        func_L01_0044FD88(o, *(u8 **)(p + 0x48C), 3, 0);
        q = *(u8 **)(p + 0x48C);
        func_0038CE20(d, q + 0xC0, D_L22_001DE460);
        ((f32 *)(*(u8 **)(p + 0x48C) + 0x10))[0] += d[0];
        ((f32 *)(*(u8 **)(p + 0x48C) + 0x10))[1] += d[1];
        ((f32 *)(*(u8 **)(p + 0x48C) + 0x10))[2] += d[2];
        func_0038CE20(d, *(u8 **)(p + 0x48C) + 0xD0, D_L22_001DE464);
        ((f32 *)(*(u8 **)(p + 0x48C) + 0x10))[0] += d[0];
        ((f32 *)(*(u8 **)(p + 0x48C) + 0x10))[1] += d[1];
        ((f32 *)(*(u8 **)(p + 0x48C) + 0x10))[2] += d[2];
        func_0038CE20(d, *(u8 **)(p + 0x48C) + 0xE0, D_L22_001DE468);
        ((f32 *)(*(u8 **)(p + 0x48C) + 0x10))[0] += d[0];
        ((f32 *)(*(u8 **)(p + 0x48C) + 0x10))[1] += d[1];
        ((f32 *)(*(u8 **)(p + 0x48C) + 0x10))[2] += d[2];
        func_0038D570(m, *(u8 **)(p + 0x48C) + 0xC0);
        func_0038D328(n, D_L22_001DE470);
        func_0038D640(m, m, n);
        func_0038D590(*(u8 **)(p + 0x48C) + 0xC0, m);
    }

    hit = 0;
    if (D_001D545C != 0x16) {
        hit = 1;
    } else if (*(s32 *)(p + 0x53C) != 0) {
        if (D_L22_00236640[0x464 + idx] != 0 || tile_count(h, 0x16) != 0) hit = 1;
    }
    if (hit && func_L01_00452F78(o, 0, 0, 0)) {
        func_L22_003B6C58(o);
    }
    if (D_001D545C == 0x16 && D_L22_00236640[0x464 + idx] == 0 && tile_count(h, 0x16) == 0) {
        o[0xA8] = 0xFF;
    }

    if (p[0x3E] == 2 || p[0x5E] != 0 || p[0x60] != 0) {
        func_L02_003A5010(o);
        return 1;
    }
    if (p[0x5F] != 0) {
        func_L01_00456BD0(o, 5);
    } else if (0.0f < *(f32 *)(p + 0x30)) {
        func_L01_00456BD0(o, 3);
    }
    frame = D_L22_001DF8C0;
    if ((idx + 8) % 8 != frame % 8) return 0;

    {
        s32 was = (*(s16 *)(p + 0x234) == 1);
        s32 sel = (o[0x95] == 1);
        s32 k = (p[0x5F] != 0) ? 3 : 1;
        func_L01_00456C98(o, sel ? *(s32 *)(p + 0x430) : *(s32 *)(p + 0x438), (s32)(p + 0x4F0), 0, 0, 0, k, 0, 0, 0,
                          sel ? *(f32 *)(p + 0x434) : *(f32 *)(p + 0x43C), 10.0f, 1.0f);
        if (*(s16 *)(p + 0x234) != 1) return 0;
        if (was) return 0;
    }
    {
        f32 a[4] __attribute__((aligned(16)));
        f32 b[4] __attribute__((aligned(16)));
        *(Q *)a = *(Q *)(o + 0x10);
        a[2] += 1.0f;
        *(Q *)b = *(Q *)(p + 0x220);
        b[2] += 1.0f;
        if (func_003D3CB0(a, b, 0, o, 0)) {
            if (D_L22_001E9858 != *(s32 *)(p + 0x230)) *(s16 *)(p + 0x234) = 0;
        }
    }
    return 0;
}
