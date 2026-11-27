#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void func_003C36C0(void);
extern void func_003C3638(void);
extern void func_003C3660(void);
extern void func_003C3690(void);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003C3638 */
extern void func_0038CB78();
 
void func_003C3638(void) {
    func_0038CB78(0x70003A00, 0x40000000, 0x3C0);
}
/* localdecomp:end func_003C3638 */

/* localdecomp:start func_003C3660 */
extern void func_0038CD28();
extern u8 D_002DA380[];
 
void func_003C3660(void) {
    func_0038CD28((s32)D_002DA380, 0x70003A00, 0x3C0);
}
/* localdecomp:end func_003C3660 */

/* localdecomp:start func_003C3690 */
extern void func_0038CD28();
 extern u8 D_002DA380[];

void func_003C3690(void) {
    func_0038CD28(0x70003A00, (s32)D_002DA380, 0x3C0);
}
/* localdecomp:end func_003C3690 */

extern void func_003A8F90(void *);
extern u8 D_002FC1A0[];
extern void func_003A9338();
extern void func_003A9440(s32, unsigned long);
extern u8 D_00110790[];
extern u8 D_00100080[];
extern u16 D_00110780[];
extern s32 D_001D9D1C_003C36C0;
extern s32 D_001DA050_003C36C0;
extern s32 D_001D9D38_003C36C0;
extern s32 D_001D9D30_003C36C0;
extern s32 D_001DA490_003C36C0;
extern u8 *D_001DA530_003C36C0;
extern s32 D_001DA054_003C36C0;
extern s32 D_001DA498_003C36C0;
extern s32 D_001DA4E4_003C36C0;
/* localdecomp:start func_003C36C0 */
__asm__(".extern D_001D9D1C_003C36C0, 16");
__asm__(".extern D_001DA050_003C36C0, 16");
__asm__(".extern D_001D9D38_003C36C0, 16");
__asm__(".extern D_001D9D30_003C36C0, 16");
__asm__(".extern D_001DA490_003C36C0, 16");
__asm__(".extern D_001DA530_003C36C0, 16");
__asm__(".extern D_001DA054_003C36C0, 16");
__asm__(".extern D_001DA498_003C36C0, 16");
__asm__(".extern D_001DA4E4_003C36C0, 16");
__asm__(".extern D_001D4BB4_003C36C0, 16");
__asm__(".extern D_001D4BB0_003C36C0, 16");
extern s32 D_001D4BB4_003C36C0;
extern s32 D_001D4BB0_003C36C0;

void func_003C36C0(void) {
    s32 a, b, c, d;
    func_003A9338(D_00110790, D_00110780[0]);
    D_001D9D1C_003C36C0 = 6;
    func_003A8F90(D_00100080);
    func_003A9440(0x47, 0x5360B);
    a = D_001DA050_003C36C0;
    b = D_001D9D38_003C36C0;
    c = D_001D4BB4_003C36C0;
    D_001DA490_003C36C0 = a;
    d = D_001D9D30_003C36C0;
    D_001D4BB0_003C36C0 = c;
    a += 0x10;
    D_001DA050_003C36C0 = a;
    D_001DA530_003C36C0 = D_002FC1A0;
    D_001DA054_003C36C0 = b + 0xFFFF0000;
    D_001DA498_003C36C0 = d;
    D_001DA4E4_003C36C0 = 0;
}
/* localdecomp:end func_003C36C0 */
