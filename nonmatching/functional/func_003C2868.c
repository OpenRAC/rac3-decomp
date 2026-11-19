/* functional: high. Allocates a 0x100-byte object slot from the table [D_001DA4A0, D_001DA4A4): first slot with kind byte (+0x20) >= 0xFE and D_001D9D00 >= slot's +0xA0; optionally allocates b bytes via func_003C76C8 (fails the whole call if that returns 0), kind 0xFF is mirrored to +0x120, initialises with func_003C2990(slot, a), stores the buffer at +0x68, zero-fills it (func_0038CF58), decrements D_001DA3C0 if nonzero, returns the slot; no slot: calls func_003C3C98 if D_001D90C8 and returns 0. US draft with PAL callee name func_003C2990 and the table end read once (as retail) rather than every iteration. Verified vs PAL asm. */
typedef struct { u8 p0[0x20]; u8 f20; u8 p21[0x47]; s32 f68; u8 p6c[0x34]; u32 fA0; u8 pa4[0x5C]; } O_3C2868;
extern u32 D_001DA4A0;
extern u32 D_001DA4A4;
extern s32 D_001D9D00;
extern s32 D_001DA3C0;
extern u8 D_001D90C8;
extern s32 func_003C76C8();
extern void func_003C2990(void *, s32);
extern void func_0038CF58();
extern int func_003C3C98();

O_3C2868 *func_003C2868(s32 a, s32 b)
{
    O_3C2868 *p;
    O_3C2868 *end;
    s32 r;

    end = (O_3C2868 *)D_001DA4A4;
    p = (O_3C2868 *)D_001DA4A0;
    if (p < end) {
        do {
            if (p->f20 < 0xFE) {
                continue;
            }
            if ((u32)D_001D9D00 < p->fA0) {
                continue;
            }
            r = 0;
            if (b) {
                r = func_003C76C8(b);
            }
            if (r == 0 && b) {
                break;
            }
            if (p->f20 == 0xFF) {
                *((u8 *)p + 0x120) = p->f20;
            }
            func_003C2990(p, a);
            p->f68 = r;
            if (b) {
                func_0038CF58(r, 0, b);
            }
            if (D_001DA3C0) {
                D_001DA3C0 = D_001DA3C0 - 1;
            }
            return p;
        } while (++p < end);
    }
    if (D_001D90C8) {
        func_003C3C98();
    }
    return 0;
}
