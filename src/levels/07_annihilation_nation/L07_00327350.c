#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L07_00327350 */
extern float D_L07_001DCA08;
__asm__(".extern D_L07_001DCA08, 4");
extern float D_L07_001DCA0C;
__asm__(".extern D_L07_001DCA0C, 4");
extern float D_L07_001DCA10;
__asm__(".extern D_L07_001DCA10, 4");
extern s32 D_L07_001DCA14;
__asm__(".extern D_L07_001DCA14, 4");
extern float D_L07_001DCA18;
__asm__(".extern D_L07_001DCA18, 4");
extern s32 D_L07_001DEF40;
__asm__(".extern D_L07_001DEF40, 16");
extern s32 func_L01_004561B8(u8 *);
extern s32 func_00382468(s32);
extern void func_003C3A10(u8 *, s32, s32, s32);
extern void func_L01_004450F0(u8 *, s32, s32);
extern float func_0038D160(float, float);
extern float func_0038DBA0(float, float);
extern float func_0038DAB8(float, float);

void func_L07_00327350(u8 *obj) {
    float v[4];
    float angle, heading, y;
    s32 anim;
    u8 prev;
    float k = 2.5f;

    switch (obj[0x20]) {
    case 1:
        if (func_L01_004561B8(obj) != 0) {
            prev = obj[0x43];
            if (prev != func_00382468(2)) {
                anim = func_00382468(2);
                func_003C3A10(obj, anim, 0, 8);
            }
        }
        if (D_L07_001DCA10 < k && func_00382468(60) == 0) {
            func_L01_004450F0(obj, 2, -1);
        } else if (k < D_L07_001DCA08 && func_00382468(60) == 0) {
            func_L01_004450F0(obj, 3, -1);
        }
        break;
    case 2:
        if (func_L01_004561B8(obj) != 0) {
            prev = obj[0x43];
            if (prev != func_00382468(2) + 2) {
                anim = func_00382468(2);
                func_003C3A10(obj, anim + 2, 0, 8);
            }
        } else if (k < D_L07_001DCA0C && func_00382468(60) == 0) {
            func_L01_004450F0(obj, 1, -1);
        }
        break;
    case 3:
        v[3] = 1.0f;
        v[0] = 500.0f;
        v[1] = 600.0f;
        v[2] = 500.0f;
        angle = ((float)(D_L07_001DEF40 % D_L07_001DCA14) * -6.2831855f) / (float)D_L07_001DCA14 + 3.1415927f;
        heading = func_0038D160(*(float *)(obj + 0x10) - v[0], *(float *)(obj + 0x14) - v[1]);
        if (func_0038DBA0(heading, angle) < D_L07_001DCA18
            || func_0038DBA0(heading, func_0038DAB8(angle, 3.1415927f)) < D_L07_001DCA18) {
            if (obj[0x43] != 4) {
                func_003C3A10(obj, 4, 0, 8);
            }
        } else if (obj[0x60] & 2) {
            prev = obj[0x43];
            if (prev != func_00382468(2)) {
                anim = func_00382468(2);
                func_003C3A10(obj, anim, 0, 8);
            }
        }
        if (D_L07_001DCA0C < k && func_00382468(60) == 0) {
            func_L01_004450F0(obj, 1, -1);
        }
        break;
    }
}
/* localdecomp:end func_L07_00327350 */
