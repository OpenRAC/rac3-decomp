#include "common.h"

INCLUDE_ASM("asm/levels", func_L10_003587D8);

/* localdecomp:start func_L10_00358F48 */
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
extern void func_L10_003591B0(void *);
extern int func_L10_003591F8(char *);
extern s32 func_00382380(void *, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003A4F28(s32);

void func_L10_00358F48(u8 *m) {
    S_358F48 *v = *(S_358F48 **)(m + 0x68);
    u8 *e;
    s32 h;
    f32 f;

    func_L10_003591B0(m);
    switch (m[0x20]) {
    case 1:
        if (v->trigger != -1 && func_00382380(D_001A4C60, v->trigger, 0) != 0) {
            m[0x20] = 2;
            v->sound = func_003A52A0(0, 4, m);
        }
        break;
    case 2:
        *(f32 *)(m + 0x18) += 0.036000002f;
        if (v->height <= *(f32 *)(m + 0x18)) {
            h = v->sound;
            if (h != -1) {
                e = D_001A30B0 + (h << 7);
                if (*(u8 **)(e + 0xDC) == m && e[0xD0] != 0) {
                    func_003A4F28(h);
                }
            }
            v->sound = -1;
            *(f32 *)(m + 0x18) = v->height;
            if (v->mode == 1 && func_L10_003591F8((char *)m) == 0) {
                m[0x20] = 3;
            } else {
                m[0x20] = 6;
            }
        }
        break;
    case 3:
        if (v->trigger2 != -1 && func_00382380(D_001A4C60, v->trigger2, 0) != 0) {
            m[0x20] = 4;
            v->sound = func_003A52A0(0, 4, m);
        }
        break;
    case 4:
        if (func_00382380(D_001A4C60, v->trigger, 0) != 0) {
            m[0x20] = 2;
            break;
        }
        *(f32 *)(m + 0x18) -= 0.036000002f;
        if (*(f32 *)(m + 0x18) <= v->height - 5.0f) {
            h = v->sound;
            if (h != -1) {
                e = D_001A30B0 + (h << 7);
                if (*(u8 **)(e + 0xDC) == m && e[0xD0] != 0) {
                    func_003A4F28(h);
                }
            }
            f = v->height - 5.0f;
            v->sound = -1;
            m[0x20] = 5;
            *(f32 *)(m + 0x18) = f;
        }
        break;
    case 5:
        if (func_L10_003591F8((char *)m) != 0 || func_00382380(D_001A4C60, v->trigger, 0) != 0) {
            m[0x20] = 2;
            v->sound = func_003A52A0(0, 4, m);
        }
        break;
    case 6:
        *(u16 *)(m + 0x34) |= 2;
        break;
    }
}
/* localdecomp:end func_L10_00358F48 */

/* localdecomp:start func_L10_003591B0 */
void func_L10_003591B0(void *arg0) {
    void *temp_a1;

    temp_a1 = *(void **)((u8 *)arg0 + 0x68);
    if ((*(u8 *)((u8 *)arg0 + 0x20)) == 0) {
        *(f32 *)((u8 *)temp_a1 + 4) = (f32) ((*(f32 *)((u8 *)arg0 + 0x18)) + 5.0f);
        if ((*(s32 *)temp_a1) == 2) {
            *(u8 *)((u8 *)arg0 + 0x20) = 5U;
            return;
        }
        *(u8 *)((u8 *)arg0 + 0x20) = 1U;
    }
}
/* localdecomp:end func_L10_003591B0 */

/* localdecomp:start func_L10_003591F8 */
extern int func_L01_00445AD0(int, int, int);
int func_L10_003591F8(char *a) {
    int *p = *(int **)(a + 0x68);
    int x = p[4];
    if (x != -1) return func_L01_00445AD0(x, -1, 0) == 0;
    return 0;
}
/* localdecomp:end func_L10_003591F8 */

/* localdecomp:start func_L10_00359238 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_359238;
extern u8 *D_L10_001DF29C;
extern void func_L10_00359368(void *);
extern void func_L01_004450F0(s32, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32,
                          f32, f32, f32, f32, f32, f32, f32, f32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_003C2880(void *);

void func_L10_00359238(u8 *m) {
    s32 *v = *(s32 **)(m + 0x68);
    V4_359238 c;
    s32 i;

    func_L10_00359368(m);
    switch (m[0x20]) {
    case 1:
        i = v[0];
        if (i != -1 && *(D_L10_001DF29C + (i << 8) + 0x20) >= 0xFD) {
            func_L01_004450F0((s32)m, 2, -1);
        }
        break;
    case 2:
        func_0038CF68(&c, m + 0xC0, 0.10000001f);
        func_003A52A0(0, 0, m);
        func_L01_00451FE0(m, 0x3F, &c, 0xFF, 0xB4, 0, 0, 0x23, 0, 3, 3.0f, 6.0f,
                          3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f);
        func_L01_00451E78(m, 1, 0.0f);
        func_003C2880(m);
        break;
    }
}
/* localdecomp:end func_L10_00359238 */

/* localdecomp:start func_L10_00359368 */
void func_L01_004450F0(s32, s32, s32);
void func_L10_00359368(void *arg0) {
    if ((*(u8 *)((u8 *)arg0 + 0x20)) == 0) {
        func_L01_004450F0((s32) arg0, 1, -1);
    }
}
/* localdecomp:end func_L10_00359368 */
