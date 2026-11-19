/* functional: high. Compiles (differences are stack layout/scheduling only); operations and order read against the asm. Uses vu0_q for 16-byte copies (this file has no s128 before this function). */
extern u8 *func_003C24B0(s32, s32);
extern void func_0038D308(void *, void *);
extern void func_L01_004C7D98(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D810(void *, void *);
extern void func_0038D5F0(void *, void *, void *);
extern s32 func_L01_004C80F8(void *, s32);
extern s32 func_L01_004C85C8(u8 *, s32, f32, f32, f32);
extern void func_003C2880(void *);
extern void func_003C7C38(void *);
extern s32 D_001A71A0[];
extern s32 D_001DCE48_sda;
__asm__(".extern D_001DCE48_sda, 4");
extern u8 D_001425D5;
extern u8 D_L01_002C5600[];

u8 *func_L01_0032C7A0(void *pos, void *dir0) {
    f32 axis[4] __attribute__((aligned(16)));
    f32 fwd[4] __attribute__((aligned(16)));
    f32 q[4] __attribute__((aligned(16)));
    f32 rot[4] __attribute__((aligned(16)));
    f32 mat[16] __attribute__((aligned(16)));
    u8 *obj;
    u8 *vars;
    f32 half;
    f32 f;
    s32 slot;
    s32 r;

    obj = func_003C24B0(0x1366, 0x80);
    if (obj == 0) {
        return obj;
    }
    f = *(f32 *)(obj + 0x2C) * 0.75f;
    obj[0x30] = 0xFF;
    *(u16 *)(obj + 0x32) = 0xFF;
    *(u16 *)(obj + 0x34) = *(u16 *)(obj + 0x34) | 0x100;
    *(f32 *)(obj + 0x2C) = f;
    obj[0x20] = 0;
    vars = *(u8 **)(obj + 0x68);
    *(vu0_q *)(obj + 0x10) = *(vu0_q *)pos;
    *(vu0_q *)vars = *(vu0_q *)dir0;
    func_0038D308(obj + 0xC0, (u8 *)D_001A71A0[0] + 0xF0);
    func_L01_004C7D98(obj + 0x10, axis);
    func_0038CF68(fwd, obj + 0xE0, 1.0f);
    func_0038CE90(rot, fwd, axis);
    half = func_0038CE68(fwd, axis) * 0.5f;
    func_0038CE20(q, rot, func_0038D0B0(half));
    q[3] = func_0038D098(half);
    func_0038D810(q, mat);
    func_0038D5F0(obj + 0xC0, mat, obj + 0xC0);
    r = D_001DCE48_sda;
    *(s32 *)(vars + 0x68) = 0;
    slot = (r * 5 + 2) / 6;
    *(vu0_q *)(vars + 0x10) = 0;
    *(s16 *)(vars + 0x66) = 0;
    *(f32 *)(vars + 0x10) = 1.0f;
    *(s32 *)(vars + 0x50) = 0;
    *(s32 *)(vars + 0x44) = 0;
    *(u16 *)(vars + 0x64) = *(u16 *)(D_L01_002C5600 + D_001425D5 * 0xF0 + 0x54);
    *(s16 *)(vars + 0x4C) = 1;
    *(vu0_q *)(vars + 0x20) = *(vu0_q *)(vars + 0x10);
    *(f32 *)(vars + 0x58) = 0.031415928f;
    *(vu0_q *)(vars + 0x30) = *(vu0_q *)(vars + 0x10);
    *(s32 *)(vars + 0x40) = slot;
    r = func_L01_004C80F8(obj, 0);
    *(s32 *)(vars + 0x48) = r;
    if (r == -1) {
        func_003C2880(obj);
        return 0;
    }
    r = func_L01_004C85C8(obj, 0, 1.0f, 1.0f, 1.0f);
    vars[0x4E] = -1;
    *(s32 *)(vars + 0x70) = 0;
    vars[0x4F] = r;
    func_003C7C38(obj);
    return obj;
}
