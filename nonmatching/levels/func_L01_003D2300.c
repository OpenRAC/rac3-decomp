/* PAL near miss (Codex wave 6): near miss: does not compile in its file's context yet (declaration conflicts; the worker's note at the top has the details).
 * Worker's note: Context blocks compile: earlier func_L01_003D2300(void) must accept moby pointer; .02.log. Standalone diagnostic 180 diff (.04.log), loops/addressing/register allocation. No type workaround.
 */
#include "common.h"
/* localdecomp:start func_L01_003D2300 */
typedef struct Node_003D2300 {
    f32 x, y, z, padC, radius, alpha, angle, pad1C, scale;
    u32 color;
    struct Node_003D2300 *next;
} Node_003D2300;
typedef struct { u8 pad[0x10]; u8 *texture; u8 pad14[0x128]; Node_003D2300 *head; } Data_003D2300;
extern f32 D_001DF340_sda[8];
extern f32 D_001DF360_sda[8];
__asm__(".extern D_001DF340_sda, 4");
__asm__(".extern D_001DF360_sda, 4");
extern f32 D_001DF2FC_sda;
extern f32 D_L01_001E2340_003D2300[8];
extern f32 D_L01_001E2300_003D2300[4][3];
extern u32 D_L01_001E2330_003D2300[4];
extern f32 D_L01_001E2A40_003D2300[4];
void func_L01_003D2300(u8 *moby) {
    extern void func_003A9440(long, unsigned long);
    extern long func_00389598(void *);
    extern void func_0038C750(void);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern f32 func_0038DAB8(f32, f32);
    extern void func_003D3A24(s32, void *, void *, void *, s32);
    Data_003D2300 *data = *(Data_003D2300 **)(moby + 0x68);
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
    for (i = 0; i < 4; i++) {
        D_L01_001E2340_003D2300[i*2] = D_001DF340_sda[i*2];
        D_L01_001E2340_003D2300[i*2+1] = D_001DF340_sda[i*2+1];
    }
    node = data->head;
    while (node != 0) {
        fade = D_L01_001E2A40_003D2300[2] - node->z;
        if (fade < D_001DF2FC_sda) {
            fade = fade / D_001DF2FC_sda;
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
        for (i = 0; i < 4; i++) {
            D_L01_001E2330_003D2300[i] = color;
            D_L01_001E2300_003D2300[i][0] = node->x + a[0] * D_001DF360_sda[i*2] + b[0] * D_001DF360_sda[i*2+1];
            D_L01_001E2300_003D2300[i][1] = node->y + a[1] * D_001DF360_sda[i*2] + b[1] * D_001DF360_sda[i*2+1];
            D_L01_001E2300_003D2300[i][2] = node->z;
        }
        func_003D3A24(4, D_L01_001E2300_003D2300, D_L01_001E2330_003D2300, D_L01_001E2340_003D2300, 1);
    next:
        node = node->next;
    }
    func_003A9440(71, 0x5360B);
}
/* localdecomp:end func_L01_003D2300 */
