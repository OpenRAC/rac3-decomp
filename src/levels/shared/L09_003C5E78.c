#include "common.h"

typedef void (*fn_3C5D58)(u8 *);

typedef struct HrugisEffectCamera {
    char pad00[0x140];
    float position[4];
} HrugisEffectCamera;

INCLUDE_ASM("asm/levels", func_L09_003C5E78);

INCLUDE_ASM("asm/levels", func_L09_003C6388);

INCLUDE_ASM("asm/levels", func_L09_003C6890);

INCLUDE_ASM("asm/levels", func_L09_003C6900);

INCLUDE_ASM("asm/levels", func_L09_003C6C38);

INCLUDE_ASM("asm/levels", func_L09_003C6D50);

/* localdecomp:start func_L09_003C70C0 */
extern HrugisEffectCamera D_L09_001E29C0;
extern void func_003C2F58(void *, int, void *);
extern float func_0038D160(float, float);
extern float func_L01_00443A18(float, float);
extern float func_003824E0(float, float);
extern float func_0038DAB8(float, float);
extern void func_00382760(void *, float, float, float);
extern unsigned char *func_L01_004669B0(float, float, float, float,
                                    void *, int, void *, int, int);
extern int func_00382498(int, int);

void func_L09_003C70C0(char *object, int a1, int joint, float radius) {
    float initial[4], point[4], velocity[4];
    float heading, speed, tilt, yaw;
    unsigned char *particle;
    unsigned char *data;
    int one = 1;
    int r;
    func_003C2F58(object, a1, initial);
    heading = func_0038D160(D_L09_001E29C0.position[0] - *(float *)(object + 0x10),
                            D_L09_001E29C0.position[1] - *(float *)(object + 0x14));
    point[0] = initial[0] + func_L01_00443A18(0, radius);
    point[1] = initial[1] + func_L01_00443A18(0, radius);
    point[2] = initial[2] + func_L01_00443A18(0, radius);
    if (joint != 0) {
        speed = func_003824E0(radius * 0.020000001f, radius * 2 * 0.020000001f);
        tilt = func_L01_00443A18(0, 1.3962634f);
    } else {
        speed = func_003824E0(radius * 2 * 0.020000001f, radius * 4.0f * 0.020000001f);
        tilt = func_L01_00443A18(0.69813168f, 0.87266463f);
    }
    yaw = func_0038DAB8(heading, func_L01_00443A18(0, 1.5707964f));
    func_00382760(velocity, speed, yaw, tilt);
    particle = func_L01_004669B0(0, 1.0f, 1.01f, radius * 210000.0f,
                             point, -one, velocity, 0x101010, 0);
    if (particle != 0) {
        particle[3] = 0x44;
        *(short *)(particle + 0xA) = (func_00382498(40, 70) * 5 + 2) / 6;
        particle[9] = 0x64;
        data = particle + 0x20;
        r = func_00382498(1, 10);
        *(int *)(data + 4) = 3;
        data[0xA] = 0x7F;
        *(float *)(data + 0x1C) = (r * 5 + 2) / 6;
        data[0xB] = particle[0xA];
    }
}
/* localdecomp:end func_L09_003C70C0 */

INCLUDE_ASM("asm/levels", func_L09_003C7338);

INCLUDE_ASM("asm/levels", func_L09_003C7568);

/* localdecomp:start func_L09_003C7748 */

extern fn_3C5D58 *func_L01_0043B548(s32, s32);
extern void func_L09_003C6C38(u8 *);
extern void func_003C2880(u8 *);
extern u8 *D_001A65C0[];

void func_L09_003C7748(u8 *a0, s32 a1) {
    u8 *pv = *(u8 **)(a0 + 104);
    fn_3C5D58 *tbl;
    if (*(s32 *)(pv + 464) != 0) {
        tbl = func_L01_0043B548(6625, 108);
        if (a1 == 0 && D_001A65C0[0] == a0) {
            func_L09_003C6C38(a0);
        }
        tbl[0](a0);
        if (a1 != 0) {
            tbl[1](a0);
        }
    } else {
        func_003C2880(a0);
    }
}
/* localdecomp:end func_L09_003C7748 */

/* localdecomp:start func_L09_003C77E8 */
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                             s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00452310(void *, s32, void *, s32, s32, f32, f32, f32, f32, f32, s32, f32, f32, s32, s32);
extern u8 D_L09_001D66B0[8];

void func_L09_003C77E8(u8 *a0) {
    func_L01_003303B8(a0 + 0x10, 1, 0x19, 0x14, 0x14, 0x14, 0x2D, 2, 1.5f, 10.0f, 0.0f, 2.0f,
                      0, 0, 0, 0, 1, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF,
                      0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
    func_L01_00452310(a0, 0x3FF, D_L09_001D66B0, 1, 0x23, -1.0f, 3.0f, 6.0f, 5.0f, 15.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0);
}
/* localdecomp:end func_L09_003C77E8 */

INCLUDE_ASM("asm/levels", func_L09_003C7928);

INCLUDE_ASM("asm/levels", func_L09_003C7B78);

INCLUDE_ASM("asm/levels", func_L09_003C7DF8);

INCLUDE_ASM("asm/levels", func_L09_003C8158);

INCLUDE_ASM("asm/levels", func_L09_003C8740);

INCLUDE_ASM("asm/levels", func_L09_003C92E0);

INCLUDE_ASM("asm/levels", func_L09_003CA6A8);

INCLUDE_ASM("asm/levels", func_L09_003CA7E8);

INCLUDE_ASM("asm/levels", func_L09_003CA998);
