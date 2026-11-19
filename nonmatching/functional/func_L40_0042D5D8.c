/* functional: high. Rewritten from PAL asm using the NTSC draft's shape: PAL constants (0.02 tick, 0x4B/4.0f, 0x19) and callees func_L01_004669B0/0046A610; compiles; vsub.xyz written as plain C */
/* localdecomp:start func_L40_0042D5D8 */
extern f32 D_L40_00249F40[];
extern u8 D_L40_0029AF58[];
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_L39_005B4410(f32, f32);
extern f32 func_L39_005B4468(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_00382760(void *, f32, f32, f32);
extern u8 *func_L01_004669B0(void *, f32, f32, f32, f32, s32, void *, u32, s32);
extern u8 *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);

void func_L40_0042D5D8(f32 *pos) {
    f32 d[4];
    f32 vel[4];
    f32 at[4];
    f32 pt[4];
    f32 heading;
    f32 speed;
    f32 size;
    f32 tilt;
    f32 yaw;
    s32 n;
    s32 i;
    u8 *q;
    u8 *data;

    d[0] = D_L40_00249F40[0] - pos[0];
    d[1] = D_L40_00249F40[1] - pos[1];
    d[2] = D_L40_00249F40[2] - pos[2];
    d[3] = D_L40_00249F40[3];
    heading = func_0038D160(d[0], d[1]);
    for (i = 19; i >= 0; i--) {
        speed = func_L39_005B4410(0.2f, 3.0f);
        at[0] = 0.0f; at[1] = 0.0f; at[2] = -1.0f; at[3] = 0.0f;
        func_0038CE20(vel, at, -(speed * 0.020000001f));
        n = (s32)func_L39_005B4468(1.0f, 2.0f);
        size = func_L39_005B4410(0.3f, 0.75f) * 210000.0f;
        pt[0] = pos[0] + func_L39_005B4468(0.0f, 0.2f);
        pt[1] = pos[1] + func_L39_005B4468(0.0f, 0.2f);
        pt[2] = pos[2] + func_L39_005B4468(0.0f, 0.2f);
        q = func_L01_004669B0(pt, 0.0f, 1.0f, 1.01f, size, n, vel, 0x7F202020, 0);
        if (q != 0) {
            *(s16 *)(q + 0xA) = 0x4B;
            q[3] = 0x44;
            q[9] = 0x44;
            data = q + 0x20;
            *(f32 *)(data + 0x1C) = 4.0f;
            *(s32 *)(data + 4) = 3;
            data[0xA] = 0x30;
            data[0xB] = q[0xA];
        }
        speed = func_L39_005B4410(1.0f, 2.0f);
        tilt = func_L39_005B4410(0.0f, 1.3962634f);
        yaw = func_0038DAB8(heading, func_L39_005B4468(0.0f, 1.3962634f));
        func_00382760(vel, speed * 0.020000001f, yaw, tilt);
        pt[0] = pos[0] + func_L39_005B4468(0.0f, 0.1f);
        pt[1] = pos[1] + func_L39_005B4468(0.0f, 0.1f);
        pt[2] = pos[2] + func_L39_005B4468(0.0f, 0.1f);
        q = func_L01_0046A610(pt, vel, 0x19, 0x7F, 0x7FFF8040, n,
                              func_L39_005B4410(0.25f, 0.7f) * 210000.0f, 500.0f, 1.0f, 0.0f, 0.0f);
        if (q != 0) {
            q[2] = (*(u8 **)(D_L40_0029AF58 + 0x184))[6];
        }
    }
}
/* localdecomp:end func_L40_0042D5D8 */
