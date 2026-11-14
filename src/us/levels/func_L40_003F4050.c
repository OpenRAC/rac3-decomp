#include "common.h"

/* NTSC-U counterpart of func_L40_003F4510 (src/levels/shared/L40_003F4510.c) */
/* localdecomp:start func_L40_003F4050 */
typedef struct {
    s32 a;
    s32 b;
    s32 c;
} S_003F4510;

extern s32 D_001A5F78[];
extern u8 *D_L40_002485DC;
extern void func_00388440(void *, s32, s32);
extern u8 *func_L39_006699B0(void);
extern s32 func_L39_00669978(s32, s32, s32, s32, u8 *);
extern s32 func_00197588(s32);
extern s32 func_L40_0053B018(s32 id, s32 a1, s32 a2, s32 a3);
extern void func_L40_003F42F0();
extern void func_L40_003F37A0();
extern void func_L40_003F4178();

s32 func_L40_003F4050(u8 *m, S_003F4510 *a1) {
    u8 *v = *(u8 **)(m + 0x68);
    s32 saved;
    u8 *msg;
    u8 *p;
    s32 uid;

    m[0x20] = 0;
    *(s32 *)(v + 0x2A4) = 0;
    saved = *(s32 *)(v + 0x2AC);
    func_00388440(v + 0x1F0, 0, 0x10C);
    msg = func_L39_006699B0();
    if (msg == 0) {
        return -1;
    }
    uid = func_00197588(2);
    p = msg + func_L39_00669978(0, uid, D_001A5F78[0] + 500, 0x1A1B, msg);
    *(s32 *)p = (m - D_L40_002485DC) >> 8;
    p += 4;
    *(S_003F4510 *)p = *a1;
    p += 12;
    *(s32 *)msg = p - msg;
    *(s32 *)(v + 0x2A0) = 2;
    func_L40_0053B018(0x1A1B, (s32)func_L40_003F42F0, (s32)func_L40_003F37A0, (s32)func_L40_003F4178);
    *(s32 *)(v + 0x2AC) = saved;
    return uid;
}
/* localdecomp:end func_L40_003F4050 */
