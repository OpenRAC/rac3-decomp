#include "common.h"

/* NTSC-U counterpart of func_L09_003C70C0 (src/levels/shared/L09_003C5E78.c) */
typedef struct HrugisEffectCamera {
    char pad00[0x140];
    float position[4];
} HrugisEffectCamera;

/* localdecomp:start func_L09_003C5730 */
extern HrugisEffectCamera D_L09_001E2A40;
extern void func_003BDA38(void *, int, void *);
extern float func_00388A28(float, float);
extern float func_L01_00440918(float, float);
extern float func_0037E250(float, float);
extern float func_00389380(float, float);
extern void func_0037E4B8(void *, float, float, float);
extern unsigned char *func_L01_004633E8(float, float, float, float,
                                    void *, int, void *, int, int);
extern int func_0037E208(int, int);

void func_L09_003C5730(char *object, int a1, int joint, float radius) {
    float initial[4], point[4], velocity[4];
    float heading, speed, tilt, yaw;
    unsigned char *particle;
    unsigned char *data;
    int one = 1;
    int r;
    func_003BDA38(object, a1, initial);
    heading = func_00388A28(D_L09_001E2A40.position[0] - *(float *)(object + 0x10),
                            D_L09_001E2A40.position[1] - *(float *)(object + 0x14));
    point[0] = initial[0] + func_L01_00440918(0, radius);
    point[1] = initial[1] + func_L01_00440918(0, radius);
    point[2] = initial[2] + func_L01_00440918(0, radius);
    if (joint != 0) {
        speed = func_0037E250(radius * 0.016666668f, radius * 2 * 0.016666668f);
        tilt = func_L01_00440918(0, 1.3962634f);
    } else {
        speed = func_0037E250(radius * 2 * 0.016666668f, radius * 4.0f * 0.016666668f);
        tilt = func_L01_00440918(0.69813168f, 0.87266463f);
    }
    yaw = func_00389380(heading, func_L01_00440918(0, 1.5707964f));
    func_0037E4B8(velocity, speed, yaw, tilt);
    particle = func_L01_004633E8(0, 1.0f, 1.01f, radius * 210000.0f,
                             point, -one, velocity, 0x101010, 0);
    if (particle != 0) {
        particle[3] = 0x44;
        *(short *)(particle + 0xA) = func_0037E208(40, 70);
        particle[9] = 0x64;
        data = particle + 0x20;
        r = func_0037E208(1, 10);
        *(int *)(data + 4) = 3;
        data[0xA] = 0x7F;
        *(float *)(data + 0x1C) = r;
        data[0xB] = particle[0xA];
    }
}
/* localdecomp:end func_L09_003C5730 */
