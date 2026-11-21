/* functional: medium. 354 diff words at the file's flags (frame 0xE0 vs 0xD0, register allocation, branch-likely layout); chain walk (root via p+0xD4, then down via p+0xD0), the clamp of p+0xC8 to [-0.3,0.3] after -0.00392, both func_003C4138 branches (target at p+0xD4 or none), the ray-test/ground branch and the 0x1F9 state flips read against retail; constants checked bit-exact (0.00392, 0.004, 0.707, 0.55, 0.01, +-0.3). */
typedef struct { f32 x, y, z, w; } V4;
typedef int Q16 __attribute__((mode(TI)));
extern u8 D_001A4BE0[];
extern u8 D_L01_001EAA20[];
extern s32 D_001DFB40_sda;
extern s32 func_003C4B50(void *);
extern void func_0038D000(void *, void *, void *);
extern void func_L01_0033C520(u8 *, s32, u8 *);
extern void func_L01_0033C030(u8 *);
extern f32 func_003C4138(void *, f32, f32);
extern void func_L01_0044C998(u8 *, u8 *, void *, void *, void *, void *);
extern u8 *func_003C4D58(u8 *);
extern void func_003C4DA8(void *, void *, void *, void *);
extern f32 func_0038CF38(void *, void *);
extern s32 func_003D3CB0(void *, void *, s32, u8 *, s32);
extern f32 func_0038CEA8(void *);

