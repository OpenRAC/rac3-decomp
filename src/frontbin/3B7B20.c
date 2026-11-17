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

extern s32 D_001D8A40;
extern u8 D_001D8AB8;
extern s32 D_001D4CE8_003B7C88;
extern void func_003B7B20_003B7C88();
extern void func_003B8430(void);
extern void func_003820B0(void);
extern s32 D_001D5B74;
extern u8 D_001D5BDC_003B7C88;
extern u8 D_001D5BDD;
extern void func_003820B8(void);
extern void *func_003B4FD0();
extern void *func_003B5028_003B7C88();
extern s32 *func_00381CC0();
extern s32 func_00381D08_003B7C88();
extern s32 func_003BB100(s32);
extern void func_00392DF0(s32, s32);
extern s32 func_003E83C8();
extern void func_003E6FF8(void *);
extern s32 func_003BB0C0(void);
extern void func_003BB0C8(void);
INCLUDE_ASM("asm/nonmatchings/text", func_003B7C88);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_0031C7E0);

/* localdecomp:start func_003B7E38 */
typedef struct { s32 p0; void *vt; } O_B2958;
extern s32 D_001D8AA0;
extern s32 D_001D8AA4;
extern s32 D_001D8AAC;
extern s32 D_001D8B38[2];
extern u8 D_001D5BDC[];
void func_003B7E38(void) {
    s32 i;
    s32 j;
    s32 *p;
    O_B2958 *o;
    func_003E85A8(0x10);
    func_003E85A8(0x11);
    for (i = 0; i < 4; i++) {
        o = (O_B2958 *)func_003B42F8(i);
        (*(void (**)(O_B2958 *))((u8 *)o->vt + 0xC))(o);
    }
    func_003A2750(1);
    func_003BB468(D_001D8AA0);
    for (j = 0; j < 4; j++) {
        func_003BB468(D_001D8B38[j]);
    }
    if (D_001D5BDC[0] == 0) {
        func_003BB468(D_001D8AAC);
        func_003BB468(D_001D8AA4);
    }
    func_0038E150(0);
    func_00392F60(0);
}
/* localdecomp:end func_003B7E38 */

/* localdecomp:start func_003B7F08 */
extern u8 D_001D5BDC[];

void func_003B7F08(void) {
    if (D_001D5BDC[0] == 0) {
        func_00381D38();
    }
}
/* localdecomp:end func_003B7F08 */

/* localdecomp:start func_003B7F30 */
extern u8 D_001D5BDC[];
extern s32 D_001D8A40_g;
extern void func_0038AE20(s32, s32, s32, s32);
extern void func_003B7FD8(void);
void func_003B7F30(void) {
    if (D_001D5BDC[0] == 0) func_00381D40();
    if (D_001D8A40_g != 0) {
        func_0038AE20(0, 0, 0, 0x30);
        func_003B7FD8();
    }
}
/* localdecomp:end func_003B7F30 */

extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_001DA1A0;
extern s32 D_001DA188[2];
extern void func_003B77A0();
extern void func_003B7C88();
INCLUDE_ASM("asm/nonmatchings/text", func_003B7F80);
