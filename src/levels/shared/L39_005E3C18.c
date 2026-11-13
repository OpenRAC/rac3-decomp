#include "common.h"

/* declared by functions of L39_005E31D8.c, which this file was cut from */
extern s32 func_L01_00517688(void);
extern s32 *D_L39_00241120;

/* localdecomp:start func_L39_005E3C18 */
extern s32 func_L01_00517688(void);
extern s32 D_001D8318_sda[] __attribute__((section(".sdata")));
extern f32 D_001D832C_sda;
extern f32 D_001D8330_sda;
__asm__(".extern D_001D832C_sda, 4");
__asm__(".extern D_001D8330_sda, 4");
__asm__(".extern D_001D8318_sda, 4");
typedef struct {
    s32 id;
    s32 text;
    u8 pad[8];
} E_005E3C18;
extern E_005E3C18 D_L39_0049A0F8_005E3C18[];
extern s32 func_003E8EF0(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003E9138(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003B5060(s32);
extern s32 func_003E8AE8(s32, s32, s32, s32, s32, s32);
extern s32 func_003E8348(s32, s32);
extern s32 func_00381FF0(s32);
extern s32 func_003E8FE8(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_L01_00516AA0(s32, s32, s32);
extern s32 func_003E8630(s32, s32);
extern s32 func_L01_00516470(s32, f32, f32);
extern void func_L39_005E3F08(void);
extern void func_L39_005E40A8(void);
void func_L39_005E3C18(void) {
    s32 i;
    s32 j;
    f32 v;
    D_001D8318_sda[func_L01_00517688()] = 10;
    func_003E8EF0(0xD0000, 0x3D, 0x332299DE, 0.5f, 0.5f, 1.0f, 1.0f, 0.7f);
    func_003E8EF0(0xD0001, 0x3E, 0x332299DE, 0.5f, 0.5f, 1.0f, 1.0f, 0.7f);
    func_003E8EF0(0xD0002, 0x3F, 0x331465B7, 0.5f, 0.5f, 1.0f, 1.0f, 0.7f);
    func_003E8EF0(0xD0003, 0x40, 0x802299DE, 0.5f, 0.5f, 1.0f, 1.0f, 0.7f);
    func_003E9138(0xD0028, 0x402299DE, 0, 0.5f, 0.5f, 0.333333f, 0.025f);
    func_003B5060(0xD000B);
    func_003E8AE8(0xD000B, 0xD0000, 0xD0001, 0xD0002, 0xD0003, 0xD0028);
    func_003E8348(0x10, 0xD000B);
    func_003B5060(0xD0025);
    for (i = 0; i < 6; i++) {
        func_003E8FE8(D_L39_0049A0F8_005E3C18[i].id, func_00381FF0(D_L39_0049A0F8_005E3C18[i].text), 0x8066CCFF, 0.0f, 0.0f, 1.0f, 1.0f);
        func_L01_00516AA0(D_L39_0049A0F8_005E3C18[i].id, 0x2040, 1);
        func_003E8630(0xD0025, D_L39_0049A0F8_005E3C18[i].id);
    }
    func_003E8348(0x11, 0xD0025);
    v = D_001D832C_sda;
    for (j = 0; j < 3; j++) {
        func_L01_00516470(D_L39_0049A0F8_005E3C18[j].id, 0.5f, v);
        v += D_001D8330_sda;
    }
    func_L01_00516470(D_L39_0049A0F8_005E3C18[3].id, 0.5f, D_001D832C_sda);
    func_L01_00516470(D_L39_0049A0F8_005E3C18[4].id, 0.35f, D_001D832C_sda + D_001D8330_sda * 2);
    func_L01_00516470(D_L39_0049A0F8_005E3C18[5].id, 0.65f, D_001D832C_sda + D_001D8330_sda * 2);
    func_L39_005E3F08();
    func_L39_005E40A8();
}
/* localdecomp:end func_L39_005E3C18 */

/* localdecomp:start func_L39_005E3F08 */
__asm__(".extern D_001D8334_sda, 4");
__asm__(".extern D_001D8338_sda, 4");
__asm__(".extern D_001D833C_sda, 4");
__asm__(".extern D_001D8340_sda, 4");
__asm__(".extern D_001D8344_sda, 4");
__asm__(".extern D_001D8348_sda, 4");
__asm__(".extern D_001D834C_sda, 4");
__asm__(".extern D_001D8350_sda, 4");
__asm__(".extern D_001D8354_sda, 4");
__asm__(".extern D_001D8358_sda, 4");
__asm__(".extern D_001D8308_sda, 4");
__asm__(".extern D_L39_00241120, 16");
extern s32 *D_L39_00241120;
extern f32 D_001D8334_sda;
extern f32 D_001D8338_sda;
extern f32 D_001D833C_sda;
extern f32 D_001D8340_sda;
extern f32 D_001D8344_sda;
extern f32 D_001D8348_sda;
extern f32 D_001D834C_sda;
extern f32 D_001D8350_sda;
extern f32 D_001D8354_sda;
extern f32 D_001D8358_sda;
extern s32 D_001D8308_sda;
extern void func_L01_00517538(s32, f32, f32);
extern s32 func_L01_00517688(void);
extern s32 func_L01_00516470(s32, f32, f32);

void func_L39_005E3F08(void) {
    f32 a = 0.43f;
    f32 b = 0.05f;
    f32 c = 0.45f;
    f32 d = 0.077f;
    f32 e = 0.502f;
    s32 lvl = *D_L39_00241120;
    if (lvl >= 2) {
        if (lvl >= 3) {
            a = D_001D8334_sda;
            b = D_001D8338_sda;
            c = D_001D833C_sda;
            d = D_001D8340_sda;
            e = D_001D8344_sda;
        } else {
            a = D_001D8348_sda;
            b = D_001D834C_sda;
            c = D_001D8350_sda;
            d = D_001D8354_sda;
            e = D_001D8358_sda;
        }
    }
    func_L01_00517538(0xD0028, c, b);
    func_L01_00516470(0xD0028, e, a + (&D_001D8308_sda)[func_L01_00517688()] * d);
}
/* localdecomp:end func_L39_005E3F08 */
