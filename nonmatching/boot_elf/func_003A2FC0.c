/* US draft of func_003A2FC0 (rac3-uya-decomp func_003A2E80, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */

/* localdecomp:start func_003A2FC0 */
typedef struct {
    u8 p0[0x198]; s32 f198; u8 p19C[0x54C - 0x19C]; u8 b54C; u8 p54D[3]; u8 b550; u8 p551[6]; u8 b557;
    u8 p558[0x14]; s32 f56C; s32 f570; u8 p574[0x5C0 - 0x574];
} Pad_3A2E80;
extern Pad_3A2E80 D_001CD0C0_003A2FC0[];
extern void *D_001D52FC;
extern void *D_001D5300;
extern void *D_001D5304;
extern void func_0012EA38(void);
extern s32 func_0012EC90(s32);
extern s32 func_0012EB40(s32);
extern s32 func_0012EBB8(s32);
extern s32 func_0012F0B8(s32, s32, void *);
extern void func_003A30D8_003A2FC0(Pad_3A2E80 *);
void func_003A2FC0(void) {
    s32 mt[2];
    s32 i, port, slot;
    Pad_3A2E80 *p;
    func_0012EA38();
    func_0012EC90(0);
    func_0012EB40(0);
    mt[0] = func_0012EBB8(0);
    func_0012EB40(1);
    mt[1] = func_0012EBB8(1);
    for (i = 0; i < 8; i++) {
        p = &D_001CD0C0_003A2FC0[i];
        port = i >= 4;
        slot = i % 4;
        func_003A30D8_003A2FC0(p);
        func_0012F0B8(port, slot, p);
        p->b557 = slot;
        p->b54C = port;
        p->f198 = 0;
        p->b550 = mt[port];
        p->f56C = 0;
        p->f570 = 0;
    }
    D_001D52FC = D_001CD0C0_003A2FC0;
    D_001D5300 = &D_001CD0C0_003A2FC0[4];
    D_001D5304 = &D_001CD0C0_003A2FC0[4];
}
/* localdecomp:end func_003A2FC0 */
