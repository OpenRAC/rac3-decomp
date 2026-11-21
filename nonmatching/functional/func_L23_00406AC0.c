/* functional: high. Same reads/writes/calls as retail; only compiler scheduling differs. */
extern s32 D_L23_001E5DB4[];
extern u8 D_L23_001EE290[];
extern void func_003C2EC0(void *, s32, Mtx4 *);
extern void func_003C4098(void *out, void *a, void *b, f32 t);

void func_L23_00406AC0(void *a0) {
    Mtx4 m;
    Vec4 a;
    Vec4 b;
    Vec4 *q;
    s32 i;
    s32 j;

    if (D_L23_001E5DB4[0] == 1) {
        for (i = 0; i < 9; i++) {
            func_003C2EC0(a0, i, &m);
            q = (Vec4 *)(D_L23_001EE290 + i * 0x60);
            for (j = 0; j < 6; j++) {
                q[j] = m.m[3];
            }
        }
    } else if (D_L23_001E5DB4[0] < 0xFA) {
        for (i = 0; i < 9; i++) {
            q = (Vec4 *)(D_L23_001EE290 + i * 0x60);
            for (j = 5; j > 0; j--) {
                a = q[j - 1];
                b = q[j];
                func_003C4098(&q[j], &a, &b, 0.85f);
            }
            func_003C2EC0(a0, i, &m);
            q[0] = m.m[3];
        }
    }
}
