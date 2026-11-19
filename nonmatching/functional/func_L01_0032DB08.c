/* functional: high. Compiles; all stores, constants and call order from the asm. A+0x48/A+0x4C stay unset exactly as in retail (not written by retail either). Args: (moby, from pos, to pos). */
extern long func_00389598(s32);
extern void func_L01_0032CEB8(void *);
extern void func_L01_0032D7E8(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D028(void *, void *, void *);
extern void func_003D2DA0(void *, void *, s32);
extern vu0_v4 D_L01_001E29C0;
extern u8 D_001425C0[];
extern u8 D_L01_002C5600[];

void func_L01_0032DB08(void *a0, void *a1, void *a2) {
    u8 A[0x90] __attribute__((aligned(16)));    /* quad descriptor A, retail sp+0x00 */
    u8 B[0x90] __attribute__((aligned(16)));    /* quad descriptor B, retail sp+0x90 */
    f32 d[4] __attribute__((aligned(16)));      /* 0x120 */
    f32 e[4] __attribute__((aligned(16)));      /* 0x130 */
    f32 f[4] __attribute__((aligned(16)));      /* 0x140 */
    f32 z1[4] __attribute__((aligned(16)));     /* 0x160 */
    f32 z2[4] __attribute__((aligned(16)));     /* 0x170 */
    u8 *tbl;
    f32 r;
    s32 c;

    *(long *)(A + 0x78) = func_00389598(0xE);
    *(s32 *)(A + 0x40) = 0x7F7F7F7F;
    *(s32 *)(A + 0x44) = 0x7F7F7F7F;
    *(long *)(A + 0x80) = 0x0000FF9000000260L;
    *(long *)(A + 0x70) = 0;
    *(long *)(A + 0x88) = 0x0000008000000048L;
    *(long *)(B + 0x78) = func_00389598(0xE);
    *(long *)(B + 0x80) = 0x0000FF9000000260L;
    *(long *)(B + 0x88) = 0x0000008000000048L;
    *(long *)(B + 0x70) = 0;
    tbl = D_L01_002C5600 + D_001425C0[0x15] * 0xF0;
    c = tbl[1] < 2 ? 0x7F000080 : 0x7F806060;
    *(s32 *)(B + 0x40) = c;
    *(s32 *)(B + 0x44) = c;
    *(vu0_q *)z1 = 0;
    *(vu0_q *)z2 = 0;
    z1[2] = 0.015f;
    z2[2] = 0.082499996f;
    z1[3] = 1.0f;
    z2[3] = 1.0f;
    func_L01_0032CEB8(A);
    func_L01_0032CEB8(B);
    func_L01_0032D7E8(a0, a1);
    vec_sub_ba(d, a2, a1);
    ((f32 *)A)[0x14] = 0.0f; ((f32 *)A)[0x15] = 0.0f; ((f32 *)A)[0x16] = 0.0f; ((f32 *)A)[0x17] = 1.0f;
    ((f32 *)A)[0x18] = 1.0f; ((f32 *)A)[0x19] = 0.0f; ((f32 *)A)[0x1A] = 1.0f; ((f32 *)A)[0x1B] = 1.0f;
    ((f32 *)B)[0x14] = 0.0f; ((f32 *)B)[0x15] = 0.0f; ((f32 *)B)[0x16] = 0.0f; ((f32 *)B)[0x17] = 1.0f;
    ((f32 *)B)[0x18] = 1.0f; ((f32 *)B)[0x19] = 0.0f; ((f32 *)B)[0x1A] = 1.0f; ((f32 *)B)[0x1B] = 1.0f;
    func_0038CF68(d, d, 1.0f);
    vec_sub_ab(e, &D_L01_001E29C0, a1);
    func_0038CE90(f, e, d);
    func_0038CF68(f, f, 1.0f);
    func_0038CE90(e, d, f);
    *(vu0_q *)A = *(vu0_q *)z1;
    *(vu0_q *)B = *(vu0_q *)z2;
    func_0038CE20(A + 0x10, A, -1.0f);
    func_0038CE20(B + 0x10, B, -1.0f);
    func_0038D028(A, A, d);
    func_0038D028(A + 0x10, A + 0x10, d);
    func_0038D028(B, B, d);
    func_0038D028(B + 0x10, B + 0x10, d);
    tbl = D_L01_002C5600 + D_001425C0[0x15] * 0xF0;
    c = tbl[1] < 2 ? 0x80 : 0x806060;
    *(s32 *)(B + 0x48) = c;
    *(s32 *)(B + 0x4C) = c;
    r = z1[2] * 0.25f;
    z1[2] = r;
    z2[2] = r * 5.5f;
    *(vu0_q *)(A + 0x20) = *(vu0_q *)z1;
    *(vu0_q *)(B + 0x20) = *(vu0_q *)z2;
    func_0038CE20(A + 0x30, A + 0x20, -1.0f);
    func_0038CE20(B + 0x30, B + 0x20, -1.0f);
    func_0038D028(A + 0x20, A + 0x20, d);
    func_0038D028(A + 0x30, A + 0x30, d);
    func_0038D028(B + 0x20, B + 0x20, d);
    func_0038D028(B + 0x30, B + 0x30, d);
    func_003D2DA0(A, 0, 0);
    func_003D2DA0(B, 0, 0);
}
