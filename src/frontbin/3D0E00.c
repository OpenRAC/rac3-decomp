#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003D0E00();
/* --- end of declarations from other files --- */

/* localdecomp:start func_003D0E00 */
extern void func_003D0A08(s32, s32, s32);
extern s32 func_003DE9F8(s32, s32, s32);
extern s32 func_003E1238(s32, s32, s32);
extern u8 D_002FF700[];
void func_003D0E00(s32 arg0) {
    s32 temp_2;
    s32 temp_4;
    s32 temp_4_2;
    s32 temp_4_3;
    void *temp_16;

    temp_16 = (arg0 * 0x30) + D_002FF700;
    temp_2 = (*(s32 *)((u8 *)temp_16 + 0xC));
    if (temp_2 != 0) {
        temp_4 = temp_2 + ((*(s16 *)((u8 *)temp_16 + 0)) * 2);
        func_003DE9F8(temp_4, temp_4 + ((*(s16 *)((u8 *)temp_16 + 2)) * 2), arg0);
        temp_4_2 = (*(s32 *)((u8 *)temp_16 + 0xC)) + ((*(s16 *)((u8 *)temp_16 + 4)) * 2);
        (*(s16 *)((u8 *)temp_16 + 0)) = 0;
        (*(s16 *)((u8 *)temp_16 + 2)) = 0;
        func_003E1238(temp_4_2, temp_4_2 + ((*(s16 *)((u8 *)temp_16 + 6)) * 2), arg0);
        temp_4_3 = (*(s32 *)((u8 *)temp_16 + 0xC)) + ((*(s16 *)((u8 *)temp_16 + 8)) * 2);
        (*(s16 *)((u8 *)temp_16 + 4)) = 0;
        (*(s16 *)((u8 *)temp_16 + 6)) = 0;
        func_003D0A08(temp_4_3, temp_4_3 + ((*(s16 *)((u8 *)temp_16 + 0xA)) * 2), arg0);
        (*(s16 *)((u8 *)temp_16 + 8)) = 0;
        (*(s16 *)((u8 *)temp_16 + 0xA)) = 0;
    }
}
/* localdecomp:end func_003D0E00 */

typedef int u128_3CB958 __attribute__((mode(TI)));
extern u8 D_001DA6B0[8];
extern f32 D_001DA6C0;
extern f32 D_001DA6C4;
extern volatile f32 D_001DA6C8;
extern u8 D_001DA6D0[];
extern void func_0038CDE8(void *, void *);
extern void func_0038CE20(f32 *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(s32, s32, f32);
INCLUDE_ASM("asm/nonmatchings/text", func_003D0EC8);

/* localdecomp:start func_003D0FD8 */
void func_003D1A20(s16 *);
void func_003D1B68(s16 *);
char *func_003D0FD8(s16 *p) {
    char *q = (char *)p;
    if (*p == 0) { func_003D1A20(p); q += 0x20; }
    else if (*p == 1) { func_003D1B68(p); q += 0x30; }
    return q;
}
/* localdecomp:end func_003D0FD8 */
