/* functional: high. Near-exact draft (instruction order / sdata addressing only differ from retail), callees and constants checked by the byte compare against PAL. */
#include "vu0.h"

extern s32 D_L40_0024112C[] __attribute__((section(".sdata")));
/* localdecomp:start func_L40_0040D678 */
extern u8 *func_L01_0045B958(u8 *m);
extern void func_L01_0045B908(u8 *m, u8 *w);
extern void func_L01_0045B6C8(u8 *m, u8 *w, f32 f);
extern void func_L01_0045AF28(u8 *m, u8 *w);
extern void func_L01_0045B110(u8 *m, u8 *w, void *target);
extern void func_L01_0045BB60(u8 *m, u8 *w, f32 yaw);
extern void func_L01_0045C240(void);
extern void func_L40_0040D7D0(u8 *m, u8 *w, void *target, f32 yaw, vu0_v4 *a, vu0_v4 *b);

/* One walk step towards `target`: the moby's walker (once a frame), then the walk itself. */
s32 func_L40_0040D678(u8 *m, void *target, f32 yaw) {
    u8 *w;
    s32 last;
    vu0_v4 old;
    vu0_v4 a;
    vu0_v4 b;

    w = func_L01_0045B958(m);
    if (w == 0) {
        return 8;
    }
    if (D_L40_0024112C[0] == *(s32 *)(w + 0xBC)) {
        return *(s32 *)(w + 0x94);
    }
    *(s32 *)(w + 0x98) = *(s32 *)(w + 0x94);
    *(s32 *)(w + 0x94) = 0;
    if (!(*(s32 *)(w + 0x38) & 0x100)) {
        func_L01_0045B908(m, w);
    }
    old = *(vu0_v4 *)(m + 0x10);
    last = *(s32 *)(w + 0xBC);
    if (D_L40_0024112C[0] - last >= 2 || last == 0) {
        func_L01_0045B6C8(m, w, 0.0f);
        *(f32 *)(w + 0xB4) = 0.0f;
        *(u8 *)(w + 0xEA) = 0xFF;
        *(s32 *)(w + 0x9C) &= ~2;
        qzero(w + 0xA0);
        *(s32 *)(w + 0x80) = 0;
    }
    *(s32 *)(w + 0xBC) = D_L40_0024112C[0];
    func_L40_0040D7D0(m, w, target, yaw, &a, &b);
    func_L01_0045AF28(m, w);
    func_L01_0045B110(m, w, target);
    func_L01_0045BB60(m, w, yaw);
    func_L01_0045C240();
    return *(s32 *)(w + 0x94);
}
/* localdecomp:end func_L40_0040D678 */
