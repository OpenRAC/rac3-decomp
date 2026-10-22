#include "common.h"

INCLUDE_ASM("asm/levels", func_L35_003A53F8);

INCLUDE_ASM("asm/levels", func_L35_003A5780);

/* localdecomp:start func_L35_003A5878 */
void func_L35_003A5878(void *arg0, f32 fparg0, f32 fparg1) {
    f32 temp_f0;
    s32 var_a1;
    void *temp_a0;
    void *var_v1;

    if (arg0 != 0) {
        temp_a0 = *(void **)((u8 *)arg0 + 0x68);
        var_v1 = temp_a0 + 0x60;
        if (temp_a0 != 0) {
            var_a1 = 0;
            if ((*(s32 *)((u8 *)temp_a0 + 0x20)) > 0) {
                do {
                    if ((*(s32 *)((u8 *)var_v1 + 0x14)) != -1) {
                        temp_f0 = (*(f32 *)((u8 *)var_v1 + 8)) + fparg0;
                        *(f32 *)((u8 *)var_v1 + 8) = temp_f0;
                        if (fparg1 < temp_f0) {
                            *(f32 *)((u8 *)var_v1 + 8) = fparg1;
                        }
                    }
                    var_a1 += 1;
                    var_v1 += 0x20;
                } while (var_a1 < (*(s32 *)((u8 *)temp_a0 + 0x20)));
            }
        }
    }
}
/* localdecomp:end func_L35_003A5878 */

/* localdecomp:start func_L35_003A58E8 */
void func_L35_003A5978(void *);
void func_L35_003A5E20(void *);
void func_L35_003A5F00(void *);
void func_L35_003A60F0(void *);
void func_L35_003A6240(void *);

void func_L35_003A58E8(void *arg0) {
    u8 temp_v1;

    temp_v1 = *(u8 *)((u8 *)arg0 + 0x20);
    switch (temp_v1) {                              /* irregular */
    case 0:
        func_L35_003A5F00(arg0);
        break;
    case 1:
        func_L35_003A6240(arg0);
        break;
    case 2:
        func_L35_003A60F0(arg0);
        break;
    }
    func_L35_003A5978(arg0);
    func_L35_003A5E20(arg0);
}
/* localdecomp:end func_L35_003A58E8 */

INCLUDE_ASM("asm/levels", func_L35_003A5978);

INCLUDE_ASM("asm/levels", func_L35_003A5E20);
