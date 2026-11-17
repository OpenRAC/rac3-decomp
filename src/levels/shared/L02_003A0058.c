#include "common.h"

typedef struct {
    u8 pad0[16];
    s32 unk10;
} C39E3B8;
typedef struct {
    u8 pad0[220];
    s32 unkDC;
} V39E3B8;
typedef struct {
    u8 pad0[36];
    C39E3B8 *unk24;
    u8 pad28[52 - 40];
    u16 unk34;
    u8 pad36[104 - 54];
    V39E3B8 *pVars;
    u8 pad6C[152 - 108];
    s32 unk98;
    u8 pad9C[256 - 156];
} M39E3B8;

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
} V_003A0200;
typedef struct {
    u8 pad0[0x24];
    f32 f24;
} C_003A0200;
typedef struct {
    u8 pad0[0x36];
    s16 f36;
    u8 pad38[0x100 - 0x38];
} M_003A0200;
typedef struct {
    u8 pad0[0x24];
    C_003A0200 *f24;
    u8 pad28[4];
    f32 f2C;
    u8 pad30[0x43 - 0x30];
    u8 f43;
    u8 pad44[0x68 - 0x44];
    V_003A0200 *f68;
} O_003A0200;

/* localdecomp:start func_L02_003A0058 */
typedef int Q_003A0058 __attribute__((mode(TI)));
extern M39E3B8 *D_L02_001DE99C[];
extern void func_0038CF68(void *, void *, f32);

void func_L02_003A0058(u8 *src, s32 idx, f32 x0, f32 x1, f32 y0, f32 y1, f32 z0, f32 z1, f32 t) {
    u8 *m = (u8 *)&D_L02_001DE99C[0][idx];
    f32 x;
    f32 y;
    f32 z;

    x = x0 + (x1 - x0) * t;
    func_0038CF68(m + 0xC0, m + 0xC0, x);
    func_0038CF68(m + 0xD0, m + 0xD0, x);
    y = y0 + (y1 - y0) * t;
    func_0038CF68(m + 0xE0, m + 0xE0, y);
    z = z0 + (z1 - z0) * t;
    *(Q_003A0058 *)(m + 0x10) = *(Q_003A0058 *)(src + 0x10);
    *(f32 *)(m + 0x18) += z - y * 0.55f;
}
/* localdecomp:end func_L02_003A0058 */
