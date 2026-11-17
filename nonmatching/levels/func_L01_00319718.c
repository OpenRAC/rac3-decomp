#include "common.h"

/* localdecomp:start func_L01_00319718 */
extern s8 D_L01_00273B80_00319718[];
extern f32 func_003824E0(f32, f32);
extern void func_003D9508(s32, s32, s32, s32, f32, f32, f32);

void func_L01_00319718(s32 owner) {
    extern void func_L01_00319880(s32, s32);
    u32 i;
    s32 table_addr;
    s8 *piece;
    s8 *table;

    table = D_L01_00273B80_00319718;
    piece = table + 0x30;
    table_addr = (s32) table;
    i = 0;
    while (i < 6) {
        i++;
        if ((*(s32 *)((s8 *)(piece) + (0x6C))) == owner) {
            func_L01_00319880(owner, table_addr);
            if ((*(s32 *)((s8 *)(piece) + (0x70))) == 0) {
                func_003D9508((s32)piece, 0x31, 0x3F7F0000, 1, func_003824E0(0.125f, 0.25f) * 5.0f, 1.25f, 0.0f);
                func_003D9508((s32)piece, 0x31, 0x5F7F7F7F, 1, func_003824E0(0.0625f, 0.125f) * 5.0f, 1.24f, 0.0f);
                func_003D9508((s32)piece, 0xB, 0x103F0000, 1, func_003824E0(0.15f, 0.35f) * 5.0f, 1.23f, 0.0f);
            }
        }
        piece += 0xB0;
        table_addr += 0xB0;
    }
}
/* localdecomp:end func_L01_00319718 */
