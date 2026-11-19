/* functional: high. Written from the PAL asm using the matched-draft shape of func_L20_003372C8 (same ribbon renderer, twin rope layout: rope 1 at v+0x30/matrix v+0x630, rope 2 at v+0x640/matrix v+0xC40, color v+0x24, idx v+0x28); folded the two identical blocks into a loop over rope[2]; offsets, gp globals (D_L20_001DEB08..EB28), loop bounds and operand order checked against retail; compiles via check.py, 625 byte diffs are scheduling/regalloc only. */
extern s32 D_L20_001DEB08;
extern s32 D_L20_001DEB0C;
extern s32 D_L20_001DEB10;
extern s32 D_L20_001DEB14;
extern s32 D_L20_001DEB18;
__asm__(".extern D_L20_001DEB08, 4");
__asm__(".extern D_L20_001DEB0C, 4");
__asm__(".extern D_L20_001DEB10, 4");
__asm__(".extern D_L20_001DEB14, 4");
__asm__(".extern D_L20_001DEB18, 4");
extern f32 D_L20_001DEB28[4][2] __attribute__((section(".sdata")));
extern vu0_v4 D_L20_001E2E00;
extern void func_0038D328(void *, void *);
extern void func_0038D5B0(void *, void *);
extern void func_0038D000(void *, void *, void *);
extern long func_00389598(s32);

typedef struct {
    vu0_v4 v[4];
    u32 color[4];
    f32 uv[4][2];
    unsigned long u70, texture, u80, mode;
} Draw_3CF108;
typedef struct {
    vu0_v4 pos[32];
    vu0_v4 vel[32];
    vu0_v4 grid[4][4];
    vu0_v4 gvel[4][4];
    vu0_v4 rotation;
} Rope_3CF108;
typedef struct {
    u8 pad0[0x24];
    s32 color;
    u8 idx[4];
    u8 pad2C[4];
    Rope_3CF108 rope[2];
} Vars_3CF108;

static __inline__ void copy_3CF108(void *d, void *s) {
    *(vu0_q *)d = *(vu0_q *)s;
}

static __inline__ s32 valid_3CF108(s32 index) {
    if (index < 31) {
        if (index >= 0) return 1;
    }
    return 0;
}

void func_L20_003CF108(void *self) {
    Draw_3CF108 q[3];
    vu0_v4 matrix[3];
    vu0_v4 position;
    vu0_v4 inverse[4];
    vu0_v4 eye;
    vu0_v4 previous;
    vu0_v4 current;
    vu0_v4 a;
    vu0_v4 b;
    Vars_3CF108 *v;
    s32 r;
    s32 i;
    s32 j;
    s32 k;
    s32 m;
    s32 k2;
    s32 n;
    long tex;
    unsigned long mode;
    u8 *indices;

    v = *(Vars_3CF108 **)((u8 *)self + 0x68);
    for (r = 0; r < 2; r++) {
        func_0038D328(matrix, &v->rope[r].rotation);
        func_0038D5B0(inverse, matrix);
        position = *(vu0_v4 *)((u8 *)self + 0x10);
        vec_sub_ba(&eye, &D_L20_001E2E00, (u8 *)self + 0x10);
        func_0038D000(&eye, &eye, inverse);
        tex = func_00389598(D_L20_001DEB08);
        mode = (unsigned long)D_L20_001DEB0C
            | ((unsigned long)D_L20_001DEB10 << 2)
            | ((unsigned long)D_L20_001DEB14 << 4)
            | ((unsigned long)D_L20_001DEB18 << 6)
            | (0x8000L << 24);
        q[0].u80 = q[1].u80 = q[2].u80 = 0xFF9000000260UL;
        q[0].texture = q[1].texture = q[2].texture = tex;
        q[0].u70 = q[1].u70 = q[2].u70 = 0;
        q[0].mode = q[1].mode = q[2].mode = mode;
        for (n = 0; n < 4; n++) {
            q[0].uv[n][1] = q[1].uv[n][1] = q[2].uv[n][1] = D_L20_001DEB28[n][1];
            q[0].color[n] = q[1].color[n] = q[2].color[n] = v->color;
        }
        indices = v->idx;
        qzero(&current);
        for (j = 0; j < 31; j++) {
            previous = current;
            if (j < 30) {
                vec_sub_ab(&b, &v->rope[r].pos[j], &v->rope[r].pos[j + 2]);
                vec_sub_ab(&a, &v->rope[r].pos[j + 1], &eye);
                func_0038CE90(&current, &a, &b);
                func_0038CF68(&current, &current, 0.1f);
            } else {
                qzero(&current);
            }
            for (k = 0; k < 4; k++) {
                s32 odd = k & 1;
                if (k < 2) {
                    copy_3CF108(&q[0].v[k], &v->rope[r].pos[j]);
                    if (odd) vec_add_ab(&q[0].v[k], &q[0].v[k], &previous);
                    else vec_sub_ab(&q[0].v[k], &q[0].v[k], &previous);
                } else {
                    copy_3CF108(&q[0].v[k], &v->rope[r].pos[j + 1]);
                    if (odd) vec_add_ab(&q[0].v[k], &q[0].v[k], &current);
                    else vec_sub_ab(&q[0].v[k], &q[0].v[k], &current);
                }
                q[0].uv[k][0] = D_L20_001DEB28[k][0] + (f32)(j % 4) * 0.25f;
            }
            func_003D2DA0(&q[0], (s32)matrix, 0);
        }
        for (i = 0; i < 4; i++) {
            qzero(&current);
            if (valid_3CF108(indices[i])) {
                for (m = 0; m < 3; m++) {
                    previous = current;
                    if (m < 2) {
                        vec_sub_ab(&b, &v->rope[r].grid[m][i], &v->rope[r].grid[m + 2][i]);
                        vec_sub_ba(&a, &v->rope[r].grid[m + 1][i], &eye);
                        func_0038CE90(&current, &a, &b);
                        func_0038CF68(&current, &current, 0.1f);
                    } else {
                        qzero(&current);
                    }
                    if (m == 0) previous = current;
                    for (k2 = 0; k2 < 4; k2++) {
                        s32 odd = k2 & 1;
                        if (k2 < 2) {
                            copy_3CF108(&q[0].v[k2], &v->rope[r].grid[m][i]);
                            if (odd) vec_add_ab(&q[0].v[k2], &q[0].v[k2], &previous);
                            else vec_sub_ab(&q[0].v[k2], &q[0].v[k2], &previous);
                        } else {
                            copy_3CF108(&q[0].v[k2], &v->rope[r].grid[m + 1][i]);
                            if (odd) vec_add_ab(&q[0].v[k2], &q[0].v[k2], &current);
                            else vec_sub_ab(&q[0].v[k2], &q[0].v[k2], &current);
                        }
                        q[0].uv[k2][0] = D_L20_001DEB28[k2][0] + (f32)(m % 4) * 0.25f;
                    }
                    func_003D2DA0(&q[0], (s32)matrix, 0);
                }
            }
        }
    }
}
