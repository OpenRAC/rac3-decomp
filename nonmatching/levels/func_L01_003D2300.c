/* PAL near miss (haiku-w4): 67 words differ with the file's flags (-O2 -G8 -fopt-stack @ps2as -mvu0-use-vf0-vf2); prologue, node loop and quad stores match. Residual: register numbering in the first copy loop (dst/src pointers and counter), lui/addiu sharing of the 0x1E base in the call-site array addresses, and the node loop's shape 3 insns short of retail (bc1tl and beqz offsets). */
#include "common.h"
/* localdecomp:start func_L01_003D2300 */
typedef struct Node_003D2300 {
    f32 x, y, z, padC, radius, alpha, angle, pad1C, scale;
    u32 color;
    struct Node_003D2300 *next;
} Node_003D2300;
typedef struct { u8 pad[0x10]; u8 *texture; u8 pad14[0x128]; Node_003D2300 *head; } Data_003D2300;
extern f32 D_001DF340_sda;
extern f32 D_001DF344_w[];
extern f32 D_001DF360_sda;
extern f32 D_001DF364_v[];
__asm__(".extern D_001DF340_sda, 4");
__asm__(".extern D_001DF344_w, 16");
__asm__(".extern D_001DF360_sda, 4");
__asm__(".extern D_001DF364_v, 16");
extern f32 D_001DF2FC_sda;
__asm__(".extern D_001DF2FC_sda, 4");
extern f32 D_L01_001E2340_003D2300[8];
extern f32 D_L01_001E2344_003D2300[];
extern f32 D_L01_001E2340_c003D2300[];
extern f32 D_L01_001E2300_c003D2300[];
extern f32 D_L01_001E2300_q0[];
extern f32 D_L01_001E2304_q1[];
extern f32 D_L01_001E2308_q2[];
extern u32 D_L01_001E2330_c003D2300[];
extern f32 D_L01_001E2300_003D2300[4][3];
extern u32 D_L01_001E2330_003D2300[4];
extern f32 D_L01_001E2A40_003D2300[4];
void func_L01_003D2300(void *moby) {
    u8 *m = moby;
    extern void func_003A9440(long, unsigned long);
    extern long func_00389598(void *);
    extern void func_0038C750(void);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern f32 func_0038DAB8(f32, f32);
    extern void func_003D3A24(s32, void *, void *, void *, s32);
    Data_003D2300 *data = *(Data_003D2300 **)(m + 0x68);
    Node_003D2300 *node;
    f32 a[3], b[3], fade, angle;
    u32 color;
    s32 i;
    func_003A9440(8, 0);
    func_003A9440(20, 0xFF9000000260UL);
    func_003A9440(71, 0x513F1);
    func_003A9440(6, func_00389598(data->texture + 0x64));
    func_003A9440(66, 0x8000000044UL);
    func_0038C750();
    {
        s32 k;
        f32 *dst1 = D_L01_001E2344_003D2300;
        f32 *src1 = D_001DF344_w;
        f32 *dst0 = D_L01_001E2340_003D2300;
        f32 *src0 = &D_001DF340_sda;
        for (k = 3; k >= 0; k--) {
            *dst0 = *src0;
            *dst1 = *src1;
            src0 += 2;
            src1 += 2;
            dst0 += 2;
            dst1 += 2;
        }
    }
    node = data->head;
    while (node != 0) {
        f32 dz = D_L01_001E2A40_003D2300[2] - node->z;
        if (dz < D_001DF2FC_sda) {
            fade = dz / D_001DF2FC_sda;
            if (fade < 0.01f) goto next;
        } else fade = 1.0f;
        color = node->color + ((s32)(node->scale * node->alpha * fade * 127.0f) << 24);
        a[0] = func_0038D098(node->angle) * node->radius;
        a[1] = func_0038D0B0(node->angle) * node->radius;
        a[2] = 0.0f;
        angle = func_0038DAB8(node->angle, 1.5707963705062866f);
        b[0] = func_0038D098(angle) * node->radius;
        b[1] = func_0038D0B0(angle) * node->radius;
        b[2] = 0.0f;
        {
            f32 *q2 = &D_L01_001E2300_003D2300[0][2];
            f32 *q1 = &D_L01_001E2300_003D2300[0][1];
            f32 *q0 = &D_L01_001E2300_003D2300[0][0];
            f32 *m1 = D_001DF364_v;
            f32 *m0 = &D_001DF360_sda;
            u32 *cp = D_L01_001E2330_003D2300;
            for (i = 0; i < 4; i++) {
                *cp = color;
                *q0 = node->x + a[0] * m0[0] + b[0] * m1[0];
                *q1 = node->y + a[1] * m0[0] + b[1] * m1[0];
                *q2 = node->z;
                cp++;
                q0 += 3;
                q1 += 3;
                q2 += 3;
                m0 += 2;
                m1 += 2;
            }
        }
        func_003D3A24(4, D_L01_001E2300_c003D2300, D_L01_001E2330_c003D2300, D_L01_001E2340_c003D2300, 1);
    next:
        node = node->next;
    }
    func_003A9440(71, 0x5360B);
}
/* localdecomp:end func_L01_003D2300 */
