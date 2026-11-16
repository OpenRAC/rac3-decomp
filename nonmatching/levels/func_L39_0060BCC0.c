/* NTSC-U draft (Claude wave K): C of func_L39_006095C0, the NTSC-U twin of func_L39_0060BCC0, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 7 words differ on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (the file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division") (NTSC-U twin "func_L39_006095C0", whose code is not the PAL one).
 * Worker's note: 7 raw diffs of 79 with @ps2as (the PAL flag line lacks @ps2as: without it the `sw $0,sym` macro lands in the first bnez delay slot as lui/sw split across the branch, so only a flags change can land it). Full decode is right (gp-byte guard loop, wait loop on ...
 */
#include "common.h"

/* localdecomp:start func_L39_006095C0 */
typedef struct {
    u8 pad0[0x15C];
    s32 w15C;
    u8 pad160[4];
    s32 w164;
} H_6095C0;
typedef struct {
    u8 pad0[7];
    u8 b7;
    u8 pad8[0x18];
} B_6095C0;

__asm__(".extern D_L39_0024040C, 16");
extern s32 D_L39_0024040C;
extern u8 D_001DA121_sda;
__asm__(".extern D_001DA121_sda, 1");
extern void (*D_001DA114_sda)(void);
__asm__(".extern D_001DA114_sda, 4");
extern s32 D_001E14B0_sda;
__asm__(".extern D_001E14B0_sda, 4");
extern H_6095C0 D_001A4560;
extern B_6095C0 D_L39_002257E0;
__asm__(".extern D_L39_002257E0, 16");

extern void func_001264E0(s32);
extern s32 func_00139E08(s32);
extern void func_00195AE8(void);
extern void func_L39_005A43D8(void);
extern void func_L39_005A33A0(void);
extern s32 func_L39_005A23F0(void);
extern void func_00193C70(s32);
extern s32 func_00193680(void);
extern void func_00193C40(void);
extern s32 func_00194C78(s32);
extern void func_00194B28(s32);
extern void func_L39_005FAF60(void);
extern void func_00383848(void);

void func_L39_006095C0(void) {
    D_L39_0024040C = 0;
    if (D_001DA121_sda == 0) {
        do {
            func_001264E0(0);
            func_00139E08(0);
            func_00195AE8();
            func_L39_005A43D8();
            func_L39_005A33A0();
            D_001DA121_sda = func_L39_005A23F0() != 0;
        } while (D_001DA121_sda == 0);
    }
    while (D_001A4560.w15C != 2 || D_001A4560.w164 >= 0) {
        func_001264E0(0);
        func_00139E08(0);
        func_L39_005A43D8();
        func_L39_005A33A0();
        func_00195AE8();
    }
    if (D_001E14B0_sda != 0) {
        func_00193C70(D_001E14B0_sda);
    }
    while (func_00193680() != 0) {
        func_00195AE8();
    }
    func_00193C40();
    func_00194C78(0);
    func_00194B28(0);
    func_00194B28(0);
    D_L39_002257E0.b7 = 0;
    func_L39_005FAF60();
    if (D_001DA114_sda != 0) {
        D_001DA114_sda();
    }
    func_00383848();
}
/* localdecomp:end func_L39_006095C0 */
