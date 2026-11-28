#include "common.h"

/* localdecomp:start func_L39_005771D0 */
typedef struct {
    s32 w;
    s32 h;
} Screen_005771D0;
extern s32 D_L39_00242914;
extern s32 D_L39_0024C9F4;
extern s32 D_L39_0024CA58[];
extern s32 D_L39_0024CA20;
extern void (*D_L39_0024BA40[])(void);
extern void (*D_L39_0024BA50[])(void);
extern s32 D_L39_00241128;
extern s32 D_L39_00242A00;
extern s32 D_L39_0024111C;
extern s32 D_L39_0024B9C4;
extern s32 D_L39_0024B9C8;
extern s32 D_L39_0024BB44;
extern Screen_005771D0 D_L39_00240300;
extern unsigned long D_L39_00240200;
extern s32 *D_L39_00241120;
extern s32 D_001A5810[];
extern void func_L01_00514380(void);
extern void func_L01_003F1760(void);
extern void func_L01_003F1780(void);
extern void func_L01_003F17A0(void);
extern void func_L01_003F17C0(s32, s32 *);
extern void func_L39_00576E48(s32, s32, s32, s32);
extern void func_L01_003F6F10(s32);
extern void func_L01_00403168(s32);
extern void func_L01_0045A550(void);
extern void func_L39_0058CC68(void);
extern void func_L39_00587E80(void);
extern void func_L39_00589538(s32);
extern void func_L39_005FCDF8(void);
extern void func_L39_00577148(void);
extern void func_L39_0057B1C0(void);
extern void func_L39_005BF490(void);
extern void func_L39_00597E70(void);
extern void func_003A92F0(s32);
extern void func_003A9108(void);
extern void func_00193590(void);
extern void func_0038E138(void);
extern void func_003A9440(s32, unsigned long);
extern void func_0038AF30(s32, s32, s32, s32, unsigned long);
extern s32 func_003A0EA8(s32);
extern void func_003B3158(s32);
extern void func_00389370(void);
extern void func_003A9150(void);
extern void func_003923D0(void);
extern void func_00392748(s32);
extern s32 func_00139E08(s32);

