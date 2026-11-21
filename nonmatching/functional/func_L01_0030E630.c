/* functional: high. Rewritten from the PAL asm (NTSC twin has different constants/callees); vu0 vsub.xyz/vadd.xyz as plain C with w kept from operand a; byte diffs expected (256). */
typedef struct { f32 x, y, z, w; } vu0_v4;
/* vsub.xyz / vadd.xyz: xyz from the operands, w kept from the first operand */
static void vec_sub_ab(f32 *d, f32 *a, f32 *b) { f32 x = a[0] - b[0], y = a[1] - b[1], z = a[2] - b[2], w = a[3]; d[0] = x; d[1] = y; d[2] = z; d[3] = w; }
static void vec_add_ab(f32 *d, f32 *a, f32 *b) { f32 x = a[0] + b[0], y = a[1] + b[1], z = a[2] + b[2], w = a[3]; d[0] = x; d[1] = y; d[2] = z; d[3] = w; }
extern vu0_v4 D_L01_001E29C0;
extern vu0_v4 D_001A4C90;
extern s32 D_L01_001D673C;
__asm__(".extern D_L01_001D673C, 16");
extern f32 D_001DC664_sda, D_001DC668_sda, D_001DC66C_sda, D_001DC670_sda, D_001DC674_sda, D_001DC678_sda, D_001DC67C_sda;
__asm__(".extern D_001DC664_sda, 4");
__asm__(".extern D_001DC668_sda, 4");
__asm__(".extern D_001DC66C_sda, 4");
__asm__(".extern D_001DC670_sda, 4");
__asm__(".extern D_001DC674_sda, 4");
__asm__(".extern D_001DC678_sda, 4");
__asm__(".extern D_001DC67C_sda, 4");
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D890(void *, void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern s32 func_0013D3E0(void);
extern f32 func_L01_00443A18(f32, f32);
extern u8 *func_L01_0046B458(void *, s32, u32, s32, s32, void *, f32, f32, f32, s32);

void func_L01_0030E630(f32 *pos, s32 count, s32 mode) {
    f32 v0[4] __attribute__((aligned(16)));
    f32 v10[4] __attribute__((aligned(16)));
    f32 v20[4] __attribute__((aligned(16)));
    f32 v30[4] __attribute__((aligned(16)));
    f32 v40[4] __attribute__((aligned(16)));
    s32 dir;
    f32 t;
    f32 speed;
    f32 life;
    f32 sc;
    u8 *p;

    vec_sub_ab(v20, (f32 *)&D_L01_001E29C0, pos);
    if (D_L01_001D673C == 0) {
        v20[2] = 0.0f;
        v30[0] = 0.0f;
        v30[1] = 0.0f;
        v30[2] = 1.0f;
        v30[3] = 1.0f;
    } else {
        vec_sub_ab(v40, pos, (f32 *)&D_001A4C90);
        func_0038CF68(v30, v40, 1.0f);
        t = func_0038CE68(v30, v20);
        func_0038CE20(v40, v30, t);
        vec_sub_ab(v20, v20, v40);
    }
    for (; count > 0; count--) {
        life = func_003824E0(D_001DC678_sda, D_001DC67C_sda);
        dir = func_00382468(2);
        if (dir == 0) {
            dir = -1;
        }
        func_0038D890(v0, v20, v30, func_003824E0(-1.0471976f, 1.0471976f));
        speed = func_003824E0(D_001DC664_sda, D_001DC668_sda) * 0.02f;
        func_0038CF68(v0, v0, speed);
        t = func_003824E0(D_001DC66C_sda, D_001DC670_sda) * 0.02f;
        *(s128 *)v10 = *(s128 *)pos;
        v0[2] = t;
        v10[0] += func_L01_00443A18(0.0f, 0.15f);
        v10[1] += func_L01_00443A18(0.0f, 0.15f);
        v10[2] += func_L01_00443A18(0.0f, 0.15f);
        if (mode == 0) {
            if ((func_0013D3E0() & 1) == 0) {
                sc = 3.5f;
                func_0038CE20(v0, v0, 1.5f);
                p = func_L01_0046B458(v10, 0x32, 0x7F800000, 0, dir, v0, life * 0.1f * sc, life, D_001DC674_sda * 1.44f, 1);
                if (p != 0) {
                    p[9] = 0x74;
                }
                p = func_L01_0046B458(v10, 0x32, 0x7F7F7F7F, 1, -dir, v0, life * 0.07f * sc, life * 0.7f, D_001DC674_sda * 1.44f, 1);
                if (p != 0) {
                    p[9] = 0x74;
                }
            } else {
                vec_sub_ab(v40, (f32 *)&D_L01_001E29C0, v10);
                func_0038CF68(v40, v40, speed);
                sc = 20.5f;
                vec_add_ab(v0, v0, v40);
                p = func_L01_0046B458(v10, 0x21, 0x7F800000, 0, dir, v0, life * 0.1f * sc, life, D_001DC674_sda * 1.44f, 1);
                if (p != 0) {
                    p[9] = 0x74;
                }
                p = func_L01_0046B458(v10, 0x21, 0x7F7F7F7F, 1, -dir, v0, life * 0.07f * sc, life * 0.7f, D_001DC674_sda * 1.44f, 1);
                if (p != 0) {
                    p[9] = 0x74;
                }
            }
        } else {
            if ((func_0013D3E0() & 1) == 0) {
                sc = 3.0f;
                func_0038CE20(v0, v0, 1.5f);
                p = func_L01_0046B458(v10, 0x32, 0x7F800000, 0, dir, v0, life * 0.1f * sc, life, D_001DC674_sda * 1.44f, 1);
                if (p != 0) {
                    p[9] = 0x74;
                }
                p = func_L01_0046B458(v10, 0x32, 0x7F7F7F7F, 1, -dir, v0, life * 0.07f * sc, life * 0.7f, D_001DC674_sda * 1.44f, 1);
                if (p != 0) {
                    p[9] = 0x74;
                }
            } else {
                vec_sub_ab(v40, (f32 *)&D_L01_001E29C0, v10);
                func_0038CF68(v40, v40, speed);
                sc = 2.5f;
                vec_add_ab(v0, v0, v40);
                p = func_L01_0046B458(v10, 0x21, 0x7F800000, 0, dir, v0, life * 0.1f * sc, life, D_001DC674_sda * 1.44f, 1);
                if (p != 0) {
                    p[9] = 0x74;
                }
                p = func_L01_0046B458(v10, 0x21, 0x7F7F7F7F, 1, -dir, v0, life * 0.07f * sc, life * 0.7f, D_001DC674_sda * 1.44f, 1);
                if (p != 0) {
                    p[9] = 0x74;
                }
            }
        }
    }
}
