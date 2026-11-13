#include "common.h"

/* localdecomp:start func_L39_00572FD0 */
typedef struct { u8 pad0[0x24C]; s32 f24C; u8 pad250[0x2A3 - 0x250]; u8 f2A3; u8 pad2A4[0x2B8 - 0x2A4]; f32 f2B8; u8 pad2BC[0x2C8 - 0x2BC]; f32 f2C8; u8 pad2CC[0x460 - 0x2CC]; } E_00572FD0;
typedef struct { u8 pad0[0x20]; s32 arr[1]; } I_00572FD0;
typedef struct { u8 pad0[0x1C]; I_00572FD0 *info; } R_00572FD0;
typedef struct { u8 pad0[0x2450]; s32 f2450; u8 pad2454[0x2528 - 0x2454]; s32 f2528; u8 pad252C[0x254C - 0x252C]; s32 f254C; } P_00572FD0;
typedef struct { u8 pad0[0x7E]; s16 f7E; u8 pad80[4]; s16 f84; u8 pad86[0x94 - 0x86]; s32 f94; } A_00572FD0;
extern E_00572FD0 D_L39_0024DE80[];
__asm__(".extern D_L39_0024B850, 16");
extern R_00572FD0 *D_L39_0024B850;
extern P_00572FD0 *func_L39_0061BF38(s32);
extern void func_L39_005789E0(s32, s32, s32, f32, f32, f32, f32);

void func_L39_00572FD0(A_00572FD0 *arg0) {
    s32 idx = arg0->f94;
    P_00572FD0 *p = func_L39_0061BF38(idx);
    I_00572FD0 *info = D_L39_0024B850[arg0->f84].info;
    E_00572FD0 *e;
    if (p->f2528 != 0) {
        if (p->f254C == 5) return;
        if (p->f254C == 3) return;
    }
    e = &D_L39_0024DE80[idx];
    e->f2A3 = 0;
    arg0->f7E = 2;
    e->f2C8 = 0.018f;
    e->f2B8 = 0.018f;
    e->f24C = 0;
    p->f2450 = 0;
    info->arr[idx] = 0;
    func_L39_005789E0(idx, 30, 3, 1.1100293f, 0.005f, 0.2f, 0.0f);
}
/* localdecomp:end func_L39_00572FD0 */
