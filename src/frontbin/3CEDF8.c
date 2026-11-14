#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void func_0038D2A0();
extern void func_003CF0F0(void);
extern void func_003CF050(void);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003CF0F0();
extern void func_003CF050();
/* --- end of declarations from other files --- */

extern f32 D_001DA670[];
extern s32 D_001DA680[];
extern f32 D_00225B30[];
extern f32 D_00334FB0[];
extern void func_0038CBA0();
INCLUDE_ASM("asm/nonmatchings/text", func_003CEDF8);

extern u32 *D_001DA050;
extern u32 *D_001DA68C;
extern s32 D_001DA694;
extern s32 D_001D4BB0;
extern void func_003CFDD0(void);
extern s32 func_003CFF38(s32);
extern void func_003A9618(void);
/* localdecomp:start func_003CEF40 */
extern u32 *D_001DA050_f;
extern u32 *D_001DA68C_f;
extern s32 D_001DA694_f;
extern s32 D_001D4BB0_f;
extern void func_003CFDD0_f(void);
extern s32 func_003CFF38_f(s32);
extern void func_003A9618_f(void);
void func_003CEF40(void) {
    u32 *save = D_001DA050_f;
    s32 r;
    D_001DA050_f += 4;
    D_001DA68C_f[0] = 0x20000000;
    D_001DA68C_f[1] = (u32)D_001DA050_f;
    D_001DA68C_f[2] = 0;
    D_001DA68C_f[3] = 0;
    func_003CFDD0_f();
    r = func_003CFF38_f(D_001D4BB0_f);
    func_003A9618_f();
    if (D_001DA694_f < r) { D_001DA694_f = r; }
    D_001DA050_f[0] = 0x20000000;
    D_001DA050_f[1] = (u32)(D_001DA68C_f + 4);
    D_001DA050_f[2] = 0;
    D_001DA050_f[3] = 0;
    D_001DA050_f += 4;
    save[0] = 0x20000000;
    save[1] = (u32)D_001DA050_f;
    save[2] = 0;
    save[3] = 0;
}
/* localdecomp:end func_003CEF40 */

/* localdecomp:start func_003CF050 */
typedef struct {
    u32 word0;
    u8 pad4[0x1F];
    u8 index23;
    u8 pad24[0xC];
    u32 word30;
    u8 pad34[0x1C];
} Item_003C9AE0;

typedef struct {
    Item_003C9AE0 *items;
    s32 count;
} Group_003C9AE0;

typedef struct {
    s16 first;
    s16 second;
} Pair_003C9AE0;

extern Group_003C9AE0 D_002FD800[];
extern Pair_003C9AE0 D_002FD500[];

void func_003CF050(void) {
    Group_003C9AE0 *group = D_002FD800;

    if (group->items != 0) {
        do {
            Item_003C9AE0 *item = group->items;
            register s32 loaded_count __asm__("$2") = group->count;

            if (loaded_count > 0) {
                register s32 count __asm__("$7") = loaded_count;
                do {
                    Pair_003C9AE0 *pair = &D_002FD500[item->index23];
                    s16 value = pair->first;

                    if (value != 0) {
                        item->word0 = (item->word0 & 0xFFFFC000) | value;
                    }

                    value = pair->second;
                    count--;
                    if (value != 0) {
                        item->word30 = (item->word30 & 0xFFFFC000) | value;
                    }
                    item++;
                } while (count != 0);
            }
            group++;
        } while (group->items != 0);
    }
}
/* localdecomp:end func_003CF050 */

extern s32 D_001D4BB4;
extern u8 D_00222400[];
extern u8 D_002FDC00[];
extern void func_0038CE20(f32 *, void *, f32);
extern void func_0038D640();
extern void func_0038CD80();
extern void func_11F0A0(s32);
/* localdecomp:start func_003CF0F0 */
/* US draft of func_003CF0F0 (rac3-uya-decomp func_003CF340, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: unmapped symbols: func_003CF418. */


extern s32 D_001D4BB4_003CF0F0;
extern u8 D_00222400_003CF0F0[];
extern u8 D_002FDC00_003CF0F0[];
extern void func_0038CE20_003CF0F0(f32 *, void *, f32);
extern void func_0038D640_003CF0F0();
extern void func_0038CD80_003CF0F0();
extern void func_11F0A0_003CF0F0(s32);
extern void func_003CF1C8_003CF0F0();
void func_003CF0F0(void) {
    u8 v[0x40];
    u32 *o = D_001DA050;
    s32 t = D_001D4BB4_003CF0F0;
    D_001DA68C = o;
    o += 4;
    D_001D4BB0 = t;
    D_001DA050 = o;
    func_0038D2A0(v);
    func_0038CE20_003CF0F0((f32 *)(v + 0x30), D_00222400_003CF0F0, -1024.0f);
    *(f32 *)(v + 0x3C) = 1.0f;
    func_0038D640_003CF0F0(v, D_00222400_003CF0F0 - 0x100, v);
    func_003A9390(5, (s32)v, 4);
    func_003A9390(0x14D, (s32)v, 4);
    func_11F0A0_003CF0F0(0);
    func_003CF1C8_003CF0F0();
    func_003CEF40();
    func_0038CD80_003CF0F0(D_002FDC00_003CF0F0, 0x3000, 0x40);
}
/* localdecomp:end func_003CF0F0 */
TEXT_PADDING(2);

INCLUDE_ASM("asm/nonmatchings/text", func_003CF1C8);
