/* PAL near miss (Codex wave 6): near miss: 5 words differ with the file's flags.
 * Worker's note: 5 diff: build/codex/w329/func_L01_003FFC88-04.log; two commuted table addu operands and origin/product allocation. Three origin-first formulations (03,05,06) stall at same 7 diffs. Inaccurate inherited extern size hint removed. Contract compile clean in ...
 */
#include "common.h"
/* localdecomp:start func_L01_003FFC88 */
extern S_003FF4E8 D_L01_001E6850[];
extern s32 D_L01_001E64C0[];
extern s32 D_001D4BC0;
extern u32 D_001D60B8_sda;
__asm__(".extern D_001D4BC0, 16");
__asm__(".extern D_001D60B8_sda, 4");
void func_L01_003FFC88(s32 character, f32 opacity) {
    extern s32 func_L01_00400160(s32, s32 *, s32 *);
    extern s32 func_L01_004000C0(s32);
    extern void func_003A9440(long, long);
    extern void func_0038AF30(s32, s32, s32, s32, s32);
    extern void func_003910C0(s32 *, s32, s32, s32, s32, s32, s32, s32, s32);
    extern s32 func_0038DBD8(s32, s32, f32);
    extern void func_0038FA18(s32 *, s32, s32, s32, unsigned long, f32, f32);
    s32 box[8];
    s32 table_index, key_offset;
    s32 texture;
    s32 x;
    s32 *context;
    s32 *strides;
    S_003FF4E8 *table;
    if (func_L01_00400160(character, &table_index, &key_offset)) {
        table = D_L01_001E6850;
        texture = func_L01_004000C0(((S_003FF4E8 *)((s32)table + table_index * 40))->v[1] + key_offset);
        if (texture) {
            func_003A9440(0x47, 0x33001);
            context = D_L01_001E64C0;
            strides = &table[0].v[8];
            x = character * strides[*(s16 *)((u8 *)context + 0x22) * 10] + ((S_003FF4E8 *)((s32)table + *(s16 *)((u8 *)context + 0x22) * 40))->v[5];
            func_0038AF30(x + 2, x + strides[*(s16 *)((u8 *)context + 0x22) * 10] - 2, 0, D_001D4BC0, (s32)(opacity * 96.0f) << 24);
            func_003910C0(box, x, x + strides[*(s16 *)((u8 *)context + 0x22) * 10], 0, D_001D4BC0, D_001D4BC0 / 2 + 2,
                x + strides[*(s16 *)((u8 *)context + 0x22) * 10] / 2 + 1, *(s32 *)((u8 *)context + 0x388), 3);
            func_0038FA18(box, func_0038DBD8(0, 0x80000000, opacity), texture, -1, 0x80000000UL, 1.0f, 1.0f);
            func_003910C0(box, x, x + strides[*(s16 *)((u8 *)context + 0x22) * 10], 0, D_001D4BC0, D_001D4BC0 / 2,
                x + strides[*(s16 *)((u8 *)context + 0x22) * 10] / 2, *(s32 *)((u8 *)context + 0x388), 3);
            func_0038FA18(box, func_0038DBD8(D_001D60B8_sda & 0xFFFFFF, D_001D60B8_sda, opacity),
                texture, -1, 0x80000000UL, 1.0f, 1.0f);
        }
    }
}
/* localdecomp:end func_L01_003FFC88 */
