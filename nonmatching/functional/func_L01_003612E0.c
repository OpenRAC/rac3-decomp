/* functional: high. The three 64-bit GS values go through a casted function pointer so their upper words are kept; the retail's unused func_0038D098(angle) call is kept. */
extern f32 D_L01_0028C6B0[][3];
extern s32 D_L01_0028C8A8[];
extern f32 D_L01_0028C950[][2];
void func_L01_003612E0(s128 *matrix, f32 degrees, f32 r1, f32 r2, s32 texture, f32 unused, s32 colour, s32 blend)
{
    extern void func_003A9440(s32, s32);
    extern s32 func_00389598(s32);
    extern void func_0038C750(void);
    extern f32 func_0038DB48(f32);
    extern f32 func_0038D098(f32);
    extern void func_00382760(void *, f32, f32, f32);
    extern void func_0038D028(void *, void *, void *);
    extern void func_003D3A24(s32, void *, void *, void *, s32);
    S_38C110v v, out;
    f32 step, angle, t, rad, denom;
    s32 i;
    /* the state-register setter takes a 64-bit value; the file declares it with 32 */
    void (*set_reg)(s32, long) = (void (*)(s32, long))func_003A9440;

    set_reg(8, 0);
    set_reg(20, 0xFF9000000260L);
    set_reg(71, 0x513F1L);
    set_reg(6, func_00389598(texture));
    if (blend) set_reg(66, 0x8000000048L);
    else set_reg(66, 0x8000000041L);
    rad = 0.017453292f;
    func_0038C750();
    denom = 20.0f;
    step = degrees * rad / denom;
    for (i = 0; i < 42; i += 2) {
        t = i / 2;
        angle = func_0038DB48(t * step);
        func_0038D098(angle);
        t /= denom;
        D_L01_0028C8A8[i] = colour; D_L01_0028C8A8[i + 1] = colour;
        D_L01_0028C950[i][0] = t;
        D_L01_0028C950[i][1] = 0;
        D_L01_0028C950[i + 1][0] = t;
        D_L01_0028C950[i + 1][1] = 1.0f;
        func_00382760(&v, 1.0f, angle, r1 * rad);
        v.w = 1.0f;
        func_0038D028(&out, &v, matrix);
        D_L01_0028C6B0[i][0] = out.x; D_L01_0028C6B0[i][1] = out.y; D_L01_0028C6B0[i][2] = out.z;
        func_00382760(&v, 1.0f, angle, r2 * rad);
        v.w = 1.0f;
        func_0038D028(&out, &v, matrix);
        D_L01_0028C6B0[i + 1][0] = out.x; D_L01_0028C6B0[i + 1][1] = out.y; D_L01_0028C6B0[i + 1][2] = out.z;
    }
    func_003D3A24(42, D_L01_0028C6B0, D_L01_0028C8A8, D_L01_0028C950, 1);
}
