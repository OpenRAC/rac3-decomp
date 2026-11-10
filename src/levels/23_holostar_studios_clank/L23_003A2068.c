#include "common.h"

INCLUDE_ASM("asm/levels", func_L23_003A2068);

INCLUDE_ASM("asm/levels", func_L23_003A2A08);

/* localdecomp:start func_L23_003A2E78 */
extern u8 *D_L23_001DF15C;
__asm__(".extern D_L23_001DF15C, 16");
extern s32 D_001DBD14;
__asm__(".extern D_001DBD14, 16");
extern void func_L23_004CF590(s32, s32, void *);
extern void func_L01_004F50C8(void *a, void *b, s32 c, s32 d);

void func_L23_003A2E78(u8 *a0) {
    s32 *p = *(s32 **)(a0 + 0x68);
    u8 *e;

    func_L23_004CF590(1, 0x3F, D_L23_001DF15C + (*p << 8));
    e = D_L23_001DF15C + (*p << 8);
    func_L01_004F50C8(e + 0x10, e + 0xF0, -1, 1);
    D_001DBD14 = 1;
}
/* localdecomp:end func_L23_003A2E78 */

/* localdecomp:start func_L23_003A2EF0 */
extern s32 func_L01_0047B3D8(void);
extern void func_L01_004CB540(u8);
extern void func_L23_004CF590(s32, s32, void *);
extern void func_L01_004F50C8(void *, void *, s32, s32);
extern u8 *D_L23_001DF15C;
__asm__(".extern D_L23_001DF15C, 16");

void func_L23_003A2EF0(u8 *self)
{
    u8 *s = *(u8 **)(self + 0x68);
    u8 *e;

    func_L01_0047B3D8();
    func_L01_004CB540(1);
    func_L23_004CF590(2, 0x5A, D_L23_001DF15C + (*(s32 *)(s + 4) << 8));
    e = D_L23_001DF15C + (*(s32 *)(s + 4) << 8);
    func_L01_004F50C8(e + 0x10, e + 0xF0, -1, 1);
}
/* localdecomp:end func_L23_003A2EF0 */

/* localdecomp:start func_L23_003A2F68 */
void func_L23_004E3428(s32, s32);
extern s32 D_001A71A4[];

void func_L23_003A2F68(void *arg0, s32 arg1) {
    void *temp_s0;

    temp_s0 = *(void **)((u8 *)arg0 + 0x68);
    if (D_001A71A4[0] != 0x74) {
        func_L23_004E3428(0x74, 1);
    }
    *(s32 *)((u8 *)temp_s0 + 0x64) = arg1;
}
/* localdecomp:end func_L23_003A2F68 */

/* localdecomp:start func_L23_003A2FB8 */
void func_L23_003A2FB8(void *arg0) {
    void *temp_s0;

    temp_s0 = *(void **)((u8 *)arg0 + 0x68);
    if (D_001A71A4[0] == 0x74) {
        if (*(u8 *)((u8 *)arg0 + 0x95) == 1) {
            func_L23_004E3428(0x3F, 1);
        } else {
            func_L23_004E3428(0x5A, 1);
        }
    }
    *(s32 *)((u8 *)temp_s0 + 0x64) = 0;
}
/* localdecomp:end func_L23_003A2FB8 */

INCLUDE_ASM("asm/levels", func_L23_003A3020);

INCLUDE_ASM("asm/levels", func_L23_003A31D8);

/* localdecomp:start func_L23_003A3860 */
void func_0038CAD0(s32);
void func_L23_003A2FB8(void *);
extern s32 D_001A71A4[];

void func_L23_003A3860(void *arg0) {
    u8 *temp_s1;

    temp_s1 = *(u8 **)((u8 *)arg0 + 0x68);
    *(u16 *)((u8 *)arg0 + 0x96) += 1;
    func_0038CAD0((s32)(temp_s1 + 0x64));
    if (D_001A71A4[0] == 0x74 && *(s32 *)(temp_s1 + 0x64) <= 0) {
        func_L23_003A2FB8(arg0);
    }
}
/* localdecomp:end func_L23_003A3860 */

INCLUDE_ASM("asm/levels", func_L23_003A38C8);

/* localdecomp:start func_L23_003A3FC8 */
s32 func_L01_00516AA0(s32, s32, s32);

void func_L23_003A3FC8(s32 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_L01_00516AA0(0x730000, 1, 1);
        return;
    }
    func_L01_00516AA0(0x730000, 1, 0);
}
/* localdecomp:end func_L23_003A3FC8 */

INCLUDE_ASM("asm/levels", func_L23_003A4008);
