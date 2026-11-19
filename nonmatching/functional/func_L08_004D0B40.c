/* functional: medium. Written from the asm: hero (D_001A4BE0) per-frame aim/target update for a tracked object (D_L08_001E8A80); same reads, writes, calls and order; vsub.xyz+sqc2 written as scalar subtracts (w copied); boot_elf func_12FE98 argument types unknown (void *). Compiles at the same frame size, bytes differ widely. */
typedef int u128_004D0B40 __attribute__((mode(TI)));
typedef union { u8 b[0x2900]; s16 h[0x1480]; u16 uh[0x1480]; s32 i[0xA40]; f32 f[0xA40]; u128_004D0B40 q[0x290]; } Hero_004D0B40;
typedef union { u8 b[0x400]; s16 h[0x200]; u16 uh[0x200]; s32 i[0x100]; f32 f[0x100]; u128_004D0B40 q[0x40]; } Obj_004D0B40;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_004D0B40;

extern Hero_004D0B40 D_001A4BE0;
extern Obj_004D0B40 D_L08_001E8A80;
extern Obj_004D0B40 D_L08_001E8AA0;
extern Obj_004D0B40 D_L08_001E8AC0;
extern s32 D_L08_001D673C;
extern s32 D_001D545C;

extern s32 func_L01_004E9308(void);
extern void func_L01_004EF6F0(void *, void *, f32, f32, s32);
extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
extern s32 func_L01_003FE908(void);
extern s32 func_003D5630(void);
extern f32 func_003C3EC8(void *, void *);
extern s32 func_003C4B50(void *);
extern u8 *func_00382348(void *);
extern u8 *func_003C4D58(void *);
extern f32 func_L01_00451580(void *);
extern f32 func_0038CF00(void *, void *);
extern void func_12FE98(void *, void *);
extern f32 func_L01_00511848(void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CE68(void *, void *);
extern f32 func_003C4138(f32 *, f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_004F40A8(void *, void *);
extern void func_L01_00511038(void *, s32, f32, f32, f32);

void func_L08_004D0B40(void) {
    V4_004D0B40 sp[7];
    Hero_004D0B40 *h = &D_001A4BE0;
    Obj_004D0B40 *g;
    Obj_004D0B40 *t;
    u8 *r;
    f32 f20;
    f32 f;
    s32 lvl;
    s32 i;

    h->q[0x2F0 / 16] = 0;
    h->uh[0x36E / 2] = h->uh[0x36E / 2] + 1;
    h->uh[0x36C / 2] = h->uh[0x36C / 2] + 1;
    h->f[0x2C8 / 4] = 1.0f;
    h->f[0x33C / 4] = 32.0f;
    h->i[0x2C0 / 4] = 0;
    h->i[0x2C4 / 4] = 0;
    h->i[0x340 / 4] = 0;
    h->i[0x338 / 4] = 0;
    h->h[0x36A / 2] = 0;
    h->i[0x35C / 4] = 0;
    if (h->i[0x358 / 4] != 0) {
        h->i[0x358 / 4] = h->i[0x358 / 4] + 1;
    }

    f20 = h->f[0x284 / 4] * 2.2f;
    if (h->i[0x25CC / 4] == 2) {
        f20 = h->f[0x284 / 4] * 2.9f;
    }
    if (func_L01_004E9308() != 0) {
        f20 = 0.0f;
    }
    func_L01_004EF6F0(&sp[1], &sp[0], f20, -48.0f, 1);

    if (func_003D3CB0(&sp[1], &sp[0], 2, h->i[0x25C0 / 4], 0) != 0) {
        h->b[0x147F] = func_L01_003FE908();
        g = &D_L08_001E8A80;
        if (g->i[0x18 / 4] != 0) {
            lvl = D_001D545C;
            h->b[0x147F] = 0;
            t = (Obj_004D0B40 *)g->i[0x18 / 4];
            if (lvl == 2) {
                if (t->h[0xAA / 2] == 0x18C6) h->b[0x147F] = lvl;
                if (((Obj_004D0B40 *)g->i[0x18 / 4])->h[0xAA / 2] == 0x18AF) h->b[0x147F] = lvl;
            }
            if (D_001D545C == 5) {
                if (((Obj_004D0B40 *)g->i[0x18 / 4])->h[0xAA / 2] == 0x1607) h->b[0x147F] = 2;
                if (((Obj_004D0B40 *)g->i[0x18 / 4])->h[0xAA / 2] == 0x1681) h->b[0x147F] = 2;
                if (((Obj_004D0B40 *)g->i[0x18 / 4])->h[0xAA / 2] == 0x15F7) h->b[0x147F] = 2;
                if (((Obj_004D0B40 *)g->i[0x18 / 4])->h[0xAA / 2] == 0x16BB) h->b[0x147F] = 3;
            }
            if (D_001D545C == 8) {
                if (((Obj_004D0B40 *)g->i[0x18 / 4])->h[0xAA / 2] == 0x1A44) h->b[0x147F] = 2;
            }
            if (D_001D545C == 10) {
                if (((Obj_004D0B40 *)g->i[0x18 / 4])->h[0xAA / 2] == 0x1645) h->b[0x147F] = 3;
                if (((Obj_004D0B40 *)g->i[0x18 / 4])->h[0xAA / 2] == 0x162E) h->b[0x147F] = 1;
            }
            if (D_001D545C == 0x15) {
                if (((Obj_004D0B40 *)g->i[0x18 / 4])->h[0xAA / 2] == 0x1BA9) h->b[0x147F] = 3;
            }
        }

        i = func_003D5630();
        h->uh[0x1470 / 2] = i;
        if ((u16)i == 0) {
            f = func_003C3EC8(&D_L08_001E8AA0, &h->b[0x2D0]);
            h->f[0x350 / 4] = f;
            if (h->f[0x88 / 4] < f) {
                if (!(h->i[0x358 / 4] > 0)) {
                    h->i[0x358 / 4] = 1;
                }
            }
            if (func_003D3CB0(&sp[1], &sp[0], 0x24, h->i[0x25C0 / 4], 0) == 0) {
                goto tail;
            }
            h->b[0x147F] = func_L01_003FE908();
        }

        if (g->i[0x18 / 4] != 0) {
            if (func_003C4B50((void *)g->i[0x18 / 4]) != 0) {
                h->h[0x36A / 2] = 1;
            }
            r = func_00382348((void *)g->i[0x18 / 4]);
            if (r != 0) {
                if ((*(u16 *)(r + 0x1E) & 8) != 0) {
                    h->h[0x36A / 2] = 1;
                }
            }
            r = func_003C4D58((void *)g->i[0x18 / 4]);
            if (r != 0) {
                if ((*(s32 *)(r + 0x3C) & 8) != 0) {
                    h->h[0x36A / 2] = 1;
                }
            }
        }

        if (g->i[0x1C / 4] > 0) {
            h->q[0x2F0 / 16] = g->q[0x20 / 16];
            f20 = g->f[0x28 / 4];
            if (D_L08_001D673C != 0) {
                f20 = func_L01_00451580(&g->b[0x20]);
            }
            h->f[0x338 / 4] = f20;
            f = func_0038CF00(&h->b[0x80], &h->b[0x2F0]);
            h->i[0x35C / 4] = g->i[0x18 / 4];
            h->f[0x33C / 4] = f;
            func_12FE98(&h->b[0x2C0], &g->b[0x40]);
            h->f[0x340 / 4] = func_L01_00511848(&g->b[0x40]);
            h->f[0x34C / 4] = func_0038D160(g->f[0x40 / 4], g->f[0x44 / 4]);
            /* sp[2].xyz = hero.pos(0x2F0) - hero.pos(0x80) */
            {
                f32 *a = &h->f[0x2F0 / 4];
                f32 *b = &h->f[0x80 / 4];
                sp[2].x = a[0] - b[0];
                sp[2].y = a[1] - b[1];
                sp[2].z = a[2] - b[2];
                sp[2].w = a[3];
            }
            if (0.0f < func_0038CE68(&sp[2], &h->b[0x2C0])) {
                h->f[0x33C / 4] = -h->f[0x33C / 4];
            }
            if (h->f[0x33C / 4] < 0.02f) {
                h->uh[0x36C / 2] = 0;
                if (h->f[0x340 / 4] <= 0.874f || h->b[0x25F4] != 0) {
                    h->uh[0x36E / 2] = 0;
                    h->i[0xBF0 / 4] = g->i[0x18 / 4];
                }
            }
        }
    }

tail:
    if (h->f[0x350 / 4] < h->f[0x88 / 4]) {
        h->i[0x358 / 4] = 0;
    }
    if (h->h[0x36E / 2] == 0) {
        h->q[0x300 / 16] = h->q[0x2F0 / 16];
        h->i[0x360 / 4] = h->i[0x360 / 4] + 1;
    } else {
        h->i[0x360 / 4] = 0;
    }

    h->q[0x2E0 / 16] = 0;
    switch (h->b[0x25F4]) {
    case 0:
        h->f[0x2E8 / 4] = -1.0f;
        break;
    case 1:
        if (h->f[0x31C / 4] == 0.0f) {
            h->q[0x2E0 / 16] = h->q[0x2C0 / 16];
            func_0038CE20(&h->b[0x2E0], &h->b[0x2E0], -1.0f);
        } else {
            func_003C4138(&h->f[0x31C / 4], 0.0f, 1.0f);
            h->q[0x2E0 / 16] = h->q[0x310 / 16];
            func_0038CE20(&h->b[0x2C0], &h->b[0x2E0], -1.0f);
        }
        break;
    case 2:
        f = -1.0f;
        if (0.0f < h->f[0xBC / 4]) {
            f = 1.0f;
        }
        h->f[0x2E0 / 4] = h->f[0xB0 / 4] - h->f[0x80 / 4];
        h->f[0x2E4 / 4] = h->f[0xB4 / 4] - h->f[0x84 / 4];
        h->f[0x2E8 / 4] = h->f[0xB8 / 4] - h->f[0x88 / 4];
        h->f[0x2EC / 4] = h->f[0xBC / 4];
        func_0038CF68(&h->b[0x2E0], &h->b[0x2E0], f);
        break;
    }

    h->i[0x344 / 4] = 0;
    h->i[0x348 / 4] = 0;
    h->i[0x330 / 4] = 0;
    h->i[0x334 / 4] = 0;
    h->i[0x328 / 4] = 0;
    h->i[0x32C / 4] = 0;
    h->i[0x320 / 4] = 0;
    h->i[0x324 / 4] = 0;
    if (!(h->f[0x33C / 4] < 0.25f)) {
        return;
    }
    lvl = h->i[0x25CC / 4];
    if (!(lvl == 0 || lvl == 0xC || lvl == 9 || lvl == 7 || lvl == 1 || (lvl == 4 && h->b[0x46C] != 0))) {
        return;
    }
    func_L01_004F40A8(&h->b[0x2C0], &sp[2]);
    if (-0.7853982f < sp[2].y && sp[2].y < 0.7853982f) {
        h->f[0x344 / 4] = sp[2].y;
    }
    if (-0.7853982f < sp[2].x && sp[2].x < 0.7853982f) {
        h->f[0x348 / 4] = sp[2].x;
    }
    for (i = 0; i < 2; i++) {
        f32 ang = 1.5707964f;
        if (i == 1) ang = -ang;
        func_L01_00511038(&sp[3], 1, 0.2f, ang, 0.45f);
        func_L01_00511038(&sp[4], 1, 0.2f, ang, -0.45f);
        if (func_003D3CB0(&sp[3], &sp[4], 0x22, h->i[0x25C0 / 4], 0) != 0) {
            if (D_L08_001D673C != 0) {
                f = func_L01_00451580(&D_L08_001E8AA0);
                f = f - func_L01_00451580(&h->b[0x2F0]);
                h->f[0x320 / 4 + i] = f;
            } else {
                h->f[0x320 / 4 + i] = D_L08_001E8A80.f[0x28 / 4] - h->f[0x338 / 4];
            }
            f = h->f[0x320 / 4 + i];
            if (f < 0.0f) f = -f;
            if (0.4f < f) {
                h->i[0x320 / 4 + i] = 0;
            }
            func_12FE98(&sp[6], &D_L08_001E8AC0);
            func_L01_004F40A8(&sp[6], &sp[5]);
            if (-0.7853982f < sp[5].y && sp[5].y < 0.7853982f) {
                h->f[0x328 / 4 + i] = sp[5].y;
            }
            if (-0.7853982f < sp[5].x && sp[5].x < 0.7853982f) {
                h->f[0x330 / 4 + i] = sp[5].x;
            }
        } else {
            h->i[0x320 / 4 + i] = 0;
            h->f[0x328 / 4 + i] = h->f[0x344 / 4];
            h->f[0x330 / 4 + i] = h->f[0x348 / 4];
        }
    }
}
