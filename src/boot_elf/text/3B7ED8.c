#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003E7DD0(s32, s32);
extern s32 func_003E7DD0(s32 arg0, s32 arg1);
/* --- end of declarations from other files --- */

/* declarations of 3B6CD8.c's earlier functions (tools/port_from_us.py) */
extern void func_00393340(s32);
extern void func_0039E9C0(s32);
extern void func_003BB5A8(s32);
extern s32 func_003BB760(s32);
extern s32 D_001D8AA0;
extern s32 D_001D8A9C;
extern s32 D_001D8AAC;
extern s32 D_001D8AB0;
extern s32 D_001D8AA4;
extern s32 D_001D8AA8;
extern u8 D_001D5BDC[];
extern u8 D_001D5BDC_003B6DB0[];
extern void func_003A5748(s32, s32, s32);
typedef struct { u8 on; u8 pad[7]; } F;
typedef struct { void (*fn)(); s32 pad; } T;
extern s32 D_001D8A18_003B6E78;
extern F D_001D8A48_003B6E78[1];
extern T D_001D8A4C[1];
typedef struct { s32 a[7]; } R;
extern R D_142430[];
extern void func_003B6C00();
extern void func_003B6CC8();
extern void func_003B6D28();
extern void func_003B6D68();
extern void func_003B6E50();
extern f32 D_001D8A68;
extern f32 D_001D8A6C;
extern f32 D_001D8A70;
extern f32 D_001D8A74;
extern f32 D_001D8A78;
extern f32 D_001D8A7C;
extern f32 D_001D8A80;
extern f32 D_001D8A84;
extern f32 D_001D8A88;
extern f32 D_001D8A8C;
extern f32 D_001D8A90;
extern f32 D_001D8A94;
extern f32 D_001D8A98;
extern f32 D_001D8AD0;
extern f32 D_001D8AD4;
extern f32 D_001D8AD8;
extern f32 D_001D8ADC;
extern f32 D_001D8AE0;
extern s32 D_001D8AC0[2];
extern void func_003BB538(void);
extern void func_003E9808();
extern s32 func_003BB4D0(u32);
extern s32 func_003E93A0(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E82D8(s32, s32);
extern s32 func_003E7E80(s32, s32);
extern s32 func_003E7CE0(s32, s32, s32);
extern s32 func_003E94F0_003B6F48(s32, s32, f32, f32, f32, f32, s32);
extern s32 func_003E7BF0(s32, s32, s32);
extern s32 func_003E9628(s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_003E8200(s32, s32);
extern s32 func_003E9020(s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_003E8E10(s32, s32, s32, s32, s32);
extern s32 func_003E89E8(s32, s32);
extern s32 func_003E8AC8(s32, s32);
extern s32 func_003E8700(s32, s32);
extern s32 D_001D8A18_003B7640;
extern s32 func_003823D0();
extern s32 func_003B9650(s32, s32, s32, s32, s32, s32, s32, s32, f32, s32, s32, s32, s32, s32, s32);
typedef struct { u8 p0[0x4954]; s32 f4954; u8 p4958[0x7080 - 0x4958]; u8 f7080[4]; } S_B22C0;
extern s32 D_001D8A20[2];
extern s32 D_001D8A30[2];
extern s32 D_001D8B38[2];
extern u8 D_001D5BDC_003B7B58;
extern S_B22C0 D_00160C40_003B7B58[];
extern s32 D_001D8A40;
extern s32 func_003BB760(s32);
extern void *func_003B5400(s32);
extern s32 func_003B48E0(void *, s32, s32, s32, s32);
extern void *func_003B46B0(s32);
extern void func_003B6DB0(void);
extern void func_003B7640(void);
extern void func_003B6F48(void);
extern void func_003B6E78();
typedef struct { u8 p[0x1C4]; u32 f1C4; } P_3B23F8;
typedef struct { u8 on; u8 pad[7]; } F_3B23F8;
typedef struct { void (*fn)(); s32 pad; } T_3B23F8;
extern P_3B23F8 *D_001D52FC_003B7C90;
extern F_3B23F8 D_001D8A48_003B7C90[1];
extern T_3B23F8 D_001D8A4C_003B7C90[1];
extern s32 D_001D8AB4;
extern u8 D_001D5BDC_003B7C90;
extern u8 D_001D5BDD;
extern s32 func_003B5388_003B7C90(void);
extern s32 func_00381C18(s32);
extern s32 func_003B53E0(void);
extern s32 func_00381BD0_003B7C90(void);
extern void func_003E8780_003B7C90(s32);
extern void func_003E73B0_003B7C90(s32);
extern s32 func_003E7770(s32, f32, f32);
extern void func_003BB988();
extern void func_003BB948(s32);

/* localdecomp:start func_003B7ED8 */
extern void func_003B6C40(void);
extern void func_003B6C68(void);
extern void func_003B6C98(void);
extern s32 D_001D8A18;
extern s8 D_001D9FA0;
extern s32 D_001D8A40;
extern s32 D_001D4CE8[];
void func_003B7ED8(void) {
    s32 t5 = D_001D8A18;
    s32 t4 = D_001D4CE8[0];
    D_001D9FA0 = (t5 == 1);
    if (t4 == 0xB || ((u32)(t4 - 6) < 2U && t5 == 1)) {
        func_003B6C40();
    } else if ((u32)(t4 - 6) < 2U) {
        func_003B6C68();
    } else if (t4 == 0xE && t5 != 1 && (t5 == 0 || t5 == 3)) {
        func_003B6C98();
    }
    D_001D8A40 = 2;
}
/* localdecomp:end func_003B7ED8 */

/* localdecomp:start func_003B7F80 */
extern void func_003B6E78(s32);
extern void func_003B7748(void);
extern void func_003B7C90(s32);
void func_003B7F80(s32 a) {
    func_003B6E78(a);
    func_003B7748();
    func_003B7C90(a);
}
/* localdecomp:end func_003B7F80 */

/* localdecomp:start func_003B7FB8 */
extern s32 D_001D8A40;
extern s32 D_001D4CE8[];
void func_003B7FB8(void) {
    s32 temp_3;

    if (D_001D8A40 == 0) {
        temp_3 = D_001D4CE8[0];
        switch (temp_3) {                           /* irregular */
        case 18:
            /* fallthrough */
        case 1:
            func_003E7DD0(0x4C003C, 1);
            func_003E7DD0(0xD000B, 1);
            return;
        default:
            func_003E7DD0(0x4C003C, 0);
            func_003E7DD0(0xD000B, 0);
            D_001D8A40 = 1;
            break;
        }
    }
}
/* localdecomp:end func_003B7FB8 */
