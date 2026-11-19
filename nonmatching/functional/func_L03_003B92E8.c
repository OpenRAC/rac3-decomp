/* functional: medium. Scalar math replaces VU0 vector ops; info struct size on stack guessed 0x30 bytes; 220 words differ in scheduling. */
extern u8 D_001A30B0[];
extern u8 D_L03_001E9200[];
__asm__(".extern D_L03_001E9200, 16");
extern s32 D_L03_001D6694;
__asm__(".extern D_L03_001D6694, 16");
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003C2F58(s32, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00446748(void *, void *, s32, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern s32 func_L01_003FB640(void *, s32, void *, f32);
extern f32 func_0038CF38(void *, void *);
extern void func_L01_00404808(void *, void *);
extern void func_L01_004AAC98(s32, s32, void *, s32);
extern void func_003A4F28(s32);
extern void func_003C2880(void *);
extern void func_L03_003B97E0(u8 *);

void func_L03_003B92E8(u8 *o) {
    u8 *s = *(u8 **)(o + 0x68);
    u8 *home;
    u8 *hit;
    vu0_v4 d;
    vu0_v4 old;
    vu0_v4 info[3];
    s32 w;
    s32 st;

    st = o[0x20];
    if (st == 0) {
        w = *(s32 *)(s + 0x38);
        if (w == -1 || *(void **)(D_001A30B0 + w * 128 + 0xDC) != *(void **)(o + 0xB8) || D_001A30B0[w * 128 + 0xD0] == 0) {
            *(s32 *)(s + 0x38) = func_003A52A0(6, 4, *(void **)(o + 0xB8));
        }
        home = s + 0x10;
        func_003C2F58(*(s32 *)(s + 0x30), *(s32 *)(s + 0x34), s + 0x10);
        func_003C2F58(*(s32 *)(s + 0x30), *(s32 *)(s + 0x34) - 0x20, s);
        if (*(s32 *)(s + 0x28) == 0) {
            *(f32 *)(s + 0x2C) = *(f32 *)(s + 0x2C) + *(f32 *)(s + 0x20);
        } else {
            *(f32 *)(s + 0x2C) = *(f32 *)(s + 0x2C) - *(f32 *)(s + 0x20);
        }
        old = *(vu0_v4 *)(o + 0x10);
        d.x = *(f32 *)(s + 0) - *(f32 *)(s + 0x10);
        d.y = *(f32 *)(s + 4) - *(f32 *)(s + 0x14);
        d.z = *(f32 *)(s + 8) - *(f32 *)(s + 0x18);
        func_0038CF68(&d, &d, *(f32 *)(s + 0x2C));
        *(f32 *)(o + 0x10) = *(f32 *)(s + 0x10) + d.x;
        *(f32 *)(o + 0x14) = *(f32 *)(s + 0x14) + d.y;
        *(f32 *)(o + 0x18) = *(f32 *)(s + 0x18) + d.z;
        *(f32 *)(o + 0x1C) = *(f32 *)(s + 0x1C);
        func_L01_00446748(&info[0], o, 1, 1.0f);
        *(u16 *)((u8 *)info + 0x1A) = *(u16 *)(o + 0xAA);
        if (*(s32 *)(s + 0x28) == 0) {
            if (func_003D3CB0(&old, o + 0x10, 0, o, &info[0]) != 0
                || func_L01_003FB640(o + 0x10, 0, o, 0.3f) != 0) {
                hit = *(u8 **)(D_L03_001E9200 + 0x18);
                if (hit != 0) {
                    s32 h = *(s16 *)(hit + 0xAA);
                    if (h == 0x1C04 || h == 0x1C06) {
                        *(s32 *)(s + 0x28) = 1;
                        hit = *(u8 **)(D_L03_001E9200 + 0x18);
                        if (*(s16 *)(hit + 0xAA) == 0x1C04 && *(s32 *)(*(u8 **)(hit + 0x68) + 0x24) == 1) {
                            *(u8 **)(s + 0x24) = hit;
                            hit[0x20] = 1;
                            *(s32 *)(*(u8 **)(s + 0x24) + 0x98) = 0;
                        }
                        return;
                    }
                }
            }
        }
        if (*(s32 *)(s + 0x28) == 0) {
            if (func_0038CF38(o + 0x10, s) <= *(f32 *)(s + 0x20) * 0.88f) {
                goto arrived;
            }
        } else if (*(s32 *)(s + 0x28) == 1) {
            if (func_0038CF38(o + 0x10, home) <= *(f32 *)(s + 0x20) * 0.88f) {
            arrived:
                if (*(u8 **)(s + 0x24) != 0) {
                    u8 *tgt = *(u8 **)(o + 0xB8);
                    (*(u8 **)(s + 0x24))[0x20] = 2;
                    if (tgt != 0 && *(s16 *)(tgt + 0xAA) == 0x1AE0) {
                        func_L01_004AAC98(7, 0, tgt, 0x1AE0);
                    }
                }
                w = *(s32 *)(s + 0x38);
                if (w != -1 && *(void **)(D_001A30B0 + w * 128 + 0xDC) == *(void **)(o + 0xB8) && D_001A30B0[w * 128 + 0xD0] != 0) {
                    func_003A4F28(w);
                }
                *(s32 *)(s + 0x38) = -1;
                func_003C2880(o);
                return;
            }
        }
        func_L01_00404808(func_L03_003B97E0, o);
        if (*(u8 **)(s + 0x24) != 0) {
            *(vu0_q *)(*(u8 **)(s + 0x24) + 0x10) = *(vu0_q *)(o + 0x10);
        }
    } else if (st == 1) {
        if (D_L03_001D6694 != 7) {
            w = *(s32 *)(s + 0x38);
            if (w != -1 && *(void **)(D_001A30B0 + w * 128 + 0xDC) == *(void **)(o + 0xB8) && D_001A30B0[w * 128 + 0xD0] != 0) {
                func_003A4F28(w);
            }
            *(s32 *)(s + 0x38) = -1;
            func_003C2880(o);
        }
    }
}
