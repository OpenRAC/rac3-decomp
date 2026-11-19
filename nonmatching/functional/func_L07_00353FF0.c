/* functional: high. 12-word near miss (scratch-array address setup, loop allocation); re-verified against the PAL asm (modulo indexing, i != count-1 length skip, GS register writes 6/0x14/8/0x42/0x47 values, DBD8 float-first prototype so t reaches f12). */
extern void func_0038C750(void);
extern long func_00389598(s32);
extern void func_003A9440(s32, long);
extern f32 func_0038CF00(void *, void *);
extern s32 func_0038DBD8(f32, u32, u32);
extern void func_003D3A24(s32, void *, void *, void *, s32);
extern f32 D_L07_00282920[10][6];
extern s32 D_L07_00282A10[10][2];
extern f32 D_L07_00282A60[10][4];
extern f32 D_L07_001E0EE0[10];
void func_L07_00353FF0(void *a, void *b, s32 count, s32 start, s32 texture)
{
    s32 i, j, next, color, k;
    f32 total, t, inverse;
    f32 *out;
    if (count < 2) return;
    func_0038C750();
    total = 0.0f;
    func_003A9440(6, func_00389598(texture));
    func_003A9440(0x14, 0xFF9000000260L);
    func_003A9440(8, 0);
    func_003A9440(0x42, 0x4000000044L);
    for (i = 0; i < count; i++) {
        j = (i + start) % count;
        next = (j + 1) % count;
        if (i != count - 1) {
            f32 d = func_0038CF00((u8 *)a + j * 16, (u8 *)a + next * 16);
            total += d;
            D_L07_001E0EE0[i] = d;
        }
        out = D_L07_00282920[i];
        out[0] = *(f32 *)((u8 *)a + j * 16);
        out[1] = *(f32 *)((u8 *)a + j * 16 + 4);
        out[2] = *(f32 *)((u8 *)a + j * 16 + 8);
        out[3] = *(f32 *)((u8 *)b + j * 16);
        out[4] = *(f32 *)((u8 *)b + j * 16 + 4);
        out[5] = *(f32 *)((u8 *)b + j * 16 + 8);
    }
    inverse = 1.0f / total;
    t = 0.0f;
    for (k = 0; k < count; k++) {
        color = func_0038DBD8(t, 0x804020, 0x30202080);
        D_L07_00282A10[k][0] = D_L07_00282A10[k][1] = color;
        D_L07_00282A60[k][0] = t;
        D_L07_00282A60[k][2] = t;
        D_L07_00282A60[k][1] = 0.0f;
        t += D_L07_001E0EE0[k] * inverse;
        D_L07_00282A60[k][3] = 1.0f;
    }
    func_003D3A24(count * 2, D_L07_00282920, D_L07_00282A10, D_L07_00282A60, 1);
    func_003A9440(0x47, 0x5360B);
}
