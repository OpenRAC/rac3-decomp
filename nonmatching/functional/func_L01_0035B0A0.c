/* functional: medium. same calls/order/args; register allocation and frame layout differ; hit/cast of fade to int via C cast (retail keeps cvt.w.s via mfc1) */
typedef struct {
    f32 m[4][4];
    s32 c[4];
    f32 x50, x54, x58;
    f32 x5C, x60;
    f32 x64;
    f32 x68, x6C;
    long x70, x78, x80, x88;
} Quad_35B0A0;

extern u8 D_001425C0[];
extern u8 D_L01_002C5600[];
extern u8 D_L01_00284500[];
extern u8 D_L01_001E29C0[];
extern long func_00389598(s32);
extern void func_L01_0035B5A0(s32, f32 *, f32 *, s32, f32);
extern void func_003C5180(void *, void *, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CE20(f32 *, void *, f32);
extern void func_003D2DA0(void *, void *, s32);

void func_L01_0035B0A0(s32 a0) {
    f32 mat[16] __attribute__((aligned(16)));
    f32 *d = &mat[0], *up = &mat[4], *side = &mat[8], *pos = &mat[12];
    f32 e[4] __attribute__((aligned(16)));
    f32 ref[4] __attribute__((aligned(16)));
    s32 kind, col, idx, j, alpha;
    u8 *rec;

    kind = (D_L01_002C5600 + D_001425C0[0x7F] * 0xF0)[1];
    if ((u32)(kind - 2) < 2) col = 0x803010;
    else col = (kind < 4) ? 0x103080 : 0x803010;
    for (idx = 0; idx < 25; idx++) {
        rec = D_L01_00284500 + idx * 0x530;
        if (*(s32 *)(rec + 0x514) != 1) continue;
        if (*(s32 *)(rec + 0x518) == 1) {
            f32 t = *(f32 *)(rec + 0x510) * 64.0f;
            alpha = (s32)(t + t);
        } else {
            alpha = 0x40;
        }
        alpha <<= 24;
        func_L01_0035B5A0(a0, (f32 *)(rec + 0x20), (f32 *)rec, col + alpha, 0.35f);
        func_L01_0035B5A0(a0, (f32 *)(rec + 0x20), (f32 *)rec, alpha | 0xFFFFFF, 0.075f);
        for (j = 0; j < 2; j++) {
            Quad_35B0A0 *P0 = (Quad_35B0A0 *)(rec + 0x60 + j * 0x90);
            Quad_35B0A0 *P1 = (Quad_35B0A0 *)(rec + 0x2A0 + j * 0x90);
            f32 *p = (f32 *)(rec + 0x20 + j * 0x10);
            f32 *f = (f32 *)(rec + 0x500 + j * 4);
            s32 *flag = (s32 *)(rec + 0x4E0 + j * 4);
            f32 fv;
            P1->x78 = func_00389598(0x17);
            P1->x80 = 0xFF9000000260L;
            P1->c[0] = col + alpha; P1->c[2] = col + alpha;
            P1->c[3] = col; P1->c[1] = col;
            P1->x70 = 0;
            P1->x88 = (((long)(j % 2 + 1) << 2) | (0x8000L << 24)) | 0x40;
            fv = *f;
            if (*flag) {
                P1->x54 = 0.0f; P1->x50 = fv + 0.0f;
                P1->x5C = 0.0f; P1->x58 = *f + 1.0f;
                P1->x64 = 1.0f; P1->x60 = *f + 0.0f;
                P1->x6C = 1.0f;
            } else {
                P1->x54 = 1.0f; P1->x50 = fv + 0.0f;
                P1->x5C = 1.0f; P1->x58 = *f + 1.0f;
                P1->x64 = 0.0f; P1->x60 = *f + 0.0f;
                P1->x6C = 0.0f;
            }
            P1->x68 = *f + 1.0f;
            {
                f32 *c = (f32 *)D_L01_001E29C0;
                e[0] = c[0] - p[0]; e[1] = c[1] - p[1]; e[2] = c[2] - p[2]; e[3] = c[3];
            }
            func_003C5180(p, ref, 1);
            func_0038CF68(d, e, 1.0f);
            func_0038CE90(up, d, ref);
            func_0038CF68(up, up, 1.0f);
            func_0038CE90(side, up, d);
            pos[0] = p[0]; pos[1] = p[1]; pos[2] = p[2]; pos[3] = 1.0f;
            if (*(s32 *)(rec + 0x518) == 1) {
                func_0038CE20(P1->m[0], P0->m[0], 0.5f);
                func_0038CE20(P1->m[1], P0->m[1], 0.5f);
                func_0038CE20(P1->m[2], P0->m[2], 0.5f);
                func_0038CE20(P1->m[3], P0->m[3], 0.5f);
            } else {
                func_0038CE20(P1->m[0], P0->m[0], *(f32 *)(rec + 0x510));
                func_0038CE20(P1->m[1], P0->m[1], *(f32 *)(rec + 0x510));
                func_0038CE20(P1->m[2], P0->m[2], *(f32 *)(rec + 0x510));
                func_0038CE20(P1->m[3], P0->m[3], *(f32 *)(rec + 0x510));
            }
            func_003D2DA0(P1, mat, 0);
        }
    }
}
