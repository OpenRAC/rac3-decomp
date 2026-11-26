#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations carried from the file this was cut from */
extern void func_00392260(s32, long, long);
extern void func_00392290(void);
extern void func_003910C0(s16 *p, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h);
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void func_0038E138(void);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);


/* localdecomp:start func_0038E0A8 */
s32 func_0038E0A8(u8 *p, s32 off, s32 *out) {
    u8 *q = p + off;
    s32 r = 0;
    s32 b = q[0];
    *out = b;
    if (b & 0x80) {
        r = 1;
        *out = (((b & 0x7F) << 8) | q[1]) + 0x7F;
    }
    return r;
}
/* localdecomp:end func_0038E0A8 */

/* localdecomp:start func_0038E0E8 */
/* the copy of func_L39_00591B38 */
void func_0038DE18(s32, void *, void *);
void func_0038E150(s32);
extern u8 D_00143E40[];
extern u8 D_00144440[];
extern u8 D_0014A240[];
extern u8 D_0014A840[];

void func_0038E0E8(void) {
    func_0038DE18(0, D_00144440, D_00143E40);
    func_0038DE18(1, D_0014A840, D_0014A240);
    func_0038E150(0);
}
/* localdecomp:end func_0038E0E8 */
