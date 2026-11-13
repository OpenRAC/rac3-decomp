#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L03_003CFCA0 */
extern s32 func_L01_00447490(u8 *, s32, s32);
extern void func_L03_003D02A0(u8 *, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32);
void func_L03_003CFCA0(u8 *a0) {
    if (func_L01_00447490(a0, -1, 0)) {
        func_L03_003D02A0(a0, 7, 0, 7825, 1, 1, 1, 0, 0x80C08020, 0.0f, 0.2f);
    }
}
/* localdecomp:end func_L03_003CFCA0 */

/* localdecomp:start func_L03_003CFD10 */
extern s32 func_L01_00447490(u8 *, s32, s32);
extern void func_L03_003D02A0(u8 *, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32);
void func_L03_003CFD10(u8 *a0) {
    if (func_L01_00447490(a0, -1, 0)) {
        func_L03_003D02A0(a0, 7, 0, 7832, 0, 1, 1, 0, 0xC050C020, 0.0f, 1.5f);
    }
}
/* localdecomp:end func_L03_003CFD10 */

/* localdecomp:start func_L03_003CFD80 */
extern void func_003A4F28(s32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern s32 func_00382468(s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_003C4C18(void *, f32);
extern void func_L01_004637C8(void *, void *, u32, u32, s32, s32, s32, s32);
extern u8 D_001A30B0[];

void func_L03_003CFD80(u8 *a0) {
    vu0_v4 vel;
    vu0_v4 pos;
    vu0_v4 off;
    s32 *pv = *(s32 **)(a0 + 0x68);
    s32 r;
    u8 *e;
    if (a0[0x20] != 0) {
        return;
    }
    (*(u16 *)(a0 + 0x96))++;
    if (*(u16 *)(a0 + 0x96) >= 0xFB) {
        if (*pv != -1) {
            e = D_001A30B0 + (*pv << 7);
            if (*(u8 **)(e + 0xDC) == a0 && e[0xD0] != 0) {
                func_003A4F28(*pv);
            }
        }
        *pv = -1;
        func_L01_004450F0(a0, 1, -1);
        return;
    }
    if (*pv == -1 || (e = D_001A30B0 + (*pv << 7), *(u8 **)(e + 0xDC) != a0) || e[0xD0] == 0) {
        *pv = func_003A52A0(0, 4, a0);
    }
    r = func_00382468(30);
    *(vu0_q *)&pos = *(vu0_q *)(a0 + 0x10);
    func_0038CF68(&off, a0 + 0xC0, -0.3f);
    vec_add_ab(&pos, &pos, &off);
    pos.z += 0.9f;
    qzero(&vel);
    func_0038CF68(&vel, a0 + 0xC0, -0.030000001f);
    func_003C4C18(&vel, 0.014f);
    vel.z += 0.040000003f;
    func_L01_004637C8(&pos, &vel, 0x80808080, 0x202020, 0x2A, r + 0x1E, r + 0x5A, 1);
}
/* localdecomp:end func_L03_003CFD80 */

/* localdecomp:start func_L03_003CFF40 */
extern s32 func_L01_00447490(u8 *, s32, s32);
extern void func_L03_003D02A0(u8 *, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32);
void func_L03_003CFF40(u8 *a0) {
    if (func_L01_00447490(a0, -1, 0)) {
        func_L03_003D02A0(a0, 7, 0, 7834, 1, 1, 1, 0, 0xC050C020, 0.0f, 1.0f);
    }
}
/* localdecomp:end func_L03_003CFF40 */
