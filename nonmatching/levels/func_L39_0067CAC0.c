/* NTSC-U draft (2026-11-14, Claude worker): C of func_L39_0067A008, the NTSC-U twin of func_L39_0067CAC0, with NTSC-U names
 * and addresses. Near miss on NTSC-U: 3 words differ with its file's flags.
 */
#include "common.h"

/* NTSC-U counterpart of func_L39_0067CAC0 (src/levels/39_multiplayer_menu/L39_0067C948.c) */

/* localdecomp:start func_L39_0067A008 */
typedef struct { u8 p0; u8 f1; u8 p2[6]; s32 f8; } S_0067A008;

extern s32 D_001DB0AC_sda;
__asm__(".extern D_001DB0AC_sda, 4");
extern s32 D_001DB0DC_sda;
__asm__(".extern D_001DB0DC_sda, 4");
extern u8 D_001DC2EA_sda;
__asm__(".extern D_001DC2EA_sda, 1");
extern s32 D_001E03B4_sda;
__asm__(".extern D_001E03B4_sda, 4");
extern s32 D_001E0238_sda;
__asm__(".extern D_001E0238_sda, 4");
extern s32 D_L39_0024BC44;
__asm__(".extern D_L39_0024BC44, 16");
extern f32 D_L39_0024BC48;
__asm__(".extern D_L39_0024BC48, 16");
extern s32 D_L39_0024BAC8;
__asm__(".extern D_L39_0024BAC8, 16");
extern u8 D_L39_00242B2E;
__asm__(".extern D_L39_00242B2E, 16");
extern unsigned long D_L39_00240380;
__asm__(".extern D_L39_00240380, 16");
extern S_0067A008 *D_L39_0024D860;
__asm__(".extern D_L39_0024D860, 16");
extern s32 D_001A5990[];
extern void func_L39_00679F08(void);
extern void func_L39_005A43D8(void);
extern void func_003A3DA0(s32);
extern s32 func_00139E08(s32);
extern void func_00383A90(void);
extern void func_L39_0058BA98(void);
extern void func_L39_005FA660(void);
extern void func_003A3C00(void);
extern void func_0038DB98(void);
extern void func_0038DF10(s32);
extern void func_L39_00596BA0(void);
extern void func_L01_0045E370(void);
extern void func_00195AE8(void);
extern void func_L39_0067C110(void);
extern void func_L39_005EF018(void);
extern void func_L39_006D6030(void *);
extern s32 func_0012DCB0(void);
extern long func_00130760(s32, s32);
extern void func_L39_00686878(void);
extern void func_L39_006869C8(void);

void func_L39_0067A008(void) {
    S_0067A008 *p;
    s32 v;

    D_001DB0AC_sda++;
    func_L39_00679F08();
    D_001E03B4_sda = D_L39_0024BC44 + 1;
    func_L39_005A43D8();
    func_003A3DA0(1);
    D_L39_0024BC48 = (f32)*(volatile u32 *)0x10000800 / (D_001A5990[0] != 0 ? 11520.0f : 9600.0f);
    func_00139E08(0);
    D_L39_00242B2E = 0;
    D_001E0238_sda = D_L39_0024BAC8 + 1;
    func_00383A90();
    D_L39_00240380 += *(volatile u32 *)0x10000800;
    *(volatile u32 *)0x10000800 = 0;
    func_L39_0058BA98();
    func_L39_005FA660();
    func_003A3C00();
    func_0038DB98();
    func_0038DF10(1);
    func_L39_00596BA0();
    func_L01_0045E370();
    func_00195AE8();
    func_L39_0067C110();
    func_L39_005EF018();
    if (D_L39_0024D860 != 0) {
        func_L39_006D6030(D_L39_0024D860);
        p = D_L39_0024D860;
        v = 0;
        if (p->f1 != 0) {
            v = (s32)func_00130760(func_0012DCB0(), 0x24000) - p->f8;
        }
        if (D_001DB0DC_sda < v && D_001DC2EA_sda != 0) {
            func_L39_00686878();
        } else {
            func_L39_006869C8();
        }
    }
    D_001DB0AC_sda--;
}
/* localdecomp:end func_L39_0067A008 */
