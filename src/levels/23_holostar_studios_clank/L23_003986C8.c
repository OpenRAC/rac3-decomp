#include "common.h"
typedef struct { u8 pad[0x18]; u8 *f18; } S_3986C8;

/* localdecomp:start func_L23_003986C8 */
__asm__(".extern D_001D545C, 4");
extern u8 D_001BBC40[];
__asm__(".extern D_001D5570, 16");
extern u8 D_001D5570[8];
extern u8 D_001A4BE0[];
extern S_3986C8 D_L23_001E8780;
extern s32 D_001D545C;
extern s32 func_L01_003FB640(void *, s32, u8 *, f32);
extern void func_L01_0043B510(s32);
extern void func_L01_004A3610(u8 *, u8 *);
extern u8 *func_L01_0045B958(u8 *);
s32 func_L23_003986C8(u8 *self) {
    u8 *st = *(u8 **)(self + 0x68);
    u8 *h1; u8 *h2; S_3986C8 *g1; S_3986C8 *g2;
    u8 *p;
    s32 id;
    if (*(s32 *)(st + 0x20) != 0) {
        if (D_001BBC40[self[0xB0] + (D_001D545C << 4)] & 0x80) return 1;
    }
    if (*(s32 *)(st + 0x30) != 0) {
        if (D_001D5570[*(s32 *)(st + 0x30)] != 0) return 1;
    }
    h1 = D_001A4BE0;
    if (*(u8 **)(h1 + 0x35C) == self) {
        if (*(s32 *)(h1 + 0x360) >= 2) return 1;
    }
    if (func_L01_003FB640(self + 0x10, 1, self, *(f32 *)(self + 0x2C) * 1.1f / *(f32 *)(*(u8 **)(self + 0x24) + 0x24)) != 0) {
        g1 = &D_L23_001E8780;
        if (g1->f18 != 0) {
            h2 = D_001A4BE0;
            if (g1->f18 == *(u8 **)(h2 + 0x25C0) && *(u8 **)(h2 + 0x35C) == self) {
                if (*(s32 *)(st + 0x20) != 0) {
                    func_L01_0043B510(self[0xB0]);
                    func_L01_004A3610(h2 + 0x80, h2 + 0x90);
                }
                return 1;
            }
            g2 = &D_L23_001E8780;
            if (*(u16 *)(g2->f18 + 0x34) & 0x20) {
                p = func_L01_0045B958(g2->f18);
                if (p != 0 && (*(u8 **)(p + 0x88) == self || *(u8 **)(p + 0x84) == self)) {
                    id = *(s16 *)(g2->f18 + 0xAA);
                    if (id == 0x1A4E || id == 0x1AA0 || id == 0x1BD3 || id == 0x16BE || id == 0x1BA0) return 1;
                }
            }
        }
    }
    return 0;
}
/* localdecomp:end func_L23_003986C8 */
