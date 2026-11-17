/* PAL near miss (Codex wave 8): near miss: 5 words differ with the file's flags.
 * Worker's note: 5 word differences; build/codex/w455/func_L07_003DC6E8.01.log. s1/f20 save order and result move before initial table load/branch vs branch delay slot. Float-array, TI-vector and vector-struct local forms retain same bytes; body and epilogue exact.
 */
#include "common.h"
/* localdecomp:start func_L07_003DC6E8 */
typedef int TI_003DC6E8 __attribute__((mode(TI)));
typedef struct { u8 pad[0xE0]; TI_003DC6E8 pos; u8 gap[0x24D0]; void *moby; } Hero_003DC6E8;
extern Hero_003DC6E8 D_001A4BE0;
extern u8 *D_L07_0021C460[];
void func_L07_003DC6E8(u8 *obj) {
    extern f32 func_L01_0040E548(void *, void *);
    extern void func_L07_003DC790(void *, void *, void *, f32);
    f32 pos[4] __attribute__((aligned(16)));
    u8 *s = *(u8 **)(obj + 0x68);
    f32 distance = func_L01_0040E548(s, s + 0x70);
    u8 **p;
    u8 *target;
    for (p = D_L07_0021C460; (target = *p) != 0; p++) {
        if (target != *(u8 **)(obj + 0xB8)) {
            *(TI_003DC6E8 *)pos = *(TI_003DC6E8 *)(target + 0x10);
            func_L07_003DC790(obj, target, pos, distance);
        }
    }
    *(TI_003DC6E8 *)pos = D_001A4BE0.pos;
    func_L07_003DC790(obj, D_001A4BE0.moby, pos, distance);
}
/* localdecomp:end func_L07_003DC6E8 */
