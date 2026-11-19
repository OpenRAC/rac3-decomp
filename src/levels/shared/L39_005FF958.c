#include "common.h"

/* localdecomp:start func_L39_005FF958 */
extern s32 D_L39_00241128;
extern s32 D_001D4CEC_sda;
extern u8 *D_L39_0024BF68;
extern u8 D_L39_0024BF6C[];
extern u8 D_L39_0024CB4D;
extern s32 D_L39_0024C190;
extern u8 *D_L39_0024C188;
extern void func_00392260(s32, s32, s32);
extern s32 func_L39_005BF798(s32, s32, s32, s32, s32);
extern s32 func_L02_004E49E8_005FF958(void);
extern void func_L39_005FBDD8(void);
extern void func_L39_005F1718(void);
extern u8 *func_L39_005ACB68(void *);
extern void func_003C7C38(void *);
extern void func_003C6FE0(void *);
extern void func_L39_0057B1C0(void);
extern void func_L01_0048F4D8_005FF958(void);
extern void func_L01_0046FD18(void *);
extern void func_L39_005FBE08(void);

/* from func_L01_004CA928 (src/levels/shared/L01_004C6618.c), the single-player levels' copy */
void func_L39_005FF958(void) {
    u8 *p;
    s32 i;
    func_00392260(0, 0, 0);
    if (D_L39_00241128 == 0 && (D_001D4CEC_sda & 1)) {
        if (func_L39_005BF798(4, 1, 1, 0, 0) == 0) return;
    }
    if (func_L02_004E49E8_005FF958() != 0) return;
    func_L39_005FBDD8();
    func_L39_005F1718();
    p = D_L39_0024BF68 = func_L39_005ACB68(D_L39_0024BF6C);
    while (p != 0) {
        if (*(s8 *)(p + 0x20) >= 0) {
            if (*(s16 *)(p + 0xAA) == 0xDC1) {
                (*(void (**)(void *))(p + 0x64))(p);
                if (!(*(u16 *)(p + 0x34) & 4)) func_003C7C38(p);
            } else if (*(s16 *)(p + 0xAA) == 0xCB2 || *(s16 *)(p + 0xAA) == 0xB02 ||
                       *(s16 *)(p + 0xAA) == 0x259 || *(s16 *)(p + 0xAA) == 0xA5C ||
                       *(s16 *)(p + 0xAA) == 0x1192) {
                func_003C6FE0(p);
                func_003C7C38(p);
            }
        }
        p = *(u8 **)(p + 0x28);
    }
    if (D_L39_0024CB4D) func_L39_0057B1C0();
    func_L01_0048F4D8_005FF958();
    for (i = 0; i <= D_L39_0024C190; i++) {
        u8 *e = D_L39_0024C188 + (i << 6);
        if ((*(long *)e & 0x80FF) == 0xFF) func_L01_0046FD18(e);
    }
    func_L39_005FBE08();
}
/* localdecomp:end func_L39_005FF958 */
