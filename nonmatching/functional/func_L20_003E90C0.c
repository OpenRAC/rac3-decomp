/* functional: high. Same routine as func_L20_003E6F88 for the second bolt (gp slots and uv table at +0xA8); generated from the same template and checked against the asm diff (only gp offsets and labels differ). */
extern void func_003D2DA0(void *, s32, s32);
typedef struct {
    u8 pad0[0x8];
    s32 i8;
    u8 padC[0x22 - 0xC];
    s16 count;
    s32 color;
    u8 idx[4];
    u8 pad2C[4];
    struct {
        vu0_v4 v[64];
        vu0_v4 row[8][4];
        f32 ang[3];
        f32 pad60C;
    } set[2];
} Bolt_003E90C0;

typedef struct {
    vu0_v4 v[4];
    u32 col[4];
    f32 uv[4][2];
    unsigned long u70;
    unsigned long u78;
    unsigned long u80;
    unsigned long gif;
} Quad_003E90C0;

extern s32 D_L20_001DF198;
__asm__(".extern D_L20_001DF198, 4");
extern s32 D_L20_001DF19C;
__asm__(".extern D_L20_001DF19C, 4");
extern s32 D_L20_001DF1A0;
__asm__(".extern D_L20_001DF1A0, 4");
extern s32 D_L20_001DF1A4;
__asm__(".extern D_L20_001DF1A4, 4");
extern s32 D_L20_001DF1A8;
__asm__(".extern D_L20_001DF1A8, 4");
extern f32 D_L20_001DF1B8[];
__asm__(".extern D_L20_001DF1B8, 4");
extern u8 D_L20_001E2E00[];
extern void func_0038D328(void *, void *);
extern void func_0038D5B0(void *, void *);
extern void func_0038D000(void *, void *, void *);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern unsigned long func_00389598(s32);

/* Draws the bolt as two ribbons (one per set): a strip of quads along the 32 path points, then a quad
 * strip along each of the 4 branches. Each quad's corners are the two path points moved +-ribbon
 * normal (the cross product of the segment and the view vector, set to length 0.1). */
void func_L20_003E90C0(u8 *obj) {
    Bolt_003E90C0 *s = *(Bolt_003E90C0 **)(obj + 0x68);
    Quad_003E90C0 q;
    vu0_v4 M[4];
    vu0_v4 Minv[4];
    vu0_v4 d;
    vu0_v4 pv;
    vu0_v4 zv;
    vu0_v4 t1;
    vu0_v4 t2;
    vu0_v4 *a;
    vu0_v4 *b;
    vu0_v4 *src;
    s32 n;
    s32 i;
    s32 j;
    s32 m;
    s32 r;

    for (n = 0; n < 2; n++) {
        func_0038D328(M, s->set[n].ang);
        func_0038D5B0(Minv, M);
        M[3] = *(vu0_v4 *)(obj + 0x10);
        vec_sub_ab(&d, D_L20_001E2E00, obj + 0x10);
        func_0038D000(&d, &d, Minv);
        q.u78 = func_00389598(D_L20_001DF198);
        q.gif = (long)D_L20_001DF19C | ((long)D_L20_001DF1A0 << 2) | ((long)D_L20_001DF1A4 << 4) | ((long)D_L20_001DF1A8 << 6)
                | (0x8000L << 24);
        q.u80 = (0xFF90L << 32) | 0x260;
        q.u70 = 0;
        for (m = 0; m < 4; m++) {
            q.uv[m][1] = D_L20_001DF1B8[m * 2 + 1];
            q.col[m] = s->color;
        }
        /* along the path */
        qzero(&zv);
        for (i = 0; i < 31; i++) {
            pv = zv;
            if (i < 30) {
                vec_sub_ab(&t2, &s->set[n].v[i], &s->set[n].v[i + 2]);
                vec_sub_ab(&t1, &s->set[n].v[i + 1], &d);
                func_0038CE90(&zv, &t1, &t2);
                func_0038CF68(&zv, &zv, 0.1f);
            } else {
                qzero(&zv);
            }
            a = &s->set[n].v[i];
            b = &s->set[n].v[i + 1];
            for (m = 0; m < 4; m++) {
                if (m < 2) {
                    q.v[m] = *a;
                    src = &pv;
                } else {
                    q.v[m] = *b;
                    src = &zv;
                }
                if (m & 1) {
                    vec_add_ab(&q.v[m], &q.v[m], src);
                } else {
                    vec_sub_ab(&q.v[m], &q.v[m], src);
                }
                q.uv[m][0] = D_L20_001DF1B8[m * 2] + (f32)(i % 4) * 0.25f;
            }
            func_003D2DA0(&q, (s32)M, 0);
        }
        /* along the four branches */
        for (j = 0; j < 4; j++) {
            qzero(&zv);
            if (s->idx[j] < 31) {
                for (r = 0; r < 3; r++) {
                    pv = zv;
                    if (r < 2) {
                        /* retail's second set subtracts set 0's row here (offset 0x4B0 in both loops) */
                        vec_sub_ab(&t2, &s->set[n].row[r][j], &s->set[0].row[r + 2][j]);
                        vec_sub_ab(&t1, &s->set[n].row[r + 1][j], &d);
                        func_0038CE90(&zv, &t1, &t2);
                        func_0038CF68(&zv, &zv, 0.1f);
                    } else {
                        qzero(&zv);
                    }
                    if (r == 0) {
                        pv = zv;
                    }
                    a = &s->set[n].row[r][j];
                    b = &s->set[n].row[r + 1][j];
                    for (m = 0; m < 4; m++) {
                        if (m < 2) {
                            q.v[m] = *a;
                            src = &pv;
                        } else {
                            q.v[m] = *b;
                            src = &zv;
                        }
                        if (m & 1) {
                            vec_add_ab(&q.v[m], &q.v[m], src);
                        } else {
                            vec_sub_ab(&q.v[m], &q.v[m], src);
                        }
                        q.uv[m][0] = D_L20_001DF1B8[m * 2] + (f32)(r % 4) * 0.25f;
                    }
                    func_003D2DA0(&q, (s32)M, 0);
                }
            }
        }
    }
}
