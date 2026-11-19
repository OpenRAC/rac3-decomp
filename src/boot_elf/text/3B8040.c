#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 3B7ED8.c's earlier functions */
extern s32 D_001D8A40;
extern u8 D_001D5BDD;
extern void func_003B7F80(s32 a);
extern void func_003B7FB8(void);

extern s32 D_001D8A40;
extern u8 D_001D8AB8;
extern s32 D_001D4CE8_003B8040;
extern void func_003B7ED8_003B8040();
extern void func_003B87E8(void);
extern void func_00382490(void);
extern s32 D_001D5B74;
extern u8 D_001D5BDC_003B8040;
extern u8 D_001D5BDD;
extern void func_00382498(void);
extern void *func_003B5388();
extern void *func_003B53E0_003B8040();
extern s32 *func_00381BD0();
extern s32 func_00381C18_003B8040();
extern s32 func_003BB4B8(s32);
extern void func_003931D0(s32, s32);
extern s32 func_003E8780();
extern void func_003E73B0(void *);
extern s32 func_003BB478(void);
extern void func_003BB480(void);
/* localdecomp:start func_003B8040 */
__asm__(".extern D_001D8A40, 4");
__asm__(".extern D_001D8AB8, 1");
__asm__(".extern D_001D4CE8, 4");
__asm__(".extern D_001D5B74, 4");
extern s32 D_001D8A40;
extern u8 D_001D8AB8;
extern s32 D_001D4CE8_003B8040;
extern void func_003B7FB8(void);
extern void func_003B7F80(s32);
extern void func_003B7ED8_003B8040();
extern void func_003B87E8(void);
extern void func_00382490(void);
extern s32 D_001D5B74;
extern u8 D_001D5BDC_003B8040;
extern u8 D_001D5BDD;
extern void func_00382498(void);
extern void *func_003B5388();
extern void *func_003B53E0_003B8040();
extern s32 *func_00381BD0();
extern s32 func_00381C18_003B8040();
extern s32 func_003BB4B8(s32);
extern void func_003931D0(s32, s32);
extern s32 func_003E8780();
extern void func_003E73B0(void *);
extern s32 func_003BB478(void);
extern void func_003BB480(void);
void func_003B8040(s32 a) {
    func_003B7FB8();
    func_00382498();
    if (D_001D8A40 != 0) func_00382490();
    switch (D_001D8A40) {
    case 0:
        func_003B7F80(a);
        break;
    case 1:
        func_003B7ED8_003B8040(a);
        break;
    case 2:
    case 3:
        func_003B87E8();
        break;
    case 4:
    case 5:
        D_001D8A40 = 0;
        break;
    case 6:
        if (D_001D5BDD != 0) {
            if (D_001D8AB8 != 0 && D_001D4CE8_003B8040 == 1) {
                func_003931D0(1, 1);
            } else {
                D_001D8A40 = 0;
                func_003E8780(func_003B53E0_003B8040());
                func_003E73B0((void *)a);
            }
        } else if (D_001D5BDC_003B8040 != 0) {
            func_003E8780(func_003B5388());
            func_003E73B0((void *)a);
        } else {
            if (D_001D5B74 != 0 || func_003BB4B8(1) != 0) {
                func_003E8780(func_00381BD0());
            } else {
                func_003E8780(func_00381C18_003B8040(0));
            }
            func_003E73B0((void *)a);
        }
        D_001D8AB8 = 0;
        break;
    }
    if (func_003BB478() != 0) {
        if (D_001D8A40 != 6) {
            func_003BB480();
            func_003E73B0((void *)a);
            if (D_001D5BDC_003B8040 == 0) {
                func_003E8780(func_00381BD0());
            }
        }
    }
}
/* localdecomp:end func_003B8040 */
