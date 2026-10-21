#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003B3610(void *, s32);
/* --- end of declarations from other files --- */

/* declarations of 3B3068.c's earlier functions (tools/port_from_us.py) */
extern void *func_003E6FC0();
extern void func_003E6DB0(void *);
extern u8 D_001DA938[];
extern u8 D_001D8880;
extern void func_003E86B0();
extern void *func_003E6FC0();
extern void func_003E6E18();
extern s32 func_003E68D0();
extern s32 func_003E72D0();
extern u8 D_001DA938[];
extern void *func_003E6FC0();
extern void func_003E6E50();
extern u8 D_001DA938[];
extern void *func_003E6FC0();
extern void func_003E6EE0(void *);
extern void func_003AA060();
extern void func_003E71C8_003B3510();
extern void func_003E6F70();
extern void *func_003E6FC0();
extern s32 D_001D9EC0;
extern s32 D_001D9BDC;
extern u8 D_001D8881;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003ADBB0;
extern S_003ADBB0 D_001DA938_003B3510;
extern s32 D_001D8888;
extern s32 D_001D888C;
extern s32 D_001D8888;
extern s32 D_001D888C;
extern void *D_001D8890;
extern void *D_001D8890;

/* localdecomp:start func_003B3610 */
typedef struct { u8 pad0[0x18]; u16 h18; u8 pad1a[0x12E]; s32 f148; u8 pad14c[0x18]; s32 f164; s32 f168; u8 pad16c[8]; s32 f174; } S_003ADCB0;
extern S_003ADCB0 D_00142430;
extern u8 D_001D4BE0;
extern u8 D_001D4BE0_b_003ADCB0;
extern void func_0012BE28();
extern void func_0013AD58();
extern void func_0039E9C0();
void func_003B3610(void *a, s32 b) {
    S_003ADCB0 *e = &D_00142430;
    func_0012BE28(&D_001D4BE0);
    func_0013AD58(&D_001D4BE0_b_003ADCB0);
    func_0039E9C0(a);
    e->f174 = (s32)a;
    e->h18 = b;
    e->f148 = 0;
    if (e->f164 < 0) {
        e->f168 = 0;
        e->f164 = 0x13;
    }
}
/* localdecomp:end func_003B3610 */

/* localdecomp:start func_003B3690 */
__asm__(".extern D_001D888C, 4");
extern s32 D_001D888C;
extern void (*D_001DA100)();
extern void func_003A1398(s32, s32);
extern void func_003B3D90(void);
void func_003B3690(void) {
    s32 t = D_001D888C;
    switch (t) {
    case 0:
        if (D_001DA100 != 0) {
            D_001DA100();
            D_001DA100 = 0;
        }
        func_003A1398(0, 0);
        t = D_001D888C;
        t += 1;
        D_001D888C = t;
        break;
    case 1:
        D_001D888C = 2;
        break;
    case 2:
        func_003B3D90();
        break;
    }
}
/* localdecomp:end func_003B3690 */
