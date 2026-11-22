#include "common.h"

/* NTSC-U counterpart of PAL func_L07_003B3160. */
/* localdecomp:start func_L07_003B18A0 */
typedef struct { u8 b[16]; } Hit_003B18A0;
extern u8 D_L07_001D66B0[] __attribute__((section(".sdata")));
extern void func_L01_004538E0(void *, s32);
extern void func_L01_004539A8(void *, f32, f32, f32, s32, s32, s32, s32, s32,
                              s32, s32, s32, s32);
extern s32 func_0037E1D8(s32);
extern s32 func_L07_003A0BC0(u8, s32, u8, s16);
extern s32 func_003883C8(void *);
extern s32 func_L01_00444358(void *, s32, s32);
extern f32 func_L01_004443B0(void *, s32);
extern void func_0039FE80(s32, s32, void *);
extern void func_L01_004568F8(void *, s32, f32);
extern void func_003BF4F8(void *, void *);
extern void func_L01_004479A8(void *, void *);
extern void func_L01_0044B598(void *, s32);
extern void func_L01_00456960(s32);
extern void func_L01_00438908(void *, s32, s32, s32);
extern void func_L01_0044ED60(void *, s32, void *, f32, f32, f32, f32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32);
extern void func_L07_003A0C90(void);
extern void func_L07_00330E70(void *);
extern s32 func_L07_003335E0(s32);
extern void func_L07_003B3508(u8 *);
extern void func_L02_003F84F0(s32, s32, f32);
extern void func_L07_003B2DF8(u8 *);

void func_L07_003B18A0(u8 *m) {
    u8 *p = *(u8 **)(m + 0x68);
    Hit_003B18A0 saved;
    f32 amount, previous;
    s32 hit;

    if (m[0x20] == 1) return;
    hit = func_L01_00444358(m, -1, 0);
    amount = func_L01_004443B0(m, hit);
    m[0xA8] = 255;
    if ((*(u16 *)(m + 0x34) & 0x4000) && amount > 0.0f) {
        func_0039FE80(7, 0, m);
        previous = *(f32 *)(p + 0x30);
        *(f32 *)(p + 0x30) = previous - amount;
        func_L01_004568F8(m, p[0x47], amount);
        p[0x77] = 255;
        if (p[0x47] != 9 && p[0x47] != 25) p[0x676] = 0;
        func_003BF4F8(m, p + 0x70);
        if (*(f32 *)(p + 0x30) < previous - (f32)*(s16 *)(p + 0x34) * 0.1f && *(s16 *)(p + 0x670) == 0) {
            func_L07_003A0BC0(20, (s32)m, 0, 120);
            *(s16 *)(p + 0x670) = func_0037E1D8(150) + 300;
        }
    }
    func_L01_004479A8(m, p + 0x70);
    if (*(s16 *)(p + 0x70) == 0) func_L01_0044B598(m, *(s32 *)(p + 0x67C));
    if (*(f32 *)(p + 0x30) <= 0.0f) {
        if (p[0x676]) func_L01_00456960(8);
        saved = *(Hit_003B18A0 *)(p + 0x70);
        func_L01_00438908(m, saved.b[4], saved.b[5], saved.b[6]);
        func_L01_0044ED60(m, 0x3FFF, D_L07_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f,
                          255, 180, 0, 0, 35, 0, 3);
        func_L07_003A0C90();
        func_L07_003A0BC0(81, (s32)m, 0, 120);
        func_L07_00330E70(m);
    } else if (p[0x5E]) {
        func_L07_00330E70(m);
        p[0x5E] = 0;
    } else if (p[0x60]) {
        func_L07_00330E70(m);
        p[0x60] = 0;
    } else {
        func_L01_004538E0(m, 3);
        hit = func_L07_003335E0(*(s32 *)(p + 0x190));
        ((s32 (*)(void *, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32))func_L01_004539A8)(
            m, 0.0f, 0.0f, 1.0f, hit, 0, 0, 0, 0, 1, 0, 0, 0);
        func_L07_003B3508(m);
        func_L02_003F84F0(6, 0, *(f32 *)(p + 0x30) / (f32)*(s16 *)(p + 0x34));
        func_L07_003B2DF8(m);
        func_003883C8(p + 0x66C);
        func_003883C8(p + 0x66E);
        func_003883C8(p + 0x670);
    }
}
/* localdecomp:end func_L07_003B18A0 */
