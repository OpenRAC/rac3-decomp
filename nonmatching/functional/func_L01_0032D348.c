/* functional: high. Compiles; all stores and call order taken from the asm (two 0x90-byte quad descriptors A at sp+0 and B at sp+0x90, B offsets rebased). Retail also does dead vec-copies into sp+0x150, omitted. Param is the file's M_32CAB0 * (declared earlier in the file). */
extern void func_003C2F58(void *, s32, void *);
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_L01_0032CF90(void *, void *);
extern long func_00389598(s32);
extern void func_L01_0032CEB8(void *);
extern s32 func_0013D3E0(void);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D028(void *, void *, void *);
extern void func_003D2DA0(void *, void *, s32);
extern vu0_v4 D_L01_001E29C0;
extern u8 D_001425C0[];
extern u8 D_L01_002C5600[];

void func_L01_0032D348(M_32CAB0 *m) {
    u8 *obj = (u8 *)m;
    u8 A[0x90] __attribute__((aligned(16)));    /* quad descriptor A, retail sp+0x00 */
    u8 B[0x90] __attribute__((aligned(16)));    /* quad descriptor B, retail sp+0x90 */
    f32 d[4] __attribute__((aligned(16)));      /* 0x120 */
    f32 e[4] __attribute__((aligned(16)));      /* 0x130 */
    f32 f[4] __attribute__((aligned(16)));      /* 0x140 */
    f32 p0[4] __attribute__((aligned(16)));     /* 0x160 */
    f32 p1[4] __attribute__((aligned(16)));     /* 0x170 */
    f32 pos[4] __attribute__((aligned(16)));    /* 0x180 */
    f32 z1[4] __attribute__((aligned(16)));     /* 0x190 */
    f32 z2[4] __attribute__((aligned(16)));     /* 0x1A0 */
    u8 *vars = m->w68;
    u8 *tbl;
    f32 r;
    s32 c2, c3;

    func_003C2F58(obj, 1, pos);
    *(vu0_q *)p0 = *(vu0_q *)pos;
    r = func_003824E0(2.0f, 4.0f);
    func_0038CF68(p1, vars + 0x30, r);
    func_0038D000(p1, p1, obj + 0xC0);
    vec_add_ab(p1, p1, pos);
    func_L01_0032CF90(obj, p0);

    *(long *)(A + 0x78) = func_00389598(0x17);
    *(long *)(A + 0x70) = 0;
    *(long *)(A + 0x80) = 0x0000FF9000000260L;
    *(long *)(A + 0x88) = 0x0000008000000048L;
    tbl = D_L01_002C5600 + D_001425C0[0x15] * 0xF0;
    if (tbl[1] < 2) {
        c2 = 0x103080;
        c3 = 0x7F103080;
    } else {
        c2 = 0x803010;
        c3 = 0x7F803010;
    }
    *(s32 *)(A + 0x48) = c2;
    *(s32 *)(A + 0x40) = c3;
    *(s32 *)(A + 0x4C) = c2;
    *(s32 *)(A + 0x44) = c3;

    *(long *)(B + 0x78) = func_00389598(0x17);
    *(long *)(B + 0x80) = 0x0000FF9000000260L;
    *(long *)(B + 0x88) = 0x0000008000000048L;
    *(long *)(B + 0x70) = 0;
    tbl = D_L01_002C5600 + D_001425C0[0x15] * 0xF0;
    if (tbl[1] < 2) {
        c2 = 0x103080;
        c3 = 0x3F103080;
    } else {
        c2 = 0x803010;
        c3 = 0x3F803010;
    }
    *(s32 *)(B + 0x48) = c2;
    *(s32 *)(B + 0x40) = c3;
    *(s32 *)(B + 0x4C) = c2;
    *(s32 *)(B + 0x44) = c3;

    *(vu0_q *)z1 = 0;
    *(vu0_q *)z2 = 0;
    z1[3] = 1.0f;
    z2[3] = 1.0f;
    r = func_003824E0(0.1f, 0.3f);
    z1[2] = r;
    z2[2] = r + r;
    func_L01_0032CEB8(A);
    func_L01_0032CEB8(B);
    if ((func_0013D3E0() & 1) == 0) {
        ((f32 *)B)[0x1B] = 1.0f;
        ((f32 *)A)[0x14] = 0.0f; ((f32 *)A)[0x15] = 0.0f; ((f32 *)A)[0x16] = 0.0f; ((f32 *)A)[0x17] = 1.0f;
        ((f32 *)A)[0x18] = 1.0f; ((f32 *)A)[0x19] = 0.0f; ((f32 *)A)[0x1A] = 1.0f; ((f32 *)A)[0x1B] = 1.0f;
        ((f32 *)B)[0x14] = 0.0f; ((f32 *)B)[0x15] = 0.0f; ((f32 *)B)[0x16] = 0.0f; ((f32 *)B)[0x17] = 1.0f;
        ((f32 *)B)[0x18] = 1.0f; ((f32 *)B)[0x19] = 0.0f; ((f32 *)B)[0x1A] = 1.0f;
    } else {
        ((f32 *)B)[0x1A] = 1.0f;
        ((f32 *)A)[0x14] = 0.0f; ((f32 *)A)[0x15] = 1.0f; ((f32 *)A)[0x16] = 0.0f; ((f32 *)A)[0x17] = 0.0f;
        ((f32 *)A)[0x18] = 1.0f; ((f32 *)A)[0x19] = 1.0f; ((f32 *)A)[0x1A] = 1.0f; ((f32 *)A)[0x1B] = 0.0f;
        ((f32 *)B)[0x14] = 0.0f; ((f32 *)B)[0x15] = 1.0f; ((f32 *)B)[0x16] = 0.0f; ((f32 *)B)[0x17] = 0.0f;
        ((f32 *)B)[0x18] = 1.0f; ((f32 *)B)[0x19] = 1.0f; ((f32 *)B)[0x1B] = 0.0f;
    }
    vec_sub_ab(d, p1, p0);
    func_0038CF68(d, d, 1.0f);
    vec_sub_ab(e, &D_L01_001E29C0, p0);
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
    r = z1[2] * 0.15f;
    z1[2] = r;
    z2[2] = r + r;
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
