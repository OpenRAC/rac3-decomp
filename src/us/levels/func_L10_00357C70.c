#include "common.h"

/* NTSC-U counterpart of func_L10_00358F48 (src/levels/10_zeldrin_starport/L10_003587D8.c): 0.036 -> 0.03 */
/* localdecomp:start func_L10_00357C70 */
typedef struct {
    s32 mode;
    f32 height;
    s32 trigger;
    s32 trigger2;
    s32 pad10;
    s32 sound;
} S_358F48;
extern u8 D_001A4C60[];
extern u8 D_001A30B0[];
extern void func_L10_00357ED8(void *);
extern int func_L10_00357F20(char *);
extern s32 func_0037E0F0(void *, s32, s32);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_0039FB08(s32);

void func_L10_00357C70(u8 *m) {
    S_358F48 *v = *(S_358F48 **)(m + 0x68);
    u8 *e;
    s32 h;
    f32 f;

    func_L10_00357ED8(m);
    switch (m[0x20]) {
    case 1:
        if (v->trigger != -1 && func_0037E0F0(D_001A4C60, v->trigger, 0) != 0) {
            m[0x20] = 2;
            v->sound = func_0039FE80(0, 4, m);
        }
        break;
    case 2:
        *(f32 *)(m + 0x18) += 0.0299999993f;
        if (v->height <= *(f32 *)(m + 0x18)) {
            h = v->sound;
            if (h != -1) {
                e = D_001A30B0 + (h << 7);
                if (*(u8 **)(e + 0xDC) == m && e[0xD0] != 0) {
                    func_0039FB08(h);
                }
            }
            v->sound = -1;
            *(f32 *)(m + 0x18) = v->height;
            if (v->mode == 1 && func_L10_00357F20((char *)m) == 0) {
                m[0x20] = 3;
            } else {
                m[0x20] = 6;
            }
        }
        break;
    case 3:
        if (v->trigger2 != -1 && func_0037E0F0(D_001A4C60, v->trigger2, 0) != 0) {
            m[0x20] = 4;
            v->sound = func_0039FE80(0, 4, m);
        }
        break;
    case 4:
        if (func_0037E0F0(D_001A4C60, v->trigger, 0) != 0) {
            m[0x20] = 2;
            break;
        }
        *(f32 *)(m + 0x18) -= 0.0299999993f;
        if (*(f32 *)(m + 0x18) <= v->height - 5.0f) {
            h = v->sound;
            if (h != -1) {
                e = D_001A30B0 + (h << 7);
                if (*(u8 **)(e + 0xDC) == m && e[0xD0] != 0) {
                    func_0039FB08(h);
                }
            }
            f = v->height - 5.0f;
            v->sound = -1;
            m[0x20] = 5;
            *(f32 *)(m + 0x18) = f;
        }
        break;
    case 5:
        if (func_L10_00357F20((char *)m) != 0 || func_0037E0F0(D_001A4C60, v->trigger, 0) != 0) {
            m[0x20] = 2;
            v->sound = func_0039FE80(0, 4, m);
        }
        break;
    case 6:
        *(u16 *)(m + 0x34) |= 2;
        break;
    }
}
/* localdecomp:end func_L10_00357C70 */
