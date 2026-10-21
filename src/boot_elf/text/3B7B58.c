#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
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

/* localdecomp:start func_003B7B58 */
typedef struct { u8 p0[0x4954]; s32 f4954; u8 p4958[0x7080 - 0x4958]; u8 f7080[4]; } S_B22C0;
__asm__(".extern D_001D8A40, 4");
__asm__(".extern D_001D8A20, 8");
__asm__(".extern D_001D8A30, 8");
__asm__(".extern D_001D8B38, 8");
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
void func_003B7B58(void) {
    s32 i;
    s32 x;
    s32 y;
    for (i = 0; i < 4; i++) {
        if (D_001D5BDC_003B7B58 != 0) {
            D_001D8A20[i] = (s32)func_003B5400(i * 2);
            D_001D8A30[i] = (s32)func_003B5400(i * 2 + 1);
        } else {
            x = func_003BB760(0);
            D_001D8B38[i] = x;
            y = (x + 15) & 0xFFFFFFF0;
            D_001D8A20[i] = y;
            y = x + 0x8D00;
            y = (y + 15) & 0xFFFFFFF0;
            D_001D8A30[i] = y;
        }
        func_003B48E0(func_003B46B0(i), D_001D8A20[i], D_001D8A30[i], D_00160C40_003B7B58->f4954, (s32)D_00160C40_003B7B58->f7080);
    }
    func_003B6DB0();
    func_003B7640();
    func_003B6F48();
    func_003B6E78();
    D_001D8A40 = 0;
}
/* localdecomp:end func_003B7B58 */

/* localdecomp:start func_003B7C90 */
typedef struct { u8 p[0x1C4]; u32 f1C4; } P_3B23F8;
typedef struct { u8 on; u8 pad[7]; } F_3B23F8;
typedef struct { void (*fn)(); s32 pad; } T_3B23F8;
__asm__(".extern D_001D8AB4, 4");
__asm__(".extern D_001D8A48_003B7C90, 8");
__asm__(".extern D_001D5BDC_003B7C90, 1");
__asm__(".extern D_001D8A68, 4");
__asm__(".extern D_001D8A6C, 4");
__asm__(".extern D_001D8A94, 4");
__asm__(".extern D_001D8A98, 4");
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
void func_003B7C90(s32 a0) {
    u32 b = D_001D52FC_003B7C90->f1C4;
    s32 i;
    s32 n = 0;
    if (b & 0x4000) {
        s32 found = 0;
        i = D_001D8AB4;
        do {
            i++;
            if (i >= 4) i = 0;
            if (D_001D8A48_003B7C90[i].on) found = 1;
            n++;
            if (found) break;
        } while (n < 4);
        D_001D8AB4 = i;
        ((s32 (*)(s32, s32, s32))func_003A5748)(3, 0, 0);
    } else if (b & 0x1000) {
        s32 found = 0;
        i = D_001D8AB4;
        do {
            i--;
            { s32 lim = -1; if (i <= lim) i = 3; lim = 0; }
            if (D_001D8A48_003B7C90[i].on) found = 1;
            n++;
            if (found) break;
        } while (n < 4);
        D_001D8AB4 = i;
        ((s32 (*)(s32, s32, s32))func_003A5748)(3, 0, 0);
    } else if (b & 0x40) {
        if (D_001D8A48_003B7C90[D_001D8AB4].on) {
            if (D_001D8A4C_003B7C90[D_001D8AB4].fn) {
                D_001D8A4C_003B7C90[D_001D8AB4].fn();
                ((s32 (*)(s32, s32, s32))func_003A5748)(4, 0, 0);
            }
        }
    } else if (b & 0x10) {
        ((s32 (*)(s32, s32, s32))func_003A5748)(4, 0, 0);
        if (D_001D5BDD) {
            func_003E8780_003B7C90(func_003B53E0());
            func_003E73B0_003B7C90(a0);
        } else if (D_001D5BDC_003B7C90) {
            func_003E8780_003B7C90(func_003B5388_003B7C90());
            func_003E73B0_003B7C90(a0);
        } else {
            func_003E8780_003B7C90(func_00381C18(0));
            func_003E73B0_003B7C90(a0);
        }
    } else if (b & 0x900) {
        ((s32 (*)(s32, s32, s32))func_003A5748)(4, 0, 0);
        if (D_001D5BDD) {
            func_003E8780_003B7C90(func_003B53E0());
            func_003E73B0_003B7C90(a0);
        } else if (!D_001D5BDC_003B7C90) {
            func_003E8780_003B7C90(func_00381BD0_003B7C90());
            func_003E73B0_003B7C90(a0);
        }
    }
    func_003E7770(0x4C0038, D_001D8A94, D_001D8A6C + D_001D8A98 + (f32)D_001D8AB4 * D_001D8A68);
    func_003BB988();
    func_003BB948(0x4C0038);
}
/* localdecomp:end func_003B7C90 */
