#include "common.h"

/* NTSC-U counterpart of func_L39_006BD988 (src/levels/39_multiplayer_menu/L39_006BBB38.c) */
extern u8 *D_L39_0024D860;

/* localdecomp:start func_L39_006BAE70 */
__asm__(".extern D_L39_0024D860, 16");
extern u8 *D_L39_0024D860;
extern u8 D_001A5E50[];
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
s32 func_L39_006D95F0(void *, s32);
void func_L39_006D8470(void *);
s32 func_L39_006D9200(void *, s32, void *, void *);
void func_L04_0051FB50(void *);

void func_L39_006BAE70(u8 *arg0) {
    u8 *g = D_001A5E50;
    u8 *s1 = *(u8 **)(D_L39_0024D860 + 0x4C);
    u8 *s2 = *(u8 **)(D_L39_0024D860 + 0x70);

    if ((u32)(*(s32 *)(g + 0x7C) - 0x28) < 0x3C) {
        if (func_L39_006B90C8(arg0)) {
            if (*(s32 *)(arg0 + 0x318) == 0
                && (s32)func_00130760(func_0012DCB0(), 0x24000) - *(s32 *)(s1 + 0x1A0) >= 0x3A99
                && s1[0x199] == 0 && s2[0x1C] == 0 && s1[0x15D] == 0) {
                *(s32 *)(arg0 + 0x318) = 1;
                if (func_L39_006D95F0(s1, *(s32 *)(g + 0x7C))) {
                    func_L39_006D8470(s1);
                } else {
                    *(s32 *)(arg0 + 0x318) = 0;
                }
            } else if (s1[0x199] == 0 && *(s32 *)(arg0 + 0x318) != 0) {
                *(s32 *)(arg0 + 0x2F8) = func_L39_006D9200(s1, *(s32 *)(arg0 + 0x2A8), arg0 + 0x2FC, arg0 + 0x300);
                func_L04_0051FB50(s1);
                *(s32 *)(arg0 + 0x318) = 0;
            }
        }
    }
}
/* localdecomp:end func_L39_006BAE70 */
