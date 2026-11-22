/* PAL near miss (opus-w3): 23 words differ with the file's flags and the config/levels/divs_nops.txt row 'func_L01_003FF570 0 2 2 2 2 2'; only local-alloc FPU register numbers in the two copies loops differ (retail (f32)i $f3, spacing $f2, D_001D60BC $f1, copies-i $f4; here $f4/$f3/$f2/$f1). Calls func_L01_003FF9F0 through an ABI-equivalent alias with the float second, which fixes the argument-move order. */
#include "common.h"
/* localdecomp:start func_L01_003FF570 */
typedef struct {
    u8 pad0[0x22]; s16 current; u8 pad24[0x358];
    f32 duration; s32 copies; f32 spacing;
} Vars_003FF570;
extern s32 D_L01_001E64C0[];
extern S_003FF4E8 D_L01_001E6850[];
extern u32 D_001D60B8_sda;
extern f32 D_001D60BC_sda;
__asm__(".extern D_001D60B8_sda, 4");
__asm__(".extern D_001D60BC_sda, 4");
void func_L01_003FF570(s32 item, f32 progress) {
    extern s32 func_L01_00400160(s32, s32 *, s32 *);
    extern s32 func_L01_004000C0(s32);
    extern void func_L01_003FF9F0_003FF570(u8 *text, f32 t, s32 mode, s32 color, s32 x, s32 style);
    s32 group, offset, handle, location, i;
    S_003FF4E8 *entry;
    s32 *values;
    f32 alpha;
    u32 color;
    if (!func_L01_00400160(item, &group, &offset)) return;
    handle = func_L01_004000C0(D_L01_001E6850[group].v[1] + offset);
    if (handle == 0) return;
    location = D_L01_001E6850[((Vars_003FF570 *)D_L01_001E64C0)->current].v[5] + item * D_L01_001E6850[((Vars_003FF570 *)D_L01_001E64C0)->current].v[8];
    if (progress > 1.0f - ((Vars_003FF570 *)D_L01_001E64C0)->duration) {
        alpha = (progress - 1.0f + ((Vars_003FF570 *)D_L01_001E64C0)->duration) / ((Vars_003FF570 *)D_L01_001E64C0)->duration;
        if (alpha > 1.0f) alpha = 1.0f;
        else if (alpha < 0.0f) alpha = 0.0f;
        func_L01_003FF9F0_003FF570((u8 *)handle, alpha, 3, D_001D60B8_sda, location, 1);
        for (i = ((Vars_003FF570 *)D_L01_001E64C0)->copies; i >= 0; i--) {
            f32 v = (progress - 1.0f + ((Vars_003FF570 *)D_L01_001E64C0)->duration) / ((Vars_003FF570 *)D_L01_001E64C0)->duration + (f32)i * ((Vars_003FF570 *)D_L01_001E64C0)->spacing;
            s32 c = (s32)(D_001D60BC_sda * ((f32)(((Vars_003FF570 *)D_L01_001E64C0)->copies - i) / (f32)((Vars_003FF570 *)D_L01_001E64C0)->copies));
            color = ((c << 16) | 0x80000000) | (c << 8) | c;
            if (v > 1.0f) v = 1.0f;
            else if (v < 0.0f) v = 0.0f;
            func_L01_003FF9F0_003FF570((u8 *)handle, v, 3, color, location, 0);
        }
    } else if (progress < ((Vars_003FF570 *)D_L01_001E64C0)->duration) {
        alpha = progress / ((Vars_003FF570 *)D_L01_001E64C0)->duration;
        if (alpha > 1.0f) alpha = 1.0f;
        else if (alpha < 0.0f) alpha = 0.0f;
        func_L01_003FF9F0_003FF570((u8 *)handle, alpha, 2, D_001D60B8_sda, location, 1);
        for (i = ((Vars_003FF570 *)D_L01_001E64C0)->copies; i >= 0; i--) {
            f32 v = progress / ((Vars_003FF570 *)D_L01_001E64C0)->duration - (f32)i * ((Vars_003FF570 *)D_L01_001E64C0)->spacing;
            s32 c = (s32)(D_001D60BC_sda * ((f32)(((Vars_003FF570 *)D_L01_001E64C0)->copies - i) / (f32)((Vars_003FF570 *)D_L01_001E64C0)->copies));
            color = ((c << 16) | 0x80000000) | (c << 8) | c;
            if (v > 1.0f) v = 1.0f;
            else if (v < 0.0f) v = 0.0f;
            func_L01_003FF9F0_003FF570((u8 *)handle, v, 2, color, location, 0);
        }
    } else {
        func_L01_003FF9F0_003FF570((u8 *)handle, 1.0f, 0, D_001D60B8_sda, location, 1);
        func_L01_003FF9F0_003FF570((u8 *)handle, -2.2f, 1, 0x80000000, location - 2, 0);
        func_L01_003FF9F0_003FF570((u8 *)handle, 0.0f, 1, 0x80000000, location - 2, 0);
        func_L01_003FF9F0_003FF570((u8 *)handle, 2.2f, 1, 0x80000000, location - 2, 0);
        func_L01_003FF9F0_003FF570((u8 *)handle, -2.2f, 1, 0x80000000, location + 2, 0);
        func_L01_003FF9F0_003FF570((u8 *)handle, 0.0f, 1, 0x80000000, location + 2, 0);
        func_L01_003FF9F0_003FF570((u8 *)handle, 2.2f, 1, 0x80000000, location + 2, 0);
        func_L01_003FF9F0_003FF570((u8 *)handle, 1.0f, 0, D_001D60B8_sda, location, 0);
    }
}
/* localdecomp:end func_L01_003FF570 */
