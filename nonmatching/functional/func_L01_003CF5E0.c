/* functional: high. functional: high. Every call, argument constant and offset follows the asm; only instruction scheduling differs */
typedef int u128_3CF5E0 __attribute__((mode(TI)));
extern void func_003C2EC0(void *, s32, void *);
extern void func_L01_0040A8C0(void *, void *, s32, s32, u32, u32, u32, u32, f32, f32, f32);
extern void func_L01_00408C98(void *, s32, void *, void *, s32, s32, s32, s32, f32, s32);
extern s32 D_001DF25C_sda;
extern s32 D_001DF260_sda;
__asm__(".extern D_001DF25C_sda, 4");
__asm__(".extern D_001DF260_sda, 4");

void func_L01_003CF5E0(u8 *self) {
    f32 A[4];
    f32 B[4];
    f32 C[4];
    f32 D[4];
    f32 t50[4];
    f32 t60[4];
    f32 mat[16];
    f32 tmp[4];
    u8 *vars;
    f32 t;

    vars = *(u8 **)(self + 0x68);
    t = *(f32 *)(vars + 0x600) - 0.1f;
    *(f32 *)(vars + 0x600) = t;
    if (t <= -8.0f) {
        *(f32 *)(vars + 0x600) = t + 8.0f;
    }
    func_003C2F58(self, 0, A);
    func_003C2F58(self, 2, B);
    func_003C2F58(self, 1, C);
    func_003C2F58(self, 3, D);
    t50[0] = A[0] - C[0]; t50[1] = A[1] - C[1]; t50[2] = A[2] - C[2]; t50[3] = A[3];
    func_0038CF68(t50, t50, *(f32 *)(vars + 0x608));
    C[0] = t50[0] + A[0]; C[1] = t50[1] + A[1]; C[2] = t50[2] + A[2]; C[3] = t50[3];
    t60[0] = B[0] - D[0]; t60[1] = B[1] - D[1]; t60[2] = B[2] - D[2]; t60[3] = B[3];
    func_0038CF68(t60, t60, *(f32 *)(vars + 0x604));
    D[0] = t60[0] + B[0]; D[1] = t60[1] + B[1]; D[2] = t60[2] + B[2]; D[3] = t60[3];
    func_003C2EC0(self, 1, mat);
    *(u128_3CF5E0 *)tmp = *(u128_3CF5E0 *)mat;
    func_0038CF68(tmp, tmp, -2.75f);
    *(u128_3CF5E0 *)(vars + 0x410) = *(u128_3CF5E0 *)tmp;
    *(f32 *)(vars + 0x41C) = 1.0f;
    *(u128_3CF5E0 *)tmp = *(u128_3CF5E0 *)mat;
    func_0038CF68(tmp, tmp, 0.75f);
    *(u128_3CF5E0 *)(vars + 0x400) = *(u128_3CF5E0 *)tmp;
    *(f32 *)(vars + 0x40C) = 1.0f;
    func_L01_0040A8C0(A, C, D_001DF25C_sda, 1, 0x6FFFFFFF, 0x6FFFFFFF, 0x6FFFFFFF, 0x6FFFFFFF, 0.035f, 0.45f, *(f32 *)(vars + 0x600));
    func_L01_0040A8C0(B, D, D_001DF25C_sda, 1, 0x6FFFFFFF, 0x6FFFFFFF, 0x6FFFFFFF, 0x6FFFFFFF, 0.035f, 0.45f, *(f32 *)(vars + 0x600));
    func_L01_0040A8C0(A, C, D_001DF25C_sda, 1, 0x7F96006B, 0x7F96006B, 0x7F96006B, 0x7F96006B, 0.08f, 0.75f, *(f32 *)(vars + 0x600));
    func_L01_0040A8C0(B, D, D_001DF25C_sda, 1, 0x7F96006B, 0x7F96006B, 0x7F96006B, 0x7F96006B, 0.08f, 0.75f, *(f32 *)(vars + 0x600));
    func_L01_00408C98(vars + 0x400, D_001DF260_sda, vars, vars + 0x200, *(s32 *)(vars + 0x60C), *(s32 *)(vars + 0x61C), *(s32 *)(vars + 0x610), *(s32 *)(vars + 0x614), *(f32 *)(vars + 0x618), 5);
}
