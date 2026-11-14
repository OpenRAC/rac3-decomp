#include "common.h"

/* localdecomp:start func_L16_00320F08 */
typedef struct {
    u8 pad0[0x20];
    u8 state;
    u8 pad21[0x30 - 0x21];
    u8 f30;
    u8 pad31[0x34 - 0x31];
    u16 flags;
    u8 pad36[0x68 - 0x36];
    s32 *pvar;
    u8 pad6c[0x98 - 0x6C];
    s32 f98;
} M_00320F08;
extern u8 D_00142CA5[];
extern u32 D_00142C50[];
extern u32 D_001A8B28[];
extern u32 D_001A85C4[];
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern u8 D_001A4C60[];
extern s32 D_L16_001D6694;
extern s32 D_L16_001E6EF0 __attribute__((section(".data")));
extern s16 *D_L16_0021D460[];
extern u8 *D_L16_001E015C;
__asm__(".extern D_L16_001E015C, 16");
extern s32 D_L16_001E0198;
extern s32 D_L16_001DFC40;
extern s32 D_001D4CF0;
extern void func_L01_0041A5B0(s32, s32);
extern s32 func_00382380(void *, s32, s32);
extern void func_L01_004AA7E8(void *, s32);
extern void func_L01_004B0EE0(void);

void func_L16_00320F08(M_00320F08 *a0) {
    s32 *v = a0->pvar;
    M_00320F08 *m;
    s16 *q;

    if (a0->state == 0) {
        a0->f30 = 0xFF;
        a0->state = 1;
    }
    if (a0->state != 1) {
        return;
    }
    if (D_00142CA5[0] != 0 && !(D_001A8B28[0] & (1 << D_001D545C))) {
        func_L01_0041A5B0(0x1428, 0x116);
    }
    if (func_00382380(D_001A4C60, v[0], 0) != 0 && !(D_001A85C4[0] & (1 << D_001D545C))) {
        func_L01_0041A5B0(0xCFC, 0xA3);
    }
    if (v[2] != -1) {
        if ((D_L16_001D6694 == 2 && D_L16_001E6EF0 == 3) || (D_00142C50[0] & 0x10000)) {
            q = D_L16_0021D460[v[2]];
            while ((v[2] & 0xFF) != 0xFF && v[2] <= D_L16_001E0198 && q != 0 && (q[-1] >= 0 || q == D_L16_0021D460[v[2]])) {
                m = (M_00320F08 *)(D_L16_001E015C + ((*(u16 *)q & 0x7FFF) << 8));
                if (m == 0) break;
                m->f98 = 0;
                m->flags = (m->flags | 0x41) & ~0x1000;
                func_L01_004AA7E8(m, 1);
                q++;
            }
        }
    }
    if (D_L16_001DFC40 < 0x1E && D_001D4CF0 == 0x1A) {
        func_L01_004B0EE0();
    }
}
/* localdecomp:end func_L16_00320F08 */
