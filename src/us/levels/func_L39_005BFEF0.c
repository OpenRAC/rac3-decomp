#include "common.h"

typedef struct { u32 f0; s16 f4; s16 f6; s16 f8; s16 fA; s16 fC; u8 fE[2]; } S_005C1F38;

/* localdecomp:start func_L39_005BFEF0 */
extern void func_193D98(s32);
extern void func_194858(s32);
extern void func_194888(s32);
extern void func_1948B8(s32, void *, unsigned long);
extern void func_1948E8(s32, void *, unsigned long);
extern void func_193E80(s32, void *, unsigned long);
extern void func_194918(s32, void *, unsigned long);
extern s32 func_003883C8(void *);
extern void func_0039DA48(s32, long);
extern void func_0039DA60(s32, long);
extern void func_0039DA08(s32, long);
extern void func_0039D800(s32, long);
void func_L39_005BFEF0(S_005C1F38 *s) {
    s32 h;
    if (s->fA != 9 && s->f0 != 0 && s->f0 != 0xFFFFFFFF) {
        if (s->fA == 5) {
            if (s->f0 == 0) {
                s->fA = 0;
            } else {
                func_193D98(s->f0);
                s->fA = 6;
            }
        } else if (s->fA == 6) {
            if (s->f0 == 0) s->fA = 0;
        }
        if (s->f0 != 0) {
            if (s->fC & 0x8000) {
                if (!(s->fA & 0x8000)) {
                    func_194858(s->f0);
                    s->fA |= 0x8000;
                }
                if (func_003883C8(s->fE) == 2) s->fC = 4;
            } else if (s->fA & 0x8000) {
                func_194888(s->f0);
                s->fA ^= 0x8000;
            }
            if (!(s->fA & 0x8000)) {
                if (s->fA == 1 || s->fA == 8 || s->fA == 9) {
                } else if (s->fA != 2 && s->fA != 3) {
                    h = s->f0;
                    s->f0 = 0xFFFFFFFF;
                    func_1948B8(h, func_0039DA48, (u32)s);
                    func_1948E8(h, func_0039DA60, (u32)s);
                    func_193E80(h, func_0039DA08, (u32)s);
                } else if (s->f0 != 0xFFFFFFFF && s->fA == 2) {
                    func_194918(s->f0, func_0039D800, (u32)s);
                }
            }
        }
    } else if (s->fA == 7 || s->f0 == 0) {
        s->fA = 0;
    }
    if (s->fA == 0) s->f4 = -1;
}
/* localdecomp:end func_L39_005BFEF0 */
