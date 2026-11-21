/* functional: high. Compiles (140 diff insns, regalloc/layout); all 11 jal targets match retail; sibling of func_L01_0032BF70 with vars+0x64 as the target slot, a 3-word skip template D_L01_001DCED8, kind 0 in both branches, and no class-0x16 handling. Matrix rows must stay contiguous (m[16]). */
typedef struct {
    s32 w0, w4, w8;
} Skip_32F1B8;
extern Skip_32F1B8 D_L01_001DCED8;
extern u8 D_L01_001DAFF0;
extern f32 D_001DCEC4_sda;
__asm__(".extern D_001DCEC4_sda, 4");
extern void func_L01_004C7D98(void *, void *);
extern void func_003C2F58(void *, s32, void *);
extern u8 *func_L01_004501E8(void *from, void *aim, f32 far_yaw, f32 far_pitch, f32 range, f32 near_pitch,
                             f32 near_yaw, void *at, s32 a3, s32 t0, s32 t1, s32 kind,
                             void *skip, s32 s0, s32 s8, s32 s10);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_003C48A8(void *, void *);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_003824E0(f32, f32);
extern void func_00382760(void *, f32, f32, f32);

void func_L01_0032F1B8(u8 *obj) {
    f32 dirv[4] __attribute__((aligned(16)));
    f32 from[4] __attribute__((aligned(16)));
    f32 at[4] __attribute__((aligned(16)));
    f32 axis[4] __attribute__((aligned(16)));
    f32 out[4] __attribute__((aligned(16)));
    f32 m[16] __attribute__((aligned(16))); /* 4x4 matrix, rows contiguous (retail sp+0x60..0x9F) */
    Skip_32F1B8 skip;
    u8 *vars = *(u8 **)(obj + 0x68);
    f32 f;
    f32 r;

    func_L01_004C7D98(obj + 0x10, dirv);
    func_003C2F58(obj, 0, from);
    if (*(s32 *)(vars + 0x64) == 0) {
        skip = D_L01_001DCED8;
        if (D_L01_001DAFF0 != 0) {
            *(u8 **)(vars + 0x64) = func_L01_004501E8(from, obj + 0xC0, 6.2831855f, 6.2831855f, 35.0f, 0.0f, 0.0f,
                                                      at, 0, 0, 0, 0, &skip, 1, -1, 0);
        } else {
            *(u8 **)(vars + 0x64) = func_L01_004501E8(from, obj + 0xC0, 6.2831855f, 6.2831855f, D_001DCEC4_sda, 0.0f, 0.0f,
                                                      at, 0, 0, 0, 0, &skip, 1, -1, 0);
        }
        if (*(s32 *)(vars + 0x64) != 0) {
            obj[0x20] = 4;
            *(s32 *)(vars + 0x5C) = 0;
        }
    }
    if (*(s16 *)(vars + 0x4C) == 0 && *(s32 *)(vars + 0x64) == 0) {
        return;
    }
    if (*(s32 *)(vars + 0x64) == 0) {
        *(vu0_q *)axis = 0;
        axis[2] = 1.0f;
        *(vu0_q *)m = *(vu0_q *)(vars + 0x30);
        func_0038CE90(m + 4, m, axis);
        func_0038CF68(m + 4, m + 4, 1.0f);
        func_0038CE90(m + 8, m + 4, m);
        m[12] = 0.0f;
        m[13] = 0.0f;
        m[14] = 0.0f;
        m[15] = 1.0f;
        func_003C48A8(m, out);
        r = func_L01_00443A18(0.7853982f, 1.5707964f);
        f = func_0038DAB8(out[2], r);
        func_00382760(vars + 0x20, 1.0f, f, func_003824E0(-0.1f, 0.45f));
    }
    *(vu0_q *)(obj + 0x10) = *(vu0_q *)(vars + 0x30);
    *(s16 *)(vars + 0x4C) = 0;
    *(s32 *)(vars + 0x54) = 0;
}
