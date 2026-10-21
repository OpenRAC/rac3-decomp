/* US draft of func_003B7C88 (rac3-uya-decomp func_003B27A8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_003B7C88 */
__asm__(".extern D_001D8A40, 4");
__asm__(".extern D_001D8AB8, 1");
__asm__(".extern D_001D4CE8, 4");
__asm__(".extern D_001D5B74, 4");
extern s32 D_001D8A40;
extern u8 D_001D8AB8;
extern s32 D_001D4CE8_003B7C88;
extern void func_003B7C00(void);
extern void func_003B7BC8(s32);
extern void func_003B7B20_003B7C88();
extern void func_003B8430(void);
extern void func_003820B0(void);
extern s32 D_001D5B74;
extern u8 D_001D5BDC_003B7C88;
extern u8 D_001D5BDD;
extern void func_003820B8(void);
extern void *func_003B4FD0();
extern void *func_003B5028_003B7C88();
extern s32 *func_00381CC0();
extern s32 func_00381D08_003B7C88();
extern s32 func_003BB100(s32);
extern void func_00392DF0(s32, s32);
extern s32 func_003E83C8();
extern void func_003E6FF8(void *);
extern s32 func_003BB0C0(void);
extern void func_003BB0C8(void);
void func_003B7C88(s32 a) {
    func_003B7C00();
    func_003820B8();
    if (D_001D8A40 != 0) func_003820B0();
    switch (D_001D8A40) {
    case 0:
        func_003B7BC8(a);
        break;
    case 1:
        func_003B7B20_003B7C88(a);
        break;
    case 2:
    case 3:
        func_003B8430();
        break;
    case 4:
    case 5:
        D_001D8A40 = 0;
        break;
    case 6:
        if (D_001D5BDD != 0) {
            if (D_001D8AB8 != 0 && D_001D4CE8_003B7C88 == 1) {
                func_00392DF0(1, 1);
            } else {
                D_001D8A40 = 0;
                func_003E83C8(func_003B5028_003B7C88());
                func_003E6FF8((void *)a);
            }
        } else if (D_001D5BDC_003B7C88 != 0) {
            func_003E83C8(func_003B4FD0());
            func_003E6FF8((void *)a);
        } else {
            if (D_001D5B74 != 0 || func_003BB100(1) != 0) {
                func_003E83C8(func_00381CC0());
            } else {
                func_003E83C8(func_00381D08_003B7C88(0));
            }
            func_003E6FF8((void *)a);
        }
        D_001D8AB8 = 0;
        break;
    }
    if (func_003BB0C0() != 0) {
        if (D_001D8A40 != 6) {
            func_003BB0C8();
            func_003E6FF8((void *)a);
            if (D_001D5BDC_003B7C88 == 0) {
                func_003E83C8(func_00381CC0());
            }
        }
    }
}
/* localdecomp:end func_003B7C88 */
