#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations carried from the file this was cut from */
extern s32 func_003A2750(s32);
extern void func_0038E150(s32);
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003A2750();
extern s32 func_003B7F80(void);
extern s32 func_003E85A8();
extern s32 func_003E7A18(s32, s32);
extern s32 func_00381D40(void);
extern s32 func_003E7A18(s32 arg0, s32 arg1);
extern void func_00392F60(s32);
extern void *func_003B42F8(s32);


/* localdecomp:start func_003B7B20 */
extern void func_003B6888(void);
extern void func_003B68B0(void);
extern void func_003B68E0(void);
extern s32 D_001D8A18;
extern s8 D_001D9FA0;
extern s32 D_001D8A40;
extern s32 D_001D4CE8[];
void func_003B7B20(void) {
    s32 t5 = D_001D8A18;
    s32 t4 = D_001D4CE8[0];
    D_001D9FA0 = (t5 == 1);
    if (t4 == 0xB || ((u32)(t4 - 6) < 2U && t5 == 1)) {
        func_003B6888();
    } else if ((u32)(t4 - 6) < 2U) {
        func_003B68B0();
    } else if (t4 == 0xE && t5 != 1 && (t5 == 0 || t5 == 3)) {
        func_003B68E0();
    }
    D_001D8A40 = 2;
}
/* localdecomp:end func_003B7B20 */

/* localdecomp:start func_003B7BC8 */
extern void func_003B6AC0(s32);
extern void func_003B7390(void);
extern void func_003B78D8(s32);
void func_003B7BC8(s32 a) {
    func_003B6AC0(a);
    func_003B7390();
    func_003B78D8(a);
}
/* localdecomp:end func_003B7BC8 */

/* localdecomp:start func_003B7C00 */
extern s32 D_001D8A40;
extern s32 D_001D4CE8[];
void func_003B7C00(void) {
    s32 temp_3;

    if (D_001D8A40 == 0) {
        temp_3 = D_001D4CE8[0];
        switch (temp_3) {                           /* irregular */
        case 18:
            /* fallthrough */
        case 1:
            func_003E7A18(0x4C003C, 1);
            func_003E7A18(0xD000B, 1);
            return;
        default:
            func_003E7A18(0x4C003C, 0);
            func_003E7A18(0xD000B, 0);
            D_001D8A40 = 1;
            break;
        }
    }
}
/* localdecomp:end func_003B7C00 */
