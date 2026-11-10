#include "common.h"

/* declared by functions of L39_00688400.c, which this file was cut from */
extern s32 D_L39_003D2880[];
extern void func_L01_00516AA0();
extern u8 D_001DC30A_sda;
extern void func_L01_00516470(int);
void func_L01_00516AA0(s32);

/* localdecomp:start func_L39_00689D28 */
extern s32 D_L39_003D2880[];
extern u8 D_L39_0024D830[8];
extern f32 D_001DC330_sda;
__asm__(".extern D_001DC330_sda, 4");
__asm__(".extern D_001DC30A_sda, 1");
extern void func_00120D28();
extern void func_L01_00516FD8();
extern void func_L01_00518010();
extern void func_003E8898(s32, f32, f32);
void func_L39_00689D28(s32 a0, s32 a1) {
    if (D_001DC30A_sda) {
        func_00120D28(D_L39_0024D830, a1, 0x1F);
        D_L39_0024D830[0x1F] = 0;
        func_L01_00516FD8(D_L39_003D2880[0x34 / 4], D_L39_0024D830);
        ((void (*)(s32, f32, f32))func_L01_00516470)(D_L39_003D2880[0x34 / 4], D_001DC330_sda, 0.93f);
        func_L01_00518010(D_L39_003D2880[0x34 / 4], 1);
        func_003E8898(D_L39_003D2880[0x34 / 4], 0.24f, 0.0f);
    }
}
/* localdecomp:end func_L39_00689D28 */

/* localdecomp:start func_L39_00689DB8 */
extern s32 D_L39_003D2880[];
extern u8 D_L39_0024D850[8];
extern f32 D_001DC32C_sda;
extern void func_00120D28();
extern void func_L01_00516FD8();
extern void func_L01_00518010();
extern void func_003E8898(s32, f32, f32);
__asm__(".extern D_001DC32C_sda, 4");
__asm__(".extern D_001DC30A_sda, 1");
void func_L39_00689DB8(s32 a0, s32 a1) {
    if (D_001DC30A_sda) {
        func_00120D28(D_L39_0024D850, a1, 0x1F);
        D_L39_0024D850[0x1F] = 0;
        func_L01_00516FD8(D_L39_003D2880[0x38 / 4], D_L39_0024D850);
        ((void (*)(s32, s32, s32))func_L01_00516AA0)(D_L39_003D2880[0x38 / 4], 1, 1);
        ((void (*)(s32, f32, f32))func_L01_00516470)(D_L39_003D2880[0x38 / 4], D_001DC32C_sda, 0.93f);
        func_L01_00518010(D_L39_003D2880[0x38 / 4], 1);
        func_003E8898(D_L39_003D2880[0x38 / 4], 0.24f, 0.0f);
    }
}
/* localdecomp:end func_L39_00689DB8 */

/* localdecomp:start func_L39_00689E58 */
extern s32 D_L39_003D2880[];
extern u8 D_L39_0024D870[8];
extern void func_00120D28();
extern void func_L01_00516FD8();
extern void func_L01_00518010();
extern void func_L01_005170B8(s32, s32);
extern void func_003E8898(s32, f32, f32);
__asm__(".extern D_001DC30A_sda, 1");
void func_L39_00689E58(s32 a0, s32 a1, s32 a2) {
    if (D_001DC30A_sda) {
        func_00120D28(D_L39_0024D870, a1, 0x3F);
        D_L39_0024D870[0x3F] = 0;
        ((void (*)(s32, s32, s32))func_L01_00516AA0)(D_L39_003D2880[0x3C / 4], 1, 1);
        func_L01_00516FD8(D_L39_003D2880[0x3C / 4], D_L39_0024D870);
        func_L01_005170B8(D_L39_003D2880[0x3C / 4], a2);
        func_L01_00518010(D_L39_003D2880[0x3C / 4], 1);
        func_003E8898(D_L39_003D2880[0x3C / 4], 0.37f, 0.0f);
    }
}
/* localdecomp:end func_L39_00689E58 */
