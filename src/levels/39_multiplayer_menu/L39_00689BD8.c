#include "common.h"

/* declared by functions of L39_00689610.c, which this file was cut from */
extern s32 D_L39_003D2880[];
extern u8 D_001DC30A_sda;

/* localdecomp:start func_L39_00689BD8 */
extern s32 D_L39_003D2880[];
extern u8 D_L39_0024D7F0[8];
extern f32 D_001DC360_sda;
extern f32 D_001DC364_sda;
extern f32 D_001DC368_sda;
extern f32 D_001DC36C_sda;
__asm__(".extern D_001DC30A_sda, 1");
__asm__(".extern D_001DC360_sda, 4");
__asm__(".extern D_001DC364_sda, 4");
__asm__(".extern D_001DC368_sda, 4");
__asm__(".extern D_001DC36C_sda, 4");
extern s32 func_001206F4(void *, s32);
extern void func_L01_00516FD8();
extern s32 func_L01_00517538(s32, f32, f32);
extern void func_L39_00611628(s32, s32 *);
extern f32 func_003C4088(f32, f32, f32);
extern s32 func_L01_005169C8(s32, f32);
void func_L39_00689BD8(s32 a0, s32 a1) {
    f32 box[4];
    f32 w;
    f32 s;
    if (D_001DC30A_sda) {
        func_001206F4(D_L39_0024D7F0, a1);
        func_L01_00516FD8(D_L39_003D2880[0x30 / 4], D_L39_0024D7F0);
        func_L01_00517538(D_L39_003D2880[0x30 / 4], 1.2f, 1.2f);
        func_L39_00611628(D_L39_003D2880[0x30 / 4], (s32 *)box);
        w = box[2] - box[0];
        if (D_001DC368_sda < w) {
            f32 sc = D_001DC368_sda * 1.2f / w;
            func_L01_00517538(D_L39_003D2880[0x30 / 4], sc, sc);
            w = D_001DC368_sda;
        }
        s = func_003C4088(D_001DC364_sda, D_001DC36C_sda,
                          (w - D_001DC360_sda) / (D_001DC368_sda - D_001DC360_sda));
        if (D_001DC36C_sda < s) {
            s = D_001DC36C_sda;
        } else if (s < D_001DC364_sda) {
            s = D_001DC364_sda;
        }
        func_L01_005169C8(D_L39_003D2880[0x18 / 4], s);
        func_L01_005169C8(D_L39_003D2880[0x1C / 4], s);
        func_L01_005169C8(D_L39_003D2880[0x20 / 4], s);
        func_L01_005169C8(D_L39_003D2880[0x24 / 4], s);
    }
}
/* localdecomp:end func_L39_00689BD8 */
