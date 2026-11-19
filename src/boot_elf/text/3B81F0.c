#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern s32 func_003A2B50(s32);
extern void func_0038E530(s32);
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003A2B50();
extern s32 func_003E8960();
extern s32 func_00381C50(void);
/* --- end of declarations from other files --- */

/* declarations of 3B7ED8.c's earlier functions */
extern void func_00393340(s32);
extern s32 D_001D8AA0;
extern s32 D_001D8AAC;
extern s32 D_001D8AA4;
extern u8 D_001D5BDC[];
extern s32 D_001D8B38[2];
extern void *func_003B46B0(s32);

/* localdecomp:start func_003B81F0 */
typedef struct { s32 p0; void *vt; } O_B2958;
extern s32 D_001D8AA0;
extern s32 D_001D8AA4;
extern s32 D_001D8AAC;
extern s32 D_001D8B38[2];
extern u8 D_001D5BDC[];
void func_003B81F0(void) {
    s32 i;
    s32 j;
    s32 *p;
    O_B2958 *o;
    func_003E8960(0x10);
    func_003E8960(0x11);
    for (i = 0; i < 4; i++) {
        o = (O_B2958 *)func_003B46B0(i);
        (*(void (**)(O_B2958 *))((u8 *)o->vt + 0xC))(o);
    }
    func_003A2B50(1);
    func_003BB820(D_001D8AA0);
    for (j = 0; j < 4; j++) {
        func_003BB820(D_001D8B38[j]);
    }
    if (D_001D5BDC[0] == 0) {
        func_003BB820(D_001D8AAC);
        func_003BB820(D_001D8AA4);
    }
    func_0038E530(0);
    func_00393340(0);
}
/* localdecomp:end func_003B81F0 */

/* localdecomp:start func_003B82C0 */
extern u8 D_001D5BDC[];

void func_003B82C0(void) {
    if (D_001D5BDC[0] == 0) {
        func_00381C48();
    }
}
/* localdecomp:end func_003B82C0 */

/* localdecomp:start func_003B82E8 */
extern u8 D_001D5BDC[];
extern s32 D_001D8A40_g;
extern void func_0038B200(s32, s32, s32, s32);
extern void func_003B8390(void);
void func_003B82E8(void) {
    if (D_001D5BDC[0] == 0) func_00381C50();
    if (D_001D8A40_g != 0) {
        func_0038B200(0, 0, 0, 0x30);
        func_003B8390();
    }
}
/* localdecomp:end func_003B82E8 */
