#include "common.h"

/* localdecomp:start func_L39_005DBF90 */
extern u8 D_001D81DC_sda;
extern s32 func_L01_00517688(void);
extern void func_003E82F8(s32);
extern s32 func_L01_00516AA0(s32, s32, s32);

void func_L39_005DBF90(s32 a0) {
    s32 prev;

    if (D_001D81DC_sda != 0) {
        prev = func_L01_00517688();
        if (a0 != -1) {
            func_003E82F8(a0);
        }
        func_L01_00516AA0(0x50000, 1, 0);
        func_L01_00516AA0(0x50001, 1, 0);
        func_L01_00516AA0(0x50002, 1, 0);
        func_L01_00516AA0(0x50003, 1, 0);
        func_L01_00516AA0(0x50004, 1, 0);
        func_L01_00516AA0(0x50005, 1, 0);
        if (a0 != -1) {
            func_003E82F8(prev);
        }
    }
}
/* localdecomp:end func_L39_005DBF90 */

/* localdecomp:start func_L39_005DC068 */
extern u8 D_001D81DC_sda;
extern s32 func_L01_00517688(void);
extern void func_003E82F8(s32);
extern s32 func_L01_00516AA0(s32, s32, s32);

void func_L39_005DC068(s32 a0) {
    s32 prev;

    if (D_001D81DC_sda != 0) {
        prev = func_L01_00517688();
        if (a0 != -1) {
            func_003E82F8(a0);
        }
        func_L01_00516AA0(0x50000, 1, 1);
        func_L01_00516AA0(0x50001, 1, 1);
        func_L01_00516AA0(0x50002, 1, 1);
        func_L01_00516AA0(0x50003, 1, 1);
        func_L01_00516AA0(0x50004, 1, 1);
        func_L01_00516AA0(0x50005, 1, 1);
        if (a0 != -1) {
            func_003E82F8(prev);
        }
    }
}
/* localdecomp:end func_L39_005DC068 */

/* localdecomp:start func_L39_005DC140 */
extern u8 D_L39_0024C410[];
extern u8 D_L39_0024C418[];

s32 func_L39_005DC140(s32 a0) {
    s32 r = 0;
    if (D_L39_0024C410[a0] != 0 || D_L39_0024C418[a0] != 0) {
        r = 1;
    }
    return r;
}
/* localdecomp:end func_L39_005DC140 */

/* localdecomp:start func_L39_005DC180 */
typedef struct S_005DC180 {
    u8 pad[0x18F];
    s8 f18F;
} S_005DC180;
__asm__(".extern D_L39_00241120, 16");
__asm__(".extern D_001D81DC_sda, 1");
__asm__(".extern D_L39_0024C3F8, 16");
__asm__(".extern D_L39_0024C400, 16");
extern u8 D_001D81DC_sda;
extern u8 D_L39_0024C3F8[8];
extern s32 D_L39_0024C400[2];
extern s32 *D_L39_00241120;
extern S_005DC180 *D_001D5F30_sda;
extern s32 func_L01_00516AA0(s32, s32, s32);

void func_L39_005DC180(s32 a0, s32 a1)
{
    if (D_001D81DC_sda != 0) {
        if (a1 != 0 && D_L39_0024C3F8[a0] == 0) {
            D_L39_0024C400[a0] = 0x19;
        }
        D_L39_0024C3F8[a0] = a1;
        if (*D_L39_00241120 == 1) {
            if (a1 != 0 && D_001D5F30_sda->f18F != 0) {
                func_L01_00516AA0(0x50024, 1, 1);
            } else {
                func_L01_00516AA0(0x50024, 1, 0);
            }
            func_L01_00516AA0(0x50023, 1, 0);
        }
    }
}
/* localdecomp:end func_L39_005DC180 */

/* localdecomp:start func_L39_005DC248 */
extern u8 D_L39_0024C410[];
void func_L39_005DC248(s32 i, u8 v) {
    D_L39_0024C410[i] = v;
}
/* localdecomp:end func_L39_005DC248 */

/* localdecomp:start func_L39_005DC260 */
extern u8 D_L39_0024C418[];
u8 func_L39_005DC260(s32 i) {
    return D_L39_0024C418[i];
}
/* localdecomp:end func_L39_005DC260 */

/* localdecomp:start func_L39_005DC278 */
extern u8 D_L39_0024C418[];
void func_L39_005DC278(s32 i, u8 v) {
    D_L39_0024C418[i] = v;
}
/* localdecomp:end func_L39_005DC278 */

INCLUDE_ASM("asm/levels", func_L39_005DC290);

INCLUDE_ASM("asm/levels", func_L39_005DC338);
