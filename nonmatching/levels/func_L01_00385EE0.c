/* PAL near miss (Codex wave 10): near miss: 86 words differ with the file's flags.
 * Worker's note: 84 positional word diffs with fixed flags; a3.log. Default assembler pools 0.05f/0.1f in .lit4, shortening body by 20 bytes; tail count/color allocation also differs. NEEDS divs row 'func_L01_00385EE0 2' used in best check.
 */
#include "common.h"
/* localdecomp:start func_L01_00385EE0 */
typedef int Q_00385EE0 __attribute__((mode(TI)));
extern f32 D_001DDD94_sda;
void func_L01_00385EE0(u8 *p) {
    extern void **func_L01_00457480(s32, s32);
    extern void func_L01_004C8668(int);
    extern void func_003C2880(void *);
    extern void func_L01_004CAB30(void *, void *);
    extern void func_L01_00386148(void *, s32, s32, s32, s32, s32, f32, f32, f32);
    u8 *v = *(u8 **)(p + 0x68);
    void **table;
    s32 slot, i;
    s32 count, alpha1, alpha2;
    if (p == 0 || p[0x20] == 0xFE || p[0x20] == 0xFD || v == 0) return;
    slot = *(s32 *)v;
    table = func_L01_00457480(*(s32 *)(v + 0x18), *(s32 *)(v + 0x14));
    if (table == 0) {
        func_L01_004C8668(*(s32 *)(v + 0x30));
        func_003C2880(p);
        return;
    }
    for (i=0; i<*(s32 *)(v + 0x10); i++) {
        u8 *point = (u8 *)table[slot] + i*16;
        func_L01_004CAB30(point, point);
    }
    if (p[0x20] == 0) {
        s32 j;
        if (++*(s32 *)(v + 0x10) >= 40) *(s32 *)(v + 0x10) = 40;
        for (j=*(s32 *)(v + 0x10)-1; j>0; --j) {
            ((Q_00385EE0 *)table[slot])[j] = ((Q_00385EE0 *)table[slot])[j-1];
        }
        *(Q_00385EE0 *)table[slot] = *(Q_00385EE0 *)(p + 0x10);
        ((f32 *)table[slot])[3] = 0.05f;
    }
    D_001DDD94_sda -= 0.1f;
    if (D_001DDD94_sda <= -7.0f) D_001DDD94_sda += 7.0f;
    if (*(s32 *)(v + 0x10) >= 2) {
        count = *(s32 *)(v + 0x10) > 19 ? 20 : *(s32 *)(v + 0x10);
        alpha2 = 255;
        alpha1 = 64;
        if (p[0x20] == 1) {
            f32 ratio = (f32)*(s32 *)(v + 0x34) / 5.0f;
            alpha1 = ratio * alpha1;
            alpha2 = ratio * alpha2;
        }
        func_L01_00386148(table[slot], 23, 14, count, (alpha2 << 24) | 0xFFFFFF, (alpha1 << 24) | 0x707070, 0.0f, 4.0f, D_001DDD94_sda);
    }
}
/* localdecomp:end func_L01_00385EE0 */
