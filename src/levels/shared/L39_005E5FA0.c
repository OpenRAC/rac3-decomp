#include "common.h"

/* localdecomp:start func_L39_005E5FA0 */
extern u8 D_001A5810[];
extern void func_L39_005F3548(s32, s32, s32);
extern void func_00193C60(s32);

void func_L39_005E5FA0(s32 buttons) {
    if (buttons & 0xA040) {
        s32 *p;
        s32 v;
        ((s32 (*)(s32, s32, s32))func_L39_005F3548)(4, 0, 0);
        p = (s32 *)D_001A5810;
        v = p[2] == 0;
        p[2] = v;
        func_00193C60(v == 0);
    }
}
/* localdecomp:end func_L39_005E5FA0 */

/* localdecomp:start func_L39_005E5FE8 */
typedef struct {
    s32 pad[3];
    s32 val;
} S_48DA70;
extern u8 D_001A5810[];
extern void func_003A5348(s32 a0, s32 a1, s32 a2);
void func_L39_005E5FE8(s32 buttons) {
    s32 v;
    if (buttons & 0x8000) {
        S_48DA70 *p = &(*(S_48DA70 *)&D_001A5810);
        v = p->val - 30;
        p->val = (v < 0) ? 0 : v;
    } else if (buttons & 0x2000) {
        S_48DA70 *p = &(*(S_48DA70 *)&D_001A5810);
        v = p->val + 30;
        p->val = (v > 1024) ? 1024 : v;
    }
    func_003A5348(3, 0, 0);
}
/* localdecomp:end func_L39_005E5FE8 */

/* localdecomp:start func_L39_005E6060 */
typedef struct {
    s32 pad[4];
    s32 val;
} S_005E6060;
extern u8 D_001A5810[];
extern void func_L39_005F3548(s32, s32, s32);

void func_L39_005E6060(s32 buttons) {
    s32 v;
    if (buttons & 0x8000) {
        S_005E6060 *p = (S_005E6060 *)D_001A5810;
        v = p->val - 30;
        p->val = (v < 0) ? 0 : v;
    } else if (buttons & 0x2000) {
        S_005E6060 *p = (S_005E6060 *)D_001A5810;
        v = p->val + 30;
        p->val = (v > 1024) ? 1024 : v;
    }
    func_L39_005F3548(3, 0, 0);
}
/* localdecomp:end func_L39_005E6060 */

/* localdecomp:start func_L39_005E60D8 */
extern u8 D_001A5810[];
extern void func_L39_005F3548(s32, s32, s32);
s32 func_L39_005E60D8(s32 a0) {
    if (a0 & 0xA040) {
        u8 *p;
        func_L39_005F3548(4, 0, 0);
        p = D_001A5810;
        p[5] = p[5] == 0;
    }
}
/* localdecomp:end func_L39_005E60D8 */

/* localdecomp:start func_L39_005E6118 */
typedef struct {
    s32 v[4];
} S_005E6118;
extern s32 D_L39_0024C738 __attribute__((section(".sdata")));
extern s32 D_001D8434_sda;
extern s32 D_001D8430_sda;
extern s32 D_001D8370_sda;
extern s32 D_L39_0024C728[] __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024C728, 4");
extern s32 D_001D8438_sda[] __attribute__((section(".sdata")));
__asm__(".extern D_001D8438_sda, 4");
extern s32 func_L01_00517688(void);
extern u8 *func_L39_0061BF38(s32);

s32 func_L39_005E6118(void) {
    s32 i;
    u8 *p;
    s32 cur;
    s32 res;
    if (D_L39_0024C738 == 0) {
        s32 v = D_001D8434_sda;
        S_005E6118 t = { { v, v, v, v } };
        D_L39_0024C738 = 1;
        *(S_005E6118 *)D_L39_0024C728 = t;
    }
    i = func_L01_00517688();
    p = func_L39_0061BF38(i);
    cur = *(s32 *)(*(u8 **)(p + 0x2534) + 0x1C0);
    res = *(s32 *)(*(u8 **)(p + 0x2534) + 0x1C4);
    if (cur != 0 && cur == D_001D8438_sda[i]) {
        s32 n = --D_L39_0024C728[i];
        if (n == 0 || n == 0xFF) {
            D_L39_0024C728[i] = D_001D8430_sda;
            res = *(s32 *)(*(u8 **)(p + 0x2534) + 0x1C0) & D_001D8370_sda;
        }
    } else {
        D_L39_0024C728[i] = D_001D8434_sda;
    }
    D_001D8438_sda[i] = *(s32 *)(*(u8 **)(p + 0x2534) + 0x1C0);
    return res;
}
/* localdecomp:end func_L39_005E6118 */
