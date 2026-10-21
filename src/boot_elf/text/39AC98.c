#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 39A9A8.c's earlier functions (tools/port_from_us.py) */
extern void func_0038CF58(void *, s32, s32);
extern u8 D_0016C690[];
extern s32 D_001D600C;
typedef struct { u8 pad[0x34]; s32 arr[8]; } T_00395958;
extern T_00395958 D_0016C690_0039AB28;
typedef struct { s32 f0; s32 f4; } S_00395958;
typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; } E_003959A8;
typedef struct { u8 pad[0x458C]; s32 g458C; E_003959A8 el[0x30]; } S_003959A8;
typedef struct { s32 w0; s32 w4; s32 w8; s32 wC; } L_003959A8;
typedef struct { s32 f0; s32 f4; u8 *f8; } A_003959A8;
extern S_003959A8 D_160C40_0039AB78;
extern void func_0039AB28();
extern void func_11F0A0();
extern s32 func_11F1E0();
extern s32 func_11F1C0();
extern s32 func_003A2A30();

/* localdecomp:start func_0039AC98 */
typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; } E_00395AC8;
typedef struct { u8 pad[0x458C]; s32 g458C; E_00395AC8 el[0x30]; } S_00395AC8;
extern S_00395AC8 D_160C40_0039AC98;
typedef struct { u8 pad[0x34]; s32 f34[3]; } T_00395AC8;
extern T_00395AC8 D_16C690_0039AC98;
__asm__(".extern D_001D6000_0039AC98, 4");
extern s32 D_001D6000_0039AC98;
extern u8 D_001D6004_0039AC98;
extern u8 D_001D6008_0039AC98;
extern s32 func_003A2A30();
extern void func_0039AB28();
extern void func_0039AB78();
s32 func_0039AC98(s32 a0, s32 a1, s32 a2, s32 a3) {
    s32 t;
    if (D_160C40_0039AC98.el[a0].f8 != 0) {
        t = D_001D6000_0039AC98;
        if (t == -1) {
            *(volatile s32 *)&D_001D6000_0039AC98 = a0;
            *(volatile s32 *)&D_001D6004_0039AC98 = a1;
            *(volatile s32 *)&D_001D6008_0039AC98 = a2;
            if (a1 >= 0) {
                D_16C690_0039AC98.f34[a1] = t;
            }
            if (D_160C40_0039AC98.el[a0].f10 != 0 && a3 == 0) {
                return func_003A2A30(a2, D_160C40_0039AC98.el[a0].fC + D_160C40_0039AC98.g458C, D_160C40_0039AC98.el[a0].f10, func_0039AB78, &D_001D6000_0039AC98);
            }
            return func_003A2A30(a2, D_160C40_0039AC98.el[a0].f4 + D_160C40_0039AC98.g458C, D_160C40_0039AC98.el[a0].f8, func_0039AB28, &D_001D6000_0039AC98);
        }
        return 0;
    }
    return 0;
}
/* localdecomp:end func_0039AC98 */
