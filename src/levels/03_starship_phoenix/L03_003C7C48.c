#include "common.h"
#include "vu0.h"

typedef struct { f32 x, y, z, w; } V4_003B5710;

/* localdecomp:start func_L03_003C7C48 */
extern u8 D_L03_001E2440[];
extern void func_0038CF68(void *, void *, f32);
extern void func_0038D890(void *, void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern f32 func_L01_00443A18(f32, f32);
extern u8 *func_L01_0046B458(f32 *, f32, s32, f32, f32, s32, s32, s32, f32 *, s32);

void func_L03_003C7C48(f32 *pos, s32 count) {
    f32 velocity[4], origin[4];
    V4_003B5710 direction;
    V4_003B5710 axis;
    f32 offset[4];
    f32 size, zero, angle, k;
    s32 sign;
    s32 i;
    u8 *p;
    vec_sub_ab(&direction, D_L03_001E2440, pos);
    func_0038CF68(offset, &direction, 0.3f);
    direction.z = 0;
    axis.x = 0;
    axis.y = 0;
    axis.z = 1.0f;
    axis.w = 1.0f;
    i = 0;
    if (count > 0) {
    k = 0.020000001f;
    zero = direction.z;
    for (; i < count; i++) {
        size = func_003824E0(0.5f, 2.0f);
        sign = func_00382468(2);
        if (!sign) sign--;
        angle = func_003824E0(-1.0471976f, 1.0471976f);
        func_0038D890(velocity, &direction, &axis, angle);
        func_0038CF68(velocity, velocity, func_003824E0(0.05f, 3.0f) * k);
        velocity[2] = func_003824E0(1.0f, 5.0f) * k;
        vec_add_ab(origin, pos, offset);
        pos[0] += func_L01_00443A18(zero, 0.15f);
        pos[1] += func_L01_00443A18(zero, 0.15f);
        pos[2] += func_L01_00443A18(zero, 0.15f);
        p = func_L01_0046B458(origin, size * 0.1f, 0x32, size, 0.0028800003f, 0xDD10FFFF, 0, sign, velocity, 0);
        if (p) p[9] = 0x74;
        p = func_L01_0046B458(origin, size * 0.07f, 0x32, size * 0.7f, 0.0028800003f, 0xDD10FFFF, 1, -sign, velocity, 0);
        if (p) p[9] = 0x74;
    }
    }
}
/* localdecomp:end func_L03_003C7C48 */

/* localdecomp:start func_L03_003C7EF0 */
void func_L01_004AA7E8(s32, s32);
extern u8 D_00142799[];

void func_L03_003C7EF0(void *arg0) {
    if (*(u8 *)((u8 *)arg0 + 0x20) == 0) {
        *(u8 *)((u8 *)arg0 + 0x20) = 1U;
    }
    if (D_00142799[0] != 0) {
        void *p = *(void **)((u8 *)arg0 + 0x24);
        *(u16 *)((u8 *)arg0 + 0x34) = (u16) ((*(u16 *)((u8 *)arg0 + 0x34)) & 0xFFBE);
        *(u16 *)((u8 *)arg0 + 0x34) = (u16) ((*(u16 *)((u8 *)arg0 + 0x34)) | (*(u16 *)((u8 *)p + 0x44) & 0x1000));
        *(s32 *)((u8 *)arg0 + 0x98) = *(s32 *)((u8 *)p + 0x10);
    } else {
        *(s32 *)((u8 *)arg0 + 0x98) = 0;
        *(u16 *)((u8 *)arg0 + 0x34) = (u16) (((*(u16 *)((u8 *)arg0 + 0x34)) | 0x41) & 0xEFFF);
        func_L01_004AA7E8((s32) arg0, 1);
    }
}
/* localdecomp:end func_L03_003C7EF0 */

/* localdecomp:start func_L03_003C7F78 */
extern unsigned char D_0014279A[];

void func_L03_003C7F78(unsigned char *p) {
    if (p[0x20] == 0) {
        p[0x20] = 1;
    }
    if (D_0014279A[0] != 0) {
        unsigned char *q = *(unsigned char **)(p + 0x24);
        unsigned short f = *(unsigned short *)(p + 0x34) & 0xFFBE;
        *(unsigned short *)(p + 0x34) = f;
        *(unsigned short *)(p + 0x34) = f | (*(unsigned short *)(q + 0x44) & 0x1000);
        *(int *)(p + 0x98) = *(int *)(q + 0x10);
    } else {
        *(int *)(p + 0x98) = 0;
        *(unsigned short *)(p + 0x34) = ((*(unsigned short *)(p + 0x34) | 0x41) & 0xEFFF);
        func_L01_004AA7E8((s32) p, 1);
    }
}
/* localdecomp:end func_L03_003C7F78 */

/* localdecomp:start func_L03_003C8000 */
void func_L01_004AA7E8(s32, s32);
extern u8 D_0014279B[];

void func_L03_003C8000(void *arg0) {
    if ((*(u8 *)((u8 *)arg0 + 0x20)) == 0) {
        *(u8 *)((u8 *)arg0 + 0x20) = 1U;
    }
    if (D_0014279B[0] != 0) {
        void *o = *(void **)((u8 *)arg0 + 0x24);
        *(u16 *)((u8 *)arg0 + 0x34) = (u16) ((*(u16 *)((u8 *)arg0 + 0x34)) & 0xFFBE);
        *(u16 *)((u8 *)arg0 + 0x34) = (u16) ((*(u16 *)((u8 *)arg0 + 0x34)) | (*(u16 *)((u8 *)o + 0x44) & 0x1000));
        *(s32 *)((u8 *)arg0 + 0x98) = *(s32 *)((u8 *)o + 0x10);
    } else {
        *(s32 *)((u8 *)arg0 + 0x98) = 0;
        *(u16 *)((u8 *)arg0 + 0x34) = (u16) (((*(u16 *)((u8 *)arg0 + 0x34)) | 0x41) & 0xEFFF);
        func_L01_004AA7E8((s32) arg0, 1);
    }
}
/* localdecomp:end func_L03_003C8000 */

/* localdecomp:start func_L03_003C8088 */
void func_L01_004AA7E8(s32, s32);
extern u8 D_0014279C[];

void func_L03_003C8088(void *arg0) {
    if ((*(u8 *)((u8 *)arg0 + 0x20)) == 0) {
        if (D_0014279C[0] == 0) {
            *(s32 *)((u8 *)arg0 + 0x98) = 0;
            *(u16 *)((u8 *)arg0 + 0x34) = (u16) (((*(u16 *)((u8 *)arg0 + 0x34)) | 0x41) & 0xEFFF);
            func_L01_004AA7E8((s32) arg0, 1);
        }
        *(u8 *)((u8 *)arg0 + 0x20) = 1U;
    }
}
/* localdecomp:end func_L03_003C8088 */

/* localdecomp:start func_L03_003C80E8 */
void func_L01_004AA7E8(s32, s32);
extern u8 D_0014279D[];

void func_L03_003C80E8(void *arg0) {
    if ((*(u8 *)((u8 *)arg0 + 0x20)) == 0) {
        if (D_0014279D[0] == 0) {
            *(s32 *)((u8 *)arg0 + 0x98) = 0;
            *(u16 *)((u8 *)arg0 + 0x34) = (u16) (((*(u16 *)((u8 *)arg0 + 0x34)) | 0x41) & 0xEFFF);
            func_L01_004AA7E8((s32) arg0, 1);
        }
        *(u8 *)((u8 *)arg0 + 0x20) = 1U;
    }
}
/* localdecomp:end func_L03_003C80E8 */

/* localdecomp:start func_L03_003C8148 */
void func_L01_004AA7E8(s32, s32);
extern u8 D_0014279E[];

void func_L03_003C8148(void *arg0) {
    u8 *p;

    if ((*(u8 *)((u8 *)arg0 + 0x20)) == 0) {
        *(u8 *)((u8 *)arg0 + 0x20) = 1U;
    }
    if (D_0014279E[0] != 0) {
        u16 f34 = *(u16 *)((u8 *)arg0 + 0x34);
        p = *(u8 **)((u8 *)arg0 + 0x24);
        f34 &= 0xFFBE;
        *(u16 *)((u8 *)arg0 + 0x34) = f34;
        f34 |= (*(u16 *)(p + 0x44)) & 0x1000;
        *(u16 *)((u8 *)arg0 + 0x34) = f34;
        *(s32 *)((u8 *)arg0 + 0x98) = *(s32 *)(p + 0x10);
    } else {
        *(s32 *)((u8 *)arg0 + 0x98) = 0;
        *(u16 *)((u8 *)arg0 + 0x34) = (u16) (((*(u16 *)((u8 *)arg0 + 0x34)) | 0x41) & 0xEFFF);
        func_L01_004AA7E8((s32) arg0, 1);
    }
}
/* localdecomp:end func_L03_003C8148 */
