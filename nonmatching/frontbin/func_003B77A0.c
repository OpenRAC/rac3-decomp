/* Near miss of func_003B77A0 with its file's own flags: tools/check.py reports 73 diff
   (the version it replaces: 77).
   What differs: Only the 0x8D00 offset still differs: SN ee-gcc 2.95.3 in this file's `-mno-
   split-addresses` mode folds `(x + 0x8D00) + 15` into `x + 0x8D0F` (`ori $a0,$zero,0x8d0f;
   addu $a0,$a0,$v0; and`), while retail keeps the two adds (`ori $s7,$zero,0x8d00` hoisted
   into $s7 before the loop, `addu $v1,$v0,$s7`, `addiu $v0,$v1,0xf`, `and`); that also leaves
   the frame at 0x40 instead of retail's 0x50 (no $s7 to save) and shifts the flag/call-result
   register from $v0 to $v1. Everything else now matches: the flag's pre-loop split load (`lui
   $v1,0x1d; lbu $v1,0x5bdc($v1)`) comes from the unsized...
*/

/* localdecomp:start func_003B77A0 */
typedef struct { u8 p0[0x4954]; s32 f4954; u8 p4958[0x7080 - 0x4958]; u8 f7080[4]; } S_B22C0;
__asm__(".extern D_001D8A40, 4");
__asm__(".extern D_001D8A20, 8");
__asm__(".extern D_001D8A30, 8");
__asm__(".extern D_001D8B38, 8");
extern s32 D_001D8A20[2];
extern s32 D_001D8A30[2];
extern s32 D_001D8B38[2];
extern u8 D_001D5BDC_003B77A0;
extern S_B22C0 D_00160C40_003B77A0[];
extern s32 D_001D8A40;
extern s32 func_003BB3A8(s32);
extern void *func_003B5048(s32);
extern s32 func_003B4528(void *, s32, s32, s32, s32);
extern void *func_003B42F8(s32);
extern void func_003B69F8(void);
extern void func_003B7288(void);
extern void func_003B6B90(void);
extern void func_003B6AC0();
void func_003B77A0(void) {
    s32 i;
    s32 x;
    s32 y;
    s32 z;
    s32 *p38 = D_001D8B38;
    u8 flag = D_001D5BDC[0];
    for (i = 0; i < 4; i++) {
        if (flag != 0) {
            D_001D8A20[i] = (s32)func_003B5048(i * 2);
            D_001D8A30[i] = (s32)func_003B5048(i * 2 + 1);
        } else {
            x = func_003BB3A8(0);
            p38[i] = x;
            y = (x + 15) & 0xFFFFFFF0;
            z = x + 0x8D00;
            D_001D8A20[i] = y;
            D_001D8A30[i] = (z + 15) & 0xFFFFFFF0;
        }
        func_003B4528(func_003B42F8(i), D_001D8A20[i], D_001D8A30[i], D_00160C40_003B77A0->f4954, (s32)D_00160C40_003B77A0->f7080);
        flag = D_001D5BDC_003B77A0;
    }
    func_003B69F8();
    func_003B7288();
    func_003B6B90();
    func_003B6AC0();
    D_001D8A40 = 0;
}
/* localdecomp:end func_003B77A0 */
