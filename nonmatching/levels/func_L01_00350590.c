/* near miss: 3 diff (a file with @ps2as): retail loads the constant 0x25 into $v1 for the three stores after the
 * call, ours uses $v0. Nested ifs and the gp externs with hints are needed; many store orders tried. */
#include "common.h"

/* localdecomp:start func_L01_00350590 */
typedef struct {
    u8 pad0[0x68];
    u8 *p68;
} S_350590;
typedef struct {
    u8 pad0[0x24];
    s32 w24;
    u8 pad28[4];
    s32 w2C;
} S_350590m;
extern void func_L01_00350658(void *);
extern void func_003A52A0(s32, s32, void *);
__asm__(".extern D_L01_001DD49C, 4");
extern void *D_L01_001DD49C;
__asm__(".extern D_001D6694, 4");
extern s32 D_001D6694;
__asm__(".extern D_L01_001DD4A8, 4");
extern s32 D_L01_001DD4A8;
__asm__(".extern D_L01_001DD4AC, 4");
extern s32 D_L01_001DD4AC;
extern u8 *D_001D52FC;
typedef struct {
    u8 pad0[0x1210];
    s32 w1210;
    u8 pad1214[0x25ED - 0x1214];
    u8 b25ED;
} S_A4BE0;
extern S_A4BE0 D_001A4BE0;

void func_L01_00350590(S_350590 *a0) {
    S_350590m *m;
    s32 t;

    m = a0->p68;
    func_L01_00350658(a0);
    if (D_L01_001DD49C != 0) {
        if (D_001D6694 == 0) {
            t = *(s32 *)(D_001D52FC + 0x1A4);
            if ((t & D_001A4BE0.w1210) != 0) {
                if (D_L01_001DD4A8 != 1) {
                    if (D_L01_001DD4A8 != 2) {
                        if (D_001A4BE0.b25ED == 0) {
                            if ((t & 8) == 0) {
                                m->w2C = 0;
                                func_003A52A0(3, 0, a0);
                                D_L01_001DD4A8 = 1;
                                D_L01_001DD4AC = 0x25;
                                m->w24 = 0x25;
                            }
                        }
                    }
                }
            }
        }
    }
}
/* localdecomp:end func_L01_00350590 */
