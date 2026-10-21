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

/* localdecomp:start func_0039AB78 */
/* Reached with lui in retail, as the assembler expands an access to a global it does not know to be
   small: declared sized (gcc leaves the access to the assembler as one macro), then with a section
   attribute, which keeps gcc's .extern size hint out of the assembly. */
extern s32 D_001D4B38_0039AB78;
__asm__(".extern D_001D4B38_0039AB78, 16");
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
void func_0039AB78(A_003959A8 *a, s32 flag) {
    s32 t;
    s32 off;
    s32 base;
    s32 h;
    u8 *o;
    s32 *r;
    L_003959A8 l;
    if (flag == 0) {
        a->f0 = -1;
        return;
    }
    t = D_160C40_0039AB78.el[a->f0].f10;
    if (t != 0) {
        off = a->f4 * 0xC800;
        o = a->f8;
        base = D_001D4B38_0039AB78 + off;
        l.w0 = (s32)o;
        l.w4 = base;
        l.w8 = t << 11;
        l.wC = 0;
        r = (s32 *)(o + 0x18);
        *(s32 *)(o + 0x14) = 0xC000;
        r[10] = 0xC000;
        r[11] = 0xC000;
        func_11F0A0(0);
        h = func_11F1E0(&l, 1);
        while (func_11F1C0(h) >= 0) {
        }
    }
    func_003A2A30(a->f8, D_160C40_0039AB78.el[a->f0].f4 + D_160C40_0039AB78.g458C, D_160C40_0039AB78.el[a->f0].f8, func_0039AB28, a);
}
/* localdecomp:end func_0039AB78 */
