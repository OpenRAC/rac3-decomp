/* PAL near miss (Codex wave 10): near miss: 2 words differ with the file's flags.
 * Worker's note: 2 word diffs at +0x4C/+0x50: table address addu destination/operands and following lw base; c01.log to c03.log. Integer sum, typed table indexing and commuted integer sum identical; simple resume candidate retained.
 */
#include "common.h"
/* localdecomp:start func_L07_00332098 */
typedef struct { s32 f0; u8 *rows; s32 f8, fC; } Table_00332098;
extern u8 D_L07_002B0D40[];
extern u8 *D_L07_001DF41C[] __attribute__((section(".sdata")));
void func_L07_00332098(u8 *m)
{
    extern s32 func_L07_00333B90(void);
    extern s32 func_L07_00333BF8(u8 *);
    extern s32 func_00382468(s32);
    extern s32 func_00382498(s32, s32);
    extern s32 func_L02_003A02D8(u8 *, s32);
    extern s32 func_L07_003A24C8(void);
    extern void func_L07_003A2380(u8, u8 *, s32, s32);
    u8 *vars = *(u8 **)(m + 0x68);
    u8 *row = ((Table_00332098 *)((vars[0x9E] << 4) + (s32)D_L07_002B0D40))->rows + vars[0x9F] * 12;
    s32 special, count, start, i, accumulator;
    s32 *ids;
    if (row[0] == 0) return;
    count = 8 - func_L07_00333B90();
    special = row[0] == 2;
    if (special && func_L07_00333BF8(m)) special = 0;
    if (count != 0) {
        start = func_00382468(8);
        accumulator = 4;
        for (i = 0; i < 8; i++) {
            if ((vars[0x9F] & 1) == (i & 1)) {
                s32 index = start + i;
                s32 selected = 0;
                u8 *object;
                if (index >= 8) index -= 8;
                accumulator += count;
                if (accumulator >= 8) {
                    accumulator -= 8;
                    selected = 1;
                }
                ids = (s32 *)(vars + 0x50);
                object = D_L07_001DF41C[0] + (*(s32 *)((s32)ids + (index << 2)) << 8);
                if (special) {
                    if (func_L02_003A02D8(object, 1)) {
                        if (func_L07_003A24C8()) {
                            func_L07_003A2380(func_00382498(37, 38), m, 0, 100);
                        }
                        special = 0;
                    }
                } else if (selected) {
                    func_L02_003A02D8(object, 0);
                }
            }
        }
    }
}
/* localdecomp:end func_L07_00332098 */
