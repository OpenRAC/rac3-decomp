#include "common.h"

/* localdecomp:start func_L39_005DA870 */
typedef struct { s32 v[3]; } S_005DA870;
extern S_005DA870 D_L39_00243710;
extern S_005DA870 D_L39_00243720;
extern S_005DA870 D_L39_00243730;
extern u8 D_001D7F58_sda[4];
extern f32 D_001D7FA8_sda;
__asm__(".extern D_L39_00241120, 16");
extern s32 *D_L39_00241120;
extern void func_003E82F8(s32);
extern s32 func_L01_00516AA0(s32, s32, s32);
extern void func_L01_005169C8(s32, f32);
extern void func_L01_00517190(s32, s32);
extern void func_L01_005170B8(s32, s32);
extern s32 func_00392A18(void);
extern s32 func_L39_00611AC8(s32, s32, s32);

void func_L39_005DA870(s32 a0, s32 a1, s32 a2, s32 a3) {
    S_005DA870 A = D_L39_00243710;
    S_005DA870 B = D_L39_00243720;
    S_005DA870 C = D_L39_00243730;
    if (a3 >= 0) {
        func_003E82F8(a3);
    }
    if (a0 < 0) {
        if (D_001D7F58_sda[a3] == 0) {
            func_L01_00516AA0(0x20014, 1, 1);
            func_L01_00516AA0(0x20015, 1, 1);
            func_L01_00516AA0(0x20016, 1, 1);
            if (*D_L39_00241120 == 1) {
                func_L39_00611AC8(0x20004, func_00392A18(), 0x62);
                func_L39_00611AC8(0x20003, func_00392A18(), 0x63);
                func_L01_005169C8(0x20003, 1.0f);
                func_L01_005169C8(0x20004, 1.0f);
            }
            func_L01_00516AA0(0x20010, 1, 0);
            func_L01_00516AA0(0x20011, 1, 0);
            func_L01_00516AA0(0x20012, 1, 0);
            func_L01_00516AA0(0x20007, 1, 0);
            func_L01_00516AA0(0x20008, 1, 0);
            func_L01_00516AA0(0x20009, 1, 0);
            func_L01_00516AA0(0x2000A, 1, 0);
            D_001D7F58_sda[a3] = 1;
        }
    } else {
        func_L01_00517190(A.v[a2], a0);
        if (a1 != 0) {
            func_L01_005170B8(A.v[a2], C.v[a2]);
        } else {
            func_L01_005170B8(A.v[a2], B.v[a2]);
        }
        if (a0 == 0) {
            func_L01_00516AA0(A.v[a2], 1, 0);
        } else {
            if (D_001D7F58_sda[a3] != 0) {
                func_L01_00516AA0(0x20014, 1, 0);
                func_L01_00516AA0(0x20015, 1, 0);
                func_L01_00516AA0(0x20016, 1, 0);
                func_L01_00516AA0(0x20017, 1, 0);
                func_L01_00516AA0(0x20018, 1, 0);
                if (*D_L39_00241120 == 1) {
                    func_L39_00611AC8(0x20004, func_00392A18(), 0x1F);
                    func_L39_00611AC8(0x20003, func_00392A18(), 0x20);
                    func_L01_005169C8(0x20003, D_001D7FA8_sda);
                    func_L01_005169C8(0x20004, D_001D7FA8_sda);
                }
                func_L01_00516AA0(0x20010, 1, 1);
                func_L01_00516AA0(0x20011, 1, 1);
                func_L01_00516AA0(0x20012, 1, 1);
                func_L01_00516AA0(0x20007, 1, 1);
                func_L01_00516AA0(0x20008, 1, 1);
                func_L01_00516AA0(0x20009, 1, 1);
                func_L01_00516AA0(0x2000A, 1, 1);
                D_001D7F58_sda[a3] = 0;
            }
            func_L01_00516AA0(A.v[a2], 1, 1);
        }
    }
}
/* localdecomp:end func_L39_005DA870 */
