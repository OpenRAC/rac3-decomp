/* NTSC-U draft (2026-11-14, Claude worker): C of func_L01_003C5330, the NTSC-U twin of func_L01_003C6BB0, with NTSC-U names
 * and addresses. Near miss on NTSC-U: 6 words differ with its file's flags.
 */
#include "common.h"

/* NTSC-U counterpart of func_L01_003C6BB0 (src/levels/shared/L01_003C64E0.c) */
/* localdecomp:start func_L01_003C5330 */
extern u8 *D_L01_001E0180;
extern s32 D_L01_001DF9DC;
extern f32 D_001DECCC_sda;
__asm__(".extern D_001DECCC_sda, 4");
extern s32 D_001A71A0[];

extern s32 func_L01_003C3E18(u8 *, u8 *);
extern void func_L01_003C41F8(u8 *, u8 *, s32);
extern void func_L01_003C5F90(u8 *, u8 *, s32, s32, s32);
extern void func_L01_003C3A10(u8 *, u8 *);
extern void func_L01_003C5670(u8 *, u8 *);
extern void func_L01_003E9588(s32, void *, void *, s32, s32, s32);
extern void func_L01_003C4468(u8 *, u8 *);
extern void func_L01_003C4570(u8 *, u8 *, s32);
extern void func_L01_00438180(s32);
extern void func_L01_00441FB8(u8 *, s32, s32);

s32 func_L01_003C5330(u8 *obj, s32 idx) {
    u8 *p = *(u8 **)(obj + 0x68);
    s32 *slot;
    s32 *base;
    u8 *e;

    if (idx < 0) {
        idx = func_L01_003C3E18(obj, p);
    }
    base = (s32 *)(p + 0x780);
    slot = base + idx;
    if (*slot == -1) {
        return 0;
    }
    *(s32 *)(p + 0x104) = idx;
    func_L01_003C41F8(obj, p, idx);
    func_L01_003C5F90(obj, p, *slot, *(s32 *)(p + idx * 4 + 0x770), 1);
    *(f32 *)(p + 0xC8) = D_001DECCC_sda * 0.016666668f;
    func_L01_003C3A10(obj, p);
    func_L01_003C5670(obj, p);
    e = D_L01_001E0180 + (*(s32 *)(p + idx * 4 + 0x760) << 7);
    func_L01_003E9588(0, e + 0x30, e + 0x70, 4, 0, 0);
    func_L01_003C4468(obj, p);
    func_L01_003C4570(obj, p, 1);
    func_L01_00438180(D_001A71A0[0]);
    D_L01_001DF9DC = 1;
    func_L01_00441FB8(obj, 0xB, -1);
    return 1;
}
/* localdecomp:end func_L01_003C5330 */
