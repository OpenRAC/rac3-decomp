#include "common.h"
/* localdecomp:start func_L39_00627180 */
extern u8 D_L39_004998A0[];
extern float func_00388770(void *),func_00388800(void *,void *),func_00388A28(float,float);
extern float func_L01_00445168(float *,float,float *,float,float,float);
extern float func_00388960(float),func_00388978(float);
typedef union { u8 b[8]; u32 w[2]; } Buf_627180;
void func_L39_00627180(u8 *g) {
    Buf_627180 buf;
    float distance, max, angle, step;
    if (g[0x216] && *(float *)(g+0x2ac)>0.0f && *(float *)(g+0x1a0)<0.05000000447034836f && func_00388770(g+0x120)<0.05000000447034836f && *(float *)(g+0x2468)<0.2f &&
        ((({
        u8 *q = g + 0x19E6;
        u32 a;
        u32 r;
        if (*q == 0) {
            r = 0;
        } else {
            s32 n = *q;
            s32 k = ((u32)q - n) & 7;
            s32 m = n + 1;
            s32 i;
            u8 *d = buf.b;
            for (i = 0; i < 40; i += 5) {
                *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
            }
            a = buf.w[0] ^ (u32)q;
            buf.w[0] = a;
            buf.w[1] ^= a;
            r = buf.w[1];
        }
        r;
    }) ^ 0) == 0 || (({
        u8 *q = g + 0x19E6;
        u32 a;
        u32 r;
        if (*q == 0) {
            r = 0;
        } else {
            s32 n = *q;
            s32 k = ((u32)q - n) & 7;
            s32 m = n + 1;
            s32 i;
            u8 *d = buf.b;
            for (i = 0; i < 40; i += 5) {
                *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
            }
            a = buf.w[0] ^ (u32)q;
            buf.w[0] = a;
            buf.w[1] ^= a;
            r = buf.w[1];
        }
        r;
    }) ^ 2) == 0 || (({
        u8 *q = g + 0x19E6;
        u32 a;
        u32 r;
        if (*q == 0) {
            r = 0;
        } else {
            s32 n = *q;
            s32 k = ((u32)q - n) & 7;
            s32 m = n + 1;
            s32 i;
            u8 *d = buf.b;
            for (i = 0; i < 40; i += 5) {
                *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
            }
            a = buf.w[0] ^ (u32)q;
            buf.w[0] = a;
            buf.w[1] ^= a;
            r = buf.w[1];
        }
        r;
    }) ^ 4) == 0 || (({
        u8 *q = g + 0x19E6;
        u32 a;
        u32 r;
        if (*q == 0) {
            r = 0;
        } else {
            s32 n = *q;
            s32 k = ((u32)q - n) & 7;
            s32 m = n + 1;
            s32 i;
            u8 *d = buf.b;
            for (i = 0; i < 40; i += 5) {
                *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
            }
            a = buf.w[0] ^ (u32)q;
            buf.w[0] = a;
            buf.w[1] ^= a;
            r = buf.w[1];
        }
        r;
    }) ^ 10) == 0 || (({
        u8 *q = g + 0x19E6;
        u32 a;
        u32 r;
        if (*q == 0) {
            r = 0;
        } else {
            s32 n = *q;
            s32 k = ((u32)q - n) & 7;
            s32 m = n + 1;
            s32 i;
            u8 *d = buf.b;
            for (i = 0; i < 40; i += 5) {
                *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
            }
            a = buf.w[0] ^ (u32)q;
            buf.w[0] = a;
            buf.w[1] ^= a;
            r = buf.w[1];
        }
        r;
    }) ^ 1) == 0)) *(short *)(g+0x336)=5;
    if (*(short *)(g+0x336)) {
        distance=func_00388800(g+0xa0,g+0x1d0);
        max=*(float *)(g+0x1f4)*0.9f;
        if (distance<max) {
            angle=func_00388A28(*(float *)(g+0xa0)-*(float *)(g+0x1d0),*(float *)(g+0xa4)-*(float *)(g+0x1d4));
            if (distance<*(float *)(g+0x1f4)*0.05f) angle=*(float *)(g+0xb8);
            step=distance-max;
            func_L01_00445168(&step,0,(float *)(g+0x204),0.03f,0.3f,0.046666666865348816f);
            *(float *)(g+0x130)=func_00388960(angle)* *(float *)(g+0x204);
            *(float *)(g+0x134)=func_00388978(angle)* *(float *)(g+0x204);
            *(float *)(g+0x138)=0.0f;
        }
    } else *(float *)(g+0x204)=0.0f;
}
/* localdecomp:end func_L39_00627180 */