void func_L39_005771D0(void) {
    s32 out[8];
    s32 t;

    /* Both arms set the same layout in this build: gcc cross-jumps them after reload and the
     * compare's two operand loads stay behind as dead instructions, as in retail's prologue. */
    if (D_L39_00242914 == 1) {
        D_L39_0024CA20 = 0x8000;
        D_L39_0024CA58[0] = D_L39_0024C9F4;
        D_L39_0024CA58[1] = D_L39_0024C9F4 + 0x80000;
    } else {
        D_L39_0024CA20 = 0x8000;
        D_L39_0024CA58[0] = D_L39_0024C9F4;
        D_L39_0024CA58[1] = D_L39_0024C9F4 + 0x80000;
    }
    D_L39_0024BA40[0] = func_L01_00514380;
    D_L39_0024BA40[1] = func_L01_003F1760;
    D_L39_0024BA40[2] = func_L01_003F1780;
    D_L39_0024BA40[3] = func_L01_003F17A0;
    D_L39_0024BA50[0] = 0;
    D_L39_0024BA50[1] = 0;
    D_L39_0024BA50[2] = 0;
    D_L39_0024BA50[3] = 0;
    func_003A92F0(1);
    func_003A9108();
    D_L39_00242A00 = 1;
    while (D_L39_00241128 == 0 && D_L39_00242914 != 0) {
        D_L39_00240200 += *(volatile u32 *)0x10000800;
        *(volatile u32 *)0x10000800 = 0;
        D_L39_0024111C = 1;
        func_00193590();
        func_L39_0058CC68();
        D_L39_0024B9C4 = 0xBF;
        switch (D_L39_00242914) {
        case 1:
            func_L01_003F17C0(2, &out[0]);
            func_L39_00576E48(out[0], out[0] + 1, 1, 0);
            func_0038E138();
            func_L39_00576E48(out[1], out[1] + 1, 0, 1);
            break;
        case 2:
            func_L01_003F17C0(3, &out[4]);
            func_L39_00576E48(out[4], out[4] + 3, 1, 0);
            func_0038E138();
            func_L39_00576E48(out[5], out[5] + 3, 0, 0);
            func_0038E138();
            func_L39_00576E48(out[6], out[6] + 3, 0, 1);
            break;
        case 3:
        default:
            func_L01_003F17C0(4, &out[0]);
            func_L39_00576E48(out[0], out[0] + 6, 1, 0);
            func_0038E138();
            func_L39_00576E48(out[1], out[1] + 6, 0, 0);
            func_0038E138();
            func_L39_00576E48(out[2], out[2] + 6, 0, 0);
            func_0038E138();
            func_L39_00576E48(out[3], out[3] + 6, 0, 1);
            break;
        }
        func_L01_003F6F10(0);
        func_L01_00403168(0);
        func_L39_00587E80();
        func_003A9440(0x47, 0x33001);
        if (D_L39_00242914 == 1) {
            func_0038AF30(0, D_L39_00240300.h >> 1, 0x155, 0x200, 0x80000000UL);
            func_0038AF30(D_L39_00240300.h >> 1, D_L39_00240300.h, 0, 0xAA, 0x80000000UL);
            func_0038AF30((D_L39_00240300.h >> 1) - 1, D_L39_00240300.h >> 1, 0, 0x200, 0x80000000UL);
        } else if (D_L39_00242914 == 2) {
            func_0038AF30(D_L39_00240300.h >> 1, D_L39_00240300.h, 0x100, 0x200, 0x80000000UL);
            func_0038AF30(0, D_L39_00240300.h, 0xFF, 0x100, 0x80000000UL);
            func_0038AF30((D_L39_00240300.h >> 1) - 1, D_L39_00240300.h >> 1, 0, 0x200, 0x80000000UL);
        } else {
            func_0038AF30(0, D_L39_00240300.h, 0xFF, 0x100, 0x80000000UL);
            func_0038AF30((D_L39_00240300.h >> 1) - 1, D_L39_00240300.h >> 1, 0, 0x200, 0x80000000UL);
        }
        func_L39_00589538(0);
        if (func_003A0EA8(3) == 0) {
            func_003A9440(0x47, 0x33001);
            func_0038E138();
            func_003B3158(4);
        }
        func_00389370();
        func_003A92F0(1);
        func_L39_005FCDF8();
        func_003A9150();
        func_L01_0045A550();
        func_L39_00577148();
        if (*D_L39_00241120 >= 3) {
            D_L39_00242A00 ^= 1;
        }
        func_L01_003F6F10(0);
        {
            s32 limit = 0x2580;
            s32 c = D_001A5810[0];
            t = *(volatile s32 *)0x10000800;
            if (c != 0) {
                limit = 0x2D00;
            }
            if (t < limit) {
                func_00139E08(0);
            }
        }
        func_L39_00577148();
        if (*D_L39_00241120 >= 3) {
            D_L39_00242A00 ^= 1;
        }
        if (*D_L39_00241120 >= 2) {
            func_L39_0057B1C0();
        }
        {
            s32 limit = 0x4B00;
            s32 c = D_001A5810[0];
            t = *(volatile s32 *)0x10000800;
            if (c != 0) {
                limit = 0x5A00;
            }
            if (limit < t) {
                D_L39_0024111C = 2;
                func_L01_003F6F10(0);
                func_L39_00577148();
                if (*D_L39_00241120 >= 3) {
                    D_L39_00242A00 ^= 1;
                }
                if (*D_L39_00241120 >= 2) {
                    func_L39_0057B1C0();
                }
            }
        }
        D_L39_0024BB44 += 1;
        func_L39_005BF490();
        func_003923D0();
        func_00392748(1);
        func_L39_00597E70();
        func_003A92F0(1);
        func_00139E08(0);
        D_L39_0024B9C8 += 1;
        func_L39_005FCDF8();
        func_003A9150();
    }
}
/* localdecomp:end func_L39_005771D0 */
