/* functional: high. Near miss, 6 words differ from retail (argument-move order in the first particle call); behaviour identical. */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003B8FA0;
extern void func_L01_00443B88(f32 *, f32, f32);

void func_L03_003B8FA0(V4_003B8FA0 *at, s32 n, s32 c1, s32 c2) {
    V4_003B8FA0 pos;
    V4_003B8FA0 vel;
    f32 size;
    s32 spin;
    u8 *p;
    u8 *pp = (u8 *)&pos;
    s32 i;

    pos = *at;
    for (i = 0; i < n; i++) {
        size = func_003824E0(1.0f, 2.0f);
        spin = func_00382468(2);
        if (spin == 0) {
            spin--;
        }
        func_L01_00443B88((f32 *)&vel, 0.05f, 0.25f);
        p = func_L01_0046B458(pp, 0x11, c1, 0, spin, &vel, 0, size * 0.1f, size, 0.0028800003f);
        if (p != 0) {
            p[9] = 0x74;
        }
        p = func_L01_0046B458(pp, 0x11, c2, 1, -spin, &vel, 0, size * 0.07f, size * 0.7f, 0.0028800003f);
        if (p != 0) {
            p[9] = 0x74;
        }
    }
}