void func_L01_0033CBC0(u8 *m) {
    Q16 buf[8];
    u8 *sp = (u8 *)buf;
    u8 *hero;
    u8 *root;
    u8 *cur;
    u8 *next;
    u8 *p;
    u8 *tgt;
    u8 *r2;
    s32 fl;
    s32 hit;
    f32 f;
    f32 g;
    f32 ret;
    V4 *a;
    V4 *b;

    if (m[0x20] == 0) {
        return;
    }
    p = *(u8 **)(m + 0x68);
    if (*(s32 *)(p + 0xE4) == D_001DFB40_sda) {
        return;
    }
    root = m;
    while (*(u8 **)(*(u8 **)(root + 0x68) + 0xD4) != 0) {
        root = *(u8 **)(*(u8 **)(root + 0x68) + 0xD4);
    }
    hero = D_001A4BE0;
    cur = root;
    do {
        p = *(u8 **)(cur + 0x68);
        fl = *(s32 *)(p + 0xDC);
        next = *(u8 **)(p + 0xD0);
        if ((fl & 4) == 0) {
            *(s32 *)(p + 0xDC) = fl & -0x11;
        }
        *(s32 *)(p + 0xDC) = *(s32 *)(p + 0xDC) & -5;
        if (func_003C4B50(cur) == 0) {
            return;
        }
        if ((*(s32 *)(p + 0xDC) & 2) != 0) {
            return;
        }
        *(s32 *)(p + 0xE4) = D_001DFB40_sda;
        if (cur[0x20] != 0) {
            a = (V4 *)(hero + 0x80);
            b = (V4 *)(cur + 0x10);
            ((V4 *)(sp + 0x30))->x = a->x - b->x;
            ((V4 *)(sp + 0x30))->y = a->y - b->y;
            ((V4 *)(sp + 0x30))->z = a->z - b->z;
            ((V4 *)(sp + 0x30))->w = a->w;
            func_0038D000(sp + 0x30, sp + 0x30, cur + 0xC0);
            f = *(f32 *)(sp + 0x30);
            if (f < 0.0f) {
                f = -f;
            }
            if (f < 0.55f) {
                f = *(f32 *)(sp + 0x34);
                if (f < 0.0f) {
                    f = -f;
                }
                if (f < 0.55f) {
                    g = *(f32 *)(sp + 0x38);
                    if (g < 0.0f) {
                        f = -(*(f32 *)(hero + 0x270) + *(f32 *)(hero + 0x284));
                        if (f < g) {
                            if (cur[0x20] == 1 || cur[0x20] == 5) {
                                func_L01_0033C520(cur, (*(s16 *)(cur + 0xAA) ^ 0x1F9) < 1u, 0);
                                func_L01_0033C030(cur);
                            }
                        }
                    }
                }
            }
            f = *(f32 *)(p + 0xC8) - 0.00392f;
            if (f < -0.3f) {
                f = -0.3f;
            }
            if (0.3f < f) {
                f = 0.3f;
            }
            *(f32 *)(p + 0xC8) = f;
            if (*(s32 *)(p + 0x120) != 0) {
                tgt = *(u8 **)(p + 0xD4);
                if (tgt == 0) {
                    f = *(f32 *)(p + 0xCC) - 0.004f;
                    *(f32 *)(p + 0xCC) = f;
                    g = f;
                    if (g < 0.0f) {
                        g = -g;
                    }
                    ret = func_003C4138(p + 0x124, 0.0f, g);
                } else {
                    f = *(f32 *)(p + 0xCC) - 0.004f;
                    g = f;
                    if (g < 0.0f) {
                        g = -g;
                    }
                    *(f32 *)(p + 0xCC) = f;
                    ret = func_003C4138(p + 0x124, *(f32 *)(*(u8 **)(tgt + 0x68) + 0x124) + 1.0f, g);
                }
                if (ret == 0.0f) {
                    *(f32 *)(p + 0xCC) = 0.0f;
                }
                *(Q16 *)(sp + 0x40) = *(Q16 *)(p + 0x100);
                *(f32 *)(sp + 0x48) = *(f32 *)(sp + 0x48) + *(f32 *)(p + 0x124);
                if (cur != 0) {
                    *(s16 *)(cur + 0x36) = 0x7F80;
                }
                *(Q16 *)(sp + 0x50) = *(Q16 *)(cur + 0x10);
                *(Q16 *)(sp + 0x60) = *(Q16 *)(cur + 0xF0);
                func_L01_0044C998(cur, *(u8 **)(p + 0x120), sp + 0x40, p + 0x110, cur + 0x10, cur + 0xF0);
                r2 = func_003C4D58(*(u8 **)(p + 0x120));
                if ((*(s32 *)(r2 + 0x3C) & 4) != 0) {
                    *(Q16 *)(p + 0x100) = *(Q16 *)(sp + 0x40);
                    *(f32 *)(p + 0x108) = *(f32 *)(p + 0x108) - *(f32 *)(p + 0x124);
                }
                a = (V4 *)(cur + 0x10);
                b = (V4 *)(sp + 0x50);
                ((V4 *)(sp + 0x70))->x = a->x - b->x;
                ((V4 *)(sp + 0x70))->y = a->y - b->y;
                ((V4 *)(sp + 0x70))->z = a->z - b->z;
                ((V4 *)(sp + 0x70))->w = a->w;
                *(f32 *)(sp + 0x7C) = *(f32 *)(p + 0xCC);
                *(Q16 *)(p + 0xC0) = *(Q16 *)(sp + 0x70);
                func_003C4DA8(p + 0x70, p + 0xC0, sp + 0x60, cur + 0xF0);
                if (*(u8 **)(p + 0x12C) != 0) {
                    *(Q16 *)(*(u8 **)(p + 0x12C) + 0x10) = *(Q16 *)(cur + 0x10);
                }
            } else {
                hit = 0;
                tgt = *(u8 **)(p + 0xD4);
                if (tgt != 0) {
                    if (0.707f < func_0038CF38(cur + 0x10, tgt + 0x10)) {
                        hit = 0;
                        *(s32 *)(p + 0xD4) = 0;
                    } else {
                        tgt = *(u8 **)(p + 0xD4);
                        *(Q16 *)(sp + 0x20) = *(Q16 *)(tgt + 0x10);
                        *(f32 *)(sp + 0x28) = *(f32 *)(sp + 0x28) + 1.0f;
                        if (*(f32 *)(cur + 0x18) + *(f32 *)(p + 0xC8) < *(f32 *)(sp + 0x28)) {
                            hit = 1;
                        }
                    }
                }
                if (*(s32 *)(p + 0xD4) == 0) {
                    *(Q16 *)sp = *(Q16 *)(cur + 0x10);
                    *(Q16 *)(sp + 0x10) = *(Q16 *)(cur + 0x10);
                    *(f32 *)(sp + 8) = *(f32 *)(sp + 8) + *(f32 *)(p + 0xE0) * 0.75f;
                    *(f32 *)(sp + 0x18) = *(f32 *)(sp + 0x18) + *(f32 *)(p + 0xC8);
                    hit = func_003D3CB0(sp, sp + 0x10, 2, 0, 0);
                    *(Q16 *)(sp + 0x20) = *(Q16 *)D_L01_001EAA20;
                }
                if (hit == 0) {
                    *(s32 *)(p + 0xDC) = *(s32 *)(p + 0xDC) | 4;
                    a = (V4 *)(cur + 0x10);
                    b = (V4 *)(p + 0xC0);
                    a->x = a->x + b->x;
                    a->y = a->y + b->y;
                    a->z = a->z + b->z;
                } else {
                    if ((*(s32 *)(p + 0xDC) & 0x20) == 0) {
                        *(f32 *)(cur + 0x18) = *(f32 *)(sp + 0x28);
                        *(s32 *)(p + 0xC8) = 0;
                    } else if (!(0.010000001f < func_0038CEA8(p + 0xC0))) {
                        *(f32 *)(cur + 0x18) = *(f32 *)(sp + 0x28);
                        *(s32 *)(p + 0xC8) = 0;
                    } else if (*(s16 *)(cur + 0xAA) == 0x1F9 && cur[0x20] == 1) {
                        cur[0xBC] = 0;
                        cur[0x20] = 5;
                        *(f32 *)(cur + 0x18) = *(f32 *)(sp + 0x28);
                        *(s32 *)(p + 0xC8) = 0;
                    } else {
                        tgt = *(u8 **)(p + 0xD4);
                        if (tgt == 0) {
                            *(f32 *)(cur + 0x18) = *(f32 *)(sp + 0x28);
                            *(s32 *)(p + 0xC8) = 0;
                        } else if (*(s16 *)(tgt + 0xAA) != 0x1F9) {
                            *(f32 *)(cur + 0x18) = *(f32 *)(sp + 0x28);
                            *(s32 *)(p + 0xC8) = 0;
                        } else if (tgt[0x20] != 1) {
                            *(f32 *)(cur + 0x18) = *(f32 *)(sp + 0x28);
                            *(s32 *)(p + 0xC8) = 0;
                        } else {
                            tgt[0x20] = 5;
                            (*(u8 **)(p + 0xD4))[0xBC] = 0;
                            *(f32 *)(cur + 0x18) = *(f32 *)(sp + 0x28);
                            *(s32 *)(p + 0xC8) = 0;
                        }
                    }
                }
            }
        }
        cur = next;
    } while (cur != 0);
}
