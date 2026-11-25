#include "common.h"

/* localdecomp:start func_U_L03_003A0F70 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003A0F70;
typedef struct { u8 pad[0x68]; f32 *p68; } S_003A0F70;
typedef struct { u8 pad[0xE0]; V4_003A0F70 v; } A_003A0F70;
typedef struct { u8 pad0[0x25C0]; void *q; } H_003A0F70;
typedef struct { u8 pad[0xD4]; u8 *p; } G_003A0F70;
extern H_003A0F70 D_001A4BE0;
extern G_003A0F70 D_L03_0021F318;
extern u8 D_L03_002A14A0[];
__asm__(".extern D_001A4BE0, 16");
__asm__(".extern D_L03_0021F318, 16");
__asm__(".extern D_L03_002A14A0, 16");
void func_U_003CCEB8(f32, void *, void *, void *, s32);
void func_U_003F9310(V4_003A0F70 *, V4_003A0F70 *, f32);
f32 func_U_0042DC48(f32, f32);
f32 func_U_0042DBF0(f32, f32);
s32 func_U_0042DBA8(s32, s32);
u8 *func_U_0045B438(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);

void func_U_L03_003A0F70(void *a0, void *b0) {
    A_003A0F70 *a = a0;
    s32 *b = b0;
    char buf[0x10];
    V4_003A0F70 vec;
    f32 *p = *(f32 **)((u8 *)a + 0x68);
    s32 i;
    for (i = 0; i < 24; i++) {
        s32 h;
        f32 f;
        u8 *r;
        func_U_003CCEB8(0.0f, D_001A4BE0.q, D_L03_002A14A0, buf, 0);
        vec = a->v;
        func_U_003F9310(&vec, &vec, p[4] * 0.033333335f);
        h = (s32)func_U_0042DC48(2.0f, 5.0f);
        f = func_U_0042DBF0(0.05f, 0.1f);
        r = func_U_0045B438(buf, &vec, (s32)((f32)(func_U_0042DBA8(20, 25)) * p[4]), b[0], h, 0x7F, 0x7F, f * 210000.0f, 2100.0f, -0.00083333335f, 1);
        h = -(h * 2);
        r = func_U_0045B438(buf, &vec, (s32)((f32)(func_U_0042DBA8(20, 25)) * p[4]), b[1], h, 0x30, 0x30, (f *= 4.0f) * 210000.0f, 4200.0f, -0.00083333335f, 0);
        if (r) r[2] = *D_L03_0021F318.p;
    }
    p[4] = p[4] + 0.029166669f;
    if (p[4] > 1.0f) p[4] = 1.0f;
}
/* localdecomp:end func_U_L03_003A0F70 */
