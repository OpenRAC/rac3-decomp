/* functional: medium. Handle meanings guessed (callees func_003E8EF0/8FE8/9138 create entries, 8A08/8630 link, 8348 commits). Struct copies written as plain V4 assignment; float constants decoded from lui/ori. Medium: prototypes of func_L01_005195E0 (1 arg) inferred. */
/* localdecomp:start func_L03_003AECB0 */
typedef struct { f32 f[4]; } __attribute__((aligned(16))) V_3AECB0;
extern void func_L01_005195E0(s32);
extern s32 func_003E8EF0(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003E8A08(s32, s32, s32);
extern s32 func_003E8FE8(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E9138(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E8630(s32, s32);
extern s32 func_003E8348(s32, s32);
extern void func_L01_00516AA0(s32, s32, s32);
extern void *func_0011A264(void *, int, int);
__asm__(".extern D_001DE7F0_sda, 4");
__asm__(".extern D_001DE7F4_sda, 4");
__asm__(".extern D_001DE7F8_sda, 4");
__asm__(".extern D_001DE7FC_sda, 4");
extern f32 D_001DE7F0_sda;
extern f32 D_001DE7F4_sda;
extern f32 D_001DE7F8_sda;
extern f32 D_001DE7FC_sda;

void func_L03_003AECB0(void) {
    V_3AECB0 P, Q, R, a, b, c;
    s32 i;
    func_L01_005195E0(0x150001);
    func_003E8EF0(0x150002, 0x39, 0x331465B7, D_001DE7F0_sda, D_001DE7F4_sda, 1.0f, 1.0f, 0.0f);
    func_003E8EF0(0x150004, 0x38, 0x332299DE, D_001DE7F0_sda, D_001DE7F4_sda, 1.0f, 1.0f, 0.0f);
    func_003E8A08(0x150001, 0x150002, 0x150004);
    func_0011A264(&a, 0, 16);
    a.f[0] = D_001DE7F0_sda - 0.02f;
    a.f[1] = D_001DE7F4_sda - 0.001f;
    a.f[2] = 0.23f;
    a.f[3] = 0.1f;
    P = a;
    func_003E8FE8(0x150006, 0, 0x8066CCFF, P.f[0], P.f[1] - P.f[3] * 0.25f, 1.0f, 1.0f);
    func_L01_00516AA0(0x150006, 0x40, 1);
    func_003E8FE8(0x150007, 0, 0x8066CCFF, P.f[0], P.f[1] + P.f[3] * 0.25f, 1.0f, 1.0f);
    func_L01_00516AA0(0x150007, 0x40, 1);
    func_003E8A08(0x150001, 0x150006, 0x150007);
    func_0011A264(&b, 0, 16);
    b.f[0] = D_001DE7F0_sda + 0.14f;
    b.f[1] = D_001DE7F4_sda;
    b.f[2] = 0.06f;
    b.f[3] = 0.075f;
    Q = b;
    for (i = 0; i < 8; i++) {
        s32 h = i + 0x150008;
        func_003E9138(h, 0x8066CCFF, 0, Q.f[0] + (f32)i * Q.f[2], Q.f[1],
                      Q.f[2] - D_001DE7F8_sda * 0.001953125f,
                      Q.f[3] - D_001DE7FC_sda / 416.0f);
        func_L01_00516AA0(h, 0x40, 1);
        func_003E8630(0x150001, h);
    }
    func_0011A264(&c, 0, 16);
    c.f[0] = D_001DE7F0_sda - 0.016f;
    c.f[1] = D_001DE7F4_sda;
    c.f[2] = 0.2f;
    c.f[3] = 0.002f;
    R = c;
    func_003E9138(0x150005, 0x8066CCFF, 0, R.f[0], R.f[1], R.f[2], R.f[3]);
    func_003E8630(0x150001, 0x150005);
    func_003E8348(1, 0x150001);
}
/* localdecomp:end func_L03_003AECB0 */
