#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 3B7B20.c's earlier functions */
extern s32 func_003A2750(s32);
extern void func_0038E150(s32);
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003A2750();
extern s32 func_003E85A8();
extern s32 func_00381D40(void);
extern void func_00392F60(s32);
extern void *func_003B42F8(s32);

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
