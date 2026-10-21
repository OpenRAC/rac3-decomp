/* Near miss of func_00396AB8 with its file's own flags: tools/check.py reports 25 diff
   (the US draft it started from: 49).
   What differs: 25 words differ. Fixed vs the US draft: D_001D5E9C/D_001D5EA0 are now reached
   through lui/%lo like retail (they are written through their literal address
   0x1D5E9C/0x1D5EA0, since a sized scalar is always small data under -G8 and would come out as
   $gp), func_00393C50 -> func_00393D10 (PAL), and the frame is now 6 registers with `move $a0,
   $v0` and the store to D_001D5EA0 before the `b` as retail has it. Still differs: (1) gcc
   issues the two struct loads in the wrong order - it loads h = e->f38 (lhu $a1,0x38($v0))
   before b = e->f0 (which then lands in the beqz delay slot in $v0), retail...
*/

/* PAL candidate for func_00396AB8 (boot_elf).
   Retail reaches D_001D5E9C and D_001D5EA0 through lui/%lo (they are not small data),
   while D_001D5EA4 and D_001D5E98 are reached through $gp.  Under -G8 a sized scalar is
   always small data, so the two lui-reached globals are written through their literal
   address (docs/wiki/Matching-Patterns.md, "Globals: gp vs lui").  Plain C only. */

/* localdecomp:start func_00396AB8 */
typedef struct {
    u8 f0;
    u8 p1[0x37];
    u16 f38;
    u8 p3A[0x50];
    u16 f8A;
    u8 p8C[0xF0 - 0x8C];
} S_391E78;
extern u8 D_001A4BE0[];
extern u8 D_001425C0[];
extern s32 D_001427F0[];
extern S_391E78 D_001DAA40_00396AB8[];
extern s32 func_00396A70(void);
extern void func_00393990(s32 id, s32 v);
extern void func_00396770();
extern void func_00397EF0();
extern s32 func_003967A0(void);
extern void func_00393CD8();
extern void func_00393D10();
extern s32 func_00396658();
extern void func_00393728();
void func_00396AB8(void) {
    s32 r;
    u8 *p;
    u8 *s;
    s32 id;
    S_391E78 *e;
    u8 b;
    u16 h;
    s32 n;
    if (D_001D5EA4 != 0) return;
    if (D_001D5E98 != 0) return;
    r = func_00396A70();
    p = D_001425C0 + r;
    e = &D_001DAA40_00396AB8[*p];
    b = e->f0;
    h = e->f38;
    if (r != 0 && b != 0) {
        *(s32 *)0x1D5E9C = r;
        *(s32 *)0x1D5EA0 = ((s32 (*)())func_00393728)(0x10, h, (s32)func_00396770, (s32)func_00397EF0,
                                   (s32)func_003967A0, (s32)&D_001427F0[r],
                                   D_001DAA40_00396AB8[*p].f8A);
    } else {
        s = D_001A4BE0;
        id = 2;
        n = -1;
        b = s[0x25E4];
        if (b == id) {
            id = *(s32 *)0x1D5EA0;
            if (id != n) {
                func_00393990(id, 0);
                *(s32 *)0x1D5EA0 = n;
            }
            *(s16 *)(s + 0x1A88) = ((s32 (*)())func_00393728)(0x10, 0xFFFF, (s32)func_00393CD8, (s32)func_00393D10,
                                                 (s32)func_00396658, (s32)(s + 0x1A84), 200);
        } else {
            id = *(s32 *)0x1D5EA0;
            if (id != n) {
                func_00393990(id, 0);
                *(s32 *)0x1D5EA0 = n;
            }
        }
    }
}
/* localdecomp:end func_00396AB8 */
