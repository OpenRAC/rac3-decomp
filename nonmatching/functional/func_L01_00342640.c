/* functional: high. Not byte-exact (scheduling/regalloc). */
extern vu0_v4 D_L01_00279480[][10];
extern s16 D_L01_001E1990[];
extern s16 D_L01_001E19A0[];
extern s16 D_L01_001E19B0[];
extern f32 D_L01_001DD290;
__asm__(".extern D_L01_001DD290, 4");
extern f32 D_L01_001E19D4;
extern u8 D_001425C0[];
void func_L01_00342640(u8 *self) {
    extern void func_L01_00409658(void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
    vu0_v4 origin[2];
    vu0_v4 delta[9];
    s32 i, j, k, level, kind, next;
    vu0_v4 *p, *d;
    u32 alpha, color;
    *(vu0_q *)origin = *(vu0_q *)(*(u8 **)(self + 0x68) + 0x30);
    i = 0;
    do {
        next = i + 1;
        if (D_L01_001E1990[i]) {
            for (j = 1; j < 10; j++)
                vec_sub_ab(&delta[j-1], &D_L01_00279480[i][j], &D_L01_00279480[i][j-1]);
            *(vu0_q *)&D_L01_00279480[i][0] = *(vu0_q *)origin;
            D_L01_00279480[i][0].w = 0.04f;
            for (j = 1; j < 10; j++) {
                vec_add_ab(&D_L01_00279480[i][j], &D_L01_00279480[i][j-1], &delta[j-1]);
                D_L01_00279480[i][j].w = 0.04f;
            }
            if (D_L01_001E1990[i] > 0)
                D_L01_001E19A0[i] = (s32)(D_L01_001DD290 * ((f32)D_L01_001E1990[i] / (f32)D_L01_001E19B0[i]));
            else D_L01_001E19A0[i] = 0;
        }
        i = next;
    } while (i < 5);
    level = D_L01_002C5600[D_001425C0[0x16]].b;
    kind = 23;
    if ((u32)(level - 2) < 2) kind = 15;
    else if (level >= 4) kind = 48;
    for (k = 0; k < 5; k++) {
        if (D_L01_001E1990[k]) {
            alpha = (s32)(D_L01_001E19A0[k] * D_L01_001E19D4) << 24;
            color = 0x7F7F7F;
            if (level < 4) {
                color = 0x7F4040;
                if (level != 3) {
                    color = 0x606020;
                    if (level != 2) color = level == 1 ? 0x2040DF : 0x205080;
                }
            }
            func_L01_00409658(D_L01_00279480[k], kind, 14, 10, alpha | 0x7F7F7F, alpha | color, 1, 0.0f, 4.0f, 0.0f);
        }
    }
}
