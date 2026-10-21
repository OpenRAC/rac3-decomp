#include "common.h"

/* localdecomp:start func_L02_004C2D20 */
typedef int u128_4BEAD0 __attribute__((mode(TI)));
typedef struct {
    u8 p0[0x10];
    u128_4BEAD0 v10;
    u8 p20[0x14];
    u16 h34;
    u8 p36[0xA];
    u8 b40, b41, b42, b43;
    u8 p44[0x14];
    s32 w58;
    s32 w5C;
    u8 p60[0x3C];
    s32 w9C;
} M_4BEAD0;
typedef struct {
    u8 p0[0x80];
    u128_4BEAD0 q80;
    u8 p90[0xB64];
    M_4BEAD0 *wBF4;
    M_4BEAD0 *wBF8;
    s32 wBFC;
    u8 pC00[4];
    f32 fC04;
    u8 pC08[0x19B8];
    M_4BEAD0 *w25C0;
    s32 w25C4;
    u8 p25C8[0x1C];
    u8 b25E4;
} G_4BEAD0;
extern G_4BEAD0 D_001A4BE0;
extern s32 D_L02_001D6694;
extern u8 D_L02_0024F8C0[];
extern u8 D_L02_0024FEC0[];
extern void func_00393BE8();
extern void func_00393C40();
extern void func_00394620();
extern void func_L01_004E04E8(void);
extern void func_00393348(s32, s32, void *, void *, void *, s32, s32);
extern void func_L01_0041C828(s32);
extern void func_003C2880(s32);
extern void func_L01_004E1560(void);
extern void func_L01_0050FED0(void);
extern s32 func_L01_004DFCC8(M_4BEAD0 *, s32, s32, void *);
extern void func_L02_004D36C0(s32, s32);
void func_L02_004C2D20(void) {
    G_4BEAD0 *g;
    M_4BEAD0 *m;
    func_L01_004E04E8();
    g = &D_001A4BE0;
    g->b25E4 = 0;
    func_00393348(35, 0, func_00393BE8, func_00393C40, func_00394620, 0, 0);
    func_L01_0041C828(3);
    if (g->wBF4 != 0) {
        g->wBF4->h34 &= ~6;
    }
    g->wBF4 = 0;
    if (g->wBFC != 0) {
        func_003C2880(g->wBFC);
        g->wBFC = 0;
    }
    func_L01_004E1560();
    g->w25C0 = g->wBF8;
    g->w25C0->v10 = g->q80;
    g->w25C0->w9C = 0;
    g->fC04 = 1.0f;
    func_L01_0050FED0();
    m = g->w25C0;
    if (m->b42 != 0xFF) {
        g->w25C0->w58 = func_L01_004DFCC8(m, m->b42, m->b40, D_L02_0024F8C0);
    }
    m = g->w25C0;
    g->w25C0->w5C = func_L01_004DFCC8(m, m->b43, m->b41, D_L02_0024FEC0);
    if (g->w25C4 != 101 || (D_L02_001D6694 != 2 && D_L02_001D6694 != 6)) {
        func_L02_004D36C0(0, 1);
    }
}
/* localdecomp:end func_L02_004C2D20 */
