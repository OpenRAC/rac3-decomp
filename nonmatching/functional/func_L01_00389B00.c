/* functional: high. 6 diff vs retail, scheduling only; 4 jals identical; VU0 add inline asm */
#include "common.h"
typedef int Q_00389B00 __attribute__((mode(TI)));
void *func_L01_00389B00(Q_00389B00 *position, void *direction, Q_00389B00 *rotation, s32 owner, float value)
{
    extern u8 *func_003C24B0(s32, s32);
    extern void func_0038CF68(void *, void *, float);
    extern void func_L01_0038A4B8(void *);
    Q_00389B00 temp;
    u8 *moby = func_003C24B0(0x1883, 0x80);
    if (moby) {
        u8 *vars = *(u8 **)(moby + 0x68);
        void *velocity = vars + 0x20;
        void *moby_position = moby + 0x10;
        moby[0x30] = 255;
        moby[0x20] = 0;
        *(u16 *)(moby + 0x32) = 255;
        moby[0x31] = 1;
        *(u16 *)(moby + 0x34) |= 0x41;
        func_0038CF68(velocity, direction, 0.16000001f);
        *(Q_00389B00 *)vars = *position;
        *(Q_00389B00 *)(moby + 0x10) = *rotation;
        func_0038CF68(&temp, velocity, -1.5f);
        __asm__(
            "lqc2 vf1, %1\n"
            "lqc2 vf2, %2\n"
            "vadd.xyz vf1, vf1, vf2\n"
            "sqc2 vf1, %0\n"
            : "=m" (*(Q_00389B00 *)(vars + 0x50))
            : "m" (*position), "m" (temp)
            : "vf1", "vf2");
        *(float *)(vars + 0x60) = value;
        *(s32 *)(vars + 0x34) = owner;
        *(float *)(vars + 0x3c) = 0.05882353f;
        *(s32 *)(vars + 0x38) = 17;
        func_L01_0038A4B8(moby_position);
    }
    return moby;
}
