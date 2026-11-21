/* functional: high. PAL port of the NTSC-U draft (func_L04_00324BA8's C), re-read against the PAL assembly. PAL differences from the draft: timers 50 (NTSC 60), p->h4 = 8 (10), p->f10 = 0.125f (0.1f), player w28 = 33 (40); the player table is D_L04_001E2840 (NTSC 001E28C0); callees renumbered. VU0 vsub.xyz is scalar and the qzero is a plain 128-bit zero (no VU0 flag on the file). vsub.xyz keeps the w of its first operand, so dir[3]/aim[3] are set from it. Not byte-matched. */
typedef int u128_00325460 __attribute__((mode(TI)));
typedef struct { s16 h0, h2, h4, pad6; f32 f8, fC, f10, f14; s32 w18, w1C, w20, w24, w28, w2C, w30, w34, w38; void *p3C; } P_325460;
typedef struct { u8 pad0[0x10]; f32 pos[4]; u8 b20; u8 pad21[0x30 - 0x21]; u8 b30, pad31; s16 h32; u8 pad34[0x68 - 0x34]; P_325460 *vars; u8 pad6C[0xC0 - 0x6C]; f32 vC0[4], vD0[4], vE0[4]; } M_325460;
typedef struct { f32 pos[4]; u8 pad10[0x10]; f32 f20; u8 pad24[4]; s32 w28, w2C; u8 pad30[0x380 - 0x30]; f32 v380[4]; u8 pad390[0x460 - 0x390]; } Player_325460;
extern M_325460 *func_003C24B0(s32, s32);
extern Player_325460 D_L04_001E2840[];
extern s32 D_001D52F0[];
extern void func_0038CF68(void *, void *, f32);
extern void func_003C5180(void *, void *, s32);
extern void func_0038CE90(void *, void *, void *);
extern void func_L01_0044C870(void *, void *, void *, void *);
extern s32 func_0038DC20(void *, f32);
extern f32 func_L01_0040E548(void *, void *);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038D0C8(f32);
extern void func_L04_00325C08(void *, void *, void *, f32);
M_325460 *func_L04_00325460(f32 *pos, s32 flag, s32 w20, s32 w24, s32 w28, s32 w2C, s32 w30, s32 w18, s32 w34, s32 w1C, s32 w38, void *parent, f32 scale, f32 extra) {
    f32 dir[4] __attribute__((aligned(16)));
    f32 basis[4] __attribute__((aligned(16)));
    f32 shift[4] __attribute__((aligned(16)));
    f32 box[4] __attribute__((aligned(16)));
    f32 aim[4] __attribute__((aligned(16)));
    M_325460 *m = func_003C24B0(0x13A0, 0x80);
    if (m) {
        P_325460 *p;
        f32 a;
        m->b30 = 0xFF;
        m->h32 = 0x1FF;
        m->b20 = 0;
        p = m->vars;
        *(u128_00325460 *)m->pos = *(u128_00325460 *)pos;
        m->pos[3] = 1.0f;
        dir[0] = D_L04_001E2840[D_001D52F0[0]].pos[0] - m->pos[0];
        dir[1] = D_L04_001E2840[D_001D52F0[0]].pos[1] - m->pos[1];
        dir[2] = D_L04_001E2840[D_001D52F0[0]].pos[2] - m->pos[2];
        dir[3] = D_L04_001E2840[D_001D52F0[0]].pos[3];
        func_0038CF68(dir, dir, 1.0f);
        func_003C5180(m->pos, basis, 1);
        *(u128_00325460 *)m->vC0 = *(u128_00325460 *)dir;
        func_0038CE90(m->vD0, m->vC0, basis);
        func_0038CF68(m->vD0, m->vD0, 1.0f);
        func_0038CE90(m->vE0, m->vD0, m->vC0);
        m->vC0[3] = 0.0f;
        m->vE0[3] = 0.0f;
        m->vD0[3] = 0.0f;
        p->w20 = w20;
        p->w24 = w24;
        p->w28 = w28;
        p->w2C = w2C;
        p->w30 = w30;
        p->h2 = 50;
        p->f8 = scale + scale;
        p->fC = scale * 4.0f;
        p->w34 = w34;
        p->w1C = w1C;
        p->w38 = w38;
        p->f14 = scale;
        p->w18 = w18;
        p->h0 = 50;
        p->p3C = parent;
        *(u128_00325460 *)shift = 0;
        if (parent) {
            func_L01_0044C870(m, parent, m->pos, shift);
        }
        *(u128_00325460 *)box = *(u128_00325460 *)m->pos;
        box[3] = scale * 3.0f;
        if (func_0038DC20(box, 511.0f) == 1) {
            p->h4 = 8;
            p->f10 = 0.125f;
            if (flag && func_L01_0040E548(pos, &D_L04_001E2840[D_001D52F0[0]]) < 2304.0f) {
                D_L04_001E2840[0].w28 = 33;
                D_L04_001E2840[0].f20 = 0.075f;
                D_L04_001E2840[0].w2C = 0;
            }
            if (p->w18) {
                aim[0] = m->pos[0] - D_L04_001E2840[D_001D52F0[0]].pos[0];
                aim[1] = m->pos[1] - D_L04_001E2840[D_001D52F0[0]].pos[1];
                aim[2] = m->pos[2] - D_L04_001E2840[D_001D52F0[0]].pos[2];
                aim[3] = m->pos[3];
                func_0038CF68(aim, aim, 1.0f);
                a = func_0038D0C8(func_0038CE68(aim, D_L04_001E2840[D_001D52F0[0]].v380));
                if (1.5707964f - a < 0.45378560f) {
                    p->w18 = 1;
                } else {
                    p->w18 = 0;
                }
            }
        } else {
            p->h4 = 0;
            p->w18 = 0;
        }
        func_L04_00325C08(m, basis, shift, extra);
    }
    return m;
}
