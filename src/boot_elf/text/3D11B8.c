#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003D11B8();
/* --- end of declarations from other files --- */

/* localdecomp:start func_003D11B8 */
extern void func_003D0DC0(s32, s32, s32);
extern s32 func_003DEDB0(s32, s32, s32);
extern s32 func_003E15F0(s32, s32, s32);
extern u8 D_002FF700[];
void func_003D11B8(s32 arg0) {
    s32 temp_2;
    s32 temp_4;
    s32 temp_4_2;
    s32 temp_4_3;
    void *temp_16;

    temp_16 = (arg0 * 0x30) + D_002FF700;
    temp_2 = (*(s32 *)((u8 *)temp_16 + 0xC));
    if (temp_2 != 0) {
        temp_4 = temp_2 + ((*(s16 *)((u8 *)temp_16 + 0)) * 2);
        func_003DEDB0(temp_4, temp_4 + ((*(s16 *)((u8 *)temp_16 + 2)) * 2), arg0);
        temp_4_2 = (*(s32 *)((u8 *)temp_16 + 0xC)) + ((*(s16 *)((u8 *)temp_16 + 4)) * 2);
        (*(s16 *)((u8 *)temp_16 + 0)) = 0;
        (*(s16 *)((u8 *)temp_16 + 2)) = 0;
        func_003E15F0(temp_4_2, temp_4_2 + ((*(s16 *)((u8 *)temp_16 + 6)) * 2), arg0);
        temp_4_3 = (*(s32 *)((u8 *)temp_16 + 0xC)) + ((*(s16 *)((u8 *)temp_16 + 8)) * 2);
        (*(s16 *)((u8 *)temp_16 + 4)) = 0;
        (*(s16 *)((u8 *)temp_16 + 6)) = 0;
        func_003D0DC0(temp_4_3, temp_4_3 + ((*(s16 *)((u8 *)temp_16 + 0xA)) * 2), arg0);
        (*(s16 *)((u8 *)temp_16 + 8)) = 0;
        (*(s16 *)((u8 *)temp_16 + 0xA)) = 0;
    }
}
/* localdecomp:end func_003D11B8 */

typedef int u128_3CB958 __attribute__((mode(TI)));
extern u8 D_001DA6B0[8];
extern f32 D_001DA6C0;
extern f32 D_001DA6C4;
extern volatile f32 D_001DA6C8;
extern u8 D_001DA6D0[];
extern void func_0038D1C8(void *, void *);
extern void func_0038D200(f32 *, void *, f32);
extern void func_0038D270(void *, void *, void *);
extern void func_0038D348(s32, s32, f32);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003D1280);

/* localdecomp:start func_003D1390 */
void func_003D1DD8(s16 *);
void func_003D1F20(s16 *);
char *func_003D1390(s16 *p) {
    char *q = (char *)p;
    if (*p == 0) { func_003D1DD8(p); q += 0x20; }
    else if (*p == 1) { func_003D1F20(p); q += 0x30; }
    return q;
}
/* localdecomp:end func_003D1390 */
